/**
 * Project Untitled
 */


#ifndef _WATER_H
#define _WATER_H

#include "Particle.h"
#include "typedef.h"


class Water: public Particle {
public: 
    
    QVector3D getM_color();
    
    /**
     * @param value
     */
    void setM_color(QVector3D * value);
    Water();
    Water(QVector3D * position, u8 size, u16 lifetime,u8 alpha,f32 density,QVector3D  * color);
private: 
    QVector3D m_color;
};

#endif //_WATER_H
