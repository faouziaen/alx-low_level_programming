#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fd, wr, rea;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	rea = read(fd, buffer, letters);
	wr = write(STDOUT_FILENO, buffer, rea);

	free(buffer);
	close(fd);
	return (wr);
}
