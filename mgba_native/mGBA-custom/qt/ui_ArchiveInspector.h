/********************************************************************************
** Form generated from reading UI file 'ArchiveInspector.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARCHIVEINSPECTOR_H
#define UI_ARCHIVEINSPECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include "library/LibraryController.h"

namespace QGBA {

class Ui_ArchiveInspector
{
public:
    QGridLayout *gridLayout;
    QLabel *loading;
    QDialogButtonBox *buttonBox;
    QGBA::LibraryController *archiveView;

    void setupUi(QDialog *QGBA__ArchiveInspector)
    {
        if (QGBA__ArchiveInspector->objectName().isEmpty())
            QGBA__ArchiveInspector->setObjectName(QString::fromUtf8("QGBA__ArchiveInspector"));
        QGBA__ArchiveInspector->resize(600, 400);
        gridLayout = new QGridLayout(QGBA__ArchiveInspector);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        loading = new QLabel(QGBA__ArchiveInspector);
        loading->setObjectName(QString::fromUtf8("loading"));

        gridLayout->addWidget(loading, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(QGBA__ArchiveInspector);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Open);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        archiveView = new QGBA::LibraryController(QGBA__ArchiveInspector);
        archiveView->setObjectName(QString::fromUtf8("archiveView"));

        gridLayout->addWidget(archiveView, 0, 0, 1, 2);


        retranslateUi(QGBA__ArchiveInspector);
        QObject::connect(buttonBox, SIGNAL(rejected()), QGBA__ArchiveInspector, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), QGBA__ArchiveInspector, SLOT(accept()));

        QMetaObject::connectSlotsByName(QGBA__ArchiveInspector);
    } // setupUi

    void retranslateUi(QDialog *QGBA__ArchiveInspector)
    {
        QGBA__ArchiveInspector->setWindowTitle(QCoreApplication::translate("QGBA::ArchiveInspector", "Open in archive...", nullptr));
        loading->setText(QCoreApplication::translate("QGBA::ArchiveInspector", "Loading...", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class ArchiveInspector: public Ui_ArchiveInspector {};
} // namespace Ui
} // namespace QGBA

#endif // UI_ARCHIVEINSPECTOR_H
