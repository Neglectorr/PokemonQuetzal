/********************************************************************************
** Form generated from reading UI file 'ForwarderView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORWARDERVIEW_H
#define UI_FORWARDERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

namespace QGBA {

class Ui_ForwarderView
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *romFilename;
    QPushButton *romBrowse;
    QLabel *label_5;
    QLineEdit *outputFilename;
    QPushButton *outputBrowse;
    QLabel *label_7;
    QComboBox *baseType;
    QLabel *baseLabel;
    QLineEdit *baseFilename;
    QPushButton *baseBrowse;
    QFrame *line;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *system3DS;
    QRadioButton *systemVita;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_3;
    QLabel *label;
    QLineEdit *title;
    QLabel *imagesLabel;
    QComboBox *imageSelect;
    QCheckBox *useDefaultImage;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *imagePreview;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QLabel *preferredLabel;
    QLabel *preferredWidth;
    QLabel *preferredX;
    QLabel *preferredHeight;
    QSpacerItem *horizontalSpacer;
    QPushButton *imageBrowse;
    QProgressBar *progressBar;
    QButtonGroup *system;

    void setupUi(QDialog *QGBA__ForwarderView)
    {
        if (QGBA__ForwarderView->objectName().isEmpty())
            QGBA__ForwarderView->setObjectName(QString::fromUtf8("QGBA__ForwarderView"));
        QGBA__ForwarderView->resize(710, 465);
        gridLayout = new QGridLayout(QGBA__ForwarderView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(QGBA__ForwarderView);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        formLayout_2 = new QFormLayout(groupBox_3);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        romFilename = new QLineEdit(groupBox_3);
        romFilename->setObjectName(QString::fromUtf8("romFilename"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, romFilename);

        romBrowse = new QPushButton(groupBox_3);
        romBrowse->setObjectName(QString::fromUtf8("romBrowse"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, romBrowse);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_5);

        outputFilename = new QLineEdit(groupBox_3);
        outputFilename->setObjectName(QString::fromUtf8("outputFilename"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, outputFilename);

        outputBrowse = new QPushButton(groupBox_3);
        outputBrowse->setObjectName(QString::fromUtf8("outputBrowse"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, outputBrowse);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_7);

        baseType = new QComboBox(groupBox_3);
        baseType->addItem(QString());
        baseType->addItem(QString());
        baseType->addItem(QString());
        baseType->setObjectName(QString::fromUtf8("baseType"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(baseType->sizePolicy().hasHeightForWidth());
        baseType->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, baseType);

        baseLabel = new QLabel(groupBox_3);
        baseLabel->setObjectName(QString::fromUtf8("baseLabel"));
        baseLabel->setEnabled(false);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, baseLabel);

        baseFilename = new QLineEdit(groupBox_3);
        baseFilename->setObjectName(QString::fromUtf8("baseFilename"));
        baseFilename->setEnabled(false);

        formLayout_2->setWidget(6, QFormLayout::FieldRole, baseFilename);

        baseBrowse = new QPushButton(groupBox_3);
        baseBrowse->setObjectName(QString::fromUtf8("baseBrowse"));
        baseBrowse->setEnabled(false);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, baseBrowse);

        line = new QFrame(groupBox_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout_2->setWidget(4, QFormLayout::SpanningRole, line);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox = new QGroupBox(QGBA__ForwarderView);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        system3DS = new QRadioButton(groupBox);
        system = new QButtonGroup(QGBA__ForwarderView);
        system->setObjectName(QString::fromUtf8("system"));
        system->addButton(system3DS);
        system3DS->setObjectName(QString::fromUtf8("system3DS"));

        horizontalLayout_2->addWidget(system3DS, 0, Qt::AlignHCenter);

        systemVita = new QRadioButton(groupBox);
        system->addButton(systemVita);
        systemVita->setObjectName(QString::fromUtf8("systemVita"));

        horizontalLayout_2->addWidget(systemVita, 0, Qt::AlignHCenter);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(QGBA__ForwarderView);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);

        groupBox_2 = new QGroupBox(QGBA__ForwarderView);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        title = new QLineEdit(groupBox_2);
        title->setObjectName(QString::fromUtf8("title"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, title);

        imagesLabel = new QLabel(groupBox_2);
        imagesLabel->setObjectName(QString::fromUtf8("imagesLabel"));
        imagesLabel->setEnabled(false);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, imagesLabel);

        imageSelect = new QComboBox(groupBox_2);
        imageSelect->setObjectName(QString::fromUtf8("imageSelect"));
        imageSelect->setEnabled(false);
        sizePolicy.setHeightForWidth(imageSelect->sizePolicy().hasHeightForWidth());
        imageSelect->setSizePolicy(sizePolicy);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, imageSelect);

        useDefaultImage = new QCheckBox(groupBox_2);
        useDefaultImage->setObjectName(QString::fromUtf8("useDefaultImage"));
        useDefaultImage->setChecked(true);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, useDefaultImage);


        verticalLayout->addLayout(formLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);

        imagePreview = new QLabel(groupBox_2);
        imagePreview->setObjectName(QString::fromUtf8("imagePreview"));
        imagePreview->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(imagePreview->sizePolicy().hasHeightForWidth());
        imagePreview->setSizePolicy(sizePolicy2);
        imagePreview->setMinimumSize(QSize(32, 32));
        imagePreview->setMaximumSize(QSize(128, 128));
        imagePreview->setFrameShape(QFrame::StyledPanel);
        imagePreview->setFrameShadow(QFrame::Sunken);
        imagePreview->setText(QString::fromUtf8(""));
        imagePreview->setScaledContents(true);
        imagePreview->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(imagePreview, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setColumnStretch(1, 1);

        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        preferredLabel = new QLabel(groupBox_2);
        preferredLabel->setObjectName(QString::fromUtf8("preferredLabel"));
        preferredLabel->setEnabled(false);

        horizontalLayout->addWidget(preferredLabel, 0, Qt::AlignRight);

        preferredWidth = new QLabel(groupBox_2);
        preferredWidth->setObjectName(QString::fromUtf8("preferredWidth"));
        preferredWidth->setEnabled(false);
        preferredWidth->setText(QString::fromUtf8("0"));

        horizontalLayout->addWidget(preferredWidth, 0, Qt::AlignRight);

        preferredX = new QLabel(groupBox_2);
        preferredX->setObjectName(QString::fromUtf8("preferredX"));
        preferredX->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(preferredX->sizePolicy().hasHeightForWidth());
        preferredX->setSizePolicy(sizePolicy3);
        preferredX->setText(QString::fromUtf8("\303\227"));

        horizontalLayout->addWidget(preferredX, 0, Qt::AlignHCenter);

        preferredHeight = new QLabel(groupBox_2);
        preferredHeight->setObjectName(QString::fromUtf8("preferredHeight"));
        preferredHeight->setEnabled(false);
        preferredHeight->setText(QString::fromUtf8("0"));

        horizontalLayout->addWidget(preferredHeight);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout);

        imageBrowse = new QPushButton(groupBox_2);
        imageBrowse->setObjectName(QString::fromUtf8("imageBrowse"));
        imageBrowse->setEnabled(false);
        sizePolicy.setHeightForWidth(imageBrowse->sizePolicy().hasHeightForWidth());
        imageBrowse->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(imageBrowse);


        gridLayout->addWidget(groupBox_2, 0, 1, 2, 1);

        progressBar = new QProgressBar(QGBA__ForwarderView);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(false);
        progressBar->setMaximum(1000);
        progressBar->setTextVisible(false);

        gridLayout->addWidget(progressBar, 2, 0, 1, 2);


        retranslateUi(QGBA__ForwarderView);
        QObject::connect(buttonBox, SIGNAL(rejected()), QGBA__ForwarderView, SLOT(deleteLater()));

        QMetaObject::connectSlotsByName(QGBA__ForwarderView);
    } // setupUi

    void retranslateUi(QDialog *QGBA__ForwarderView)
    {
        QGBA__ForwarderView->setWindowTitle(QCoreApplication::translate("QGBA::ForwarderView", "Create forwarder", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("QGBA::ForwarderView", "Files", nullptr));
        label_4->setText(QCoreApplication::translate("QGBA::ForwarderView", "ROM file:", nullptr));
        romBrowse->setText(QCoreApplication::translate("QGBA::ForwarderView", "Browse", nullptr));
        label_5->setText(QCoreApplication::translate("QGBA::ForwarderView", "Output filename:", nullptr));
        outputBrowse->setText(QCoreApplication::translate("QGBA::ForwarderView", "Browse", nullptr));
        label_7->setText(QCoreApplication::translate("QGBA::ForwarderView", "Forwarder base:", nullptr));
        baseType->setItemText(0, QCoreApplication::translate("QGBA::ForwarderView", "Latest stable version", nullptr));
        baseType->setItemText(1, QCoreApplication::translate("QGBA::ForwarderView", "Latest development build", nullptr));
        baseType->setItemText(2, QCoreApplication::translate("QGBA::ForwarderView", "Specific file", nullptr));

        baseLabel->setText(QCoreApplication::translate("QGBA::ForwarderView", "Base file:", nullptr));
        baseBrowse->setText(QCoreApplication::translate("QGBA::ForwarderView", "Browse", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QGBA::ForwarderView", "System", nullptr));
        system3DS->setText(QCoreApplication::translate("QGBA::ForwarderView", "3DS", nullptr));
        systemVita->setText(QCoreApplication::translate("QGBA::ForwarderView", "Vita", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QGBA::ForwarderView", "Presentation", nullptr));
        label->setText(QCoreApplication::translate("QGBA::ForwarderView", "Title:", nullptr));
        imagesLabel->setText(QCoreApplication::translate("QGBA::ForwarderView", "Images:", nullptr));
        useDefaultImage->setText(QCoreApplication::translate("QGBA::ForwarderView", "Use default image", nullptr));
        preferredLabel->setText(QCoreApplication::translate("QGBA::ForwarderView", "Preferred size:", nullptr));
        imageBrowse->setText(QCoreApplication::translate("QGBA::ForwarderView", "Select image file", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class ForwarderView: public Ui_ForwarderView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_FORWARDERVIEW_H
