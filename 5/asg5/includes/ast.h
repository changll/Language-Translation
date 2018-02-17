#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <map>
#include "literal.h"

extern void yyerror(const char*);
extern void yyerror(const char*, const char);

class CallNode : public Node{
public:
    CallNode(const std::string id):Node(), ident(id){}
    virtual const Literal* eval() const;
private:
    const std::string ident;
};

class PrintNode : public Node{
public:
    PrintNode( const Node* n):Node(), node(n){
        if(node == nullptr) node = new NoneLiteral();
    }
    virtual const Literal* eval() const;
private:
    const Node* node;
};

class ReturnNode : public Node{
public:
    ReturnNode( const Node* n):Node(), node(n){}
    virtual const Literal* eval() const;
private:
    const Node* node;
};

class FuncNode : public Node{
public:
    FuncNode(const std::string id, Node* stmt);
    virtual const Literal* eval() const{ return nullptr; }
private:
    std::string ident;
    const Node* suite;
};

class IfNode : public Node{
public:
    IfNode(const Node* n, const Node* ts, const Node* es) :
        test(n), thenSuite(ts), elseSuite(es){}
    virtual const Literal* eval() const;
private:
    const Node* test;
    const Node* thenSuite;
    const Node* elseSuite;
};

class SuiteNode : public Node{
public:
    SuiteNode() : Node(){}
    virtual ~SuiteNode(){}
    void insert(Node* node)  {stmts.push_back(node);}
    virtual const Literal* eval() const;
private:
    std::vector<Node*> stmts;
};

class IdentNode : public Node {
public:
  IdentNode(const std::string id) : Node(), ident(id) { }
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval() const;
private:
  std::string ident;
};

class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual const Literal* eval() const = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
protected:
  Node *left;
  Node *right;
};

class EqualEqualBinaryNode : public BinaryNode{
public:
    EqualEqualBinaryNode(Node* left, Node* right):BinaryNode(left,right){}
    virtual const Literal* eval() const;
};

class LessEqualBinaryNode : public BinaryNode{
public:
    LessEqualBinaryNode(Node* left, Node* right):BinaryNode(left,right){}
    virtual const Literal* eval() const;
};

class NotEqualBinaryNode : public BinaryNode{
public:
    NotEqualBinaryNode(Node* left, Node* right):BinaryNode(left,right){}
    virtual const Literal* eval() const;
};

class GreaterEqualBinaryNode : public BinaryNode{
public:
    GreaterEqualBinaryNode(Node* left, Node* right):BinaryNode(left,right){}
    virtual const Literal* eval() const;
};

class LessBinaryNode : public BinaryNode{
public:
    LessBinaryNode(Node* left, Node* right):BinaryNode(left,right){}
    virtual const Literal* eval() const;
};

class GreaterBinaryNode : public BinaryNode{
public:
    GreaterBinaryNode(Node* left, Node* right):BinaryNode(left,right){}
    virtual const Literal* eval() const;
};

class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right);
  virtual const Literal* eval() const;
};

class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval() const;
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class ModBinaryNode : public BinaryNode {
public:
  ModBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class DouMultBinaryNode : public BinaryNode {
public:
  DouMultBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

class DouDivBinaryNode : public BinaryNode {
public:
  DouDivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval() const;
};

