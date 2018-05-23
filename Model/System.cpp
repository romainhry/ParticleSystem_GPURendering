/**
 * Project Untitled
 */


#include "System.h"
#include "typedef.h"

/**
 * System implementation
 */


void System::change_wind() {

}

void System::start_system() {

}

/**
 * @return float
 */
f32 System::getM_atmDensity() {
    return m_atmDensity;
}

/**
 * @param value
 */
void System::setM_atmDensity(f32 value) {

    m_atmDensity = value;
}

/**
 * @return u16
 */
u16 System::getM_particleNb() {
    return m_particleNb;
}

/**
 * @param value
 */
void System::setM_particleNb(u16 value) {
    m_particleNb = value;

}

void System::check_life_time() {

}

void System::compute_wind() {

}
