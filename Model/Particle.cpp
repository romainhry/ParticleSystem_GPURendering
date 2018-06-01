/**
 * Project Untitled
 */


#include "Particle.h"
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

// The VBO containing the 4 vertices of the particles.
// Thanks to instancing, they will be shared by all particles.
static const GLfloat s_vertices[] = {
 -0.5f, -0.5f, 0.0f,
 0.5f, -0.5f, 0.0f,
 -0.5f, 0.5f, 0.0f,
 0.5f, 0.5f, 0.0f,
};

static const GLushort s_indices[] = {
    0,1,4,3
};


/**
 * Particle implementation
 */
Particle::Particle()
{
    /*
    initializeOpenGLFunctions();

    // Generate 2 VBOs
    arrayBuf.create();
    indexBuf.create();


    // Transfer vertex data to VBO 0
    arrayBuf.bind();
    arrayBuf.allocate(s_vertices, 4 * sizeof(GLfloat) * 4);

    // Transfer index data to VBO 1
    indexBuf.bind();
    indexBuf.allocate(s_vertices, 4 * sizeof(GLushort));*/
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

Particle::~Particle() {

    arrayBuf.destroy();
    indexBuf.destroy();
}
