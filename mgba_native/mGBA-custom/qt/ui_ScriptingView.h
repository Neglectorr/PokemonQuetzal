/********************************************************************************
** Form generated from reading UI file 'ScriptingView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTINGVIEW_H
#define UI_SCRIPTINGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "HistoryLineEdit.h"
#include "LogWidget.h"

namespace QGBA {

class Ui_ScriptingView
{
public:
    QAction *load;
    QAction *loadMostRecent;
    QAction *reset;
    QAction *action0;
    QAction *editAutorunScripts;
    QAction *clearConsoleAction;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QListView *buffers;
    QWidget *verticalLayoutWidget;
    QGridLayout *gridLayout_3;
    QSplitter *splitter_1;
    QPlainTextEdit *buffer;
    QGBA::LogWidget *log;
    HistoryLineEdit *prompt;
    QPushButton *runButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *mru;
    QMenu *menuView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QGBA__ScriptingView)
    {
        if (QGBA__ScriptingView->objectName().isEmpty())
            QGBA__ScriptingView->setObjectName(QString::fromUtf8("QGBA__ScriptingView"));
        QGBA__ScriptingView->resize(843, 637);
        load = new QAction(QGBA__ScriptingView);
        load->setObjectName(QString::fromUtf8("load"));
        loadMostRecent = new QAction(QGBA__ScriptingView);
        loadMostRecent->setObjectName(QString::fromUtf8("loadMostRecent"));
        reset = new QAction(QGBA__ScriptingView);
        reset->setObjectName(QString::fromUtf8("reset"));
        action0 = new QAction(QGBA__ScriptingView);
        action0->setObjectName(QString::fromUtf8("action0"));
        editAutorunScripts = new QAction(QGBA__ScriptingView);
        editAutorunScripts->setObjectName(QString::fromUtf8("editAutorunScripts"));
        clearConsoleAction = new QAction(QGBA__ScriptingView);
        clearConsoleAction->setObjectName(QString::fromUtf8("clearConsoleAction"));
        centralwidget = new QWidget(QGBA__ScriptingView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        buffers = new QListView(splitter);
        buffers->setObjectName(QString::fromUtf8("buffers"));
        buffers->setMinimumSize(QSize(90, 0));
        buffers->setMaximumSize(QSize(200, 16777215));
        splitter->addWidget(buffers);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        gridLayout_3 = new QGridLayout(verticalLayoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        splitter_1 = new QSplitter(verticalLayoutWidget);
        splitter_1->setObjectName(QString::fromUtf8("splitter_1"));
        splitter_1->setOrientation(Qt::Vertical);
        buffer = new QPlainTextEdit(splitter_1);
        buffer->setObjectName(QString::fromUtf8("buffer"));
        buffer->setLineWrapMode(QPlainTextEdit::NoWrap);
        buffer->setReadOnly(true);
        splitter_1->addWidget(buffer);
        log = new QGBA::LogWidget(splitter_1);
        log->setObjectName(QString::fromUtf8("log"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(log->sizePolicy().hasHeightForWidth());
        log->setSizePolicy(sizePolicy);
        log->setReadOnly(true);
        splitter_1->addWidget(log);

        gridLayout_3->addWidget(splitter_1, 0, 0, 1, 2);

        prompt = new HistoryLineEdit(verticalLayoutWidget);
        prompt->setObjectName(QString::fromUtf8("prompt"));

        gridLayout_3->addWidget(prompt, 1, 0, 1, 1);

        runButton = new QPushButton(verticalLayoutWidget);
        runButton->setObjectName(QString::fromUtf8("runButton"));

        gridLayout_3->addWidget(runButton, 1, 1, 1, 1);

        splitter->addWidget(verticalLayoutWidget);

        gridLayout->addWidget(splitter, 0, 0, 3, 1);

        QGBA__ScriptingView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QGBA__ScriptingView);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 29));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        mru = new QMenu(menuFile);
        mru->setObjectName(QString::fromUtf8("mru"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        QGBA__ScriptingView->setMenuBar(menubar);
        statusbar = new QStatusBar(QGBA__ScriptingView);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QGBA__ScriptingView->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menuFile->addAction(load);
        menuFile->addAction(mru->menuAction());
        menuFile->addAction(loadMostRecent);
        menuFile->addSeparator();
        menuFile->addAction(reset);
        menuFile->addAction(editAutorunScripts);
        menuView->addAction(clearConsoleAction);

        retranslateUi(QGBA__ScriptingView);
        QObject::connect(clearConsoleAction, SIGNAL(triggered()), log, SLOT(clear()));

        QMetaObject::connectSlotsByName(QGBA__ScriptingView);
    } // setupUi

    void retranslateUi(QMainWindow *QGBA__ScriptingView)
    {
        QGBA__ScriptingView->setWindowTitle(QCoreApplication::translate("QGBA::ScriptingView", "Scripting", nullptr));
        load->setText(QCoreApplication::translate("QGBA::ScriptingView", "Load script...", nullptr));
        loadMostRecent->setText(QCoreApplication::translate("QGBA::ScriptingView", "&Load most recent", nullptr));
        reset->setText(QCoreApplication::translate("QGBA::ScriptingView", "&Reset", nullptr));
        action0->setText(QCoreApplication::translate("QGBA::ScriptingView", "0", nullptr));
        editAutorunScripts->setText(QCoreApplication::translate("QGBA::ScriptingView", "Edit autorun scripts...", nullptr));
        clearConsoleAction->setText(QCoreApplication::translate("QGBA::ScriptingView", "Clear console", nullptr));
        runButton->setText(QCoreApplication::translate("QGBA::ScriptingView", "Run", nullptr));
        menuFile->setTitle(QCoreApplication::translate("QGBA::ScriptingView", "File", nullptr));
        mru->setTitle(QCoreApplication::translate("QGBA::ScriptingView", "Load recent script", nullptr));
        menuView->setTitle(QCoreApplication::translate("QGBA::ScriptingView", "View", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class ScriptingView: public Ui_ScriptingView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_SCRIPTINGVIEW_H
