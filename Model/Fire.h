/**
 * Project Untitled
 */


#ifndef _FIRE_H
#define _FIRE_H

#include "Particle.h"
#include "../typedef.h"


class Fire: public Particle {
public: 
    
    QVector3D getM_color();
    
    /**
     * @param value
     */
    void setM_color(QVector3D * value);

    Fire(QVector3D * p, u8 size, u16 lifeTime,u8 alpha,f32 density, QVector3D * color);
    Fire();
    void reduce_lifeTime(u16 time);

};

#endif //_FIRE_H
