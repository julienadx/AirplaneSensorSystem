/**
* @author Julien_Audoux
* @file Light.h
* @date 19/10/2020
* @brief definition of the light type derived from Sensor
*/

#ifndef PROJECT_LIGHT_H
#define PROJECT_LIGHT_H

#include "Sensor.h"
#include "data.h"

/**
   * @class Light
   * @brief light sensor derived from Sensor class
   */
class Light : public Sensor
{
public:
  /**
   * @brief default constructor
   */
  Light();

  /**
   * @brief copy constructor
   * @param Light&
   */
  Light(const Light&);

  /**
   * @brief default constructor
   * @param bool
   */
  Light(bool);

  /**
   * @brief default destructor
   */
  ~Light();
};


#endif //PROJECT_LIGHT_H
