/**
 * Project Untitled
 */


#include "Particle.h"
#include "../typedef.h"
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

/**
 * Particle implementation
 */
Particle::Particle(): m_position(), m_size(),m_lifeTime(),m_alpha(),m_density()
{

}

Particle::Particle(QVector3D * p, u8 s, u16 l,u8 a,f32 d): m_position(*p), m_size(s),m_lifeTime(l),m_alpha(a),m_density(d)
{

}


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

QVector3D Particle::getM_speed()
{
    return m_speed;
}


/**
 * @param value
 */
void Particle::setM_speed(QVector3D * value)
{
    m_speed = * value;
}

void Particle::reduce_lifeTime(u16 time)
{
    if(m_lifeTime > time)
        m_lifeTime -= time;
    else
        m_lifeTime = 0;
}

Particle::~Particle() {
}
