/********************************************************************************
** Form generated from reading UI file 'ShortcutView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTCUTVIEW_H
#define UI_SHORTCUTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "KeyEditor.h"

namespace QGBA {

class Ui_ShortcutView
{
public:
    QVBoxLayout *verticalLayout;
    QTreeView *shortcutTable;
    QHBoxLayout *horizontalLayout;
    QRadioButton *keyboardButton;
    QRadioButton *gamepadButton;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer_2;
    QGBA::KeyEditor *keyEdit;

    void setupUi(QWidget *QGBA__ShortcutView)
    {
        if (QGBA__ShortcutView->objectName().isEmpty())
            QGBA__ShortcutView->setObjectName(QString::fromUtf8("QGBA__ShortcutView"));
        QGBA__ShortcutView->resize(432, 443);
        verticalLayout = new QVBoxLayout(QGBA__ShortcutView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        shortcutTable = new QTreeView(QGBA__ShortcutView);
        shortcutTable->setObjectName(QString::fromUtf8("shortcutTable"));
        shortcutTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        shortcutTable->header()->setDefaultSectionSize(120);

        verticalLayout->addWidget(shortcutTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        keyboardButton = new QRadioButton(QGBA__ShortcutView);
        keyboardButton->setObjectName(QString::fromUtf8("keyboardButton"));
        keyboardButton->setChecked(true);

        horizontalLayout->addWidget(keyboardButton);

        gamepadButton = new QRadioButton(QGBA__ShortcutView);
        gamepadButton->setObjectName(QString::fromUtf8("gamepadButton"));

        horizontalLayout->addWidget(gamepadButton);

        clearButton = new QPushButton(QGBA__ShortcutView);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout->addWidget(clearButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        keyEdit = new QGBA::KeyEditor(QGBA__ShortcutView);
        keyEdit->setObjectName(QString::fromUtf8("keyEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(keyEdit->sizePolicy().hasHeightForWidth());
        keyEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(keyEdit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QGBA__ShortcutView);

        QMetaObject::connectSlotsByName(QGBA__ShortcutView);
    } // setupUi

    void retranslateUi(QWidget *QGBA__ShortcutView)
    {
        QGBA__ShortcutView->setWindowTitle(QCoreApplication::translate("QGBA::ShortcutView", "Edit Shortcuts", nullptr));
        keyboardButton->setText(QCoreApplication::translate("QGBA::ShortcutView", "Keyboard", nullptr));
        gamepadButton->setText(QCoreApplication::translate("QGBA::ShortcutView", "Gamepad", nullptr));
        clearButton->setText(QCoreApplication::translate("QGBA::ShortcutView", "Clear", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class ShortcutView: public Ui_ShortcutView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_SHORTCUTVIEW_H
