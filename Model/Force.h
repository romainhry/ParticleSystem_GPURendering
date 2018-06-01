/**
 * Project Untitled
 */


#ifndef _FORCE_H
#define _FORCE_H

#include <QMatrix4x4>

class Force {
public: 
    
    virtual QMatrix4x4 get_matrix() = 0;
};

#endif //_FORCE_H
