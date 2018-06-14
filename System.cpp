#include "System.h"

#include <QVector2D>
#include <QVector3D>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <QDebug>
#include <random>

#include "enum.h"
#include "typedef.h"
#include "Model/Fire.h"
#include "Model/Smoke.h"
#include "Model/Water.h"
#include "Model/Classic.h"
#include "Model/Wind.h"
#include "Model/Gravity.h"



GLfloat* System::g_particule_position_size_data = new GLfloat[MAX_PARTICLES * 4];
GLubyte* System::g_particule_color_data         = new GLubyte[MAX_PARTICLES * 4];

Particle_type System::m_particle_type = classical;


struct VertexData
{
    QVector3D position;
    QVector3D color;
};


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

//! [1]
}

//! [2]
void System::drawGeometry(QOpenGLShaderProgram *program)
{


    int ParticlesCount = m_particleVector.size();
    VertexData vertices[ParticlesCount];
    for(int i =0; i < ParticlesCount; i++){
       vertices[i]= {m_particleVector.at(i)->getM_position(),m_particleVector.at(i)->getM_color()};
    }

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

    glPointSize(2.0);
    glDrawArrays(GL_POINTS, 0, System::MAX_PARTICLES);

}
//! [2]


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
    Particle* temp;
    QVector3D* position;
    QVector3D* color;
    f32 density;
    u16 lifeTime;
    u8 size;
    u8 alpha;

    clean_system();

    int nb_particles = m_particleVector.size();

    QVector3D wind = m_wind.getM_translation() * m_wind.getM_factor() ;    
    f32 atm_density = ATM_DENSITY*m_atmDensityFactor;


    //Calculations for the screw
    QMatrix4x4 rotation_matrix;
    rotation_matrix.setToIdentity();
    int rotation_angle = m_wind.getM_angle();
    if( rotation_angle > 0 && rotation_angle < 360){
        rotation_matrix.setToIdentity();
        rotation_matrix.rotate(rotation_angle * m_wind.getM_factor() * 0.01f, m_wind.getM_translation());
    }


    for(int i = 0; i < nb_particles;   i++){

        Particle* part = m_particleVector.at(i);

        QVector3D newPos1 = rotation_matrix * part->getM_position();
        part->setM_position( &newPos1 );

        QVector3D density = QVector3D(0,-1,0)*(part->getM_density()-atm_density);

        part->reduce_lifeTime(pRefresh_delay_s32);

        // Simulate simple physics : gravity only, no collisions
        QVector3D newSpeed = part->getM_speed() + (wind + m_gravity.getM_gravity() + density) * pRefresh_delay_s32 * 0.000001f;
        part->setM_speed(&newSpeed);
        QVector3D newPos2 = (part->getM_position() + part->getM_speed() * pRefresh_delay_s32);
        part->setM_position(&newPos2);


    }

    int nb_missing_particles =  MAX_PARTICLES-nb_particles;
    if(nb_missing_particles > 700){
        nb_missing_particles = 700;
    }

    /* For gaussian distribution of the position */
    std::random_device rd;
    std::mt19937 e2(rd());
    std::normal_distribution<double> distribution(0.0,2.5);

    //TODO make the particle factory outside of this
    for(int i = 0; i < nb_missing_particles; i++){


        switch (m_particle_type) {
        case fire:

            color = new QVector3D(0.95 + (f32)rand()/RAND_MAX*0.05,
                                     (f32)rand()/RAND_MAX*0.05,
                                     0.05 + (f32)rand()/RAND_MAX*0.05);
            position = new QVector3D((f32)distribution(e2),
                                     -6,
                                     (f32)distribution(e2));
            size = 1;
            alpha = 1;
            density = 0.2+((f32)rand()/RAND_MAX)*0.3; // between 0.1 and 0.3
            lifeTime = 1800+((f32)rand()/RAND_MAX)*900;

            temp = new Fire(position,
                             size,
                             lifeTime,
                             alpha,
                             density,
                             color);
            break;

        case smoke:

            color = new QVector3D(((f32)rand()/RAND_MAX)/10.0,
                                     ((f32)rand()/RAND_MAX)/10.0,
                                     ((f32)rand()/RAND_MAX)/10.0);

            position = new QVector3D((f32)distribution(e2),
                                     -6,
                                     (f32)distribution(e2));
            size = 1;
            alpha = 1;
            density = 0.1+((f32)rand()/RAND_MAX)*0.2; // between 0.1 and 0.3
            lifeTime = 1800+((f32)rand()/RAND_MAX)*1400; // <> ~1800 & 3200

            temp = new Smoke(position,
                             size,
                             lifeTime,
                             alpha,
                             density,
                             color);
            break;
        case water:
            temp = new Water();

            break;
        default:
            temp = new Classic();
            break;
        }

        m_particleVector.push_back(temp);
    }

}


void System::clean_system(){


    for(int i = m_particleVector.size()-1; i >= 0;   i--){

        Particle* part = m_particleVector.at(i);

        if(part->getM_lifeTime() < 1){
            if(dynamic_cast<Fire*>( part ))
            {
                if((f32)rand()/RAND_MAX > 0.75)
                {
                    Particle * newParticle;
                    QVector3D* color;
                    f32 density;
                    u16 lifeTime;

                    color = new QVector3D(   0.2 +(f32)rand()/RAND_MAX/5.0,
                                             0.2 +(f32)rand()/RAND_MAX/5.0,
                                             0.2 +(f32)rand()/RAND_MAX/5.0);

                    density = 0.1+((f32)rand()/RAND_MAX)*0.2; // between 0.1 and 0.3
                    lifeTime = 1000+((f32)rand()/RAND_MAX)*1000; // <> 1000 & 2000

                    newParticle = new Smoke(new QVector3D(part->getM_position()),
                                     part->getM_size(),
                                     lifeTime,
                                     part->getM_alpha(),
                                     part->getM_density(),
                                     color);
                    newParticle->setM_speed(new QVector3D(part->getM_speed()));
                    m_particleVector.push_back(newParticle);
                }

            }
            m_particleVector.remove(i);
            delete part;
        }
    }
}

void System::setM_windRotation(u16 value)
{
    m_wind.setM_angle(value);
}

void System::setParticleType(Particle_type pt)
{
    m_particle_type = pt;
}
