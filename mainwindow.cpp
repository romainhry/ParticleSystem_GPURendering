#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_slider_gravity_ui_valueChanged(int value)
{
    ui->spinBox_gravity_ui->setValue((double)value /10);
}

void MainWindow::on_spinBox_gravity_ui_valueChanged(double arg1)
{
    ui->slider_gravity_ui->setValue(arg1 * 10);
}

void MainWindow::on_slider_atm_factor_ui_valueChanged(int value)
{
    ui->spinBox_atm_factor_ui->setValue((double)value /10);
}

void MainWindow::on_spinBox_atm_factor_ui_valueChanged(double arg1)
{
    ui->slider_atm_factor_ui->setValue(arg1 * 10);
}


void MainWindow::on_slider_wind_x_ui_valueChanged(int value)
{
    ui->spinBox_wind_x_ui->setValue((double)value /10);
}

void MainWindow::on_spinBox_wind_x_ui_valueChanged(double arg1)
{
    ui->slider_wind_x_ui->setValue(arg1 * 10);
}

void MainWindow::on_slider_wind_y_ui_valueChanged(int value)
{
    ui->spinBox_wind_y_ui->setValue((double)value /10);
}

void MainWindow::on_spinBox_wind_y_ui_valueChanged(double arg1)
{
    ui->slider_wind_y_ui->setValue(arg1 * 10);
}

void MainWindow::on_slider_wind_z_ui_valueChanged(int value)
{
    ui->spinBox_wind_z_ui->setValue((double)value /10);
}

void MainWindow::on_spinBox_wind_z_ui_valueChanged(double arg1)
{
    ui->slider_wind_z_ui->setValue(arg1 * 10);
}

void MainWindow::on_slider_wind_strength_ui_valueChanged(int value)
{
    ui->spinBox_wind_strength_ui->setValue((double)value /10);
}

void MainWindow::on_spinBox_wind_strength_ui_valueChanged(double arg1)
{
    ui->slider_wind_strength_ui->setValue(arg1 * 10);
}
