#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <stdlib.h>
#include "lib_tar.h"

/**
 * You are free to use this file to write tests for your implementation
 */

void debug_dump(const uint8_t *bytes, size_t len) {
    for (int i = 0; i < len;) {
        printf("%04x:  ", (int) i);

        for (int j = 0; j < 16 && i + j < len; j++) {
            printf("%02x ", bytes[i + j]);
        }
        printf("\t");
        for (int j = 0; j < 16 && i < len; j++, i++) {
            printf("%c ", bytes[i]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s tar_file\n", argv[0]);
        return -1;
    }

    int fd = open(argv[1] , O_RDONLY);
    if (fd == -1) {
        perror("open(tar_file)");
        return -1;
    }

    int ret = check_archive(fd);
    printf("check_archive returned %d\n", ret);

    int exist = exists(fd,"fake path");
    printf("exists : %d\n", exist);

    exist = exists(fd,"slides/1b-teaserHand.pdf");// dont really need the 1b-teaserHand.pdf
    printf("correct exists : %d \n",exist);

    int dir = is_dir(fd, "slides/1b-teaserHand.pdf");
    printf("1 if its the dir : %d\n", dir);

    //test list
    size_t no_entries = 50;
    char** entries = (char**) malloc(sizeof(char*) * no_entries);
    for(int i = 0 ; i < no_entries; i++){
        entries[i] = malloc(300);
    }
    int list_check = list(fd, "slides/",entries,&no_entries);
    printf("list check : %d \n", list_check);
    printf("total entries = %ld \n", no_entries);
    for(int i = 0 ; i < no_entries; i++){
        printf("%s\n", entries[i]);
    }

    for(int i = 0 ; i < no_entries; i++){
        free(entries[i]);
    }
    free(entries);

    size_t value = 5000;

    size_t *len = &value;

    uint8_t * dest = (uint8_t *) malloc((*len));

    int read_check = read_file(fd, "slides/",0, dest, len);

    printf("READ CHECK :\n %d\n",read_check);
    printf("TEXT :\n %s\n", dest);
    printf("value length :%ld\n", *len);
    free(dest);
    return 0;
}