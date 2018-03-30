/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwidget.h"

#include <QMouseEvent>

#include <math.h>

MainWidget::MainWidget(QWidget *parent) :
    QOpenGLWidget(parent),
    geometries(0),
    angularSpeed(0),
    head(0),
    body(0),
    leftArm(0),
    rightArm(0),
    leftLeg(0),
    rightLeg(0)
{

    setMinimumHeight(1000);
    setMinimumWidth(1000);
}

MainWidget::~MainWidget()
{
    // Make sure the context is current when deleting the texture
    // and the buffers.
    makeCurrent();
    delete geometries;
    doneCurrent();
}

//! [0]
void MainWidget::mousePressEvent(QMouseEvent *e)
{
    // Save mouse press position
    mousePressPosition = QVector2D(e->localPos());
}

void MainWidget::mouseReleaseEvent(QMouseEvent *e)
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
void MainWidget::timerEvent(QTimerEvent *)
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

void MainWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

   // glEnable(GL_CULL_FACE);

    initShaders();

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable back face culling
    glEnable(GL_CULL_FACE);


    geometries = new GeometryEngine;
    head =       new Cube(2.0,2.0,2.0,    {116.0/255.0, 72.0/255.0, 55.0/255.0});

    // Not optimized : you should instance only 1 cube, and change the model matrix
    // this methode will instanciate 8 vbo * nb(vbo in cube) instead of nb(vbo in cube)
    body =       new Cube(3.0,5.0,2.0,    {0,147.0/255.0,0});
    leftArm =    new Cube(1.0,4.0,1.0,    {0,147.0/255.0,0});
    rightArm =   new Cube(1.0,4.0,1.0,    {0,147.0/255.0,0});
    leftLeg =    new Cube(1.0,5.0,1.0,    {0,0,147.0/255.0});
    rightLeg =   new Cube(1.0,5.0,1.0,    {0,0,147.0/255.0});

    // Use QBasicTimer because its faster than QTimer
    timer.start(12, this);
}

//! [3]
void MainWidget::initShaders()
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
void MainWidget::resizeGL(int w, int h)
{
    // Calculate aspect ratio
    qreal aspect = qreal(w) / qreal(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 0.1, zFar = 50.0, fov = 45.0;

    // Set view matrix
    view.setToIdentity();
    view.translate({0,-10,-30});

    // Reset projection
    projection.setToIdentity();
    // Set perspective projection matrix
    projection.perspective(fov, aspect, zNear, zFar);
}
//! [5]

void MainWidget::paintGL()
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
    geometries->drawGeometry(&program);


    QMatrix4x4 matrixHead;
    matrixHead.translate(5.0, 10, 0);
    program.setUniformValue("mvp", humanoide * matrixHead);
    head->drawGeometry(&program);

    QMatrix4x4 matrixBody;
    matrixBody.translate(5.0, 5.5, 0);
    program.setUniformValue("mvp", humanoide * matrixBody);
    body->drawGeometry(&program);

    QMatrix4x4 matrixRightLeg;
    matrixRightLeg.translate(6.0, 0.0, 0);
    program.setUniformValue("mvp", humanoide * matrixRightLeg);
    rightLeg->drawGeometry(&program);

    QMatrix4x4 matrixLeftLeg;
    matrixLeftLeg.translate(4.0, 0.0, 0);
    program.setUniformValue("mvp", humanoide * matrixLeftLeg);
    leftLeg->drawGeometry(&program);

    QMatrix4x4 matrixRightArm;
    matrixRightArm.translate(7.5, 5.5, 0);
    program.setUniformValue("mvp", humanoide * matrixRightArm);
    rightArm->drawGeometry(&program);

    QMatrix4x4 matrixLeftArm;
    matrixLeftArm.translate(2.5, 5.5, 0);
    program.setUniformValue("mvp", humanoide * matrixLeftArm );
    leftArm->drawGeometry(&program);

}
