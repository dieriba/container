#ifndef PARSE_H
#define PARSE_H
#include "d_result.h"
#include "d_error.h"

DResult parse_args(char **argv, DError *error);

#endif