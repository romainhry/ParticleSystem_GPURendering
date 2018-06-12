#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H


#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QBasicTimer>
#include <QTimer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include "System.h"


class RenderWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit RenderWidget(QWidget *parent = 0);
    System * getM_system();
    ~RenderWidget();

protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void timerEvent(QTimerEvent *e) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void initShaders();
    void initTextures();

private slots:
    void animate();


private:
    QBasicTimer timer;

    QTimer animationTimer;
    QOpenGLShaderProgram program;



    QMatrix4x4 projection;
    QMatrix4x4 view;

    QVector2D mousePressPosition;
    QVector3D rotationAxis;
    qreal angularSpeed;
    QQuaternion rotation;

    System * m_system;

};

#endif // RENDERWIDGET_H
