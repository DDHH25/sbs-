// Exercise.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// 1,2,3,4,5 ===> 5,4,3,2,1
int* solution(int num_list[], size_t num_list_len) {
    
    size_t size = sizeof(int) * num_list_len;
    int* answer = (int*)malloc(size);
    if (!answer)
        return NULL;

    for (int i = 0; i < num_list_len; i++)
    {
        answer[num_list_len-1-i] = num_list[i];
    }
    
    return answer;
}


// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution2(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t size = strlen(my_string);
    char* answer = (char*)malloc(size+1);
    for (int i = 0; i < size; i++)
    {
        answer[size - 1 - i] = my_string[i];
    }
    answer[size] = '\0';

    return answer;
}


// 정수 배열 numbers와 정수 num1, num2가 매개변수로 주어질 때, 
// numbers의 num1번 째 인덱스부터 num2번째 인덱스까지 
// 자른 정수 배열을 return 하도록 solution 함수를 완성해보세요.
// numbers_len은 배열 numbers의 길이입니다.
// {1,2,3,4,5}
int* solution3(int numbers[], size_t numbers_len, int num1, int num2) {
    // 잘라질 배열의 개수를 구함
    int count = num2 - num1 + 1;

    // 잘라질 배열
    int* answer = (int*)malloc(sizeof(int) * count);
    if (!answer) return NULL;   // 메모리 할당 실패시에 바로 종료

    for (int i = num1; i <= num2; i++)
    {
        answer[i - num1] = numbers[i];
    }

    return answer;
}


// 영어에선 a, e, i, o, u 다섯 가지 알파벳을 모음으로 분류합니다. 
// 문자열 my_string이 매개변수로 주어질 때 모음을 제거한 문자열을 return하도록 solution 함수를 완성해주세요.

// 파라미터로 주어지는 문자열은 const로 주어집니다. 
// 변경하려면 문자열을 복사해서 사용하세요.
char* solution4(const char* my_string) {
    int size = strlen(my_string) + 1;
    char* answer = (char*)malloc(size);
    if (!answer) return NULL;
    memset(answer, 0, size);    // 문자열의 자연스러운 완성을 위해 내용을 모두 0으로 초기화해둔다

    const char* vow = "aeiou";
    for (int i = 0, j=0; i < size - 1; i++)
    {        
        if (!strchr(vow, my_string[i]))
            answer[j++] = my_string[i];
    }

    return answer;
}

void print_array(int arr[], size_t len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr1[] = { 1,2,3,4,5 };
    int arr2[] = { 1,3,5 };
    // int* p = solution3(arr1, 5, 1, 3);
    int* p = solution3(arr2, 3, 1, 2);    
    print_array(p, 2);    
    if (p)
    {
        free(p);
        p = NULL;
    }

    //char* sz = solution4("bus");
    char* sz = solution4("nice to meet you");
    printf("%s\n", sz);
    if (sz)
    {
        free(sz);
        sz = NULL;
    }

    return 0;
}



//
//int main()
//{
//    int arr[] = { 1,2,3,4,5 };
//    int* new_arr = solution(arr, 5);
//    // 5,4,3,2,1
//    if (new_arr)
//    {
//        for (int i = 0; i < 5; i++)
//            printf("%d ", new_arr[i]);
//
//        printf("\n");
//        free(new_arr);
//        new_arr = NULL;
//    }
//
//    char* new_sz = solution2("Hello");
//    if (new_sz)
//    {
//        printf("%s\n", new_sz);
//        free(new_sz);
//        new_sz = NULL;
//    }
//
//    return 0;
//}
