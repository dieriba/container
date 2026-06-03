#include "mount.h"

static void mount(const char *src, const char *dst)
{
}

Option new_mount_option()
{
    Option run_cmd_opt_mount;
    clp_init_option_kv(&run_cmd_opt_mount, MOUNT_LONG_NAME_OPT, MOUNT_SHORT_NAME_OPT, "Mount host specific path into container", false, false);
    return run_cmd_opt_mount;
}

void handle_mount(Option *mount_opt)
{
}