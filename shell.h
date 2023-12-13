#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define delimeter " \t\n"
extern char **environ;

void mahmoud_print(const char *myText);
int my_cmd_execute(char **myCmd, char **argv, int index);

char *my_cmd_read(void);
/*string functions*/
char *str_duplicate(const char *str);
int str_compare2(char *str1, char *str2);
int str_length(char *str);
char *str_copy(char *dest, char *src);
char *str_cat(char *dest, char *src);
void rev_string(char *s);
char **my_tokenizer(char *myLine);
void my_FreeArrOfString(char **myArr);
char *my_getenv(char *envVariable);
char *my_getpath(char *myCmd);
char *my_itoa(int num);
void my_getFullCmd(char *FullCmd, char *myCmd, char *cmdDir);
int is_postive(char *s);
int my_atoi(char *s);
/*builtin*/
int my_builtin_check(char *cmd);
void my_builtin_handle(char **cmd, char **argv, int *status, int index);
void exit_my_shell(char **cmd, char **argv, int *status, int index);
void my_print_env(char **cmd, int *status);
/*error*/
void my_printerror(char *shellName, char *myCmd, int index);
void my_writeErr(char **argv, char *index_str, char *msg, char **cmd);
#endif
