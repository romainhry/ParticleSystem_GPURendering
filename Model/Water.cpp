/**
 * Project Untitled
 */


#include "Water.h"
#include "../typedef.h"

/**
 * Water implementation
 */
Water::Water(QVector3D * p, u8 s, u16 l,u8 a,f32 d, QVector3D * c): Particle(p,s,l,a,d),m_color(*c){}

Water::Water():Particle(),m_color(){}

/**
 * @return QVector3D
 */
QVector3D Water::getM_color() {
    return m_color;
}

/**
 * @param value
 */
void Water::setM_color(QVector3D * value) {

    m_color = * value;

}
