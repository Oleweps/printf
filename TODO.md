#### building printf

* Authorized functions and macros

## need to include:
    #include <unistd.h>
    #include <fcntl.h>
    > write (man 2 write)

## need to include:
    #include <stdlib.h>
    - malloc (man 3 malloc)
    - free (man 3 free)

## need to include:
    #include <stdarg.h>
    - va_start (man 3 va_start)
    - va_end (man 3 va_end)
    - va_copy (man 3 va_copy)
    - va_arg (man 3 va_arg)

write(1, buf, strlen(buf));

- prototype:
# void _printf(cont char* const *str, ....);


1. look for % symbol:

2. check what follows next after the percent:

3. store symbols in a struct for different values we will print

