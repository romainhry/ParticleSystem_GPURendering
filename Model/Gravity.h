/**
 * Project Untitled
 */


#ifndef _GRAVITY_H
#define _GRAVITY_H

#include "Force.h"
#include "typedef.h"


class Gravity: public Force {
public: 
    
    float getM_gravity_factor();
    
    /**
     * @param value
     */
    void setM_gravity_factor(f32 value);
private: 
    float m_gravity_factor;
};

#endif //_GRAVITY_H
