#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::test() {

}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}


MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_bConnect_clicked() {

}

void MainWindow::on_bSend_clicked() {

}
