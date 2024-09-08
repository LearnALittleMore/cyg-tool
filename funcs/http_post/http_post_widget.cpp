#include "http_post_widget.h"
#include "ui_http_post_widget.h"

#include "http_client.h"
#include "http_server.h"

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
    ui->stackedWidget->insertWidget(0, new HttpClient(ui->stackedWidget));
    ui->stackedWidget->insertWidget(1, new HttpServer(ui->stackedWidget));
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
