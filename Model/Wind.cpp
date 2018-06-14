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

/**
 * @return u16
 */
u16 Wind::getM_angle() {
    return m_angle;
}

/**
 * @param value
 */
void Wind::setM_angle(u16 value) {
    m_angle = value;

}

QMatrix4x4 Wind::get_matrix()
{


    return QMatrix4x4((f32)cos(m_angle), (f32)0,  (f32)sin(m_angle),   (f32)m_translation.x(),
                      (f32)0,            (f32)1,  (f32)0,              (f32)m_translation.y(),
                      (f32)-sin(m_angle),(f32)0,  (f32)cos(m_angle),   (f32)m_translation.z(),
                      0,                0,          0,                  1);

}
