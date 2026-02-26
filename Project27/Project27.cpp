#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 함수의 타입 정의
typedef int (*PFUNC)(int, int);

typedef int (PFIND_FUNC)(int*, int, int);

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}


int multiply(int a, int b)
{
    return a * b;
}


int divide(int a, int b)
{
    return a / b;
}


int sequence_find(int arr[], int count, int val)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == val)
            return i;
    }

    return -1;
}

int binary_find(int arr[], int count, int val)
{
    int start = 0;
    int end = count - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == val)
            return mid;

        if (arr[mid] < val)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

// Callback 함수, 콜백함수
void print_operation(int a, int b, PFUNC op)
{
    printf("%d\n", op(a, b));
}


int find_value(int arr[], int count, int val, PFIND_FUNC func)
{
    return func(arr, count, val);
}


int main()
{
    // 함수의 포인터 선언
    int (*plus)(int, int);  // 
    plus = add; // 함수의 포인터에 함수의 주소를 저장

    printf("%d\n", add(1, 2));
    printf("%d\n", plus(10, 20));

    /*int (*operators)(int, int);
    char op;
    printf("연산자를 입력하세요 >>> ");
    scanf("%c", &op);
    switch (op)
    {
    case '+': operators = add; break;
    case '-': operators = subtract; break;
    case '*': operators = multiply; break;
    case '/': operators = divide; break;
    default: operators = add;
    }

    printf("%d\n", operators(10, 20));*/

    PFUNC fp = add;
    printf("%d\n", fp(10, 20));


    print_operation(10, 5, add);
    print_operation(10, 5, subtract);
    print_operation(10, 5, multiply);
    print_operation(10, 5, divide);

    PFUNC arrFuncs[4] = {add, subtract, multiply, divide};
    for (int i = 0; i < 4; i++)
    {
        printf("차례대로 연산하기: %d\n", arrFuncs[i](10, 5));
    }
    

    return 0;
}
