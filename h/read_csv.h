#ifndef READ_CSV_H
#define READ_CSV_H
#define MAX_LINE_LEN 10000
#define MAX_FIELDS 200

int read_csv(const char *filename, char data[][MAX_FIELDS][MAX_LINE_LEN], int *rows, int *cols, int inc_header);

#endif

