#ifndef FINDITEM_H
#define FINDITEM_H

#include <QDialog>

namespace Ui {
class finditem;
}

class finditem : public QDialog
{
    Q_OBJECT

public:
    explicit finditem(QWidget *parent = nullptr);
    ~finditem();

private slots:
    void on_btnFind_clicked();

private:
    Ui::finditem *ui;
};

#endif // FINDITEM_H
