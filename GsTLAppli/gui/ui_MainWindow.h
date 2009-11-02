/********************************************************************************
** Form generated from reading ui file 'MainWindow.ui'
**
** Created: Sun Nov 1 20:46:31 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *fileLoadObject;
    QAction *fileParameterOpenAction;
    QAction *fileParameterSaveAction;
    QAction *fileParamterSaveAsAction;
    QAction *filePrintAction;
    QAction *fileExitAction;
    QAction *editUndoAction;
    QAction *editRedoAction;
    QAction *editCutAction;
    QAction *editCopyAction;
    QAction *editPasteAction;
    QAction *editFindAction;
    QAction *helpContentsAction;
    QAction *helpIndexAction;
    QAction *helpAboutAction;
    QAction *objectNewObjectAction;
    QAction *objectLoadObjectAction;
    QAction *objectSaveObjectAction;
    QAction *objectSaveAsObjectAction;
    QAction *objectAddPropertyAction;
    QAction *objectCopyPropertyAction;
    QAction *displaySnapshotAction;
    QAction *displayToggle2d3dAction;
    QAction *displayChangeColormapAction;
    QAction *displayDisplayColormapAction;
    QAction *displayBackgroundColorAction;
    QAction *windowCommandPanelHideAction;
    QAction *Action;
    QWidget *widget;
    QHBoxLayout *hboxLayout;
    QSplitter *MainSplitter;
    QFrame *left_panel_;
    QHBoxLayout *hboxLayout1;
    QVBoxLayout *vboxLayout;
    QTreeWidget *AlgorithmSelector;
    QGroupBox *ExecPanelGroupBox;
    QWidget *Layout3;
    QHBoxLayout *hboxLayout2;
    QPushButton *GoStopButton;
    QProgressBar *ProgressBar1;
    QGroupBox *GroupBox3;
    QPushButton *SaveParamButton;
    QPushButton *LoadParamButton;
    QPushButton *ClearParamButton;
    QFrame *right_panel_;
    QMenuBar *menubar_;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *PopupMenu;
    QMenu *PopupMenu_3;
    QMenu *PopupMenu_2;
    QMenu *helpMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1018, 836);
        fileLoadObject = new QAction(MainWindow);
        fileLoadObject->setObjectName(QString::fromUtf8("fileLoadObject"));
        fileLoadObject->setShortcut(4194380);
        fileParameterOpenAction = new QAction(MainWindow);
        fileParameterOpenAction->setObjectName(QString::fromUtf8("fileParameterOpenAction"));
        fileParameterOpenAction->setShortcut(4194383);
        fileParameterSaveAction = new QAction(MainWindow);
        fileParameterSaveAction->setObjectName(QString::fromUtf8("fileParameterSaveAction"));
        fileParameterSaveAction->setShortcut(4194387);
        fileParamterSaveAsAction = new QAction(MainWindow);
        fileParamterSaveAsAction->setObjectName(QString::fromUtf8("fileParamterSaveAsAction"));
        fileParamterSaveAsAction->setShortcut(0);
        filePrintAction = new QAction(MainWindow);
        filePrintAction->setObjectName(QString::fromUtf8("filePrintAction"));
        filePrintAction->setShortcut(4194384);
        fileExitAction = new QAction(MainWindow);
        fileExitAction->setObjectName(QString::fromUtf8("fileExitAction"));
        fileExitAction->setShortcut(4194385);
        editUndoAction = new QAction(MainWindow);
        editUndoAction->setObjectName(QString::fromUtf8("editUndoAction"));
        editUndoAction->setShortcut(4194394);
        editRedoAction = new QAction(MainWindow);
        editRedoAction->setObjectName(QString::fromUtf8("editRedoAction"));
        editRedoAction->setShortcut(4194393);
        editCutAction = new QAction(MainWindow);
        editCutAction->setObjectName(QString::fromUtf8("editCutAction"));
        editCutAction->setShortcut(4194392);
        editCopyAction = new QAction(MainWindow);
        editCopyAction->setObjectName(QString::fromUtf8("editCopyAction"));
        editCopyAction->setShortcut(4194371);
        editPasteAction = new QAction(MainWindow);
        editPasteAction->setObjectName(QString::fromUtf8("editPasteAction"));
        editPasteAction->setShortcut(4194390);
        editFindAction = new QAction(MainWindow);
        editFindAction->setObjectName(QString::fromUtf8("editFindAction"));
        editFindAction->setShortcut(4194374);
        helpContentsAction = new QAction(MainWindow);
        helpContentsAction->setObjectName(QString::fromUtf8("helpContentsAction"));
        helpContentsAction->setShortcut(0);
        helpIndexAction = new QAction(MainWindow);
        helpIndexAction->setObjectName(QString::fromUtf8("helpIndexAction"));
        helpIndexAction->setShortcut(0);
        helpAboutAction = new QAction(MainWindow);
        helpAboutAction->setObjectName(QString::fromUtf8("helpAboutAction"));
        helpAboutAction->setShortcut(0);
        objectNewObjectAction = new QAction(MainWindow);
        objectNewObjectAction->setObjectName(QString::fromUtf8("objectNewObjectAction"));
        objectNewObjectAction->setShortcut(4194382);
        objectLoadObjectAction = new QAction(MainWindow);
        objectLoadObjectAction->setObjectName(QString::fromUtf8("objectLoadObjectAction"));
        objectLoadObjectAction->setShortcut(4194380);
        objectSaveObjectAction = new QAction(MainWindow);
        objectSaveObjectAction->setObjectName(QString::fromUtf8("objectSaveObjectAction"));
        objectSaveAsObjectAction = new QAction(MainWindow);
        objectSaveAsObjectAction->setObjectName(QString::fromUtf8("objectSaveAsObjectAction"));
        objectAddPropertyAction = new QAction(MainWindow);
        objectAddPropertyAction->setObjectName(QString::fromUtf8("objectAddPropertyAction"));
        objectCopyPropertyAction = new QAction(MainWindow);
        objectCopyPropertyAction->setObjectName(QString::fromUtf8("objectCopyPropertyAction"));
        displaySnapshotAction = new QAction(MainWindow);
        displaySnapshotAction->setObjectName(QString::fromUtf8("displaySnapshotAction"));
        displaySnapshotAction->setShortcut(4198448);
        displayToggle2d3dAction = new QAction(MainWindow);
        displayToggle2d3dAction->setObjectName(QString::fromUtf8("displayToggle2d3dAction"));
        displayChangeColormapAction = new QAction(MainWindow);
        displayChangeColormapAction->setObjectName(QString::fromUtf8("displayChangeColormapAction"));
        displayDisplayColormapAction = new QAction(MainWindow);
        displayDisplayColormapAction->setObjectName(QString::fromUtf8("displayDisplayColormapAction"));
        displayBackgroundColorAction = new QAction(MainWindow);
        displayBackgroundColorAction->setObjectName(QString::fromUtf8("displayBackgroundColorAction"));
        windowCommandPanelHideAction = new QAction(MainWindow);
        windowCommandPanelHideAction->setObjectName(QString::fromUtf8("windowCommandPanelHideAction"));
        windowCommandPanelHideAction->setShortcut(4194376);
        Action = new QAction(MainWindow);
        Action->setObjectName(QString::fromUtf8("Action"));
        widget = new QWidget(MainWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        hboxLayout = new QHBoxLayout(widget);
        hboxLayout->setSpacing(2);
        hboxLayout->setMargin(1);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        MainSplitter = new QSplitter(widget);
        MainSplitter->setObjectName(QString::fromUtf8("MainSplitter"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainSplitter->sizePolicy().hasHeightForWidth());
        MainSplitter->setSizePolicy(sizePolicy);
        MainSplitter->setOrientation(Qt::Horizontal);
        left_panel_ = new QFrame(MainSplitter);
        left_panel_->setObjectName(QString::fromUtf8("left_panel_"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(7));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(left_panel_->sizePolicy().hasHeightForWidth());
        left_panel_->setSizePolicy(sizePolicy1);
        left_panel_->setMinimumSize(QSize(0, 0));
        left_panel_->setMaximumSize(QSize(340, 32767));
        left_panel_->setFrameShape(QFrame::Box);
        left_panel_->setFrameShadow(QFrame::Plain);
        hboxLayout1 = new QHBoxLayout(left_panel_);
        hboxLayout1->setSpacing(2);
        hboxLayout1->setMargin(1);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(2);
        vboxLayout->setMargin(0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        AlgorithmSelector = new QTreeWidget(left_panel_);
        AlgorithmSelector->setObjectName(QString::fromUtf8("AlgorithmSelector"));

        vboxLayout->addWidget(AlgorithmSelector);

        ExecPanelGroupBox = new QGroupBox(left_panel_);
        ExecPanelGroupBox->setObjectName(QString::fromUtf8("ExecPanelGroupBox"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ExecPanelGroupBox->sizePolicy().hasHeightForWidth());
        ExecPanelGroupBox->setSizePolicy(sizePolicy2);
        ExecPanelGroupBox->setMinimumSize(QSize(0, 120));
        ExecPanelGroupBox->setMaximumSize(QSize(32767, 90));
        Layout3 = new QWidget(ExecPanelGroupBox);
        Layout3->setObjectName(QString::fromUtf8("Layout3"));
        Layout3->setGeometry(QRect(10, 80, 310, 32));
        hboxLayout2 = new QHBoxLayout(Layout3);
        hboxLayout2->setSpacing(6);
        hboxLayout2->setMargin(0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        GoStopButton = new QPushButton(Layout3);
        GoStopButton->setObjectName(QString::fromUtf8("GoStopButton"));
        QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(GoStopButton->sizePolicy().hasHeightForWidth());
        GoStopButton->setSizePolicy(sizePolicy3);
        GoStopButton->setMinimumSize(QSize(80, 0));
        GoStopButton->setFlat(false);

        hboxLayout2->addWidget(GoStopButton);

        ProgressBar1 = new QProgressBar(Layout3);
        ProgressBar1->setObjectName(QString::fromUtf8("ProgressBar1"));
        ProgressBar1->setOrientation(Qt::Horizontal);

        hboxLayout2->addWidget(ProgressBar1);

        GroupBox3 = new QGroupBox(ExecPanelGroupBox);
        GroupBox3->setObjectName(QString::fromUtf8("GroupBox3"));
        GroupBox3->setGeometry(QRect(10, 10, 310, 60));
        GroupBox3->setMaximumSize(QSize(32767, 32767));
        SaveParamButton = new QPushButton(GroupBox3);
        SaveParamButton->setObjectName(QString::fromUtf8("SaveParamButton"));
        SaveParamButton->setGeometry(QRect(80, 20, 50, 30));
        LoadParamButton = new QPushButton(GroupBox3);
        LoadParamButton->setObjectName(QString::fromUtf8("LoadParamButton"));
        LoadParamButton->setGeometry(QRect(10, 20, 50, 30));
        ClearParamButton = new QPushButton(GroupBox3);
        ClearParamButton->setObjectName(QString::fromUtf8("ClearParamButton"));
        ClearParamButton->setGeometry(QRect(240, 20, 60, 30));

        vboxLayout->addWidget(ExecPanelGroupBox);


        hboxLayout1->addLayout(vboxLayout);

        MainSplitter->addWidget(left_panel_);
        right_panel_ = new QFrame(MainSplitter);
        right_panel_->setObjectName(QString::fromUtf8("right_panel_"));
        sizePolicy.setHeightForWidth(right_panel_->sizePolicy().hasHeightForWidth());
        right_panel_->setSizePolicy(sizePolicy);
        right_panel_->setMinimumSize(QSize(500, 0));
        right_panel_->setFrameShape(QFrame::Box);
        right_panel_->setFrameShadow(QFrame::Plain);
        MainSplitter->addWidget(right_panel_);

        hboxLayout->addWidget(MainSplitter);

        MainWindow->setCentralWidget(widget);
        menubar_ = new QMenuBar(MainWindow);
        menubar_->setObjectName(QString::fromUtf8("menubar_"));
        menubar_->setGeometry(QRect(0, 0, 1018, 29));
        fileMenu = new QMenu(menubar_);
        fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
        editMenu = new QMenu(menubar_);
        editMenu->setObjectName(QString::fromUtf8("editMenu"));
        PopupMenu = new QMenu(menubar_);
        PopupMenu->setObjectName(QString::fromUtf8("PopupMenu"));
        PopupMenu_3 = new QMenu(menubar_);
        PopupMenu_3->setObjectName(QString::fromUtf8("PopupMenu_3"));
        PopupMenu_2 = new QMenu(menubar_);
        PopupMenu_2->setObjectName(QString::fromUtf8("PopupMenu_2"));
        helpMenu = new QMenu(menubar_);
        helpMenu->setObjectName(QString::fromUtf8("helpMenu"));
        MainWindow->setMenuBar(menubar_);

        menubar_->addAction(fileMenu->menuAction());
        menubar_->addAction(editMenu->menuAction());
        menubar_->addAction(PopupMenu->menuAction());
        menubar_->addAction(PopupMenu_3->menuAction());
        menubar_->addAction(PopupMenu_2->menuAction());
        menubar_->addAction(helpMenu->menuAction());
        fileMenu->addAction(fileParameterOpenAction);
        fileMenu->addAction(fileParameterSaveAction);
        fileMenu->addAction(fileParamterSaveAsAction);
        fileMenu->addSeparator();
        fileMenu->addAction(filePrintAction);
        fileMenu->addSeparator();
        fileMenu->addAction(fileExitAction);
        editMenu->addAction(editUndoAction);
        editMenu->addAction(editRedoAction);
        editMenu->addSeparator();
        editMenu->addAction(editCopyAction);
        editMenu->addAction(editCutAction);
        editMenu->addAction(editPasteAction);
        PopupMenu->addAction(objectNewObjectAction);
        PopupMenu->addAction(objectLoadObjectAction);
        PopupMenu->addAction(objectSaveObjectAction);
        PopupMenu->addAction(objectSaveAsObjectAction);
        PopupMenu->addSeparator();
        PopupMenu->addAction(objectAddPropertyAction);
        PopupMenu->addAction(objectCopyPropertyAction);
        PopupMenu_3->addAction(displaySnapshotAction);
        PopupMenu_3->addSeparator();
        PopupMenu_3->addAction(displayToggle2d3dAction);
        PopupMenu_3->addSeparator();
        PopupMenu_3->addAction(displayDisplayColormapAction);
        PopupMenu_3->addAction(displayChangeColormapAction);
        PopupMenu_3->addAction(displayBackgroundColorAction);
        PopupMenu_2->addAction(windowCommandPanelHideAction);
        helpMenu->addAction(helpContentsAction);
        helpMenu->addAction(helpIndexAction);
        helpMenu->addSeparator();
        helpMenu->addAction(helpAboutAction);

        retranslateUi(MainWindow);
        QObject::connect(fileLoadObject, SIGNAL(activated()), MainWindow, SLOT(fileNew()));
        QObject::connect(fileParameterOpenAction, SIGNAL(activated()), MainWindow, SLOT(fileOpen()));
        QObject::connect(fileParameterSaveAction, SIGNAL(activated()), MainWindow, SLOT(fileSave()));
        QObject::connect(fileParamterSaveAsAction, SIGNAL(activated()), MainWindow, SLOT(fileSaveAs()));
        QObject::connect(filePrintAction, SIGNAL(activated()), MainWindow, SLOT(filePrint()));
        QObject::connect(editUndoAction, SIGNAL(activated()), MainWindow, SLOT(editUndo()));
        QObject::connect(editRedoAction, SIGNAL(activated()), MainWindow, SLOT(editRedo()));
        QObject::connect(editCutAction, SIGNAL(activated()), MainWindow, SLOT(editCut()));
        QObject::connect(editCopyAction, SIGNAL(activated()), MainWindow, SLOT(editCopy()));
        QObject::connect(editPasteAction, SIGNAL(activated()), MainWindow, SLOT(editPaste()));
        QObject::connect(editFindAction, SIGNAL(activated()), MainWindow, SLOT(editFind()));
        QObject::connect(helpIndexAction, SIGNAL(activated()), MainWindow, SLOT(helpIndex()));
        QObject::connect(helpContentsAction, SIGNAL(activated()), MainWindow, SLOT(helpContents()));
        QObject::connect(helpAboutAction, SIGNAL(activated()), MainWindow, SLOT(helpAbout()));
        QObject::connect(fileExitAction, SIGNAL(activated()), MainWindow, SLOT(fileExit()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GsTLAppli", 0, QApplication::UnicodeUTF8));
        fileLoadObject->setText(QApplication::translate("MainWindow", "&Load Object", 0, QApplication::UnicodeUTF8));
        fileLoadObject->setIconText(QApplication::translate("MainWindow", "Load Object", 0, QApplication::UnicodeUTF8));
        fileParameterOpenAction->setText(QApplication::translate("MainWindow", "&Load Parameters...", 0, QApplication::UnicodeUTF8));
        fileParameterOpenAction->setIconText(QApplication::translate("MainWindow", "Load Parameters", 0, QApplication::UnicodeUTF8));
        fileParameterSaveAction->setText(QApplication::translate("MainWindow", "&Save Parameters", 0, QApplication::UnicodeUTF8));
        fileParameterSaveAction->setIconText(QApplication::translate("MainWindow", "Save Parameters", 0, QApplication::UnicodeUTF8));
        fileParamterSaveAsAction->setText(QApplication::translate("MainWindow", "Save Parameters &As...", 0, QApplication::UnicodeUTF8));
        fileParamterSaveAsAction->setIconText(QApplication::translate("MainWindow", "Save Parameters As", 0, QApplication::UnicodeUTF8));
        filePrintAction->setText(QApplication::translate("MainWindow", "&Print...", 0, QApplication::UnicodeUTF8));
        filePrintAction->setIconText(QApplication::translate("MainWindow", "Print", 0, QApplication::UnicodeUTF8));
        fileExitAction->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        fileExitAction->setIconText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        editUndoAction->setText(QApplication::translate("MainWindow", "&Undo", 0, QApplication::UnicodeUTF8));
        editUndoAction->setIconText(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
        editRedoAction->setText(QApplication::translate("MainWindow", "&Redo", 0, QApplication::UnicodeUTF8));
        editRedoAction->setIconText(QApplication::translate("MainWindow", "Redo", 0, QApplication::UnicodeUTF8));
        editCutAction->setText(QApplication::translate("MainWindow", "&Cut", 0, QApplication::UnicodeUTF8));
        editCutAction->setIconText(QApplication::translate("MainWindow", "Cut", 0, QApplication::UnicodeUTF8));
        editCopyAction->setText(QApplication::translate("MainWindow", "C&opy", 0, QApplication::UnicodeUTF8));
        editCopyAction->setIconText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
        editPasteAction->setText(QApplication::translate("MainWindow", "&Paste", 0, QApplication::UnicodeUTF8));
        editPasteAction->setIconText(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
        editFindAction->setText(QApplication::translate("MainWindow", "&Find...", 0, QApplication::UnicodeUTF8));
        editFindAction->setIconText(QApplication::translate("MainWindow", "Find", 0, QApplication::UnicodeUTF8));
        helpContentsAction->setText(QApplication::translate("MainWindow", "&Contents...", 0, QApplication::UnicodeUTF8));
        helpContentsAction->setIconText(QApplication::translate("MainWindow", "Contents", 0, QApplication::UnicodeUTF8));
        helpIndexAction->setText(QApplication::translate("MainWindow", "&Index...", 0, QApplication::UnicodeUTF8));
        helpIndexAction->setIconText(QApplication::translate("MainWindow", "Index", 0, QApplication::UnicodeUTF8));
        helpAboutAction->setText(QApplication::translate("MainWindow", "&About...", 0, QApplication::UnicodeUTF8));
        helpAboutAction->setIconText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        objectNewObjectAction->setText(QApplication::translate("MainWindow", "&New", 0, QApplication::UnicodeUTF8));
        objectNewObjectAction->setIconText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        objectLoadObjectAction->setText(QApplication::translate("MainWindow", "&Load", 0, QApplication::UnicodeUTF8));
        objectLoadObjectAction->setIconText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        objectSaveObjectAction->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        objectSaveObjectAction->setIconText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        objectSaveObjectAction->setToolTip(QApplication::translate("MainWindow", "Save Object", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        objectSaveAsObjectAction->setIconText(QApplication::translate("MainWindow", "Save As...", 0, QApplication::UnicodeUTF8));
        objectAddPropertyAction->setIconText(QApplication::translate("MainWindow", "Add Property", 0, QApplication::UnicodeUTF8));
        objectCopyPropertyAction->setIconText(QApplication::translate("MainWindow", "Copy Property", 0, QApplication::UnicodeUTF8));
        displaySnapshotAction->setIconText(QApplication::translate("MainWindow", "Snapshot", 0, QApplication::UnicodeUTF8));
        displayToggle2d3dAction->setIconText(QApplication::translate("MainWindow", "Toggle 2d/3d", 0, QApplication::UnicodeUTF8));
        displayChangeColormapAction->setIconText(QApplication::translate("MainWindow", "Change Colormap...", 0, QApplication::UnicodeUTF8));
        displayDisplayColormapAction->setIconText(QApplication::translate("MainWindow", "Show Colormap", 0, QApplication::UnicodeUTF8));
        displayBackgroundColorAction->setIconText(QApplication::translate("MainWindow", "Background Color...", 0, QApplication::UnicodeUTF8));
        windowCommandPanelHideAction->setIconText(QApplication::translate("MainWindow", "Hide/Show Command Panel", 0, QApplication::UnicodeUTF8));
        Action->setIconText(QApplication::translate("MainWindow", "Action", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = AlgorithmSelector->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Description", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Algorithm", 0, QApplication::UnicodeUTF8));
        ExecPanelGroupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        GoStopButton->setToolTip(QApplication::translate("MainWindow", "Run / Interrupt", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        GoStopButton->setText(QApplication::translate("MainWindow", "Execute", 0, QApplication::UnicodeUTF8));
        GroupBox3->setTitle(QApplication::translate("MainWindow", "Parameters", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SaveParamButton->setToolTip(QApplication::translate("MainWindow", "Click to save the parameters", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        SaveParamButton->setText(QApplication::translate("MainWindow", "Save", "Start performing the selected task", QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        LoadParamButton->setToolTip(QApplication::translate("MainWindow", "Load parameters from file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        LoadParamButton->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ClearParamButton->setToolTip(QApplication::translate("MainWindow", "Clear the parameters", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ClearParamButton->setText(QApplication::translate("MainWindow", "Clear All", "Start performing the selected task", QApplication::UnicodeUTF8));
        fileMenu->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        editMenu->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        PopupMenu->setTitle(QApplication::translate("MainWindow", "&Object", 0, QApplication::UnicodeUTF8));
        PopupMenu_3->setTitle(QApplication::translate("MainWindow", "&Display", 0, QApplication::UnicodeUTF8));
        PopupMenu_2->setTitle(QApplication::translate("MainWindow", "&Window", 0, QApplication::UnicodeUTF8));
        helpMenu->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
