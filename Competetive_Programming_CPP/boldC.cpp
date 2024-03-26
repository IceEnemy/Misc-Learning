#include <stdio.h>

#define COLOR_BOLD  "\e[1m"
#define COLOR_OFF   "\e[m"
#define COLOR_BOLD_SLOW_BLINKING_RED  "\e[1;5;31m"

int main(void)
{
    for (int i = 1; i <= 5; i++)
    {
        printf(COLOR_BOLD_SLOW_BLINKING_RED "Md.Mehedi hasan\n" COLOR_OFF);
    }

    return 0;
}

