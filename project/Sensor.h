/**
* @author Julien_Audoux
* @file Sensor.h
* @date 19/10/2020
* @brief definition of the Sensor m_type, class with all common characteristics of all sensors, to be derived from
*/

#ifndef PROJECT_SENSOR_H
#define PROJECT_SENSOR_H

#include "data.h"

/**
   * @class Sensor
   * @brief mother class of all types of sensors
   */
class Sensor
{
public:
  /**
   * @brief default constructor
   */
  Sensor();

  /**
   * @brief copy constructor
   * @param Sensor&
   */
  Sensor(const Sensor&);

  /**
   * @brief constructor with argument
   * @param data
   */
  Sensor(data);

  /**
   * @brief default destructor
   */
  ~Sensor();

  /**
   * @brief overload of = operator
   * @param Sensor&
   * @return Scheduler&
   */
  Sensor &operator=(const Sensor&);

  /**
   * @brief accessor that returns the value of the sensor
   * @return data
   */
  data getData();

protected:
  /**
   * @brief replace the former value of a sensor with a random value of the same type
   * @return void
   */
  void aleaGenVal();

  /**
   * @brief data attribute of a sensor
   */
  data data;
};

#endif //PROJECT_SENSOR_H
