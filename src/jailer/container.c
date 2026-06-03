#include "../../includes/container.h"
#include "mount.h"
#include "command.h"

void container_run(Command *command)
{
    handle_mount(clp_get_option_by_short(command, *MOUNT_SHORT_NAME_OPT));
}

Command init_container_command()
{
    Command container;
    clp_init_command(&container, CONTAINER_CMD, "container", "Manage containers");

    Command run;
    clp_init_command(&run, CONTAINER_CMD_RUN, "run", "Create and run a new container");

    Option mount_opt = new_mount_option();
    clp_add_command_option(&run, &mount_opt);

    clp_add_command_sub_command(&container, &run);

    return container;
}