#include "lib_tar.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>


/* THIS IS THE LOOP TO GO THROUGH ALL THE THINGS
tar_header_t* header;
char* buffer = malloc(sizeof(char)*512);
header = (tar_header_t*) buffer;
read(tar_fd,buffer,512);
while(not_last_block(header)){



/////////////////////////////////
    int size = TAR_INT(header->size);

    if ( size%512 == 0 ){ //if size is perfectly 512 size
        lseek(tar_fd , size, SEEK_CUR);
    }

    else{
        lseek(tar_fd, ((size/512) +1) * 512,SEEK_CUR);
    }

    read(tar_fd, buffer , 512);
    header = (tar_header_t*) buffer;
    //        printf("the size is %d\n",size);
    //        fflush(stdout);

}
lseek(tar_fd, 0 , SEEK_SET);
free(buffer);
*/

int find_check_sum(tar_header_t* header){
    int count=0;
    char* data = (char*) header;
    for(int i = 0 ; i < 512 ; i++){ // checksum starts at 148 and ends at 156
        if( i < 148 || i >=156 ){
            count += data[i];
        }
        else{// in the checksum
            //0x20 means space
            count += 0x20;
        }
    }
    return count;
}
//check if block is not the last
int not_last_block(tar_header_t *header){


    char* data = (char *) header;

    for (int i = 0 ; i < 512 ; i++){
        if( data[i] != 0){
            return 1; //there is something in the header
        }
    }
    return 0; //empty block

}
/**
 * Checks whether the archive is valid.
 *
 * Each non-null header of a valid archive has:
 *  - a magic value of "ustar" and a null,
 *  - a version value of "00" and no null,
 *  - a correct checksum
 *
 * @param tar_fd A file descriptor pointing to the start of a file supposed to contain a tar archive.
 *
 * @return a zero or positive value if the archive is valid, representing the number of non-null headers in the archive,
 *         -1 if the archive contains a header with an invalid magic value,
 *         -2 if the archive contains a header with an invalid version value,
 *         -3 if the archive contains a header with an invalid checksum value
 */
int check_archive(int tar_fd) {
    tar_header_t* header;
    char* buffer = malloc(sizeof(char)*512);
    int non_null_headers = 0;
    header = (tar_header_t*) buffer;
    read(tar_fd,buffer,512);
    while(not_last_block(header)){

        //check magic value
        //        printf("hi %d\n",strcmp(header.magic, TMAGIC));
        if(strcmp(header->magic, TMAGIC)){
            lseek(tar_fd,0,SEEK_SET);
            //            free(header);
            return -1;
        }
        //check version value
        //        printf("hi\n");
        if((header->version[0]!= REGTYPE) || (header->version[1] != REGTYPE)){ // equivalent to regtype and aregtype
            lseek(tar_fd,0,SEEK_SET);
            return -2;
        }
        //verify the checksum
        //        printf("hi\n");
        int checksum = find_check_sum(header);
        if(TAR_INT(header->chksum) != checksum){
            lseek(tar_fd,0,SEEK_SET);
            //            free(header);
            return -3;
        }
        non_null_headers++;
        //all preliminary conditions done
        //move pointer
        int size = TAR_INT(header->size);

        if ( size%512 == 0 ){ //if size is perfectly 512 size
            lseek(tar_fd , size, SEEK_CUR);
        }

        else{
            lseek(tar_fd, ((size/512) +1) * 512,SEEK_CUR);
        }
        read(tar_fd, buffer ,512);
        header = (tar_header_t*) buffer;
        //        printf("the size is %d\n",size);
        //        fflush(stdout);

    }
    lseek(tar_fd, 0 , SEEK_SET);
    free(buffer);
    return non_null_headers;
}

/**
 * Checks whether an entry exists in the archive.
 *
 * @param tar_fd A file descriptor pointing to the start of a valid tar archive file.
 * @param path A path to an entry in the archive.
 *
 * @return zero if no entry at the given path exists in the archive,
 *         any other value otherwise.
 */
int exists(int tar_fd, char *path) {
    tar_header_t* header;
    char* buffer = malloc(sizeof(char)*512);
    header = (tar_header_t*) buffer;
    read(tar_fd,buffer,512);
    while(not_last_block(header)){
        if(header->name[0] == AREGTYPE){
            break;
        }
        //check if its a file
        if(header ->name[0] == AREGTYPE){
            break;
        }

        if(!strcmp(header->name,path)){
            lseek(tar_fd, 0, SEEK_SET);
            return 1;
        }

        int size = TAR_INT(header->size);

        if ( size%512 == 0 ){ //if size is perfectly 512 size
            lseek(tar_fd , size, SEEK_CUR);
        }

        else{
            lseek(tar_fd, ((size/512) +1) * 512, SEEK_CUR);
        }

        read(tar_fd, buffer, 512);//we need to use a buffer
        header = (tar_header_t*) buffer;
        //        printf("the size is %d\n",size);
        //        fflush(stdout);

    }
    lseek(tar_fd, 0 , SEEK_SET);
    free(buffer);
    return 0;
}

/**
 * Checks whether an entry exists in the archive and is a directory.
 *
 * @param tar_fd A file descriptor pointing to the start of a valid tar archive file.
 * @param path A path to an entry in the archive.
 *
 * @return zero if no entry at the given path exists in the archive or the entry is not a directory,
 *         any other value otherwise.
 */
int is_dir(int tar_fd, char *path) {
    tar_header_t* header;
    char* buffer = malloc(sizeof(char)*512);
    header = (tar_header_t*) buffer;
    read(tar_fd,buffer,512);
    while(not_last_block(header)){
        if(header->name[0] == AREGTYPE){
            break;
        }
        if(!strcmp(header->name,path) && (header->typeflag == DIRTYPE)){
            free(buffer);
            lseek(tar_fd, 0, SEEK_SET);
            return 1;
        }

        int size = TAR_INT(header->size);

        if ( size%512 == 0 ){ //if size is perfectly 512 size
            lseek(tar_fd , size, SEEK_CUR);
        }

        else{
            lseek(tar_fd, ((size/512) +1) * 512,SEEK_CUR);
        }

        read(tar_fd, buffer , 512);
        header = (tar_header_t*) buffer;
        //        printf("the size is %d\n",size);
        //        fflush(stdout);
    }
    lseek(tar_fd, 0 , SEEK_SET);
    free(buffer);
    return 0;
}

/**
 * Checks whether an entry exists in the archive and is a file.
 *
 * @param tar_fd A file descriptor pointing to the start of a valid tar archive file.
 * @param path A path to an entry in the archive.
 *
 * @return zero if no entry at the given path exists in the archive or the entry is not a file,
 *         any other value otherwise.
 */
int is_file(int tar_fd, char *path) {
    tar_header_t* header;
    char* buffer = malloc(sizeof(char)*512);
    header = (tar_header_t*) buffer;
    read(tar_fd,buffer,512);
    while(not_last_block(header)){
        if(header->name[0] == AREGTYPE){
            break;
        }
        if(!strcmp(header->name,path) && (header->typeflag == REGTYPE || header->typeflag == AREGTYPE)){
            free(buffer);
            lseek(tar_fd, 0, SEEK_SET);
            return 1;
        }

        int size = TAR_INT(header->size);

        if ( size%512 == 0 ){ //if size is perfectly 512 size
            lseek(tar_fd , size, SEEK_CUR);
        }

        else{
            lseek(tar_fd, ((size/512) +1) * 512,SEEK_CUR);
        }

        read(tar_fd, buffer , 512);
        header = (tar_header_t*) buffer;
        //        printf("the size is %d\n",size);
        //        fflush(stdout);
    }
    lseek(tar_fd, 0 , SEEK_SET);
    free(buffer);
    return 0;
}

/**
 * Checks whether an entry exists in the archive and is a symlink.
 *
 * @param tar_fd A file descriptor pointing to the start of a valid tar archive file.
 * @param path A path to an entry in the archive.
 * @return zero if no entry at the given path exists in the archive or the entry is not symlink,
 *         any other value otherwise.
 */
int is_symlink(int tar_fd, char *path) {
    tar_header_t* header;
    char* buffer = malloc(sizeof(char)*512);
    header = (tar_header_t*) buffer;
    read(tar_fd,buffer,512);
    while(not_last_block(header)){

        if(!strcmp(header->name,path) && (header->typeflag == SYMTYPE)){
            free(buffer);
            lseek(tar_fd, 0, SEEK_SET);
            return 1;
        }

        int size = TAR_INT(header->size);

        if ( size%512 == 0 ){ //if size is perfectly 512 size
            lseek(tar_fd , size, SEEK_CUR);
        }

        else{
            lseek(tar_fd, ((size/512) +1) * 512,SEEK_CUR);
        }

        read(tar_fd, buffer , 512);
        header = (tar_header_t*) buffer;
        //        printf("the size is %d\n",size);
        //        fflush(stdout);
    }
    lseek(tar_fd, 0 , SEEK_SET);
    free(buffer);
    return 0;
}


/**
 * Lists the entries at a given path in the archive.
 * list() does not recurse into the directories listed at the given path.
 *
 * Example:
 *  dir/          list(..., "dir/", ...) lists "dir/a", "dir/b", "dir/c/" and "dir/e/"
 *   ├── a
 *   ├── b
 *   ├── c/
 *   │   └── d
 *   └── e/
 *
 * @param tar_fd A file descriptor pointing to the start of a valid tar archive file.
 * @param path A path to an entry in the archive. If the entry is a symlink, it must be resolved to its linked-to entry.
 * @param entries An array of char arrays, each one is long enough to contain a tar entry path.
 * @param no_entries An in-out argument.
 *                   The caller set it to the number of entries in `entries`.
 *                   The callee set it to the number of entries listed.
 *
 * @return zero if no directory at the given path exists in the archive,
 *         any other value otherwise.
 */


int list(int tar_fd, char *path, char **entries, size_t *no_entries) {
    if(!exists(tar_fd, path)){
        *no_entries = 0;
        return 0;
    }


    if(is_symlink(tar_fd, path)){
        tar_header_t* header;
        char* buffer = malloc(sizeof(char)*512);
        header = (tar_header_t*) buffer;
        read(tar_fd,buffer,512);
        while(not_last_block(header)){
            /////////////////////////////////
            if(header->typeflag == SYMTYPE && !strcmp(header->name,path) ){
                lseek(tar_fd, 0, SEEK_SET);

                return list(tar_fd, header->linkname, entries, no_entries);
            }

            /////////////////////////////////
            int size = TAR_INT(header->size);

            if ( size%512 == 0 ){ //if size is perfectly 512 size
                lseek(tar_fd , size, SEEK_CUR);
            }

            else{
                lseek(tar_fd, ((size/512) +1) * 512,SEEK_CUR);
            }

            read(tar_fd, buffer , 512);
            header = (tar_header_t*) buffer;
            //        printf("the size is %d\n",size);
            //        fflush(stdout);

        }
        free(buffer);
    }


    int path_length = strlen(path);

    //    printf("hello\n");
    if(!exists(tar_fd,path) || is_file(tar_fd,path) || !is_dir(tar_fd, path) ){
        //        printf("exit\n");
        *no_entries = 0 ;
        return 0;
    }
    //time to go through again
    tar_header_t* header;
    lseek(tar_fd , 0 , SEEK_SET);
    char* buffer = malloc(sizeof(char)*512);
    header = (tar_header_t*) buffer;
    read(tar_fd,buffer,512);
    int total_entries = 0;
    while(not_last_block(header)){
        //        printf("hello");


        if(strcmp(header->name,path) && !strncmp(header->name,path,path_length)){
            //            printf("in");
            int name_length = strlen(header->name);
            char* extracted_entry = malloc(name_length - path_length + 1);


            for(int i = 0; i < name_length-path_length; i++){
                extracted_entry[i] = header->name[i+path_length];
            }
            extracted_entry[name_length - path_length] = AREGTYPE;
            //we hav to check the sub directory


            //check if extract4ed naem is not a file in of itself
            int extracted_entry_length = strlen(extracted_entry);
            if(extracted_entry_length == 1){
                strcpy(entries[total_entries],extracted_entry);
                total_entries++;
            }
            else{
                int do_copy = 1;
                for(int i = extracted_entry_length-2; i > 0 ; i--){
                    if(extracted_entry[i] == '/'){
                        do_copy = 0;
                    }
                }
                if(do_copy==1){
                    strcpy(entries[total_entries],extracted_entry);
                    total_entries++;
                }
            }
            free(extracted_entry);
        }


        /////////////////////////////////
        int size = TAR_INT(header->size);

        if ( size%512 == 0 ){ //if size is perfectly 512 size
            lseek(tar_fd , size, SEEK_CUR);
        }

        else{
            lseek(tar_fd, ((size/512) +1) * 512,SEEK_CUR);
        }

        read(tar_fd, buffer , 512);
        header = (tar_header_t*) buffer;
        //        printf("the size is %d\n",size);
        //        fflush(stdout);

    }
    *no_entries = total_entries;
    lseek(tar_fd, 0 , SEEK_SET);
    free(buffer);


    return 1;
}

/**
 * Reads a file at a given path in the archive.
 *
 * @param tar_fd A file descriptor pointing to the start of a valid tar archive file.
 * @param path A path to an entry in the archive to read from.  If the entry is a symlink, it must be resolved to its linked-to entry.
 * @param offset An offset in the file from which to start reading from, zero indicates the start of the file.
 * @param dest A destination buffer to read the given file into.
 * @param len An in-out argument.
 *            The caller set it to the size of dest.
 *            The callee set it to the number of bytes written to dest.
 *
 * @return -1 if no entry at the given path exists in the archive or the entry is not a file,
 *         -2 if the offset is outside the file total length,
 *         zero if the file was read in its entirety into the destination buffer,
 *         a positive value if the file was partially read, representing the remaining bytes left to be read to reach
 *         the end of the file.
 *
 */
ssize_t read_file(int tar_fd, char *path, size_t offset, uint8_t *dest, size_t *len) {
    //check offset
    if((offset<0) || (offset >= *len)){
        *len = 0;
        return -2;
    }
    //check if it exists
    if(!exists(tar_fd, path)){
        *len = 0;
        return -1;
    }
    if(is_symlink(tar_fd , path)){
        tar_header_t* header;
        char* buffer = malloc(sizeof(char)*512);
        header = (tar_header_t*) buffer;
        read(tar_fd,buffer,512);
        while(not_last_block(header)){
            if(!strcmp(header->name,path)){
                if(header->typeflag == SYMTYPE){
                    lseek(tar_fd , 0 , SEEK_SET);
                    return read_file(tar_fd, header->linkname, offset ,dest, len);
                }
                if(header->typeflag == DIRTYPE){
                    *len = 0;
                    return -1;
                }
            }


            /////////////////////////////////
            int size = TAR_INT(header->size);

            if ( size%512 == 0 ){ //if size is perfectly 512 size
                lseek(tar_fd , size, SEEK_CUR);
            }

            else{
                lseek(tar_fd, ((size/512) +1) * 512,SEEK_CUR);
            }

            read(tar_fd, buffer , 512);
            header = (tar_header_t*) buffer;
            //        printf("the size is %d\n",size);
            //        fflush(stdout);

        }
    }


    if( !is_file(tar_fd, path)){ // cehck if fiel
        *len = 0;
        return -1;
    }

    lseek(tar_fd,0,SEEK_SET); //reset poiter


    tar_header_t* header;
    char* buffer = malloc(sizeof(char)*512);
    header = (tar_header_t*) buffer;
    read(tar_fd,buffer,512);
    while(not_last_block(header)){

        if(header-> name[0] == AREGTYPE){
            break;
        }

        if(!strcmp(header->name , path) ){

            if( (ssize_t) TAR_INT(header->size) < offset  ){
                *len = 0;
                return -2;
            }

            if(  (ssize_t) TAR_INT(header->size)< *len + offset ){
                *len =((ssize_t) TAR_INT(header->size)) - offset;
            }

            lseek(tar_fd, (int) offset, SEEK_CUR);
            read(tar_fd, dest, (int ) *len);
            break;
        }


        /////////////////////////////////
        int size = TAR_INT(header->size);

        if ( size%512 == 0 ){ //if size is perfectly 512 size
            lseek(tar_fd , size, SEEK_CUR);
        }

        else{
            lseek(tar_fd, ((size/512) +1) * 512,SEEK_CUR);
        }

        read(tar_fd, buffer , 512);
        header = (tar_header_t*) buffer;
        //        printf("the size is %d\n",size);
        //        fflush(stdout);

    }
    lseek(tar_fd, 0 , SEEK_SET);

    if((TAR_INT(header->size) - offset) == *len){
        return 0;
    }
    ssize_t returnval = (ssize_t) (-*len - offset + TAR_INT(header->size));
    return returnval;
}