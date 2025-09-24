#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "h/read_csv.h"

int read_csv(const char *filename, char data[][MAX_FIELDS][MAX_LINE_LEN],
             int *rows, int *cols, int inc_header) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        return -1;
    }

    char line[MAX_LINE_LEN];
    int row = 0;

    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\r\n")] = 0;
        if (row == 0 && inc_header == 0) {
            row++;
            continue;
        }

        int col = 0;
        char *token = strtok(line, ",");
        while (token != NULL) {
            strncpy(data[row - (inc_header == 0)][col], token, MAX_LINE_LEN);
            data[row - (inc_header == 0)][col][MAX_LINE_LEN - 1] = '\0';
            col++;
            token = strtok(NULL, ",");
        }

        if (row == 0) {
            *cols = col;
        }

        row++;
    }

    fclose(fp);
    *rows = (inc_header == 0) ? row - 1 : row;
    return 0;
}

