#include "mount.h"

static void mount(const char *src, const char *dst)
{
}

Option *new_mount_option()
{
    return clp_new_option_kv(MOUNT_LONG_NAME_OPT, MOUNT_SHORT_NAME_OPT, "Mount host specific path into container", false, false);
}

void handle_mount(Option *mount_opt)
{
    
}