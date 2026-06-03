#include "clp.h"
#include "command.h"
#include "includes/container.h"

void handle_user_command(Command *user_command)
{
    switch (user_command->code)
    {
    case JAILER:
        break;
    case CONTAINER_CMD_RUN:
        container_run(user_command);
    default:
        break;
    }
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