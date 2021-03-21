/**
* @author Julien_Audoux
* @file Humidity.h
* @date 19/10/2020
* @brief definition of the Humidity type derived from Sensor
*/

#ifndef PROJECT_HUMIDITY_H
#define PROJECT_HUMIDITY_H

#include "Sensor.h"

/**
 * @class Humidity
 * @brief humidity sensor derived from Sensor class
 */
class Humidity : public Sensor
{
public:
  /**
   * @brief default constructor
   */
  Humidity();

  /**
   * @brief copy constructor
   * @param Humidity&
   */
  Humidity(const Humidity&);

  /**
   * @brief constructor with argument
   * @param float
   */
  Humidity(float);

  /**
   * @brief default destructor
   */
  ~Humidity();
};


#endif //PROJECT_HUMIDITY_H
