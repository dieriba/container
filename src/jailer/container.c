#include "../../includes/container.h"
#include "mount.h"
#include "command.h"

#define command_register_opt(cmd, opt_constructor) \
    do                                             \
    {                                              \
        Option *opt = opt_constructor();            \
        clp_add_command_option(cmd, opt);        \
    } while (0)

void container_run(Command *command)
{
    handle_mount(clp_get_option_by_short(command, *MOUNT_SHORT_NAME_OPT));
}

Command *init_container_command()
{
    Command *container = clp_new_command(CONTAINER_CMD, "container", "Manage containers");
    Command *run = clp_new_command(CONTAINER_CMD_RUN, "run", "Create and run a new container");
    command_register_opt(run, new_mount_option);

    clp_add_command_sub_command(container, run);
    return container;
}