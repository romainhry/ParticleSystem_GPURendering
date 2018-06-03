/**
 * Project Untitled
 */


#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

#include "typedef.h"
#include "Particle.h"
#include "Gravity.h"
#include "Wind.h"
#include <QVector>

#ifndef NBPARTICLEMAX
#define NBPARTICLEMAX 10
#endif

class System : protected QOpenGLFunctions {
public: 
    
    System();
    ~System();

    void drawGeometry(QOpenGLShaderProgram *program);

    void change_wind();
    
    void start_system();
    
    float getM_atmDensity();
    
    /**
     * @param value
     */
    void setM_atmDensity(f32 value);
    
    u16 getM_particleNb();
    
    /**
     * @param value
     */
    void setM_particleNb(u16 value);

    Gravity m_gravity;
    Wind m_wind;

private: 
    f32 m_atmDensity;
    u16 m_particleNb;


    QVector<Particle*> m_particleVector;

    void check_life_time();
    
    void compute_wind();

    void initGeometry();

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
};

#endif //_SYSTEM_H
