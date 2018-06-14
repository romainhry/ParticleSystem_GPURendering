/**
 * Project Untitled
 */


#ifndef _SMOKE_H
#define _SMOKE_H

#include "Particle.h"
#include <QVector3D>
#include "../typedef.h"


class Smoke: public Particle {

public:



    Smoke();
    Smoke(QVector3D * position, u8 size, u16 lifetime,u8 alpha,f32 density, QVector3D * m_color);

    void reduce_lifeTime(u16 time);


};

#endif //_SMOKE_H
