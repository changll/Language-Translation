#include <map>
#include <algorithm>
#include "parameterTable.h"
#include "node.h"

bool ParameterTable::found(const std::string& name) const{
  std::map<std::string, const Node*>::const_iterator it =
    parameter.find(name);
  if(it == parameter.end()) return false;
  return true;
}
const Node* ParameterTable::getPara(const std::string& name) const {
  std::map<std::string, const Node*>::const_iterator it =
    parameter.find(name);
  if ( it == parameter.end() ) throw name+std::string(" parameter not found");
  return it->second;
}

void ParameterTable::setPara(const std::string& name, const Node* val) {
  parameter[name] = val;
}

void ParameterTable::display() const{}

