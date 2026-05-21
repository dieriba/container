#ifndef MOUNT_H
#define MOUNT_H

#define MOUNT_OPT "mount"
#define MOUNT_OPT_KEY_SRC MOUNT_OPT "src"
#define MOUNT_OPT_KEY_DST MOUNT_OPT "dst"


void mount(const char*src, const char*dst);

#endif