/**
 * Project Untitled
 */


#ifndef _GRAVITY_H
#define _GRAVITY_H

#include "Force.h"
#include "../typedef.h"


class Gravity: public Force {
public: 
    
    f32 getM_gravity_factor();
    QVector3D getM_gravity();


    
    /**
     * @param value
     */
    void setM_gravity_factor(f32 value);

    QMatrix4x4 get_matrix();

    Gravity(f32 factor);
private: 
    f32 m_gravity_factor;
    QVector3D m_gravity;
};

#endif //_GRAVITY_H
