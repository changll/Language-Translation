#include <map>
#include <algorithm>
#include "functionTable.h"
#include "node.h"

bool FunctionTable::found(const std::string& name) const{
  std::map<std::string, const Node*>::const_iterator it =
    function.find(name);
  if(it == function.end()) return false;
  return true;
}
const Node* FunctionTable::getSuite(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it =
    function.find(name);
  if ( it == function.end() ) throw name+std::string(" Symbol not found");
  return it->second;
}

void FunctionTable::setSuite(const std::string& name, const Node* val) {
  function[name] = val;
}

void FunctionTable::display() const{}

