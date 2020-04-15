#include "slide_line.h"

/**
 * slide_line - slide a number array and combine like terms
 * @line: integer array to slide
 * @size: size of the array
 * @direction: macro of which direction to slide numbers
 *
 * Return: 1
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);
	if(direction == SLIDE_RIGHT)
	{
		merge_nums_right(line, size);
		move_zeroes_left(line, size);
	}
	else
	{
		merge_nums_left(line, size);
		move_zeroes_right(line, size);
	}
	
	return (1);
}

/**
 * merge_nums_left - merge all adjacent equal non-zero numbers left
 * @line: integer array to slide
 * @size: size of the array
 *
 * Return: 1
 */
int merge_nums_left(int *line, size_t size)
{
	size_t i, p = 0;

	for (i = 1; i < size; i++)
	{
		if (line[i])
		{
			if (line[p])
			{
				if (line[p] == line[i])
				{
					line[p++] *= 2;
					line[i] = 0;
				}
			}
			p = i;
		}
	}
	return (1);
}

/**
 * merge_nums_right - merge all adjacent equal non-zero numbers right
 * @line: integer array to slide
 * @size: size of the array
 *
 * Return: 1
 */
int merge_nums_right(int *line, size_t size)
{
	ssize_t i, p = size - 1;

	for (i = size - 2; i >= 0; i--)
	{
		if (line[i])
		{
			if (line[p])
			{
				if (line[p] == line[i])
				{
					line[p--] *= 2;
					line[i] = 0;
				}
			}
			p = i;
		}
	}
	return (1);
}

/**
 * move_zeroes_right - move zeroes to the right of the numbers
 * @line: integer array to slide
 * @size: size of the array
 *
 * Return: 1
 */
int move_zeroes_right(int *line, size_t size)
{
	size_t i = 0, zeroes = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			zeroes++;
		else if (zeroes)
			line[i - zeroes] = line[i];
	}
	for (i = size - zeroes; i < size; i++)
		line[i] = 0;
	return (1);
}

/**
 * move_zeroes_left - move the zeroes to the left of the numbers
 * @line: integer array to slide
 * @size: size of the array
 *
 * Return: 1
 */
int move_zeroes_left(int *line, size_t size)
{
	ssize_t i = 0, zeroes = 0;

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] == 0)
			zeroes++;
		else if (zeroes)
			line[i + zeroes] = line[i];
	}
	for (i = zeroes - 1; i >= 0; i--)
		line[i] = 0;
	return (1);
}
