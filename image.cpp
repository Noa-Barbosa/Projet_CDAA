#include "image.h"
#include "ui_image.h"

Image::Image(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Image)
{
    ui->setupUi(this);
}

Image::~Image()
{
    delete ui;
}

QString Image::photo()
{
    return ui->lineEdit->text();
}
