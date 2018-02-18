#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel *sTip = new QLabel(tr("Ready"));     // 初启动是状态栏的显示
    statusBar()->addWidget(sTip);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QMessageBox msgBox;
    msgBox.setText(tr("Open!"));
    msgBox.exec();
}

void MainWindow::on_actionNew_triggered()
{
    QMessageBox msgBox;
    msgBox.setText(tr("New!"));
    msgBox.exec();
}

void MainWindow::on_actionSave_triggered()
{
    QMessageBox msgBox;
    msgBox.setText(tr("Save!"));
    msgBox.exec();
}

void MainWindow::on_actionExit_triggered()
{
    QMessageBox msgBox;
    msgBox.setText(tr("Exit!"));
    msgBox.exec();
}

void MainWindow::on_actionCopy_triggered()
{
    QMessageBox msgBox;
    msgBox.setText(tr("Copy!"));
    msgBox.exec();
}

void MainWindow::on_actionCut_triggered()
{
    QMessageBox msgBox;
    msgBox.setText(tr("Cut!"));
    msgBox.exec();
}

void MainWindow::on_actionPaste_triggered()
{
    QMessageBox msgBox;
    msgBox.setText(tr("Paste!"));
    msgBox.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText(tr("About!"));
    msgBox.exec();
}
