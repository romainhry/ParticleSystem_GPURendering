/**
 * Project Untitled
 */


#include "Water.h"

/**
 * Water implementation
 */


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
