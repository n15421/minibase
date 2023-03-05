#include <hooker/hook_api/hook.h>

bool hook_func(void *hook_func, void *detour_func, void *original_func)
{
    if (MH_CreateHook(hook_func, detour_func, (LPVOID *)original_func) != MH_OK)
    {
        printf("Failed to create func hook, RVA: %llu \n", (uintptr_t)hook_func);
        return false;
    }
    if (MH_EnableHook(hook_func) != MH_OK)
    {
        printf("Failed to enable func hook, RVA: %llu \n", (uintptr_t)hook_func);
        return false;
    }
    return true;
}

void *get_rva_func(unsigned int rva)
{
    uintptr_t base_addr = (uintptr_t)GetModuleHandle(NULL);
    return (void *)(base_addr + rva + 4096);
}

void *get_sym_func(const char *sym)
{
    static bool is_sym_file_generated = false;
    FILE *fp = fopen(SYM_FILE, "r");
    if (!fp)
    {
        printf("Symbol file " SYM_FILE " not found, trying to generate.\n");

        fopen("cvdump.exe", "r")
            ? system("cvdump.exe -headers -p bedrock_server.pdb > " SYM_FILE )
            : printf("cvdump.exe not found, please download it from " CVDUMP_URL "\n");
        
        fp = fopen(SYM_FILE, "r");
        if (!fp)
        {
            if (!is_sym_file_generated)
            {
                printf("Failed to generate. \n");
                is_sym_file_generated = true;
            }
            printf("The symbol %s will not be parsed. \n", sym);
            return NULL;
        }
    }

    char *rva_val_str = NULL;
    unsigned int rva_val = 0;

    const size_t MAX_LINE_LENGTH = 2048;
    char *line = malloc((MAX_LINE_LENGTH + 1) * sizeof(char));

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL)
    {
        if (strstr(line, sym))
        {
            rva_val_str = strtok(line, ":");
            rva_val_str = strtok(NULL, ", ");
            sscanf(rva_val_str, "[%*x:%x]", &rva_val);
            break;
        }
    }

    free(line);
    fclose(fp);

    return get_rva_func(rva_val);
}
