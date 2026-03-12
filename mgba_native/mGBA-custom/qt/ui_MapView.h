/********************************************************************************
** Form generated from reading UI file 'MapView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPVIEW_H
#define UI_MAPVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "AssetInfo.h"
#include "AssetTile.h"

namespace QGBA {

class Ui_MapView
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *bgLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *magnification;
    QLabel *label_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *map;
    QSpacerItem *verticalSpacer_2;
    QGBA::AssetTile *tile;
    QSpacerItem *verticalSpacer;
    QPushButton *exportButton;
    QGBA::AssetInfo *bgInfo;
    QVBoxLayout *verticalLayout_2;
    QPushButton *copyButton;

    void setupUi(QWidget *QGBA__MapView)
    {
        if (QGBA__MapView->objectName().isEmpty())
            QGBA__MapView->setObjectName(QString::fromUtf8("QGBA__MapView"));
        QGBA__MapView->resize(941, 617);
        gridLayout = new QGridLayout(QGBA__MapView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bgLayout = new QVBoxLayout();
        bgLayout->setObjectName(QString::fromUtf8("bgLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        magnification = new QSpinBox(QGBA__MapView);
        magnification->setObjectName(QString::fromUtf8("magnification"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(magnification->sizePolicy().hasHeightForWidth());
        magnification->setSizePolicy(sizePolicy);
        magnification->setSuffix(QString::fromUtf8("\303\227"));
        magnification->setMinimum(1);
        magnification->setMaximum(8);

        horizontalLayout_4->addWidget(magnification);

        label_2 = new QLabel(QGBA__MapView);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);


        bgLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(bgLayout, 1, 0, 1, 1);

        scrollArea = new QScrollArea(QGBA__MapView);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 613, 601));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        map = new QLabel(scrollAreaWidgetContents);
        map->setObjectName(QString::fromUtf8("map"));

        verticalLayout->addWidget(map);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 1, 1, 6, 2);

        tile = new QGBA::AssetTile(QGBA__MapView);
        tile->setObjectName(QString::fromUtf8("tile"));

        gridLayout->addWidget(tile, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        exportButton = new QPushButton(QGBA__MapView);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));

        gridLayout->addWidget(exportButton, 6, 0, 1, 1);

        bgInfo = new QGBA::AssetInfo(QGBA__MapView);
        bgInfo->setObjectName(QString::fromUtf8("bgInfo"));
        verticalLayout_2 = new QVBoxLayout(bgInfo);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        gridLayout->addWidget(bgInfo, 2, 0, 1, 1);

        copyButton = new QPushButton(QGBA__MapView);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));

        gridLayout->addWidget(copyButton, 5, 0, 1, 1);


        retranslateUi(QGBA__MapView);

        QMetaObject::connectSlotsByName(QGBA__MapView);
    } // setupUi

    void retranslateUi(QWidget *QGBA__MapView)
    {
        QGBA__MapView->setWindowTitle(QCoreApplication::translate("QGBA::MapView", "Maps", nullptr));
        label_2->setText(QCoreApplication::translate("QGBA::MapView", "Magnification", nullptr));
        map->setText(QString());
        exportButton->setText(QCoreApplication::translate("QGBA::MapView", "Export", nullptr));
        bgInfo->setTitle(QString());
        copyButton->setText(QCoreApplication::translate("QGBA::MapView", "Copy", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class MapView: public Ui_MapView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_MAPVIEW_H
