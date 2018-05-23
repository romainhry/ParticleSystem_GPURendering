/**
 * Project Untitled
 */

#include <QVector3D>
#include "Smoke.h"

/**
 * Smoke implementation
 */


/**
 * @return QVector3D
 */
QVector3D Smoke::getM_color() {
    return m_color;
}

/**
 * @param value
 */
void Smoke::setM_color(QVector3D * value) {
    m_color = * value;
}
