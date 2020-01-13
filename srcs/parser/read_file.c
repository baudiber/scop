#include "../../includes/scop.h"

bool    parse_file(char *file_name)
{
    int     fd;

    if ((fd = open(file_name, O_DIRECTORY) >= 0))
        return (false);
    if ((fd = open(file_name, O_RDONLY) < 0))
        return (false);
    return (true);
}