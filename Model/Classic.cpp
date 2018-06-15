/**
 * Project Untitled
 */


#include "Classic.h"
#include <QVector3D>
#include "../typedef.h"

/**
 * Classic implementation
 */


/**
 * @return QVector3D
 */
QVector3D Classic::getM_color()
{
    return m_color;
}

/**
 * @param value
 */
void Classic::setM_color(QVector3D * value)
{

    m_color = * value;
}

void Classic::setM_position(QVector3D *value)
{

    if ( value->y() < -6 ){
        m_position = QVector3D(value->x(), -6, value->z());
    }else{
        m_position = *value;
    }

}

Classic::Classic(QVector3D * p, u8 s, u16 l,u8 a,f32 d, QVector3D *c): Particle(p,s,l,a,d,c){}
Classic::Classic():Particle(){}
