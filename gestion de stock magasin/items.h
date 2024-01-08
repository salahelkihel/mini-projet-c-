#pragma once


#ifndef ITEMS_H
#define ITEMS_H

#endif // ITEMS_H
#include <QString>
#include <iostream>
#include <QString>
using namespace std;
class Item {
private:
    // You may include private members if needed

public:
    QString name;
    QString quantity;
    QString status;
    QString dop;
    QString dos;
    QString sellingPrice;
    QString purchasePrice;

    // Constructors
    Item();
    Item(QString itemName, QString itemQuantity, QString itemStatus, QString itemDOP, QString itemDOS, QString itemSellingPrice, QString itemPurchasePrice);

    // Mutators
    void setName(QString itemName);
    void setQuantity(QString itemQuantity);
    void setStatus(QString itemStatus);
    void setDOP(QString itemDOP);
    void setDOS(QString itemDOS);
    void setSellingPrice(QString itemSellingPrice);
    void setPurchasePrice(QString itemPurchasePrice);

    // Accessors
    QString getName() const;
    QString getQuantity() const;
    QString getStatus() const;
    QString getDOP() const;
    QString getDOS() const;
    QString getSellingPrice() const;
    QString getPurchasePrice() const;
};

// Implement member functions here...

