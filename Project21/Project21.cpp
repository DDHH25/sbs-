// 숫자 야구 게임 : 컴퓨터가 랜덤하게 생성한 3자리 숫자를 사용자가 맞추는 게임
// 사용자가 숫자를 입력할때 마다 틀리면 컴퓨터가 힌트를 준다.
// 각 자리의 숫자는 중복 불가 ex) 112(안됨)
// 0 안됨, 1 ~ 9까지만 사용가능
// 
// ex) computer: 473
// 유저: 123 ====> 1 strike, 0 ball
// 유저: 723 ====> 1 strike, 1 ball
// 유저: 743 ====> 1 strike, 2 ball
// 유저: 812 ====> 0 strike, 0 ball
// 유저: 471 ====> 2 strike, 0 ball
// 유저: 473 ====> 3 strike, 0 ball ===> Game 종료, 6번에 완료
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // 난수 발생을 위해 필요함
#include <time.h>   // 난수 발생을 위해 필요함
#include <conio.h>  // windows os 전용 헤더파일(표준이 아님)

#define COUNT   3

/*
순차 탐색 함수
*/
int find_value(int arr[], size_t len_arr, int to_find)
{
    for (int i = 0; i < len_arr; i++)
    {
        // 값을 찾았다면 해당 인덱스를 반환하고 즉시 함수 종료
        if (to_find == arr[i])
            return i;
    }

    // 여기까지 왔으면 못찾았다는 것임
    return -1;
}


/**
배열 arr에 난수를 대입하는 함수
start ~ end 까지의 난수를 생성하여 arr에 중복되지 않게 저장

@param arr : 난수를 저장할 배열
@param len_arr : 배열의 길이(아이템들의 개수)
@param start : 난수 발생의 시작값
@param end : 난수 발생의 마지막값
*/
void make_random_array(int arr[], size_t len_arr, int start, int end)
{    
    // 
    // start ~ end까지의 난수 생성
    for (int i = 0; i < len_arr;)
    //int i = 0;
    //while( i < len_arr )
    {
        // 난수를 생성하여 임시변수에 저장
        int r = rand() % (end - start) + start;

        // 이 배열에 현재 만들어진 값이 있는지 중복 검사
        // r을 arr에서 못찾았다면 r을 arr에 대입
        if (find_value(arr, len_arr, r) < 0)
            arr[i++] = r;   // i는 대입이후 증가됨
    }    
}

/*
배열 출력 함수
*/
void print_array(int arr[], size_t len_arr)
{
    for (int i = 0; i < len_arr; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

/**
입력된 정수가 3자리 숫자인지 검증
입력된 정수가 중복값을 갖고 있지 않은지 검증
입력값에 0이 있는지 여부도 검사
*/
int validate(int number, int arr[], size_t len_arr)
{
    int rem;
    for (int i = len_arr-1; i >= 0; i--)
    {        
        rem = number % 10;
        if (rem == 0)
            return 0;   // 입력값 오류

        // rem이 기존 배열에 없다면 값을 대입
        if (find_value(arr, len_arr, rem) >= 0)
            return 0;   // 중복값으로 인한 입력값 오류

        arr[i] = rem;
        number /= 10;
    }

    if (number) 
        return 0;

    // number의 값이 0이면 1을 반환하고 아니면 0을 반환    
    return (number) ? 0 : 1;
}

void clear_array(int arr[], size_t len_arr)
{
    for (int i = 0; i < len_arr; i++)
        arr[i] = 0;
}

void input_user_value(int arr[], size_t len_arr)
{
    int tmp;

    do
    {
        system("cls");  // 콘솔 화면 청소
        printf("숫자를 입력하세요 >>> ");
        scanf("%d", &tmp);
        if (validate(tmp, arr, COUNT))
            return;
        
        printf("잘 못 입력했습니다.\n");
        printf("아무키나 입력하세요...\n");
        clear_array(arr, COUNT);
        _getch();   // 키입력 대기를 하는 함수

    } while (1);
}

/*
3strike가 나오면 1을 반환하고, 그렇지 않으면 0을 반환
*/
int judge(int coms[], int user[], size_t len)
{
    int s = 0;
    int b = 0;
    int index;
    for (int i = 0; i < len; i++)
    {
        index = find_value(coms, len, user[i]);
        if (index < 0) continue;    // 못찾으면 돌아감(s,b를 증가시키지 않음)

        // 여기까지 왔으면 찾았다는것임
        if (index == i)
            ++s;
        else
            ++b;
    }

    printf("%d 스트라이크, %d 볼\n", s, b);
    _getch();

    return s == 3;
}


int main()
{
    srand(time(NULL));  // 난수 발생 초기화

    int hidden[COUNT] = { 0 };  // 컴퓨터가 정할 랜덤한 3자리수
    int user[COUNT] = { 0 };

    make_random_array(hidden, COUNT, 1, 10);
    // print_array(hidden, COUNT);
    printf("컴퓨터의 숫자를 맞춰보세요~~~\n");
        
    int result = 0;
    do
    {
        input_user_value(user, COUNT);
        print_array(user, COUNT);

        result = judge(hidden, user, COUNT);
        clear_array(user, COUNT);
    } while (!result);

    return 0;
}
