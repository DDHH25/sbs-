#include <stdio.h>  // 표준 입출력에 관련된 함수들이 정의되어 있다
#include <stdlib.h> // 표준 라이브러리에 해당되는 함수들이 정의되어 있다
#include <time.h>   // 시스템(컴퓨터) 시간에 관련된 함수들이 정의되어 있다

// 난수를 반환하는 함수를 만드세요
// 제한 범위를 주어 1 ~ n까지의 난수를 생성해야 합니다.
// 반환값은 정수(int)형입니다.
int make_random(int start, int end)
{
    if (start >= end)
        return 0;

    int range = end - start;

    return rand() % range + start;
}

void make_random_array(int array[], size_t count)
{
    for (int i = 0; i < count; i++)
    {
        array[i] = make_random(30, 100);
    }
}

void print_array(int arr[], size_t count)
{
    for (int i = 0; i < count; i++)
        printf("%d\t", arr[i]);
    
    printf("\n");
}

void exchange(int* n1, int* n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

// 배열의 아이템들을 순서대로 오름차순 정렬하기
void sort_array(int arr[], size_t count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                exchange(&arr[j], &arr[j + 1]);
        }
    }
}

// 배열을 전달받아서 최대값을 찾아서 반환하는 함수를 구현하세요
// 함수이름: find_max
// 매개변수: 배열, 배열의 개수
// 반환값: int, 최대값
int find_max(int arr[], size_t count)
{    
    int max = arr[0];
    for (int i = 1; i < count; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    return max;
}

/*
순차 탐색 알고리즘
*/
int find_value(int arr[], size_t count, int value)
{
    for (int i = 0; i < count; i++)
    {
        if (value == arr[i])
        {
            printf("%d 번만에 찾음\n", i + 1);
            return i;
        }
            
    }

    // 여기까지 왔으면 못 찾았다는 것임
    return -1;
}

/*
이진 탐색(Binary Search)
*/
int binary_search(int arr[], size_t count, int value)
{
    // 3개의 인덱싱 변수를 준비한다.
    int start = 0;          // 배열의 시작 인덱스
    int end = count - 1;    // 배열의 마지막 인덱스
    int mid;
    int i = 1;
    while (start <= end)
    {
        mid = (start + end) / 2;    // 현재 상태의 가운데 인덱스를 구함
        if (value == arr[mid])
        {
            printf("%d 번만에 찾음\n", i);
            return mid;
        }

        // 인덱스 범위를 재조정한다.
        if (value > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;

        i++;
    }

    // 여기까지 왔으면 못 찾았다는 것임
    return -1;
}


/*
학생의 중간고사 점수가 배열로 주어졌을때
총점과 평균을 반환하는 함수를 구현하세요
*/
float total_avg(float arr[], size_t count, float* ptot)
{
    float tot = 0.F;
    for (int i = 0; i < count; i++)
        tot += arr[i];

    float avg = tot / count;
    *ptot = tot;

    return avg;
    /*float res[2];
    res[0] = tot;
    res[1] = avg;

    return res;*/
}



int main()
{
    // 난수를 생성하기 위해 반드시 난수 생성 엔진을 초기화해야한다.
    srand(time(NULL));

    int arr[15];
    make_random_array(arr, 15);
    print_array(arr, 15);   // 정렬전 출력
    sort_array(arr, 15);    // 정렬
    print_array(arr, 15);   // 정렬후 출력

    // 정렬을 하는 이유는 탐색을 빠르게 처리하기 위해서다!!!
    const int COUNT = 1000;
    int arr2[COUNT];
    for (int i = 0; i < COUNT; i++)
        arr2[i] = i + 1;

    int result = binary_search(arr2, COUNT, 540);
    printf("찾은 인덱스: %d\n", result);

    // 정렬되지 않은 배열에서 데이터를 찾으려면 순차 탐색해야 함
    result = find_value(arr2, COUNT, 540);
    printf("찾은 인덱스: %d\n", result);

    float tot, avg;
    float score[] = { 100.F, 99.F, 88.F };
    avg = total_avg(score, 3, &tot);
    printf("avg = %.2f\n", avg);
    printf("tot = %.2f\n", tot);
    printf("총점: %.2f, 평균: %.2f\n", tot, avg);
    
    return 0;
}
