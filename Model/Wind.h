/**
 * Project Untitled
 */


#ifndef _WIND_H
#define _WIND_H

#include "Force.h"
#include "typedef.h"


class Wind: public Force {
public: 
    
    QVector3D getM_translation();
    
    /**
     * @param value
     */
    void setM_translation(QVector3D * value);

    f32 getM_factor();

    /**
     * @param value
     */
    void setM_factor(f32);

     QMatrix4x4 get_matrix();
protected: 
    QVector3D m_translation;
    f32 m_factor;
};

#endif //_WIND_H
