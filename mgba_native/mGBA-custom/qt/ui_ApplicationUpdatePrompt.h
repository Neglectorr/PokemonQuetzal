/********************************************************************************
** Form generated from reading UI file 'ApplicationUpdatePrompt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATIONUPDATEPROMPT_H
#define UI_APPLICATIONUPDATEPROMPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>

namespace QGBA {

class Ui_ApplicationUpdatePrompt
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *text;
    QLabel *details;
    QProgressBar *progressBar;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QGBA__ApplicationUpdatePrompt)
    {
        if (QGBA__ApplicationUpdatePrompt->objectName().isEmpty())
            QGBA__ApplicationUpdatePrompt->setObjectName(QString::fromUtf8("QGBA__ApplicationUpdatePrompt"));
        QGBA__ApplicationUpdatePrompt->resize(186, 127);
        verticalLayout = new QVBoxLayout(QGBA__ApplicationUpdatePrompt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        text = new QLabel(QGBA__ApplicationUpdatePrompt);
        text->setObjectName(QString::fromUtf8("text"));
        text->setText(QString::fromUtf8("{text}"));
        text->setWordWrap(true);

        verticalLayout->addWidget(text);

        details = new QLabel(QGBA__ApplicationUpdatePrompt);
        details->setObjectName(QString::fromUtf8("details"));
        details->setText(QString::fromUtf8("{details}"));

        verticalLayout->addWidget(details);

        progressBar = new QProgressBar(QGBA__ApplicationUpdatePrompt);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        buttonBox = new QDialogButtonBox(QGBA__ApplicationUpdatePrompt);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(QGBA__ApplicationUpdatePrompt);
        QObject::connect(buttonBox, SIGNAL(rejected()), QGBA__ApplicationUpdatePrompt, SLOT(reject()));

        QMetaObject::connectSlotsByName(QGBA__ApplicationUpdatePrompt);
    } // setupUi

    void retranslateUi(QDialog *QGBA__ApplicationUpdatePrompt)
    {
        QGBA__ApplicationUpdatePrompt->setWindowTitle(QCoreApplication::translate("QGBA::ApplicationUpdatePrompt", "An update is available", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class ApplicationUpdatePrompt: public Ui_ApplicationUpdatePrompt {};
} // namespace Ui
} // namespace QGBA

#endif // UI_APPLICATIONUPDATEPROMPT_H
