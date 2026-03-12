/********************************************************************************
** Form generated from reading UI file 'TileView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILEVIEW_H
#define UI_TILEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "AssetTile.h"
#include "TilePainter.h"

namespace QGBA {

class Ui_TileView
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QSpinBox *paletteId;
    QLabel *label_3;
    QCheckBox *palette256;
    QFrame *line;
    QSpinBox *magnification;
    QLabel *label_2;
    QSpinBox *tilesPerRow;
    QLabel *label;
    QCheckBox *tileFit;
    QGBA::AssetTile *tile;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *tilesBg;
    QRadioButton *tilesObj;
    QRadioButton *tilesBoth;
    QGridLayout *gridLayout_2;
    QPushButton *copyOne;
    QPushButton *exportOne;
    QPushButton *copyAll;
    QPushButton *exportAll;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QGBA::TilePainter *tiles;
    QButtonGroup *tilesSelector;

    void setupUi(QWidget *QGBA__TileView)
    {
        if (QGBA__TileView->objectName().isEmpty())
            QGBA__TileView->setObjectName(QString::fromUtf8("QGBA__TileView"));
        QGBA__TileView->resize(680, 450);
        gridLayout = new QGridLayout(QGBA__TileView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(QGBA__TileView);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        paletteId = new QSpinBox(groupBox_2);
        paletteId->setObjectName(QString::fromUtf8("paletteId"));
        paletteId->setMaximum(15);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, paletteId);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_3);

        palette256 = new QCheckBox(groupBox_2);
        palette256->setObjectName(QString::fromUtf8("palette256"));

        formLayout_2->setWidget(1, QFormLayout::SpanningRole, palette256);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout_2->setWidget(2, QFormLayout::SpanningRole, line);

        magnification = new QSpinBox(groupBox_2);
        magnification->setObjectName(QString::fromUtf8("magnification"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(magnification->sizePolicy().hasHeightForWidth());
        magnification->setSizePolicy(sizePolicy);
        magnification->setSuffix(QString::fromUtf8("\303\227"));
        magnification->setMinimum(1);
        magnification->setMaximum(8);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, magnification);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, label_2);

        tilesPerRow = new QSpinBox(groupBox_2);
        tilesPerRow->setObjectName(QString::fromUtf8("tilesPerRow"));
        tilesPerRow->setEnabled(false);
        tilesPerRow->setMinimum(1);
        tilesPerRow->setMaximum(64);
        tilesPerRow->setValue(32);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, tilesPerRow);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, label);

        tileFit = new QCheckBox(groupBox_2);
        tileFit->setObjectName(QString::fromUtf8("tileFit"));
        tileFit->setChecked(true);

        formLayout_2->setWidget(5, QFormLayout::SpanningRole, tileFit);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        tile = new QGBA::AssetTile(QGBA__TileView);
        tile->setObjectName(QString::fromUtf8("tile"));

        gridLayout->addWidget(tile, 0, 1, 2, 1);

        groupBox = new QGroupBox(QGBA__TileView);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tilesBg = new QRadioButton(groupBox);
        tilesSelector = new QButtonGroup(QGBA__TileView);
        tilesSelector->setObjectName(QString::fromUtf8("tilesSelector"));
        tilesSelector->addButton(tilesBg);
        tilesBg->setObjectName(QString::fromUtf8("tilesBg"));

        verticalLayout_2->addWidget(tilesBg);

        tilesObj = new QRadioButton(groupBox);
        tilesSelector->addButton(tilesObj);
        tilesObj->setObjectName(QString::fromUtf8("tilesObj"));

        verticalLayout_2->addWidget(tilesObj);

        tilesBoth = new QRadioButton(groupBox);
        tilesSelector->addButton(tilesBoth);
        tilesBoth->setObjectName(QString::fromUtf8("tilesBoth"));
        tilesBoth->setChecked(true);

        verticalLayout_2->addWidget(tilesBoth);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        copyOne = new QPushButton(QGBA__TileView);
        copyOne->setObjectName(QString::fromUtf8("copyOne"));

        gridLayout_2->addWidget(copyOne, 0, 0, 1, 1);

        exportOne = new QPushButton(QGBA__TileView);
        exportOne->setObjectName(QString::fromUtf8("exportOne"));

        gridLayout_2->addWidget(exportOne, 1, 0, 1, 1);

        copyAll = new QPushButton(QGBA__TileView);
        copyAll->setObjectName(QString::fromUtf8("copyAll"));

        gridLayout_2->addWidget(copyAll, 0, 1, 1, 1);

        exportAll = new QPushButton(QGBA__TileView);
        exportAll->setObjectName(QString::fromUtf8("exportAll"));

        gridLayout_2->addWidget(exportAll, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 3, 0, 1, 2);

        scrollArea = new QScrollArea(QGBA__TileView);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 441, 768));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tiles = new QGBA::TilePainter(scrollAreaWidgetContents);
        tiles->setObjectName(QString::fromUtf8("tiles"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tiles->sizePolicy().hasHeightForWidth());
        tiles->setSizePolicy(sizePolicy3);
        tiles->setMinimumSize(QSize(256, 768));

        verticalLayout->addWidget(tiles);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 2, 4, 1);

        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(2, 1);
        QWidget::setTabOrder(paletteId, palette256);
        QWidget::setTabOrder(palette256, magnification);
        QWidget::setTabOrder(magnification, tilesPerRow);
        QWidget::setTabOrder(tilesPerRow, tileFit);
        QWidget::setTabOrder(tileFit, tilesBg);
        QWidget::setTabOrder(tilesBg, tilesObj);
        QWidget::setTabOrder(tilesObj, tilesBoth);
        QWidget::setTabOrder(tilesBoth, copyOne);
        QWidget::setTabOrder(copyOne, copyAll);
        QWidget::setTabOrder(copyAll, exportOne);
        QWidget::setTabOrder(exportOne, exportAll);
        QWidget::setTabOrder(exportAll, scrollArea);

        retranslateUi(QGBA__TileView);
        QObject::connect(tileFit, SIGNAL(toggled(bool)), tilesPerRow, SLOT(setDisabled(bool)));
        QObject::connect(magnification, SIGNAL(valueChanged(int)), tiles, SLOT(setTileMagnification(int)));
        QObject::connect(palette256, SIGNAL(toggled(bool)), paletteId, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(QGBA__TileView);
    } // setupUi

    void retranslateUi(QWidget *QGBA__TileView)
    {
        QGBA__TileView->setWindowTitle(QCoreApplication::translate("QGBA::TileView", "Tiles", nullptr));
        groupBox_2->setTitle(QString());
        label_3->setText(QCoreApplication::translate("QGBA::TileView", "Palette", nullptr));
        palette256->setText(QCoreApplication::translate("QGBA::TileView", "256 colors", nullptr));
        label_2->setText(QCoreApplication::translate("QGBA::TileView", "Magnification", nullptr));
        label->setText(QCoreApplication::translate("QGBA::TileView", "Tiles per row", nullptr));
        tileFit->setText(QCoreApplication::translate("QGBA::TileView", "Fit to window", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QGBA::TileView", "Displayed tiles", nullptr));
        tilesBg->setText(QCoreApplication::translate("QGBA::TileView", "Only BG tiles", nullptr));
        tilesObj->setText(QCoreApplication::translate("QGBA::TileView", "Only OBJ tiles", nullptr));
        tilesBoth->setText(QCoreApplication::translate("QGBA::TileView", "Both", nullptr));
        copyOne->setText(QCoreApplication::translate("QGBA::TileView", "Copy Selected", nullptr));
        exportOne->setText(QCoreApplication::translate("QGBA::TileView", "Export Selected", nullptr));
        copyAll->setText(QCoreApplication::translate("QGBA::TileView", "Copy All", nullptr));
        exportAll->setText(QCoreApplication::translate("QGBA::TileView", "Export All", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class TileView: public Ui_TileView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_TILEVIEW_H
