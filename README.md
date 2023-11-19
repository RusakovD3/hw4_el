# Задание на структуры в Си

Написать программу абонентский справочник. Список абонентов представляет собой статический массив (100 элементов) из структур следующего в вида:
```
struct abonent {
char name[10];
char second_name[10];
char tel[10];
};
```

При запуске на экран выводится текстовое меню:
1) Добавить абонента
2) Удалить абонента
3) Поиск абонентов по имени
4) Вывод всех записей
5) Выход
   
и пользователю предлагается ввести пункт меня с клавиатуры. Добавление абонента в массив реализуется простым заполнением свободной структуры, при выходе за 100 абонентов уведомить пользователя о переполнении справочника и не позволять больше добавлять абонентов. При удалении структура заполняется нулями. При поиске пользователь вводит с клавиатуры имя абонентов и на экран выводится список всех абонентов с таким же именем. Программа продолжает выполняться пока пользователь не введет пункт 5
