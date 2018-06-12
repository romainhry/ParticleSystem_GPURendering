/**
 * Project Untitled
 */


#include "Gravity.h"

/**
 * Gravity implementation
 */
Gravity::Gravity(f32 factor)
{
    m_gravity_factor = factor;
    m_gravity = QVector3D(0.0f,-9.81,0.0f) * factor;
}

/**
 * @return float
 */
float Gravity::getM_gravity_factor() {
    return m_gravity_factor;
}

/**
 * @param value
 */
void Gravity::setM_gravity_factor(f32 value) {

    m_gravity_factor = value;
    m_gravity = QVector3D(0.0f,-9.81f,0.0f) * value;
}

QVector3D Gravity::getM_gravity()
{
    return m_gravity;
}

QMatrix4x4 Gravity::get_matrix()
{

}
