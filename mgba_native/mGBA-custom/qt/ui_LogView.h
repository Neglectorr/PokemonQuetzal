/********************************************************************************
** Form generated from reading UI file 'LogView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGVIEW_H
#define UI_LOGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace QGBA {

class Ui_LogView
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *levelDebug;
    QCheckBox *levelStub;
    QCheckBox *levelInfo;
    QCheckBox *levelWarn;
    QCheckBox *levelError;
    QCheckBox *levelFatal;
    QFrame *line;
    QCheckBox *levelGameError;
    QPushButton *advanced;
    QSpacerItem *verticalSpacer_2;
    QPushButton *clear;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *maxLines;
    QPlainTextEdit *view;

    void setupUi(QWidget *QGBA__LogView)
    {
        if (QGBA__LogView->objectName().isEmpty())
            QGBA__LogView->setObjectName(QString::fromUtf8("QGBA__LogView"));
        QGBA__LogView->resize(600, 400);
        horizontalLayout = new QHBoxLayout(QGBA__LogView);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(QGBA__LogView);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        levelDebug = new QCheckBox(groupBox);
        levelDebug->setObjectName(QString::fromUtf8("levelDebug"));
        levelDebug->setChecked(false);

        verticalLayout->addWidget(levelDebug);

        levelStub = new QCheckBox(groupBox);
        levelStub->setObjectName(QString::fromUtf8("levelStub"));
        levelStub->setChecked(false);

        verticalLayout->addWidget(levelStub);

        levelInfo = new QCheckBox(groupBox);
        levelInfo->setObjectName(QString::fromUtf8("levelInfo"));
        levelInfo->setChecked(false);

        verticalLayout->addWidget(levelInfo);

        levelWarn = new QCheckBox(groupBox);
        levelWarn->setObjectName(QString::fromUtf8("levelWarn"));
        levelWarn->setChecked(true);

        verticalLayout->addWidget(levelWarn);

        levelError = new QCheckBox(groupBox);
        levelError->setObjectName(QString::fromUtf8("levelError"));
        levelError->setChecked(true);

        verticalLayout->addWidget(levelError);

        levelFatal = new QCheckBox(groupBox);
        levelFatal->setObjectName(QString::fromUtf8("levelFatal"));
        levelFatal->setChecked(true);

        verticalLayout->addWidget(levelFatal);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        levelGameError = new QCheckBox(groupBox);
        levelGameError->setObjectName(QString::fromUtf8("levelGameError"));
        levelGameError->setChecked(false);

        verticalLayout->addWidget(levelGameError);


        verticalLayout_2->addWidget(groupBox);

        advanced = new QPushButton(QGBA__LogView);
        advanced->setObjectName(QString::fromUtf8("advanced"));

        verticalLayout_2->addWidget(advanced);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        clear = new QPushButton(QGBA__LogView);
        clear->setObjectName(QString::fromUtf8("clear"));

        verticalLayout_2->addWidget(clear);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(QGBA__LogView);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        maxLines = new QSpinBox(QGBA__LogView);
        maxLines->setObjectName(QString::fromUtf8("maxLines"));
        maxLines->setMaximum(9999);

        horizontalLayout_3->addWidget(maxLines);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout_2);

        view = new QPlainTextEdit(QGBA__LogView);
        view->setObjectName(QString::fromUtf8("view"));
        view->setReadOnly(true);

        horizontalLayout->addWidget(view);


        retranslateUi(QGBA__LogView);

        QMetaObject::connectSlotsByName(QGBA__LogView);
    } // setupUi

    void retranslateUi(QWidget *QGBA__LogView)
    {
        QGBA__LogView->setWindowTitle(QCoreApplication::translate("QGBA::LogView", "Logs", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QGBA::LogView", "Enabled Levels", nullptr));
        levelDebug->setText(QCoreApplication::translate("QGBA::LogView", "Debug", nullptr));
        levelStub->setText(QCoreApplication::translate("QGBA::LogView", "Stub", nullptr));
        levelInfo->setText(QCoreApplication::translate("QGBA::LogView", "Info", nullptr));
        levelWarn->setText(QCoreApplication::translate("QGBA::LogView", "Warning", nullptr));
        levelError->setText(QCoreApplication::translate("QGBA::LogView", "Error", nullptr));
        levelFatal->setText(QCoreApplication::translate("QGBA::LogView", "Fatal", nullptr));
        levelGameError->setText(QCoreApplication::translate("QGBA::LogView", "Game Error", nullptr));
        advanced->setText(QCoreApplication::translate("QGBA::LogView", "Advanced settings", nullptr));
        clear->setText(QCoreApplication::translate("QGBA::LogView", "Clear", nullptr));
        label->setText(QCoreApplication::translate("QGBA::LogView", "Max Lines", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class LogView: public Ui_LogView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_LOGVIEW_H
