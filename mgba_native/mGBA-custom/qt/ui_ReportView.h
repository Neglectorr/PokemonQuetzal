/********************************************************************************
** Form generated from reading UI file 'ReportView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTVIEW_H
#define UI_REPORTVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

namespace QGBA {

class Ui_ReportView
{
public:
    QGridLayout *gridLayout;
    QListWidget *fileList;
    QPlainTextEdit *fileView;
    QLabel *description;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *generate;
    QPushButton *save;
    QPushButton *openList;
    QVBoxLayout *verticalLayout;
    QCheckBox *includeSave;
    QCheckBox *includeState;

    void setupUi(QDialog *QGBA__ReportView)
    {
        if (QGBA__ReportView->objectName().isEmpty())
            QGBA__ReportView->setObjectName(QString::fromUtf8("QGBA__ReportView"));
        QGBA__ReportView->resize(914, 533);
        gridLayout = new QGridLayout(QGBA__ReportView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        fileList = new QListWidget(QGBA__ReportView);
        fileList->setObjectName(QString::fromUtf8("fileList"));
        fileList->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fileList->sizePolicy().hasHeightForWidth());
        fileList->setSizePolicy(sizePolicy);
        fileList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        fileList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        fileList->setProperty("showDropIndicator", QVariant(false));
        fileList->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout->addWidget(fileList, 1, 1, 3, 1);

        fileView = new QPlainTextEdit(QGBA__ReportView);
        fileView->setObjectName(QString::fromUtf8("fileView"));
        fileView->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fileView->sizePolicy().hasHeightForWidth());
        fileView->setSizePolicy(sizePolicy1);
        fileView->setTextInteractionFlags(Qt::TextEditorInteraction);

        gridLayout->addWidget(fileView, 1, 2, 3, 1);

        description = new QLabel(QGBA__ReportView);
        description->setObjectName(QString::fromUtf8("description"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy2);
        description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        description->setWordWrap(true);
        description->setOpenExternalLinks(true);

        gridLayout->addWidget(description, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        generate = new QPushButton(QGBA__ReportView);
        generate->setObjectName(QString::fromUtf8("generate"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("view-refresh");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("../../../../../../"), QSize(), QIcon::Normal, QIcon::Off);
        }
        generate->setIcon(icon);

        horizontalLayout_2->addWidget(generate);

        save = new QPushButton(QGBA__ReportView);
        save->setObjectName(QString::fromUtf8("save"));
        save->setEnabled(false);
        QIcon icon1;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("../../../../../../"), QSize(), QIcon::Normal, QIcon::Off);
        }
        save->setIcon(icon1);

        horizontalLayout_2->addWidget(save);

        openList = new QPushButton(QGBA__ReportView);
        openList->setObjectName(QString::fromUtf8("openList"));
        openList->setEnabled(false);
        QIcon icon2;
        iconThemeName = QString::fromUtf8("document-send");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("../../../../../../"), QSize(), QIcon::Normal, QIcon::Off);
        }
        openList->setIcon(icon2);

        horizontalLayout_2->addWidget(openList);


        gridLayout->addLayout(horizontalLayout_2, 4, 1, 2, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        includeSave = new QCheckBox(QGBA__ReportView);
        includeSave->setObjectName(QString::fromUtf8("includeSave"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(includeSave->sizePolicy().hasHeightForWidth());
        includeSave->setSizePolicy(sizePolicy3);
        includeSave->setChecked(true);

        verticalLayout->addWidget(includeSave);

        includeState = new QCheckBox(QGBA__ReportView);
        includeState->setObjectName(QString::fromUtf8("includeState"));
        sizePolicy3.setHeightForWidth(includeState->sizePolicy().hasHeightForWidth());
        includeState->setSizePolicy(sizePolicy3);
        includeState->setChecked(true);

        verticalLayout->addWidget(includeState);


        gridLayout->addLayout(verticalLayout, 2, 0, 4, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 7);

        retranslateUi(QGBA__ReportView);
        QObject::connect(openList, SIGNAL(clicked()), QGBA__ReportView, SLOT(openBugReportPage()));
        QObject::connect(generate, SIGNAL(clicked()), QGBA__ReportView, SLOT(generateReport()));
        QObject::connect(save, SIGNAL(clicked()), QGBA__ReportView, SLOT(save()));

        QMetaObject::connectSlotsByName(QGBA__ReportView);
    } // setupUi

    void retranslateUi(QDialog *QGBA__ReportView)
    {
        QGBA__ReportView->setWindowTitle(QCoreApplication::translate("QGBA::ReportView", "Generate Bug Report", nullptr));
        description->setText(QCoreApplication::translate("QGBA::ReportView", "<html><head/><body><p>To file a bug report, please first generate a report file to attach to the bug report you're about to file. It is recommended that you include the save files, as these often help with debugging issues. This will collect some information about the version of {projectName} you're running, your configuration, your computer, and the game you currently have open (if any). Once this collection is completed you can review all of the information gathered below and save it to a zip file. The collection will automatically attempt to redact any personal information, such as your username if it's in any of the paths gathered, but just in case you can edit it afterwards. After you have generated and saved it, please click the button below or go to <a href=\"https://mgba.io/i/\"><span style=\" text-decoration: underline; color:#2980b9;\">mgba.io/i</span></a> to file the bug report on GitHub. Make sure to attach the report you generated!</p></body></html>", nullptr));
        generate->setText(QCoreApplication::translate("QGBA::ReportView", "Generate report", nullptr));
        save->setText(QCoreApplication::translate("QGBA::ReportView", "Save", nullptr));
        openList->setText(QCoreApplication::translate("QGBA::ReportView", "Open issue list in browser", nullptr));
        includeSave->setText(QCoreApplication::translate("QGBA::ReportView", "Include save file", nullptr));
        includeState->setText(QCoreApplication::translate("QGBA::ReportView", "Create and include savestate", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class ReportView: public Ui_ReportView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_REPORTVIEW_H
