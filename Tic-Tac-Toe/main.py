__author__ = 'Roland'

from PyQt4 import QtCore, QtGui
from ui.ui import Ui_MainWindow
from ui.boardView import BoardView
from ai import Ai

class StartQt4(QtGui.QMainWindow):

    def __init__(self, parent=None):
        QtGui.QWidget.__init__(self,parent)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.view = BoardView(self.ui.graphicsView)
        self.opponent = Ai()

        #event bindings
        QtCore.QObject.connect(self.ui.newGameButton,QtCore.SIGNAL("clicked()"),self.newGame)

    def newGame(self):
        self.view.clearBoard()
        self.board = None
        self.ui.winnerLabel.setText("Player goes first")

    def mousePressEvent(self, event):
        """
        Event executed after every mouse press; All internal game loop logic contained here
        """
        if self.view.winCheck():
            self.playerWin()

        #AI move
        self.opponent.updateBoard(self.view.boardMatrix)
        self.opponent.move()

        #check win

    def playerWin(self):
        self.ui.winnerLabel.setText("Congratulations! You won!")

if __name__ == '__main__':
    import sys
    app = QtGui.QApplication(sys.argv)
    start = StartQt4()
    start.show()
    sys.exit(app.exec_()) #enters qt's event loop

    """
    while !exit:
        process next posted event
    while spontaneous event queue:
        process next spontaneous event
    while posted event queue:
        process next posted event
    """