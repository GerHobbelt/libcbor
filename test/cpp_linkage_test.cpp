/*
 * Copyright (c) 2014-2020 Pavel Kalvoda <me@pavelkalvoda.com>
 *
 * libcbor is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include <iostream>
#include "cbor.h"

#if defined(BUILD_MONOLITHIC)
#define main cbor_cpp_linkage_test_main
#endif

extern "C"
int main() {
	std::cout << "Hello from libcbor " << CBOR_VERSION << std::endl;
  return 0;
}
