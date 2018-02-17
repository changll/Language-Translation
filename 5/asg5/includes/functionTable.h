#ifndef FUNCTIONTABLE__H
#define FUNCTIONTABLE__H

#include <iostream>
#include <string>
#include <map>

class Node;

class FunctionTable {
public:
  FunctionTable() : function() {}
  bool found(const std::string& name) const;
  const Node* getSuite(const std::string& name) const;
  void     setSuite(const std::string& name, const Node* suite);
  void display() const;
private:
  std::map<std::string, const Node*> function;
};

#endif
