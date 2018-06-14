#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "renderwidget.h"
#include "System.h"
#include "enum.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_slider_gravity_ui_valueChanged(int value);
    void on_spinBox_gravity_ui_valueChanged(double arg1);

    void on_slider_atm_factor_ui_valueChanged(int value);
    void on_spinBox_atm_factor_ui_valueChanged(double arg1);

    void on_slider_wind_x_ui_valueChanged(int value);
    void on_spinBox_wind_x_ui_valueChanged(double arg1);

    void on_slider_wind_y_ui_valueChanged(int value);
    void on_spinBox_wind_y_ui_valueChanged(double arg1);

    void on_slider_wind_z_ui_valueChanged(int value);
    void on_spinBox_wind_z_ui_valueChanged(double arg1);

    void on_slider_wind_strength_ui_valueChanged(int value);
    void on_spinBox_wind_strength_ui_valueChanged(double arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_slider_wind_rotate_ui_valueChanged(int value);

    void on_spinBox_wind_rotate_ui_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    RenderWidget m_render;
    System * m_system;
};

#endif // MAINWINDOW_H
