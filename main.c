#include "lr.h"
#include <stdio.h>
#include <locale.h>

int main() {
setlocale(LC_ALL, "Russian");
int choice;
scanf("%d", &choice);
switch(choice) {
case 1: return lab1(); break;
case 2: return lab2(); break;
case 3: return lab3(); break;
case 4: return lab4(); break;
case 5: return lab5(); break;
case 6: return lab6(); break;
case 7: return lab7(); break;
default: printf("Неверный выбор.\n"); break;
}
return 0;
}
