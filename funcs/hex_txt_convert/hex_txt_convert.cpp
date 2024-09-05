#include "hex_txt_convert.h"
#include "ui_hex_txt_convert.h"

#include <QTextCodec>

using namespace std;

HexTxtConvert::HexTxtConvert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HexTxtConvert)
{
    ui->setupUi(this);

    ui->radioBtnUtf8->setChecked(true);
}

HexTxtConvert::~HexTxtConvert()
{
    delete ui;
}

void HexTxtConvert::on_btnHex2Txt_clicked()
{
    QString file = ui->textEditHex->toPlainText();

    QByteArray byteArray;
    QString strByte; /* 临时存储表示一个字节的字符串, 如: "0B" */
    for (QChar c : file)
    {
        if (c == QChar(0x20))
        {
            if(strByte.size() == 1) /* 检测到单个数字，认为是输入错误，如: 74 65 7 74 */
            {
                return;
            }

            continue;
        }

        strByte.push_back(c);
        if (strByte.size() == 2)
        {
            bool ok;
            char byte = strByte.toInt(&ok, 16);
            if (!ok) return;

            byteArray.append(byte);

            strByte.clear();
        }
    }

    QString txt;

    /* utf-8编码 */
    if (ui->radioBtnUtf8->isChecked())
    {
        txt = QString::fromUtf8(byteArray);
    }
    /* gbk编码 */
    else
    {
        QTextCodec* gbkCodec = QTextCodec::codecForName("GBK");
        txt = gbkCodec->toUnicode(byteArray);
    }

    ui->textEditTxt->setText(txt);
}

void HexTxtConvert::on_btnTxt2Hex_clicked()
{
    QString file = ui->textEditTxt->toPlainText();

    QByteArray byteArray;

    /* utf-8编码 */
    if (ui->radioBtnUtf8->isChecked())
    {
        byteArray = file.toUtf8();
    }
    /* gbk编码 */
    else
    {
        QTextCodec* gbkCodec = QTextCodec::codecForName("GBK");
        byteArray = gbkCodec->fromUnicode(file);
    }

    QString hex = byteArray.toHex();
    /* 字节之间插入空格 */
    for (int i = 2; i < hex.size(); i+=3) /* 每次循环会多出一个空格，因此i每次自增3，而不是2 */
    {
        hex.insert(i, " ");
    }

    ui->textEditHex->setText(hex);
}
