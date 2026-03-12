/********************************************************************************
** Form generated from reading UI file 'GIFView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIFVIEW_H
#define UI_GIFVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

namespace QGBA {

class Ui_GIFView
{
public:
    QGridLayout *gridLayout_3;
    QDialogButtonBox *buttonBox;
    QCheckBox *loop;
    QGridLayout *gridLayout;
    QPushButton *start;
    QPushButton *stop;
    QSpacerItem *horizontalSpacer;
    QPushButton *selectFile;
    QLineEdit *filename;
    QRadioButton *fmtApng;
    QRadioButton *fmtGif;
    QRadioButton *fmtWebP;
    QLabel *label;
    QSpinBox *frameskip;
    QButtonGroup *format;

    void setupUi(QWidget *QGBA__GIFView)
    {
        if (QGBA__GIFView->objectName().isEmpty())
            QGBA__GIFView->setObjectName(QString::fromUtf8("QGBA__GIFView"));
        QGBA__GIFView->resize(392, 225);
        gridLayout_3 = new QGridLayout(QGBA__GIFView);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        buttonBox = new QDialogButtonBox(QGBA__GIFView);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout_3->addWidget(buttonBox, 4, 0, 1, 3);

        loop = new QCheckBox(QGBA__GIFView);
        loop->setObjectName(QString::fromUtf8("loop"));
        loop->setChecked(true);

        gridLayout_3->addWidget(loop, 1, 1, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        start = new QPushButton(QGBA__GIFView);
        start->setObjectName(QString::fromUtf8("start"));
        start->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy);

        gridLayout->addWidget(start, 1, 0, 1, 1);

        stop = new QPushButton(QGBA__GIFView);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setEnabled(false);
        sizePolicy.setHeightForWidth(stop->sizePolicy().hasHeightForWidth());
        stop->setSizePolicy(sizePolicy);

        gridLayout->addWidget(stop, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        selectFile = new QPushButton(QGBA__GIFView);
        selectFile->setObjectName(QString::fromUtf8("selectFile"));
        sizePolicy.setHeightForWidth(selectFile->sizePolicy().hasHeightForWidth());
        selectFile->setSizePolicy(sizePolicy);

        gridLayout->addWidget(selectFile, 1, 3, 1, 1);

        filename = new QLineEdit(QGBA__GIFView);
        filename->setObjectName(QString::fromUtf8("filename"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(filename->sizePolicy().hasHeightForWidth());
        filename->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(filename, 0, 0, 1, 4);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 3);

        fmtApng = new QRadioButton(QGBA__GIFView);
        format = new QButtonGroup(QGBA__GIFView);
        format->setObjectName(QString::fromUtf8("format"));
        format->addButton(fmtApng);
        fmtApng->setObjectName(QString::fromUtf8("fmtApng"));

        gridLayout_3->addWidget(fmtApng, 3, 0, 1, 1);

        fmtGif = new QRadioButton(QGBA__GIFView);
        format->addButton(fmtGif);
        fmtGif->setObjectName(QString::fromUtf8("fmtGif"));
        fmtGif->setChecked(true);

        gridLayout_3->addWidget(fmtGif, 1, 0, 1, 1);

        fmtWebP = new QRadioButton(QGBA__GIFView);
        format->addButton(fmtWebP);
        fmtWebP->setObjectName(QString::fromUtf8("fmtWebP"));

        gridLayout_3->addWidget(fmtWebP, 2, 0, 1, 1);

        label = new QLabel(QGBA__GIFView);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 2, 1, 1, 1);

        frameskip = new QSpinBox(QGBA__GIFView);
        frameskip->setObjectName(QString::fromUtf8("frameskip"));
        sizePolicy.setHeightForWidth(frameskip->sizePolicy().hasHeightForWidth());
        frameskip->setSizePolicy(sizePolicy);
        frameskip->setMaximum(9);
        frameskip->setValue(2);

        gridLayout_3->addWidget(frameskip, 2, 2, 1, 1);

        QWidget::setTabOrder(filename, start);
        QWidget::setTabOrder(start, stop);
        QWidget::setTabOrder(stop, selectFile);
        QWidget::setTabOrder(selectFile, fmtGif);
        QWidget::setTabOrder(fmtGif, fmtWebP);
        QWidget::setTabOrder(fmtWebP, fmtApng);
        QWidget::setTabOrder(fmtApng, loop);
        QWidget::setTabOrder(loop, frameskip);

        retranslateUi(QGBA__GIFView);
        QObject::connect(buttonBox, SIGNAL(rejected()), QGBA__GIFView, SLOT(close()));

        QMetaObject::connectSlotsByName(QGBA__GIFView);
    } // setupUi

    void retranslateUi(QWidget *QGBA__GIFView)
    {
        QGBA__GIFView->setWindowTitle(QCoreApplication::translate("QGBA::GIFView", "Record GIF/WebP/APNG", nullptr));
        loop->setText(QCoreApplication::translate("QGBA::GIFView", "Loop", nullptr));
        start->setText(QCoreApplication::translate("QGBA::GIFView", "Start", nullptr));
        stop->setText(QCoreApplication::translate("QGBA::GIFView", "Stop", nullptr));
        selectFile->setText(QCoreApplication::translate("QGBA::GIFView", "Select File", nullptr));
        fmtApng->setText(QCoreApplication::translate("QGBA::GIFView", "APNG", nullptr));
        fmtGif->setText(QCoreApplication::translate("QGBA::GIFView", "GIF", nullptr));
        fmtWebP->setText(QCoreApplication::translate("QGBA::GIFView", "WebP", nullptr));
        label->setText(QCoreApplication::translate("QGBA::GIFView", "Frameskip", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class GIFView: public Ui_GIFView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_GIFVIEW_H
