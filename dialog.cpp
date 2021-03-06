
#include <QtWidgets>
#include <QTextCodec>
#include <iostream>

#include "parmdefine.h"
#include "dialog.h"
#include "ui_dialog.h"

using namespace std;

//! [0]
Dialog::Dialog()
{
    codec = QTextCodec::codecForName("utf-8");

    createMenu();
    createGridGroupBox1();
    createGridGroupBox2();
    createGridGroupBox3();
    createGridGroupBox4();
    createGridGroupBox5();
    createGridGroupBox6();
    createGridGroupBox7();
    createButtonBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(2);
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(gridGroupBox1);
    mainLayout->addWidget(gridGroupBox2);
    mainLayout->addWidget(gridGroupBox3);
    mainLayout->addWidget(gridGroupBox4);
    mainLayout->addWidget(gridGroupBox5);
    mainLayout->addWidget(gridGroupBox6);
    mainLayout->addWidget(gridGroupBox7);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    tmpString = codec->toUnicode("空间红外天文观测仿真软件");
    setWindowTitle(tmpString);
    setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    //this->setWindowState(Qt::WindowMinimized);

    initParameter();
    loadObjectParameterFileNames();
}

void Dialog::initParameter()
{
    ObjectParameterFile = OBJECTPARAMETERFILE;
    fileNameList = QList<QString>();
}


void Dialog::createMenu()
{
    menuBar = new QMenuBar;

    tmpString = codec->toUnicode("文件");
    fileMenu = new QMenu(tmpString, this);
    tmpString = codec->toUnicode("打开");
    openAction = fileMenu->addAction(tmpString);
    tmpString = codec->toUnicode("保存");
    saveAction = fileMenu->addAction(tmpString);
    tmpString = codec->toUnicode("另存为");
    saveAsAction = fileMenu->addAction(tmpString);
    tmpString = codec->toUnicode("退出");
    exitAction = fileMenu->addAction(tmpString);
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
    //connect
}

//Observation strategy
void Dialog::createGridGroupBox1()
{
    tmpString = codec->toUnicode("观测策略");
    gridGroupBox1 = new QGroupBox(tmpString);
    QGridLayout *layout = new QGridLayout;
    layout->setVerticalSpacing(WidgetVerticalSpacing);
    layout->setContentsMargins(LayoutContentsMargin,LayoutContentsMarginTop,LayoutContentsMargin,LayoutContentsMargin);

    tmpString = codec->toUnicode("赤经：");
    label11 = new QLabel(tmpString);
    lineEdit11 = new QLineEdit;
    lineEdit11->setMaximumWidth(InputBoxMaxLength);
    tmpString = codec->toUnicode("度");
    symble11 = new QLabel(tmpString);
    layout->addWidget(label11, 0, 0);
    layout->addWidget(lineEdit11, 0, 1);
    layout->addWidget(symble11, 0, 2);

    tmpString = codec->toUnicode("赤纬：");
    label12 = new QLabel(tmpString);
    lineEdit12 = new QLineEdit;
    lineEdit12->setMaximumWidth(InputBoxMaxLength);
    tmpString = codec->toUnicode("度");
    symble12 = new QLabel(tmpString);
    layout->addWidget(label12, 0, 3);
    layout->addWidget(lineEdit12, 0, 4);
    layout->addWidget(symble12, 0, 5);

    tmpString = codec->toUnicode("曝光时间(A)：");
    label13 = new QLabel(tmpString);
    lineEdit13 = new QLineEdit;
    lineEdit13->setMaximumWidth(InputBoxMaxLength);
    tmpString = codec->toUnicode("秒");
    symble13 = new QLabel(tmpString);
    layout->addWidget(label13, 1, 0);
    layout->addWidget(lineEdit13, 1, 1);
    layout->addWidget(symble13, 1, 2);

    tmpString = codec->toUnicode("曝光时间(B)：");
    label14 = new QLabel(tmpString);
    lineEdit14 = new QLineEdit;
    lineEdit14->setMaximumWidth(InputBoxMaxLength);
    tmpString = codec->toUnicode("秒");
    symble14 = new QLabel(tmpString);
    layout->addWidget(label14, 1, 3);
    layout->addWidget(lineEdit14, 1, 4);
    layout->addWidget(symble14, 1, 5);

    layout->setColumnStretch(2, 20);
    layout->setColumnStretch(5, 20);

    gridGroupBox1->setLayout(layout);
}

//optical system feature
void Dialog::createGridGroupBox2()
{
    tmpString = codec->toUnicode("光学系统特征");
    gridGroupBox2 = new QGroupBox(tmpString);
    QGridLayout *layout = new QGridLayout;
    layout->setVerticalSpacing(WidgetVerticalSpacing);
    layout->setContentsMargins(LayoutContentsMargin,LayoutContentsMarginTop,LayoutContentsMargin,LayoutContentsMargin);

    //有效孔径
    tmpString = codec->toUnicode("有效孔径（直径）：");
    label21 = new QLabel(tmpString);
    lineEdit21 = new QLineEdit;
    lineEdit21->setMaximumWidth(InputBoxMaxLength);
    layout->addWidget(label21, 0, 0);
    layout->addWidget(lineEdit21, 0, 1);

    //通道A
    tmpString = codec->toUnicode("通道A");
    label22 = new QLabel(tmpString);
    layout->addWidget(label22, 0, 2);

    tmpString = codec->toUnicode("光学透过率：");
    label23 = new QLabel(tmpString);
    lineEdit22 = new QLineEdit;
    lineEdit22->setMaximumWidth(InputBoxMaxLength);
    button21 = new QPushButton;
    button21->setIcon(QIcon(":/images/open.png"));
    button21->setMaximumHeight(ButtonMaximumHeight);
    connect(button21, SIGNAL(clicked()), this, SLOT(slotOpenFile21()));
    layout->addWidget(label23, 0, 3);
    layout->addWidget(lineEdit22, 0, 4);
    layout->addWidget(button21, 0, 5);

    tmpString = codec->toUnicode("PSF：");
    label24 = new QLabel(tmpString);
    lineEdit23 = new QLineEdit;
    lineEdit23->setMaximumWidth(InputBoxMaxLength);
    button22 = new QPushButton;
    button22->setIcon(QIcon(":/images/open.png"));
    button22->setMaximumHeight(ButtonMaximumHeight);
    connect(button22, SIGNAL(clicked()), this, SLOT(slotOpenFile22()));
    layout->addWidget(label24, 0, 6);
    layout->addWidget(lineEdit23, 0, 7);
    layout->addWidget(button22, 0, 8);


    //通道B
    tmpString = codec->toUnicode("通道B");
    label25 = new QLabel(tmpString);
    layout->addWidget(label25, 1, 2);

    tmpString = codec->toUnicode("光学透过率：");
    label26 = new QLabel(tmpString);
    lineEdit24 = new QLineEdit;
    lineEdit24->setMaximumWidth(InputBoxMaxLength);
    button23 = new QPushButton;
    button23->setIcon(QIcon(":/images/open.png"));
    button23->setMaximumHeight(ButtonMaximumHeight);
    connect(button23, SIGNAL(clicked()), this, SLOT(slotOpenFile23()));
    layout->addWidget(label26, 1, 3);
    layout->addWidget(lineEdit24, 1, 4);
    layout->addWidget(button23, 1, 5);

    tmpString = codec->toUnicode("PSF：");
    label27 = new QLabel(tmpString);
    lineEdit25 = new QLineEdit;
    lineEdit25->setMaximumWidth(InputBoxMaxLength);
    button24 = new QPushButton;
    button24->setIcon(QIcon(":/images/open.png"));
    button24->setMaximumHeight(ButtonMaximumHeight);
    connect(button24, SIGNAL(clicked()), this, SLOT(slotOpenFile24()));
    layout->addWidget(label27, 1, 6);
    layout->addWidget(lineEdit25, 1, 7);
    layout->addWidget(button24, 1, 8);

    gridGroupBox2->setLayout(layout);
}


//detector parameter
void Dialog::createGridGroupBox3()
{
    tmpString = codec->toUnicode("探测器参数");
    gridGroupBox3 = new QGroupBox(tmpString);
    QGridLayout *layout = new QGridLayout;
    layout->setVerticalSpacing(WidgetVerticalSpacing);
    layout->setContentsMargins(LayoutContentsMargin,LayoutContentsMarginTop,LayoutContentsMargin,LayoutContentsMargin);

    //通道A
    tmpString = codec->toUnicode("通道A");
    label31 = new QLabel(tmpString);
    layout->addWidget(label31, 0, 0);

    tmpString = codec->toUnicode("读出噪声：");
    label32 = new QLabel(tmpString);
    lineEdit32 = new QLineEdit;
    lineEdit32->setMaximumWidth(InputBoxMaxLength);
    button32 = new QPushButton;
    button32->setIcon(QIcon(":/images/open.png"));
    button32->setMaximumHeight(ButtonMaximumHeight);
    connect(button32, SIGNAL(clicked()), this, SLOT(slotOpenFile32()));
    layout->addWidget(label32, 0, 1);
    layout->addWidget(lineEdit32, 0, 2);
    layout->addWidget(button32, 0, 3);

    tmpString = codec->toUnicode("增益：");
    label33 = new QLabel(tmpString);
    lineEdit33 = new QLineEdit;
    lineEdit33->setMaximumWidth(InputBoxMaxLength);
    button33 = new QPushButton;
    button33->setIcon(QIcon(":/images/open.png"));
    button33->setMaximumHeight(ButtonMaximumHeight);
    connect(button33, SIGNAL(clicked()), this, SLOT(slotOpenFile33()));
    layout->addWidget(label33, 0, 4);
    layout->addWidget(lineEdit33, 0, 5);
    layout->addWidget(button33, 0, 6);

    tmpString = codec->toUnicode("像元尺寸：");
    label34 = new QLabel(tmpString);
    lineEdit34 = new QLineEdit;
    lineEdit34->setMaximumWidth(InputBoxMaxLength);
    button34 = new QPushButton;
    button34->setIcon(QIcon(":/images/open.png"));
    button34->setMaximumHeight(ButtonMaximumHeight);
    connect(button34, SIGNAL(clicked()), this, SLOT(slotOpenFile34()));
    layout->addWidget(label34, 0, 7);
    layout->addWidget(lineEdit34, 0, 8);
    layout->addWidget(button34, 0, 9);

    tmpString = codec->toUnicode("像元数目：");
    label35 = new QLabel(tmpString);
    lineEdit35 = new QLineEdit;
    lineEdit35->setMaximumWidth(InputBoxMaxLength);
    button35 = new QPushButton;
    button35->setIcon(QIcon(":/images/open.png"));
    button35->setMaximumHeight(ButtonMaximumHeight);
    connect(button35, SIGNAL(clicked()), this, SLOT(slotOpenFile35()));
    layout->addWidget(label35, 1, 1);
    layout->addWidget(lineEdit35, 1, 2);
    layout->addWidget(button35, 1, 3);

    tmpString = codec->toUnicode("响应曲线：");
    label36 = new QLabel(tmpString);
    lineEdit36 = new QLineEdit;
    lineEdit36->setMaximumWidth(InputBoxMaxLength);
    button36 = new QPushButton;
    button36->setIcon(QIcon(":/images/open.png"));
    button36->setMaximumHeight(ButtonMaximumHeight);
    connect(button36, SIGNAL(clicked()), this, SLOT(slotOpenFile36()));
    layout->addWidget(label36, 1, 4);
    layout->addWidget(lineEdit36, 1, 5);
    layout->addWidget(button36, 1, 6);

    tmpString = codec->toUnicode("背景热噪声：");
    label37 = new QLabel(tmpString);
    lineEdit37 = new QLineEdit;
    lineEdit37->setMaximumWidth(InputBoxMaxLength);
    button37 = new QPushButton;
    button37->setIcon(QIcon(":/images/open.png"));
    button37->setMaximumHeight(ButtonMaximumHeight);
    connect(button37, SIGNAL(clicked()), this, SLOT(slotOpenFile37()));
    layout->addWidget(label37, 1, 7);
    layout->addWidget(lineEdit37, 1, 8);
    layout->addWidget(button37, 1, 9);


    //通道B
    tmpString = codec->toUnicode("通道B");
    label38 = new QLabel(tmpString);
    layout->addWidget(label38, 2, 0);

    tmpString = codec->toUnicode("读出噪声：");
    label39 = new QLabel(tmpString);
    lineEdit39 = new QLineEdit;
    lineEdit39->setMaximumWidth(InputBoxMaxLength);
    button39 = new QPushButton;
    button39->setIcon(QIcon(":/images/open.png"));
    button39->setMaximumHeight(ButtonMaximumHeight);
    connect(button39, SIGNAL(clicked()), this, SLOT(slotOpenFile39()));
    layout->addWidget(label39, 2, 1);
    layout->addWidget(lineEdit39, 2, 2);
    layout->addWidget(button39, 2, 3);

    tmpString = codec->toUnicode("增益：");
    label310 = new QLabel(tmpString);
    lineEdit310 = new QLineEdit;
    lineEdit310->setMaximumWidth(InputBoxMaxLength);
    button310 = new QPushButton;
    button310->setIcon(QIcon(":/images/open.png"));
    button310->setMaximumHeight(ButtonMaximumHeight);
    connect(button310, SIGNAL(clicked()), this, SLOT(slotOpenFile310()));
    layout->addWidget(label310, 2, 4);
    layout->addWidget(lineEdit310, 2, 5);
    layout->addWidget(button310, 2, 6);

    tmpString = codec->toUnicode("像元尺寸：");
    label311 = new QLabel(tmpString);
    lineEdit311 = new QLineEdit;
    lineEdit311->setMaximumWidth(InputBoxMaxLength);
    button311 = new QPushButton;
    button311->setIcon(QIcon(":/images/open.png"));
    button311->setMaximumHeight(ButtonMaximumHeight);
    connect(button311, SIGNAL(clicked()), this, SLOT(slotOpenFile311()));
    layout->addWidget(label311, 2, 7);
    layout->addWidget(lineEdit311, 2, 8);
    layout->addWidget(button311, 2, 9);

    tmpString = codec->toUnicode("像元数目：");
    label312 = new QLabel(tmpString);
    lineEdit312 = new QLineEdit;
    lineEdit312->setMaximumWidth(InputBoxMaxLength);
    button312 = new QPushButton;
    button312->setIcon(QIcon(":/images/open.png"));
    button312->setMaximumHeight(ButtonMaximumHeight);
    connect(button312, SIGNAL(clicked()), this, SLOT(slotOpenFile312()));
    layout->addWidget(label312, 3, 1);
    layout->addWidget(lineEdit312, 3, 2);
    layout->addWidget(button312, 3, 3);

    tmpString = codec->toUnicode("响应曲线：");
    label313 = new QLabel(tmpString);
    lineEdit313 = new QLineEdit;
    lineEdit313->setMaximumWidth(InputBoxMaxLength);
    button313 = new QPushButton;
    button313->setIcon(QIcon(":/images/open.png"));
    button313->setMaximumHeight(ButtonMaximumHeight);
    connect(button313, SIGNAL(clicked()), this, SLOT(slotOpenFile313()));
    layout->addWidget(label313, 3, 4);
    layout->addWidget(lineEdit313, 3, 5);
    layout->addWidget(button313, 3, 6);

    tmpString = codec->toUnicode("背景热噪声：");
    label314 = new QLabel(tmpString);
    lineEdit314 = new QLineEdit;
    lineEdit314->setMaximumWidth(InputBoxMaxLength);
    button314 = new QPushButton;
    button314->setIcon(QIcon(":/images/open.png"));
    button314->setMaximumHeight(ButtonMaximumHeight);
    connect(button314, SIGNAL(clicked()), this, SLOT(slotOpenFile314()));
    layout->addWidget(label314, 3, 7);
    layout->addWidget(lineEdit314, 3, 8);
    layout->addWidget(button314, 3, 9);

    gridGroupBox3->setLayout(layout);
}

//plantform stable parameter
void Dialog::createGridGroupBox4()
{
    tmpString = codec->toUnicode("平台稳定性参数");
    gridGroupBox4 = new QGroupBox(tmpString);
    QGridLayout *layout = new QGridLayout;//QHBoxLayout
    layout->setVerticalSpacing(WidgetVerticalSpacing);
    layout->setContentsMargins(LayoutContentsMargin,LayoutContentsMarginTop,LayoutContentsMargin,LayoutContentsMargin);

    tmpString = codec->toUnicode("平台稳定度(lsigma)：");
    label41 = new QLabel(tmpString);
    lineEdit41 = new QLineEdit;
    lineEdit41->setMaximumWidth(InputBoxMaxLength);
    tmpString = codec->toUnicode("arcsec");
    symble41 = new QLabel(tmpString);

    layout->addWidget(label41, 0, 0);
    layout->addWidget(lineEdit41, 0, 1);
    layout->addWidget(symble41, 0, 2);
    //layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);

    gridGroupBox4->setLayout(layout);
}

//sky background module
void Dialog::createGridGroupBox5()
{
    tmpString = codec->toUnicode("天光背景模型");
    gridGroupBox5 = new QGroupBox(tmpString);
    QGridLayout *layout = new QGridLayout;
    layout->setVerticalSpacing(WidgetVerticalSpacing);
    layout->setContentsMargins(LayoutContentsMargin,LayoutContentsMarginTop,LayoutContentsMargin,LayoutContentsMargin);

    tmpString = codec->toUnicode("黄道光");
    checkBox51 = new QCheckBox(tmpString);
    tmpString = codec->toUnicode("地表反射光");
    checkBox52 = new QCheckBox(tmpString);
    tmpString = codec->toUnicode("宇宙射线");
    checkBox53 = new QCheckBox(tmpString);
    /*
    tmpString = codec->toUnicode("理论模型");
    radioButton61 = new QRadioButton(tmpString);
    tmpString = codec->toUnicode("实测模型");
    radioButton62 = new QRadioButton(tmpString);
    */

    layout->addWidget(checkBox51, 0, 0);
    layout->addWidget(checkBox52, 0, 1);
    layout->addWidget(checkBox53, 0, 2);

    layout->setColumnStretch(2, 20);

    gridGroupBox5->setLayout(layout);
}

//Object distribute module
void Dialog::createGridGroupBox6()
{
    tmpString = codec->toUnicode("目标天体参数");
    gridGroupBox6 = new QGroupBox(tmpString);
    QGridLayout *layout = new QGridLayout;
    layout->setVerticalSpacing(WidgetVerticalSpacing);
    layout->setContentsMargins(LayoutContentsMargin,LayoutContentsMarginTop,LayoutContentsMargin,LayoutContentsMargin);


    tmpString = codec->toUnicode("展源目标类型：");
    label61 = new QLabel(tmpString);
    comboBox61 = new QComboBox;
    comboBox61->setMaximumWidth(InputBoxMaxLength);
    tmpString = codec->toUnicode("星系");
    comboBox61->addItem(tmpString);
    tmpString = codec->toUnicode("行星状星云");
    comboBox61->addItem(tmpString);
    tmpString = codec->toUnicode("反射星云");
    comboBox61->addItem(tmpString);
    tmpString = codec->toUnicode("轻II区");
    comboBox61->addItem(tmpString);
    tmpString = codec->toUnicode("PDR区");
    comboBox61->addItem(tmpString);

    tmpString = codec->toUnicode("目标亮度（wise-w1）：");
    label62 = new QLabel(tmpString);
    lineEdit62 = new QLineEdit;
    lineEdit62->setMaximumWidth(InputBoxMaxLength);
    tmpString = codec->toUnicode("mag/arcsec2");
    unit62 = new QLabel(tmpString);

    tmpString = codec->toUnicode("ExtModel+qPAH：");
    label63 = new QLabel(tmpString);
    comboBox63 = new QComboBox;
    tmpString = codec->toUnicode("MW3.1_00(0.47)");
    comboBox63->addItem(tmpString);
    tmpString = codec->toUnicode("MW3.1_10(1.12)");
    comboBox63->addItem(tmpString);
    tmpString = codec->toUnicode("MW3.1_20(1.77)");
    comboBox63->addItem(tmpString);
    tmpString = codec->toUnicode("MW3.1_30(2.50)");
    comboBox63->addItem(tmpString);
    tmpString = codec->toUnicode("MW3.1_40(3.19)");
    comboBox63->addItem(tmpString);
    tmpString = codec->toUnicode("MW3.1_50(3.90)");
    comboBox63->addItem(tmpString);
    tmpString = codec->toUnicode("MW3.1_60(4.58)");
    comboBox63->addItem(tmpString);
    tmpString = codec->toUnicode("LMC2_00(0.75)");
    comboBox63->addItem(tmpString);
    tmpString = codec->toUnicode("LMC2_05(1.49)");
    comboBox63->addItem(tmpString);
    tmpString = codec->toUnicode("LMC2_10(2.37)");
    comboBox63->addItem(tmpString);
    tmpString = codec->toUnicode("smc(0.10)");
    comboBox63->addItem(tmpString);

    tmpString = codec->toUnicode("");
    label64 = new QLabel(tmpString);
    tmpString = codec->toUnicode("u_single");
    checkBox64 = new QCheckBox(tmpString);
    checkBox64->setLayoutDirection(Qt::RightToLeft);

    tmpString = codec->toUnicode("umin：");
    label65 = new QLabel(tmpString);
    comboBox65 = new QComboBox;
    tmpString = codec->toUnicode("0.10");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("0.15");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("0.20");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("0.30");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("0.40");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("0.50");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("0.70");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("0.80");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("1.00");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("1.20");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("1.50");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("2.00");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("2.50");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("3.00");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("4.00");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("5.00");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("7.00");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("8.00");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("10.0");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("12.0");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("15.0");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("20.0");
    comboBox65->addItem(tmpString);
    tmpString = codec->toUnicode("25.0");
    comboBox65->addItem(tmpString);

    tmpString = codec->toUnicode("umax：");
    label66 = new QLabel(tmpString);
    comboBox66 = new QComboBox;
    comboBox66->setMinimumWidth(100);
    tmpString = codec->toUnicode("1e3");
    comboBox66->addItem(tmpString);
    tmpString = codec->toUnicode("1e4");
    comboBox66->addItem(tmpString);
    tmpString = codec->toUnicode("1e5");
    comboBox66->addItem(tmpString);
    tmpString = codec->toUnicode("1e6");
    comboBox66->addItem(tmpString);
    tmpString = codec->toUnicode("1e7");
    comboBox66->addItem(tmpString);

    tmpString = codec->toUnicode("PAHTempFile：");
    label67 = new QLabel(tmpString);
    lineEdit67 = new QLineEdit;
    tmpString = codec->toUnicode("无匹配文件");
    lineEdit67->setText(tmpString);
    lineEdit67->setReadOnly(true);

    layout->addWidget(label61,    0, 0);
    layout->addWidget(comboBox61, 0, 1);
    layout->addWidget(label62,    0, 2);
    layout->addWidget(lineEdit62, 0, 3);
    layout->addWidget(unit62,     0, 4);

    layout->addWidget(label63,    1, 0);
    layout->addWidget(comboBox63, 1, 1);
    layout->addWidget(label65,    1, 2);
    layout->addWidget(comboBox65, 1, 3);
    layout->addWidget(label66,    1, 5);
    layout->addWidget(comboBox66, 1, 6);

    //layout->addWidget(label64,    2, 0);
    layout->addWidget(checkBox64, 2, 1);
    //void	addWidget(QWidget * widget, int fromRow, int fromColumn, int rowSpan, int columnSpan, Qt::Alignment alignment = 0)
    layout->addWidget(label67,    2, 2);
    layout->addWidget(lineEdit67, 2, 3, 1, 2);

    connect(checkBox64, SIGNAL(clicked()), this, SLOT(slotCheckBox64()));
    connect(comboBox63, SIGNAL(activated(int)), this, SLOT(slotSetValueEdit67()));
    connect(comboBox65, SIGNAL(activated(int)), this, SLOT(slotSetValueEdit67()));
    connect(comboBox66, SIGNAL(activated(int)), this, SLOT(slotSetValueEdit67()));

    //layout->setColumnStretch(1, 20);

    gridGroupBox6->setLayout(layout);
}

//output type select
void Dialog::createGridGroupBox7()
{
    tmpString = codec->toUnicode("输出类型选择");
    gridGroupBox7 = new QGroupBox(tmpString);
    QGridLayout *layout = new QGridLayout;
    layout->setVerticalSpacing(WidgetVerticalSpacing);
    layout->setContentsMargins(LayoutContentsMargin,LayoutContentsMarginTop,LayoutContentsMargin,LayoutContentsMargin);

    tmpString = codec->toUnicode("输出类型：");
    label71 = new QLabel(tmpString);
    comboBox71 = new QComboBox;
    comboBox71->setMaximumWidth(InputBoxMaxLength);
    tmpString = codec->toUnicode("仅图像输出");
    comboBox71->addItem(tmpString);
    tmpString = codec->toUnicode("仅灵敏度输出");
    comboBox71->addItem(tmpString);
    tmpString = codec->toUnicode("二者同时输出");
    comboBox71->addItem(tmpString);
    label72 = new QLabel("");

    layout->addWidget(label71, 0, 0);
    layout->addWidget(comboBox71, 0, 1);
    layout->addWidget(label72, 0, 2);

    layout->setColumnStretch(2, 20);

    gridGroupBox7->setLayout(layout);
}

void Dialog::slotOpenFile21()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit22->setText(fileName);
//    QMessageBox msgBox;
//    msgBox.setText("Get File name:");
//    msgBox.setInformativeText("File Name is:"+fileName);
//    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
//    msgBox.setDefaultButton(QMessageBox::Save);
//    int ret = msgBox.exec();
}

void Dialog::slotOpenFile22()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit23->setText(fileName);
}

void Dialog::slotOpenFile23()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit24->setText(fileName);
}

void Dialog::slotOpenFile24()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit25->setText(fileName);
}

void Dialog::slotOpenFile32()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit32->setText(fileName);
}

void Dialog::slotOpenFile33()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit33->setText(fileName);
}

void Dialog::slotOpenFile34()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit34->setText(fileName);
}

void Dialog::slotOpenFile35()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit35->setText(fileName);
}

void Dialog::slotOpenFile36()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit36->setText(fileName);
}

void Dialog::slotOpenFile37()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit37->setText(fileName);
}

void Dialog::slotOpenFile39()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit39->setText(fileName);
}

void Dialog::slotOpenFile310()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit310->setText(fileName);
}

void Dialog::slotOpenFile311()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit311->setText(fileName);
}

void Dialog::slotOpenFile312()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit312->setText(fileName);
}

void Dialog::slotOpenFile313()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit313->setText(fileName);
}

void Dialog::slotOpenFile314()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    lineEdit314->setText(fileName);
}

void Dialog::createButtonBox()
{

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void Dialog::slotCheckBox64()
{
    if(checkBox64->isChecked())
    {
        comboBox66->setEnabled(false);
    }else{
        comboBox66->setEnabled(true);
    }
    slotSetValueEdit67();
}

void Dialog::slotSetValueEdit67()
{
    QString tmpFileName("U");
    if(checkBox64->isChecked())
    {
        QString comboBox63Value = comboBox63->currentText();
        QString comboBox65Value = comboBox65->currentText();
        comboBox63Value.remove(QRegExp("\\(\\d.\\d{2}\\)"));
        comboBox65Value.append("_");
        tmpFileName.append(comboBox65Value).append(comboBox65Value).append(comboBox63Value).append(".fits");
    }else{
        QString comboBox63Value = comboBox63->currentText();
        QString comboBox65Value = comboBox65->currentText();
        QString comboBox66Value = comboBox66->currentText();
        comboBox63Value.remove(QRegExp("\\(\\d.\\d{2}\\)"));
        comboBox65Value.append("_");
        comboBox66Value.append("_");
        tmpFileName.append(comboBox65Value).append(comboBox66Value).append(comboBox63Value).append(".fits");
    }
    if(hasSameFileName(tmpFileName))
    {
        lineEdit67->setText(tmpFileName);
    }else{
        tmpString = codec->toUnicode("无匹配文件");
        lineEdit67->setText(tmpString);
    }
}

bool Dialog::loadObjectParameterFileNames()
{
    QFile qfile(ObjectParameterFile);
    if (!qfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&qfile);
    QString line = in.readLine();
    while (!line.isNull()) {
        fileNameList.append(line);
        line = in.readLine();
    }

    return true;
}


bool Dialog::hasSameFileName(QString tmpFileName)
{
    bool findName = false;
    for (int i = 0; i < fileNameList.size(); ++i) {
        if (fileNameList.at(i) == tmpFileName)
        {
            findName = true;
            break;
        }
    }

    return findName;
}
