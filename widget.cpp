#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QMouseEvent>

//功能头文件
#include "funcs/kbq/kbqwidget.h"
#include "funcs/hex_txt_convert/hex_txt_convert.h"
#include "funcs/http_post/http_post_widget.h"

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
    initStyleSheet(); /* stylesheet的设置在功能窗体之前，功能窗体的外观由其自定义 */
    initFuncWidgets();
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
    this->setWindowTitle("tool-box");

    ui->btn_close->setIcon(QIcon(":/icon/image/close.png"));
    ui->btn_max->setIcon(QIcon(":/icon/image/max.png"));
    ui->btn_min->setIcon(QIcon(":/icon/image/min.png"));
    ui->label_icon->setPixmap(QPixmap(":/icon/image/github_32.png"));

    ui->label_tool_name->setText("TOOL-BOX");
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
    ADD_FUNC_WIDGET("KBQ", KBQWidget);
    ADD_FUNC_WIDGET("HexTxt", HexTxtConvert);
    ADD_FUNC_WIDGET("HttpPost", HttpPostWidget);

    ui->label_func->setText(m_funcWidgets.begin()->first);
    ui->listWidget->setCurrentRow(0);
    ui->stackedWidget->setCurrentIndex(0);
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

        //居中
        QScreen *screen = QGuiApplication::primaryScreen();
        QRect screenGeometry = screen->geometry();
        int x = (screenGeometry.width() - this->width()) / 2;
        int y = (screenGeometry.height() - this->height()) / 2;
        this->move(x, y);

        m_curWinSize = 0;
    }
}

void Widget::on_btn_close_clicked()
{
    this->close();
}

void Widget::on_listWidget_itemClicked(QListWidgetItem*item)
{
    auto it = m_funcWidgets.find(item->text());

    if (it != m_funcWidgets.end())
    {
        ui->label_func->setText(item->text());
        ui->stackedWidget->setCurrentWidget(it->second);
    }
}
