#include "../common.h"

extern ash_session_t *session;

int command_ls(int argc, char *argv[]) {
    struct archive_entry *entry;

    // Loop through each entry in the archive
    while (archive_read_next_header(session->handler, &entry) == ARCHIVE_OK) {
        printf("name\tperm\tsize\n====\n");
        printf("%s\t%d\t%ld\n", archive_entry_pathname(entry), archive_entry_perm(entry), archive_entry_size(entry));
        archive_read_data_skip(session->handler); // Skip actual file data, if not needed
    }

    return 0;
}