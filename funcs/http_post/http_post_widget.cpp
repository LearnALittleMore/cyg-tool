#include "http_post_widget.h"
#include "ui_http_post_widget.h"

HttpPostWidget::HttpPostWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HttpPostWidget)
{
    ui->setupUi(this);

    initWidget();
}

HttpPostWidget::~HttpPostWidget()
{
    delete ui;
}

void HttpPostWidget::initWidget()
{
    ui->lineEdit_servPort->setPlaceholderText("服务端口");
    ui->lineEdit_servUrl_1->setPlaceholderText("url");
    ui->lineEdit_servUrl_2->setPlaceholderText("url");
    ui->lineEdit_servUrl_3->setPlaceholderText("url");
}

void HttpPostWidget::on_btn_cli_clicked()
{
    ui->btn_cli->setText("client *");
    ui->btn_serv->setText("server");
    ui->stackedWidget->setCurrentIndex(0);
}

void HttpPostWidget::on_btn_serv_clicked()
{
    ui->btn_cli->setText("client");
    ui->btn_serv->setText("server *");
    ui->stackedWidget->setCurrentIndex(1);
}

void HttpPostWidget::on_btn_connect_clicked()
{
    ui->btn_conn_light->setStyleSheet("background-color: rgb(85, 245,127);");
}

void HttpPostWidget::on_btn_disconnect_clicked()
{
    ui->btn_conn_light->setStyleSheet("background-color: rgb(251, 115,115);");
}

void HttpPostWidget::on_btn_servStart_clicked()
{
    ui->plainTextEdit_servMsg->setPlainText("Http服务已启动");
}

void HttpPostWidget::on_btn_servStop_clicked()
{
    ui->plainTextEdit_servMsg->appendPlainText("Http服务已关闭\n");
}
