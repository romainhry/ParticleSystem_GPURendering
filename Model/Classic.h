/**
 * Project Untitled
 */


#ifndef _CLASSIC_H
#define _CLASSIC_H

#include "Particle.h"
#include <QVector3D>


class Classic: public Particle {
public: 
    
    QVector3D getM_color();
    
    /**
     * @param value
     */
    void setM_color(QVector3D * value);
private: 
    QVector3D m_color;
};

#endif //_CLASSIC_H
