/********************************************************************************
** Form generated from reading UI file 'OverrideView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERRIDEVIEW_H
#define UI_OVERRIDEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace QGBA {

class Ui_OverrideView
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabGBA;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *hwAutodetect;
    QCheckBox *hwRTC;
    QCheckBox *hwGyro;
    QCheckBox *hwTilt;
    QCheckBox *hwLight;
    QCheckBox *hwRumble;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *savetype;
    QLabel *label_3;
    QLineEdit *idleLoop;
    QFrame *line;
    QFrame *line_2;
    QCheckBox *hwGBPlayer;
    QCheckBox *vbaBugCompat;
    QSpacerItem *verticalSpacer;
    QWidget *tabGB;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QComboBox *gbModel;
    QLabel *label_4;
    QComboBox *mbc;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QFrame *color0;
    QFrame *color1;
    QFrame *color2;
    QFrame *color3;
    QLabel *label_6;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QFrame *color4;
    QFrame *color5;
    QFrame *color6;
    QFrame *color7;
    QHBoxLayout *horizontalLayout_4;
    QFrame *color8;
    QFrame *color9;
    QFrame *color10;
    QFrame *color11;
    QComboBox *colorPreset;
    QLabel *label_15;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *QGBA__OverrideView)
    {
        if (QGBA__OverrideView->objectName().isEmpty())
            QGBA__OverrideView->setObjectName(QString::fromUtf8("QGBA__OverrideView"));
        QGBA__OverrideView->resize(444, 288);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QGBA__OverrideView->sizePolicy().hasHeightForWidth());
        QGBA__OverrideView->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(QGBA__OverrideView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(QGBA__OverrideView);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabGBA = new QWidget();
        tabGBA->setObjectName(QString::fromUtf8("tabGBA"));
        gridLayout = new QGridLayout(tabGBA);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(tabGBA);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        hwAutodetect = new QCheckBox(groupBox);
        hwAutodetect->setObjectName(QString::fromUtf8("hwAutodetect"));
        hwAutodetect->setChecked(true);

        verticalLayout_2->addWidget(hwAutodetect);

        hwRTC = new QCheckBox(groupBox);
        hwRTC->setObjectName(QString::fromUtf8("hwRTC"));
        hwRTC->setEnabled(false);

        verticalLayout_2->addWidget(hwRTC);

        hwGyro = new QCheckBox(groupBox);
        hwGyro->setObjectName(QString::fromUtf8("hwGyro"));
        hwGyro->setEnabled(false);

        verticalLayout_2->addWidget(hwGyro);

        hwTilt = new QCheckBox(groupBox);
        hwTilt->setObjectName(QString::fromUtf8("hwTilt"));
        hwTilt->setEnabled(false);

        verticalLayout_2->addWidget(hwTilt);

        hwLight = new QCheckBox(groupBox);
        hwLight->setObjectName(QString::fromUtf8("hwLight"));
        hwLight->setEnabled(false);

        verticalLayout_2->addWidget(hwLight);

        hwRumble = new QCheckBox(groupBox);
        hwRumble->setObjectName(QString::fromUtf8("hwRumble"));
        hwRumble->setEnabled(false);

        verticalLayout_2->addWidget(hwRumble);


        gridLayout->addWidget(groupBox, 0, 0, 3, 1);

        groupBox_2 = new QGroupBox(tabGBA);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        savetype = new QComboBox(groupBox_2);
        savetype->addItem(QString());
        savetype->addItem(QString());
        savetype->addItem(QString());
        savetype->addItem(QString());
        savetype->addItem(QString());
        savetype->addItem(QString());
        savetype->addItem(QString());
        savetype->addItem(QString());
        savetype->setObjectName(QString::fromUtf8("savetype"));

        formLayout->setWidget(0, QFormLayout::FieldRole, savetype);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        idleLoop = new QLineEdit(groupBox_2);
        idleLoop->setObjectName(QString::fromUtf8("idleLoop"));

        formLayout->setWidget(2, QFormLayout::FieldRole, idleLoop);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(1, QFormLayout::SpanningRole, line);


        verticalLayout_3->addLayout(formLayout);

        line_2 = new QFrame(groupBox_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        hwGBPlayer = new QCheckBox(groupBox_2);
        hwGBPlayer->setObjectName(QString::fromUtf8("hwGBPlayer"));

        verticalLayout_3->addWidget(hwGBPlayer);

        vbaBugCompat = new QCheckBox(groupBox_2);
        vbaBugCompat->setObjectName(QString::fromUtf8("vbaBugCompat"));
        vbaBugCompat->setTristate(true);
        vbaBugCompat->setCheckState(Qt::PartiallyChecked);

        verticalLayout_3->addWidget(vbaBugCompat);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        tabWidget->addTab(tabGBA, QString());
        tabGB = new QWidget();
        tabGB->setObjectName(QString::fromUtf8("tabGB"));
        formLayout_3 = new QFormLayout(tabGB);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_2 = new QLabel(tabGB);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        gbModel = new QComboBox(tabGB);
        gbModel->addItem(QString());
        gbModel->setObjectName(QString::fromUtf8("gbModel"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, gbModel);

        label_4 = new QLabel(tabGB);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_4);

        mbc = new QComboBox(tabGB);
        mbc->addItem(QString());
        mbc->setObjectName(QString::fromUtf8("mbc"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, mbc);

        label_5 = new QLabel(tabGB);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        color0 = new QFrame(tabGB);
        color0->setObjectName(QString::fromUtf8("color0"));
        color0->setMinimumSize(QSize(30, 30));
        color0->setAutoFillBackground(true);
        color0->setFrameShape(QFrame::StyledPanel);
        color0->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(color0);

        color1 = new QFrame(tabGB);
        color1->setObjectName(QString::fromUtf8("color1"));
        color1->setMinimumSize(QSize(30, 30));
        color1->setAutoFillBackground(true);
        color1->setFrameShape(QFrame::StyledPanel);
        color1->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(color1);

        color2 = new QFrame(tabGB);
        color2->setObjectName(QString::fromUtf8("color2"));
        color2->setMinimumSize(QSize(30, 30));
        color2->setAutoFillBackground(true);
        color2->setFrameShape(QFrame::StyledPanel);
        color2->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(color2);

        color3 = new QFrame(tabGB);
        color3->setObjectName(QString::fromUtf8("color3"));
        color3->setMinimumSize(QSize(30, 30));
        color3->setAutoFillBackground(true);
        color3->setFrameShape(QFrame::StyledPanel);
        color3->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(color3);


        formLayout_3->setLayout(3, QFormLayout::FieldRole, horizontalLayout);

        label_6 = new QLabel(tabGB);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(tabGB);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        color4 = new QFrame(tabGB);
        color4->setObjectName(QString::fromUtf8("color4"));
        color4->setMinimumSize(QSize(30, 30));
        color4->setAutoFillBackground(true);
        color4->setFrameShape(QFrame::StyledPanel);
        color4->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(color4);

        color5 = new QFrame(tabGB);
        color5->setObjectName(QString::fromUtf8("color5"));
        color5->setMinimumSize(QSize(30, 30));
        color5->setAutoFillBackground(true);
        color5->setFrameShape(QFrame::StyledPanel);
        color5->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(color5);

        color6 = new QFrame(tabGB);
        color6->setObjectName(QString::fromUtf8("color6"));
        color6->setMinimumSize(QSize(30, 30));
        color6->setAutoFillBackground(true);
        color6->setFrameShape(QFrame::StyledPanel);
        color6->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(color6);

        color7 = new QFrame(tabGB);
        color7->setObjectName(QString::fromUtf8("color7"));
        color7->setMinimumSize(QSize(30, 30));
        color7->setAutoFillBackground(true);
        color7->setFrameShape(QFrame::StyledPanel);
        color7->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(color7);


        formLayout_3->setLayout(4, QFormLayout::FieldRole, horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        color8 = new QFrame(tabGB);
        color8->setObjectName(QString::fromUtf8("color8"));
        color8->setMinimumSize(QSize(30, 30));
        color8->setAutoFillBackground(true);
        color8->setFrameShape(QFrame::StyledPanel);
        color8->setFrameShadow(QFrame::Raised);

        horizontalLayout_4->addWidget(color8);

        color9 = new QFrame(tabGB);
        color9->setObjectName(QString::fromUtf8("color9"));
        color9->setMinimumSize(QSize(30, 30));
        color9->setAutoFillBackground(true);
        color9->setFrameShape(QFrame::StyledPanel);
        color9->setFrameShadow(QFrame::Raised);

        horizontalLayout_4->addWidget(color9);

        color10 = new QFrame(tabGB);
        color10->setObjectName(QString::fromUtf8("color10"));
        color10->setMinimumSize(QSize(30, 30));
        color10->setAutoFillBackground(true);
        color10->setFrameShape(QFrame::StyledPanel);
        color10->setFrameShadow(QFrame::Raised);

        horizontalLayout_4->addWidget(color10);

        color11 = new QFrame(tabGB);
        color11->setObjectName(QString::fromUtf8("color11"));
        color11->setMinimumSize(QSize(30, 30));
        color11->setAutoFillBackground(true);
        color11->setFrameShape(QFrame::StyledPanel);
        color11->setFrameShadow(QFrame::Raised);

        horizontalLayout_4->addWidget(color11);


        formLayout_3->setLayout(5, QFormLayout::FieldRole, horizontalLayout_4);

        colorPreset = new QComboBox(tabGB);
        colorPreset->setObjectName(QString::fromUtf8("colorPreset"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, colorPreset);

        label_15 = new QLabel(tabGB);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_15);

        tabWidget->addTab(tabGB, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(QGBA__OverrideView);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Save);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(QGBA__OverrideView);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QGBA__OverrideView);
    } // setupUi

    void retranslateUi(QWidget *QGBA__OverrideView)
    {
        QGBA__OverrideView->setWindowTitle(QCoreApplication::translate("QGBA::OverrideView", "Game Overrides", nullptr));
        groupBox->setTitle(QString());
        hwAutodetect->setText(QCoreApplication::translate("QGBA::OverrideView", "Autodetect", nullptr));
        hwRTC->setText(QCoreApplication::translate("QGBA::OverrideView", "Realtime clock", nullptr));
        hwGyro->setText(QCoreApplication::translate("QGBA::OverrideView", "Gyroscope", nullptr));
        hwTilt->setText(QCoreApplication::translate("QGBA::OverrideView", "Tilt", nullptr));
        hwLight->setText(QCoreApplication::translate("QGBA::OverrideView", "Light sensor", nullptr));
        hwRumble->setText(QCoreApplication::translate("QGBA::OverrideView", "Rumble", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("QGBA::OverrideView", "Save type", nullptr));
        savetype->setItemText(0, QCoreApplication::translate("QGBA::OverrideView", "Autodetect", nullptr));
        savetype->setItemText(1, QCoreApplication::translate("QGBA::OverrideView", "None", nullptr));
        savetype->setItemText(2, QCoreApplication::translate("QGBA::OverrideView", "SRAM", nullptr));
        savetype->setItemText(3, QCoreApplication::translate("QGBA::OverrideView", "Flash 512kb", nullptr));
        savetype->setItemText(4, QCoreApplication::translate("QGBA::OverrideView", "Flash 1Mb", nullptr));
        savetype->setItemText(5, QCoreApplication::translate("QGBA::OverrideView", "EEPROM 8kB", nullptr));
        savetype->setItemText(6, QCoreApplication::translate("QGBA::OverrideView", "EEPROM 512 bytes", nullptr));
        savetype->setItemText(7, QCoreApplication::translate("QGBA::OverrideView", "SRAM 64kB (bootlegs only)", nullptr));

        label_3->setText(QCoreApplication::translate("QGBA::OverrideView", "Idle loop", nullptr));
        hwGBPlayer->setText(QCoreApplication::translate("QGBA::OverrideView", "Game Boy Player features", nullptr));
        vbaBugCompat->setText(QCoreApplication::translate("QGBA::OverrideView", "VBA bug compatibility mode", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGBA), QCoreApplication::translate("QGBA::OverrideView", "Game Boy Advance", nullptr));
        label_2->setText(QCoreApplication::translate("QGBA::OverrideView", "Game Boy model", nullptr));
        gbModel->setItemText(0, QCoreApplication::translate("QGBA::OverrideView", "Autodetect", nullptr));

        label_4->setText(QCoreApplication::translate("QGBA::OverrideView", "Memory bank controller", nullptr));
        mbc->setItemText(0, QCoreApplication::translate("QGBA::OverrideView", "Autodetect", nullptr));

        label_5->setText(QCoreApplication::translate("QGBA::OverrideView", "Background Colors", nullptr));
        label_6->setText(QCoreApplication::translate("QGBA::OverrideView", "Sprite Colors 1", nullptr));
        label_7->setText(QCoreApplication::translate("QGBA::OverrideView", "Sprite Colors 2", nullptr));
        label_15->setText(QCoreApplication::translate("QGBA::OverrideView", "Palette preset", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGB), QCoreApplication::translate("QGBA::OverrideView", "Game Boy", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class OverrideView: public Ui_OverrideView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_OVERRIDEVIEW_H
