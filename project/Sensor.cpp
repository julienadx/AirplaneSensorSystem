/**
* @author Julien_Audoux
* @file Sensor.cpp
* @date 19/10/2020
* @brief implementation of the Sensor m_type, class with all common characteristics of all sensors, to be derived from
*/

#include <cstdlib>
#include <time.h>
#include <iostream>
#include "data.h"
#include "Sensor.h"

#define MAX_RANDOM 1000

Sensor::Sensor()
{
  this->data.m_type = e_sDefault;
  this->data.m_humidity = 0.0;
  this->data.m_light = false;
  this->data.m_sound = 0;
  this->data.m_temperature = 0.0;
}

Sensor::Sensor(const Sensor& Sensor_p)
{
  this->data = Sensor_p.data;
}

Sensor::Sensor(struct data data_p)
{
  this->data = data_p;
}

Sensor &Sensor::operator=(const Sensor& a_p)
{
  if (this != &a_p) {
    this->data = a_p.data;
    return (*this);
  }
}

Sensor::~Sensor() {}

data Sensor::getData()
{
  this->aleaGenVal();
  return this->data;
}

void Sensor::aleaGenVal()
{
  std::srand((int) std::time(nullptr));
  switch (this->data.m_type)
  {
    case e_sTemperature:
      this->data.m_temperature = (rand() % 80) - 40;
      break;
    case e_sHumidity:
      this->data.m_humidity = (rand() % 100);
      break;
    case e_sLight:
      if ((rand() % MAX_RANDOM) <= MAX_RANDOM / 2)
      {
        this->data.m_light = false;
      }
      else
      {
        this->data.m_light = true;
      }
      break;
    case e_sSound:
      this->data.m_sound = (rand() % 140);
      break;
    default:
      std::cout << "[-]error: aleaGenVal failed" << std::endl;
      break;
  }
}