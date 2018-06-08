#include "renderwidget.h"
#include <QMouseEvent>
#include "System.h"
#include <math.h>

RenderWidget::RenderWidget(QWidget *parent) :
    QOpenGLWidget(parent),
    m_system(0),
    angularSpeed(0)

{


}

RenderWidget::~RenderWidget()
{
    // Make sure the context is current when deleting the texture
    // and the buffers.
    makeCurrent();
    //delete geometries;
    doneCurrent();
}

//! [0]
void RenderWidget::mousePressEvent(QMouseEvent *e)
{

    // Save mouse press position
    mousePressPosition = QVector2D(e->localPos());


}

void RenderWidget::mouseReleaseEvent(QMouseEvent *e)
{

    // Mouse release position - mouse press position
    QVector2D diff = QVector2D(e->localPos()) - mousePressPosition;

    // Rotation axis is perpendicular to the mouse position difference
    // vector
    QVector3D n = QVector3D(diff.y(), diff.x(), 0.0).normalized();

    // Accelerate angular speed relative to the length of the mouse sweep
    qreal acc = diff.length() / 100.0;

    // Calculate new rotation axis as weighted sum
    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();

    // Increase angular speed
    angularSpeed += acc;

}
//! [0]

//! [1]
void RenderWidget::timerEvent(QTimerEvent *)
{

    // Decrease angular speed (friction)
    angularSpeed *= 0.99;

    // Stop rotation when speed goes below threshold
    if (angularSpeed < 0.01) {
        angularSpeed = 0.0;
    } else {
        // Update rotation
        rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;

        // Request an update
        update();
    }

}
//! [1]

void RenderWidget::initializeGL()
{

    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

   // glEnable(GL_CULL_FACE);

    initShaders();

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable back face culling
    glEnable(GL_CULL_FACE);


    m_system = new System;
    // Use QBasicTimer because its faster than QTimer
    timer.start(12, this);

}

//! [3]
void RenderWidget::initShaders()
{

    // Compile vertex shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.glsl"))
        close();

    // Compile fragment shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fshader.glsl"))
        close();

    // Link shader pipeline
    if (!program.link())
        close();

    // Bind shader pipeline for use
    if (!program.bind())
        close();
}
//! [3]


// run each time the windows is resized
void RenderWidget::resizeGL(int w, int h)
{

    // Calculate aspect ratio
    qreal aspect = qreal(w) / qreal(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 0.1, zFar = 50.0, fov = 45.0;

    // Set view matrix
    view.setToIdentity();
    view.translate({0,0,-30});

    // Reset projection
    projection.setToIdentity();
    // Set perspective projection matrix
    projection.perspective(fov, aspect, zNear, zFar);
}
//! [5]

void RenderWidget::paintGL()
{

    // Clear color 0nd depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Parent matrix model , in order to applicate the same transformation to all its childs
    QMatrix4x4 humanoide;
    humanoide.rotate(rotation);
    humanoide = projection * view * humanoide;


    // Calculate model matrix
    QMatrix4x4 matrix;
    //Set modelview-projection matrix
    program.setUniformValue("mvp", humanoide * matrix);
    //Draw base geometry
    m_system->drawGeometry(&program);

}

System * RenderWidget::getM_system()
{
    return m_system;
}
