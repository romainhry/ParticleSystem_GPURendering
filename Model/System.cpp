/**
 * Project Untitled
 */


#include "System.h"
#include "typedef.h"
#include "Gravity.h"
#include "Wind.h"


static const u8 deltaTime = 1;
/**
 * System implementation
 */


System::System() :
    m_gravity(),
    m_wind(),
    m_atmDensity(),
    m_particleNb(),
    indexBuf(QOpenGLBuffer::IndexBuffer)
{
    //initializeOpenGLFunctions();

    // Generate 2 VBOs
    arrayBuf.create();
    indexBuf.create();

    // Initializes cube geometry and transfers it to VBOs
    initGeometry();

}
void System::change_wind() {

}

void System::start_system() {

    m_particleVector.push_back(new Particle());
/*
    for(Particle * p = m_particleTab; p < m_particleTab + NBPARTICLEMAX; p++){

        if(p->getM_lifeTime() > 0){

            // Decrease life
            p->setM_lifeTime(p->getM_lifeTime()-deltaTime);
            if (p->getM_lifeTime() > 0){

                // Simulate simple physics : gravity only, no collisions
                QVector3D newSpeed = (p->getM_speed() + m_gravity.getM_gravity_factor() * QVector3D(0,9.81f,0) * deltaTime);
                p->setM_speed(&newSpeed);
                QVector3D newPos = p->getM_position() + p->getM_speed() * deltaTime;
                p->setM_position(&newPos);
                //p.cameradistance = glm::length2( p.pos - CameraPosition );
/*
                // Fill the GPU buffer
                g_particule_position_size_data[4*ParticlesCount+0] = p.getM_position().x;
                g_particule_position_size_data[4*ParticlesCount+1] = p.getM_position().y;
                g_particule_position_size_data[4*ParticlesCount+2] = p.getM_position().z;

                g_particule_position_size_data[4m_particlesCount+3] = p.getM_size();

                g_particule_color_data[4*ParticlesCount+0] = p.r;
                g_particule_color_data[4*ParticlesCount+1] = p.g;
                g_particule_color_data[4*ParticlesCount+2] = p.b;
                g_particule_color_data[4*ParticlesCount+3] = p.a;

            }else{
                // Particles that just died will be put at the end of the buffer in SortParticles();
                p.cameradistance = -1.0f;
            }

            ParticlesCount++;
            }

        }
    }*/

}

/**
 * @return float
 */
f32 System::getM_atmDensity() {
    return m_atmDensity;
}

/**
 * @param value
 */
void System::setM_atmDensity(f32 value) {

    m_atmDensity = value;
}

/**
 * @return u16
 */
u16 System::getM_particleNb() {
    return m_particleNb;
}

/**
 * @param value
 */
void System::setM_particleNb(u16 value) {
    m_particleNb = value;

}

void System::check_life_time() {

    for(int i=0; i<NBPARTICLEMAX; i++){/*
           if (m_particleTab[i].getM_lifeTime() == 0){

           }*/
       }
}

void System::compute_wind() {

}

void System::initGeometry()
{
    /*
    // Transfer vertex data to VBO 0
   arrayBuf.bind();
   arrayBuf.allocate(vertices, nbrVertices * sizeof(VertexData));

   // Transfer index data to VBO 1
   indexBuf.bind();
   indexBuf.allocate(indices, nbrIndices * sizeof(GLushort));
   */
}

void System::drawGeometry(QOpenGLShaderProgram *program)
{
    // Tell OpenGL which VBOs to use
    arrayBuf.bind();
    indexBuf.bind();


    // Offset for position
    quintptr offset = 0;

    /*
    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = program->attributeLocation("position");
    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    // Offset for texture coordinate
    offset += sizeof(QVector3D);

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
    int colorLocation = program->attributeLocation("color");
    program->enableAttributeArray(colorLocation);
    program->setAttributeBuffer(colorLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    // Draw cube geometry using indices from VBO 1
    glDrawElements(GL_LINES, 6, GL_UNSIGNED_SHORT, 0);
    */
}

System::~System()
{
    indexBuf.destroy();
    arrayBuf.destroy();
}
