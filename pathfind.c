#include "shell.h"
/**
 * path_finder - Takes PATH string, tokenizes it, then concats with "/" & cmd
 * @cmd: command passed from getline in main
 *
 * Return: new_path for use in cmd_read
 */
char *path_finder(char *cmd)
{
	char *path = _strdup(get_env("PATH"));
	int i = 0, j = 0;
	char *_path_tokens = strtok(path, ":");
	char *_path_array[100];
	char *s2 = cmd;
	char *_new_path = NULL;
	struct stat buf;

	_new_path = malloc(sizeof(char) * 100);
	if (get_env("PATH")[0] == ':')
		if (stat(cmd, &buf) == 0)
			return (_strdup(cmd));

	while (_path_tokens != NULL)
	{
		_path_array[i++] = _path_tokens;
		_path_tokens = strtok(NULL, ":");
	}
	_path_array[i] = NULL;
	for (j = 0; _path_array[j]; j++)
	{
		_strcpy(_new_path, _path_array[j]);
		_strcat(_new_path, "/");
		_strcat(_new_path, s2);
		_strcat(_new_path, "\0");

		if (stat(_new_path, &buf) == 0)
		{
			free(path);
			return (_new_path);
		}
		else
			_new_path[0] = 0;
	}
	free(path);
	free(_new_path);
	if (stat(cmd, &buf) == 0)
		return (_strdup(cmd));
	return (NULL);
}
