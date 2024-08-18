#include "widget.h"
#include "ui_widget.h"

#include <QFile>

//添加一个新的功能
#define ADD_FUNC_WIDGET(funcName, className) \
{ \
    className *pWidget = new className(this); \
    QListWidgetItem *pItem = new QListWidgetItem(funcName); \
    pItem->setTextAlignment(Qt::AlignCenter); \
    ui->listWidget->addItem(pItem); \
    ui->stackedWidget->addWidget(pWidget); \
    m_funcWidgets[funcName] = pWidget; \
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    m_curWinSize = 0;

    ui->setupUi(this);

    initMainWindow();
    initStyleSheet();
    initFuncWidgets();
    initConnect();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initMainWindow()
{
    this->setWindowFlag(Qt::FramelessWindowHint);

    ui->btn_close->setIcon(QIcon(":/icon/image/close.png"));
    ui->btn_max->setIcon(QIcon(":/icon/image/max.png"));
    ui->btn_min->setIcon(QIcon(":/icon/image/min.png"));

    ui->label_tool_name->setText("CYG-TOOL");
}

void Widget::initStyleSheet()
{
    QFile file(":/stylesheet/style/simple.qss");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    QString styleSheet = in.readAll();
    file.close();

    this->setStyleSheet(styleSheet);
}

void Widget::initFuncWidgets()
{
    ADD_FUNC_WIDGET("KBQ", QWidget);

    ui->label_func->setText(m_funcWidgets.begin()->first);
    ui->listWidget->setCurrentRow(0);
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::initConnect()
{
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*item)), this, SLOT(sl_listWidget_clicked(QListWidgetItem*item)));
}

void Widget::on_btn_min_clicked()
{
    this->showMinimized();
}

void Widget::on_btn_max_clicked()
{
    if (m_curWinSize == 0)
    {
        this->showMaximized();
        m_curWinSize = 1;
    }
    else
    {
        this->showNormal();
        m_curWinSize = 0;
    }
}

void Widget::on_btn_close_clicked()
{
    this->close();
}

void Widget::sl_listWidget_clicked(QListWidgetItem *item)
{
    auto it = m_funcWidgets.find(item->text());

    if (it != m_funcWidgets.end())
    {
        ui->label_func->setText(item->text());
        ui->stackedWidget->setCurrentWidget(it->second);
    }
}
