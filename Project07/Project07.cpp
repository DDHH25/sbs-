#include <stdio.h>

// 콘솔 입출력 함수가 정의된 헤더 파일
// 윈도우즈 OS에서만 사용가능(MSC 컴파일러에서만 지원)
#include <conio.h>  

// 반복문 : while, do~while, for

int main()
{
    // while 반복문 : 조건식의 결과가 참인동안 반복실행된다!!
    // 조건식의 결과에 따라 한번 반복실행되지 않을 수 있다.
    // 반복 조건을 먼저 판단하고 반복에 들어간다.
    // 반복해야할 회수가 명확하지 않을때 주로 사용한다.
    /*
    while (조건식)
    {
        반복 실행할 명령문(들)...
    }
    */
    int i = 0;
    while (i < 5)
    {
        printf("i = %d\n", i + 1);
        i++;
    }

    i = 0;  // i를 다시 0으로 초기화
    while (i++ < 15) printf("=");


    // 1부터 10까지의 합 구하기
    i = 1;
    int total = 0;  // total이라는 변수를 선언하고 0으로 초기화
    // 0 + 1 + 2 + 3 + 4 + 5 + ... + 10 = 55
    while (i <= 10)
    {
        total += i;     // total = total + i;
        i++;
    }
    printf("\ntotal = %d\n", total);

    i = 0;  // i를 다시 0으로 초기화
    while (i++ < 15) printf("=");

    // 0부터 10까지의 짝수들의 합을 구하세요
    i = 0;
    total = 0;
    while (i <= 10)
    {        
        total += i;
        i += 2;
    }
    printf("\ntotal = %d\n", total);

    i = 0;  // i를 다시 0으로 초기화
    while (i++ < 15) printf("=");
    printf("\n");   // 한 줄 건너뛰기

    // 구구단 출력하기
    i = 1;
    while (i < 10)
    {
        printf("2 x %d = %d\n", i, i * 2);
        i++;
    }

    // 
    int ch = 0;
    while (ch != 'x')
    {
        printf("\n종료하려면 'x'를 입력하세요: ");
        //_getch();
        ch = _getch();   // conio.h이 포함되어 있어야 한다.
        printf("%c", ch);
    }

    // 1 부터 100까지의 합을 구하세요
    i = 1;
    total = 0;
    while (1)   // 무한 반복
    {
        total += i;
        i++;

        // 반복문안에서 탈출조건을 체크하여 탈출시킴
        if (i > 100) // i가 100보다 크다면...
            break;  // 현재 반복문을 즉시 탈출시킴
    }
    printf("\ntotal = %d\n", total);

    // 반복문 중첩시키기
    int dan = 2;    // 단수를 설정할 변수를 선언한다.    
    while (dan <= 9)
    {
        // printf("--- %d단 ---\n", dan);
        i = 1;
        while (i < 10)
        {
            printf("%d x %d = %d\n", dan, i, dan*i);
            i++;
        }
        dan++;
    }
    /*
    2 x 1 = 2   3 x 1 = 3   4 x 1 = 4   ... 9 x 1 = 9
    2 x 2 = 4   3 x 2 = 6   4 x 2 = 8   ... 9 x 2 = 18
    2 x 3 = 6   3 x 3 = 9   4 x 3 = 12  ... 9 x 3 = 27
    ...
    ...
    2 x 9 = 18  3 x 9 = 27  4 x 9 = 36  ... 9 x 9 = 81
    */    

    i = 1;
    while (i <= 9)
    {                
        dan = 2;
        while (dan <= 9)
        {
            printf("%d x %d = %d\t", dan, i, dan * i);
            dan++;
        }
        printf("\n");   // 줄바꿈
        i++;
    }

    // 1 ~ 99까지 테이블 모양으로 출력하기
    /*
    1   2   3   4   5   6   7   8   9   10
    11  12  13  14  15  16  17  18  19  20
    21  22  23  24  25  26  27  28  29  30
    ...
    ...
    91  92  93  94  95  96  97  98  99
    */
    i = 1;
    while (i < 100)
    {
        printf("%d\t", i);
        if (i % 10 == 0) // i가 10의 배수이면
            printf("\n");

        i++;
    }

    
    return 0;
}
