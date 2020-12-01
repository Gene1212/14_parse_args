#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char **parse_args(char *line)
{
    char **returnval = malloc(sizeof(char *) * 6);
    int i = 0;
    char *token;
    char *curr = line;
    while (curr != NULL)
    {
        token = strsep(&curr, " ");
        //printf("%s\n", token);
        returnval[i] = token;
        i += 1;
    }
    returnval[i] = NULL;

    return returnval;
}

int main()
{
    char line[100] = "ls -a -l";
    char **args = parse_args(line);
    execvp(args[0], args);
    return 0;
}