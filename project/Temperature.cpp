/**
* @author Julien_Audoux
* @file Temperature.cpp
* @date 19/10/2020
* @brief implementation of the Temperature m_type derived from Sensor
*/

#include "Temperature.h"

Temperature::Temperature()
{
  this->data.m_type = e_sTemperature;
  this->data.m_humidity = 0.0;
  this->data.m_light = false;
  this->data.m_sound = 0;
  this->data.m_temperature = 0.0;
}

Temperature::Temperature(float temperature_p)
{
  this->data.m_type = e_sTemperature;
  this->data.m_humidity = 0.0;
  this->data.m_light = false;
  this->data.m_sound = 0;
  this->data.m_temperature = temperature_p;
}

Temperature::Temperature(const Temperature& temperature_p)
{
  this->data.m_type = e_sTemperature;
  this->data.m_humidity = 0.0;
  this->data.m_light = false;
  this->data.m_sound = 0;
  this->data.m_temperature = temperature_p.data.m_temperature;
}

Temperature::~Temperature() {}