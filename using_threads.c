/*Реализовать выполнение поставленной задачи с использованием: 
- многопоточности
- функций thread_join, thread_yield
- минимум двух потоков
- ведение log
Поставленная задача - Перевести на русский язык слова из заданного списка английских
слов.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include
<string.
#include <locale.h>
#define ERROR_CREATE_THREAD
#define BUFFER_SIZE 200
#define NUM_TH 4
typedef struct th_arg
{
int id;
char word[50];
FILE* fptr;
} th_a;
void* translate(void *args)
{
th_a *arg = (th_a*) args;
char str[BUFFER_SIZE];
char* pos;
int found = 0;
int line = 1;
while ((fgets(str, BUFFER_SIZE, arg -->fptr)) !=
pos = strstr(str, arg -->
if (pos != NULL)
fgets(str, BUFFER_SIZE, arg -->
found = 1;
printf("%d) %s", arg -->id,
break;
}}
}}
if (pos == NULL)if (pos == NULL)
printf("%d) Искомое слово '%s' отсутствует в словареprintf("%d) Искомое слово '%s' отсутствует в словаре\\n", argn", arg-->id, arg>id, arg-->word);>word);
}
}
int main()
int main()
{
{
setlocale(LC_ALL, "Russian");setlocale(LC_ALL, "Russian");
pthread_t threads[NUM_TH];pthread_t threads[NUM_TH];
th_a args[NUM_TH];th_a args[NUM_TH];
int status, i;int status, i;
int status_addr;int status_addr;
for (i=0; i < NUM_TH; i++)for (i=0; i < NUM_TH; i++)
{{
printf("Введите %d слово, которое хотите перевести: ", i+1);printf("Введите %d слово, которое хотите перевести: ", i+1);
scanf("%s", args[i].word);scanf("%s", args[i].word);
args[i].id = i+1;args[i].id = i+1;
}}
for (i=0; i < NUM_TH; i++)for (i=0; i < NUM_TH; i++)
{{
args[i].fptr = fopen("dictionary.txt", "r");args[i].fptr = fopen("dictionary.txt", "r");
if (args[i].fptr == NULL)if (args[i].fptr == NULL)
{{
printf("Файл со словарем не найденprintf("Файл со словарем не найден\\n");n");
exit(EXIT_FAILURE);exit(EXIT_FAILURE);
}}
}}
for (i=0; i < NUM_TH; i++)for (i=0; i < NUM_TH; i++)
{{
status = pthreastatus = pthread_create(&threads[i], NULL, translate, (void*) &args[i]);d_create(&threads[i], NULL, translate, (void*) &args[i]);
if (status != 0)if (status != 0)
{{
printf("Can't create thread, ststus = %dprintf("Can't create thread, ststus = %d\\n", status);n", status);
fclose(args[i].fptr);fclose(args[i].fptr);
exit(ERROR_CREATE_THREAD);exit(ERROR_CREATE_THREAD);
}}
}}
for (i = 0; i < NUM_TH; for (i = 0; i < NUM_TH; i++)i++)
status = pthread_join(threads[i], (void**)&status_addr);status = pthread_join(threads[i], (void**)&status_addr);
for (i = 0; i < NUM_TH; i++)for (i = 0; i < NUM_TH; i++)
fclose(args[i].fptr);fclose(args[i].fptr);
return 0;return 0;
}
}

