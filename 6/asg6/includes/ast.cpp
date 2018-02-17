#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include<math.h>
#include <cstdlib>
#include <iomanip>
#include "ast.h"
#include "tableManager.h"

const Literal* EqualEqualBinaryNode::eval() const{
    if(!left || !right) throw std::string("error");
    const Literal* x = left->eval();
    const Literal* y = right->eval();
    const Literal* number = (*x == *y);
    return number;
}

const Literal* LessEqualBinaryNode::eval() const{
    if(!left || !right) throw std::string("error");
    const Literal* x = left->eval();
    const Literal* y = right->eval();
    const Literal* number = (*x <= *y);
    return number;
}
const Literal* NotEqualBinaryNode::eval() const{
    if(!left || !right) throw std::string("error");
    const Literal* x = left->eval();
    const Literal* y = right->eval();
    const Literal* number = ((*x).notEqual(*y));
    return number;
}
const Literal* GreaterEqualBinaryNode::eval() const{
    if(!left || !right) throw std::string("error");
    const Literal* x = left->eval();
    const Literal* y = right->eval();
    const Literal* number = (*x >= *y);
    return number;
}
const Literal* LessBinaryNode::eval() const{
    if(!left || !right) throw std::string("error");
    const Literal* x = left->eval();
    const Literal* y = right->eval();
    const Literal* number = (*x < *y);
    return number;
}

const Literal* GreaterBinaryNode::eval() const{
    if(!left || !right) throw std::string("error");
    const Literal* x = left->eval();
    const Literal* y = right->eval();
    const Literal* number = (*x > *y);
    return number;
}


const Literal* ReturnNode::eval() const{
    const Literal* res = nullptr;
    if(node == nullptr) TableManager::getInstance().insertSymb("_RETURN_", new NoneLiteral());
    else {
        res = node->eval();
        TableManager::getInstance().insertSymb("_RETURN_", res);
    }
    return res;
}

const Literal* PrintNode::eval() const{
    const Literal* res = node->eval();
    if(!node || !res){
        return nullptr;
    }
    res->print();
    return nullptr;
}

const Literal* CallNode::eval() const{
    TableManager& tm = TableManager::getInstance();
    if(!tm.getSuite(ident)){
        std::cout<<"function "<<ident<<" not found"<<std::endl;
        std::exception up = std::exception();
        throw up;
    }
    const Node* node = tm.getPara(ident);
    int index = 0;
    if(node){
        if(argNode){
            if(argNode->getSize() > ((ParaNode*)node)->getSize()){ throw "too much arguments"; }
            while(index < argNode->getSize()){
                tm.insertSymb(((ParaNode*)node)->getPa(index)->getName(),
                        argNode->getArg(index)->eval());
                index++;
            }
            for(int i = index; i < ((ParaNode*)node)->getSize(); i++){
                if(!((ParaNode*)node)->getPa(i)->getValue()){throw "less arguments!";}
                tm.insertSymb(((ParaNode*)node)->getPa(i)->getName(),
                        ((ParaNode*)node)->getPa(i)->getValue()->eval());
            }
        }
    }
    tm.pushScope();
    tm.getSuite(ident)->eval();
    const Literal* res = TableManager::getInstance().getEntry("_RETURN_");
    tm.popScope();
    return res;
}

FuncNode::FuncNode(const std::string id, Node* para,Node* stmt):Node(),ident(id),parameter(para),
    suite(stmt){
    TableManager::getInstance().insertFunc(ident,suite);
    TableManager::getInstance().insertPara(ident,parameter);
}


const Literal* SuiteNode::eval() const{
    for(const Node* n : stmts){
        if(!n) throw std::string("A suite is nullptr");
        if(TableManager::getInstance().getEntry("_RETURN_"))  break;
        n->eval();
    }
    return nullptr;
}

const Literal* IfNode::eval() const{
    if(!test) return 0;
    const Literal* lit = test->eval();
    lit = dynamic_cast<const Literal*>(lit);
    if(!lit) throw std::string("Couldn't eval test in IfNode");

    bool flag = lit->eval()->isTrue();
    if(flag){
        if(!thenSuite) throw std::string("thenSuite is null");
        thenSuite->eval();
    }
    else{
        if(!elseSuite) return nullptr;//IF with no ELSE;
        elseSuite->eval();
    }

    return nullptr;
}

const Literal* IdentNode::eval() const {
  const Literal* val = TableManager::getInstance().getEntry(ident);
  return val;
}


AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) :
  BinaryNode(left, right) {
  const Literal* res = right->eval();
  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  TableManager::getInstance().insertSymb(n, res);
}


const Literal* AsgBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* res = right->eval();

  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  TableManager::getInstance().insertSymb(n, res);
  return res;
}

const Literal* AddBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  //return (*x+*y);
  return (*x).operator+(*y);
}

const Literal* SubBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)/(*y));
}


const Literal* ModBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return ((*x)%(*y));
}

const Literal* DouMultBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x).DouMult(*y);
}

const Literal* DouDivBinaryNode::eval() const {
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  return (*x).DouDiv(*y);
}

