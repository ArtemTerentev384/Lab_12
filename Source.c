#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "Source.h"

void NumberOne();
void NumberTwo();
void NumerThree();
void NumberFour();
void NumberFive();
void print_bytes(void* ptr, size_t size);
void HomeWork();
void print_size(const char* type_name, size_t size);


void main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    // Устанавливаем локально для корректной работы стандартных функций
    setlocale(LC_ALL, ".UTF8");
    
    setlocale(LC_ALL, "Russian");

    //NumberOne();
    //NumerThree();
    //NumberFour();
    //NumberFive();

    HomeWork();
}

void NumberOne()
{
    char* p_char;
    int* p_int;
    double* p_double;

    char c;
    int i;
    double d;

    printf("=== Размеры указателей ===\n");
    printf("Размер указателя на char   (char*):   %zu байт\n", sizeof(p_char));
    printf("Размер указателя на int    (int*):    %zu байт\n", sizeof(p_int));
    printf("Размер указателя на double (double*): %zu байт\n", sizeof(p_double));

    printf("\n=== Размеры самих переменных ===\n");
    printf("Размер переменной char:   %zu байт\n", sizeof(c));
    printf("Размер переменной int:    %zu байт\n", sizeof(i));
    printf("Размер переменной double: %zu байт\n", sizeof(d));
}

void NumberTwo() 
{
    float PI = 3.14159, * p1, * p2;
    p1 = p2 = &PI;
    printf("По адресу p1=%p хранится *p1=%g\n", p1, *p1);
    printf("По адресу p2=%p хранится *p2=%g\n", p2, *p2);
}

void NumerThree() 
{
    int x = 5;
    int* pa = &x;

    printf("--- Исходный тип int (размер %zu байт) ---\n", sizeof(int));
    printf("Начальный адрес pa: %p\n", (void*)pa);

    pa++;
    printf("После pa++:         %p (смещение +%zu байт)\n", (void*)pa, sizeof(int));

    pa--;
    printf("После pa--:         %p (возврат на место)\n\n", (void*)pa);

    double d = 3.14;
    double* pd = &d;
    printf("--- Тип double (размер %zu байт) ---\n", sizeof(double));
    printf("Начальный адрес pd: %p\n", (void*)pd);
    pd++;
    printf("После pd++:         %p (смещение +%zu байт)\n\n", (void*)pd, sizeof(double));

    char c = 'A';
    char* pc = &c;
    printf("--- Тип char (размер %zu байт) ---\n", sizeof(char));
    printf("Начальный адрес pc: %p\n", (void*)pc);
    pc++;
    printf("После pc++:         %p (смещение +%zu байт)\n\n", (void*)pc, sizeof(char));

    short s = 10;
    short* ps = &s;
    printf("--- Тип short (размер %zu байт) ---\n", sizeof(short));
    printf("Начальный адрес ps: %p\n", (void*)ps);
    ps++;
    printf("После ps++:         %p (смещение +%zu байт)\n", (void*)ps, sizeof(short));
}


void NumberFour() 
{
    float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1 };
    float* ptr_a;

    printf("--- 4.1 Проверка адресов ---\n");
    printf("Адрес array:    %p\n", (void*)array);
    printf("Адрес &array[0]: %p\n", (void*)&array[0]);
    printf("Адрес &array:    %p\n", (void*)&array);
    printf("Размер одного элемента (float): %zu байт\n\n", sizeof(float));

    printf("--- 4.2 Операции с указателем ---\n");
    ptr_a = array; 
    printf("Начало: ptr_a = %p, *ptr_a = %.2f\n", (void*)ptr_a, *ptr_a);

    ptr_a++; 
    printf("ptr_a++: ptr_a = %p, *ptr_a = %.2f\n", (void*)ptr_a, *ptr_a);

    ptr_a + 4;
    printf("ptr_a+4 (без присвоения): ptr_a = %p, *ptr_a = %.2f\n", (void*)ptr_a, *ptr_a);

    ptr_a = ptr_a + 4;
    printf("ptr_a = ptr_a + 4:        ptr_a = %p, *ptr_a = %.2f\n", (void*)ptr_a, *ptr_a);

    ptr_a - 2; 
    ptr_a = ptr_a - 2; 
    printf("ptr_a = ptr_a - 2:        ptr_a = %p, *ptr_a = %.2f\n\n", (void*)ptr_a, *ptr_a);

    printf("--- 4.3 Проход по массиву с шагом 2 ---\n");
    ptr_a = array; 
    for (int i = 0; i < 10; i += 2) {
        printf("Индекс %d: адрес %p, значение %.2f\n", i, (void*)ptr_a, *ptr_a);
        ptr_a += 2;
    }
    printf("\n");

    printf("--- 4.4 Проход по массиву в обратном порядке ---\n");
    ptr_a = array + 9;

    for (int i = 9; i >= 0; i--) {
        printf("Индекс %d: адрес %p, значение %.2f\n", i, (void*)ptr_a, *ptr_a);
        ptr_a--;
    }
}


void NumberFive() 
{
    int i_val = 12345;
    float f_val = 12345.0f;
    double d_val = 12345.0;

    printf("--- Число 12345 (int, 4 байта) ---\n");
    print_bytes(&i_val, sizeof(i_val));

    printf("\n--- Число 12345.0 (float, 4 байта) ---\n");
    print_bytes(&f_val, sizeof(f_val));

    printf("\n--- Число 12345.0 (double, 8 байт) ---\n");
    print_bytes(&d_val, sizeof(d_val));
}

void print_bytes(void* ptr, size_t size) 
{
    unsigned char* byte_ptr = (unsigned char*)ptr;
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", byte_ptr[i]);
    }
    printf("\n");
}


void HomeWork() 
{
    printf("--- Размеры основных типов данных ---\n");

    char* p_char = (char*)0;
    print_size("char", (size_t)((char*)(p_char + 1) - (char*)p_char));

    short int* p_short = (short int*)0;
    print_size("short int", (size_t)((char*)(p_short + 1) - (char*)p_short));

    unsigned short int* p_ushort = (unsigned short int*)0;
    print_size("unsigned short int", (size_t)((char*)(p_ushort + 1) - (char*)p_ushort));

    int* p_int = (int*)0;
    print_size("int", (size_t)((char*)(p_int + 1) - (char*)p_int));

    unsigned char* p_uchar = (unsigned char*)0;
    print_size("unsigned char", (size_t)((char*)(p_uchar + 1) - (char*)p_uchar));

    wchar_t* p_wchar = (wchar_t*)0;
    print_size("wchar_t", (size_t)((char*)(p_wchar + 1) - (char*)p_wchar));

    long long int* p_ll = (long long int*)0;
    print_size("long long int", (size_t)((char*)(p_ll + 1) - (char*)p_ll));

    size_t* p_size_t = (size_t*)0;
    print_size("size_t", (size_t)((char*)(p_size_t + 1) - (char*)p_size_t));

    float* p_float = (float*)0;
    print_size("float", (size_t)((char*)(p_float + 1) - (char*)p_float));

    double* p_double = (double*)0;
    print_size("double", (size_t)((char*)(p_double + 1) - (char*)p_double));

    signed int* p_sint = (signed int*)0;
    print_size("signed int", (size_t)((char*)(p_sint + 1) - (char*)p_sint));

    unsigned int* p_uint = (unsigned int*)0;
    print_size("unsigned int", (size_t)((char*)(p_uint + 1) - (char*)p_uint));
}

void print_size(const char* type_name, size_t size) {
    printf("%-20s : %zu байт\n", type_name, size);
}