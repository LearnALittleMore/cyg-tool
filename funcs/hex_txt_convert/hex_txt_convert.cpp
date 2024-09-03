#include "hex_txt_convert.h"
#include "ui_hex_txt_convert.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

HexTxtConvert::HexTxtConvert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HexTxtConvert)
{
    ui->setupUi(this);
}

HexTxtConvert::~HexTxtConvert()
{
    delete ui;
}

void HexTxtConvert::on_btnHex2Txt_clicked()
{
    string file = ui->textEditHex->toPlainText().toStdString();
    string txt;

    string strByte; //临时存储表示一个字节的字符串, 如: "0B"
    for (size_t i = 0; i < file.size(); i++)
    {
        if (file[i] == 0x20) //空格
        {
            if(strByte.size() == 1)
            {
                return;
            }

            continue;
        }

        strByte.push_back(file[i]);

        if (strByte.size() == 2)
        {
            char byte;
            try{
                byte = static_cast<char>(std::stoi(strByte, nullptr, 16));
            }
            catch(exception e)
            {
                return;
            }

            txt.push_back(byte);

            strByte.clear();
        }
    }

    ui->textEditTxt->setText(QString::fromStdString(txt));
}

void HexTxtConvert::on_btnTxt2Hex_clicked()
{
    string file = ui->textEditTxt->toPlainText().toStdString();
    string hex;

    std::stringstream ss;
    for (unsigned char byte : file)
    {
        ss << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
        hex.append(ss.str()+' ');
        ss.str("");
    }

    ui->textEditHex->setText(QString::fromStdString(hex));
}
