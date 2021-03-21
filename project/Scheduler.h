/**
* @author Julien_Audoux
* @file Scheduler.h
* @date 19/10/2020
* @brief definition of the Scheduler type, gathering and showing data from Sensors using a server
*/

#ifndef PROJECT_SCHEDULER_H
#define PROJECT_SCHEDULER_H

#include "Server.h"

/**
   * @class Scheduler
   * @brief class that using a server and sensors and manage the gathering of values
   */
class Scheduler
{
public:
  /**
   * @brief default constructor
   */
  Scheduler();

  /**
   * @brief constructor with argument server
   * @param Server
   */
  Scheduler(Server);

  /**
   * @brief constructor with all arguments
   * @param int interval
   * @param int times
   * @param Server
   */
  Scheduler(int, int, Server);

  /**
   * @brief copy constructor
   * @param Scheduler&
   */
  Scheduler(const Scheduler&);

  /**
   * @brief overload of = operator
   * @param Scheduler&
   * @return Scheduler&
   */
  Scheduler &operator=(const Scheduler&);

  /**
   * @brief launching the loop of gathering values from sensors using a server
   * @param std::vector<Sensor>
   * @return void
   */
  void launchScheduler(std::vector<Sensor>);

  /**
   * @brief default destructor
   */
  ~Scheduler();

private:
  /**
   * @brief attribute int interval in seconds
   */
  int m_interval;
  /**
   * @brief attribute int times in seconds
   */
  int m_times;
  /**
   * @brief attribute server
   */
  Server m_server;
};

#endif //PROJECT_SCHEDULER_H
