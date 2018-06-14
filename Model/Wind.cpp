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

QMatrix4x4 Wind::get_ScrewMatrix()
{

    //Calculations for the screw
    QMatrix4x4 rotation_matrix;
    rotation_matrix.setToIdentity();
    if( m_angle > 0 && m_angle < 360){
        rotation_matrix.setToIdentity();
        rotation_matrix.rotate(m_angle * m_factor * 0.01f, m_translation);
    }
    return rotation_matrix;

}
