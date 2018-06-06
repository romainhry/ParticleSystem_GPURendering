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
    
    /**
     * @param value
     */
    void setM_gravity_factor(f32 value);

    QMatrix4x4 get_matrix();
private: 
    f32 m_gravity_factor;
};

#endif //_GRAVITY_H
