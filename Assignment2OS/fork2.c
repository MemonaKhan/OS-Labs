// // // #include<stdio.h>
// // // #include<unistd.h>
// // // #include<sys/types.h>

// // // void main(){
// // // int pid, ret, status;
// // // pid = fork();
// // // if(pid == 0){

// // // printf("child print it");
// // // execl("/bin/ls -l","date",(char*)0);
// // // }
// // // else{

// // // printf("\n\nparent print it\n");
// // // wait(&status);
// // // }



// // // }


// // // My Code for fork asssignment

// // // #include<stdio.h>
// // // #include<unistd.h>
// // // #include<sys/types.h>
// // // #include<string.h>
// // // #include<stdlib.h>

// // // void main(void){
// // //     // while(1){
// // //         char input_cmd[25];
// // //         char* cmd[25];
// // //         int i=0;
// // //         fgets(input_cmd, sizeof(input_cmd), stdin);
// // //         char* full_cmd = strtok(input_cmd," ");
// // //         // printf("%s",cmd[1]);
// // //         while( full_cmd != NULL ) {
// // //             cmd[i]=full_cmd;
// // //             printf( " %s\n", cmd[i]); //printing each token
// // //             full_cmd = strtok(NULL, " ");
// // //             i++;
// // //    }
// // //             printf( " %s\n", cmd[0]); //printing each token
// // //             printf( " %s\n", cmd[1]); //printing each token
   
// // //     // }
// // // }


// // // My another Code

// // #include <stdio.h>
// // #include <unistd.h>
// // #include <sys/types.h>
// // #include <sys/wait.h>
// // #include <string.h>
// // int main(){  
// //     char input[50];
// //     int fid;

// //     while(1){
// //         printf("MyShell>>");
// //         fgets(input, sizeof(input), stdin);
// //         char path[100];
// //       strcpy(path, "/bin/");
      
// //       strcat(path, input);
// //       printf("%s",input);
// //       printf("%s",path);
// // execl(path,input,(char*)0);

// //     //     fid=fork();
        
// //     //     if(fid==0){
// //     //         // if(input == "quit"){
// //     //         // 	break;
// //     //         // }
// //     //         // else{
// //     //             execl('/bin/date','date',(char*)0);
// //     //         // }
// //     //     }
        
// //     //     else{
// //     //         wait(0);
            
// //     //     }

// //     }
// // }



// // My not running code


// #include<stdio.h>
// #include<unistd.h>
// #include<sys/types.h>
// #include<string.h>
// #include<stdlib.h>

// void main(void){
//     // while(1){
//         char input_cmd[25];
//         char* cmd[25];
//         int i=0;
//         // Getting input for command
//         fgets(input_cmd, sizeof(input_cmd), stdin);
// // Prsing of Command and spiliting it
//         char* full_cmd = strtok(input_cmd," ");
//         while( full_cmd != NULL ) {
//             cmd[i]=full_cmd;
//             printf( " %s\n", cmd[i]); //printing each token
//             full_cmd = strtok(NULL, " ");
//             i++;
//    }
// //    printf("%s", full_cmd);
// //    printf("%s",cmd);
// //    char *cmd1 = cmd[0];
// //       execvp(cmd1, cmd);

// char *cmd1 = *cmd[0];
// char *argv[3];
// argv[0] = "ls";
// argv[1] = "-l";
// argv[2] = NULL;

// execvp(cmd1, argv);

// //    int child = fork();
// //     if (child <= 0) {
// //     //   char path[100];
// //     //   strcpy(path, "/bin/");
// //     //   strcat(path, cmd);
// //       cmd[i - 2] = strtok(cmd[i - 2], "\n");
// //       execvp(cmd[0], cmd);
// //       printf("------ Error! ------");
// //       break;
// //     }
// //     else{
// //       wait(&child);
// //     }
   
// //     }
// }