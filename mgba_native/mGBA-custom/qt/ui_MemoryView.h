/********************************************************************************
** Form generated from reading UI file 'MemoryView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORYVIEW_H
#define UI_MEMORYVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MemoryModel.h"

namespace QGBA {

class Ui_MemoryView
{
public:
    QHBoxLayout *horizontalLayout_7;
    QGBA::MemoryModel *hexfield;
    QVBoxLayout *sidebarLayout;
    QComboBox *regions;
    QHBoxLayout *addressLayout;
    QLabel *address;
    QSpacerItem *horizontalSpacer;
    QSpinBox *segments;
    QLabel *segmentColon;
    QSpinBox *setAddress;
    QHBoxLayout *alignmentLayout;
    QLabel *alignmentLabel;
    QComboBox *width;
    QGroupBox *data;
    QGridLayout *gridLayout_9;
    QLabel *sintLabel;
    QLineEdit *sintVal;
    QLabel *uintLabel;
    QLineEdit *uintVal;
    QLabel *stringLabel;
    QPushButton *loadTBL;
    QPlainTextEdit *stringVal;
    QGridLayout *buttons;
    QPushButton *copy;
    QPushButton *save;
    QPushButton *paste;
    QPushButton *saveRange;
    QPushButton *load;
    QGroupBox *verticalGroupBox_2;
    QVBoxLayout *verticalLayout;
    QTreeView *accessLog;
    QPushButton *accessLoggerButton;

    void setupUi(QWidget *QGBA__MemoryView)
    {
        if (QGBA__MemoryView->objectName().isEmpty())
            QGBA__MemoryView->setObjectName(QString::fromUtf8("QGBA__MemoryView"));
        QGBA__MemoryView->resize(708, 549);
        horizontalLayout_7 = new QHBoxLayout(QGBA__MemoryView);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        hexfield = new QGBA::MemoryModel(QGBA__MemoryView);
        hexfield->setObjectName(QString::fromUtf8("hexfield"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hexfield->sizePolicy().hasHeightForWidth());
        hexfield->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(hexfield);

        sidebarLayout = new QVBoxLayout();
        sidebarLayout->setObjectName(QString::fromUtf8("sidebarLayout"));
        regions = new QComboBox(QGBA__MemoryView);
        regions->setObjectName(QString::fromUtf8("regions"));

        sidebarLayout->addWidget(regions);

        addressLayout = new QHBoxLayout();
        addressLayout->setObjectName(QString::fromUtf8("addressLayout"));
        address = new QLabel(QGBA__MemoryView);
        address->setObjectName(QString::fromUtf8("address"));

        addressLayout->addWidget(address);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        addressLayout->addItem(horizontalSpacer);

        segments = new QSpinBox(QGBA__MemoryView);
        segments->setObjectName(QString::fromUtf8("segments"));
        segments->setMinimum(-1);
        segments->setMaximum(0);
        segments->setDisplayIntegerBase(16);

        addressLayout->addWidget(segments);

        segmentColon = new QLabel(QGBA__MemoryView);
        segmentColon->setObjectName(QString::fromUtf8("segmentColon"));
        segmentColon->setText(QString::fromUtf8(":"));

        addressLayout->addWidget(segmentColon);

        setAddress = new QSpinBox(QGBA__MemoryView);
        setAddress->setObjectName(QString::fromUtf8("setAddress"));
        setAddress->setMinimumSize(QSize(100, 0));
        setAddress->setAccelerated(true);
        setAddress->setPrefix(QString::fromUtf8("0x"));
        setAddress->setMaximum(268435455);
        setAddress->setSingleStep(16);
        setAddress->setDisplayIntegerBase(16);

        addressLayout->addWidget(setAddress);


        sidebarLayout->addLayout(addressLayout);

        alignmentLayout = new QHBoxLayout();
        alignmentLayout->setObjectName(QString::fromUtf8("alignmentLayout"));
        alignmentLabel = new QLabel(QGBA__MemoryView);
        alignmentLabel->setObjectName(QString::fromUtf8("alignmentLabel"));

        alignmentLayout->addWidget(alignmentLabel);

        width = new QComboBox(QGBA__MemoryView);
        width->addItem(QString());
        width->addItem(QString());
        width->addItem(QString());
        width->setObjectName(QString::fromUtf8("width"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(width->sizePolicy().hasHeightForWidth());
        width->setSizePolicy(sizePolicy1);

        alignmentLayout->addWidget(width);


        sidebarLayout->addLayout(alignmentLayout);

        data = new QGroupBox(QGBA__MemoryView);
        data->setObjectName(QString::fromUtf8("data"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(data->sizePolicy().hasHeightForWidth());
        data->setSizePolicy(sizePolicy2);
        gridLayout_9 = new QGridLayout(data);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        sintLabel = new QLabel(data);
        sintLabel->setObjectName(QString::fromUtf8("sintLabel"));

        gridLayout_9->addWidget(sintLabel, 0, 0, 1, 1);

        sintVal = new QLineEdit(data);
        sintVal->setObjectName(QString::fromUtf8("sintVal"));
        sintVal->setMaxLength(11);
        sintVal->setReadOnly(true);
        sintVal->setPlaceholderText(QString::fromUtf8(""));

        gridLayout_9->addWidget(sintVal, 0, 1, 1, 1);

        uintLabel = new QLabel(data);
        uintLabel->setObjectName(QString::fromUtf8("uintLabel"));

        gridLayout_9->addWidget(uintLabel, 1, 0, 1, 1);

        uintVal = new QLineEdit(data);
        uintVal->setObjectName(QString::fromUtf8("uintVal"));
        uintVal->setMaxLength(10);
        uintVal->setReadOnly(true);
        uintVal->setPlaceholderText(QString::fromUtf8(""));

        gridLayout_9->addWidget(uintVal, 1, 1, 1, 1);

        stringLabel = new QLabel(data);
        stringLabel->setObjectName(QString::fromUtf8("stringLabel"));

        gridLayout_9->addWidget(stringLabel, 2, 0, 1, 1);

        loadTBL = new QPushButton(data);
        loadTBL->setObjectName(QString::fromUtf8("loadTBL"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(loadTBL->sizePolicy().hasHeightForWidth());
        loadTBL->setSizePolicy(sizePolicy3);

        gridLayout_9->addWidget(loadTBL, 2, 1, 1, 1, Qt::AlignRight);

        stringVal = new QPlainTextEdit(data);
        stringVal->setObjectName(QString::fromUtf8("stringVal"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(stringVal->sizePolicy().hasHeightForWidth());
        stringVal->setSizePolicy(sizePolicy4);
        stringVal->setPlainText(QString::fromUtf8(""));
        stringVal->setPlaceholderText(QString::fromUtf8(""));

        gridLayout_9->addWidget(stringVal, 3, 0, 1, 2);


        sidebarLayout->addWidget(data);

        buttons = new QGridLayout();
        buttons->setObjectName(QString::fromUtf8("buttons"));
        copy = new QPushButton(QGBA__MemoryView);
        copy->setObjectName(QString::fromUtf8("copy"));

        buttons->addWidget(copy, 0, 0, 1, 1);

        save = new QPushButton(QGBA__MemoryView);
        save->setObjectName(QString::fromUtf8("save"));

        buttons->addWidget(save, 0, 1, 1, 1);

        paste = new QPushButton(QGBA__MemoryView);
        paste->setObjectName(QString::fromUtf8("paste"));

        buttons->addWidget(paste, 1, 0, 1, 1);

        saveRange = new QPushButton(QGBA__MemoryView);
        saveRange->setObjectName(QString::fromUtf8("saveRange"));

        buttons->addWidget(saveRange, 1, 1, 1, 1);

        load = new QPushButton(QGBA__MemoryView);
        load->setObjectName(QString::fromUtf8("load"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(load->sizePolicy().hasHeightForWidth());
        load->setSizePolicy(sizePolicy5);

        buttons->addWidget(load, 2, 0, 1, 2);


        sidebarLayout->addLayout(buttons);

        verticalGroupBox_2 = new QGroupBox(QGBA__MemoryView);
        verticalGroupBox_2->setObjectName(QString::fromUtf8("verticalGroupBox_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(verticalGroupBox_2->sizePolicy().hasHeightForWidth());
        verticalGroupBox_2->setSizePolicy(sizePolicy6);
        verticalLayout = new QVBoxLayout(verticalGroupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        accessLog = new QTreeView(verticalGroupBox_2);
        accessLog->setObjectName(QString::fromUtf8("accessLog"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(accessLog->sizePolicy().hasHeightForWidth());
        accessLog->setSizePolicy(sizePolicy7);
        accessLog->setTextElideMode(Qt::ElideNone);
        accessLog->header()->setVisible(false);

        verticalLayout->addWidget(accessLog);

        accessLoggerButton = new QPushButton(verticalGroupBox_2);
        accessLoggerButton->setObjectName(QString::fromUtf8("accessLoggerButton"));

        verticalLayout->addWidget(accessLoggerButton);


        sidebarLayout->addWidget(verticalGroupBox_2);

        sidebarLayout->setStretch(3, 1);
        sidebarLayout->setStretch(5, 1);

        horizontalLayout_7->addLayout(sidebarLayout);

        horizontalLayout_7->setStretch(0, 1);

        retranslateUi(QGBA__MemoryView);

        QMetaObject::connectSlotsByName(QGBA__MemoryView);
    } // setupUi

    void retranslateUi(QWidget *QGBA__MemoryView)
    {
        QGBA__MemoryView->setWindowTitle(QCoreApplication::translate("QGBA::MemoryView", "Memory", nullptr));
        address->setText(QCoreApplication::translate("QGBA::MemoryView", "Address:", nullptr));
        alignmentLabel->setText(QCoreApplication::translate("QGBA::MemoryView", "Alignment:", nullptr));
        width->setItemText(0, QCoreApplication::translate("QGBA::MemoryView", "1 Byte", nullptr));
        width->setItemText(1, QCoreApplication::translate("QGBA::MemoryView", "2 Bytes", nullptr));
        width->setItemText(2, QCoreApplication::translate("QGBA::MemoryView", "4 Bytes", nullptr));

        data->setTitle(QString());
        sintLabel->setText(QCoreApplication::translate("QGBA::MemoryView", "Signed:", nullptr));
        uintLabel->setText(QCoreApplication::translate("QGBA::MemoryView", "Unsigned:", nullptr));
        stringLabel->setText(QCoreApplication::translate("QGBA::MemoryView", "String:", nullptr));
        loadTBL->setText(QCoreApplication::translate("QGBA::MemoryView", "Load TBL", nullptr));
        copy->setText(QCoreApplication::translate("QGBA::MemoryView", "Copy Selection", nullptr));
        save->setText(QCoreApplication::translate("QGBA::MemoryView", "Save Selection", nullptr));
        paste->setText(QCoreApplication::translate("QGBA::MemoryView", "Paste", nullptr));
        saveRange->setText(QCoreApplication::translate("QGBA::MemoryView", "Save Range", nullptr));
        load->setText(QCoreApplication::translate("QGBA::MemoryView", "Load", nullptr));
        verticalGroupBox_2->setTitle(QCoreApplication::translate("QGBA::MemoryView", "Selected address accesses", nullptr));
        accessLoggerButton->setText(QCoreApplication::translate("QGBA::MemoryView", "Logging configuration", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class MemoryView: public Ui_MemoryView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_MEMORYVIEW_H
