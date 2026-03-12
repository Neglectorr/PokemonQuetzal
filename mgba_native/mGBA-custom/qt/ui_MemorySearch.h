/********************************************************************************
** Form generated from reading UI file 'MemorySearch.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORYSEARCH_H
#define UI_MEMORYSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

namespace QGBA {

class Ui_MemorySearch
{
public:
    QGridLayout *gridLayout;
    QTableWidget *results;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *value;
    QLabel *label_2;
    QRadioButton *typeNum;
    QRadioButton *typeStr;
    QFrame *line;
    QLabel *label_3;
    QRadioButton *bitsGuess;
    QRadioButton *bits8;
    QRadioButton *bits16;
    QRadioButton *bits32;
    QFrame *line_2;
    QLabel *label_4;
    QRadioButton *numGuess;
    QRadioButton *numDec;
    QRadioButton *numHex;
    QFrame *line_3;
    QLabel *label_5;
    QRadioButton *opEqual;
    QRadioButton *opGreater;
    QRadioButton *opLess;
    QRadioButton *opUnknown;
    QRadioButton *opDelta;
    QRadioButton *opDelta0;
    QRadioButton *opDeltaPositive;
    QRadioButton *opDeltaNegative;
    QCheckBox *searchROM;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *search;
    QPushButton *searchWithin;
    QPushButton *viewMem;
    QPushButton *refresh;
    QButtonGroup *type;
    QButtonGroup *op;
    QButtonGroup *width;

    void setupUi(QWidget *QGBA__MemorySearch)
    {
        if (QGBA__MemorySearch->objectName().isEmpty())
            QGBA__MemorySearch->setObjectName(QString::fromUtf8("QGBA__MemorySearch"));
        QGBA__MemorySearch->resize(725, 813);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QGBA__MemorySearch->sizePolicy().hasHeightForWidth());
        QGBA__MemorySearch->setSizePolicy(sizePolicy);
        QGBA__MemorySearch->setMinimumSize(QSize(540, 400));
        gridLayout = new QGridLayout(QGBA__MemorySearch);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        results = new QTableWidget(QGBA__MemorySearch);
        if (results->columnCount() < 3)
            results->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        results->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        results->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        results->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        results->setObjectName(QString::fromUtf8("results"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(results->sizePolicy().hasHeightForWidth());
        results->setSizePolicy(sizePolicy1);
        results->setEditTriggers(QAbstractItemView::NoEditTriggers);
        results->setSelectionBehavior(QAbstractItemView::SelectRows);
        results->setShowGrid(false);
        results->verticalHeader()->setVisible(false);

        gridLayout->addWidget(results, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(QGBA__MemorySearch);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        value = new QLineEdit(QGBA__MemorySearch);
        value->setObjectName(QString::fromUtf8("value"));

        formLayout->setWidget(0, QFormLayout::FieldRole, value);

        label_2 = new QLabel(QGBA__MemorySearch);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        typeNum = new QRadioButton(QGBA__MemorySearch);
        type = new QButtonGroup(QGBA__MemorySearch);
        type->setObjectName(QString::fromUtf8("type"));
        type->addButton(typeNum);
        typeNum->setObjectName(QString::fromUtf8("typeNum"));
        typeNum->setChecked(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, typeNum);

        typeStr = new QRadioButton(QGBA__MemorySearch);
        type->addButton(typeStr);
        typeStr->setObjectName(QString::fromUtf8("typeStr"));

        formLayout->setWidget(2, QFormLayout::FieldRole, typeStr);

        line = new QFrame(QGBA__MemorySearch);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(4, QFormLayout::SpanningRole, line);

        label_3 = new QLabel(QGBA__MemorySearch);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_3);

        bitsGuess = new QRadioButton(QGBA__MemorySearch);
        width = new QButtonGroup(QGBA__MemorySearch);
        width->setObjectName(QString::fromUtf8("width"));
        width->addButton(bitsGuess);
        bitsGuess->setObjectName(QString::fromUtf8("bitsGuess"));
        bitsGuess->setChecked(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, bitsGuess);

        bits8 = new QRadioButton(QGBA__MemorySearch);
        width->addButton(bits8);
        bits8->setObjectName(QString::fromUtf8("bits8"));

        formLayout->setWidget(6, QFormLayout::FieldRole, bits8);

        bits16 = new QRadioButton(QGBA__MemorySearch);
        width->addButton(bits16);
        bits16->setObjectName(QString::fromUtf8("bits16"));

        formLayout->setWidget(7, QFormLayout::FieldRole, bits16);

        bits32 = new QRadioButton(QGBA__MemorySearch);
        width->addButton(bits32);
        bits32->setObjectName(QString::fromUtf8("bits32"));
        bits32->setChecked(false);

        formLayout->setWidget(8, QFormLayout::FieldRole, bits32);

        line_2 = new QFrame(QGBA__MemorySearch);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(9, QFormLayout::SpanningRole, line_2);

        label_4 = new QLabel(QGBA__MemorySearch);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_4);

        numGuess = new QRadioButton(QGBA__MemorySearch);
        numGuess->setObjectName(QString::fromUtf8("numGuess"));
        numGuess->setChecked(true);

        formLayout->setWidget(10, QFormLayout::FieldRole, numGuess);

        numDec = new QRadioButton(QGBA__MemorySearch);
        numDec->setObjectName(QString::fromUtf8("numDec"));

        formLayout->setWidget(11, QFormLayout::FieldRole, numDec);

        numHex = new QRadioButton(QGBA__MemorySearch);
        numHex->setObjectName(QString::fromUtf8("numHex"));

        formLayout->setWidget(12, QFormLayout::FieldRole, numHex);

        line_3 = new QFrame(QGBA__MemorySearch);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(13, QFormLayout::SpanningRole, line_3);

        label_5 = new QLabel(QGBA__MemorySearch);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(14, QFormLayout::LabelRole, label_5);

        opEqual = new QRadioButton(QGBA__MemorySearch);
        op = new QButtonGroup(QGBA__MemorySearch);
        op->setObjectName(QString::fromUtf8("op"));
        op->addButton(opEqual);
        opEqual->setObjectName(QString::fromUtf8("opEqual"));
        opEqual->setChecked(true);

        formLayout->setWidget(14, QFormLayout::FieldRole, opEqual);

        opGreater = new QRadioButton(QGBA__MemorySearch);
        op->addButton(opGreater);
        opGreater->setObjectName(QString::fromUtf8("opGreater"));

        formLayout->setWidget(15, QFormLayout::FieldRole, opGreater);

        opLess = new QRadioButton(QGBA__MemorySearch);
        op->addButton(opLess);
        opLess->setObjectName(QString::fromUtf8("opLess"));

        formLayout->setWidget(16, QFormLayout::FieldRole, opLess);

        opUnknown = new QRadioButton(QGBA__MemorySearch);
        op->addButton(opUnknown);
        opUnknown->setObjectName(QString::fromUtf8("opUnknown"));

        formLayout->setWidget(17, QFormLayout::FieldRole, opUnknown);

        opDelta = new QRadioButton(QGBA__MemorySearch);
        op->addButton(opDelta);
        opDelta->setObjectName(QString::fromUtf8("opDelta"));
        opDelta->setEnabled(false);

        formLayout->setWidget(18, QFormLayout::FieldRole, opDelta);

        opDelta0 = new QRadioButton(QGBA__MemorySearch);
        op->addButton(opDelta0);
        opDelta0->setObjectName(QString::fromUtf8("opDelta0"));
        opDelta0->setEnabled(false);

        formLayout->setWidget(21, QFormLayout::FieldRole, opDelta0);

        opDeltaPositive = new QRadioButton(QGBA__MemorySearch);
        op->addButton(opDeltaPositive);
        opDeltaPositive->setObjectName(QString::fromUtf8("opDeltaPositive"));
        opDeltaPositive->setEnabled(false);

        formLayout->setWidget(19, QFormLayout::FieldRole, opDeltaPositive);

        opDeltaNegative = new QRadioButton(QGBA__MemorySearch);
        op->addButton(opDeltaNegative);
        opDeltaNegative->setObjectName(QString::fromUtf8("opDeltaNegative"));
        opDeltaNegative->setEnabled(false);

        formLayout->setWidget(20, QFormLayout::FieldRole, opDeltaNegative);

        searchROM = new QCheckBox(QGBA__MemorySearch);
        searchROM->setObjectName(QString::fromUtf8("searchROM"));

        formLayout->setWidget(3, QFormLayout::FieldRole, searchROM);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(QGBA__MemorySearch);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        search = new QPushButton(QGBA__MemorySearch);
        search->setObjectName(QString::fromUtf8("search"));

        horizontalLayout_2->addWidget(search);

        searchWithin = new QPushButton(QGBA__MemorySearch);
        searchWithin->setObjectName(QString::fromUtf8("searchWithin"));

        horizontalLayout_2->addWidget(searchWithin);

        viewMem = new QPushButton(QGBA__MemorySearch);
        viewMem->setObjectName(QString::fromUtf8("viewMem"));

        horizontalLayout_2->addWidget(viewMem);

        refresh = new QPushButton(QGBA__MemorySearch);
        refresh->setObjectName(QString::fromUtf8("refresh"));

        horizontalLayout_2->addWidget(refresh);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);


        retranslateUi(QGBA__MemorySearch);
        QObject::connect(buttonBox, SIGNAL(rejected()), QGBA__MemorySearch, SLOT(close()));
        QObject::connect(opDelta0, SIGNAL(toggled(bool)), value, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(QGBA__MemorySearch);
    } // setupUi

    void retranslateUi(QWidget *QGBA__MemorySearch)
    {
        QGBA__MemorySearch->setWindowTitle(QCoreApplication::translate("QGBA::MemorySearch", "Memory Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem = results->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("QGBA::MemorySearch", "Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = results->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("QGBA::MemorySearch", "Current Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = results->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("QGBA::MemorySearch", "Type", nullptr));
        label->setText(QCoreApplication::translate("QGBA::MemorySearch", "Value", nullptr));
        label_2->setText(QCoreApplication::translate("QGBA::MemorySearch", "Type", nullptr));
        typeNum->setText(QCoreApplication::translate("QGBA::MemorySearch", "Numeric", nullptr));
        typeStr->setText(QCoreApplication::translate("QGBA::MemorySearch", "Text", nullptr));
        label_3->setText(QCoreApplication::translate("QGBA::MemorySearch", "Width", nullptr));
        bitsGuess->setText(QCoreApplication::translate("QGBA::MemorySearch", "Guess", nullptr));
        bits8->setText(QCoreApplication::translate("QGBA::MemorySearch", "1 Byte (8-bit)", nullptr));
        bits16->setText(QCoreApplication::translate("QGBA::MemorySearch", "2 Bytes (16-bit)", nullptr));
        bits32->setText(QCoreApplication::translate("QGBA::MemorySearch", "4 Bytes (32-bit)", nullptr));
        label_4->setText(QCoreApplication::translate("QGBA::MemorySearch", "Number type", nullptr));
        numGuess->setText(QCoreApplication::translate("QGBA::MemorySearch", "Guess", nullptr));
        numDec->setText(QCoreApplication::translate("QGBA::MemorySearch", "Decimal", nullptr));
        numHex->setText(QCoreApplication::translate("QGBA::MemorySearch", "Hexadecimal", nullptr));
        label_5->setText(QCoreApplication::translate("QGBA::MemorySearch", "Search type", nullptr));
        opEqual->setText(QCoreApplication::translate("QGBA::MemorySearch", "Equal to value", nullptr));
        opGreater->setText(QCoreApplication::translate("QGBA::MemorySearch", "Greater than value", nullptr));
        opLess->setText(QCoreApplication::translate("QGBA::MemorySearch", "Less than value", nullptr));
        opUnknown->setText(QCoreApplication::translate("QGBA::MemorySearch", "Unknown/changed", nullptr));
        opDelta->setText(QCoreApplication::translate("QGBA::MemorySearch", "Changed by value", nullptr));
        opDelta0->setText(QCoreApplication::translate("QGBA::MemorySearch", "Unchanged", nullptr));
        opDeltaPositive->setText(QCoreApplication::translate("QGBA::MemorySearch", "Increased", nullptr));
        opDeltaNegative->setText(QCoreApplication::translate("QGBA::MemorySearch", "Decreased", nullptr));
        searchROM->setText(QCoreApplication::translate("QGBA::MemorySearch", "Search ROM", nullptr));
        search->setText(QCoreApplication::translate("QGBA::MemorySearch", "New Search", nullptr));
        searchWithin->setText(QCoreApplication::translate("QGBA::MemorySearch", "Search Within", nullptr));
        viewMem->setText(QCoreApplication::translate("QGBA::MemorySearch", "Open in Memory Viewer", nullptr));
        refresh->setText(QCoreApplication::translate("QGBA::MemorySearch", "Refresh", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class MemorySearch: public Ui_MemorySearch {};
} // namespace Ui
} // namespace QGBA

#endif // UI_MEMORYSEARCH_H
