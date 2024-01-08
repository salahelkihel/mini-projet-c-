#ifndef UPDATEITEM_H
#define UPDATEITEM_H

#include <QDialog>

namespace Ui {
class updateItem;
}

class updateItem : public QDialog
{
    Q_OBJECT

public:
    explicit updateItem(QWidget *parent = nullptr);
    ~updateItem();

private slots:
    void on_pushButton_update_clicked();

    void on_pushButton_loadInfo_clicked();

    void on_pushButton_quit_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::updateItem *ui;
};

#endif // UPDATEITEM_H
