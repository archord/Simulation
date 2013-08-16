
#include <QtWidgets>
#include <QTextCodec>

#include "dialog.h"
#include "ui_dialog.h"

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


    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
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
}

//Observation strategy
void Dialog::createGridGroupBox1()
{
    tmpString = codec->toUnicode("观测策略");
    gridGroupBox1 = new QGroupBox(tmpString);
    QGridLayout *layout = new QGridLayout;

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

    tmpString = codec->toUnicode("黄道光");
    checkBox51 = new QCheckBox(tmpString);
    tmpString = codec->toUnicode("地表反射光");
    checkBox52 = new QCheckBox(tmpString);
    tmpString = codec->toUnicode("宇宙射线");
    checkBox53 = new QCheckBox(tmpString);
    layout->addWidget(checkBox51, 0, 0);
    layout->addWidget(checkBox52, 0, 1);
    layout->addWidget(checkBox53, 0, 2);

    layout->setColumnStretch(2, 20);

    gridGroupBox5->setLayout(layout);
}

//Object distribute module
void Dialog::createGridGroupBox6()
{
    tmpString = codec->toUnicode("目标天体分布模型");
    gridGroupBox6 = new QGroupBox(tmpString);
    QGridLayout *layout = new QGridLayout;

    tmpString = codec->toUnicode("理论模型");
    radioButton61 = new QRadioButton(tmpString);
    tmpString = codec->toUnicode("实测模型");
    radioButton62 = new QRadioButton(tmpString);
    layout->addWidget(radioButton61, 0, 0);
    layout->addWidget(radioButton62, 0, 1);

    layout->setColumnStretch(1, 20);

    gridGroupBox6->setLayout(layout);
}

//output type select
void Dialog::createGridGroupBox7()
{
    tmpString = codec->toUnicode("输出类型选择");
    gridGroupBox7 = new QGroupBox(tmpString);
    QGridLayout *layout = new QGridLayout;

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


