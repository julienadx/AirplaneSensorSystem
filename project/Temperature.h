/**
* @author Julien_Audoux
* @file Temperature.h
* @date 19/10/2020
* @brief definition of the Temperature type derived from Sensor
*/

#ifndef PROJECT_TEMPERATURE_H
#define PROJECT_TEMPERATURE_H

#include "Sensor.h"
#include "data.h"

/**
   * @class Temperature
   * @brief Temperature sensor derived from Sensor class
   */
class Temperature : public Sensor
{
public:
  /**
   * @brief default constructor
   */
  Temperature();

  /**
   * @brief copy constructor
   * @param Temperature&
   */
  Temperature(const Temperature&);

  /**
   * @brief constructor with argument
   * @param float
   */
  Temperature(float);

  /**
   * @brief default destructor
   */
  ~Temperature();
};

#endif //PROJECT_TEMPERATURE_H
