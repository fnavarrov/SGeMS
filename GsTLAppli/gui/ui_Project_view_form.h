/********************************************************************************
** Form generated from reading ui file 'Project_view_form.ui'
**
** Created: Sun Nov 1 20:46:27 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PROJECT_VIEW_FORM_H
#define UI_PROJECT_VIEW_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Project_view_form
{
public:
    QVBoxLayout *vboxLayout;
    QSplitter *splitter;
    QTabWidget *ControlPanel;
    QWidget *objects_page;
    QHBoxLayout *hboxLayout;
    QWidget *pref_page;
    QVBoxLayout *vboxLayout1;
    QGroupBox *_pref_group_sel;
    QHBoxLayout *hboxLayout1;
    QGroupBox *_pref_group;
    QWidget *TabPage;
    QVBoxLayout *vboxLayout2;
    QGroupBox *InfoGroupBox;
    QGroupBox *_info_group;
    QWidget *layoutWidget;
    QVBoxLayout *vboxLayout3;
    QFrame *ViewerFrame;
    QVBoxLayout *vboxLayout4;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem1;
    QPushButton *view_all_button_;
    QPushButton *face_view_button_;
    QPushButton *side_view_button_;
    QPushButton *top_view_button_;
    QPushButton *home_view_button_;
    QPushButton *set_home_view_button_;
    QPushButton *snapshot_button_;
    QSpacerItem *spacerItem2;

    void setupUi(QWidget *Project_view_form)
    {
        if (Project_view_form->objectName().isEmpty())
            Project_view_form->setObjectName(QString::fromUtf8("Project_view_form"));
        Project_view_form->resize(735, 708);
        vboxLayout = new QVBoxLayout(Project_view_form);
        vboxLayout->setSpacing(6);
        vboxLayout->setMargin(0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        splitter = new QSplitter(Project_view_form);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(3);
        ControlPanel = new QTabWidget(splitter);
        ControlPanel->setObjectName(QString::fromUtf8("ControlPanel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ControlPanel->sizePolicy().hasHeightForWidth());
        ControlPanel->setSizePolicy(sizePolicy);
        ControlPanel->setTabShape(QTabWidget::Rounded);
        objects_page = new QWidget();
        objects_page->setObjectName(QString::fromUtf8("objects_page"));
        hboxLayout = new QHBoxLayout(objects_page);
        hboxLayout->setSpacing(6);
        hboxLayout->setMargin(7);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        ControlPanel->addTab(objects_page, QString());
        pref_page = new QWidget();
        pref_page->setObjectName(QString::fromUtf8("pref_page"));
        vboxLayout1 = new QVBoxLayout(pref_page);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setMargin(9);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        _pref_group_sel = new QGroupBox(pref_page);
        _pref_group_sel->setObjectName(QString::fromUtf8("_pref_group_sel"));
        _pref_group_sel->setMaximumSize(QSize(32767, 60));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        _pref_group_sel->setFont(font);
        _pref_group_sel->setAlignment(Qt::AlignHCenter);
        hboxLayout1 = new QHBoxLayout(_pref_group_sel);
        hboxLayout1->setSpacing(6);
        hboxLayout1->setMargin(9);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));

        vboxLayout1->addWidget(_pref_group_sel);

        _pref_group = new QGroupBox(pref_page);
        _pref_group->setObjectName(QString::fromUtf8("_pref_group"));
        _pref_group->setFlat(false);

        vboxLayout1->addWidget(_pref_group);

        ControlPanel->addTab(pref_page, QString());
        TabPage = new QWidget();
        TabPage->setObjectName(QString::fromUtf8("TabPage"));
        vboxLayout2 = new QVBoxLayout(TabPage);
        vboxLayout2->setSpacing(6);
        vboxLayout2->setMargin(9);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        InfoGroupBox = new QGroupBox(TabPage);
        InfoGroupBox->setObjectName(QString::fromUtf8("InfoGroupBox"));
        InfoGroupBox->setMaximumSize(QSize(32767, 60));
        InfoGroupBox->setFont(font);
        InfoGroupBox->setAlignment(Qt::AlignHCenter);

        vboxLayout2->addWidget(InfoGroupBox);

        _info_group = new QGroupBox(TabPage);
        _info_group->setObjectName(QString::fromUtf8("_info_group"));
        _info_group->setAutoFillBackground(false);
        _info_group->setFlat(false);

        vboxLayout2->addWidget(_info_group);

        ControlPanel->addTab(TabPage, QString());
        splitter->addWidget(ControlPanel);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        vboxLayout3 = new QVBoxLayout(layoutWidget);
        vboxLayout3->setSpacing(4);
        vboxLayout3->setMargin(11);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
        ViewerFrame = new QFrame(layoutWidget);
        ViewerFrame->setObjectName(QString::fromUtf8("ViewerFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(70);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ViewerFrame->sizePolicy().hasHeightForWidth());
        ViewerFrame->setSizePolicy(sizePolicy1);
        ViewerFrame->setMinimumSize(QSize(100, 100));
        ViewerFrame->setFrameShape(QFrame::Box);
        ViewerFrame->setFrameShadow(QFrame::Plain);
        ViewerFrame->setMidLineWidth(2);
        vboxLayout4 = new QVBoxLayout(ViewerFrame);
        vboxLayout4->setSpacing(6);
        vboxLayout4->setMargin(11);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout4->addItem(spacerItem);


        vboxLayout3->addWidget(ViewerFrame);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setMargin(0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        spacerItem1 = new QSpacerItem(16, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem1);

        view_all_button_ = new QPushButton(layoutWidget);
        view_all_button_->setObjectName(QString::fromUtf8("view_all_button_"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(view_all_button_->sizePolicy().hasHeightForWidth());
        view_all_button_->setSizePolicy(sizePolicy2);
        view_all_button_->setMaximumSize(QSize(31, 31));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/icons/appli/Pixmaps/global.png")), QIcon::Normal, QIcon::Off);
        view_all_button_->setIcon(icon);
        view_all_button_->setIconSize(QSize(25, 25));
        view_all_button_->setFlat(true);

        hboxLayout2->addWidget(view_all_button_);

        face_view_button_ = new QPushButton(layoutWidget);
        face_view_button_->setObjectName(QString::fromUtf8("face_view_button_"));
        sizePolicy2.setHeightForWidth(face_view_button_->sizePolicy().hasHeightForWidth());
        face_view_button_->setSizePolicy(sizePolicy2);
        face_view_button_->setMaximumSize(QSize(31, 31));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/icons/appli/Pixmaps/xy.png")), QIcon::Normal, QIcon::Off);
        face_view_button_->setIcon(icon1);
        face_view_button_->setIconSize(QSize(25, 25));
        face_view_button_->setFlat(true);

        hboxLayout2->addWidget(face_view_button_);

        side_view_button_ = new QPushButton(layoutWidget);
        side_view_button_->setObjectName(QString::fromUtf8("side_view_button_"));
        sizePolicy2.setHeightForWidth(side_view_button_->sizePolicy().hasHeightForWidth());
        side_view_button_->setSizePolicy(sizePolicy2);
        side_view_button_->setMaximumSize(QSize(31, 31));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/icons/appli/Pixmaps/yz.png")), QIcon::Normal, QIcon::Off);
        side_view_button_->setIcon(icon2);
        side_view_button_->setIconSize(QSize(25, 25));
        side_view_button_->setFlat(true);

        hboxLayout2->addWidget(side_view_button_);

        top_view_button_ = new QPushButton(layoutWidget);
        top_view_button_->setObjectName(QString::fromUtf8("top_view_button_"));
        sizePolicy2.setHeightForWidth(top_view_button_->sizePolicy().hasHeightForWidth());
        top_view_button_->setSizePolicy(sizePolicy2);
        top_view_button_->setMaximumSize(QSize(31, 31));
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/icons/appli/Pixmaps/xz.png")), QIcon::Normal, QIcon::Off);
        top_view_button_->setIcon(icon3);
        top_view_button_->setIconSize(QSize(25, 25));
        top_view_button_->setFlat(true);

        hboxLayout2->addWidget(top_view_button_);

        home_view_button_ = new QPushButton(layoutWidget);
        home_view_button_->setObjectName(QString::fromUtf8("home_view_button_"));
        sizePolicy2.setHeightForWidth(home_view_button_->sizePolicy().hasHeightForWidth());
        home_view_button_->setSizePolicy(sizePolicy2);
        home_view_button_->setMaximumSize(QSize(31, 31));
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8(":/icons/appli/Pixmaps/home.png")), QIcon::Normal, QIcon::Off);
        home_view_button_->setIcon(icon4);
        home_view_button_->setIconSize(QSize(25, 25));
        home_view_button_->setFlat(true);

        hboxLayout2->addWidget(home_view_button_);

        set_home_view_button_ = new QPushButton(layoutWidget);
        set_home_view_button_->setObjectName(QString::fromUtf8("set_home_view_button_"));
        sizePolicy2.setHeightForWidth(set_home_view_button_->sizePolicy().hasHeightForWidth());
        set_home_view_button_->setSizePolicy(sizePolicy2);
        set_home_view_button_->setMaximumSize(QSize(31, 31));
        QIcon icon5;
        icon5.addPixmap(QPixmap(QString::fromUtf8(":/icons/appli/Pixmaps/sethome.png")), QIcon::Normal, QIcon::Off);
        set_home_view_button_->setIcon(icon5);
        set_home_view_button_->setIconSize(QSize(25, 25));
        set_home_view_button_->setFlat(true);

        hboxLayout2->addWidget(set_home_view_button_);

        snapshot_button_ = new QPushButton(layoutWidget);
        snapshot_button_->setObjectName(QString::fromUtf8("snapshot_button_"));
        sizePolicy2.setHeightForWidth(snapshot_button_->sizePolicy().hasHeightForWidth());
        snapshot_button_->setSizePolicy(sizePolicy2);
        snapshot_button_->setMaximumSize(QSize(31, 31));
        QIcon icon6;
        icon6.addPixmap(QPixmap(QString::fromUtf8(":/icons/appli/Pixmaps/camera.png")), QIcon::Normal, QIcon::Off);
        snapshot_button_->setIcon(icon6);
        snapshot_button_->setIconSize(QSize(25, 25));
        snapshot_button_->setFlat(true);

        hboxLayout2->addWidget(snapshot_button_);

        spacerItem2 = new QSpacerItem(190, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem2);


        vboxLayout3->addLayout(hboxLayout2);

        splitter->addWidget(layoutWidget);

        vboxLayout->addWidget(splitter);


        retranslateUi(Project_view_form);

        ControlPanel->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Project_view_form);
    } // setupUi

    void retranslateUi(QWidget *Project_view_form)
    {
        Project_view_form->setWindowTitle(QApplication::translate("Project_view_form", "View", 0, QApplication::UnicodeUTF8));
        ControlPanel->setTabText(ControlPanel->indexOf(objects_page), QApplication::translate("Project_view_form", "Objects", 0, QApplication::UnicodeUTF8));
        _pref_group_sel->setTitle(QApplication::translate("Project_view_form", "Preferences for:", 0, QApplication::UnicodeUTF8));
        _pref_group->setTitle(QString());
        ControlPanel->setTabText(ControlPanel->indexOf(pref_page), QApplication::translate("Project_view_form", "Preferences", 0, QApplication::UnicodeUTF8));
        InfoGroupBox->setTitle(QApplication::translate("Project_view_form", "Information on:", 0, QApplication::UnicodeUTF8));
        _info_group->setTitle(QString());
        ControlPanel->setTabText(ControlPanel->indexOf(TabPage), QApplication::translate("Project_view_form", "Info", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        view_all_button_->setToolTip(QApplication::translate("Project_view_form", "View All", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        view_all_button_->setText(QString());
#ifndef QT_NO_TOOLTIP
        face_view_button_->setToolTip(QApplication::translate("Project_view_form", "Face View", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        face_view_button_->setText(QString());
#ifndef QT_NO_TOOLTIP
        side_view_button_->setToolTip(QApplication::translate("Project_view_form", "Side View", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        side_view_button_->setText(QString());
#ifndef QT_NO_TOOLTIP
        top_view_button_->setToolTip(QApplication::translate("Project_view_form", "Top View", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        top_view_button_->setText(QString());
#ifndef QT_NO_TOOLTIP
        home_view_button_->setToolTip(QApplication::translate("Project_view_form", "Home View", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        home_view_button_->setText(QString());
#ifndef QT_NO_TOOLTIP
        set_home_view_button_->setToolTip(QApplication::translate("Project_view_form", "Set Home View", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        set_home_view_button_->setText(QString());
#ifndef QT_NO_TOOLTIP
        snapshot_button_->setToolTip(QApplication::translate("Project_view_form", "Snapshot", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        snapshot_button_->setText(QString());
        Q_UNUSED(Project_view_form);
    } // retranslateUi

};

namespace Ui {
    class Project_view_form: public Ui_Project_view_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT_VIEW_FORM_H
