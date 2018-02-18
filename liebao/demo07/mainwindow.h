#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTextEdit;
class QAction;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createActions(); // 创建动作
    void createMenus();
    void createToolBars();
    void createStatus();

public slots:
    void slotNewFile();
    void slotOpenFile();
    void slotSaveFile();
    void slotCopy();
    void slotCut();
    void slotPaste();
    void slotAbout();

private:

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *aboutMenu;

    QToolBar *fileTools;
    QToolBar *editTools;

    QAction *fileOpenAction;
    QAction *fileNewAction;
    QAction *fileSaveAction;
    QAction *exitAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *aboutAction;

    QTextEdit *text;
};

#endif // MAINWINDOW_H
