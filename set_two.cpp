#include "set_two.h"
#include "ui_set_two.h"

Set_two::Set_two(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Set_two)
{
    ui->setupUi(this);
    setWindowTitle("小鸟消消乐");
    setWindowIcon(QIcon(":/resorce/icon.ico"));

    soundEffect = new QSoundEffect(this);
    soundEffect->setSource(QUrl::fromLocalFile(":/resorce/Button_music.wav")); // 设置音效文件的资源路径
    // 可选：设置音量
    soundEffect->setVolume(1.0);  // 设置音量，范围为0.0到1.0

    ui->Slider_1->setRange(0, 100);
    ui->Slider_1->setValue(50);
    ui->Box_1->setRange(0, 100);
    ui->Box_1->setValue(50);
    connect(ui->Slider_1, &QSlider::valueChanged, ui->Box_1, &QSpinBox::setValue);
    connect(ui->Box_1, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),ui->Slider_1, &QSlider::setValue);
    ui->Slider_2->setRange(0, 100);
    ui->Slider_2->setValue(50);
    ui->Box_2->setRange(0, 100);
    ui->Box_2->setValue(50);
    connect(ui->Slider_2, &QSlider::valueChanged, ui->Box_2, &QSpinBox::setValue);
    connect(ui->Box_2, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),ui->Slider_2, &QSlider::setValue);
}

Set_two::~Set_two()
{
    delete ui;
}

void Set_two::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pixmap(":/resorce/bg.png");
    painter.drawPixmap(rect(), pixmap);
}

void Set_two::on_Button_main_clicked()
{
    soundEffect->play();
    emit this->back();
}


void Set_two::on_Slider_1_sliderMoved(int position)
{
    emit this->Music_1(position);
}


void Set_two::on_Slider_2_sliderMoved(int position)
{
    emit this->Music_2(position);
}

