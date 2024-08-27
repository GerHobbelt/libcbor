/*
 * Copyright (c) 2014-2020 Pavel Kalvoda <me@pavelkalvoda.com>
 *
 * libcbor is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "cbor/common.h"

// wrap RTL calls in static functions: fixes issues with MSVC crtdbg.h usage, DLL vs static/lib RTL exports, etc.

static void *my_cbor_malloc(size_t s) {
	return malloc(s);
}
static void *my_cbor_realloc(void *p, size_t s) {
	return realloc(p, s);
}
static void my_cbor_free(void *p) {
  if (p != NULL)
		free(p);
}

CBOR_EXPORT _cbor_malloc_t _cbor_malloc = my_cbor_malloc;
CBOR_EXPORT _cbor_realloc_t _cbor_realloc = my_cbor_realloc;
CBOR_EXPORT _cbor_free_t _cbor_free = my_cbor_free;

void cbor_set_allocs(_cbor_malloc_t custom_malloc,
                     _cbor_realloc_t custom_realloc, _cbor_free_t custom_free) {
  _cbor_malloc = custom_malloc;
  _cbor_realloc = custom_realloc;
  _cbor_free = custom_free;
}
