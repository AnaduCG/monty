#include "monty.h"

/**
 *main - entry point in all C programming
 *@argc: gets the number of arguments passed
 *@argv: arguments passed
 *Return: returns 0 on success
 */
int main(int argc, char *argv[])
{
	int fd, i = 0;
	unsigned int line = 1;
	char buf[1], str[1024];
	ssize_t r;

	/* Checking for argument count */
	if (argc != 2)
		_error("USAGE: monty file\n");
	/* opening file */
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* reading from file */
	while ((r = read(fd, buf, 1)) > 0)
	{
		/* checking for a new line in file */
		if (buf[0] == '\n')
		{
			str[i] = '\0';
			_to_arr(str, line);
			line++;
			i = 0;
		}
		else
		{
			str[i] = buf[0];
			i++;
		}
	}
	if (r < 0)
	{
		close(fd);
		_error("Error reading file\n");
	}
	close(fd);
	return (0);
}
