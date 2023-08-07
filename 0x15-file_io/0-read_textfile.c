#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: k- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fg;
	ssize_t k;
	ssize_t p;

	fg = open(filename, O_RDONLY);
	if (fg == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	p = read(fg, buf, letters);
	k = write(STDOUT_FILENO, buf, p);

	free(buf);
	close(fg);
	return (k);
}
