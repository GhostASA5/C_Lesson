2. Просмотрев файлы через nm мы видим следующие перменные. global_var и static_var из
file1.o. global_var и static_var в file2.o. global_var в main.o.
3. Получаем ошибку линковки из-за дублирования global_var в file1.c и file2.c. 
Также будет ошибка из-за попытки объявить static_var как extern в file2.c
5. static_var доступна только в file1.o и хранится в .data. global_var доступна 
другим файлам и хранится в .data. global_var в file2.o и main.o объявлена как extern, поэтому обозначена как *UND*

```
file1.o:     формат файла elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 file1.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .data  0000000000000000 .data
0000000000000004 l     O .data  0000000000000004 static_var
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     O .data  0000000000000004 global_var
0000000000000000 g     F .text  0000000000000043 print_from_file1
0000000000000000         *UND*  0000000000000000 printf

file2.o:     формат файла elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 file2.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     F .text  0000000000000027 print_from_file2
0000000000000000         *UND*  0000000000000000 global_var
0000000000000000         *UND*  0000000000000000 printf

main.o:     формат файла elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 main.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     F .text  000000000000003f main
0000000000000000         *UND*  0000000000000000 global_var
0000000000000000         *UND*  0000000000000000 printf
0000000000000000         *UND*  0000000000000000 print_from_file1
0000000000000000         *UND*  0000000000000000 print_from_file2

```

6. Да, видим строки

```
file1.c -> global_var = %d
file1.c -> static_var = %d
file2.c -> global_var = %d
main.c -> global_var = %d
```