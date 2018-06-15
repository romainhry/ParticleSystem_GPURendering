/**
 * Project Untitled
 */


#include "Water.h"
#include "../typedef.h"

/**
 * Water implementation
 */
Water::Water(QVector3D * p, u8 s, u16 l,u8 a,f32 d, QVector3D *c): Particle(p,s,l,a,d,c){}

Water::Water():Particle(){}

void Water::setM_position(QVector3D  * value)
{
    if ( value->y() < -6 ){
        m_position = QVector3D(value->x(), -6, value->z());
    }else{
        m_position = *value;
    }
}

