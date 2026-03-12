/********************************************************************************
** Form generated from reading UI file 'VideoView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOVIEW_H
#define UI_VIDEOVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace QGBA {

class Ui_VideoView
{
public:
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QPushButton *start;
    QPushButton *stop;
    QPushButton *selectFile;
    QLineEdit *filename;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *presetHQ;
    QRadioButton *presetYoutube;
    QRadioButton *presetWebM;
    QRadioButton *presetMP4;
    QRadioButton *presetLossless;
    QFrame *line;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *preset4K;
    QRadioButton *preset1080;
    QRadioButton *preset720;
    QRadioButton *preset480;
    QRadioButton *presetNative;
    QWidget *advancedBox;
    QGridLayout *gridLayout_6;
    QGroupBox *formatBox;
    QVBoxLayout *verticalLayout_6;
    QComboBox *container;
    QComboBox *video;
    QComboBox *audio;
    QGroupBox *bitrateBox;
    QGridLayout *gridLayout_3;
    QRadioButton *doVbr;
    QSpinBox *abr;
    QRadioButton *doCrf;
    QLabel *label_2;
    QSpinBox *crf;
    QSpinBox *vbr;
    QLabel *label;
    QLabel *label_5;
    QGroupBox *dimensionsBox;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLabel *label_3;
    QSpinBox *height;
    QSpinBox *width;
    QSpinBox *hratio;
    QSpinBox *wratio;
    QCheckBox *lockRatio;
    QHBoxLayout *horizontalLayout;
    QCheckBox *showAdvanced;
    QDialogButtonBox *buttonBox;
    QButtonGroup *presets;
    QButtonGroup *resolutions;
    QButtonGroup *ratefactor;

    void setupUi(QWidget *QGBA__VideoView)
    {
        if (QGBA__VideoView->objectName().isEmpty())
            QGBA__VideoView->setObjectName(QString::fromUtf8("QGBA__VideoView"));
        QGBA__VideoView->resize(324, 593);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QGBA__VideoView->sizePolicy().hasHeightForWidth());
        QGBA__VideoView->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(QGBA__VideoView);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        start = new QPushButton(QGBA__VideoView);
        start->setObjectName(QString::fromUtf8("start"));
        start->setEnabled(false);
        sizePolicy.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy);

        gridLayout->addWidget(start, 1, 0, 1, 1);

        stop = new QPushButton(QGBA__VideoView);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setEnabled(false);
        sizePolicy.setHeightForWidth(stop->sizePolicy().hasHeightForWidth());
        stop->setSizePolicy(sizePolicy);

        gridLayout->addWidget(stop, 1, 1, 1, 1);

        selectFile = new QPushButton(QGBA__VideoView);
        selectFile->setObjectName(QString::fromUtf8("selectFile"));
        sizePolicy.setHeightForWidth(selectFile->sizePolicy().hasHeightForWidth());
        selectFile->setSizePolicy(sizePolicy);

        gridLayout->addWidget(selectFile, 1, 3, 1, 1);

        filename = new QLineEdit(QGBA__VideoView);
        filename->setObjectName(QString::fromUtf8("filename"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(filename->sizePolicy().hasHeightForWidth());
        filename->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(filename, 0, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        groupBox_2 = new QGroupBox(QGBA__VideoView);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        presetHQ = new QRadioButton(groupBox_2);
        presets = new QButtonGroup(QGBA__VideoView);
        presets->setObjectName(QString::fromUtf8("presets"));
        presets->addButton(presetHQ);
        presetHQ->setObjectName(QString::fromUtf8("presetHQ"));

        verticalLayout_2->addWidget(presetHQ);

        presetYoutube = new QRadioButton(groupBox_2);
        presets->addButton(presetYoutube);
        presetYoutube->setObjectName(QString::fromUtf8("presetYoutube"));

        verticalLayout_2->addWidget(presetYoutube);

        presetWebM = new QRadioButton(groupBox_2);
        presets->addButton(presetWebM);
        presetWebM->setObjectName(QString::fromUtf8("presetWebM"));

        verticalLayout_2->addWidget(presetWebM);

        presetMP4 = new QRadioButton(groupBox_2);
        presetMP4->setObjectName(QString::fromUtf8("presetMP4"));

        verticalLayout_2->addWidget(presetMP4);

        presetLossless = new QRadioButton(groupBox_2);
        presets->addButton(presetLossless);
        presetLossless->setObjectName(QString::fromUtf8("presetLossless"));

        verticalLayout_2->addWidget(presetLossless);


        horizontalLayout_2->addLayout(verticalLayout_2);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        preset4K = new QRadioButton(groupBox_2);
        preset4K->setObjectName(QString::fromUtf8("preset4K"));

        verticalLayout_3->addWidget(preset4K);

        preset1080 = new QRadioButton(groupBox_2);
        resolutions = new QButtonGroup(QGBA__VideoView);
        resolutions->setObjectName(QString::fromUtf8("resolutions"));
        resolutions->addButton(preset1080);
        preset1080->setObjectName(QString::fromUtf8("preset1080"));

        verticalLayout_3->addWidget(preset1080);

        preset720 = new QRadioButton(groupBox_2);
        resolutions->addButton(preset720);
        preset720->setObjectName(QString::fromUtf8("preset720"));

        verticalLayout_3->addWidget(preset720);

        preset480 = new QRadioButton(groupBox_2);
        resolutions->addButton(preset480);
        preset480->setObjectName(QString::fromUtf8("preset480"));

        verticalLayout_3->addWidget(preset480);

        presetNative = new QRadioButton(groupBox_2);
        resolutions->addButton(presetNative);
        presetNative->setObjectName(QString::fromUtf8("presetNative"));
        presetNative->setEnabled(false);
        presetNative->setChecked(true);

        verticalLayout_3->addWidget(presetNative);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_4->addWidget(groupBox_2);

        advancedBox = new QWidget(QGBA__VideoView);
        advancedBox->setObjectName(QString::fromUtf8("advancedBox"));
        gridLayout_6 = new QGridLayout(advancedBox);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        formatBox = new QGroupBox(advancedBox);
        formatBox->setObjectName(QString::fromUtf8("formatBox"));
        verticalLayout_6 = new QVBoxLayout(formatBox);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        container = new QComboBox(formatBox);
        container->addItem(QString::fromUtf8("MKV"));
        container->addItem(QString::fromUtf8("WebM"));
        container->addItem(QString::fromUtf8("AVI"));
        container->addItem(QString::fromUtf8("MP4"));
        container->setObjectName(QString::fromUtf8("container"));
        container->setEditable(true);

        verticalLayout_6->addWidget(container);

        video = new QComboBox(formatBox);
        video->addItem(QString::fromUtf8("H.264"));
        video->addItem(QString::fromUtf8("H.264 (NVENC)"));
        video->addItem(QString::fromUtf8("HEVC"));
        video->addItem(QString::fromUtf8("HEVC (NVENC)"));
        video->addItem(QString::fromUtf8("VP8"));
        video->addItem(QString::fromUtf8("VP9"));
        video->addItem(QString::fromUtf8("Ut Video"));
        video->addItem(QString::fromUtf8("FFV1"));
        video->addItem(QString::fromUtf8("None"));
        video->setObjectName(QString::fromUtf8("video"));
        video->setEditable(true);

        verticalLayout_6->addWidget(video);

        audio = new QComboBox(formatBox);
        audio->addItem(QString::fromUtf8("FLAC"));
        audio->addItem(QString::fromUtf8("WavPack"));
        audio->addItem(QString::fromUtf8("Opus"));
        audio->addItem(QString::fromUtf8("Vorbis"));
        audio->addItem(QString::fromUtf8("MP3"));
        audio->addItem(QString::fromUtf8("AAC"));
        audio->addItem(QString::fromUtf8("Uncompressed"));
        audio->addItem(QString::fromUtf8("None"));
        audio->setObjectName(QString::fromUtf8("audio"));
        audio->setEditable(true);

        verticalLayout_6->addWidget(audio);


        gridLayout_6->addWidget(formatBox, 0, 0, 1, 1);

        bitrateBox = new QGroupBox(advancedBox);
        bitrateBox->setObjectName(QString::fromUtf8("bitrateBox"));
        gridLayout_3 = new QGridLayout(bitrateBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        doVbr = new QRadioButton(bitrateBox);
        ratefactor = new QButtonGroup(QGBA__VideoView);
        ratefactor->setObjectName(QString::fromUtf8("ratefactor"));
        ratefactor->addButton(doVbr);
        doVbr->setObjectName(QString::fromUtf8("doVbr"));
        doVbr->setText(QString::fromUtf8(""));
        doVbr->setChecked(true);

        gridLayout_3->addWidget(doVbr, 1, 0, 1, 1);

        abr = new QSpinBox(bitrateBox);
        abr->setObjectName(QString::fromUtf8("abr"));
        abr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        abr->setMinimum(16);
        abr->setMaximum(320);
        abr->setValue(128);

        gridLayout_3->addWidget(abr, 3, 2, 1, 1);

        doCrf = new QRadioButton(bitrateBox);
        ratefactor->addButton(doCrf);
        doCrf->setObjectName(QString::fromUtf8("doCrf"));
        doCrf->setText(QString::fromUtf8(""));

        gridLayout_3->addWidget(doCrf, 0, 0, 1, 1);

        label_2 = new QLabel(bitrateBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_2, 3, 1, 1, 1);

        crf = new QSpinBox(bitrateBox);
        crf->setObjectName(QString::fromUtf8("crf"));
        crf->setEnabled(false);
        crf->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        crf->setMaximum(50);
        crf->setValue(18);

        gridLayout_3->addWidget(crf, 0, 2, 1, 1);

        vbr = new QSpinBox(bitrateBox);
        vbr->setObjectName(QString::fromUtf8("vbr"));
        vbr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        vbr->setMaximum(10000);

        gridLayout_3->addWidget(vbr, 1, 2, 1, 1);

        label = new QLabel(bitrateBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label, 1, 1, 1, 1);

        label_5 = new QLabel(bitrateBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_5, 0, 1, 1, 1);


        gridLayout_6->addWidget(bitrateBox, 0, 1, 1, 1);

        dimensionsBox = new QGroupBox(advancedBox);
        dimensionsBox->setObjectName(QString::fromUtf8("dimensionsBox"));
        gridLayout_4 = new QGridLayout(dimensionsBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_4 = new QLabel(dimensionsBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setText(QString::fromUtf8(":"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_4, 1, 2, 1, 1);

        label_3 = new QLabel(dimensionsBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setText(QString::fromUtf8("\303\227"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_3, 0, 2, 1, 1);

        height = new QSpinBox(dimensionsBox);
        height->setObjectName(QString::fromUtf8("height"));
        height->setMinimum(1);
        height->setMaximum(3160);

        gridLayout_4->addWidget(height, 0, 3, 1, 1);

        width = new QSpinBox(dimensionsBox);
        width->setObjectName(QString::fromUtf8("width"));
        width->setMinimum(1);
        width->setMaximum(3840);

        gridLayout_4->addWidget(width, 0, 1, 1, 1);

        hratio = new QSpinBox(dimensionsBox);
        hratio->setObjectName(QString::fromUtf8("hratio"));
        hratio->setMinimum(1);
        hratio->setMaximum(9999);

        gridLayout_4->addWidget(hratio, 1, 3, 1, 1);

        wratio = new QSpinBox(dimensionsBox);
        wratio->setObjectName(QString::fromUtf8("wratio"));
        wratio->setMinimum(1);
        wratio->setMaximum(9999);

        gridLayout_4->addWidget(wratio, 1, 1, 1, 1);

        lockRatio = new QCheckBox(dimensionsBox);
        lockRatio->setObjectName(QString::fromUtf8("lockRatio"));

        gridLayout_4->addWidget(lockRatio, 1, 4, 1, 1);


        gridLayout_6->addWidget(dimensionsBox, 1, 0, 1, 2);


        verticalLayout_4->addWidget(advancedBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        showAdvanced = new QCheckBox(QGBA__VideoView);
        showAdvanced->setObjectName(QString::fromUtf8("showAdvanced"));

        horizontalLayout->addWidget(showAdvanced);

        buttonBox = new QDialogButtonBox(QGBA__VideoView);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout_4->addLayout(horizontalLayout);

#if QT_CONFIG(shortcut)
        label_2->setBuddy(abr);
        label->setBuddy(vbr);
        label_5->setBuddy(crf);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(filename, start);
        QWidget::setTabOrder(start, stop);
        QWidget::setTabOrder(stop, selectFile);
        QWidget::setTabOrder(selectFile, presetHQ);
        QWidget::setTabOrder(presetHQ, presetYoutube);
        QWidget::setTabOrder(presetYoutube, presetWebM);
        QWidget::setTabOrder(presetWebM, presetMP4);
        QWidget::setTabOrder(presetMP4, presetLossless);
        QWidget::setTabOrder(presetLossless, preset4K);
        QWidget::setTabOrder(preset4K, preset1080);
        QWidget::setTabOrder(preset1080, preset720);
        QWidget::setTabOrder(preset720, preset480);
        QWidget::setTabOrder(preset480, presetNative);
        QWidget::setTabOrder(presetNative, showAdvanced);
        QWidget::setTabOrder(showAdvanced, container);
        QWidget::setTabOrder(container, video);
        QWidget::setTabOrder(video, audio);
        QWidget::setTabOrder(audio, doCrf);
        QWidget::setTabOrder(doCrf, doVbr);
        QWidget::setTabOrder(doVbr, crf);
        QWidget::setTabOrder(crf, vbr);
        QWidget::setTabOrder(vbr, abr);
        QWidget::setTabOrder(abr, width);
        QWidget::setTabOrder(width, height);
        QWidget::setTabOrder(height, wratio);
        QWidget::setTabOrder(wratio, hratio);
        QWidget::setTabOrder(hratio, lockRatio);

        retranslateUi(QGBA__VideoView);
        QObject::connect(doCrf, SIGNAL(toggled(bool)), crf, SLOT(setEnabled(bool)));
        QObject::connect(doVbr, SIGNAL(toggled(bool)), vbr, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(QGBA__VideoView);
    } // setupUi

    void retranslateUi(QWidget *QGBA__VideoView)
    {
        QGBA__VideoView->setWindowTitle(QCoreApplication::translate("QGBA::VideoView", "Record Video", nullptr));
        start->setText(QCoreApplication::translate("QGBA::VideoView", "Start", nullptr));
        stop->setText(QCoreApplication::translate("QGBA::VideoView", "Stop", nullptr));
        selectFile->setText(QCoreApplication::translate("QGBA::VideoView", "Select File", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QGBA::VideoView", "Presets", nullptr));
        presetHQ->setText(QCoreApplication::translate("QGBA::VideoView", "High &Quality", nullptr));
        presetYoutube->setText(QCoreApplication::translate("QGBA::VideoView", "&YouTube", nullptr));
        presetWebM->setText(QCoreApplication::translate("QGBA::VideoView", "WebM", nullptr));
        presetMP4->setText(QCoreApplication::translate("QGBA::VideoView", "MP4", nullptr));
        presetLossless->setText(QCoreApplication::translate("QGBA::VideoView", "&Lossless", nullptr));
        preset4K->setText(QCoreApplication::translate("QGBA::VideoView", "4K", nullptr));
        preset1080->setText(QCoreApplication::translate("QGBA::VideoView", "&1080p", nullptr));
        preset720->setText(QCoreApplication::translate("QGBA::VideoView", "&720p", nullptr));
        preset480->setText(QCoreApplication::translate("QGBA::VideoView", "&480p", nullptr));
        presetNative->setText(QCoreApplication::translate("QGBA::VideoView", "&Native", nullptr));
        formatBox->setTitle(QCoreApplication::translate("QGBA::VideoView", "Format", nullptr));



        bitrateBox->setTitle(QCoreApplication::translate("QGBA::VideoView", " Bitrate (kbps)", nullptr));
        label_2->setText(QCoreApplication::translate("QGBA::VideoView", "ABR", nullptr));
        crf->setSuffix(QString());
        vbr->setSuffix(QString());
        label->setText(QCoreApplication::translate("QGBA::VideoView", "VBR", nullptr));
        label_5->setText(QCoreApplication::translate("QGBA::VideoView", "CRF", nullptr));
        dimensionsBox->setTitle(QCoreApplication::translate("QGBA::VideoView", "Dimensions", nullptr));
        lockRatio->setText(QCoreApplication::translate("QGBA::VideoView", "Lock aspect ratio", nullptr));
        showAdvanced->setText(QCoreApplication::translate("QGBA::VideoView", "Show advanced", nullptr));
    } // retranslateUi

};

} // namespace QGBA

namespace QGBA {
namespace Ui {
    class VideoView: public Ui_VideoView {};
} // namespace Ui
} // namespace QGBA

#endif // UI_VIDEOVIEW_H
