#include <iostream>

#include "ConcreteStream.hpp"
#include "ParenthesesDecorator.hpp"
#include "CommaDecorator.hpp"
#include "NumberDecorator.hpp"

AbstractStream* buildThreeBadFormat(std::string stream) {
  AbstractStream* abs = new ConcreteStream(stream);
  abs = new ParenthesesDecorator(abs);
  abs = new CommaDecorator(abs);
  return new NumberDecorator(abs);
}

AbstractStream* buildThreeGoodFormat(std::string stream) {
  AbstractStream* abs = new ConcreteStream(stream);
  abs = new NumberDecorator(abs);
  abs = new CommaDecorator(abs);
  return new ParenthesesDecorator(abs);
}

AbstractStream* buildParentheses(std::string stream) {
  AbstractStream* abs = new ConcreteStream(stream);
  return new ParenthesesDecorator(abs);
}

AbstractStream* buildCommas(std::string stream) {
  AbstractStream* abs = new ConcreteStream(stream);
  return new CommaDecorator(abs);
}

AbstractStream* buildIntegers(std::string stream) {
  AbstractStream* abs = new ConcreteStream(stream);
  return new NumberDecorator(abs);
}

int main() {
  std::string stream;
  std::getline(std::cin, stream);
  std::cout << buildThreeBadFormat(stream)->toString() << std::endl;
  std::cout << buildThreeGoodFormat(stream)->toString() << std::endl;
  std::cout << buildParentheses(stream)->toString() << std::endl;
  std::cout << buildCommas(stream)->toString() << std::endl;
  std::cout << buildIntegers(stream)->toString() << std::endl;
}