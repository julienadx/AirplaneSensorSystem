/**
* @author Julien_Audoux
* @file main.cpp
* @date 27/10/2020
* @brief main of the airplane sensor system
*/


#include <vector>
#include "Scheduler.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Sound.h"
#include "Light.h"

/**
   * @brief handler for signals during execution
   * @param int : this signal detected
   * @return void
   */
void sigHandler(const int sig_p)
{
  switch (sig_p) {
    case SIGINT:
      std::cout << "[*] ---- Ctrl-C signal detected ----\n" << Server::endLog(1) << std::endl;
      exit(0);
      break;
    default:
      std::cout << "[-] ---- unknown signal detected ----" << std::endl;
      break;
  }
}

/**
   * @brief main of the airplane sensor system : managing the global execution
   * @param int argc : the number of execution arguments
   * @param char *argv[] : char array which stores the execution arguments
   * @return int : termination exit code
   */
int main(int argc, char *argv[])
{

  bool m_log = false;
  bool m_consol = false;

  switch (argc) {
    case 2:
      if (*argv[1] == 'c')
      {
        m_consol = true;
      }
      else if (*argv[1] == 'l')
      {
        m_log = true;
      }
      break;
    case 3:
      if (*argv[1] == 'l' || *argv[2] == 'l')
      {
        m_log = true;
      }
      if (*argv[1] == 'c' || *argv[2] == 'c')
      {
        m_consol = true;
      }
      break;
    default:
      m_consol = true;
      break;
  }

  Server m_server = Server(m_consol, m_log);

  m_server.display(m_server.startLog());

  std::vector<Sensor> m_tab(0);

  m_tab.push_back(Temperature());
  m_tab.push_back(Humidity());
  m_tab.push_back(Sound());
  m_tab.push_back(Light());

  signal(SIGINT, sigHandler);

  Scheduler m_scheduler = Scheduler(m_server);
  m_scheduler.launchScheduler(m_tab);

  m_server.display(Server::endLog(2));

  return 0;
}
