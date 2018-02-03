#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLineEdit>


#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
{
    // 创建一个带有快捷键 ALT+W 的标签
    label = new QLabel(tr("找什么(&W)"));
    lineEdit = new QLineEdit;
    // 设置编辑器作为标签的伙伴。按下标签的快捷键时， lineEdit 会接受焦点
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("区分大小写(&C)"));
    backwardCheckBox = new QCheckBox(tr("向后查找(&B)"));

    findButton = new QPushButton(tr("开始查找(&F)"));
    findButton->setEnabled(false); // 将按钮禁止

    closeButton = new QPushButton(tr("关闭"));

    connect(lineEdit,SIGNAL(textChanged(QString)),
                this,SLOT(enabledFindButton(QString)));

    connect(findButton,SIGNAL(clicked()),
                this,SLOT(findNext(QString,Qt::CaseSensitivity)));

    connect(closeButton,SIGNAL(clicked()),
                this,SLOT(close()));

    // 水平布局  加入部件  label 和 lineEdit
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    // 垂直布局  加入水平布局(topLeftLayout) 和 控件(caseCheckBox、backwardCheckBox)
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    // 垂直布局 加入两个按钮部件
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    // 实现布局器的空白控件分配
    rightLayout->addStretch();

    // 水平布局 加入之前布局
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    // 实现控件的布局
    setLayout(mainLayout);

    setWindowTitle(tr("查找对话框"));
    setFixedHeight(sizeHint().height());
}

void FindDialog::enabledFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}

void FindDialog::findClicked()
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ?
                Qt::CaseSensitive : Qt::CaseInsensitive;
    if(backwardCheckBox->isChecked())
    {
        emit findPrevious(text,cs);
    }else{
        emit findNext(text,cs);
    }
}
