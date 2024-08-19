#include "kbqwidget.h"
#include "ui_kbqwidget.h"

KBQWidget::KBQWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::KBQWidget)
{
    ui->setupUi(this);
    initWidget();
}

KBQWidget::~KBQWidget()
{
    delete ui;
}

void KBQWidget::initWidget()
{
    ui->lineEdit_ip->setPlaceholderText("ip地址");
    ui->lineEdit_port->setPlaceholderText("端口");
}

void KBQWidget::on_btn_start_close_clicked()
{
    if (ui->btn_start_close->text() == "启动")
    {
        ui->btn_start_close->setText("关闭");
        ui->plainTextEdit_func->appendPlainText("KBQ服务已启动\n");
    }
    else if (ui->btn_start_close->text() == "关闭")
    {
        ui->btn_start_close->setText("启动");
        ui->plainTextEdit_func->appendPlainText("KBQ服务已关闭\n");
    }
}
