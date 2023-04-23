#include <unistd.h>

int _putchar(char ch)
{
    char c = (char)ch;  

    return write(1, &ch, 1);
}