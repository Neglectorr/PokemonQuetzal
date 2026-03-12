/********************************************************************************
** Form generated from reading UI file 'MemoryAccessLogView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORYACCESSLOGVIEW_H
#define UI_MEMORYACCESSLOGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace QGBA {

class Ui_MemoryAccessLogView
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *filename;
    QPushButton *browse;
    QCheckBox *logExtra;
    QCheckBox *loadExisting;
    QPushButton *load;
    QPushButton *unload;
    QGroupBox *regionBox;
    QVBoxLayout *verticalLayout;
    QPushButton *exportButton;
    QPushButton *start;
    QPushButton *stop;

    void setupUi(QWidget *QGBA__MemoryAccessLogView)
    {
        if (QGBA__MemoryAccessLogView->objectName().isEmpty())
            QGBA__MemoryAccessLogView->setObjectName(QString::fromUtf8("QGBA__MemoryAccessLogView"));
        QGBA__MemoryAccessLogView->resize(311, 387);
        gridLayout = new QGridLayout(QGBA__MemoryAccessLogView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        groupBox = new QGroupBox(QGBA__MemoryAccessLogView);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        filename = new QLineEdit(groupBox);
        filename->setObjectName(QString::fromUtf8("filename"));

        gridLayout_2->addWidget(filename, 0, 0, 1, 2);

        browse = new QPushButton(groupBox);
        browse->setObjectName(QString::fromUtf8("browse"));

        gridLayout_2->addWidget(browse, 0, 2, 1, 1);

        logExtra = new QCheckBox(groupBox);
        logExtra->setObjectName(QString::fromUtf8("logExtra"));

        gridLayout_2->addWidget(logExtra, 1, 0, 1, 3);

        loadExisting = new QCheckBox(groupBox);
        loadExisting->setObjectName(QString::fromUtf8("loadExisting"));
        loadExisting->setChecked(true);

        gridLayout_2->addWidget(loadExisting, 2, 0, 1, 3);

        load = new QPushButton(groupBox);
        load->setObjectName(QString::fromUtf8("load"));

        gridLayout_2->addWidget(load, 3, 0, 1, 1);

        unload = new QPushButton(groupBox);
        unload->setObjectName(QString::fromUtf8("unload"));
        unload->setEnabled(false);

        gridLayout_2->addWidget(unload, 3, 1, 1, 2);

        gridLayout_2->setColumnStretch(0, 3);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 2);

        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        regionBox = new QGroupBox(QGBA__MemoryAccessLogView);
        regionBox->setObjectName(QString::fromUtf8("regionBox"));
        verticalLayout = new QVBoxLayout(regionBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        gridLayout->addWidget(regionBox, 1, 0, 1, 2);

        exportButton = new QPushButton(QGBA__MemoryAccessLogView);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));
        exportButton->setEnabled(false);

        gridLayout->addWidget(exportButton, 2, 0, 1, 2);

        start = new QPushButton(QGBA__MemoryAccessLogView);
        start->setObjectName(QString::fromUtf8("start"));

        gridLayout->addWidget(start, 3, 0, 1, 1);

        stop = new QPushButton(QGBA__MemoryAccessLogView);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setEnabled(false);

        gridLayout->addWidget(stop, 3, 1, 1, 1);


        retranslateUi(QGBA__MemoryAccessLogView);
        QObject::connect(start, SIGNAL(clicked()), QGBA__MemoryAccessLogView, SLOT(start()));
        QObject::connect(stop, SIGNAL(clicked()), QGBA__MemoryAccessLogView, SLOT(stop()));
        QObject::connect(load, SIGNAL(clicked()), QGBA__MemoryAccessLogView, SLOT(load()));
        QObject::connect(unload, SIGNAL(clicked()), QGBA__MemoryAccessLogView, SLOT(unload()));

        QMetaObject::connectSlotsByName(QGBA__MemoryAccessLogView);
    } // setupUi

    void retranslateUi(QWidget *QGBA__MemoryAccessLogView)
    {
        QGBA__MemoryAccessLogView->setWindowTitle(QCoreApplication::translate("QGBA::MemoryAccessLogView", "Memory access logging", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QGBA::MemoryAccessLogView", "Log file", nullptr));
        browse->setText(QCoreApplication::translate("QGBA::MemoryAccessLogView", "Browse", nullptr));
        logExtra->setText(QCoreApplication::translate("QGBA::MemoryAccessLogView", "Log additional information (uses 3\303\227 space)", nullptr));
        loadExisting->setText(QCoreApplication::translate("QGBA::MemoryAccessLogView", "Load existing file if present", nullptr));
        load->setText(QCoreApplication::translate("QGBA::MemoryAccessLogView", "Load", nullptr));
        unload->setText(QCoreApplication::translate("QGBA::MemoryAccessLogView", "Unload", nullptr));
        regionBox->setTitle(QCoreApplication::translate("QGBA::MemoryAccessLogView", "Regions", nullptr));
        exportButton->setText(QCoreApplication::translate("QGBA::MemoryAccessLogView", "Export ROM snapshot", nullptr));
        start->setText(QCoreApplication::translate("QGBA::MemoryAccessLogView", "Start", nullptr));
        stop->setText(QCoreApplication::translate("QGBA::MemoryAccessLogView", "Stop", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class MemoryAccessLogView: public Ui_MemoryAccessLogView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_MEMORYACCESSLOGVIEW_H
