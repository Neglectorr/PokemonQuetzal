/********************************************************************************
** Form generated from reading UI file 'DebuggerConsole.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGGERCONSOLE_H
#define UI_DEBUGGERCONSOLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "HistoryLineEdit.h"
#include "LogWidget.h"

namespace QGBA {

class Ui_DebuggerConsole
{
public:
    QGridLayout *gridLayout;
    QGBA::HistoryLineEdit *prompt;
    QPushButton *breakpoint;
    QGBA::LogWidget *log;

    void setupUi(QWidget *QGBA__DebuggerConsole)
    {
        if (QGBA__DebuggerConsole->objectName().isEmpty())
            QGBA__DebuggerConsole->setObjectName(QString::fromUtf8("QGBA__DebuggerConsole"));
        QGBA__DebuggerConsole->resize(480, 500);
        gridLayout = new QGridLayout(QGBA__DebuggerConsole);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        prompt = new QGBA::HistoryLineEdit(QGBA__DebuggerConsole);
        prompt->setObjectName(QString::fromUtf8("prompt"));

        gridLayout->addWidget(prompt, 1, 0, 1, 1);

        breakpoint = new QPushButton(QGBA__DebuggerConsole);
        breakpoint->setObjectName(QString::fromUtf8("breakpoint"));

        gridLayout->addWidget(breakpoint, 1, 1, 1, 1);

        log = new QGBA::LogWidget(QGBA__DebuggerConsole);
        log->setObjectName(QString::fromUtf8("log"));
        log->setReadOnly(true);

        gridLayout->addWidget(log, 0, 0, 1, 2);


        retranslateUi(QGBA__DebuggerConsole);

        QMetaObject::connectSlotsByName(QGBA__DebuggerConsole);
    } // setupUi

    void retranslateUi(QWidget *QGBA__DebuggerConsole)
    {
        QGBA__DebuggerConsole->setWindowTitle(QCoreApplication::translate("QGBA::DebuggerConsole", "Debugger", nullptr));
        prompt->setPlaceholderText(QCoreApplication::translate("QGBA::DebuggerConsole", "Enter command (try `help` for more info)", nullptr));
        breakpoint->setText(QCoreApplication::translate("QGBA::DebuggerConsole", "Break", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class DebuggerConsole: public Ui_DebuggerConsole {};
} // namespace Ui
} // namespace QGBA

#endif // UI_DEBUGGERCONSOLE_H
