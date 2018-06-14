/**
 * Project Untitled
 */


#include "Fire.h"
#include "../typedef.h"

/**
 * Fire implementation
 */
Fire::Fire(QVector3D * p, u8 s, u16 l,u8 a,f32 d, QVector3D *c): Particle(p,s,l,a,d,c){}
Fire::Fire():Particle(){}



void Fire::reduce_lifeTime(u16 time)
{
    f32 coef = (f32)time/m_lifeTime/7;
    m_color += QVector3D(-coef,coef/3,coef);
    Particle::reduce_lifeTime(time);
}
