/**
 * Project Untitled
 */


#ifndef _SMOKE_H
#define _SMOKE_H

#include "Particle.h"
#include <QVector3D>


class Smoke: public Particle {
public: 
    
    QVector3D getM_color();
    
    /**
     * @param value
     */
    void setM_color(QVector3D * value);
private: 
    static QVector3D m_color;
};

#endif //_SMOKE_H
