/**
 * Project Untitled
 */


#ifndef _WIND_H
#define _WIND_H

#include "Force.h"


class Wind: public Force {
public: 
    
    QVector3D getM_translation();
    
    /**
     * @param value
     */
    void setM_translation(QVector3D * value);
protected: 
    QVector3D m_translation;
};

#endif //_WIND_H
