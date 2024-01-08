#ifndef DELETEITEM_H
#define DELETEITEM_H

#include <QDialog>

namespace Ui {
class deleteitem;
}

class deleteitem : public QDialog
{
    Q_OBJECT

public:
    explicit deleteitem(QWidget *parent = nullptr);
    ~deleteitem();

private slots:
    void on_pushButton_delete_clicked();

    void on_pushButton_loadInfo_clicked();

    void on_pushButton_quit_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::deleteitem *ui;
};

#endif // DELETEITEM_H
