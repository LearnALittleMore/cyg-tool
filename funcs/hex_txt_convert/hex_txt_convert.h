#ifndef HEX_TXT_CONVERT_H
#define HEX_TXT_CONVERT_H

#include <QWidget>

namespace Ui {
class HexTxtConvert;
}

class HexTxtConvert : public QWidget
{
    Q_OBJECT

public:
    explicit HexTxtConvert(QWidget *parent = 0);
    ~HexTxtConvert();

private:
    Ui::HexTxtConvert *ui;

private slots:
    void on_btnHex2Txt_clicked();
    void on_btnTxt2Hex_clicked();
};

#endif // HEX_TXT_CONVERT_H
