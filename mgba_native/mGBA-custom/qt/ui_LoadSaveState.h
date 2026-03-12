/********************************************************************************
** Form generated from reading UI file 'LoadSaveState.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADSAVESTATE_H
#define UI_LOADSAVESTATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "SavestateButton.h"

namespace QGBA {

class Ui_LoadSaveState
{
public:
    QGridLayout *gridLayout_2;
    QGBA::SavestateButton *state5;
    QLabel *lsLabel;
    QGBA::SavestateButton *state6;
    QGBA::SavestateButton *state8;
    QGBA::SavestateButton *state4;
    QGBA::SavestateButton *state1;
    QGBA::SavestateButton *state3;
    QGBA::SavestateButton *state7;
    QGBA::SavestateButton *state9;
    QGBA::SavestateButton *state2;
    QPushButton *cancel;

    void setupUi(QWidget *QGBA__LoadSaveState)
    {
        if (QGBA__LoadSaveState->objectName().isEmpty())
            QGBA__LoadSaveState->setObjectName(QString::fromUtf8("QGBA__LoadSaveState"));
        QGBA__LoadSaveState->resize(760, 560);
        gridLayout_2 = new QGridLayout(QGBA__LoadSaveState);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(6, 6, 6, 6);
        state5 = new QGBA::SavestateButton(QGBA__LoadSaveState);
        state5->setObjectName(QString::fromUtf8("state5"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(state5->sizePolicy().hasHeightForWidth());
        state5->setSizePolicy(sizePolicy);
        state5->setIconSize(QSize(240, 160));

        gridLayout_2->addWidget(state5, 2, 1, 1, 1);

        lsLabel = new QLabel(QGBA__LoadSaveState);
        lsLabel->setObjectName(QString::fromUtf8("lsLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lsLabel->sizePolicy().hasHeightForWidth());
        lsLabel->setSizePolicy(sizePolicy1);
        lsLabel->setStyleSheet(QString::fromUtf8("font-size: 30pt; font-weight: bold; color: white;"));
        lsLabel->setScaledContents(false);
        lsLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lsLabel, 0, 0, 1, 3);

        state6 = new QGBA::SavestateButton(QGBA__LoadSaveState);
        state6->setObjectName(QString::fromUtf8("state6"));
        sizePolicy.setHeightForWidth(state6->sizePolicy().hasHeightForWidth());
        state6->setSizePolicy(sizePolicy);
        state6->setIconSize(QSize(240, 160));

        gridLayout_2->addWidget(state6, 2, 2, 1, 1);

        state8 = new QGBA::SavestateButton(QGBA__LoadSaveState);
        state8->setObjectName(QString::fromUtf8("state8"));
        sizePolicy.setHeightForWidth(state8->sizePolicy().hasHeightForWidth());
        state8->setSizePolicy(sizePolicy);
        state8->setIconSize(QSize(240, 160));

        gridLayout_2->addWidget(state8, 3, 1, 1, 1);

        state4 = new QGBA::SavestateButton(QGBA__LoadSaveState);
        state4->setObjectName(QString::fromUtf8("state4"));
        sizePolicy.setHeightForWidth(state4->sizePolicy().hasHeightForWidth());
        state4->setSizePolicy(sizePolicy);
        state4->setIconSize(QSize(240, 160));

        gridLayout_2->addWidget(state4, 2, 0, 1, 1);

        state1 = new QGBA::SavestateButton(QGBA__LoadSaveState);
        state1->setObjectName(QString::fromUtf8("state1"));
        sizePolicy.setHeightForWidth(state1->sizePolicy().hasHeightForWidth());
        state1->setSizePolicy(sizePolicy);
        state1->setIconSize(QSize(240, 160));

        gridLayout_2->addWidget(state1, 1, 0, 1, 1);

        state3 = new QGBA::SavestateButton(QGBA__LoadSaveState);
        state3->setObjectName(QString::fromUtf8("state3"));
        sizePolicy.setHeightForWidth(state3->sizePolicy().hasHeightForWidth());
        state3->setSizePolicy(sizePolicy);
        state3->setIconSize(QSize(240, 160));

        gridLayout_2->addWidget(state3, 1, 2, 1, 1);

        state7 = new QGBA::SavestateButton(QGBA__LoadSaveState);
        state7->setObjectName(QString::fromUtf8("state7"));
        sizePolicy.setHeightForWidth(state7->sizePolicy().hasHeightForWidth());
        state7->setSizePolicy(sizePolicy);
        state7->setIconSize(QSize(240, 160));

        gridLayout_2->addWidget(state7, 3, 0, 1, 1);

        state9 = new QGBA::SavestateButton(QGBA__LoadSaveState);
        state9->setObjectName(QString::fromUtf8("state9"));
        sizePolicy.setHeightForWidth(state9->sizePolicy().hasHeightForWidth());
        state9->setSizePolicy(sizePolicy);
        state9->setIconSize(QSize(240, 160));

        gridLayout_2->addWidget(state9, 3, 2, 1, 1);

        state2 = new QGBA::SavestateButton(QGBA__LoadSaveState);
        state2->setObjectName(QString::fromUtf8("state2"));
        sizePolicy.setHeightForWidth(state2->sizePolicy().hasHeightForWidth());
        state2->setSizePolicy(sizePolicy);
        state2->setIconSize(QSize(240, 160));

        gridLayout_2->addWidget(state2, 1, 1, 1, 1);

        cancel = new QPushButton(QGBA__LoadSaveState);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cancel->sizePolicy().hasHeightForWidth());
        cancel->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(cancel, 4, 1, 1, 1, Qt::AlignHCenter);

        gridLayout_2->setRowStretch(0, 1);
        QWidget::setTabOrder(state1, state2);
        QWidget::setTabOrder(state2, state3);
        QWidget::setTabOrder(state3, state4);
        QWidget::setTabOrder(state4, state5);
        QWidget::setTabOrder(state5, state6);
        QWidget::setTabOrder(state6, state7);
        QWidget::setTabOrder(state7, state8);
        QWidget::setTabOrder(state8, state9);

        retranslateUi(QGBA__LoadSaveState);

        QMetaObject::connectSlotsByName(QGBA__LoadSaveState);
    } // setupUi

    void retranslateUi(QWidget *QGBA__LoadSaveState)
    {
        QGBA__LoadSaveState->setWindowTitle(QCoreApplication::translate("QGBA::LoadSaveState", "%1 State", nullptr));
        state5->setText(QCoreApplication::translate("QGBA::LoadSaveState", "No Save", nullptr));
#if QT_CONFIG(shortcut)
        state5->setShortcut(QCoreApplication::translate("QGBA::LoadSaveState", "5", nullptr));
#endif // QT_CONFIG(shortcut)
        lsLabel->setText(QCoreApplication::translate("QGBA::LoadSaveState", "%1 State", nullptr));
        state6->setText(QCoreApplication::translate("QGBA::LoadSaveState", "No Save", nullptr));
#if QT_CONFIG(shortcut)
        state6->setShortcut(QCoreApplication::translate("QGBA::LoadSaveState", "6", nullptr));
#endif // QT_CONFIG(shortcut)
        state8->setText(QCoreApplication::translate("QGBA::LoadSaveState", "No Save", nullptr));
#if QT_CONFIG(shortcut)
        state8->setShortcut(QCoreApplication::translate("QGBA::LoadSaveState", "8", nullptr));
#endif // QT_CONFIG(shortcut)
        state4->setText(QCoreApplication::translate("QGBA::LoadSaveState", "No Save", nullptr));
#if QT_CONFIG(shortcut)
        state4->setShortcut(QCoreApplication::translate("QGBA::LoadSaveState", "4", nullptr));
#endif // QT_CONFIG(shortcut)
        state1->setText(QCoreApplication::translate("QGBA::LoadSaveState", "No Save", nullptr));
#if QT_CONFIG(shortcut)
        state1->setShortcut(QCoreApplication::translate("QGBA::LoadSaveState", "1", nullptr));
#endif // QT_CONFIG(shortcut)
        state3->setText(QCoreApplication::translate("QGBA::LoadSaveState", "No Save", nullptr));
#if QT_CONFIG(shortcut)
        state3->setShortcut(QCoreApplication::translate("QGBA::LoadSaveState", "3", nullptr));
#endif // QT_CONFIG(shortcut)
        state7->setText(QCoreApplication::translate("QGBA::LoadSaveState", "No Save", nullptr));
#if QT_CONFIG(shortcut)
        state7->setShortcut(QCoreApplication::translate("QGBA::LoadSaveState", "7", nullptr));
#endif // QT_CONFIG(shortcut)
        state9->setText(QCoreApplication::translate("QGBA::LoadSaveState", "No Save", nullptr));
#if QT_CONFIG(shortcut)
        state9->setShortcut(QCoreApplication::translate("QGBA::LoadSaveState", "9", nullptr));
#endif // QT_CONFIG(shortcut)
        state2->setText(QCoreApplication::translate("QGBA::LoadSaveState", "No Save", nullptr));
#if QT_CONFIG(shortcut)
        state2->setShortcut(QCoreApplication::translate("QGBA::LoadSaveState", "2", nullptr));
#endif // QT_CONFIG(shortcut)
        cancel->setText(QCoreApplication::translate("QGBA::LoadSaveState", "Cancel", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class LoadSaveState: public Ui_LoadSaveState {};
} // namespace Ui
} // namespace QGBA

#endif // UI_LOADSAVESTATE_H
