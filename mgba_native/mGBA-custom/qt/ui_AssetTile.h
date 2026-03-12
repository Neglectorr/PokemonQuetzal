/********************************************************************************
** Form generated from reading UI file 'AssetTile.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSETTILE_H
#define UI_ASSETTILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include "AssetInfo.h"
#include "Swatch.h"

namespace QGBA {

class Ui_AssetTile
{
public:
    QVBoxLayout *verticalLayout;
    QGBA::Swatch *preview;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *tileId;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *paletteId;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *address;
    QFrame *line;
    QGBA::Swatch *color;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_10;
    QLabel *r;
    QLabel *g;
    QLabel *b;

    void setupUi(QGBA::AssetInfo *QGBA__AssetTile)
    {
        if (QGBA__AssetTile->objectName().isEmpty())
            QGBA__AssetTile->setObjectName(QString::fromUtf8("QGBA__AssetTile"));
        QGBA__AssetTile->resize(241, 406);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QGBA__AssetTile->sizePolicy().hasHeightForWidth());
        QGBA__AssetTile->setSizePolicy(sizePolicy);
        QGBA__AssetTile->setWindowTitle(QString::fromUtf8("AssetTile"));
        verticalLayout = new QVBoxLayout(QGBA__AssetTile);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        preview = new QGBA::Swatch(QGBA__AssetTile);
        preview->setObjectName(QString::fromUtf8("preview"));
        preview->setMinimumSize(QSize(87, 87));

        verticalLayout->addWidget(preview, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(QGBA__AssetTile);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        tileId = new QLabel(QGBA__AssetTile);
        tileId->setObjectName(QString::fromUtf8("tileId"));
        tileId->setText(QString::fromUtf8("0"));
        tileId->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tileId->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(tileId);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(QGBA__AssetTile);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        paletteId = new QLabel(QGBA__AssetTile);
        paletteId->setObjectName(QString::fromUtf8("paletteId"));
        paletteId->setText(QString::fromUtf8("0"));
        paletteId->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        paletteId->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_4->addWidget(paletteId);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(QGBA__AssetTile);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        address = new QLabel(QGBA__AssetTile);
        address->setObjectName(QString::fromUtf8("address"));
        address->setText(QString::fromUtf8("0x06000000"));
        address->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        address->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(address);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(QGBA__AssetTile);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        color = new QGBA::Swatch(QGBA__AssetTile);
        color->setObjectName(QString::fromUtf8("color"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(color->sizePolicy().hasHeightForWidth());
        color->setSizePolicy(sizePolicy1);
        color->setMinimumSize(QSize(50, 50));

        verticalLayout->addWidget(color, 0, Qt::AlignHCenter);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_4 = new QLabel(QGBA__AssetTile);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_9->addWidget(label_4);

        label_5 = new QLabel(QGBA__AssetTile);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_9->addWidget(label_5);

        label_6 = new QLabel(QGBA__AssetTile);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_9->addWidget(label_6);


        horizontalLayout_3->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(8, -1, -1, -1);
        r = new QLabel(QGBA__AssetTile);
        r->setObjectName(QString::fromUtf8("r"));
        r->setText(QString::fromUtf8("0x00 (00)"));
        r->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_10->addWidget(r);

        g = new QLabel(QGBA__AssetTile);
        g->setObjectName(QString::fromUtf8("g"));
        g->setText(QString::fromUtf8("0x00 (00)"));
        g->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_10->addWidget(g);

        b = new QLabel(QGBA__AssetTile);
        b->setObjectName(QString::fromUtf8("b"));
        b->setText(QString::fromUtf8("0x00 (00)"));
        b->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_10->addWidget(b);


        horizontalLayout_3->addLayout(verticalLayout_10);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(QGBA__AssetTile);

        QMetaObject::connectSlotsByName(QGBA__AssetTile);
    } // setupUi

    void retranslateUi(QGBA::AssetInfo *QGBA__AssetTile)
    {
        QGBA__AssetTile->setTitle(QString());
        label->setText(QCoreApplication::translate("QGBA::AssetTile", "Tile #", nullptr));
        label_2->setText(QCoreApplication::translate("QGBA::AssetTile", "Palette #", nullptr));
        label_3->setText(QCoreApplication::translate("QGBA::AssetTile", "Address", nullptr));
        label_4->setText(QCoreApplication::translate("QGBA::AssetTile", "Red", nullptr));
        label_5->setText(QCoreApplication::translate("QGBA::AssetTile", "Green", nullptr));
        label_6->setText(QCoreApplication::translate("QGBA::AssetTile", "Blue", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class AssetTile: public Ui_AssetTile {};
} // namespace Ui
} // namespace QGBA

#endif // UI_ASSETTILE_H
