// Copyright (c) 2017-2018 The DOMO developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZDOMCONTROLDIALOG_H
#define ZDOMCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zdom/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZDomControlDialog;
}

class CZDomControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZDomControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZDomControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZDomControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZDomControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZDomControlDialog(QWidget *parent);
    ~ZDomControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZDomControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZDomControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZDOMCONTROLDIALOG_H
