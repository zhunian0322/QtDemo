#include "mainwindow.h"

#include <QtWidgets>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("My Main Window"));       // 设置窗口标题

    // 创建文本编辑器，并设置为中央窗口
    text = new QTextEdit(this);
    setCentralWidget(text);

    createActions();
    createMenus();
    createToolBars();
    createStatus();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{
    fileNewAction = new QAction(QIcon(":/images/new.png"),tr("New"),this);
    fileNewAction->setShortcut(tr("Ctrl+N"));
    connect(fileNewAction,SIGNAL(triggered()),this, SLOT(slotNewFile()));

    fileOpenAction = new QAction(QIcon(":/images/open.png"),tr("Open"),this);
    fileOpenAction->setShortcut(tr("Ctrl+O"));  // 设置快捷健
    connect(fileOpenAction,SIGNAL(triggered()),this, SLOT(slotOpenFile()));  // 触发动作执行相应槽函数

    fileSaveAction = new QAction(QIcon(":/images/save.png"),tr("Save"),this);
    fileSaveAction->setShortcut(tr("Ctrl+S"));
    connect(fileSaveAction, SIGNAL(triggered()), this, SLOT(slotSaveFile()));

    exitAction = new QAction(tr("Exit"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    copyAction = new QAction(QIcon(":/images/copy.png"),tr("Copy"),this);
    copyAction->setShortcut(tr("Ctrl+C"));
    connect(copyAction, SIGNAL(triggered()), this, SLOT(slotCopy()));

    cutAction = new QAction(QIcon(":/images/cut.png"),tr("Cut"),this);
    cutAction->setShortcut(tr("Ctrl+X"));
    connect(cutAction, SIGNAL(triggered()), this, SLOT(slotCut()));

    pasteAction = new QAction(QIcon(":/images/paste.png"),tr("Paste"),this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    connect(pasteAction, SIGNAL(triggered()), this, SLOT(slotPaste()));

    aboutAction = new QAction(tr("About"),this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(slotAbout()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("File"));
    editMenu = menuBar()->addMenu(tr("Edit"));
    aboutMenu = menuBar()->addMenu(tr("Help"));

    fileMenu->addAction(fileOpenAction);
    fileMenu->addAction(fileNewAction);
    fileMenu->addAction(fileSaveAction);
    fileMenu->addAction(exitAction);

    editMenu->addAction(copyAction);
    editMenu->addAction(cutAction);
    editMenu->addAction(pasteAction);

    aboutMenu->addAction(aboutAction);

}

void MainWindow::createToolBars()
{
   fileTools = addToolBar(tr("File"));
   editTools = addToolBar(tr("Edit"));

   fileTools->addAction(fileOpenAction);
   fileTools->addAction(fileNewAction);
   fileTools->addAction(fileSaveAction);

   editTools->addAction(copyAction);
   editTools->addAction(cutAction);
   editTools->addAction(pasteAction);
}

void MainWindow::createStatus()
{
    QLabel *tipLabel = new QLabel(tr("Ready!"));
    statusBar()->addWidget(tipLabel);
}



void MainWindow::slotAbout()
{
    // 弹出消息对话框
    QMessageBox msgBox;
    msgBox.setText(tr("About!"));

    msgBox.exec();
}

void MainWindow::slotCopy()
{
    // 弹出消息对话框
    QMessageBox msgBox;
    msgBox.setText(tr("Copy!"));

    msgBox.exec();
}

void MainWindow::slotCut()
{
    // 弹出消息对话框
    QMessageBox msgBox;
    msgBox.setText(tr("Cut!"));

    msgBox.exec();
}

void MainWindow::slotNewFile()
{
    // 弹出消息对话框
    QMessageBox msgBox;
    msgBox.setText(tr("File New!"));

    msgBox.exec();
}

void MainWindow::slotOpenFile()
{
    // 弹出消息对话框
    QMessageBox msgBox;
    msgBox.setText(tr("File Open!"));

    msgBox.exec();
}

void MainWindow::slotPaste()
{
    // 弹出消息对话框
    QMessageBox msgBox;
    msgBox.setText(tr("Paste!"));

    msgBox.exec();

}

void MainWindow::slotSaveFile()
{
    // 弹出消息对话框
    QMessageBox msgBox;
    msgBox.setText(tr("File Save!"));

    msgBox.exec();
}
