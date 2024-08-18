#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QMouseEvent>

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
    , ui(new Ui::widget_main)
{
    m_curWinSize = 0;
    m_mouPress = false;

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

void Widget::mousePressEvent(QMouseEvent *event)
{
    m_mouPress = true;
    if (event->button() == Qt::LeftButton)//判断左键是否按下
    {
        m_mouPress = true;
        m_mouPoint = event->pos();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QSize size = this->size();

    if (m_mouPress &&
        m_mouPoint.rx() < size.rwidth() - 100 && m_mouPoint.ry() < 30)
    {
        this->move(event->pos() - m_mouPoint + pos());
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_mouPress = false;
}

void Widget::initMainWindow()
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowTitle("cyg-tool");

    ui->btn_close->setIcon(QIcon(":/icon/image/close.png"));
    ui->btn_max->setIcon(QIcon(":/icon/image/max.png"));
    ui->btn_min->setIcon(QIcon(":/icon/image/min.png"));
    ui->label_icon->setPixmap(QPixmap(":/icon/image/github_40.png"));

    ui->btn_setting->setText("设置");
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
    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(sl_listWidget_clicked(QListWidgetItem*)));
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
        this->resize(800,600);
        m_curWinSize = 0;
    }
}

void Widget::on_btn_close_clicked()
{
    this->close();
}

void Widget::sl_listWidget_clicked(QListWidgetItem*item)
{
    auto it = m_funcWidgets.find(item->text());

    if (it != m_funcWidgets.end())
    {
        ui->label_func->setText(item->text());
        ui->stackedWidget->setCurrentWidget(it->second);
    }
}
