/**
 * Project Untitled
 */


#ifndef _SMOKE_H
#define _SMOKE_H

#include "Particle.h"
#include <QVector3D>
#include "../typedef.h"

const static QVector3D m_color = QVector3D(1,1,1);

class Smoke: public Particle {
private:


public:

    QVector3D getM_color()
    {
        return m_color;
    }

    /**
     * @param value
     */
    /*static void setM_color(QVector3D * value)
    {
        m_color = * value;
    }*/
    Smoke();
    Smoke(QVector3D * position, u8 size, u16 lifetime,u8 alpha,f32 density);

};

#endif //_SMOKE_H
