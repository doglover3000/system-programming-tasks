//Использовать команду CPUID для вывода информации о процессоре.

#include <stdio.
#include <locale.h>
void get_vendor()
{ //производитель процессора
int a, b, d, c = 0;
printf("Производитель процессора: ");
__
"
: "=a"(a), "=b" (b), "=c" (c), "=d" (
: "0"(0) //ЕАХ=0
while (a != 0)
printf("%c", a);
a = a >> 8;
while (b != 0)
printf("%c", b);
b = b >> 8;
while (d != 0)
printf("%c", d);
d = d >> 8;
while (c != 0)
printf("%c", c);
c = c >> 8;
printf(" n");
}
void get_brand()
{//марка процессора
int a, b, d, c = 0;
printf("Марка процессора: ");printf("Марка процессора: ");
__asm__(__asm__(
"cpuid;""cpuid;"
: "=a"(a), "=b" (b), "=c" (c), "=d" (d): "=a"(a), "=b" (b), "=c" (c), "=d" (d)
: "0"(0x80000002): "0"(0x80000002)
););
while (a != 0) {while (a != 0) {
printf("%c", a);printf("%c", a);
a = a >> 8;a = a >> 8;
};};
wwhile (b != 0) {hile (b != 0) {
printf("%c", b);printf("%c", b);
b = b >> 8;b = b >> 8;
};};
while (c != 0) {while (c != 0) {
printf("%c", c);printf("%c", c);
c = c >> 8;c = c >> 8;
};};
while (d != 0) {while (d != 0) {
printf("%c", d);printf("%c", d);
d = d >> 8;d = d >> 8;
};};
__asm__(__asm__(
"cpuid;""cpuid;"
: "=a"(a), "=b" (b), "=c" (c), "=d" (d): "=a"(a), "=b" (b), "=c" (c), "=d" (d)
: "0"(0x80000003): "0"(0x80000003)
););
while (a != 0) {while (a != 0) {
printf("%c", a);printf("%c", a);
a = a >> 8;a = a >> 8;
};};
while (b != 0) {while (b != 0) {
printf("%c", b);printf("%c", b);
b = b >> 8;b = b >> 8;
};};
while (c != 0) {while (c != 0) {
printf("%c", c);printf("%c", c);
c = c >> 8;c = c >> 8;
};};
while (d != 0) {while (d != 0) {
printf("%c", d);printf("%c", d);
d = d >> 8;d = d >> 8;
};};
__asm__(__asm__(
"cpuid;""cpuid;"
: : "=a"(a), "=b" (b), "=c" (c), "=d" (d)"=a"(a), "=b" (b), "=c" (c), "=d" (d)
: "0"(0x80000004): "0"(0x80000004)
););
while (a != 0)while (a != 0)
{{
printf("%c", a);printf("%c", a);
a = a >> 8;a = a >> 8;
};};
while (b != 0)while (b != 0)
{{
printf("%c", b);printf("%c", b);
b = b >> 8;b = b >> 8;
};};
while (c != 0)while (c != 0)
{{
printf("%c", c);printf("%c", c);
c = c >> 8;c = c >> 8;
};};
while (d != 0)while (d != 0)
{{
printf("%c", d);printf("%c", d);
d = d >> 8;d = d >> 8;
};};
printf("printf("\\n");n");
}
}
void get_cache() {//кэш
void get_cache() {//кэш--памятьпамять
int a, c = 0;int a, c = 0;
printf("Размер кэшprintf("Размер кэш--памяти 2го уровня: ");памяти 2го уровня: ");
char first, second, third, fourth;char first, second, third, fourth;
__asm__(__asm__(
"cpuid;""cpuid;"
: "=a"(a), "=c" (c): "=a"(a), "=c" (c)
: "a"(0x80000006): "a"(0x80000006)
););
first =first = c;c;
c = c >> 8;c = c >> 8;
second = c;second = c;
c = c >> 8;c = c >> 8;
third = c;third = c;
c = c >> 8;c = c >> 8;
fourth = c;fourth = c;
int cachesize = (int)(fourth) << 8 + (int)(third);int cachesize = (int)(fourth) << 8 + (int)(third);
printf("%dprintf("%d\\n", cachesize);n", cachesize);
printf("Тип кэшprintf("Тип кэш--памяти 2го уровня: ");памяти 2го уровня: ");
switch ((int)(second) >> 4)switch ((int)(second) >> 4)
{{
case 0:case 0:
printf("Отсутсвутеprintf("Отсутсвуте\\n");n");
break;break;
case 1:case 1:
printf("Кэш прямого отображенияprintf("Кэш прямого отображения\\n");n");
break;break;
case 2:case 2:
printf("Двухванальное ассотиативное кэшированиеprintf("Двухванальное ассотиативное кэширование\\n");n");
break;break;
case 4:case 4:
printf("Четырехканальное ассотиативное кэшированиеprintf("Четырехканальное ассотиативное кэширование\\n");n");
break;break;
case 6:case 6:
printfprintf("Восьмиканальное ассотиативное кэширование("Восьмиканальное ассотиативное кэширование\\n");n");
break;break;
case 8:case 8:
printf("Шестнадцатиканальное ассотиативное кэшированиеprintf("Шестнадцатиканальное ассотиативное кэширование\\n");n");
break;break;
case 15:case 15:
printf("Полностью ассотиативное кэшированиеprintf("Полностью ассотиативное кэширование\\n");n");
break;break;
default:default:
break;break;
}}
}
}
int main()
int main()
{
{
setlocale(LC_ALL, "Russian");setlocale(LC_ALL, "Russian");
get_vendor();get_vendor();
get_brand();get_brand();
get_cache();get_cache();
return 0;return 0;
}
}
