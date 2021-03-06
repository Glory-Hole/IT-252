/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

int test_bitAnd(int x, int y)
{
  return x&y;
}
int test_bitNor(int x, int y)
{
  return ~(x|y);
}
int test_copyLSB(int x)
{
  return (x & 0x1) ? -1 : 0;
}
int test_evenBits(void) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i+=2)
    result |= 1<<i;
  return result;
}
int test_logicalShift(int x, int n) {
  unsigned u = (unsigned) x;
  unsigned shifted = u >> n;
  return (int) shifted;
}





int test_bang(int x)
{
  return !x;
}
int test_leastBitPos(int x) {
  int mask = 1;
  if (x == 0)
    return 0;
  while (!(mask & x)) {
    mask = mask << 1;
  }
  return mask;
}
int test_isNotEqual(int x, int y)
{
  return x != y;
}
int test_negate(int x) {
  return -x;
}
int test_isPositive(int x) {
  return x > 0;
}
int test_isNonNegative(int x) {
  return x >= 0;
}
int test_rotateLeft(int x, int n) {
  unsigned u = (unsigned) x;
  int i;
  for (i = 0; i < n; i++) {
      unsigned msb = u >> 31;
      unsigned rest = u << 1;
      u = rest | msb;
  }
  return (int) u;
}
int test_addOK(int x, int y)
{
    long long lsum = (long long) x + y;
    return lsum == (int) lsum;
}
int test_absVal(int x) {
  return (x < 0) ? -x : x;
}
int test_isNonZero(int x)
{
  return x!=0;
}
