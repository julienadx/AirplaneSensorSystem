/**
* @author Julien_Audoux
* @file Humidity.cpp
* @date 19/10/2020
* @brief implementation of the Humidity type derived from Sensor
*/

#include "Humidity.h"

Humidity::Humidity()
{
  this->data.m_type = e_sHumidity;
  this->data.m_temperature = 0.0;
  this->data.m_light = false;
  this->data.m_sound = 0;
  this->data.m_humidity = 0.0;
}

Humidity::Humidity(float humidity_p)
{
  this->data.m_type = e_sHumidity;
  this->data.m_temperature = 0.0;
  this->data.m_light = false;
  this->data.m_sound = 0;
  this->data.m_humidity = humidity_p;
}

Humidity::Humidity(const Humidity& humidity_p)
{
  this->data.m_type = e_sHumidity;
  this->data.m_temperature = 0.0;
  this->data.m_light = false;
  this->data.m_sound = 0;
  this->data.m_humidity = humidity_p.data.m_humidity;
}

Humidity::~Humidity() {}