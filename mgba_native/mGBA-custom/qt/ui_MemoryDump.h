/********************************************************************************
** Form generated from reading UI file 'MemoryDump.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORYDUMP_H
#define UI_MEMORYDUMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

namespace QGBA {

class Ui_MemoryDump
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpinBox *segment;
    QLabel *label_3;
    QSpinBox *address;
    QLabel *label_2;
    QSpinBox *bytes;
    QCheckBox *spanSegments;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QGBA__MemoryDump)
    {
        if (QGBA__MemoryDump->objectName().isEmpty())
            QGBA__MemoryDump->setObjectName(QString::fromUtf8("QGBA__MemoryDump"));
        QGBA__MemoryDump->resize(448, 208);
        formLayout = new QFormLayout(QGBA__MemoryDump);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(QGBA__MemoryDump);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        segment = new QSpinBox(QGBA__MemoryDump);
        segment->setObjectName(QString::fromUtf8("segment"));
        segment->setMinimum(-1);
        segment->setMaximum(511);
        segment->setDisplayIntegerBase(16);

        horizontalLayout->addWidget(segment);

        label_3 = new QLabel(QGBA__MemoryDump);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setText(QString::fromUtf8(":"));

        horizontalLayout->addWidget(label_3);

        address = new QSpinBox(QGBA__MemoryDump);
        address->setObjectName(QString::fromUtf8("address"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(address->sizePolicy().hasHeightForWidth());
        address->setSizePolicy(sizePolicy);
        address->setAccelerated(true);
        address->setPrefix(QString::fromUtf8("0x"));
        address->setMaximum(268435455);
        address->setSingleStep(16);
        address->setDisplayIntegerBase(16);

        horizontalLayout->addWidget(address);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        label_2 = new QLabel(QGBA__MemoryDump);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        bytes = new QSpinBox(QGBA__MemoryDump);
        bytes->setObjectName(QString::fromUtf8("bytes"));
        sizePolicy.setHeightForWidth(bytes->sizePolicy().hasHeightForWidth());
        bytes->setSizePolicy(sizePolicy);
        bytes->setPrefix(QString::fromUtf8("0x"));
        bytes->setMinimum(1);
        bytes->setMaximum(268435456);
        bytes->setValue(256);
        bytes->setDisplayIntegerBase(16);

        formLayout->setWidget(1, QFormLayout::FieldRole, bytes);

        spanSegments = new QCheckBox(QGBA__MemoryDump);
        spanSegments->setObjectName(QString::fromUtf8("spanSegments"));

        formLayout->setWidget(2, QFormLayout::SpanningRole, spanSegments);

        buttonBox = new QDialogButtonBox(QGBA__MemoryDump);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        formLayout->setWidget(3, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(QGBA__MemoryDump);
        QObject::connect(buttonBox, SIGNAL(accepted()), QGBA__MemoryDump, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QGBA__MemoryDump, SLOT(reject()));

        QMetaObject::connectSlotsByName(QGBA__MemoryDump);
    } // setupUi

    void retranslateUi(QDialog *QGBA__MemoryDump)
    {
        QGBA__MemoryDump->setWindowTitle(QCoreApplication::translate("QGBA::MemoryDump", "Save Memory Range", nullptr));
        label->setText(QCoreApplication::translate("QGBA::MemoryDump", "Start Address:", nullptr));
        label_2->setText(QCoreApplication::translate("QGBA::MemoryDump", "Byte Count:", nullptr));
        spanSegments->setText(QCoreApplication::translate("QGBA::MemoryDump", "Dump across banks", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class MemoryDump: public Ui_MemoryDump {};
} // namespace Ui
} // namespace QGBA

#endif // UI_MEMORYDUMP_H
