#include "main.h"

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: the name of the file to create it.
 * @text_content: NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, bytes_writ;
	int len = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (fd == -1)
			return (-1);
		if (text_content)
		{
			while (text_content[len])
				len++;
			bytes_writ = write(fd, text_content, len);
			if (bytes_writ == -1)
			{
				close(fd);
				return (-1);
			}
		}
		close(fd);
		return (1);
}
