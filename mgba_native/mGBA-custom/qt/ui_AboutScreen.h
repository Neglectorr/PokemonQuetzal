/********************************************************************************
** Form generated from reading UI file 'AboutScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTSCREEN_H
#define UI_ABOUTSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace QGBA {

class Ui_AboutScreen
{
public:
    QGridLayout *gridLayout_2;
    QLabel *extraLinks;
    QLabel *gitInfo;
    QLabel *projectName;
    QLabel *patronsHeader;
    QLabel *copyright;
    QLabel *projectVersion;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *logo;
    QSpacerItem *verticalSpacer_3;
    QLabel *description;
    QLabel *patrons;

    void setupUi(QWidget *QGBA__AboutScreen)
    {
        if (QGBA__AboutScreen->objectName().isEmpty())
            QGBA__AboutScreen->setObjectName(QString::fromUtf8("QGBA__AboutScreen"));
        QGBA__AboutScreen->resize(617, 341);
        gridLayout_2 = new QGridLayout(QGBA__AboutScreen);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        extraLinks = new QLabel(QGBA__AboutScreen);
        extraLinks->setObjectName(QString::fromUtf8("extraLinks"));
        extraLinks->setAlignment(Qt::AlignCenter);
        extraLinks->setOpenExternalLinks(true);

        gridLayout_2->addWidget(extraLinks, 4, 1, 1, 1);

        gitInfo = new QLabel(QGBA__AboutScreen);
        gitInfo->setObjectName(QString::fromUtf8("gitInfo"));
        QFont font;
        font.setPointSize(10);
        gitInfo->setFont(font);
        gitInfo->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(gitInfo, 2, 1, 1, 1);

        projectName = new QLabel(QGBA__AboutScreen);
        projectName->setObjectName(QString::fromUtf8("projectName"));
        QFont font1;
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        projectName->setFont(font1);
        projectName->setText(QString::fromUtf8("{projectName}"));
        projectName->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_2->addWidget(projectName, 0, 1, 1, 1);

        patronsHeader = new QLabel(QGBA__AboutScreen);
        patronsHeader->setObjectName(QString::fromUtf8("patronsHeader"));
        patronsHeader->setAlignment(Qt::AlignCenter);
        patronsHeader->setWordWrap(true);

        gridLayout_2->addWidget(patronsHeader, 6, 0, 1, 2);

        copyright = new QLabel(QGBA__AboutScreen);
        copyright->setObjectName(QString::fromUtf8("copyright"));
        copyright->setFont(font);
        copyright->setAlignment(Qt::AlignCenter);
        copyright->setWordWrap(true);

        gridLayout_2->addWidget(copyright, 8, 0, 1, 4);

        projectVersion = new QLabel(QGBA__AboutScreen);
        projectVersion->setObjectName(QString::fromUtf8("projectVersion"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        projectVersion->setFont(font2);
        projectVersion->setText(QString::fromUtf8("{projectVersion}"));
        projectVersion->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        projectVersion->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(projectVersion, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(8, -1, 16, 12);
        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        logo = new QLabel(QGBA__AboutScreen);
        logo->setObjectName(QString::fromUtf8("logo"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy);
        logo->setMinimumSize(QSize(256, 192));
        logo->setText(QString::fromUtf8("{logo}"));

        verticalLayout->addWidget(logo);

        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 6, 1);

        description = new QLabel(QGBA__AboutScreen);
        description->setObjectName(QString::fromUtf8("description"));
        description->setAlignment(Qt::AlignCenter);
        description->setWordWrap(true);

        gridLayout_2->addWidget(description, 3, 1, 1, 1);

        patrons = new QLabel(QGBA__AboutScreen);
        patrons->setObjectName(QString::fromUtf8("patrons"));
        patrons->setText(QString::fromUtf8("{patrons}"));
        patrons->setAlignment(Qt::AlignCenter);
        patrons->setWordWrap(true);

        gridLayout_2->addWidget(patrons, 7, 0, 1, 2);


        retranslateUi(QGBA__AboutScreen);

        QMetaObject::connectSlotsByName(QGBA__AboutScreen);
    } // setupUi

    void retranslateUi(QWidget *QGBA__AboutScreen)
    {
        QGBA__AboutScreen->setWindowTitle(QCoreApplication::translate("QGBA::AboutScreen", "About", nullptr));
        extraLinks->setText(QCoreApplication::translate("QGBA::AboutScreen", "<a href=\"http://mgba.io/\">Website</a> \342\200\242 <a href=\"https://forums.mgba.io/\">Forums / Support</a> \342\200\242 <a href=\"https://patreon.com/mgba\">Donate</a> \342\200\242 <a href=\"https://github.com/mgba-emu/mgba/tree/{gitBranch}\">Source</a>", nullptr));
        gitInfo->setText(QCoreApplication::translate("QGBA::AboutScreen", "Branch: <tt>{gitBranch}</tt><br/>Revision: <tt>{gitCommit}</tt>", nullptr));
        patronsHeader->setText(QCoreApplication::translate("QGBA::AboutScreen", "{projectName} would like to thank the following patrons from Patreon:", nullptr));
        copyright->setText(QCoreApplication::translate("QGBA::AboutScreen", "\302\251 2013 \342\200\223 {year} Jeffrey Pfau, licensed under the Mozilla Public License, version 2.0\n"
"Game Boy Advance is a registered trademark of Nintendo Co., Ltd.", nullptr));
        description->setText(QCoreApplication::translate("QGBA::AboutScreen", "{projectName} is an open-source Game Boy Advance emulator", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class AboutScreen: public Ui_AboutScreen {};
} // namespace Ui
} // namespace QGBA

#endif // UI_ABOUTSCREEN_H
