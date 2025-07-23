/*
Написать скелет программы, которая создает дерево процессов соответствующее
схемам:
1) 1 → (2,3,4) 2→ 5 3 → (6,7);
2) 1 → 2 2→ 3 3 → (4,5) 5 → 6;
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <signal.h>
#include <signal.h>
#include <unistd.h>
#include <unistd.h>
//1
//1-->2 2>2 2-->3 3>3 3-->(4,5) 5>(4,5) 5-->6>6
int main()
int main()
{
{
int pid = getpid();int pid = getpid();
printf("Process 1 printf("Process 1 -- %d, parent %d, parent -- %d%d\\n", getpid(), getppid());n", getpid(), getppid());
int pid2 = fork();int pid2 = fork();
if (pid2 == if (pid2 == --1)1)
return perror(0), 1;return perror(0), 1;
if (pid2 == 0)if (pid2 == 0)
{{
printf("Process 2 printf("Process 2 -- %d, parent %d, parent -- %d%d\\n", getpid(), getppid());n", getpid(), getppid());
int pid3 = fork();int pid3 = fork();
if (pid3 == if (pid3 == --1)1)
return return perror(0), 1;perror(0), 1;
if (pid3 == 0)if (pid3 == 0)
{{
printf("Process 3 printf("Process 3 -- %d, parent %d, parent -- %d%d\\n", getpid(), getppid());n", getpid(), getppid());
int pid4 = fork();int pid4 = fork();
if (pid4 == if (pid4 == --1)1)
return perror(0), 1;return perror(0), 1;
if (pid4 == 0)if (pid4 == 0)
printf("Process 4 printf("Process 4 -- %d, parent %d, parent -- %d%d\\n", getpid(), getppid());n", getpid(), getppid());
elselsee
{{
int pid5 = fork();int pid5 = fork();
if (pid5 == if (pid5 == --1)1)
return perror(0), 1;return perror(0), 1;
if (pid5 == 0)if (pid5 == 0)
{{
printf("Process 5 printf("Process 5 -- %d, parent %d, parent -- %d%d\\n", getpid(), getppid());n", getpid(), getppid());
int pid6 = fork();int pid6 = fork();
if (pid6 == if (pid6 == --1)1)
return perror(0), 1;return perror(0), 1;
if (pid6 if (pid6 == 0)== 0)
printf("Process 6 printf("Process 6 -- %d, parent %d, parent -- %d%d\\n", getpid(), n", getpid(), getppid());getppid());
}}
sleep(1);sleep(1);
}}
}}
sleep(1);sleep(1);
}}
elseelse
{{
char p[5];char p[5];
sprintf(p, "%d", pid);sprintf(p, "%d", pid);
execlp("pstree", "pstree", "execlp("pstree", "pstree", "--p", p, NULL);p", p, NULL);
return 0;return 0;
}}
return 0;return 0;
}
}
