/**
 * Project Untitled
 */


#include "Particle.h"

/**
 * Particle implementation
 */


/**
 * @return QVector3D
 */
QVector3D Particle::getM_position() {
    return m_position;
}

/**
 * @param value
 */
void Particle::setM_position(QVector3D * value) {
    m_position = *value;
}

/**
 * @return u8
 */
u8 Particle::getM_size() {
    return m_size;
}

/**
 * @param value
 */
void Particle::setM_size(u8 value) {
    m_size = value;
}

/**
 * @return u16
 */
u16 Particle::getM_lifeTime() {
    return m_lifeTime;
}

/**
 * @param value
 */
void Particle::setM_lifeTime(u16 value) {
    m_lifeTime = value;
}

/**
 * @return u8
 */
u8 Particle::getM_alpha() {
    return m_alpha;
}

/**
 * @param value
 */
void Particle::setM_alpha(u8 value) {
    m_alpha = value;
}

/**
 * @return float
 */
f32 Particle::getM_density() {
    return m_density;
}

/**
 * @param value
 */
void Particle::setM_density(f32 value) {

    m_density = value;
}

Particle::~Particle() {
}
