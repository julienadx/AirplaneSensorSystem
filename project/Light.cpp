/**
* @author Julien_Audoux
* @file Light.cpp
* @date 19/10/2020
* @brief implementation of the Light type derived from Sensor
*/

#include "Light.h"

Light::Light()
{
  this->data.m_type = e_sLight;
  this->data.m_temperature = 0.0;
  this->data.m_light = false;
  this->data.m_sound = 0;
  this->data.m_humidity = 0.0;
}

Light::Light(bool light_p)
{
  this->data.m_type = e_sLight;
  this->data.m_temperature = 0.0;
  this->data.m_light = light_p;
  this->data.m_sound = 0;
  this->data.m_humidity = 0.0;
}

Light::Light(const Light& light_p)
{
  this->data.m_type = e_sLight;
  this->data.m_temperature = 0.0;
  this->data.m_light = light_p.data.m_light;
  this->data.m_sound = 0;
  this->data.m_humidity = 0.0;
}

Light::~Light() {}