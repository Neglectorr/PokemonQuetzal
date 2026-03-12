/********************************************************************************
** Form generated from reading UI file 'BattleChipView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLECHIPVIEW_H
#define UI_BATTLECHIPVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace QGBA {

class Ui_BattleChipView
{
public:
    QVBoxLayout *verticalLayout;
    QListView *chipList;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout_4;
    QComboBox *chipName;
    QLabel *label_2;
    QPushButton *insert;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *save;
    QPushButton *load;
    QSpacerItem *horizontalSpacer;
    QPushButton *add;
    QPushButton *remove;
    QWidget *advanced;
    QHBoxLayout *horizontalLayout_4;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QRadioButton *gateBattleChip;
    QRadioButton *gateProgress;
    QRadioButton *gateBeastLink;
    QFrame *line;
    QFormLayout *formLayout_5;
    QCheckBox *inserted;
    QSpinBox *chipId;
    QLabel *label_4;
    QPushButton *updateData;
    QCheckBox *showAdvanced;
    QHBoxLayout *horizontalLayout_5;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QGBA__BattleChipView)
    {
        if (QGBA__BattleChipView->objectName().isEmpty())
            QGBA__BattleChipView->setObjectName(QString::fromUtf8("QGBA__BattleChipView"));
        QGBA__BattleChipView->resize(658, 722);
        verticalLayout = new QVBoxLayout(QGBA__BattleChipView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        chipList = new QListView(QGBA__BattleChipView);
        chipList->setObjectName(QString::fromUtf8("chipList"));
        chipList->setAcceptDrops(true);
        chipList->setDragEnabled(true);
        chipList->setDragDropMode(QAbstractItemView::InternalMove);
        chipList->setDefaultDropAction(Qt::MoveAction);
        chipList->setIconSize(QSize(56, 48));
        chipList->setMovement(QListView::Free);
        chipList->setProperty("isWrapping", QVariant(true));
        chipList->setResizeMode(QListView::Adjust);
        chipList->setGridSize(QSize(120, 72));
        chipList->setViewMode(QListView::IconMode);

        verticalLayout->addWidget(chipList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        chipName = new QComboBox(QGBA__BattleChipView);
        chipName->setObjectName(QString::fromUtf8("chipName"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, chipName);

        label_2 = new QLabel(QGBA__BattleChipView);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_2);


        horizontalLayout_2->addLayout(formLayout_4);

        insert = new QPushButton(QGBA__BattleChipView);
        insert->setObjectName(QString::fromUtf8("insert"));

        horizontalLayout_2->addWidget(insert);

        horizontalLayout_2->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        save = new QPushButton(QGBA__BattleChipView);
        save->setObjectName(QString::fromUtf8("save"));

        horizontalLayout_3->addWidget(save);

        load = new QPushButton(QGBA__BattleChipView);
        load->setObjectName(QString::fromUtf8("load"));

        horizontalLayout_3->addWidget(load);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        add = new QPushButton(QGBA__BattleChipView);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout_3->addWidget(add);

        remove = new QPushButton(QGBA__BattleChipView);
        remove->setObjectName(QString::fromUtf8("remove"));

        horizontalLayout_3->addWidget(remove);


        verticalLayout->addLayout(horizontalLayout_3);

        advanced = new QWidget(QGBA__BattleChipView);
        advanced->setObjectName(QString::fromUtf8("advanced"));
        advanced->setVisible(false);
        horizontalLayout_4 = new QHBoxLayout(advanced);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_3 = new QLabel(advanced);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        gateBattleChip = new QRadioButton(advanced);
        gateBattleChip->setObjectName(QString::fromUtf8("gateBattleChip"));
        gateBattleChip->setText(QString::fromUtf8("Ba&ttleChip Gate"));
        gateBattleChip->setChecked(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, gateBattleChip);

        gateProgress = new QRadioButton(advanced);
        gateProgress->setObjectName(QString::fromUtf8("gateProgress"));
        gateProgress->setText(QString::fromUtf8("Progress &Gate"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, gateProgress);

        gateBeastLink = new QRadioButton(advanced);
        gateBeastLink->setObjectName(QString::fromUtf8("gateBeastLink"));
        gateBeastLink->setText(QString::fromUtf8("Beast &Link Gate"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, gateBeastLink);


        horizontalLayout_4->addLayout(formLayout_2);

        line = new QFrame(advanced);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        inserted = new QCheckBox(advanced);
        inserted->setObjectName(QString::fromUtf8("inserted"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, inserted);

        chipId = new QSpinBox(advanced);
        chipId->setObjectName(QString::fromUtf8("chipId"));
        chipId->setMaximum(65535);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, chipId);

        label_4 = new QLabel(advanced);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_4);

        updateData = new QPushButton(advanced);
        updateData->setObjectName(QString::fromUtf8("updateData"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(updateData->sizePolicy().hasHeightForWidth());
        updateData->setSizePolicy(sizePolicy);

        formLayout_5->setWidget(2, QFormLayout::SpanningRole, updateData);


        horizontalLayout_4->addLayout(formLayout_5);


        verticalLayout->addWidget(advanced);

        showAdvanced = new QCheckBox(QGBA__BattleChipView);
        showAdvanced->setObjectName(QString::fromUtf8("showAdvanced"));

        verticalLayout->addWidget(showAdvanced);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        buttonBox = new QDialogButtonBox(QGBA__BattleChipView);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Reset);

        horizontalLayout_5->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalLayout->setStretch(0, 1);

        retranslateUi(QGBA__BattleChipView);
        QObject::connect(buttonBox, SIGNAL(rejected()), QGBA__BattleChipView, SLOT(reject()));
        QObject::connect(showAdvanced, SIGNAL(toggled(bool)), advanced, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(QGBA__BattleChipView);
    } // setupUi

    void retranslateUi(QDialog *QGBA__BattleChipView)
    {
        QGBA__BattleChipView->setWindowTitle(QCoreApplication::translate("QGBA::BattleChipView", "BattleChip Gate", nullptr));
        label_2->setText(QCoreApplication::translate("QGBA::BattleChipView", "Chip name", nullptr));
        insert->setText(QCoreApplication::translate("QGBA::BattleChipView", "Insert", nullptr));
        save->setText(QCoreApplication::translate("QGBA::BattleChipView", "Save", nullptr));
        load->setText(QCoreApplication::translate("QGBA::BattleChipView", "Load", nullptr));
        add->setText(QCoreApplication::translate("QGBA::BattleChipView", "Add", nullptr));
        remove->setText(QCoreApplication::translate("QGBA::BattleChipView", "Remove", nullptr));
        label_3->setText(QCoreApplication::translate("QGBA::BattleChipView", "Gate type", nullptr));
        inserted->setText(QCoreApplication::translate("QGBA::BattleChipView", "Inserted", nullptr));
        label_4->setText(QCoreApplication::translate("QGBA::BattleChipView", "Chip ID", nullptr));
        updateData->setText(QCoreApplication::translate("QGBA::BattleChipView", "Update Chip data", nullptr));
        showAdvanced->setText(QCoreApplication::translate("QGBA::BattleChipView", "Show advanced", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class BattleChipView: public Ui_BattleChipView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_BATTLECHIPVIEW_H
