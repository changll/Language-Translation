#ifndef PARAMETERTABLE__H
#define PARAMETERTABLE__H

#include <iostream>
#include <string>
#include <map>

class Node;

class ParameterTable {
public:
  ParameterTable() : parameter() {}
  bool found(const std::string& name) const;
  const Node* getPara(const std::string& name) const;
  void     setPara(const std::string& name, const Node* para);
  void display() const;
private:
  std::map<std::string, const Node*> parameter;
};

#endif
