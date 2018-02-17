#include "node.h"
#include "poolOfNodes.h"
#include<math.h>

class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual const Literal* operator==(const Literal& rhs) const = 0;
  virtual const Literal* equalEqual(float) const = 0;
  virtual const Literal* equalEqual(int) const = 0;

  virtual const Literal* operator<=(const Literal& rhs) const = 0;
  virtual const Literal* lessEqual(float) const = 0;
  virtual const Literal* lessEqual(int) const = 0;

  virtual const Literal* operator>=(const Literal& rhs) const = 0;
  virtual const Literal* greaterEqual(float) const = 0;
  virtual const Literal* greaterEqual(int) const = 0;

  virtual const Literal* operator<(const Literal& rhs) const = 0;
  virtual const Literal* less(float) const = 0;
  virtual const Literal* less(int) const = 0;

  virtual const Literal* operator>(const Literal& rhs) const = 0;
  virtual const Literal* greater(float) const = 0;
  virtual const Literal* greater(int) const = 0;

  virtual const Literal* notEqual(const Literal& rhs) const = 0;
  virtual const Literal* optNotEqual(float) const = 0;
  virtual const Literal* optNotEqual(int) const = 0;

  virtual const Literal* operator+(const Literal& rhs) const =0;
  virtual const Literal* opPlus(float) const =0;
  virtual const Literal* opPlus(int) const =0;

  virtual const Literal* operator*(const Literal& rhs) const =0;
  virtual const Literal* opMult(float) const =0;
  virtual const Literal* opMult(int) const =0;

  virtual const Literal* operator-(const Literal& rhs) const =0;
  virtual const Literal* opSubt(float) const =0;
  virtual const Literal* opSubt(int) const =0;

  virtual const Literal* operator/(const Literal& rhs) const =0;
  virtual const Literal* opDiv(float) const =0;
  virtual const Literal* opDiv(int) const =0;

  virtual const Literal* operator%(const Literal& rhs) const =0;
  virtual const Literal* opMod(float) const =0;
  virtual const Literal* opMod(int) const =0;

  virtual const Literal* DouMult(const Literal& rhs) const =0;
  virtual const Literal* opDouMult(float) const =0;
  virtual const Literal* opDouMult(int) const =0;

  virtual const Literal* DouDiv(const Literal& rhs) const =0;
  virtual const Literal* opDouDiv(float) const =0;
  virtual const Literal* opDouDiv(int) const =0;

  virtual const Literal* eval() const = 0;
  virtual  bool isTrue() const = 0;
  virtual void print() const {
    std::cout << "No Way" << std::endl;
  }
};

class FloatLiteral: public Literal {
public:
  FloatLiteral(float _val): val(_val) {}

  virtual const Literal* operator==(const Literal& rhs) const {
      return rhs.equalEqual(val);
  }
  virtual const Literal* equalEqual(float lhs) const {
      const Literal* node;
      if(lhs == val) node = new FloatLiteral(1);
      else node = new FloatLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }
  virtual const Literal* equalEqual(int lhs) const {
      const Literal* node;
      if(static_cast<float>(lhs) == val) node = new FloatLiteral(1);
      else node = new FloatLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }

  virtual const Literal* operator<=(const Literal& rhs) const {
      return rhs.lessEqual(val);
  }
  virtual const Literal* lessEqual(float lhs) const {
      const Literal* node;
      if( lhs <= val) node = new FloatLiteral(1);
      else node = new FloatLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }
  virtual const Literal* lessEqual(int lhs) const {
      const Literal* node;
      if(static_cast<float>(lhs) <= val) node = new FloatLiteral(1);
      else node = new FloatLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }

  virtual const Literal* operator>=(const Literal& rhs) const {
      return rhs.greaterEqual(val);
  }
  virtual const Literal* greaterEqual(float lhs) const {
      const Literal* node;
      if(lhs >= val) node = new FloatLiteral(1);
      else node = new FloatLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }
  virtual const Literal* greaterEqual(int lhs) const {
      const Literal* node;
      if(static_cast<float>(lhs) >= val) node = new FloatLiteral(1);
      else node = new FloatLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }

  virtual const Literal* operator<(const Literal& rhs) const {
      return rhs.less(val);
  }
  virtual const Literal* less(float lhs) const {
      const Literal* node;
      if(lhs < val) node = new FloatLiteral(1);
      else node = new FloatLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }
  virtual const Literal* less(int lhs) const {
      const Literal* node;
      if(static_cast<float>(lhs) < val) node = new FloatLiteral(1);
      else node = new FloatLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }

  virtual const Literal* operator>(const Literal& rhs) const {
      return rhs.greater(val);
  }
  virtual const Literal* greater(float lhs) const {
      const Literal* node;
      if(lhs > val) node = new FloatLiteral(1);
      else node = new FloatLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }
  virtual const Literal* greater(int lhs) const {
      const Literal* node;
      if(static_cast<float>(lhs) > val) node = new FloatLiteral(1);
      else node = new FloatLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }

  virtual const Literal* notEqual(const Literal& rhs) const {
      return rhs.optNotEqual(val);
  }
  virtual const Literal* optNotEqual(float lhs) const {
      const Literal* node;
      if(lhs != val) node = new FloatLiteral(1);
      else node = new FloatLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }
  virtual const Literal* optNotEqual(int lhs) const {
      const Literal* node;
      if(static_cast<float>(lhs) != val) node = new FloatLiteral(1);
      else node = new FloatLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(lhs) * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opMod(val);
  }
  virtual const Literal* opMod(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(fmod(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(fmod(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* DouMult(const Literal& rhs) const  {
    return rhs.opDouMult(val);
  }
  virtual const Literal* opDouMult(float lhs) const  {
    const Literal* node = new FloatLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDouMult(int lhs) const  {
    const Literal* node = new FloatLiteral(pow(static_cast<float>(lhs), val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* DouDiv(const Literal& rhs) const  {
    return rhs.opDouDiv(val);
  }
  virtual const Literal* opDouDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDouDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* eval() const { return this; }
  virtual bool isTrue() const {
      if(!val) return false;
      return true;
  }
  virtual void print() const {
    std::cout << val << std::endl;
  }
private:
  float val;
};

class IntLiteral: public Literal {
public:
 IntLiteral(int _val): val(_val) {}

  virtual const Literal* operator==(const Literal& rhs) const {
      return rhs.equalEqual(val);
  }
  virtual const Literal* equalEqual(float lhs) const {
      const Literal* node;
      if(lhs == static_cast<float>(val)) node = new IntLiteral(1);
      else node = new IntLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }
  virtual const Literal* equalEqual(int lhs) const {
      const Literal* node;
      if(lhs == val) node = new IntLiteral(1);
      else node = new IntLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }

  virtual const Literal* operator<=(const Literal& rhs) const {
      return rhs.lessEqual(val);
  }
  virtual const Literal* lessEqual(float lhs) const {
      const Literal* node;
      if(lhs <= static_cast<float>(val)) node = new IntLiteral(1);
      else node = new IntLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }
  virtual const Literal* lessEqual(int lhs) const {
      const Literal* node;
      if(lhs <= val) node = new IntLiteral(1);
      else node = new IntLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }

  virtual const Literal* operator>=(const Literal& rhs) const {
      return rhs.greaterEqual(val);
  }
  virtual const Literal* greaterEqual(float lhs) const {
      const Literal* node;
      if(lhs >= static_cast<float>(val)) node = new IntLiteral(1);
      else node = new IntLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }
  virtual const Literal* greaterEqual(int lhs) const {
      const Literal* node;
      if(lhs >= val) node = new IntLiteral(1);
      else node = new IntLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }

  virtual const Literal* operator<(const Literal& rhs) const {
      return rhs.less(val);
  }
  virtual const Literal* less(float lhs) const {
      const Literal* node;
      if(lhs < static_cast<float>(val)) node = new IntLiteral(1);
      else node = new IntLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }
  virtual const Literal* less(int lhs) const {
      const Literal* node;
      if(lhs < val) node = new IntLiteral(1);
      else node = new IntLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }

  virtual const Literal* operator>(const Literal& rhs) const {
      return rhs.greater(val);
  }
  virtual const Literal* greater(float lhs) const {
      const Literal* node;
      if(lhs > static_cast<float>(val)) node = new IntLiteral(1);
      else node = new IntLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }
  virtual const Literal* greater(int lhs) const {
      const Literal* node;
      if(lhs > val) node = new IntLiteral(1);
      else node = new IntLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }

  virtual const Literal* notEqual(const Literal& rhs) const {
      return rhs.optNotEqual(val);
  }
  virtual const Literal* optNotEqual(float lhs) const {
      const Literal* node;
      if(lhs != static_cast<float>(val)) node = new IntLiteral(1);
      else node = new IntLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }
  virtual const Literal* optNotEqual(int lhs) const {
      const Literal* node;
      if(lhs != val) node = new IntLiteral(1);
      else node = new IntLiteral(0);
      PoolOfNodes::getInstance().add(node);
      return node;
  }


  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(val) + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new IntLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new IntLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new IntLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node;
    if(lhs/val <= (float)lhs/(float)val){
         node = new IntLiteral(lhs/val);
    }
    else{
         node = new IntLiteral(lhs/val - 1);
    }
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const  {
    return rhs.opMod(val);
  }
  virtual const Literal* opMod(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(fmod(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMod(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new IntLiteral(lhs % val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* DouMult(const Literal& rhs) const  {
    return rhs.opDouMult(val);
  }
  virtual const Literal* opDouMult(float lhs) const  {
    const Literal* node = new FloatLiteral(pow(lhs , val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDouMult(int lhs) const  {
    const Literal* node = new IntLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* DouDiv(const Literal& rhs) const  {
    return rhs.opDouDiv(val);
  }
  virtual const Literal* opDouDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDouDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new IntLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* eval() const { return this; }
  virtual bool isTrue() const{
      if(!val) return false;
      return true;
  }
  virtual void print() const {
    std::cout << val << std::endl;
  }
private:
  int val;
};

class NoneLiteral : public IntLiteral{
public:
    NoneLiteral() : IntLiteral(0){}
    virtual const Literal* eval() const{return this;}
    virtual void print() const{
        std::cout<<"None"<<std::endl;
    }
};

