# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'C:\Users\Roland\Python\Tic-Tac-Toe\data\launch.ui'
#
# Created: Fri Jul 26 10:58:14 2013
#      by: PyQt4 UI code generator 4.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(451, 404)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.graphicsView = QtGui.QGraphicsView(self.centralwidget)
        self.graphicsView.setGeometry(QtCore.QRect(40, 70, 360, 300))
        self.graphicsView.setObjectName(_fromUtf8("graphicsView"))
        self.newGameButton = QtGui.QPushButton(self.centralwidget)
        self.newGameButton.setGeometry(QtCore.QRect(20, 10, 161, 51))
        self.newGameButton.setObjectName(_fromUtf8("newGameButton"))
        self.winnerLabel = QtGui.QLabel(self.centralwidget)
        self.winnerLabel.setGeometry(QtCore.QRect(230, 20, 141, 31))
        self.winnerLabel.setText(_fromUtf8("Player goes first"))
        self.winnerLabel.setObjectName(_fromUtf8("winnerLabel"))
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.newGameButton.setText(_translate("MainWindow", "New Game", None))

