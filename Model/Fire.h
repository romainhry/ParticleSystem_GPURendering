/**
 * Project Untitled
 */


#ifndef _FIRE_H
#define _FIRE_H

#include "Particle.h"


class Fire: public Particle {
public: 
    
    QVector3D getM_color();
    
    /**
     * @param value
     */
    void setM_color(QVector3D * value);
private: 
    QVector3D m_color;
};

#endif //_FIRE_H
