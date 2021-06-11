#include "Example.hpp"

int factorial(int n) {
  /* return 0 to make the test fail */
  //   return 0;

  if (n == 1 || n == 0) {
    return n;
  } else {
    return (n * factorial(n - 1));
  }
}

int square(int n) { return (n * n); }