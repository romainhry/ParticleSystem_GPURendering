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

#include "cube.h"
#include "vertexdata.h"

#include <QVector2D>
#include <QVector3D>





//! [0]
Cube::Cube(float pWidth_fl,float pLength_fl,float pDepth_fl, QVector3D pColor_v3)
    : index1Buf(QOpenGLBuffer::IndexBuffer), index2Buf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();

    this->width = pWidth_fl/2.0;
    this->length = pLength_fl/2.0;
    this->depth = pDepth_fl/2.0;
    color = pColor_v3;


    // Generate 3 VBOs
    arrayBuf.create();
    index1Buf.create();
    index2Buf.create();

    // Initializes cube geometry and transfers it to VBOs
    initGeometry();
}

Cube::~Cube()
{
    arrayBuf.destroy();
    index1Buf.destroy();
    index2Buf.destroy();
}
//! [0]

void Cube::initGeometry()
{
    VertexData vertices[] = {
        {QVector3D(-width, -length, -depth),    color}, // V0
        {QVector3D(width, -length, -depth),   color}, // V1
        {QVector3D(-width, length, -depth),  color}, // V2
        {QVector3D(-width, -length, depth),   color}, // V3
        {QVector3D(width, length, -depth), color}, // V4
        {QVector3D(width, -length, depth),  color}, // V5
        {QVector3D(-width, length, depth), color}, // V6
        {QVector3D(width, length, depth),color}  // V7
    };

    int nbrVertices = 8;

    GLushort indices1[] = {
        0,1,4,2,6,3,5,1
    };

    GLushort indices2[] = {
        7,6,3,5,1,4,2,6
    };

    int nbrIndices = 8;

    // Transfer vertex data to VBO 0
    arrayBuf.bind();
    arrayBuf.allocate(vertices, nbrVertices * sizeof(VertexData));

    // Transfer index data to VBO 1
    index1Buf.bind();
    index1Buf.allocate(indices1, nbrIndices * sizeof(GLushort));

    // Transfer index data to VBO 2
    index2Buf.bind();
    index2Buf.allocate(indices2, nbrIndices * sizeof(GLushort));
}

//! [2]
void Cube::drawGeometry(QOpenGLShaderProgram *program)
{
    // Tell OpenGL which VBOs to use
    arrayBuf.bind();
    index1Buf.bind();

    // Offset for position
    quintptr offset = 0;

    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = program->attributeLocation("position");
    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    // Offset for texture coordinate
    offset += sizeof(QVector3D);

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
    int colorLocation = program->attributeLocation("color");
    program->enableAttributeArray(colorLocation);
    program->setAttributeBuffer(colorLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    // Draw cube geometry using indices from VBO 1
    glFrontFace(GL_CW);
    glDrawElements(GL_TRIANGLE_FAN, 8, GL_UNSIGNED_SHORT, 0);

    glFrontFace(GL_CCW);
    index2Buf.bind();
    glDrawElements(GL_TRIANGLE_FAN, 8, GL_UNSIGNED_SHORT, 0);


}
//! [2]
