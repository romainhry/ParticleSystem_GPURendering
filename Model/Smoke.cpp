/**
 * Project Untitled
 */

#include <QVector3D>
#include "Smoke.h"
#include "../typedef.h"

/**
 * Smoke implementation
 */
Smoke::Smoke(QVector3D * p, u8 s, u16 l,u8 a,f32 d): Particle(p,s,l,a,d){}
Smoke::Smoke():Particle(){}
