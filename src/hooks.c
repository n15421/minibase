#include <hooker/hooks.h>

bool server_started = false;
TMHOOK(on_server_started, void, 8903664, uintptr_t _this)
{
    server_started = true;
    on_server_started.original(_this);
}                               

TMHOOK(on_console_output, bool, 778480, uintptr_t _this, const char *str, size_t size)
{
    if (server_started)
        printf("detour_on_console_output: %s\n", str);
    
    return on_console_output.original(_this, str, size);
}

TMHOOK(on_console_input, bool, 489760, uintptr_t _this, const char *str)
{
    puts("detour_on_console_input: ");
    puts(str);
    return on_console_input.original(_this, str);
}


bool init_hooks(void)
{
    on_console_input.init(&on_console_input);
    on_server_started.init(&on_server_started);
    on_console_output.init(&on_console_output);

    return true;
}
