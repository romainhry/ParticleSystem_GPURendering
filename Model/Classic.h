/**
 * Project Untitled
 */


#ifndef _CLASSIC_H
#define _CLASSIC_H

#include "Particle.h"
#include <QVector3D>
#include "../typedef.h"


class Classic: public Particle {
public: 
    
    QVector3D getM_color();
    
    /**
     * @param value
     */
    void setM_color(QVector3D * value);

    void setM_position(QVector3D *value);

    Classic(QVector3D * p, u8 s, u16 l,u8 a,f32 d, QVector3D * c);
    Classic();
private: 
    QVector3D m_color;
};

#endif //_CLASSIC_H
