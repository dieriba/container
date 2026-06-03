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

    Option run_cmd_opt_mount;
    clp_init_option_kv(&run_cmd_opt_mount, MOUNT_LONG_NAME_OPT, MOUNT_SHORT_NAME_OPT, "Mount host specific path into container", false, false);


    clp_add_command_option(&run, &run_cmd_opt_mount);

    clp_add_command_sub_command(&container, &run);

    return container;
}