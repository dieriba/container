#ifndef JAILER_H
#define JAILER_H
#include "clp.h"

void container_run(Command *command);
Command *init_container_command();

#endif