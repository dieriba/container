#include "d_error.h"
#include "parse.h"

void cleanup()
{
    
}

int main(int argc, char **argv, char **envp)
{
    DError error;
    if (parse_args(argv, &error) != D_OK)
        goto end;

end:
    cleanup();
}