/**
 * Project Untitled
 */


#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "typedef.h"

class System {
public: 
    
    void change_wind();
    
    void start_system();
    
    float getM_atmDensity();
    
    /**
     * @param value
     */
    void setM_atmDensity(f32 value);
    
    u16 getM_particleNb();
    
    /**
     * @param value
     */
    void setM_particleNb(u16 value);
private: 
    float m_atmDensity;
    u16 m_particleNb;
    
    void check_life_time();
    
    void compute_wind();
};

#endif //_SYSTEM_H
