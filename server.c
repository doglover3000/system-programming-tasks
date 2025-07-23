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
#define SERVER_IP "127.0.0.1"
int createConnect();
void working(int soc);
int main() {
int connection = createConnect();
if (connection == -1) {
printf("Сервер не отвечает\n");
} else {
printf("Соединение с сервером установлено\n");
working(connection);
}
}
int createConnect() {
int soc = socket(AF_INET, SOCK_STREAM, 0);
if(soc < 0) {
printf("Ошибка создания сокета");
exit(0);
}
struct sockaddr_in serverAddr;
serverAddr.sin_port = htons(DEFAULT_PORT);
serverAddr.sin_family = AF_INET;
inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);
int res = connect(soc, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
int i = 0;
if(res == -1 && i < 3) {
sleep(1);
res = connect(soc, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
i++;
}
return res == -1 ? res : soc;
}
void working(int soc) {
int crash = 0;
int isCommand = 0;
char buf[BUFFER_SIZE];
while(1)
{
printf("Введите строку: ");
fgets(buf, BUFFER_SIZE, stdin);
if (strcmp(buf, CLOSE_COMMAND) == 0) {
send(soc, buf, BUFFER_SIZE, 0);
break;
}
send(soc, buf, BUFFER_SIZE, 0);
if(recv(soc, buf, BUFFER_SIZE, 0) == 0)
{
crash = 1;
printf("Соединение разорвано\n");
break;
}
else
{
printf("Результат: %s", buf);
printf("\nХотите ввести еще одну строку?(Y/N) ");
fgets(buf, BUFFER_SIZE, stdin);
}
if (strcmp(buf, NEW_GAME_COMMAND_NO) == 0)
{
strcpy(buf, CLOSE_COMMAND);
send(soc, buf, BUFFER_SIZE, 0);
printf("Вы завершили работу\n");
break;
}
}
if (!crash)
printf("Соединение закрыто\n");
close(soc);
}
