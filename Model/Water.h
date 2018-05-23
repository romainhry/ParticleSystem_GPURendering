/**
 * Project Untitled
 */


#ifndef _WATER_H
#define _WATER_H

#include "Particle.h"


class Water: public Particle {
public: 
    
    QVector3D getM_color();
    
    /**
     * @param value
     */
    void setM_color(QVector3D * value);
private: 
    QVector3D m_color;
};

#endif //_WATER_H
