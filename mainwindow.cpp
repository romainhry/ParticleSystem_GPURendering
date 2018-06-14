#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderwidget.h"
#include <QVector3D>
#include <thread>
#include "enum.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->horizontalLayout->insertWidget(0,&m_render,1,0);


    m_system = m_render.getM_system();
}


MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_slider_gravity_ui_valueChanged(int value)
{
    f32 newValue = (f32)value /10;
    ui->spinBox_gravity_ui->setValue(newValue);
    m_render.setM_gravity(newValue);
}

void MainWindow::on_spinBox_gravity_ui_valueChanged(f64 arg1)
{
    f32 newValue = arg1 * 10;
    ui->slider_gravity_ui->setValue(newValue);
    m_render.setM_gravity(newValue);
}

void MainWindow::on_slider_atm_factor_ui_valueChanged(int value)
{
    f32 newValue = (f32)value /10;
    ui->spinBox_atm_factor_ui->setValue(newValue);
    m_render.setM_atmDensityFactor(newValue);
}

void MainWindow::on_spinBox_atm_factor_ui_valueChanged(f64 arg1)
{
    f32 newValue = arg1 * 10;
    ui->slider_atm_factor_ui->setValue(newValue);
    m_render.setM_atmDensityFactor(newValue);

}


void MainWindow::on_slider_wind_x_ui_valueChanged(int value)
{
    f32 newValue = (f32)value /10;
    ui->spinBox_wind_x_ui->setValue(newValue);
    m_render.change_wind(new QVector3D(newValue,
                                        ui->spinBox_wind_y_ui->value(),
                                        ui->spinBox_wind_z_ui->value()));
}

void MainWindow::on_spinBox_wind_x_ui_valueChanged(f64 arg1)
{
    f32 newValue = arg1 * 10;
    ui->slider_wind_x_ui->setValue(newValue);
    m_render.change_wind(new QVector3D(arg1,
                                        ui->spinBox_wind_y_ui->value(),
                                        ui->spinBox_wind_z_ui->value()));
}

void MainWindow::on_slider_wind_y_ui_valueChanged(int value)
{
    f32 newValue = (f32)value /10;
    ui->spinBox_wind_y_ui->setValue(newValue);
    m_render.change_wind(new QVector3D(ui->spinBox_wind_x_ui->value(),
                                        newValue,
                                        ui->spinBox_wind_z_ui->value()));
}

void MainWindow::on_spinBox_wind_y_ui_valueChanged(f64 arg1)
{
    f32 newValue = arg1 * 10;
    ui->slider_wind_y_ui->setValue(newValue);
    m_render.change_wind(new QVector3D(ui->spinBox_wind_x_ui->value(),
                                        arg1,
                                        ui->spinBox_wind_z_ui->value()));
}

void MainWindow::on_slider_wind_z_ui_valueChanged(int value)
{
    f32 newValue = (f32)value /10;
    ui->spinBox_wind_z_ui->setValue(newValue);
     m_render.change_wind(new QVector3D(ui->spinBox_wind_x_ui->value(),
                                         ui->spinBox_wind_y_ui->value(),
                                         newValue));
}

void MainWindow::on_spinBox_wind_z_ui_valueChanged(f64 arg1)
{
    f32 newValue = arg1 * 10;
    ui->slider_wind_z_ui->setValue(newValue);
    m_render.change_wind(new QVector3D(ui->spinBox_wind_x_ui->value(),
                                        ui->spinBox_wind_y_ui->value(),
                                        arg1));
}

void MainWindow::on_slider_wind_strength_ui_valueChanged(int value)
{
    f32 newValue = (f32)value /10;
    ui->spinBox_wind_strength_ui->setValue(newValue);
    m_render.setM_windFactor(newValue);
}

void MainWindow::on_spinBox_wind_strength_ui_valueChanged(f64 arg1)
{
    f32 newValue = arg1 * 10;
    ui->slider_wind_strength_ui->setValue(newValue);

    m_render.setM_windFactor(arg1);
}

void MainWindow::on_slider_wind_rotate_ui_valueChanged(int value)
{
    //m_system->setM_windRotation(value);
    m_render.setM_windRotation(value);
    ui->spinBox_wind_rotate_ui->setValue(value);
}

void MainWindow::on_spinBox_wind_rotate_ui_valueChanged(double arg1)
{
    //m_system->setM_windRotation((u16)arg1);
    m_render.setM_windRotation((u16)arg1);
    ui->slider_wind_rotate_ui->setValue((int)arg1);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    m_system->setParticleType((Particle_type)index);
}

void MainWindow::on_pushButton_clicked()
{

    m_render.startRendering();
    ui->pushButton->hide();
}


