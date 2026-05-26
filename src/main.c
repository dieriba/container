#include "clp.h"
#include "jailer.h"

typedef enum COMMAND
{
    JAILER,
    CONTAINER_CMD,
    CONTAINER_CMD_RUN,
} COMMAND;

void handle_user_command(Command *user_command)
{
    switch (user_command->code)
    {
    case JAILER:
        break;
    case CONTAINER_CMD_RUN:
        jailer_container_run(user_command);
    default:
        break;
    }
}

static Command init_container_command()
{
    Command container;
    clp_init_command(&container, CONTAINER_CMD, "container", "Manage containers");

    Command run;
    clp_init_command(&run, CONTAINER_CMD_RUN, "run", "Create and run a new container");

    Option run_cmd_opt_ports;
    clp_init_option(&run_cmd_opt_ports, "port", "p", "Map a container's port to host ports", TYPE_STR, false, false);
    Option run_cmd_opt_mount;
    clp_init_option_kv(&run_cmd_opt_mount, "mount", "m", "Mount host specific path into container", false, false);
    Option run_cmd_opt_network;
    clp_init_option_kv(&run_cmd_opt_mount, "network", "n", "Manage container's network", false, false);
    
    clp_add_command_option(&run, &run_cmd_opt_ports);
    clp_add_command_option(&run, &run_cmd_opt_mount);
    clp_add_command_option(&run, &run_cmd_opt_network);

    return container;
}

int main(int argc, char **argv, char **envp)
{
    Command root;
    clp_init_command(&root, JAILER, "jailer", "");
    Command container = init_container_command();

    clp_add_command_sub_command(&root, &container);
    Command *user_command = NULL;
    clp_parse_args(&root, argv, &user_command);
    handle_user_command(user_command);
    clp_cleanup(&root);
}