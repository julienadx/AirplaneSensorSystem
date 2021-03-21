/**
* @author Julien_Audoux
* @file Server.h
* @date 19/10/2020
* @brief definition of the Server type, to be able to gather the sensors data and showing them in logs
*/

#ifndef PROJECT_SERVER_H
#define PROJECT_SERVER_H

#include <iostream>
#include <fstream>
#include "data.h"
#include "Sensor.h"

class Server
{
public:
  /**
   * @brief default constructor
   */
  Server();

  /**
   * @brief copy constructor
   * @param Server&
   */
  Server(const Server&);

  /**
   * @brief constructor with all arguments
   * @param bool for file log activation
   * @param bool for console log activation
   * @param std::string for value from a sensor
   */
  Server(bool, bool, std::string);

  /**
   * @brief constructor with arguments
   * @param bool for file log activation
   * @param bool for console log activation
   */
  Server(bool, bool);

  /**
   * @brief overload of = operator
   * @param Server&
   * @return Server&
   */
  Server &operator=(const Server&);

  /**
   * @brief overload of << operator
   * @param std::ostream& for the current flux
   * @param Server&
   * @return std::ostream& for the altered flux
   */
  friend std::ostream &operator<<(std::ostream &flux, const Server&);

  /**
   * @brief overload of << operator
   * @param std::oftream& for the current flux
   * @param Server&
   * @return std::oftream& for the altered flux
   */
  friend std::ofstream &operator<<(std::ofstream &flux, const Server&);

  /**
   * @brief default destructor
   */
  ~Server();

  /**
   * @brief receiving data from a sensor and paste it in the attribute dataRcved of the Server
   * @param Sensor to receive data from
   * @param int : the current lap of gathering data
   * @return void
   */
  void dataRcv(Sensor, int);

  /**
   * @brief display a given string in the console or log file
   * @param std::string to be displayed
   * @param bool : a default parameter to add a std::endl if true or nothing if false
   * @return void
   */
  void display(std::string, bool=true);

  /**
   * @brief display the sensor value stored in the server (attribute dataRcved)
   * @return void
   */
  void display();

  /**
   * @brief returns the string related to the startup logs
   * @return std::string : startup logs
   */
  std::string startLog() const;

  /**
   * @brief returns the string related to the end up logs
   * @param int : default parameter to define the end up context
   * @return std::string : end up logs
   */
  static std::string endLog(int= 0);

private:
  /**
   * @brief bool attribute to store the state of console logs (activated or not)
   */
  bool m_consolActivation;
  /**
   * @brief bool attribute to store the state of file logs (activated or not)
   */
  bool m_logActivation;
  /**
   * @brief std::string attribute to store the current value received by a sensor
   */
  std::string m_dataRcved;

  /**
   * @brief write in a file a received data
   * @return void
   */
  void fileWrite() const;

  /**
   * @brief write in console a received data
   * @return void
   */
  void consolWrite() const;

  /**
   * @brief write in a file a given std::string
   * @param std::string : the std::string to be written
   * @param bool : true for a std::endl at the end of writing or false for nothing
   * @return void
   */
  static void fileWrite(std::string, bool);

  /**
   * @brief write in console a given std::string
   * @param std::string : the std::string to be written
   * @param bool : true for a std::endl at the end of writing or false for nothing
   * @return void
   */
  static void consolWrite(std::string, bool);
};

#endif //PROJECT_SERVER_H
