#include <example/logger.h>

void server_logger(const char *msg, enum log_level level)
{
    TMCALL("?log@BedrockLog@@YAXW4LogCategory@1@V?$bitset@$02@std@@W4LogRule@1@W4LogAreaID@@IPEBDH4ZZ",
        char (*)(unsigned int a1, char a2, int a3, int a4, unsigned int a5, const char *a6, int a7, const char *a8),
        0, 1, 0, 12, level, "HOOKER->LOG", 114514, msg);
}
