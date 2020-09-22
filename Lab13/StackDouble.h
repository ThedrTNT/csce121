#ifndef STACKDOUBLE_H
#define STACKDOUBLE_H

class StackDouble {
 private:
  double* A;
  int capacity;
  int length;
 public:  
  StackDouble();
  ~StackDouble();
  void push(double x);
  double pop();
};
#endif
