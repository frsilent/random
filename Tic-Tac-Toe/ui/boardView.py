__author__ = 'Roland'

from PyQt4 import QtCore, QtGui
import os

class BoardView(QtGui.QGraphicsView):
    def __init__(self, parent=None):
        """
        Creates a 2d matrix view to represent the graphical board
        """
        QtGui.QWidget.__init__(self,parent)
        self.width = 360
        self.height = 300

        self.rows = 3
        self.cols = 3

        self.col_width = self.width / self.cols
        self.row_height = self.height / self.rows

        #TODO: pretty up with comprehension
        self.boardMatrix = []
        for col in range(0, self.cols):
            self.boardMatrix.append([])
            for row in range(0, self.rows):
                self.boardMatrix[col].append(None)

        self.setScene(QtGui.QGraphicsScene(self.parent()))
        self.scene = self.scene()
        self.scene.setSceneRect(0,0,360,300)

        #load and resize images to fit squarely into grid
        self.xImage = QtGui.QPixmap(os.path.abspath('data/x.png')).scaled(self.col_width, self.row_height)
        self.yImage = QtGui.QPixmap(os.path.abspath('data/y.png')).scaled(self.col_width, self.row_height)

        self.addGridToScene()

    def mousePressEvent(self,event):
        """
        Handles event of player clicking in the grid
        """
        x,y = self.screenToLogical(event.pos())
        if not self.boardMatrix[x][y]:
            self.boardMatrix[x][y] = self.scene.addPixmap(self.xImage)
            screen_position = self.logicalToScreen((x,y))
            self.boardMatrix[x][y].setOffset(*screen_position)

            #TODO: hack to pass this event to main, find optimal way of doing this (possibly with event filter)
            super(BoardView, self).mousePressEvent(event)

    def addGridToScene(self):
        """
        create the grid for the board
        """
        pen = QtGui.QPen(QtCore.Qt.black, .3, QtCore.Qt.SolidLine)
        #horizontal then vertical lines
        [self.scene.addLine(0, (y+1)*self.row_height, self.width, (y+1)*self.row_height, pen) for y in range(0,self.rows-1)]
        [self.scene.addLine((x+1)*self.col_width, 0, (x+1)*self.col_width, self.height, pen) for x in range(0,self.cols-1)]

    def screenToLogical(self, position):
        """
        converts screen position to logical gameboard coordinates
        """
        x = int(position.x()/self.col_width)
        y = int(position.y()/self.row_height)

        #limit to screen boundaries
        x = min( max(x, 0) , self.cols-1)
        y = min( max(y, 0) , self.rows-1)

        return (x,y)

    def winCheck(self):
        """
        only written for 3x3; refactor if board is reused for larger
        """

        #rows
        for i in range(0,self.rows):
            if type(self.boardMatrix[0][i]) == type(self.boardMatrix[1][i]) == type(self.boardMatrix[2][i]) \
                and self.boardMatrix[0][i] is not None:
                    return True
        #columns
        for i in range(0,self.cols):
            if type(self.boardMatrix[i][0]) == type(self.boardMatrix[i][1]) == type(self.boardMatrix[i][2]) \
                and self.boardMatrix[i][0] is not None:
                    return True
        #diagonal
        #anti-diagonal




    def logicalToScreen(self, xyTuple):
        return (int(xyTuple[0]*self.col_width), int(xyTuple[1]*self.row_height))

    def clearBoard(self):
        """
        clears the board by resetting all points to none & removing graphics
        """
        del self.boardMatrix
        self.boardMatrix = []
        for col in range(0, self.cols):
            self.boardMatrix.append([])
            for row in range(0, self.rows):
                self.boardMatrix[col].append(None)
        #remove graphics
        for item in self.scene.items():
            if type(item) is QtGui.QGraphicsPixmapItem:
                self.scene.removeItem(item)

    def getMatrix(self):
        return self.boardMatrix