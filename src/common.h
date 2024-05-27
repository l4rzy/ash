#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <archive.h>
#include <archive_entry.h>

typedef struct _ash_session_t {
    char *archive_name;
    struct archive *handler;
} ash_session_t;

#endif