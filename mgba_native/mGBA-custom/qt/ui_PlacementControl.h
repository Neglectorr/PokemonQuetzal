/********************************************************************************
** Form generated from reading UI file 'PlacementControl.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLACEMENTCONTROL_H
#define UI_PLACEMENTCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

namespace QGBA {

class Ui_PlacementControl
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *offsetX;
    QSpinBox *offsetY;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *QGBA__PlacementControl)
    {
        if (QGBA__PlacementControl->objectName().isEmpty())
            QGBA__PlacementControl->setObjectName(QString::fromUtf8("QGBA__PlacementControl"));
        QGBA__PlacementControl->resize(202, 72);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QGBA__PlacementControl->sizePolicy().hasHeightForWidth());
        QGBA__PlacementControl->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(QGBA__PlacementControl);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(QGBA__PlacementControl);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1, Qt::AlignRight);

        offsetX = new QSpinBox(QGBA__PlacementControl);
        offsetX->setObjectName(QString::fromUtf8("offsetX"));
        offsetX->setWrapping(true);
        offsetX->setAccelerated(true);
        offsetX->setMinimum(-128);
        offsetX->setMaximum(127);

        gridLayout->addWidget(offsetX, 1, 1, 1, 1);

        offsetY = new QSpinBox(QGBA__PlacementControl);
        offsetY->setObjectName(QString::fromUtf8("offsetY"));
        offsetY->setWrapping(true);
        offsetY->setAccelerated(true);
        offsetY->setMinimum(-128);
        offsetY->setMaximum(127);

        gridLayout->addWidget(offsetY, 1, 2, 1, 1);

        label_2 = new QLabel(QGBA__PlacementControl);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1, Qt::AlignRight);

        label_3 = new QLabel(QGBA__PlacementControl);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1, Qt::AlignHCenter);

        label_4 = new QLabel(QGBA__PlacementControl);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1, Qt::AlignHCenter);


        retranslateUi(QGBA__PlacementControl);

        QMetaObject::connectSlotsByName(QGBA__PlacementControl);
    } // setupUi

    void retranslateUi(QDialog *QGBA__PlacementControl)
    {
        QGBA__PlacementControl->setWindowTitle(QCoreApplication::translate("QGBA::PlacementControl", "Adjust placement", nullptr));
        label->setText(QCoreApplication::translate("QGBA::PlacementControl", "All", nullptr));
        label_2->setText(QCoreApplication::translate("QGBA::PlacementControl", "Offset", nullptr));
        label_3->setText(QCoreApplication::translate("QGBA::PlacementControl", "X", nullptr));
        label_4->setText(QCoreApplication::translate("QGBA::PlacementControl", "Y", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class PlacementControl: public Ui_PlacementControl {};
} // namespace Ui
} // namespace QGBA

#endif // UI_PLACEMENTCONTROL_H
