/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
    QCheckBox *checkBox;
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(682, 600);
        MainWindow->setMinimumSize(QSize(682, 600));
        MainWindow->setMaximumSize(QSize(682, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        eLPort = new QLineEdit(centralWidget);
        eLPort->setObjectName(QStringLiteral("eLPort"));
        eLPort->setGeometry(QRect(10, 30, 71, 25));
        eLPort->setCursorPosition(5);
        eRHost = new QLineEdit(centralWidget);
        eRHost->setObjectName(QStringLiteral("eRHost"));
        eRHost->setGeometry(QRect(90, 30, 251, 25));
        bConnect = new QPushButton(centralWidget);
        bConnect->setObjectName(QStringLiteral("bConnect"));
        bConnect->setGeometry(QRect(430, 20, 161, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 57, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 10, 73, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 10, 72, 17));
        eRPort = new QLineEdit(centralWidget);
        eRPort->setObjectName(QStringLiteral("eRPort"));
        eRPort->setGeometry(QRect(350, 30, 71, 25));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(600, 0, 71, 91));
        rTCP = new QRadioButton(groupBox);
        rTCP->setObjectName(QStringLiteral("rTCP"));
        rTCP->setGeometry(QRect(10, 30, 51, 23));
        rTCP->setChecked(true);
        rUDP = new QRadioButton(groupBox);
        rUDP->setObjectName(QStringLiteral("rUDP"));
        rUDP->setGeometry(QRect(10, 60, 61, 23));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 70, 82, 23));
        bSend = new QPushButton(centralWidget);
        bSend->setObjectName(QStringLiteral("bSend"));
        bSend->setGeometry(QRect(120, 60, 471, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(140, 510, 31, 21));
        eIn = new QLineEdit(centralWidget);
        eIn->setObjectName(QStringLiteral("eIn"));
        eIn->setGeometry(QRect(160, 510, 71, 25));
        eIn->setReadOnly(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 510, 31, 21));
        eOut = new QLineEdit(centralWidget);
        eOut->setObjectName(QStringLiteral("eOut"));
        eOut->setGeometry(QRect(270, 510, 71, 25));
        eOut->setReadOnly(true);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 510, 31, 21));
        eSize = new QLineEdit(centralWidget);
        eSize->setObjectName(QStringLiteral("eSize"));
        eSize->setGeometry(QRect(380, 510, 101, 25));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(490, 510, 61, 21));
        eMutation = new QLineEdit(centralWidget);
        eMutation->setObjectName(QStringLiteral("eMutation"));
        eMutation->setGeometry(QRect(550, 510, 81, 25));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(640, 510, 54, 21));
        lStatus = new QLabel(centralWidget);
        lStatus->setObjectName(QStringLiteral("lStatus"));
        lStatus->setGeometry(QRect(10, 540, 621, 17));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 510, 31, 21));
        eId = new QLineEdit(centralWidget);
        eId->setObjectName(QStringLiteral("eId"));
        eId->setGeometry(QRect(30, 510, 101, 25));
        eId->setReadOnly(true);
        tHex = new QTableWidget(centralWidget);
        tHex->setObjectName(QStringLiteral("tHex"));
        tHex->setGeometry(QRect(5, 101, 671, 401));
        tHex->setMinimumSize(QSize(1, 0));
        QFont font;
        font.setFamily(QStringLiteral("Unifont"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tHex->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 682, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuScripts = new QMenu(menuBar);
        menuScripts->setObjectName(QStringLiteral("menuScripts"));
        menuTools_2 = new QMenu(menuBar);
        menuTools_2->setObjectName(QStringLiteral("menuTools_2"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        QWidget::setTabOrder(eLPort, eRHost);
        QWidget::setTabOrder(eRHost, eRPort);
        QWidget::setTabOrder(eRPort, bConnect);
        QWidget::setTabOrder(bConnect, rTCP);
        QWidget::setTabOrder(rTCP, rUDP);
        QWidget::setTabOrder(rUDP, checkBox);
        QWidget::setTabOrder(checkBox, bSend);
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

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "rproxy - multi protocol reversing proxy", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        eLPort->setToolTip(QApplication::translate("MainWindow", "local port number to open for receiving connections from the client.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        eLPort->setText(QApplication::translate("MainWindow", "12345", Q_NULLPTR));
        eRHost->setText(QApplication::translate("MainWindow", "127.0.0.1", Q_NULLPTR));
        bConnect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "local port:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "remote host:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "remote port:", Q_NULLPTR));
        eRPort->setText(QApplication::translate("MainWindow", "8080", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Protocol:", Q_NULLPTR));
        rTCP->setText(QApplication::translate("MainWindow", "TCP", Q_NULLPTR));
        rUDP->setText(QApplication::translate("MainWindow", "UDP", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Auto send", Q_NULLPTR));
        bSend->setText(QApplication::translate("MainWindow", ">>> Send >>>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "IN:", Q_NULLPTR));
        eIn->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "OUT:", Q_NULLPTR));
        eOut->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Size:", Q_NULLPTR));
        eSize->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Mutation:", Q_NULLPTR));
        eMutation->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "%", Q_NULLPTR));
        lStatus->setText(QApplication::translate("MainWindow", "Dissconnected", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "ID:", Q_NULLPTR));
        eId->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuScripts->setTitle(QApplication::translate("MainWindow", "Scripts", Q_NULLPTR));
        menuTools_2->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
