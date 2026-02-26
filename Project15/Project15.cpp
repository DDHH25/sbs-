
#include <stdio.h>

#define CUR_YEAR    2026

// 함수를 호출하기전에 먼저 정의가 있어야 한다!!!
// 함수는 반환값이 없거나, 무조건 1개여야 한다.
// 매개변수는 없거나, 여러개 지정할 수 있다.
// 호출시에는 매개변수가 선언된 위치와 개수가 일치하게 전달해야 한다.

// americano함수 구현하기
// money가 매개변수로 주어지면 잔수를 반환하는 함수를 구현하세요
// 아메리카노 한잔은 1500원 입니다. 예를들어 money가 2000이 주어지면
// 1을 반환하도록 합니다.
// 함수이름: americano
// 매개변수: money, int형
// 반환값: int
int americano(int money)
{
    return money / 1500;
}

// 정수 n을 주면 1부터 n까지의 합을 구하여 반환하는 함수를 정의
int totaler(int until)
{
    int total = 0;
    for (int i = 1; i <= until; i++)
    {
        total += i;
    }

    return total;
}

// 사칙연산 계산기 함수 구현하기: 더하기(+), 빼기(-), 곱하기(*), 나누기(/), 나머지(%)
// 그외는 지원하지 않는 연산자입니다를 출력하는 함수를 구현하세요
// 함수이름: calculater
// 매개변수1,2: 정수1, 정수2 int형
// 매개변수3: 연산자, char형
// 반환값: int

int calculater(int num1, char op, int num2)
{
    int res;
    switch (op)
    {
    case '+':
        res = num1 + num2;
        break;

    case '-':
        res = num1 - num2;
        break;

    case '*':
        res = num1 * num2;
        break;

    case '/':
        if (!num2)
        {
            printf("0으로 나눌 수 없습니다\n");
            return 0;
        }
        res = num1 / num2;
        break;

    case '%':
        if (!num2)
        {
            printf("0으로 나눌 수 없습니다\n");
            return 0;
        }
        res = num1 % num2;
        break;

    default:
        printf("지원하지 않는 연산자입니다\n");
        return 0;
    }

    return res;
}

// 나이(int)를 매개변수로 주면 출생 연도를 반환하는 함수를 구현하세요
// (현재2026) 23 => 2004
// birth_year
// 매개변수: age(정수)
// 반환값: 년도(정수)
int birth_year(int age)
{
    const int current_year = 2026;  // 상수로 만들기

    return current_year - age + 1;
}

// 상품금액을 매개변수로 주면 vat를 가산하여 최종 결제 금액을 
// 구하는 함수를 구현하세요
// vat는 상품금액의 10%입니다.
// 10000원이 입력되면 11000원을 반환하여야 합니다.

// 함수이름: calc_price
// 매개변수: price, int
// 반환값: int
int calc_price(int price)
{
    int vat = price / 10;
    return price + vat;
}


// 두개의 정수를 매개변수로받아서 두 정수의 합을 구한뒤
// 그 결과가 홀수인지 짝수인지 판별하여 출력하는 함수를 구현

// odd_or_even
// 매개변수: n1, n2 (int)
// 반환값: 없음
void odd_or_even(int n1, int n2)
{
    int sum = n1 + n2;
    printf("%s\n", sum % 2 ? "홀수" : "짝수");
}

// 알파벳 문자 한개를 매개변수로 받아서
// 대문자이면 소문자로 변환하여 반환하고
// 소문자이면 대문자로 변환하여 반환하는 함수를 구현하세요
// 그외는 0을 반환하세요
// 함수이름 : change_case
// 매개변수 : alpha, char
// 반환값: char
char change_case(char alpha)
{    
    if (alpha >= 'a' && alpha <= 'z')
        return alpha - 32;

    if (alpha >= 'A' && alpha <= 'Z')
        return alpha + 32;

    return 0;
}

int main()
{
    int money = 5000;
    int cup = americano(money);
    printf("%d원으로 아메리카노 %d잔 구매가능\n", money, cup);

    int sum = totaler(10);
    printf("1부터 10까지의 합: %d\n", sum);

    sum = totaler(100);
    printf("1부터 100까지의 합: %d\n", sum);

    sum = totaler(8);
    printf("1부터 8까지의 합: %d\n", sum);

    sum = calculater(5, '/', 0);
    printf("결과: %d\n", sum);

    printf("출생년도: %d\n", birth_year(40));

    printf("결제금액: %d\n", calc_price(25000));

    odd_or_even(5, 3);

    return 0;
}
