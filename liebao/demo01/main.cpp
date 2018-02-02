#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建一个 label(标签)，标签内容为 Hello Qt！
    //QLabel *label = new QLabel("Hello Qt!");

    // 创建一个 label(标签)，标签内容为 Hello Qt！(文字以 html 语法显示)
    QLabel *label = new QLabel("<h1><i>Hello </i>"
                               "<font color=red>Qt!</font></h1>");

    label->show();

    return a.exec();
}
