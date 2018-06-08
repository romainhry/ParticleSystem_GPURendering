/**
 * Project Untitled
 */


#include "Wind.h"
#include "../typedef.h"

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

/**
 * @return f32
 */
f32 Wind::getM_factor() {
    return m_factor;
}

/**
 * @param value
 */
void Wind::setM_factor(f32 value) {
    m_factor = value;
}

QMatrix4x4 Wind::get_matrix()
{

}
