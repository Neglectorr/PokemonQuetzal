/********************************************************************************
** Form generated from reading UI file 'SaveConverter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVECONVERTER_H
#define UI_SAVECONVERTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

namespace QGBA {

class Ui_SaveConverter
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *inputFile;
    QPushButton *inputBrowse;
    QComboBox *inputType;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLineEdit *outputFile;
    QPushButton *outputBrowse;
    QComboBox *outputType;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QGBA__SaveConverter)
    {
        if (QGBA__SaveConverter->objectName().isEmpty())
            QGBA__SaveConverter->setObjectName(QString::fromUtf8("QGBA__SaveConverter"));
        QGBA__SaveConverter->resize(546, 300);
        verticalLayout = new QVBoxLayout(QGBA__SaveConverter);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(QGBA__SaveConverter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        inputFile = new QLineEdit(groupBox);
        inputFile->setObjectName(QString::fromUtf8("inputFile"));

        gridLayout->addWidget(inputFile, 0, 0, 1, 1);

        inputBrowse = new QPushButton(groupBox);
        inputBrowse->setObjectName(QString::fromUtf8("inputBrowse"));

        gridLayout->addWidget(inputBrowse, 0, 1, 1, 1);

        inputType = new QComboBox(groupBox);
        inputType->setObjectName(QString::fromUtf8("inputType"));
        inputType->setEnabled(false);

        gridLayout->addWidget(inputType, 1, 0, 1, 2);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(QGBA__SaveConverter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        outputFile = new QLineEdit(groupBox_2);
        outputFile->setObjectName(QString::fromUtf8("outputFile"));

        gridLayout_2->addWidget(outputFile, 0, 0, 1, 1);

        outputBrowse = new QPushButton(groupBox_2);
        outputBrowse->setObjectName(QString::fromUtf8("outputBrowse"));

        gridLayout_2->addWidget(outputBrowse, 0, 1, 1, 1);

        outputType = new QComboBox(groupBox_2);
        outputType->setObjectName(QString::fromUtf8("outputType"));
        outputType->setEnabled(false);

        gridLayout_2->addWidget(outputType, 1, 0, 1, 2);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(QGBA__SaveConverter);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(inputFile, inputBrowse);
        QWidget::setTabOrder(inputBrowse, inputType);
        QWidget::setTabOrder(inputType, outputFile);
        QWidget::setTabOrder(outputFile, outputBrowse);
        QWidget::setTabOrder(outputBrowse, outputType);

        retranslateUi(QGBA__SaveConverter);
        QObject::connect(buttonBox, SIGNAL(accepted()), QGBA__SaveConverter, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QGBA__SaveConverter, SLOT(reject()));

        QMetaObject::connectSlotsByName(QGBA__SaveConverter);
    } // setupUi

    void retranslateUi(QDialog *QGBA__SaveConverter)
    {
        QGBA__SaveConverter->setWindowTitle(QCoreApplication::translate("QGBA::SaveConverter", "Convert/Extract Save Game", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QGBA::SaveConverter", "Input file", nullptr));
        inputBrowse->setText(QCoreApplication::translate("QGBA::SaveConverter", "Browse", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QGBA::SaveConverter", "Output file", nullptr));
        outputBrowse->setText(QCoreApplication::translate("QGBA::SaveConverter", "Browse", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class SaveConverter: public Ui_SaveConverter {};
} // namespace Ui
} // namespace QGBA

#endif // UI_SAVECONVERTER_H
