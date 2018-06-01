#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderwidget.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   // m_render = new RenderWidget();

    ui->setupUi(this);


    //ui->horizontalLayout->addWidget(&m_render,2,0);
    ui->horizontalLayout->insertWidget(0,&m_render,2,0);
     // m_render.setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    //ui->renderLayout->addStretch(10);

   // m_render.show();

    /*ui->widget = &m_render;
    ui->widget->show();*/
    //setCentralWidget(m_render);
}


MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_slider_gravity_ui_valueChanged(int value)
{
    ui->spinBox_gravity_ui->setValue((double)value /10);

    m_system.m_gravity.setM_gravity_factor((f32)value /10);
}

void MainWindow::on_spinBox_gravity_ui_valueChanged(double arg1)
{
    ui->slider_gravity_ui->setValue(arg1 * 10);
        m_system.m_gravity.setM_gravity_factor((f32)arg1 * 10);
}

void MainWindow::on_slider_atm_factor_ui_valueChanged(int value)
{
    ui->spinBox_atm_factor_ui->setValue((double)value /10);
    m_system.setM_atmDensity((f32)value /10);
}

void MainWindow::on_spinBox_atm_factor_ui_valueChanged(double arg1)
{
    ui->slider_atm_factor_ui->setValue(arg1 * 10);
    m_system.setM_atmDensity((f32)arg1 *10);

}


void MainWindow::on_slider_wind_x_ui_valueChanged(int value)
{
    ui->spinBox_wind_x_ui->setValue((double)value /10);
    //m_system.m_wind.set
}

void MainWindow::on_spinBox_wind_x_ui_valueChanged(double arg1)
{
    ui->slider_wind_x_ui->setValue(arg1 * 10);
    //m_system.m_wind.set
}

void MainWindow::on_slider_wind_y_ui_valueChanged(int value)
{
    ui->spinBox_wind_y_ui->setValue((double)value /10);
    //m_system.m_wind.set
}

void MainWindow::on_spinBox_wind_y_ui_valueChanged(double arg1)
{
    ui->slider_wind_y_ui->setValue(arg1 * 10);
}

void MainWindow::on_slider_wind_z_ui_valueChanged(int value)
{
    ui->spinBox_wind_z_ui->setValue((double)value /10);
    //m_system.m_wind.set
}

void MainWindow::on_spinBox_wind_z_ui_valueChanged(double arg1)
{
    ui->slider_wind_z_ui->setValue(arg1 * 10);
    //m_system.m_wind.set
}

void MainWindow::on_slider_wind_strength_ui_valueChanged(int value)
{
    ui->spinBox_wind_strength_ui->setValue((double)value /10);
    //m_system.m_wind.set
}

void MainWindow::on_spinBox_wind_strength_ui_valueChanged(double arg1)
{
    ui->slider_wind_strength_ui->setValue(arg1 * 10);
    //m_system.m_wind.set
}
