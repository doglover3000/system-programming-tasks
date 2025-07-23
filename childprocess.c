//Реализовать выполнение двух дочерних процессов, по сигналу от родительского процесса, меняющих свое тело.

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main()
{
printf("Process 0, pid = %d: n", getpid());
int child1 = fork();
if (child1 == 1)
return perror(0), 1;
if (child1 == 0)
//child1 process
printf("Child1 is created! Child process 1, pid = % n", getpid());
sleep(1);
printf("Child1 script starts... n");
char cmd[] = "/usr/bin/ls";
char * argVec[] = {"ls"," l", NULL};
char * envVec[] = {NULL};
if(execve(cmd, argVec, envVec) == 1)
perror("Could not execute execve");
else
//parent process
sleep(1);
kill(child1, SIGSTOP);
printf("Child1 stopped for 2 sec n");
sleep(2);
printf("Child1 continued n");
kill(child1, SIGCONT);
int child2 = fork();
if (child2 == 1)
return perror(0), 1;return perror(0), 1;
if (chilif (child2 == 0)d2 == 0)
{{
//child2 process//child2 process
printf("Child2 script starts...printf("Child2 script starts...\\n");n");
char cmd[] = "./test.sh";char cmd[] = "./test.sh";
char * argVec[] = {NULL};char * argVec[] = {NULL};
char * envVec[] = {NULL};char * envVec[] = {NULL};
if(execve(cmd, argVec, envVec) == if(execve(cmd, argVec, envVec) == --1)1)
perror("Could not execute execve");perror("Could not execute execve");
}}
elseelse
{{
//parent process//parent process
kill(child2, SIGSTOP);kill(child2, SIGSTOP);
printf("Child2 is created! Childprintf("Child2 is created! Child--process 2, pid = %d:process 2, pid = %d:\\n", child2);n", child2);
printf("Child2 stopped for 5 secprintf("Child2 stopped for 5 sec\\n");n");
sleep(5);sleep(5);
printf("Child2 continuedprintf("Child2 continued\\n");n");
kill(child2, SIGCONT);kill(child2, SIGCONT);
}}
return 0;return 0;
}
}
