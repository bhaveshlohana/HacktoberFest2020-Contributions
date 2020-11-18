#include "ParenthesesDecorator.hpp"

std::string ParenthesesDecorator::toString() {
  return "( " + StreamDecorator::toString() + " )";
}