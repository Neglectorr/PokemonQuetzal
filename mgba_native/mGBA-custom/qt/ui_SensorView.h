/********************************************************************************
** Form generated from reading UI file 'SensorView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSORVIEW_H
#define UI_SENSORVIEW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace QGBA {

class Ui_SensorView
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QRadioButton *timeNoOverride;
    QRadioButton *timeFixed;
    QPushButton *timeNow;
    QRadioButton *timeOffset;
    QSpinBox *offsetSeconds;
    QRadioButton *timeFakeEpoch;
    QDateTimeEdit *time;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QLabel *label_4;
    QSpinBox *lightSpin;
    QSlider *lightSlide;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *tilt;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_11;
    QPushButton *tiltSetY;
    QPushButton *tiltSetX;
    QDoubleSpinBox *tiltX;
    QDoubleSpinBox *tiltY;
    QGroupBox *gyro;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_17;
    QPushButton *gyroSetY;
    QPushButton *gyroSetX;
    QLabel *label_2;
    QDoubleSpinBox *gyroSensitivity;
    QSlider *gyroView;
    QButtonGroup *timeButtons;

    void setupUi(QWidget *QGBA__SensorView)
    {
        if (QGBA__SensorView->objectName().isEmpty())
            QGBA__SensorView->setObjectName(QString::fromUtf8("QGBA__SensorView"));
        QGBA__SensorView->resize(448, 332);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QGBA__SensorView->sizePolicy().hasHeightForWidth());
        QGBA__SensorView->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(QGBA__SensorView);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(QGBA__SensorView);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        timeNoOverride = new QRadioButton(groupBox);
        timeButtons = new QButtonGroup(QGBA__SensorView);
        timeButtons->setObjectName(QString::fromUtf8("timeButtons"));
        timeButtons->addButton(timeNoOverride);
        timeNoOverride->setObjectName(QString::fromUtf8("timeNoOverride"));
        timeNoOverride->setChecked(true);

        gridLayout_4->addWidget(timeNoOverride, 0, 0, 1, 1);

        timeFixed = new QRadioButton(groupBox);
        timeButtons->addButton(timeFixed);
        timeFixed->setObjectName(QString::fromUtf8("timeFixed"));

        gridLayout_4->addWidget(timeFixed, 1, 0, 1, 1);

        timeNow = new QPushButton(groupBox);
        timeNow->setObjectName(QString::fromUtf8("timeNow"));

        gridLayout_4->addWidget(timeNow, 1, 1, 1, 1);

        timeOffset = new QRadioButton(groupBox);
        timeButtons->addButton(timeOffset);
        timeOffset->setObjectName(QString::fromUtf8("timeOffset"));

        gridLayout_4->addWidget(timeOffset, 2, 0, 1, 1);

        offsetSeconds = new QSpinBox(groupBox);
        offsetSeconds->setObjectName(QString::fromUtf8("offsetSeconds"));
        offsetSeconds->setAccelerated(true);
        offsetSeconds->setMinimum(-99999999);
        offsetSeconds->setMaximum(99999999);
        offsetSeconds->setSingleStep(1);

        gridLayout_4->addWidget(offsetSeconds, 2, 1, 1, 1);

        timeFakeEpoch = new QRadioButton(groupBox);
        timeButtons->addButton(timeFakeEpoch);
        timeFakeEpoch->setObjectName(QString::fromUtf8("timeFakeEpoch"));

        gridLayout_4->addWidget(timeFakeEpoch, 3, 0, 1, 1);

        time = new QDateTimeEdit(groupBox);
        time->setObjectName(QString::fromUtf8("time"));
        time->setWrapping(true);
        time->setMaximumDate(QDate(2099, 12, 31));
        time->setMinimumDate(QDate(2000, 1, 1));
        time->setCurrentSection(QDateTimeEdit::MonthSection);

        gridLayout_4->addWidget(time, 4, 0, 1, 2);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(QGBA__SensorView);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_6->addWidget(label_4, 0, 0, 1, 1);

        lightSpin = new QSpinBox(groupBox_2);
        lightSpin->setObjectName(QString::fromUtf8("lightSpin"));
        lightSpin->setMaximum(255);

        gridLayout_6->addWidget(lightSpin, 0, 1, 1, 1);

        lightSlide = new QSlider(groupBox_2);
        lightSlide->setObjectName(QString::fromUtf8("lightSlide"));
        lightSlide->setMaximum(255);
        lightSlide->setOrientation(Qt::Horizontal);
        lightSlide->setTickPosition(QSlider::TicksBelow);
        lightSlide->setTickInterval(16);

        gridLayout_6->addWidget(lightSlide, 1, 0, 1, 2);


        verticalLayout_2->addWidget(groupBox_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tilt = new QGroupBox(QGBA__SensorView);
        tilt->setObjectName(QString::fromUtf8("tilt"));
        gridLayout_10 = new QGridLayout(tilt);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        tiltSetY = new QPushButton(tilt);
        tiltSetY->setObjectName(QString::fromUtf8("tiltSetY"));
        tiltSetY->setCheckable(true);

        gridLayout_11->addWidget(tiltSetY, 0, 1, 1, 1);

        tiltSetX = new QPushButton(tilt);
        tiltSetX->setObjectName(QString::fromUtf8("tiltSetX"));
        tiltSetX->setCheckable(true);

        gridLayout_11->addWidget(tiltSetX, 0, 0, 1, 1);

        tiltX = new QDoubleSpinBox(tilt);
        tiltX->setObjectName(QString::fromUtf8("tiltX"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tiltX->sizePolicy().hasHeightForWidth());
        tiltX->setSizePolicy(sizePolicy1);
        tiltX->setAlignment(Qt::AlignCenter);
        tiltX->setReadOnly(true);
        tiltX->setButtonSymbols(QAbstractSpinBox::NoButtons);
        tiltX->setMinimum(-1.000000000000000);
        tiltX->setMaximum(1.000000000000000);
        tiltX->setSingleStep(0.010000000000000);

        gridLayout_11->addWidget(tiltX, 1, 0, 1, 1, Qt::AlignHCenter);

        tiltY = new QDoubleSpinBox(tilt);
        tiltY->setObjectName(QString::fromUtf8("tiltY"));
        sizePolicy1.setHeightForWidth(tiltY->sizePolicy().hasHeightForWidth());
        tiltY->setSizePolicy(sizePolicy1);
        tiltY->setAlignment(Qt::AlignCenter);
        tiltY->setReadOnly(true);
        tiltY->setButtonSymbols(QAbstractSpinBox::NoButtons);
        tiltY->setMinimum(-1.000000000000000);
        tiltY->setMaximum(1.000000000000000);
        tiltY->setSingleStep(0.010000000000000);

        gridLayout_11->addWidget(tiltY, 1, 1, 1, 1, Qt::AlignHCenter);


        gridLayout_10->addLayout(gridLayout_11, 0, 0, 1, 2);


        verticalLayout_3->addWidget(tilt);

        gyro = new QGroupBox(QGBA__SensorView);
        gyro->setObjectName(QString::fromUtf8("gyro"));
        gridLayout_12 = new QGridLayout(gyro);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gyroSetY = new QPushButton(gyro);
        gyroSetY->setObjectName(QString::fromUtf8("gyroSetY"));
        gyroSetY->setCheckable(true);

        gridLayout_17->addWidget(gyroSetY, 0, 1, 1, 1);

        gyroSetX = new QPushButton(gyro);
        gyroSetX->setObjectName(QString::fromUtf8("gyroSetX"));
        gyroSetX->setCheckable(true);

        gridLayout_17->addWidget(gyroSetX, 0, 0, 1, 1);

        label_2 = new QLabel(gyro);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_17->addWidget(label_2, 2, 0, 1, 1);

        gyroSensitivity = new QDoubleSpinBox(gyro);
        gyroSensitivity->setObjectName(QString::fromUtf8("gyroSensitivity"));
        gyroSensitivity->setDecimals(0);
        gyroSensitivity->setMaximum(1000.000000000000000);

        gridLayout_17->addWidget(gyroSensitivity, 2, 1, 1, 1);

        gyroView = new QSlider(gyro);
        gyroView->setObjectName(QString::fromUtf8("gyroView"));
        gyroView->setEnabled(false);
        gyroView->setMinimum(-1073741823);
        gyroView->setMaximum(1073741823);
        gyroView->setValue(0);
        gyroView->setTracking(false);
        gyroView->setOrientation(Qt::Horizontal);

        gridLayout_17->addWidget(gyroView, 1, 0, 1, 2);


        gridLayout_12->addLayout(gridLayout_17, 0, 0, 1, 2);


        verticalLayout_3->addWidget(gyro);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(QGBA__SensorView);

        QMetaObject::connectSlotsByName(QGBA__SensorView);
    } // setupUi

    void retranslateUi(QWidget *QGBA__SensorView)
    {
        QGBA__SensorView->setWindowTitle(QCoreApplication::translate("QGBA::SensorView", "Sensors", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QGBA::SensorView", "Realtime clock", nullptr));
        timeNoOverride->setText(QCoreApplication::translate("QGBA::SensorView", "System time", nullptr));
        timeFixed->setText(QCoreApplication::translate("QGBA::SensorView", "Fixed time", nullptr));
        timeNow->setText(QCoreApplication::translate("QGBA::SensorView", "Now", nullptr));
        timeOffset->setText(QCoreApplication::translate("QGBA::SensorView", "Offset time", nullptr));
        offsetSeconds->setSuffix(QCoreApplication::translate("QGBA::SensorView", " sec", nullptr));
        timeFakeEpoch->setText(QCoreApplication::translate("QGBA::SensorView", "Start time at", nullptr));
        time->setDisplayFormat(QCoreApplication::translate("QGBA::SensorView", "MM/dd/yy hh:mm:ss AP", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QGBA::SensorView", "Light sensor", nullptr));
        label_4->setText(QCoreApplication::translate("QGBA::SensorView", "Brightness", nullptr));
        tilt->setTitle(QCoreApplication::translate("QGBA::SensorView", "Tilt sensor", nullptr));
        tiltSetY->setText(QCoreApplication::translate("QGBA::SensorView", "Set Y", nullptr));
        tiltSetX->setText(QCoreApplication::translate("QGBA::SensorView", "Set X", nullptr));
        gyro->setTitle(QCoreApplication::translate("QGBA::SensorView", "Gyroscope", nullptr));
        gyroSetY->setText(QCoreApplication::translate("QGBA::SensorView", "Set Y", nullptr));
        gyroSetX->setText(QCoreApplication::translate("QGBA::SensorView", "Set X", nullptr));
        label_2->setText(QCoreApplication::translate("QGBA::SensorView", "Sensitivity", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class SensorView: public Ui_SensorView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_SENSORVIEW_H
