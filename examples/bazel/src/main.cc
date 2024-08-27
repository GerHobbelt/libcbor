#include "src/hello.h"

#include <stdio.h>

#if defined(BUILD_MONOLITHIC)
#define main cbor_version_example_main
#endif

extern "C"
int main() {
  print_cbor_version();
  
  return 0;
}

