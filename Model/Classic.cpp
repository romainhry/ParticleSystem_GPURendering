/**
 * Project Untitled
 */


#include "Classic.h"
#include <QVector3D>

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
