/**
* @author Julien_Audoux
* @file Sound.h
* @date 19/10/2020
* @brief definition of the Sound type derived from Sensor
*/

#ifndef PROJECT_SOUND_H
#define PROJECT_SOUND_H


#include "Sensor.h"
#include "data.h"

/**
   * @class Sound
   * @brief Sound sensor derived from Sensor class
   */
class Sound : public Sensor
{
public:
  /**
   * @brief default constructor
   */
  Sound();

  /**
   * @brief copy constructor
   * @param Sound&
   */
  Sound(const Sound&);

  /**
   * @brief constructor with parameter
   * @param int
   */
  Sound(int);

  /**
   * @brief destructor
   */
  ~Sound();
};

#endif //PROJECT_SOUND_H
