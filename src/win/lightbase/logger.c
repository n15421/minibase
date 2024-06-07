#include <stdio.h>

char g_log_level = 0;

int lb_set_loglevel(char in_level)
{
    g_log_level = in_level;
}

int lb_log(char in_log_level, const char *in_fmt, ...) {
    va_list arg = 0;
    va_start(arg, in_log_level);
    if (g_log_level >= in_log_level) vfprintf(stdout, in_fmt, arg);
    va_end(arg);

    return 0;
}