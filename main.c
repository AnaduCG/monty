#include "monty.h"
#include <stdlib.h>
#include <fcntl.h>

void _use(char *str)
{
	char **vals = malloc(sizeof(char *) * strlen(str));
	char *token = strtok(str, " \t\n");
	int i = 0;
	while (token)
	{
		vals[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	for (i = 0; vals[i]; i++)
		printf("%s\n", vals[i]);
}
/**
 *
 *
 *
 *
 */
void _error(char *str)
{
	write(2, str, strlen(str));
	exit(EXIT_FAILURE);
}
/**
 *
 *
 *
 *
 */
int main(int argc, char *argv[])
{
	int fd, line = 1, i = 0;
	char buf[1], str[1024];
	ssize_t r;

	if (argc != 2)
	{
		_error("Argument Error\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == !-1)
	{
		_error("Error Opening file\n");
		exit(0);
	}
	r = read(fd, buf, 1);
	while (r > 0)
	{
		if (buf[0] == '\n')
		{
			line++;
			str[i++] = '\0';
			_use(str);
			i = 0;
		}
		str[i] = buf[0];

		/* if (write(1, buf, 1) == -1)
		{
			_error("Error writing file\n");
			close(fd);
			exit(0);
		} */
		r = read(fd, buf, 1);
		i++;
	}
	if (r == -1)
	{
		_error("Error reading file\n");
		close(fd);
		exit(0);
	}
	close(fd);
	return (0);
}
