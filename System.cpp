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

#include "System.h"

#include <QVector2D>
#include <QVector3D>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

#include <QDebug>

static const u8 deltaTime = 1;

GLfloat* System::g_particule_position_size_data = new GLfloat[MAX_PARTICLES * 4];
GLubyte* System::g_particule_color_data         = new GLubyte[MAX_PARTICLES * 4];


struct VertexData
{
    QVector3D position;
    QVector3D color;
};




VertexData vertices[] = {
    {QVector3D(0.0f, 0.0f, 0.0f), QVector3D(1.0f, 0.0f,0.0f)},
    {QVector3D(1.0f, 0.0f, 0.0f), QVector3D(1.0f, 0.0f,0.0f)},
    {QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 1.0f,0.0f)},
    {QVector3D(0.0f, 1.0f, 0.0f), QVector3D(0.0f, 1.0f,0.0f)},
    {QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 0.0f,1.0f)},
    {QVector3D(0.0f, 0.0f, 1.0f), QVector3D(0.0f, 0.0f,1.0f)},
};

const int nbrVertices = 6;

GLushort indices[] = {
    0,1,
    2,3,
    4,5
};

const int nbrIndices = 6;


//! [0]
System::System():
    m_gravity(1),
    m_wind(),
    m_atmDensityFactor(1),
    m_particleNb(),
    indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();

    // Generate 2 VBOs
    arrayBuf.create();
    indexBuf.create();

    // Initializes cube geometry and transfers it to VBOs
    initGeometry();
}

System::~System()
{
    arrayBuf.destroy();
    indexBuf.destroy();
}
//! [0]

void System::initGeometry()
{
////! [1]
///

    /* initialize random seed: */
    srand (time(NULL));



    //Not useful anymore
    /*
    for(int i = 0; i < MaxPrticles; i++){
        f32 test1 = ((f32)rand()/RAND_MAX)*6-3;
        f32 test2 = ((f32)rand()/RAND_MAX)*6-3;
        f32 test3 = ((f32)rand()/RAND_MAX)*6-3;


        QVector3D* p; u8 s; u16 l; u8 a; f32 d;
        p = new QVector3D(test1,test2,test3);          //position

        s = 1;                                      //size
        l = 125;                                    //lifeTime
        a = 1;                                      //alpha
        d = 1;                                      //density

        Smoke* temp = new Smoke(p,s,l,a,d);

        m_particleVector.push_back(temp);
    }*/


    // Transfer vertex data to VBO 0
    arrayBuf.bind();
    arrayBuf.allocate(vertices, System::MAX_PARTICLES * sizeof(VertexData));

    // Transfer index data to VBO 1
    indexBuf.bind();
    indexBuf.allocate(indices, nbrIndices * sizeof(GLushort));





    //////////////////////////////////PARTIE TEST
    ///

    // The VBO containing the 4 vertices of the particles.
    // Thanks to instancing, they will be shared by all particles.
    static const GLfloat g_vertex_buffer_data[] = {
     -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     -0.5f, 0.5f, 0.0f,
     0.5f, 0.5f, 0.0f,
    };

    glGenBuffers(1, &billboard_vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    // The VBO containing the positions and sizes of the particles
    glGenBuffers(1, &particles_position_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
    // Initialize with empty (NULL) buffer : it will be updated later, each frame.
    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * 4 * sizeof(GLfloat), NULL, GL_STREAM_DRAW);


    // The VBO containing the colors of the particles
    glGenBuffers(1, &particles_color_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
    // Initialize with empty (NULL) buffer : it will be updated later, each frame.
    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * 4 * sizeof(GLubyte), NULL, GL_STREAM_DRAW);




//! [1]
}

//! [2]
void System::drawGeometry(QOpenGLShaderProgram *program)
{
    /*
    // Tell OpenGL which VBOs to use
    arrayBuf.bind();
    indexBuf.bind();


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
    glDrawElements(GL_LINES, 6, GL_UNSIGNED_SHORT, 0);
    */



    /*

    //////////Test
    // Update the buffers that OpenGL uses for rendering.
    // There are much more sophisticated means to stream data from the CPU to the GPU,
    // but this is outside the scope of this tutorial.
    // http://www.opengl.org/wiki/Buffer_Object_Streaming


    glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
    glBufferData(GL_ARRAY_BUFFER, System::MaxPrticles * 4 * sizeof(GLfloat), NULL, GL_STREAM_DRAW); // Buffer orphaning, a common way to improve streaming perf. See above link for details.
    glBufferSubData(GL_ARRAY_BUFFER, 0, ParticlesCount * sizeof(GLfloat) * 4, g_particule_position_size_data);

    glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
    glBufferData(GL_ARRAY_BUFFER, System::MaxPrticles * 4 * sizeof(GLubyte), NULL, GL_STREAM_DRAW); // Buffer orphaning, a common way to improve streaming perf. See above link for details.
    glBufferSubData(GL_ARRAY_BUFFER, 0, ParticlesCount * sizeof(GLubyte) * 4, g_particule_color_data);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

/*
    // Use our shader
    glUseProgram(program);

    // Bind our texture in Texture Unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, Texture);
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(TextureID, 0);

    // Same as the billboards tutorial
    glUniform3f(CameraRight_worldspace_ID, ViewMatrix[0][0], ViewMatrix[1][0], ViewMatrix[2][0]);
    glUniform3f(CameraUp_worldspace_ID   , ViewMatrix[0][1], ViewMatrix[1][1], ViewMatrix[2][1]);

    glUniformMatrix4fv(ViewProjMatrixID, 1, GL_FALSE, &ViewProjectionMatrix[0][0]);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, billboard_vertex_buffer);
    glVertexAttribPointer(
        0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : positions of particles' centers
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, particles_position_buffer);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        4,                                // size : x + y + z + size => 4
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );

    // 3rd attribute buffer : particles' colors
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, particles_color_buffer);
    glVertexAttribPointer(
        2,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        4,                                // size : r + g + b + a => 4
        GL_UNSIGNED_BYTE,                 // type
        GL_TRUE,                          // normalized?    *** YES, this means that the unsigned char[4] will be accessible with a vec4 (floats) in the shader ***
        0,                                // stride
        (void*)0                          // array buffer offset
    );

    // These functions are specific to glDrawArrays*Instanced*.
    // The first parameter is the attribute buffer we're talking about.
    // The second parameter is the "rate at which generic vertex attributes advance when rendering multiple instances"
    // http://www.opengl.org/sdk/docs/man/xhtml/glVertexAttribDivisor.xml
    glVertexAttribDivisor(0, 0); // particles vertices : always reuse the same 4 vertices -> 0
    glVertexAttribDivisor(1, 1); // positions : one per quad (its center)                 -> 1
    glVertexAttribDivisor(2, 1); // color : one per quad                                  -> 1



    // Draw the particules !
    // This draws many times a small triangle_strip (which looks like a quad).
    // This is equivalent to :
    // for(i in ParticlesCount) : glDrawArrays(GL_TRIANGLE_STRIP, 0, 4),
    // but faster.
    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, ParticlesCount);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    */

    ////// NEW TEST
    ///

    int ParticlesCount = m_particleVector.size();
    VertexData vertices[ParticlesCount];
    for(int i =0; i < ParticlesCount; i++){
       vertices[i]= {m_particleVector.at(i)->getM_position(),m_particleVector.at(i)->getM_color()};
    }



   /* VertexData vertices[] = {
        {QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 1.0f,0.0f)},
        {QVector3D(1.0f, 0.0f, 0.0f), QVector3D(0.0f, 1.0f,0.0f)},
        {QVector3D(0.0f, 0.0f, 0.0f), QVector3D(1.0f, 0.0f,0.0f)},
        {QVector3D(0.0f, 1.0f, 0.0f), QVector3D(1.0f, 0.0f,0.0f)},
        {QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 0.0f,1.0f)},
        {QVector3D(0.0f, 0.0f, 1.0f), QVector3D(0.0f, 0.0f,1.0f)},
    };*/

    // Tell OpenGL which VBOs to use
    arrayBuf.bind();
    arrayBuf.allocate(vertices, MAX_PARTICLES * sizeof(VertexData));
    indexBuf.bind();


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
    //glDrawElements(GL_LINES, 6, GL_UNSIGNED_SHORT, 0);
    glPointSize(2.0);
    glDrawArrays(GL_POINTS, 0, System::MAX_PARTICLES);

}
//! [2]

void System::start_system(){
}

/**
 * @return float
 */
f32 System::getM_atmDensityFactor() {
    return m_atmDensityFactor;
}

/**
 * @param value
 */
void System::setM_atmDensityFactor(f32 value) {

    m_atmDensityFactor = value;
}

/**
 * @return u16
 */
u16 System::getM_particleNb() {
    return m_particleNb;
}

/**
 * @param value
 */
void System::setM_particleNb(u16 value) {
    m_particleNb = value;

}


/**
 * @param value
 */
void System::setM_windFactor(f32 factor) {
    m_wind.setM_factor(factor);
}

/**
 * @param value
 */
void System::setM_gravity(f32 factor) {
    m_gravity.setM_gravity_factor(factor);
}

void System::change_wind(QVector3D * vec) {

    m_wind.setM_translation(vec);

}


/**
 * TODO
 * updates all particles taking into account all the forces and the lifetime
 */
void System::update_particles(s32 pRefresh_delay_s32)
{

    clean_system();

    int nb_particles = m_particleVector.size();

    QVector3D wind = m_wind.getM_translation() * m_wind.getM_factor() ;    

    f32 atm_density = ATM_DENSITY*m_atmDensityFactor;

    for(int i = 0; i < nb_particles;   i++){

        Particle* part = m_particleVector.at(i);

        QVector3D density = QVector3D(0,-1,0)*(part->getM_density()-atm_density);

        qDebug() << density;

        part->reduce_lifeTime(pRefresh_delay_s32);

        // Simulate simple physics : gravity only, no collisions
        QVector3D newSpeed = part->getM_speed() + (m_gravity.getM_gravity() + wind + density) * pRefresh_delay_s32 * 0.000001f;
        part->setM_speed(&newSpeed);
        QVector3D newPos = (part->getM_position() + part->getM_speed() * pRefresh_delay_s32);
        part->setM_position(&newPos);


    }

    int nb_missing_particles =  MAX_PARTICLES-nb_particles;
    if(nb_missing_particles > 15){
        nb_missing_particles = 15;
    }

    //TODO make the particle factory outside of this
    for(int i = 0; i < nb_missing_particles; i++){
        f32 test1 = ((f32)rand()/RAND_MAX)*6-3;
        f32 test2 = ((f32)rand()/RAND_MAX)*6-3;
        f32 test3 = ((f32)rand()/RAND_MAX)*6-3;


        QVector3D* p; u8 s; u16 l; u8 a; f32 d;
        p = new QVector3D(test1,test2,test3);          //position

        s = 1;                                      //size
        l = 5000;                                    //lifeTime
        a = 1;                                      //alpha
        d = 0.2;                                      //density

        Smoke* temp = new Smoke(p,s,l,a,d);

        m_particleVector.push_back(temp);
    }

}


void System::clean_system(){


    for(int i = m_particleVector.size()-1; i >= 0;   i--){

        Particle* part = m_particleVector.at(i);

        if(part->getM_lifeTime() < 1){
            m_particleVector.remove(i);
            delete part;
        }
    }
}
