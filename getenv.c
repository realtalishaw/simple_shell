#include "shell.h"
char *_getenv(char *name)
{
	char **env;
	int len;

	env = environ;
	len = strlen(name);

	while (*env != NULL)
	{
		if (strncmp(*env, name, len) == 0)
			return (*env);
		env++;
	}
	return (*env);
}

int main(void)
{
	char *path;

	path = _getenv("PATH");
	printf("PATH is: %s", path);
}
