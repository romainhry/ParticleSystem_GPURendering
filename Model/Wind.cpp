/**
 * Project Untitled
 */

#include <QtMath>
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

QMatrix4x4 Wind::get_RotationMatrix()
{

    f32 angle = qDegreesToRadians((f32)m_angle* 0.1f) ;
    return QMatrix4x4((f32)cos(angle), (f32)0,  (f32)sin(angle),    0,
                      (f32)0,            (f32)1,  (f32)0,               0,
                      (f32)-sin(angle),(f32)0,  (f32)cos(angle),    0,
                      0,                0,          0,                  1);

}
