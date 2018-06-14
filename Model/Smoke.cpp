/**
 * Project Untitled
 */

#include <QVector3D>
#include "Smoke.h"
#include "../typedef.h"

/**
 * Smoke implementation
 */
Smoke::Smoke(QVector3D * p, u8 s, u16 l,u8 a,f32 d, QVector3D *c): Particle(p,s,l,a,d,c){}
Smoke::Smoke():Particle(){}


void Smoke::reduce_lifeTime(u16 time)
{
    f32 coef = (f32)time/m_lifeTime/4;
    m_color += QVector3D(coef,coef,coef);
    Particle::reduce_lifeTime(time);
}

