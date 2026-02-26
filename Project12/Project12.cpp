#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    // 배열 arr을 정의
    // 배열의 길이 : 5, (n)
    // 배열의 타입 : int
    int arr[5]; 
    arr[0] = 100;   // 배열의 첫번째 요소에 값 100을 대입
    // 인덱스의 범위 : 0 ~ n-1
    for (int i = 0; i < 5; i++) // 0 ~ 4
    {
        arr[i] = i + 1; // 1,2,3,4,5
    }

    // arr의 모든 값들을 옆 방향으로 출력하기
    // 1    2   3   4   5
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]); // arr[0], arr[1], arr[2], arr[3], arr[4]
    }
    printf("\n");


    // float형 배열 10칸 짜리를 선언해보세요
    float nums[10]; // 4 * 10
    // nums의 값을 다음과 같이 만드세요
    // 5.0, 10.0, 15.0, 20.0, 25.0 ... 50.0
    for (int i = 0; i < 10; i++)
    {
        nums[i] = (i+1) * 5.F;
        printf("%.1f ", nums[i]);
    }

    // 배열의 초기화
    char sz[3] = { 65, 66, 67 };    // 100, 101, 102
    short my_nums[] = {1,2,3,4,5,6,7};  // 7칸짜리 short형배열을 1,2,3,4,5,6,7로 초기화
    long bigs[5] = { 0 };   // bigs의 모든 요소들을 0으로 초기화함

    // sz배열의 모든 요소에 정수 값을 입력받아 대입하세요
    // 
    printf("\n");
    //for (int i = 0; i < 3; i++)
    //{
    //    printf("정수 입력: ");
    //    scanf("%hhd", &sz[i]);
    //}    

    //for (int i = 0; i < 3; i++)
    //    printf("%d\t", sz[i]);

    // 배열의 메모리 할당 크기를 알아보기
    printf("int형의 크기: %llubytes\n", sizeof(int));       // 4
    printf("배열 arr의 크기: %llubytes\n", sizeof(arr));    // 배열의 크기 = 배열의 타입의 크기 * 배열의 길이
    printf("배열 nums의 크기: %llubytes\n", sizeof(nums));
    printf("배열 sz의 크기: %llubytes\n", sizeof(sz));
    printf("배열 my_nums의 크기: %llubytes\n", sizeof(my_nums));
    printf("배열 bigs의 크기: %llubytes\n", sizeof(bigs));

    arr[0] = 88;
    arr[1] = 95;
    arr[2] = 100;
    arr[3] = 70;
    arr[4] = 65;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // 두 값을 서로 교환하기
                int tmp = arr[j];   
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < 5; i++) 
    {
        printf("%d\t", arr[i]);
    }

    // arr배열의 값들의 합과 평균을 구하여 다음과 같이 출력하세요
    // 합계: xxx
    // 평균: xx.xx
    int total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += arr[i];
    }
    printf("합계: %d\n", total);
    printf("평균: %.2f\n", total/5.F);


    // 이 배열의 아이템들의 개수를 출력하세요
    short numbers[] = { 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9 };
    // number의 아이템 개수: xx개
    int index = sizeof(numbers) / sizeof(short);
    printf("number의 아이템 개수: %d개\n", index);

    int arr2[1];
    printf("arr2의 크기(bytes): %d\n", sizeof(arr2));
    printf("int형의 크기: %d\n", sizeof(int));


    // numbers배열의 가장 마지막 아이템에 100을 대입하고
    // numbers 배열의 인덱싱을 이용하여 그 값을 출력하세요
    // x에는 인덱스 번호를 출력
    // numbers배열의 가장 마지막 아이템: numbers[x] = 100
    numbers[index - 1] = 100;   // numbers배열의 가장 마지막 아이템에 100 대입하기
    printf("numbers배열의 가장 마지막 아이템: numbers[%d] = %d\n", index - 1, numbers[index - 1]);

    // for 문을 이용하여 numbers 배열에 1 ~ 개수까지의 수를 
    // 각 아이템에 순서대로 대입하세요
    for (int i = 0; i < index; i++)
    {
        numbers[i] = i + 1;
    }

    return 0;
}
