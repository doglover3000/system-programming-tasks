#Проверить права доступа файлов из пакета на запуск заданий. Задать вопрос пользователю, если прав не хватает, исполнить ответ пользователя. Выполнить пакет.

#!/bin/bash
`rm tmp.txt`
for i in `cat package.txt`
do
echo `ls -l $i | cut -c 4` » tmp.txt
done
dash=-
for j in `cat tmp.txt`
do
if [ "$j" == "$dash" ]
then
read -p "One script doesn't have rights. Give rights? " answer
case $answer in
y) echo "Done"
for i in `cat package.txt`
do
`chmod 700 $i`
done
3
;;
n) echo "Right not given, program end.";;
esac
fi
done
echo "All files have rights!"
`rm tmp.txt`
