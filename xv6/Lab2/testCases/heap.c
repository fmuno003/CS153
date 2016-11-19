#include "types.h"
#include "user.h"

#undef NULL
#define NULL ((void*)0)

#define assert(x) if (x) {} else { \
  printf(1, "%s: %d ", __FILE__, __LINE__); \
  printf(1, "assert failed (%s)\n", # x); \
  printf(1, "TEST FAILED\n"); \
  exit(); \
}

int main(int argc, char *argv[])
{
  uint sz = (uint) sbrk(0); // end of heap
  uint stackpage = (160 - 1) * 4096; // start of stack
  uint guardpage = stackpage - 4096; // start of guardpage

  // ensure they actually placed stack high...
  assert((uint) &sz > stackpage);

  // full use of heap possible
  assert((int) sbrk(guardpage - sz) != -1);
  printf(1, "TEST PASSED\n");
  exit();
}
