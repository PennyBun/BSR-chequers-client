/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *loginLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(400, 300);
        centralWidget = new QWidget(LoginWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        loginLineEdit = new QLineEdit(centralWidget);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));
        loginLineEdit->setGeometry(QRect(30, 20, 141, 25));
        loginLineEdit->setEchoMode(QLineEdit::Normal);
        passwordLineEdit = new QLineEdit(centralWidget);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(30, 70, 141, 25));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        loginButton = new QPushButton(centralWidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(40, 170, 89, 25));
        registerButton = new QPushButton(centralWidget);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(190, 170, 89, 25));
        LoginWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LoginWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        LoginWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LoginWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LoginWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LoginWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LoginWindow->setStatusBar(statusBar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "LoginWindow", Q_NULLPTR));
        loginButton->setText(QApplication::translate("LoginWindow", "Zaloguj", Q_NULLPTR));
        registerButton->setText(QApplication::translate("LoginWindow", "Zarejestruj", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
