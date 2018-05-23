/**
 * Project Untitled
 */


#include "Fire.h"

/**
 * Fire implementation
 */


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
