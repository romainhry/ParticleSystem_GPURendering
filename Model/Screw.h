/**
 * Project Untitled
 */


#ifndef _SCREW_H
#define _SCREW_H

#include "Wind.h"
#include "typedef.h"


class Screw: public Wind {
public: 
    
    u16 getM_angle();
    
    /**
     * @param value
     */
    void setM_angle(u16 value);
private: 
    u16 m_angle;
};

#endif //_SCREW_H
