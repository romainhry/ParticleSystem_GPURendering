/**
 * Project Untitled
 */


#include "Classic.h"
#include <QVector3D>
#include "typedef.h"

/**
 * Classic implementation
 */


/**
 * @return QVector3D
 */
QVector3D Classic::getM_color() {
    return m_color;
}

/**
 * @param value
 */
void Classic::setM_color(QVector3D * value) {

    m_color = * value;
}

Classic::Classic(QVector3D * p, u8 s, u16 l,u8 a,f32 d, QVector3D * c): Particle(p,s,l,a,d),m_color(*c){}
Classic::Classic():Particle(),m_color(){}
