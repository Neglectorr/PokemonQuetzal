/********************************************************************************
** Form generated from reading UI file 'PrinterView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTERVIEW_H
#define UI_PRINTERVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace QGBA {

class Ui_PrinterView
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QLabel *image;
    QFrame *line;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *hurry;
    QPushButton *tear;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *magnification;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *copyButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *QGBA__PrinterView)
    {
        if (QGBA__PrinterView->objectName().isEmpty())
            QGBA__PrinterView->setObjectName(QString::fromUtf8("QGBA__PrinterView"));
        QGBA__PrinterView->resize(246, 425);
        verticalLayout = new QVBoxLayout(QGBA__PrinterView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(QGBA__PrinterView);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 234, 249));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        image = new QLabel(scrollAreaWidgetContents);
        image->setObjectName(QString::fromUtf8("image"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy);
        image->setMinimumSize(QSize(160, 1));
        image->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout->addWidget(image, 1, 1, 1, 1);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnMinimumWidth(1, 160);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        hurry = new QPushButton(QGBA__PrinterView);
        hurry->setObjectName(QString::fromUtf8("hurry"));
        hurry->setEnabled(false);

        horizontalLayout_2->addWidget(hurry);

        tear = new QPushButton(QGBA__PrinterView);
        tear->setObjectName(QString::fromUtf8("tear"));

        horizontalLayout_2->addWidget(tear);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        magnification = new QSpinBox(QGBA__PrinterView);
        magnification->setObjectName(QString::fromUtf8("magnification"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(magnification->sizePolicy().hasHeightForWidth());
        magnification->setSizePolicy(sizePolicy1);
        magnification->setSuffix(QString::fromUtf8("\303\227"));
        magnification->setMinimum(1);
        magnification->setMaximum(8);

        horizontalLayout_4->addWidget(magnification);

        label_2 = new QLabel(QGBA__PrinterView);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        copyButton = new QPushButton(QGBA__PrinterView);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));
        sizePolicy1.setHeightForWidth(copyButton->sizePolicy().hasHeightForWidth());
        copyButton->setSizePolicy(sizePolicy1);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("edit-copy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        copyButton->setIcon(icon);

        horizontalLayout_3->addWidget(copyButton);

        buttonBox = new QDialogButtonBox(QGBA__PrinterView);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Save);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(QGBA__PrinterView);
        QObject::connect(buttonBox, SIGNAL(rejected()), QGBA__PrinterView, SLOT(close()));

        QMetaObject::connectSlotsByName(QGBA__PrinterView);
    } // setupUi

    void retranslateUi(QWidget *QGBA__PrinterView)
    {
        QGBA__PrinterView->setWindowTitle(QCoreApplication::translate("QGBA::PrinterView", "Game Boy Printer", nullptr));
        hurry->setText(QCoreApplication::translate("QGBA::PrinterView", "Hurry up!", nullptr));
        tear->setText(QCoreApplication::translate("QGBA::PrinterView", "Tear off", nullptr));
        label_2->setText(QCoreApplication::translate("QGBA::PrinterView", "Magnification", nullptr));
        copyButton->setText(QCoreApplication::translate("QGBA::PrinterView", "Copy", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class PrinterView: public Ui_PrinterView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_PRINTERVIEW_H
