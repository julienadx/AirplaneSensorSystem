/**
* @author Julien_Audoux
* @file data.h
* @date 19/10/2020
* @brief definition of the data type and the ESensortype enumeration
*/

#ifndef PROJECT_DATA_H
#define PROJECT_DATA_H

/**
 * @enum ESensorType
 * @brief enumeration to encode the type of a sensor
 */
enum ESensortype
{
  e_sTemperature,
  e_sHumidity,
  e_sSound,
  e_sLight,
  e_sDefault
};

/**
 * @struct data
 * @brief structure defining a type that contains the type of the sensor and all the return values possible
 */
struct data
{
  ESensortype m_type;
  float m_temperature;
  float m_humidity;
  int m_sound;
  bool m_light;
};

typedef struct data data;

#endif //PROJECT_DATA_H
