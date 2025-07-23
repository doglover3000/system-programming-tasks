//В символьной строке переставить четные и нечетные слова.

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#define DEFAULT_PORT 2000
#define BUFFER_SIZE 1024
#define CLOSE_COMMAND "close\n"
#define NEW_GAME_COMMAND_YES "Y\n"
#define NEW_GAME_COMMAND_NO "N\n"
#define MAX_CLIENT_COUNT 50
#define DELIM " \t\n"
void* clientWorker(void* soc);
void* serverListener();
int main() {
char command[BUFFER_SIZE];
pthread_t server;
pthread_create(&server, NULL, &serverListener, NULL);
sched_yield();
while(1)
{
fgets(command, BUFFER_SIZE, stdin);
if(strcmp(command, CLOSE_COMMAND) == 0)
break;
else
printf("Команда не распознана\n");
}
}
void* clientWorker(void* _soc) {
int *soc = (int*)_soc;
char buf[BUFFER_SIZE];
char tmp[BUFFER_SIZE];
char *p1, *p2;
printf("Соединение с %d установлено\n\n", *soc);
while(1)
{
if(recv(*soc, buf, BUFFER_SIZE, 0) == -1)
break;
if(strcmp(buf, CLOSE_COMMAND) != 0)
printf("Клиент %d прислал %s", *soc, buf);
if(strcmp(buf, CLOSE_COMMAND) == 0)
{
printf("Клиент решил закрыть соединение\n", *soc);
break;
}
else
{
for ( p1 = strtok(buf, DELIM); p1; p1 = strtok(NULL, DELIM) )
{
if ( p2 = strtok(NULL, DELIM) )
{
strcat(tmp, p2);
strcat(tmp, " ");
}
strcat(tmp, p1);
strcat(tmp, " ");
}
strcpy(buf, tmp);
strcpy(tmp, "");
}
send(*soc, buf, BUFFER_SIZE, 0);
printf("Клиенту %d отправлено %s\n", *soc, buf);
}
printf("Соединение с %d закрыто\n", *soc);
close(*soc);
}
void* serverListener() {
int soc;
soc = socket(AF_INET, SOCK_STREAM, 0);
if(soc < 0)
{
printf("Ошибка создания сокета \n");
return 0;
}
struct sockaddr_in serverAddr;
serverAddr.sin_port = htons(DEFAULT_PORT);
serverAddr.sin_family = AF_INET;
serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
int res = bind(soc, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
if(res < 0)
{
printf("Порт занят");
return 0;
}
printf("\n");
listen(soc, SOMAXCONN);
pthread_t threads[MAX_CLIENT_COUNT];
int clientSocets[MAX_CLIENT_COUNT];
int lastClient = 0;
socklen_t serverSize = sizeof(serverAddr);
while(1)
{
int clientSocet = accept(soc, (struct sockaddr *)&serverAddr, &serverSize);
if(clientSocet < 0)
{
printf("Ошибка подключения клиента\n");
}
clientSocets[lastClient] = clientSocet;
pthread_create(&threads[lastClient], NULL, &clientWorker,
&clientSocets[lastClient]);
sched_yield();
lastClient++;
}
}
