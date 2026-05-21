#include "clp.h"

typedef enum COMMAND
{
    CONTAINER,
    CONTAINER_CMD_RUN,
} COMMAND;

void container_cmd_run(Command *command)
{
    
}

void handle_user_command(Command *user_command)
{
    switch (user_command->code)
    {
    case CONTAINER:
        break;
    case CONTAINER_CMD_RUN:
        container_cmd_run(user_command);
    default:
        break;
    }
}

int main(int argc, char **argv, char **envp)
{
    Command *user_command;

    Command root;
    clp_init_command(&root, "container", "", CONTAINER);

    Command run;
    clp_init_command(&run, "run", "run a container", CONTAINER_CMD_RUN);

    clp_add_command_sub_command(&root, &run);
    clp_parse_args(&root, argv, &user_command);
    handle_user_command(user_command);
end:
    clp_cleanup(&root);
}