/**
 * Project Untitled
 */


#ifndef _WIND_H
#define _WIND_H

#include <QMatrix4x4>
#include <QVector3D>

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

    QMatrix4x4 get_ScrewMatrix();

     u16 getM_angle();

     /**
      * @param value
      */
     void setM_angle(u16 value);

protected: 
    QVector3D m_translation;
    f32 m_factor;

    u16 m_angle;
    QVector3D m_rotation;
};

#endif //_WIND_H
