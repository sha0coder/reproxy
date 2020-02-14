/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

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
        bConnect->setGeometry(QRect(430, 20, 181, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 57, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 10, 73, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 10, 72, 17));
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
        label_7->setGeometry(QRect(490, 510, 61, 21));
        eMutation = new QLineEdit(centralWidget);
        eMutation->setObjectName(QString::fromUtf8("eMutation"));
        eMutation->setGeometry(QRect(550, 510, 81, 25));
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
        menuBar->setGeometry(QRect(0, 0, 704, 21));
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "rproxy - multi protocol reversing proxy", nullptr));
        actionLoad_Hex->setText(QCoreApplication::translate("MainWindow", "Load Hex", nullptr));
        actionLoad_Bin->setText(QCoreApplication::translate("MainWindow", "Load  Bin", nullptr));
        actionSave_Hex->setText(QCoreApplication::translate("MainWindow", "Save Hex", nullptr));
        actionSave_Bin->setText(QCoreApplication::translate("MainWindow", "Save Bin", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionManual->setText(QCoreApplication::translate("MainWindow", "Manual", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionAbout_2->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionSave_all->setText(QCoreApplication::translate("MainWindow", "Save all", nullptr));
        actionRadare->setText(QCoreApplication::translate("MainWindow", "Radare", nullptr));
        actionLoad_script->setText(QCoreApplication::translate("MainWindow", "Load script", nullptr));
        actionScripting->setText(QCoreApplication::translate("MainWindow", "Scripting", nullptr));
#if QT_CONFIG(tooltip)
        eLPort->setToolTip(QCoreApplication::translate("MainWindow", "local port number to open for receiving connections from the client.", nullptr));
#endif // QT_CONFIG(tooltip)
        eLPort->setText(QCoreApplication::translate("MainWindow", "12345", nullptr));
        eRHost->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        bConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "local port:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "remote host:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "remote port:", nullptr));
        eRPort->setText(QCoreApplication::translate("MainWindow", "8080", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Protocol:", nullptr));
        rTCP->setText(QCoreApplication::translate("MainWindow", "TCP", nullptr));
        rUDP->setText(QCoreApplication::translate("MainWindow", "UDP", nullptr));
        chkAutoSend->setText(QCoreApplication::translate("MainWindow", "Auto send ", nullptr));
        bSend->setText(QCoreApplication::translate("MainWindow", ">>> Send >>>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "IN:", nullptr));
        eIn->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "OUT:", nullptr));
        eOut->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Size:", nullptr));
        eSize->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Mutation:", nullptr));
        eMutation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        lStatus->setText(QCoreApplication::translate("MainWindow", "Dissconnected", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        eId->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuScripts->setTitle(QCoreApplication::translate("MainWindow", "Scripts", nullptr));
        menuTools_2->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
