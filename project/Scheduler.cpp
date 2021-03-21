/**
* @author Julien_Audoux
* @file Scheduler.cpp
* @date 19/10/2020
* @brief implementation of the Scheduler m_type, gathering and showing data from Sensors using a m_server
*/

#include <zconf.h>
#include <vector>
#include "Scheduler.h"
#include "Server.h"
#include <signal.h>

#define DEFAULT_INTERVAL 10
#define DEFAULT_TIMES 10000

Scheduler::Scheduler()
{
  this->m_interval = DEFAULT_INTERVAL;
  this->m_times = DEFAULT_TIMES;
  this->m_server = Server();
}

Scheduler::Scheduler(Server server_p)
{
  this->m_server = server_p;
  this->m_interval = DEFAULT_INTERVAL;
  this->m_times = DEFAULT_TIMES;
}

Scheduler::Scheduler(int interval_p, int times_p, Server server_p)
{
  this->m_interval = interval_p;
  this->m_times = times_p;
  this->m_server = server_p;
}

Scheduler::Scheduler(const Scheduler& scheduler_p)
{
  this->m_interval = scheduler_p.m_interval;
  this->m_times = scheduler_p.m_times;
  this->m_server = scheduler_p.m_server;
}

Scheduler &Scheduler::operator=(const Scheduler& a_p)
{
  if (this != &a_p) {
    this->m_interval = a_p.m_interval;
    this->m_times = a_p.m_times;
    this->m_server = a_p.m_server;
  }
  return (*this);
}


Scheduler::~Scheduler() {}

void Scheduler::launchScheduler(std::vector<Sensor> tab_p)
{

  this->m_server.display("~-----Session launched with " + std::to_string(this->m_interval) + "s interval " +
                       std::to_string(this->m_times) + " times-----~");

  for (int m_lap = 1; m_lap < this->m_times + 1; ++m_lap)
  {
    time_t tt;
    struct tm *ti;
    time(&tt);
    ti = localtime(&tt);
    m_server.display(asctime(ti), false);
    for (int m_i = 0; m_i < tab_p.size(); ++m_i)
    {
      if (m_lap % 2 == 0 && tab_p[m_i].getData().m_type == e_sTemperature)
      {
        this->m_server.dataRcv(tab_p[m_i], m_lap);
      }
      if (m_lap % 5 == 0 && tab_p[m_i].getData().m_type == e_sHumidity)
      {
        this->m_server.dataRcv(tab_p[m_i], m_lap);
      }
      if (m_lap % 3 == 0 && tab_p[m_i].getData().m_type == e_sSound)
      {
        this->m_server.dataRcv(tab_p[m_i], m_lap);
      }
      if (m_lap % 1 == 0 && tab_p[m_i].getData().m_type == e_sLight)
      {
        this->m_server.dataRcv(tab_p[m_i], m_lap);
      }
    }
    sleep(this->m_interval);
  }
}