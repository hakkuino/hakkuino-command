#include "Command.h"
#include "Arduino.h"
#include <Logger.h>


Command::~Command()
{
  for (uint8_t i=0; i<this->argsSize; i++)
  {
    delete this->args[i];
  }
  delete this->args;
}
Command::Command(String s)
{
  this->argsSize = 0;
  this->input = s;
  this->cmd = s.substring(0,s.indexOf('('));
  String argsString = s.substring(s.indexOf('(') + 1, s.indexOf(')')) + ",";
  for (uint8_t i=1; i < argsString.length(); i++)
  {
    if (argsString.charAt(i) == ',')
    {
      this->argsSize++;
    }
  }
  short i;
  uint8_t cpt=0;
  this->args=(String**)malloc(this->argsSize*sizeof(String*));
  while((i = argsString.indexOf(',')) > 0)
  {
    this->args[cpt] = new String(argsString.substring(0,i));
    argsString = argsString.substring(i+1);
    cpt++;
  }
}
String Command::getCommand()
{
  return this->cmd;
}
String Command::getArg(uint8_t i)
{
  if (i >= 0 && i < this->argsSize)
  {
    return *(this->args[i]);
  }
  else
  {
    return "";  
  }
}
uint8_t Command::getArgsSize()
{
  return this->argsSize;
}