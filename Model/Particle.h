/**
 * Project Untitled
 */


#ifndef _PARTICLE_H
#define _PARTICLE_H

#include "typedef.h"
#include <QVector3D>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class Particle  : protected QOpenGLFunctions {
public: 
    
    Particle();
    QVector3D getM_position();

    
    /**
     * @param value
     */
    void setM_position(QVector3D  * value);
    
    u8 getM_size();
    
    /**
     * @param value
     */
    void setM_size(u8 value);
    
    u16 getM_lifeTime();
    
    /**
     * @param value
     */
    void setM_lifeTime(u16 value);
    
    u8 getM_alpha();
    
    /**
     * @param value
     */
    void setM_alpha(u8 value);
    
    float getM_density();
    
    /**
     * @param value
     */
    void setM_density(f32 value);

    QVector3D getM_speed();

    /**
     * @param value
     */
    void setM_speed(QVector3D * value);

     ~Particle();
protected: 
    QVector3D m_position;
    QVector3D m_speed;
    u8 m_size;
    u16 m_lifeTime;
    u8 m_alpha;
    f32 m_density;

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;

    

};

#endif //_PARTICLE_H
