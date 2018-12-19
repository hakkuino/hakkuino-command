#include <stdint.h>
#include "Arduino.h"

#ifndef HAKKUINO_COMMAND_H
#define HAKKUINO_COMMAND_H

/* Here is the state machine of pomodoro light */

class Command {
  String input;
  String cmd;
  String** args;
  int argsSize;
public:
  Command(String s);
  ~Command();
  String getCommand();
  String getArg(uint8_t i);
  uint8_t getArgsSize();
};

#endif