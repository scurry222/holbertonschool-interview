#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
int merge_nums(int *line, size_t size);
int move_zeroes_right(int *line, size_t size);
int move_zeroes_left(int *line, size_t size);


#endif
