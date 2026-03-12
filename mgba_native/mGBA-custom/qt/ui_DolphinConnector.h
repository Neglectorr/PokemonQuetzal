/********************************************************************************
** Form generated from reading UI file 'DolphinConnector.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOLPHINCONNECTOR_H
#define UI_DOLPHINCONNECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

namespace QGBA {

class Ui_DolphinConnector
{
public:
    QGridLayout *gridLayout;
    QRadioButton *specLocal;
    QRadioButton *specIPAddr;
    QLineEdit *ipAddr;
    QHBoxLayout *horizontalLayout;
    QPushButton *connect;
    QPushButton *disconnect;
    QPushButton *close;
    QCheckBox *doReset;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *QGBA__DolphinConnector)
    {
        if (QGBA__DolphinConnector->objectName().isEmpty())
            QGBA__DolphinConnector->setObjectName(QString::fromUtf8("QGBA__DolphinConnector"));
        QGBA__DolphinConnector->resize(306, 123);
        gridLayout = new QGridLayout(QGBA__DolphinConnector);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        specLocal = new QRadioButton(QGBA__DolphinConnector);
        buttonGroup = new QButtonGroup(QGBA__DolphinConnector);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(specLocal);
        specLocal->setObjectName(QString::fromUtf8("specLocal"));
        specLocal->setChecked(true);

        gridLayout->addWidget(specLocal, 0, 0, 1, 1);

        specIPAddr = new QRadioButton(QGBA__DolphinConnector);
        buttonGroup->addButton(specIPAddr);
        specIPAddr->setObjectName(QString::fromUtf8("specIPAddr"));

        gridLayout->addWidget(specIPAddr, 0, 1, 1, 1);

        ipAddr = new QLineEdit(QGBA__DolphinConnector);
        ipAddr->setObjectName(QString::fromUtf8("ipAddr"));
        ipAddr->setEnabled(false);

        gridLayout->addWidget(ipAddr, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        connect = new QPushButton(QGBA__DolphinConnector);
        connect->setObjectName(QString::fromUtf8("connect"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("network-connect")));
        connect->setIcon(icon);

        horizontalLayout->addWidget(connect);

        disconnect = new QPushButton(QGBA__DolphinConnector);
        disconnect->setObjectName(QString::fromUtf8("disconnect"));
        disconnect->setEnabled(false);
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("network-disconnect")));
        disconnect->setIcon(icon1);

        horizontalLayout->addWidget(disconnect);

        close = new QPushButton(QGBA__DolphinConnector);
        close->setObjectName(QString::fromUtf8("close"));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("window-close")));
        close->setIcon(icon2);

        horizontalLayout->addWidget(close);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        doReset = new QCheckBox(QGBA__DolphinConnector);
        doReset->setObjectName(QString::fromUtf8("doReset"));

        gridLayout->addWidget(doReset, 2, 0, 1, 1);


        retranslateUi(QGBA__DolphinConnector);
        QObject::connect(close, SIGNAL(clicked()), QGBA__DolphinConnector, SLOT(close()));
        QObject::connect(specIPAddr, SIGNAL(toggled(bool)), ipAddr, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(QGBA__DolphinConnector);
    } // setupUi

    void retranslateUi(QDialog *QGBA__DolphinConnector)
    {
        QGBA__DolphinConnector->setWindowTitle(QCoreApplication::translate("QGBA::DolphinConnector", "Connect to Dolphin", nullptr));
        specLocal->setText(QCoreApplication::translate("QGBA::DolphinConnector", "Local computer", nullptr));
        specIPAddr->setText(QCoreApplication::translate("QGBA::DolphinConnector", "IP address", nullptr));
        connect->setText(QCoreApplication::translate("QGBA::DolphinConnector", "Connect", nullptr));
        disconnect->setText(QCoreApplication::translate("QGBA::DolphinConnector", "Disconnect", nullptr));
        close->setText(QCoreApplication::translate("QGBA::DolphinConnector", "Close", nullptr));
        doReset->setText(QCoreApplication::translate("QGBA::DolphinConnector", "Reset on connect", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class DolphinConnector: public Ui_DolphinConnector {};
} // namespace Ui
} // namespace QGBA

#endif // UI_DOLPHINCONNECTOR_H
