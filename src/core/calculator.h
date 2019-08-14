#ifndef CALCULATOR
#define CALCULATOR

namespace wora {
class Calculator {
public:
  Calculator() {}
  ~Calculator() {}

  double add(double a, double b);
  double subtract(double a, double b);
  double divide(double a, double b);
  double multiply(double a, double b);
};
} // namespace wora

#endif