#include "lr.h"
#include <stdio.h>
#include <locale.h>
#define MAX 100

void process_line(char buffer[]); // ���������� ������� �� main

int lab1() {
double calculateVolume(double H, double R, double D) {
double remainingHeight = H - D;
double remainingVolume = (1.0 / 3.0) * 3.14 * R * R * remainingHeight;
return remainingVolume;
}

double H, R, D;
printf("������� ������ �������� (H): ");
scanf("%lf", &H);
printf("������� ������ ��������� (R): ");
scanf("%lf", &R);
printf("������� ������ �������� ����� (D): ");
scanf("%lf", &D);
printf("����� ���������� �����: %.2lf\n", calculateVolume(H, R, D));
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
printf("������� �������� x: ");
scanf("%d", &x);
printf("������� ���������� ������ N: ");
scanf("%d", &N);
for (int i = 0; i < N; i++) {
double term = 1;
for (int j = 1; j <= 2 * i; j++) {
term *= x;
}
term = (i % 2 == 0) ? term / fact(2 * i) : -term / fact(2 * i);
sum += term;
}
printf("����� %d ������ ���� �����: %f\n", N, sum);
return 0;
}

int lab3() {
const int YES = 1;
const int NO = 0;

int c; // ������� ������ �� ������
int prev_c; // ���������� ������
int flag; // ���� ��� �����
int cnt; // �������

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

printf("���������� ���� � ������ � �������������� ���������: %d\n", cnt);
return 0;
}

int lab4() {
// ����������� ������������� ��������
#define YES 1
#define NO 0
#define MAXLINE 1000

// ������� ������������ �����
int c;
while ((c = getchar()) != '\n' && c != EOF) {}

char line[MAXLINE];
printf("������� ������: ");
fgets(line, MAXLINE, stdin);
process_line(line);
printf("������ ����� �������� ������ ��������: %s", line);
return 0;
}

void process_line(char buffer[]) {
char c; // ������� ������
int flag = NO; // ������� �����
int i = 0; // ������� �������� ������� �������� ������
int pos = 0; // ������� �������� ������� �������������� ������
// ���� ������ �������� �� ������
while ((c = buffer[i]) != '\0') {
if (c == ' ') {
// ������ ������
if (flag == NO) {
// ��� ������ ������ ����� �����
buffer[pos++] = c;
flag = YES; // ��������� ����, ��� ������ ������
}
} else {
// ������� �����
buffer[pos++] = c;
flag = NO; // �������� ����, ��� ��� ��� �� ������
}
i++;
}
buffer[pos] = '\0'; // ��������� ������ ������� ��������
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

printf("���� � ������������ ������: %d\n", max_pair_num);
printf("������������ �����: %d\n", max_sum);
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

printf("������� �������� ������� ����������� %d x %d:\n", N, K);
for (i = 0; i < N; i++) {
for (j = 0; j < K; j++) {
scanf("%d", &arr[i][j]);
}
}

for (i = 0; i < N; i++) {
bubbleSort(arr[i], K);
}

zeroOutColumns(arr, N, K);

printf("��������������� ������:\n");
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
unsigned long N; // �������� �����
int position = 0; // ������� ������� ���������� ����
unsigned long mask = 1; // ����� ��� ������ ��������� ���

printf("������� ����� N: ");
scanf("%lu", &N); // ������ �������� �����

if (N == 0) {
printf("� ����� ��� ������.\n");
return 0;
}

// ����� ������� ������� ���������� ���� � �������� ������������� �����
while ((N & mask) == 0) {
position++;
mask = 1; // ����� ����� �� ���� ��� �����
}

printf("������� ������� ���������� ����: %d\n", position + 1);
printf("����� N � �������� ����: ");
printBinary(N);
return 0;
}

// ������� ��� ������ ����� � �������� �������������
void printBinary(unsigned long num) {
if (num > 1) {
printBinary(num / 2);
}
printf("%lu", num % 2);
}
