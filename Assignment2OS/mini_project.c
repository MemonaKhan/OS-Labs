#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include <sys/wait.h>

void main(void){
    printf("This is Memona Khan Shell\n");
    printf("Type any Linux command OR type \'quit\' to Exit the Shell\n");

  while(1){
    printf("MemonaKhan@Shell >>> ");
    
    char input_command[25];
    fgets(input_command, sizeof(input_command), stdin);
    char* command_token = strtok(input_command," ");

    char* command;
    command = command_token;

    char* command_arg[25];
    command_arg[0] = command_token;

    int index = 1;
    while(command_token != NULL) {
        command_token = strtok(NULL," ");
        command_arg[index] = command_token;
        index++;
    }
    
    if (strcmp(command,"\n") == 0 || strcmp(command,"quit\n") == 0){
        break;
    }
    command_arg[index - 2] = strtok(command_arg[index - 2], "\n");

    int child_ret = fork();

    if (child_ret == 0) {
      execvp(command, command_arg);
      printf("\nError in running the command, please try again\n");
      break;
    }
    else{
      wait(&child_ret);
    }
  }
}