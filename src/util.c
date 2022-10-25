#include "../include/util.h"

char* read_ascii_file(const char* path) {
    // Will create a file
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Could not open file (%s)!\n", path);
        return NULL;
    }

    // Getting the file size
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Reading the file
    char* buf = (char*) malloc(sizeof(char) * (size + 1));
    if (!buf) {
        printf("Could not allocate memory for the file!\n");
        return NULL;
    }
    fread(buf, 1, size, file);
    buf[size] = '\0';
    fclose(file);

    return buf;
}