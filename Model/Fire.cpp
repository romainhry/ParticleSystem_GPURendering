/**
 * Project Untitled
 */


#include "Fire.h"
#include "../typedef.h"

/**
 * Fire implementation
 */
Fire::Fire(QVector3D * p, u8 s, u16 l,u8 a,f32 d, QVector3D * c): Particle(p,s,l,a,d),m_color(*c){}
Fire::Fire():Particle(),m_color(){}

/**
 * @return QVector3D
 */
QVector3D Fire::getM_color() {
    return m_color;
}

/**
 * @param value
 */
void Fire::setM_color(QVector3D * value) {
    m_color = * value;

}



