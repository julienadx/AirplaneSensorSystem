/**
* @author Julien_Audoux
* @file Server.cpp
* @date 19/10/2020
* @brief implementation of the Server m_type, to be able to gather the sensors data and showing them in logs
*/

#include "Server.h"
#include "Sensor.h"
#include <iostream>

#define LOG_FILE "log.txt"
#define VERSION "1.4"

//default constructor
Server::Server()
{
  this->m_consolActivation = true;
  this->m_logActivation = true;
  this->m_dataRcved = "";
}

Server::Server(bool consolActivation_p, bool logActivation_p)
{
  this->m_consolActivation = consolActivation_p;
  this->m_logActivation = logActivation_p;
  this->m_dataRcved = "";
}


Server::Server(bool consolActivation_p, bool logActivation_p, std::string dataRcved_p)
{
  this->m_consolActivation = consolActivation_p;
  this->m_logActivation = logActivation_p;
  this->m_dataRcved = dataRcved_p;
}

//copy constructor
Server::Server(const Server& a_p)
{
  this->m_consolActivation = a_p.m_consolActivation;
  this->m_logActivation = a_p.m_logActivation;
  this->m_dataRcved = a_p.m_dataRcved;
}

std::string Server::startLog() const
{
  std::string m_str = "\n~---------------AIRPLANE SENSOR SYSTEM V";
  m_str += VERSION;
  m_str += "---------------~\n[+]Server created with logs: ";
  if (this->m_consolActivation && this->m_logActivation)
  {
    m_str += "console | ";
    m_str += LOG_FILE;
  } else if (this->m_logActivation)
  {
    m_str += LOG_FILE;
  } else if (this->m_consolActivation)
  {
    m_str += "console";
  }
  m_str += "\n[*]press Ctrl-C anytime to stop the execution";
  return m_str;
}

std::string Server::endLog(int mode_p)
{
  std::string m_str = "";
  switch (mode_p)
  {
    case 1:
      m_str = "[+]Process terminated on interruption with success";
      break;
    case 2:
      m_str = "[+]Process terminated on its own with success";
      break;
    case 3:
      m_str = "[-]Error: Process failed";
      break;
    default:
      m_str = "[+]Process terminated with success";
      break;
  }
  return m_str;
}

//overload of the operator =
Server &Server::operator=(const Server& a_p)
{
  if (this != &a_p)
  {
    this->m_consolActivation = a_p.m_consolActivation;
    this->m_logActivation = a_p.m_logActivation;
    this->m_dataRcved = a_p.m_dataRcved;
  }
  return (*this);
}

//overload of the operator << in the console
std::ostream &operator<<(std::ostream& flux_p, const Server& a_p)
{
  flux_p << a_p.m_dataRcved;
  return flux_p;
}

//overload of the operator << in a file
std::ofstream &operator<<(std::ofstream& flux_p, Server const& a_p)
{
  flux_p << a_p.m_dataRcved;
  return flux_p;
}

//destructor method
Server::~Server() = default;

void Server::dataRcv(Sensor sensor_p, int i_p)
{
  data m_data = sensor_p.getData();
  switch (m_data.m_type)
  {
    case e_sTemperature:
      this->m_dataRcved = "\t[" + std::to_string(i_p) + "]Temperature: " + std::to_string(m_data.m_temperature) + "°C";
      break;
    case e_sHumidity:
      this->m_dataRcved = "\t[" + std::to_string(i_p) + "]Humidity: " + std::to_string(m_data.m_humidity) + "%";
      break;
    case e_sLight:
      this->m_dataRcved = "\t[" + std::to_string(i_p) + "]Light: " + std::to_string(m_data.m_light) + "";
      break;
    case e_sSound:
      this->m_dataRcved = "\t[" + std::to_string(i_p) + "]Sound: " + std::to_string(m_data.m_sound) + "dB";
      break;
    default:
      this->m_dataRcved = "\t[-]failed to read data";
      break;
  }
  this->display();
}

void Server::fileWrite() const
{
  //defining the output file
  std::ofstream m_file;
  m_file.open(LOG_FILE, std::ios_base::app);
  if (m_file)
  {
    //output in the file
    m_file << *this << std::endl;
    m_file.close();
  }
  else
  {
    std::cout << "[-]Error: cannot open file" << std::endl;
  }
}

void Server::fileWrite(std::string str_p, bool mode_p)
{
  //defining the output file
  std::ofstream m_file;
  m_file.open(LOG_FILE, std::ios_base::app);
  if (m_file)
  {
    m_file << str_p;
    if (mode_p)
    {
      //output in the file
      m_file << std::endl;
    }
    m_file.close();
  }
  else
  {
    std::cout << "[-]Error: cannot open file" << std::endl;
  }
}

void Server::consolWrite() const
{
  std::cout << *this << std::endl;
}

void Server::consolWrite(std::string str_p, bool mode_p)
{
  std::cout << str_p;
  if (mode_p) {
    std::cout << std::endl;
  }
}

void Server::display(std::string str_p, bool mode_p)
{
  if (this->m_logActivation)
  {
    this->fileWrite(str_p, mode_p);
  }
  if (this->m_consolActivation)
  {
    this->consolWrite(str_p, mode_p);
  }
}

void Server::display()
{
  if (this->m_logActivation)
  {
    this->fileWrite();
  }
  if (this->m_consolActivation)
  {
    this->consolWrite();
  }
}

