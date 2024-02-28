#include "shell.h"

/**
 * getEnv - retrieves value of an environment variable
 * @name: The name of the environment variable to retrieve
 * Return: The value of environment variable
 */
char *getEnv(char *name)
{
	char **environ2 = copyArrayOfStrings(environ);
	int i;
	char *tok, *result = NULL;
	envVarNode *array;
	int numEnvVars = lenOfArray(environ2);

	if (name == NULL)
	{
		freeArrayOfStrings(environ2);
		return (NULL);
	}

	array = malloc(numEnvVars * sizeof(envVarNode));
	if (array == NULL)
	{
		_puts("getEnv(): malloc failed");
		freeArrayOfStrings(environ2);
		return (NULL);
	}

	for (i = 0; i < numEnvVars; i++)
	{
		tok = strtok(environ2[i], "=");
		array[i].key = malloc(_strlen(tok) + 1);
		if (array[i].key == NULL)
		{
			_puts("getEnv(): malloc failed.");
			freeArrayOfStrings(environ2);
			return (NULL);
		}
		_strcpy(array[i].key, tok);

		tok = strtok(NULL,  "=");
		array[i].value = malloc(_strlen(tok) + 1);
		if (array[i].value == NULL)
		{
			_puts("getEnv(): malloc failed.");
			freeArrayOfStrings(environ2);
			free(array[i].key);
			free(array);
			return (NULL);
		}
		_strcpy(array[i].value, tok);
	}

	for (i = 0; i < numEnvVars; i++)
	{
		if (_strcmp(array[i].key, name) == 0)
		{
			result = _strdup(array[i].value);
			break;
		}
	}

	for (i = 0; i < numEnvVars; i++)
	{
		free(array[i].key);
		free(array[i].value);
	}
	free(array);

	freeArrayOfStrings(environ2);
	return (result);
}
