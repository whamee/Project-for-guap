#include "lr.h"
#include <stdio.h>
#include <locale.h>
#define MAX 100

void process_line(char buffer[]); // Объявление функции до main

int lab1() {
double calculateVolume(double H, double R, double D) {
double remainingHeight = H - D;
double remainingVolume = (1.0 / 3.0) * 3.14 * R * R * remainingHeight;
return remainingVolume;
}

double H, R, D;
printf("Введите высоту цилиндра (H): ");
scanf("%lf", &H);
printf("Введите радиус основания (R): ");
scanf("%lf", &R);
printf("Введите высоту конусной части (D): ");
scanf("%lf", &D);
printf("Объем оставшейся части: %.2lf\n", calculateVolume(H, R, D));
return 0;
}

int lab2() {
double fact(int n) {
if (n == 0)
return 1;
else
return n * fact(n - 1);
}

int N, x;
double sum = 0;
printf("Введите значение x: ");
scanf("%d", &x);
printf("Введите количество членов N: ");
scanf("%d", &N);
for (int i = 0; i < N; i++) {
double term = 1;
for (int j = 1; j <= 2 * i; j++) {
term *= x;
}
term = (i % 2 == 0) ? term / fact(2 * i) : -term / fact(2 * i);
sum += term;
}
printf("Сумма %d членов ряда равна: %f\n", N, sum);
return 0;
}

int lab3() {
const int YES = 1;
const int NO = 0;

int c; // текущий символ из потока
int prev_c; // предыдущий символ
int flag; // флаг для слова
int cnt; // счетчик

cnt = 0;
flag = NO;
prev_c = ' ';

while ((c = getchar()) != EOF) {
if (c == ' ' || c == '.' || c == '\n' || c == ',') {
if (flag == YES) {
cnt = cnt + 1;
}
flag = NO;
} else {
if (prev_c == c) {
flag = YES;
}
}
prev_c = c;
}

printf("Количество слов в тексте с повторяющимися символами: %d\n", cnt);
return 0;
}

int lab4() {
// определение символических констант
#define YES 1
#define NO 0
#define MAXLINE 1000

// Очистка стандартного ввода
int c;
while ((c = getchar()) != '\n' && c != EOF) {}

char line[MAXLINE];
printf("Введите строку: ");
fgets(line, MAXLINE, stdin);
process_line(line);
printf("Строка после удаления лишних пробелов: %s", line);
return 0;
}

void process_line(char buffer[]) {
char c; // текущий символ
int flag = NO; // признак слова
int i = 0; // позиция текущего символа исходной строки
int pos = 0; // позиция текущего символа результирующей строки
// цикл чтения символов из строки
while ((c = buffer[i]) != '\0') {
if (c == ' ') {
// найден пробел
if (flag == NO) {
// это первый пробел после слова
buffer[pos++] = c;
flag = YES; // поднимаем флаг, что пробел найден
}
} else {
// найдена буква
buffer[pos++] = c;
flag = NO; // опускаем флаг, так как это не пробел
}
i++;
}
buffer[pos] = '\0'; // Закрываем строку нулевым символом
}

int lab5() {
int arr[10] = {4, 7, 2, 8, 10, 5, 6, 3, 9, 1};
int max_sum = arr[0] + arr[1];
int max_pair_num = 0;

for (int i = 1; i < 9; i++) {
int current_sum = arr[i] + arr[i + 1];
if (current_sum > max_sum) {
max_sum = current_sum;
max_pair_num = i;
}
}

printf("Пара с максимальной суммой: %d\n", max_pair_num);
printf("Максимальная сумма: %d\n", max_sum);
return 0;
}

void bubbleSort(int arr[], int n) {
int i, j;
for (i = 0; i < n-1; i++) {
for (j = 0; j < n-i-1; j++) {
if (arr[j] > arr[j+1]) {
int temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
}
}
}
}

void zeroOutColumns(int arr[][4], int N, int K) {
for (int j = 0; j < K; j++) {
int sum = 0;
for (int i = 0; i < N; i++) {
sum += arr[i][j];
}
if (sum == 0) {
for (int i = 0; i < N; i++) {
arr[i][j] = 0;
}
}
}
}

int lab6() {
const int N = 3;
const int K = 4;
int arr[N][K];
int i, j;

printf("Введите элементы массива размерности %d x %d:\n", N, K);
for (i = 0; i < N; i++) {
for (j = 0; j < K; j++) {
scanf("%d", &arr[i][j]);
}
}

for (i = 0; i < N; i++) {
bubbleSort(arr[i], K);
}

zeroOutColumns(arr, N, K);

printf("Отсортированный массив:\n");
for (i = 0; i < N; i++) {
for (j = 0; j < K; j++) {
printf("%d ", arr[i][j]);
}
printf("\n");
}

return 0;
}

void
printBinary(unsigned long num);

int lab7() {
unsigned long N; // вводимое число
int position = 0; // позиция первого единичного бита
unsigned long mask = 1; // маска для поиска единичных бит

printf("Введите число N: ");
scanf("%lu", &N); // читаем вводимое число

if (N == 0) {
printf("В числе нет единиц.\n");
return 0;
}

// поиск позиции первого единичного бита в двоичном представлении числа
while ((N & mask) == 0) {
position++;
mask = 1; // сдвиг маски на один бит влево
}

printf("Позиция первого единичного бита: %d\n", position + 1);
printf("Число N в двоичном виде: ");
printBinary(N);
return 0;
}

// функция для вывода числа в двоичном представлении
void printBinary(unsigned long num) {
if (num > 1) {
printBinary(num / 2);
}
printf("%lu", num % 2);
}
