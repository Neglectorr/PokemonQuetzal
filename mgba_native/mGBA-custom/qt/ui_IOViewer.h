/********************************************************************************
** Form generated from reading UI file 'IOViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IOVIEWER_H
#define UI_IOVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace QGBA {

class Ui_IOViewer
{
public:
    QVBoxLayout *verticalLayout_2;
    QComboBox *regSelect;
    QLabel *regValue;
    QGridLayout *gridLayout;
    QCheckBox *b3;
    QCheckBox *b4;
    QCheckBox *b2;
    QCheckBox *b0;
    QLabel *l2;
    QCheckBox *b5;
    QCheckBox *b1;
    QLabel *l5;
    QLabel *l4;
    QLabel *l7;
    QLabel *l0;
    QCheckBox *b6;
    QLabel *l9;
    QCheckBox *b9;
    QLabel *l1;
    QLabel *l3;
    QCheckBox *bF;
    QLabel *l8;
    QCheckBox *bD;
    QCheckBox *bE;
    QLabel *lC;
    QLabel *lE;
    QCheckBox *bC;
    QCheckBox *bA;
    QLabel *l6;
    QCheckBox *b8;
    QCheckBox *bB;
    QCheckBox *b7;
    QLabel *lD;
    QLabel *lF;
    QLabel *lA;
    QLabel *lB;
    QFrame *line;
    QWidget *regDescription;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *QGBA__IOViewer)
    {
        if (QGBA__IOViewer->objectName().isEmpty())
            QGBA__IOViewer->setObjectName(QString::fromUtf8("QGBA__IOViewer"));
        QGBA__IOViewer->resize(343, 342);
        verticalLayout_2 = new QVBoxLayout(QGBA__IOViewer);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        regSelect = new QComboBox(QGBA__IOViewer);
        regSelect->setObjectName(QString::fromUtf8("regSelect"));

        verticalLayout_2->addWidget(regSelect);

        regValue = new QLabel(QGBA__IOViewer);
        regValue->setObjectName(QString::fromUtf8("regValue"));
        regValue->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_2->addWidget(regValue, 0, Qt::AlignRight|Qt::AlignTop);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        b3 = new QCheckBox(QGBA__IOViewer);
        b3->setObjectName(QString::fromUtf8("b3"));

        gridLayout->addWidget(b3, 0, 12, 1, 1, Qt::AlignHCenter);

        b4 = new QCheckBox(QGBA__IOViewer);
        b4->setObjectName(QString::fromUtf8("b4"));

        gridLayout->addWidget(b4, 0, 11, 1, 1, Qt::AlignHCenter);

        b2 = new QCheckBox(QGBA__IOViewer);
        b2->setObjectName(QString::fromUtf8("b2"));

        gridLayout->addWidget(b2, 0, 13, 1, 1, Qt::AlignHCenter);

        b0 = new QCheckBox(QGBA__IOViewer);
        b0->setObjectName(QString::fromUtf8("b0"));

        gridLayout->addWidget(b0, 0, 15, 1, 1, Qt::AlignHCenter);

        l2 = new QLabel(QGBA__IOViewer);
        l2->setObjectName(QString::fromUtf8("l2"));
        l2->setMaximumSize(QSize(16777215, 80));
        QFont font;
        font.setPointSize(10);
        l2->setFont(font);
        l2->setText(QString::fromUtf8("2"));

        gridLayout->addWidget(l2, 1, 13, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        b5 = new QCheckBox(QGBA__IOViewer);
        b5->setObjectName(QString::fromUtf8("b5"));

        gridLayout->addWidget(b5, 0, 10, 1, 1, Qt::AlignHCenter);

        b1 = new QCheckBox(QGBA__IOViewer);
        b1->setObjectName(QString::fromUtf8("b1"));

        gridLayout->addWidget(b1, 0, 14, 1, 1, Qt::AlignHCenter);

        l5 = new QLabel(QGBA__IOViewer);
        l5->setObjectName(QString::fromUtf8("l5"));
        l5->setMaximumSize(QSize(16777215, 80));
        l5->setFont(font);
        l5->setText(QString::fromUtf8("5"));

        gridLayout->addWidget(l5, 1, 10, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        l4 = new QLabel(QGBA__IOViewer);
        l4->setObjectName(QString::fromUtf8("l4"));
        l4->setMaximumSize(QSize(16777215, 80));
        l4->setFont(font);
        l4->setText(QString::fromUtf8("4"));

        gridLayout->addWidget(l4, 1, 11, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        l7 = new QLabel(QGBA__IOViewer);
        l7->setObjectName(QString::fromUtf8("l7"));
        l7->setMaximumSize(QSize(16777215, 80));
        l7->setFont(font);
        l7->setText(QString::fromUtf8("7"));

        gridLayout->addWidget(l7, 1, 8, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        l0 = new QLabel(QGBA__IOViewer);
        l0->setObjectName(QString::fromUtf8("l0"));
        l0->setMaximumSize(QSize(16777215, 80));
        l0->setFont(font);
        l0->setText(QString::fromUtf8("0"));

        gridLayout->addWidget(l0, 1, 15, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        b6 = new QCheckBox(QGBA__IOViewer);
        b6->setObjectName(QString::fromUtf8("b6"));

        gridLayout->addWidget(b6, 0, 9, 1, 1, Qt::AlignHCenter);

        l9 = new QLabel(QGBA__IOViewer);
        l9->setObjectName(QString::fromUtf8("l9"));
        l9->setMaximumSize(QSize(16777215, 80));
        l9->setFont(font);
        l9->setText(QString::fromUtf8("9"));

        gridLayout->addWidget(l9, 1, 6, 1, 1, Qt::AlignHCenter);

        b9 = new QCheckBox(QGBA__IOViewer);
        b9->setObjectName(QString::fromUtf8("b9"));

        gridLayout->addWidget(b9, 0, 6, 1, 1, Qt::AlignHCenter);

        l1 = new QLabel(QGBA__IOViewer);
        l1->setObjectName(QString::fromUtf8("l1"));
        l1->setMaximumSize(QSize(16777215, 80));
        l1->setFont(font);
        l1->setText(QString::fromUtf8("1"));

        gridLayout->addWidget(l1, 1, 14, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        l3 = new QLabel(QGBA__IOViewer);
        l3->setObjectName(QString::fromUtf8("l3"));
        l3->setMaximumSize(QSize(16777215, 80));
        l3->setFont(font);
        l3->setText(QString::fromUtf8("3"));

        gridLayout->addWidget(l3, 1, 12, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        bF = new QCheckBox(QGBA__IOViewer);
        bF->setObjectName(QString::fromUtf8("bF"));

        gridLayout->addWidget(bF, 0, 0, 1, 1, Qt::AlignHCenter);

        l8 = new QLabel(QGBA__IOViewer);
        l8->setObjectName(QString::fromUtf8("l8"));
        l8->setMaximumSize(QSize(16777215, 80));
        l8->setFont(font);
        l8->setText(QString::fromUtf8("8"));

        gridLayout->addWidget(l8, 1, 7, 1, 1, Qt::AlignHCenter);

        bD = new QCheckBox(QGBA__IOViewer);
        bD->setObjectName(QString::fromUtf8("bD"));

        gridLayout->addWidget(bD, 0, 2, 1, 1, Qt::AlignHCenter);

        bE = new QCheckBox(QGBA__IOViewer);
        bE->setObjectName(QString::fromUtf8("bE"));

        gridLayout->addWidget(bE, 0, 1, 1, 1, Qt::AlignHCenter);

        lC = new QLabel(QGBA__IOViewer);
        lC->setObjectName(QString::fromUtf8("lC"));
        lC->setMaximumSize(QSize(16777215, 80));
        lC->setFont(font);
        lC->setText(QString::fromUtf8("C"));

        gridLayout->addWidget(lC, 1, 3, 1, 1, Qt::AlignHCenter);

        lE = new QLabel(QGBA__IOViewer);
        lE->setObjectName(QString::fromUtf8("lE"));
        lE->setMaximumSize(QSize(16777215, 80));
        lE->setFont(font);
        lE->setText(QString::fromUtf8("E"));

        gridLayout->addWidget(lE, 1, 1, 1, 1, Qt::AlignHCenter);

        bC = new QCheckBox(QGBA__IOViewer);
        bC->setObjectName(QString::fromUtf8("bC"));

        gridLayout->addWidget(bC, 0, 3, 1, 1, Qt::AlignHCenter);

        bA = new QCheckBox(QGBA__IOViewer);
        bA->setObjectName(QString::fromUtf8("bA"));

        gridLayout->addWidget(bA, 0, 5, 1, 1);

        l6 = new QLabel(QGBA__IOViewer);
        l6->setObjectName(QString::fromUtf8("l6"));
        l6->setMaximumSize(QSize(16777215, 80));
        l6->setFont(font);
        l6->setText(QString::fromUtf8("6"));

        gridLayout->addWidget(l6, 1, 9, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        b8 = new QCheckBox(QGBA__IOViewer);
        b8->setObjectName(QString::fromUtf8("b8"));

        gridLayout->addWidget(b8, 0, 7, 1, 1, Qt::AlignHCenter);

        bB = new QCheckBox(QGBA__IOViewer);
        bB->setObjectName(QString::fromUtf8("bB"));

        gridLayout->addWidget(bB, 0, 4, 1, 1, Qt::AlignHCenter);

        b7 = new QCheckBox(QGBA__IOViewer);
        b7->setObjectName(QString::fromUtf8("b7"));

        gridLayout->addWidget(b7, 0, 8, 1, 1, Qt::AlignHCenter);

        lD = new QLabel(QGBA__IOViewer);
        lD->setObjectName(QString::fromUtf8("lD"));
        lD->setMaximumSize(QSize(16777215, 80));
        lD->setFont(font);
        lD->setText(QString::fromUtf8("D"));

        gridLayout->addWidget(lD, 1, 2, 1, 1, Qt::AlignHCenter);

        lF = new QLabel(QGBA__IOViewer);
        lF->setObjectName(QString::fromUtf8("lF"));
        lF->setMaximumSize(QSize(16777215, 80));
        lF->setFont(font);
        lF->setText(QString::fromUtf8("F"));

        gridLayout->addWidget(lF, 1, 0, 1, 1, Qt::AlignHCenter);

        lA = new QLabel(QGBA__IOViewer);
        lA->setObjectName(QString::fromUtf8("lA"));
        lA->setMaximumSize(QSize(16777215, 80));
        lA->setFont(font);
        lA->setText(QString::fromUtf8("A"));

        gridLayout->addWidget(lA, 1, 5, 1, 1, Qt::AlignHCenter);

        lB = new QLabel(QGBA__IOViewer);
        lB->setObjectName(QString::fromUtf8("lB"));
        lB->setMaximumSize(QSize(16777215, 80));
        lB->setFont(font);

        gridLayout->addWidget(lB, 1, 4, 1, 1, Qt::AlignHCenter);


        verticalLayout_2->addLayout(gridLayout);

        line = new QFrame(QGBA__IOViewer);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        regDescription = new QWidget(QGBA__IOViewer);
        regDescription->setObjectName(QString::fromUtf8("regDescription"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(regDescription->sizePolicy().hasHeightForWidth());
        regDescription->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(regDescription);

        buttonBox = new QDialogButtonBox(QGBA__IOViewer);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Close|QDialogButtonBox::Reset);

        verticalLayout_2->addWidget(buttonBox);

        QWidget::setTabOrder(regSelect, b0);
        QWidget::setTabOrder(b0, b1);
        QWidget::setTabOrder(b1, b2);
        QWidget::setTabOrder(b2, b3);
        QWidget::setTabOrder(b3, b4);
        QWidget::setTabOrder(b4, b5);
        QWidget::setTabOrder(b5, b6);
        QWidget::setTabOrder(b6, b7);
        QWidget::setTabOrder(b7, bE);
        QWidget::setTabOrder(bE, b8);
        QWidget::setTabOrder(b8, b9);
        QWidget::setTabOrder(b9, bA);
        QWidget::setTabOrder(bA, bB);
        QWidget::setTabOrder(bB, bC);
        QWidget::setTabOrder(bC, bD);
        QWidget::setTabOrder(bD, bF);

        retranslateUi(QGBA__IOViewer);

        QMetaObject::connectSlotsByName(QGBA__IOViewer);
    } // setupUi

    void retranslateUi(QWidget *QGBA__IOViewer)
    {
        QGBA__IOViewer->setWindowTitle(QCoreApplication::translate("QGBA::IOViewer", "I/O Viewer", nullptr));
        regValue->setText(QCoreApplication::translate("QGBA::IOViewer", "0x0000", nullptr));
        lB->setText(QCoreApplication::translate("QGBA::IOViewer", "B", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class IOViewer: public Ui_IOViewer {};
} // namespace Ui
} // namespace QGBA

#endif // UI_IOVIEWER_H
