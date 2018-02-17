#include <map>
#include <algorithm>
#include "tableManager.h"
#include "literal.h"

TableManager& TableManager::getInstance() {
    static TableManager instance;
    return instance;
}
const Literal* TableManager::getEntry(const std::string& name){
    int scope = currentScope;
    while(scope >= 0){
        if (tables[scope].found(name)) return tables[scope].getValue(name);
        scope--;
    }
    return nullptr;
}

const Node* TableManager::getSuite(const std::string& name){
    int scope = currentScope;
    while(scope >= 0){
        if (functions[scope].found(name)) return functions[scope].getSuite(name);
        scope--;
    }
    return nullptr;
}

const Node* TableManager::getPara(const std::string& name){
    int scope = currentScope;
    while(scope >= 0){
        if (parameters[scope].found(name)) return parameters[scope].getPara(name);
        scope--;
    }
    return nullptr;
}

void TableManager::insertSymb(const std::string& name, const Literal* val) {
    tables[currentScope].setValue(name, val);
}

void TableManager::insertFunc(const std::string& name, const Node* node) {
    functions[currentScope].setSuite(name, node);
}

void TableManager::insertPara(const std::string& name, const Node* node) {
    parameters[currentScope].setPara(name, node);
}

void TableManager::pushScope(){
    tables.push_back(SymbolTable());
    functions.push_back(FunctionTable());
    parameters.push_back(ParameterTable());
    currentScope++;
}

void TableManager::popScope(){
    tables.pop_back();
    functions.pop_back();
    parameters.pop_back();
    currentScope--;
}

void TableManager::display() const {}

