#include "http_server.h"
#include "ui_http_server.h"

HttpServer::HttpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HttpServer)
{
    ui->setupUi(this);
}

HttpServer::~HttpServer()
{
    delete ui;
}

void HttpServer::on_btn_servStart_clicked()
{

}
