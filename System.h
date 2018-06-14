/**
 * Project Untitled
 */


#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

#include "typedef.h"
#include "Model/Particle.h"
#include "Model/Gravity.h"
#include "Model/Wind.h"


#include <QVector>

#include <QOpenGLExtraFunctions>
#include "enum.h"

#ifndef NBPARTICLEMAX
#define NBPARTICLEMAX 10
#endif

class System : protected QOpenGLExtraFunctions {
public: 
    
    System();
    virtual ~System();

    void drawGeometry(QOpenGLShaderProgram *program);

    void change_wind(QVector3D *);

    
    float getM_atmDensityFactor();
    
    /**
     * @param value
     */
    void setM_atmDensityFactor(f32 value);
    
    u16 getM_particleNb();
    
    /**
     * @param value
     */
    void setM_particleNb(u16 value);

    void setM_windFactor(f32);
    void setM_gravity(f32);

    void update_particles(s32 pRefresh_delay_s32);

    void setParticleType(Particle_type pt);

    void setM_windRotation(u16 value);



private: 
    f32 m_atmDensityFactor;
    u16 m_particleNb;
    Gravity m_gravity;
    Wind m_wind;


    QVector<Particle*> m_particleVector;

    void check_life_time();
    
    void compute_wind();

    void initGeometry();

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;

    static const int MAX_PARTICLES = 1000; //100 000
    static const int ATM_DENSITY = 12;

    static Particle_type m_particle_type;

    //test buffers
    GLuint billboard_vertex_buffer;
    GLuint particles_position_buffer;
    GLuint particles_color_buffer;



    static GLfloat* g_particule_position_size_data;
    static GLubyte* g_particule_color_data;



    void clean_system();
};

#endif //_SYSTEM_H
