#include "../../includes/container.h"
#include "mount.h"
#include "command.h"

void container_run(Command *command)
{
}

Command init_container_command()
{
    Command container;
    clp_init_command(&container, CONTAINER_CMD, "container", "Manage containers");

    Command run;
    clp_init_command(&run, CONTAINER_CMD_RUN, "run", "Create and run a new container");

    Option run_cmd_opt_ports;
    clp_init_option(&run_cmd_opt_ports, "port", "p", "Map a container's port to host ports", TYPE_STR, false, false);
    Option run_cmd_opt_mount;
    clp_init_option_kv(&run_cmd_opt_mount, MOUNT_LONG_NAME_OPT, MOUNT_SHORT_NAME_OPT, "Mount host specific path into container", false, false);
    Option run_cmd_opt_network;
    clp_init_option_kv(&run_cmd_opt_mount, "network", "n", "Manage container's network", false, false);

    clp_add_command_option(&run, &run_cmd_opt_ports);
    clp_add_command_option(&run, &run_cmd_opt_mount);
    clp_add_command_option(&run, &run_cmd_opt_network);

    return container;
}