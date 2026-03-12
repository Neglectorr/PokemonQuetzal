/********************************************************************************
** Form generated from reading UI file 'ObjView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJVIEW_H
#define UI_OBJVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "AssetTile.h"
#include "TilePainter.h"

namespace QGBA {

class Ui_ObjView
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QGBA::TilePainter *tiles;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *objId;
    QLabel *label_3;
    QLabel *address;
    QPushButton *copyButton;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *magnification;
    QLabel *label_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *x;
    QLabel *tileId_3;
    QLabel *y;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *w;
    QLabel *tileId_5;
    QLabel *h;
    QGridLayout *gridLayout_5;
    QLabel *xformPC;
    QLabel *xformPA;
    QLabel *label_10;
    QLabel *xformPD;
    QSpacerItem *horizontalSpacer_8;
    QLabel *xformPB;
    QListWidget *objList;
    QPushButton *exportButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *transform;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_13;
    QLabel *palette;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_15;
    QCheckBox *doubleSize;
    QFrame *line;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *flippedH;
    QCheckBox *flippedV;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_5;
    QLabel *mode;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_12;
    QCheckBox *mosaic;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_11;
    QCheckBox *enabled;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_14;
    QLabel *priority;
    QGBA::AssetTile *tile;

    void setupUi(QWidget *QGBA__ObjView)
    {
        if (QGBA__ObjView->objectName().isEmpty())
            QGBA__ObjView->setObjectName(QString::fromUtf8("QGBA__ObjView"));
        QGBA__ObjView->resize(800, 730);
        gridLayout = new QGridLayout(QGBA__ObjView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(QGBA__ObjView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tiles = new QGBA::TilePainter(frame);
        tiles->setObjectName(QString::fromUtf8("tiles"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tiles->sizePolicy().hasHeightForWidth());
        tiles->setSizePolicy(sizePolicy);
        tiles->setMinimumSize(QSize(8, 8));

        gridLayout_2->addWidget(tiles, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        gridLayout->addWidget(frame, 0, 2, 4, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        objId = new QSpinBox(QGBA__ObjView);
        objId->setObjectName(QString::fromUtf8("objId"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(objId->sizePolicy().hasHeightForWidth());
        objId->setSizePolicy(sizePolicy1);
        objId->setMaximum(127);

        horizontalLayout_2->addWidget(objId);

        label_3 = new QLabel(QGBA__ObjView);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        address = new QLabel(QGBA__ObjView);
        address->setObjectName(QString::fromUtf8("address"));
        address->setText(QString::fromUtf8("0x07000000"));
        address->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        address->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(address);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        copyButton = new QPushButton(QGBA__ObjView);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));

        gridLayout->addWidget(copyButton, 4, 3, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        magnification = new QSpinBox(QGBA__ObjView);
        magnification->setObjectName(QString::fromUtf8("magnification"));
        sizePolicy.setHeightForWidth(magnification->sizePolicy().hasHeightForWidth());
        magnification->setSizePolicy(sizePolicy);
        magnification->setSuffix(QString::fromUtf8("\303\227"));
        magnification->setMinimum(1);
        magnification->setMaximum(8);

        horizontalLayout_4->addWidget(magnification);

        label_2 = new QLabel(QGBA__ObjView);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        groupBox = new QGroupBox(QGBA__ObjView);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        x = new QLabel(groupBox);
        x->setObjectName(QString::fromUtf8("x"));
        x->setMinimumSize(QSize(20, 0));
        x->setText(QString::fromUtf8("0"));
        x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        x->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(x);

        tileId_3 = new QLabel(groupBox);
        tileId_3->setObjectName(QString::fromUtf8("tileId_3"));
        tileId_3->setText(QString::fromUtf8(", "));
        tileId_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(tileId_3);

        y = new QLabel(groupBox);
        y->setObjectName(QString::fromUtf8("y"));
        y->setMinimumSize(QSize(20, 0));
        y->setText(QString::fromUtf8("0"));
        y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        y->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(y);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 0, 1, 2, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        w = new QLabel(groupBox);
        w->setObjectName(QString::fromUtf8("w"));
        w->setMinimumSize(QSize(20, 0));
        w->setText(QString::fromUtf8("8"));
        w->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        w->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_3->addWidget(w);

        tileId_5 = new QLabel(groupBox);
        tileId_5->setObjectName(QString::fromUtf8("tileId_5"));
        tileId_5->setText(QString::fromUtf8("\303\227"));
        tileId_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(tileId_5);

        h = new QLabel(groupBox);
        h->setObjectName(QString::fromUtf8("h"));
        h->setMinimumSize(QSize(20, 0));
        h->setText(QString::fromUtf8("8"));
        h->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        h->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_3->addWidget(h);


        gridLayout_4->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        xformPC = new QLabel(groupBox);
        xformPC->setObjectName(QString::fromUtf8("xformPC"));
        xformPC->setText(QString::fromUtf8("+0.00"));
        xformPC->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_5->addWidget(xformPC, 0, 3, 1, 1);

        xformPA = new QLabel(groupBox);
        xformPA->setObjectName(QString::fromUtf8("xformPA"));
        xformPA->setText(QString::fromUtf8("+1.00"));
        xformPA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_5->addWidget(xformPA, 0, 2, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_5->addWidget(label_10, 0, 0, 1, 1);

        xformPD = new QLabel(groupBox);
        xformPD->setObjectName(QString::fromUtf8("xformPD"));
        xformPD->setText(QString::fromUtf8("+1.00"));
        xformPD->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_5->addWidget(xformPD, 1, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 0, 1, 1, 1);

        xformPB = new QLabel(groupBox);
        xformPB->setObjectName(QString::fromUtf8("xformPB"));
        xformPB->setText(QString::fromUtf8("+0.00"));
        xformPB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_5->addWidget(xformPB, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_5, 0, 2, 2, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        objList = new QListWidget(QGBA__ObjView);
        objList->setObjectName(QString::fromUtf8("objList"));
        objList->setIconSize(QSize(64, 64));
        objList->setFlow(QListView::LeftToRight);
        objList->setResizeMode(QListView::Adjust);
        objList->setGridSize(QSize(64, 96));
        objList->setViewMode(QListView::IconMode);
        objList->setUniformItemSizes(true);

        gridLayout->addWidget(objList, 5, 0, 1, 4);

        exportButton = new QPushButton(QGBA__ObjView);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));

        gridLayout->addWidget(exportButton, 4, 2, 1, 1);

        groupBox_2 = new QGroupBox(QGBA__ObjView);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        transform = new QLabel(groupBox_2);
        transform->setObjectName(QString::fromUtf8("transform"));
        transform->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_6->addWidget(transform);


        gridLayout_3->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_16->addWidget(label_16);

        horizontalSpacer_13 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_13);

        palette = new QLabel(groupBox_2);
        palette->setObjectName(QString::fromUtf8("palette"));
        palette->setText(QString::fromUtf8("0"));
        palette->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        palette->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_16->addWidget(palette);


        gridLayout_3->addLayout(horizontalLayout_16, 1, 0, 1, 1);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_18->addWidget(label_18);

        horizontalSpacer_15 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_15);

        doubleSize = new QCheckBox(groupBox_2);
        doubleSize->setObjectName(QString::fromUtf8("doubleSize"));
        doubleSize->setEnabled(false);

        horizontalLayout_18->addWidget(doubleSize);


        gridLayout_3->addLayout(horizontalLayout_18, 2, 2, 1, 1);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 0, 1, 4, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        flippedH = new QCheckBox(groupBox_2);
        flippedH->setObjectName(QString::fromUtf8("flippedH"));
        flippedH->setEnabled(false);

        horizontalLayout_5->addWidget(flippedH);

        flippedV = new QCheckBox(groupBox_2);
        flippedV->setObjectName(QString::fromUtf8("flippedV"));
        flippedV->setEnabled(false);

        horizontalLayout_5->addWidget(flippedV);


        gridLayout_3->addLayout(horizontalLayout_5, 0, 2, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        horizontalSpacer_5 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        mode = new QLabel(groupBox_2);
        mode->setObjectName(QString::fromUtf8("mode"));
        mode->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_7->addWidget(mode);


        gridLayout_3->addLayout(horizontalLayout_7, 3, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_15->addWidget(label_15);

        horizontalSpacer_12 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_12);

        mosaic = new QCheckBox(groupBox_2);
        mosaic->setObjectName(QString::fromUtf8("mosaic"));
        mosaic->setEnabled(false);

        horizontalLayout_15->addWidget(mosaic);


        gridLayout_3->addLayout(horizontalLayout_15, 3, 2, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_14->addWidget(label_14);

        horizontalSpacer_11 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_11);

        enabled = new QCheckBox(groupBox_2);
        enabled->setObjectName(QString::fromUtf8("enabled"));
        enabled->setEnabled(false);

        horizontalLayout_14->addWidget(enabled);


        gridLayout_3->addLayout(horizontalLayout_14, 1, 2, 1, 1);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_17->addWidget(label_17);

        horizontalSpacer_14 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_14);

        priority = new QLabel(groupBox_2);
        priority->setObjectName(QString::fromUtf8("priority"));
        priority->setText(QString::fromUtf8("0"));
        priority->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        priority->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_17->addWidget(priority);


        gridLayout_3->addLayout(horizontalLayout_17, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 3, 0, 2, 1);

        tile = new QGBA::AssetTile(QGBA__ObjView);
        tile->setObjectName(QString::fromUtf8("tile"));

        gridLayout->addWidget(tile, 0, 1, 5, 1);

        gridLayout->setColumnStretch(3, 1);

        retranslateUi(QGBA__ObjView);
        QObject::connect(magnification, SIGNAL(valueChanged(int)), tiles, SLOT(setTileMagnification(int)));

        QMetaObject::connectSlotsByName(QGBA__ObjView);
    } // setupUi

    void retranslateUi(QWidget *QGBA__ObjView)
    {
        QGBA__ObjView->setWindowTitle(QCoreApplication::translate("QGBA::ObjView", "Sprites", nullptr));
        label_3->setText(QCoreApplication::translate("QGBA::ObjView", "Address", nullptr));
        copyButton->setText(QCoreApplication::translate("QGBA::ObjView", "Copy", nullptr));
        label_2->setText(QCoreApplication::translate("QGBA::ObjView", "Magnification", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QGBA::ObjView", "Geometry", nullptr));
        label->setText(QCoreApplication::translate("QGBA::ObjView", "Position", nullptr));
        label_4->setText(QCoreApplication::translate("QGBA::ObjView", "Dimensions", nullptr));
        label_10->setText(QCoreApplication::translate("QGBA::ObjView", "Matrix", nullptr));
        exportButton->setText(QCoreApplication::translate("QGBA::ObjView", "Export", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QGBA::ObjView", "Attributes", nullptr));
        label_6->setText(QCoreApplication::translate("QGBA::ObjView", "Transform", nullptr));
        transform->setText(QCoreApplication::translate("QGBA::ObjView", "Off", nullptr));
        label_16->setText(QCoreApplication::translate("QGBA::ObjView", "Palette", nullptr));
        label_18->setText(QCoreApplication::translate("QGBA::ObjView", "Double Size", nullptr));
        doubleSize->setText(QString());
        label_5->setText(QCoreApplication::translate("QGBA::ObjView", "Flipped", nullptr));
        flippedH->setText(QCoreApplication::translate("QGBA::ObjView", "H", nullptr));
#if QT_CONFIG(shortcut)
        flippedH->setShortcut(QCoreApplication::translate("QGBA::ObjView", "Return, Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        flippedV->setText(QCoreApplication::translate("QGBA::ObjView", "V", nullptr));
#if QT_CONFIG(shortcut)
        flippedV->setShortcut(QCoreApplication::translate("QGBA::ObjView", "Return, Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        label_7->setText(QCoreApplication::translate("QGBA::ObjView", "Mode", nullptr));
        mode->setText(QCoreApplication::translate("QGBA::ObjView", "Normal", nullptr));
        label_15->setText(QCoreApplication::translate("QGBA::ObjView", "Mosaic", nullptr));
        mosaic->setText(QString());
#if QT_CONFIG(shortcut)
        mosaic->setShortcut(QCoreApplication::translate("QGBA::ObjView", "Return, Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        label_14->setText(QCoreApplication::translate("QGBA::ObjView", "Enabled", nullptr));
        enabled->setText(QString());
        label_17->setText(QCoreApplication::translate("QGBA::ObjView", "Priority", nullptr));
        tile->setTitle(QCoreApplication::translate("QGBA::ObjView", "Tile", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class ObjView: public Ui_ObjView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_OBJVIEW_H
