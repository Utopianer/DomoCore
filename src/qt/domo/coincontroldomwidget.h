// Copyright (c) 2019 The DOMO developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLDOMWIDGET_H
#define COINCONTROLDOMWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlDomWidget;
}

class CoinControlDomWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlDomWidget(QWidget *parent = nullptr);
    ~CoinControlDomWidget();

private:
    Ui::CoinControlDomWidget *ui;
};

#endif // COINCONTROLDOMWIDGET_H
