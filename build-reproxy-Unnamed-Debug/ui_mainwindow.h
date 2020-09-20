/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_Hex;
    QAction *actionLoad_Bin;
    QAction *actionSave_Hex;
    QAction *actionSave_Bin;
    QAction *actionQuit;
    QAction *actionManual;
    QAction *actionAbout;
    QAction *actionAbout_2;
    QAction *actionSave_all;
    QAction *actionRadare;
    QAction *actionLoad_script;
    QAction *actionScripting;
    QWidget *centralWidget;
    QLineEdit *eLPort;
    QLineEdit *eRHost;
    QPushButton *bConnect;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *eRPort;
    QGroupBox *groupBox;
    QRadioButton *rTCP;
    QRadioButton *rUDP;
    QCheckBox *chkAutoSend;
    QPushButton *bSend;
    QLabel *label_4;
    QLineEdit *eIn;
    QLabel *label_5;
    QLineEdit *eOut;
    QLabel *label_6;
    QLineEdit *eSize;
    QLabel *label_7;
    QLineEdit *eMutation;
    QLabel *label_8;
    QLabel *lStatus;
    QLabel *label_9;
    QLineEdit *eId;
    QTableWidget *tHex;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuScripts;
    QMenu *menuTools_2;
    QMenu *menuHelp;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(704, 600);
        MainWindow->setMinimumSize(QSize(600, 600));
        MainWindow->setMaximumSize(QSize(704, 600));
        actionLoad_Hex = new QAction(MainWindow);
        actionLoad_Hex->setObjectName(QString::fromUtf8("actionLoad_Hex"));
        actionLoad_Bin = new QAction(MainWindow);
        actionLoad_Bin->setObjectName(QString::fromUtf8("actionLoad_Bin"));
        actionSave_Hex = new QAction(MainWindow);
        actionSave_Hex->setObjectName(QString::fromUtf8("actionSave_Hex"));
        actionSave_Bin = new QAction(MainWindow);
        actionSave_Bin->setObjectName(QString::fromUtf8("actionSave_Bin"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionManual = new QAction(MainWindow);
        actionManual->setObjectName(QString::fromUtf8("actionManual"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_2 = new QAction(MainWindow);
        actionAbout_2->setObjectName(QString::fromUtf8("actionAbout_2"));
        actionSave_all = new QAction(MainWindow);
        actionSave_all->setObjectName(QString::fromUtf8("actionSave_all"));
        actionRadare = new QAction(MainWindow);
        actionRadare->setObjectName(QString::fromUtf8("actionRadare"));
        actionLoad_script = new QAction(MainWindow);
        actionLoad_script->setObjectName(QString::fromUtf8("actionLoad_script"));
        actionScripting = new QAction(MainWindow);
        actionScripting->setObjectName(QString::fromUtf8("actionScripting"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        eLPort = new QLineEdit(centralWidget);
        eLPort->setObjectName(QString::fromUtf8("eLPort"));
        eLPort->setGeometry(QRect(10, 30, 71, 25));
        eLPort->setCursorPosition(5);
        eRHost = new QLineEdit(centralWidget);
        eRHost->setObjectName(QString::fromUtf8("eRHost"));
        eRHost->setGeometry(QRect(90, 30, 251, 25));
        bConnect = new QPushButton(centralWidget);
        bConnect->setObjectName(QString::fromUtf8("bConnect"));
        bConnect->setGeometry(QRect(440, 20, 171, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 71, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 10, 91, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 10, 81, 17));
        eRPort = new QLineEdit(centralWidget);
        eRPort->setObjectName(QString::fromUtf8("eRPort"));
        eRPort->setGeometry(QRect(350, 30, 71, 25));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(620, 0, 71, 91));
        rTCP = new QRadioButton(groupBox);
        rTCP->setObjectName(QString::fromUtf8("rTCP"));
        rTCP->setGeometry(QRect(10, 30, 51, 23));
        rTCP->setChecked(true);
        rUDP = new QRadioButton(groupBox);
        rUDP->setObjectName(QString::fromUtf8("rUDP"));
        rUDP->setGeometry(QRect(10, 60, 61, 23));
        chkAutoSend = new QCheckBox(centralWidget);
        chkAutoSend->setObjectName(QString::fromUtf8("chkAutoSend"));
        chkAutoSend->setEnabled(true);
        chkAutoSend->setGeometry(QRect(10, 70, 101, 23));
        chkAutoSend->setChecked(false);
        bSend = new QPushButton(centralWidget);
        bSend->setObjectName(QString::fromUtf8("bSend"));
        bSend->setGeometry(QRect(120, 60, 491, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 510, 31, 21));
        eIn = new QLineEdit(centralWidget);
        eIn->setObjectName(QString::fromUtf8("eIn"));
        eIn->setGeometry(QRect(160, 510, 71, 25));
        eIn->setReadOnly(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(240, 510, 31, 21));
        eOut = new QLineEdit(centralWidget);
        eOut->setObjectName(QString::fromUtf8("eOut"));
        eOut->setGeometry(QRect(270, 510, 71, 25));
        eOut->setReadOnly(true);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(350, 510, 31, 21));
        eSize = new QLineEdit(centralWidget);
        eSize->setObjectName(QString::fromUtf8("eSize"));
        eSize->setGeometry(QRect(380, 510, 101, 25));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(490, 510, 71, 21));
        eMutation = new QLineEdit(centralWidget);
        eMutation->setObjectName(QString::fromUtf8("eMutation"));
        eMutation->setGeometry(QRect(560, 510, 71, 25));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(640, 510, 54, 21));
        lStatus = new QLabel(centralWidget);
        lStatus->setObjectName(QString::fromUtf8("lStatus"));
        lStatus->setGeometry(QRect(10, 540, 621, 17));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 510, 31, 21));
        eId = new QLineEdit(centralWidget);
        eId->setObjectName(QString::fromUtf8("eId"));
        eId->setGeometry(QRect(30, 510, 101, 25));
        eId->setReadOnly(true);
        tHex = new QTableWidget(centralWidget);
        tHex->setObjectName(QString::fromUtf8("tHex"));
        tHex->setGeometry(QRect(5, 101, 691, 401));
        tHex->setMinimumSize(QSize(1, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Unifont"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tHex->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 704, 34));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuScripts = new QMenu(menuBar);
        menuScripts->setObjectName(QString::fromUtf8("menuScripts"));
        menuTools_2 = new QMenu(menuBar);
        menuTools_2->setObjectName(QString::fromUtf8("menuTools_2"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        QWidget::setTabOrder(eLPort, eRHost);
        QWidget::setTabOrder(eRHost, eRPort);
        QWidget::setTabOrder(eRPort, bConnect);
        QWidget::setTabOrder(bConnect, rTCP);
        QWidget::setTabOrder(rTCP, rUDP);
        QWidget::setTabOrder(rUDP, chkAutoSend);
        QWidget::setTabOrder(chkAutoSend, bSend);
        QWidget::setTabOrder(bSend, eIn);
        QWidget::setTabOrder(eIn, eOut);
        QWidget::setTabOrder(eOut, eSize);
        QWidget::setTabOrder(eSize, eMutation);
        QWidget::setTabOrder(eMutation, eId);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuScripts->menuAction());
        menuBar->addAction(menuTools_2->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLoad_Hex);
        menuFile->addAction(actionLoad_Bin);
        menuFile->addAction(actionSave_Hex);
        menuFile->addAction(actionSave_Bin);
        menuFile->addAction(actionSave_all);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuScripts->addAction(actionLoad_script);
        menuTools_2->addAction(actionRadare);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout_2);
        menuHelp->addAction(actionScripting);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "rproxy - multi protocol reversing proxy", 0, QApplication::UnicodeUTF8));
        actionLoad_Hex->setText(QApplication::translate("MainWindow", "Load Hex", 0, QApplication::UnicodeUTF8));
        actionLoad_Bin->setText(QApplication::translate("MainWindow", "Load  Bin", 0, QApplication::UnicodeUTF8));
        actionSave_Hex->setText(QApplication::translate("MainWindow", "Save Hex", 0, QApplication::UnicodeUTF8));
        actionSave_Bin->setText(QApplication::translate("MainWindow", "Save Bin", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionManual->setText(QApplication::translate("MainWindow", "Manual", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionAbout_2->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionSave_all->setText(QApplication::translate("MainWindow", "Save all", 0, QApplication::UnicodeUTF8));
        actionRadare->setText(QApplication::translate("MainWindow", "Radare", 0, QApplication::UnicodeUTF8));
        actionLoad_script->setText(QApplication::translate("MainWindow", "Load script", 0, QApplication::UnicodeUTF8));
        actionScripting->setText(QApplication::translate("MainWindow", "Scripting", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        eLPort->setToolTip(QApplication::translate("MainWindow", "local port number to open for receiving connections from the client.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        eLPort->setText(QApplication::translate("MainWindow", "12345", 0, QApplication::UnicodeUTF8));
        eRHost->setText(QApplication::translate("MainWindow", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        bConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "local port:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "remote host:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "remote port:", 0, QApplication::UnicodeUTF8));
        eRPort->setText(QApplication::translate("MainWindow", "8080", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Protocol:", 0, QApplication::UnicodeUTF8));
        rTCP->setText(QApplication::translate("MainWindow", "TCP", 0, QApplication::UnicodeUTF8));
        rUDP->setText(QApplication::translate("MainWindow", "UDP", 0, QApplication::UnicodeUTF8));
        chkAutoSend->setText(QApplication::translate("MainWindow", "Auto send ", 0, QApplication::UnicodeUTF8));
        bSend->setText(QApplication::translate("MainWindow", ">>> Send >>>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "IN:", 0, QApplication::UnicodeUTF8));
        eIn->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "OUT:", 0, QApplication::UnicodeUTF8));
        eOut->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Size:", 0, QApplication::UnicodeUTF8));
        eSize->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Mutation:", 0, QApplication::UnicodeUTF8));
        eMutation->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        lStatus->setText(QApplication::translate("MainWindow", "Dissconnected", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "ID:", 0, QApplication::UnicodeUTF8));
        eId->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuScripts->setTitle(QApplication::translate("MainWindow", "Scripts", 0, QApplication::UnicodeUTF8));
        menuTools_2->setTitle(QApplication::translate("MainWindow", "Tools", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
