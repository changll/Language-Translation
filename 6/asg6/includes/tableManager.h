#ifndef TABLEMANAGER__H
#define TABLEMANAGER__H

#include <iostream>
#include <string>
#include <vector>
#include "symbolTable.h"
#include "functionTable.h"
#include "parameterTable.h"

class Literal;

class TableManager {
public:
  static TableManager&  getInstance();
  const Literal* getEntry(const std::string& name);
  const Node* getSuite(const std::string& name);
  const Node* getPara(const std::string& name);

  void     insertSymb(const std::string& name, const Literal* val);
  void     insertFunc(const std::string& name, const Node* node);
  void     insertPara(const std::string& name, const Node* node);

  void pushScope();
  void popScope();
  void display() const;
private:
  int currentScope;
  std::vector<SymbolTable> tables;
  std::vector<FunctionTable> functions;
  std::vector<ParameterTable> parameters;

  TableManager() : currentScope(0), tables(), functions(),parameters(){
    tables.push_back(SymbolTable());
    functions.push_back(FunctionTable());
    parameters.push_back(ParameterTable());
  }
};

#endif
