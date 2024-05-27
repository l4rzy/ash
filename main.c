#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <archive.h>
#include <archive_entry.h>

#define MAX_COMMAND_LENGTH 1024
#define ASH_VER_MAJ 0
#define ASH_VER_MIN 1

typedef struct _ash_session_t {
    char *archive_name;
    struct archive *handler;
} ash_session_t;

static ash_session_t *session;

int command_ls() {
    struct archive_entry *entry;

    // Loop through each entry in the archive
    while (archive_read_next_header(session->handler, &entry) == ARCHIVE_OK) {
        printf("name\tperm\tsize\n====\n");
        printf("%s\t%d\t%ld\n", archive_entry_pathname(entry), archive_entry_perm(entry), archive_entry_size(entry));
        archive_read_data_skip(session->handler); // Skip actual file data, if not needed
    }

    return 0;
}

int command_help() {
    printf("tbd\n");
    return 0;
}

int process_command(const char *command) {
    // Process the command here
    if (!strncmp(command, "ls", 2)) {
        return command_ls();
    }
    if (!strncmp(command, "help", 4)) {
        return command_help();
    }
    printf("error: command `%s` is not implemented\n", command);
    return 1;
}

int ash_banner() {
	printf("ash - archive shell, version %d.%d\n", ASH_VER_MAJ, ASH_VER_MIN);
	return 0;
}

int ash_cmd_helper(char *prog_name) {
	ash_banner();
	printf("\nUsage:\n%s <archive name>\n", prog_name);
	return 0;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		ash_cmd_helper(argv[0]);
		return 1;
	}

    // initiate crucial program structure
    session = malloc(sizeof(ash_session_t));
    int r;
    // Open the archive file for reading
    session->handler = archive_read_new();
    archive_read_support_format_all(session->handler);
    r = archive_read_open_filename(session->handler, argv[1], 10240);
    if (r != ARCHIVE_OK) {
        fprintf(stderr, "Error opening archive file: %s\n", archive_error_string(session->handler));
        return 1;
    }

    char *input;

    // Initialize the readline library
    rl_bind_key('\t', rl_complete);

	// print banner
	ash_banner();

    // Main loop for reading and processing commands
    while (1) {
        input = readline(">> "); // Displaying prompt
        if (!input) {
            // User pressed Ctrl+D (EOF)
            printf("Goodbye!\n");
            break;
        }

        if (strlen(input) > 0) {
            // Add input to history
            add_history(input);

            // Process the command
            process_command(input);
        }

        // Free memory allocated by readline
        free(input);
    }

    return 0;
}
