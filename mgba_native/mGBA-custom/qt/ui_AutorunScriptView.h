/********************************************************************************
** Form generated from reading UI file 'AutorunScriptView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTORUNSCRIPTVIEW_H
#define UI_AUTORUNSCRIPTVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

namespace QGBA {

class Ui_AutorunScriptView
{
public:
    QGridLayout *gridLayout;
    QPushButton *add;
    QPushButton *remove;
    QSpacerItem *horizontalSpacer;
    QPushButton *up;
    QPushButton *down;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QListView *autorunList;

    void setupUi(QDialog *QGBA__AutorunScriptView)
    {
        if (QGBA__AutorunScriptView->objectName().isEmpty())
            QGBA__AutorunScriptView->setObjectName(QString::fromUtf8("QGBA__AutorunScriptView"));
        QGBA__AutorunScriptView->resize(400, 300);
        gridLayout = new QGridLayout(QGBA__AutorunScriptView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        add = new QPushButton(QGBA__AutorunScriptView);
        add->setObjectName(QString::fromUtf8("add"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("list-add")));
        add->setIcon(icon);

        gridLayout->addWidget(add, 1, 0, 1, 1);

        remove = new QPushButton(QGBA__AutorunScriptView);
        remove->setObjectName(QString::fromUtf8("remove"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("list-remove")));
        remove->setIcon(icon1);

        gridLayout->addWidget(remove, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        up = new QPushButton(QGBA__AutorunScriptView);
        up->setObjectName(QString::fromUtf8("up"));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("go-up")));
        up->setIcon(icon2);

        gridLayout->addWidget(up, 1, 3, 1, 1);

        down = new QPushButton(QGBA__AutorunScriptView);
        down->setObjectName(QString::fromUtf8("down"));
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("go-down")));
        down->setIcon(icon3);

        gridLayout->addWidget(down, 1, 4, 1, 1);

        groupBox = new QGroupBox(QGBA__AutorunScriptView);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        autorunList = new QListView(groupBox);
        autorunList->setObjectName(QString::fromUtf8("autorunList"));

        gridLayout_2->addWidget(autorunList, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 5);


        retranslateUi(QGBA__AutorunScriptView);
        QObject::connect(add, SIGNAL(clicked()), QGBA__AutorunScriptView, SLOT(addScript()));
        QObject::connect(remove, SIGNAL(clicked()), QGBA__AutorunScriptView, SLOT(removeScript()));
        QObject::connect(up, SIGNAL(clicked()), QGBA__AutorunScriptView, SLOT(moveUp()));
        QObject::connect(down, SIGNAL(clicked()), QGBA__AutorunScriptView, SLOT(moveDown()));

        QMetaObject::connectSlotsByName(QGBA__AutorunScriptView);
    } // setupUi

    void retranslateUi(QDialog *QGBA__AutorunScriptView)
    {
        QGBA__AutorunScriptView->setWindowTitle(QCoreApplication::translate("QGBA::AutorunScriptView", "Autorun scripts", nullptr));
        add->setText(QCoreApplication::translate("QGBA::AutorunScriptView", "Add", nullptr));
        remove->setText(QCoreApplication::translate("QGBA::AutorunScriptView", "Remove", nullptr));
        up->setText(QCoreApplication::translate("QGBA::AutorunScriptView", "Move up", nullptr));
        down->setText(QCoreApplication::translate("QGBA::AutorunScriptView", "Move down", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QGBA::AutorunScriptView", "Run scripts when starting a game", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class AutorunScriptView: public Ui_AutorunScriptView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_AUTORUNSCRIPTVIEW_H
