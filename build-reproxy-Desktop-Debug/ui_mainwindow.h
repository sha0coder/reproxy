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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
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
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox;
    QPushButton *bSend;
    QTableView *tHex;
    QLabel *lStatus;
    QLabel *label_4;
    QLineEdit *eIn;
    QLabel *label_5;
    QLineEdit *eOut;
    QLabel *label_6;
    QLineEdit *eSize;
    QLabel *label_7;
    QLineEdit *eMutation;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(662, 600);
        MainWindow->setMinimumSize(QSize(662, 600));
        MainWindow->setMaximumSize(QSize(662, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        eLPort = new QLineEdit(centralWidget);
        eLPort->setObjectName(QStringLiteral("eLPort"));
        eLPort->setGeometry(QRect(10, 30, 61, 25));
        eRHost = new QLineEdit(centralWidget);
        eRHost->setObjectName(QStringLiteral("eRHost"));
        eRHost->setGeometry(QRect(80, 30, 251, 25));
        bConnect = new QPushButton(centralWidget);
        bConnect->setObjectName(QStringLiteral("bConnect"));
        bConnect->setGeometry(QRect(410, 20, 161, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 57, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 10, 73, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(330, 10, 72, 17));
        eRPort = new QLineEdit(centralWidget);
        eRPort->setObjectName(QStringLiteral("eRPort"));
        eRPort->setGeometry(QRect(340, 30, 61, 25));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(580, 0, 71, 91));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 30, 51, 23));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 60, 61, 23));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 70, 82, 23));
        bSend = new QPushButton(centralWidget);
        bSend->setObjectName(QStringLiteral("bSend"));
        bSend->setGeometry(QRect(100, 60, 471, 31));
        tHex = new QTableView(centralWidget);
        tHex->setObjectName(QStringLiteral("tHex"));
        tHex->setGeometry(QRect(10, 100, 641, 401));
        lStatus = new QLabel(centralWidget);
        lStatus->setObjectName(QStringLiteral("lStatus"));
        lStatus->setGeometry(QRect(20, 540, 611, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 510, 31, 21));
        eIn = new QLineEdit(centralWidget);
        eIn->setObjectName(QStringLiteral("eIn"));
        eIn->setGeometry(QRect(30, 510, 41, 25));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 510, 31, 21));
        eOut = new QLineEdit(centralWidget);
        eOut->setObjectName(QStringLiteral("eOut"));
        eOut->setGeometry(QRect(110, 510, 41, 25));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(160, 510, 31, 21));
        eSize = new QLineEdit(centralWidget);
        eSize->setObjectName(QStringLiteral("eSize"));
        eSize->setGeometry(QRect(190, 510, 111, 25));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(510, 510, 61, 21));
        eMutation = new QLineEdit(centralWidget);
        eMutation->setObjectName(QStringLiteral("eMutation"));
        eMutation->setGeometry(QRect(570, 510, 81, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 662, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "rproxy - multi protocol reversing proxy", Q_NULLPTR));
        bConnect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "local port:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "remote host:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "remote port:", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Protocol:", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "TCP", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "UDP", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Auto send", Q_NULLPTR));
        bSend->setText(QApplication::translate("MainWindow", ">>> Send >>>", Q_NULLPTR));
        lStatus->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "IN:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "OUT:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Size:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Mutation:", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
