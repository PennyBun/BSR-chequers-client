/********************************************************************************
** Form generated from reading UI file 'roomwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMWINDOW_H
#define UI_ROOMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_RoomWindow
{
public:

    void setupUi(QDialog *RoomWindow)
    {
        if (RoomWindow->objectName().isEmpty())
            RoomWindow->setObjectName(QStringLiteral("RoomWindow"));
        RoomWindow->resize(400, 300);

        retranslateUi(RoomWindow);

        QMetaObject::connectSlotsByName(RoomWindow);
    } // setupUi

    void retranslateUi(QDialog *RoomWindow)
    {
        RoomWindow->setWindowTitle(QApplication::translate("RoomWindow", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RoomWindow: public Ui_RoomWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMWINDOW_H
