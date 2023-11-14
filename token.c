char **tokenizer(char *line) 
{
    if (!line) 
    {
        return NULL;
    }

    char **command = NULL;
    int token_count = 0;

    char *line_copy = strdup(line);
    for (char *token = strtok(line_copy, " \t\n"); token; token = strtok(NULL, " \t\n")) 
    {
        token_count++;
    }
    free(line_copy);

    command = malloc(sizeof(char *) * (token_count + 1));
    if (!command) 
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(line, " \t\n");
    for (int i = 0; token; token = strtok(NULL, " \t\n"), i++) 
    {
        command[i] = strdup(token);
        if (!command[i]) 
	{
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }
    command[token_count] = NULL;

    return command;
}
