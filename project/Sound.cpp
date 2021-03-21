/**
* @author Julien_Audoux
* @file Sound.cpp
* @date 19/10/2020
* @brief implementation of the Sound m_type derived from Sensor
*/

#include "Sound.h"

Sound::Sound()
{
  this->data.m_type = e_sSound;
  this->data.m_temperature = 0.0;
  this->data.m_sound = false;
  this->data.m_sound = 0;
  this->data.m_humidity = 0.0;
}

Sound::Sound(int sound_p)
{
  this->data.m_type = e_sSound;
  this->data.m_temperature = 0.0;
  this->data.m_sound = sound_p;
  this->data.m_light = false;
  this->data.m_humidity = 0.0;
}

Sound::Sound(const Sound& sound_p)
{
  this->data.m_type = e_sSound;
  this->data.m_temperature = 0.0;
  this->data.m_sound = sound_p.data.m_sound;
  this->data.m_light = false;
  this->data.m_humidity = 0.0;
}

Sound::~Sound() {}