#include "bitops.h"
#include <stdio.h>

/*
 * Return and of x and y
 * Points: 3
 */
int and_op(int x, int y) {
  return x & y;
}

/* 
 * Return or of x and y
 * Points: 3
 */
int or_op(int x, int y) {
  return x|y;
}

/*
 * Return xor of x and y
 * Points: 3
 */
int xor_op(int x, int y) {
  return x ^ y;
}


/*
 * Clear `b`th byte of x
 * Points: 7
 */
int masking_and(int x, int b) {
  return x&~(0xff << 8*(32-b));
}

/*
 * Set `b`th byte of x
 * Points: 7
 */
int masking_or(int x, int b) {
  int size = sizeof(x);
  int mask = (0xff << 8*(32-b));
  return x|mask;
}

/*
 * Toggle `b`th byte of x
 * Points: 7
 */
int masking_xor(int x, int b) {
  int size = sizeof(x);
  int mask = (0xff << 8*(size-b));
  return x^mask;
}

/*
 * Shift x to the left by `sc` # of bits
 * Points: 3
 */
int shifting_left_op(int x, int sc) {
  x = x << sc;
  return x;
}

/*
 * Shift x to the right by `sc` # of bits
 * Points: 3
 */
int shifting_right_op(int x, int sc) {
  x = x >> sc;
  return x;
}


/*
 * Return logical not of x
 * Points: 3
 */
int bang(int x) {
  return !x;
}

/*
 * Print binary string representation for x
 * Points: 30
 */
void bit_conversion(int x) {
  int answer = 0;
  int multiplier = 1;
  while (x) {
    int i = x % 2;
    answer += i * multiplier;
    multiplier *= 10;
    x = x / 2;
  }
  printf("%d\n", answer);
}
