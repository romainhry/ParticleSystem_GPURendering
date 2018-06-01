/**
 * Project Untitled
 */


#include "Wind.h"
#include "typedef.h"

/**
 * Wind implementation
 */

/**
 * @return QVector3D
 */
QVector3D Wind::getM_translation() {
    return m_translation;
}

/**
 * @param value
 */
void Wind::setM_translation(QVector3D * value) {
    m_translation = * value;
}

QMatrix4x4 Wind::get_matrix()
{

}
