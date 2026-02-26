// Project23.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void print_array(int arr[], size_t len)
{
    printf("arr의 크기: %llu bytes\n", sizeof(arr));
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int copy_array(int arr[], size_t len, int** ppDest)
{
    /*int* p = *ppDest;*/

    size_t bytes = sizeof(int) * len;
    int* pArr = (int*)malloc(bytes);
    if (!pArr) return NULL;

    // 메모리 복사, pArr에 arr의 내용을 bytes만큼 복사한다.
    memcpy(pArr, arr, bytes);

    *ppDest = pArr; // main.p = pArr;

    return bytes / sizeof(int);
}

void swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}


int main()
{
    int n = 10; // n은 사이즈가 4바이트이고, 값은 10이 들어가 있다.
    int* p = &n;    // p는 사이즈가 8바이트이고, 값은 n의 주소가 들어가 있다.
    int arr[3] = { 1,2,3 };
    p = arr;    // p는 사이즈가 8바이트이고, 값은 arr배열의 시작 주소가 들어가 있다.

    // 1차원 포인터변수는 일반 변수의 주소와 1차원 배열의 주소를 저장할 수 있다.
    // 2차원 포인터변수는 1차원 포인터변수의 주소를 저장할 수 있다.

    printf("arr의 크기: %llu bytes\n", sizeof(arr));
    printf("p의 크기: %llu bytes\n", sizeof(p));
    print_array(arr, 3);

    int count = copy_array(arr, 3, &p);
    print_array(p, count);
    // printf("pArr의 크기: %llu bytes\n", sizeof(pArr));

    if (p)
    {
        free(p);
        p = NULL;
    }

    // 2차원 포인터 변수
    int** pp = &p;



    return 0;
}
