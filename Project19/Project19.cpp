#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  // 표준 입출력 함수들이 정의되어 있는 헤더파일
#include <string.h> // 문자열 처리에 관련된 함수들이 정의되어 있는 헤더파일

void string_info(char sz[])
{
    // 문자열의 길이: strlen
    int len = strlen(sz);
    printf("문자열의 길이: %d\n", len);

    // 배열의 크기
    printf("배열의 크기: %d\n", len+1);
}

// 문자열을 전달받아서 모두 대문자로 바꾸는 함수를 구현하세요
void upper_case(char sz[])
{
    for (int i = 0; i < strlen(sz); i++)
    {
        if (sz[i] >= 'a' && sz[i] <= 'z')
            sz[i] -= 32;
    }
}

// 문자열내에 있는 숫자들을 모두 더하여 반환하는 함수를 구현하세요
// "12345" ===> 15
// "a1b2c3d4e5" ===> 15
// "abcd123" ===> 6
// 
// string_sum
// 매개변수: 문자열
// 반환값: 정수형
int string_sum(const char* sz)
{
    int tot = 0;
    int len = strlen(sz);
    for (int i = 0; i < len; i++)
    {
        if (sz[i] >= '0' && sz[i] <= '9')
            tot += (sz[i] - '0');
    }

    return tot;
}


// 문자열을 전달받아서 해당 문자열을 뒤에서부터 출력하도록 함수를 구현하세요
// print_reverse
// 매개변수: 문자열, 변환하면 안됨
// 반환값은 없음
// abc ===> cba
void print_reverse(const char* sz)
{
    int len = strlen(sz);
    for (int i = len-1; i >= 0; i--)
    {
        printf("%c", sz[i]);
    }
    printf("\n");
}


// 문자열을 전달받아서 특정 문자가 몇개 있는지 카운트하여
// 그 결과를 반환하는 함수를 구현하세요

// char_count
// 매개변수1: 문자열, 변환하면 안됨
// 매개변수2: 찾고자하는 문자
// 반환값 : 찾고자하는 문자의 개수
int char_count(const char* sz, const char ch)
{
    int count = 0;
    int len = strlen(sz);
    for (int i = 0; i < len; i++)
    {
        if (ch == sz[i])
            count++;
    }
    return count;
}

// 문자열에서 특정 문자를 찾아서 있다면 해당 문자의 인덱스를 반환하고
// 없다면 -1을 반환하는 함수를 구현하세요
// 
// find_char
// 매개변수1: 문자열, 변환하면 안됨
// 매개변수2: 찾고자 하는 문자
// 반환값: 찾고자 하는 문자의 인덱스, 없으면 -1
int find_char(const char* sz, const char ch)
{    
    int len = strlen(sz);
    for (int i = 0; i < len; i++)
    {
        if (ch == sz[i])
            return i;
    }

    return -1;
}


// 문자열을 받아서 모음은 출력하지 않고 자음만 출력하는 함수를 구현하세요
// 모음 : aeiou

// print_conson
// 매개변수: const char* sz
// 반환값: 없음
// Nice to meet you ===> Nc t mt y
void print_conson(const char* sz)
{
    int len = strlen(sz);
    for (int i = 0; i < len; i++)
    {
        if (find_char("aeiou", sz[i]) >= 0)
            continue;

        printf("%c", sz[i]);
    }
}

/*
switch (sz[i])
{
case 'a':
case 'e':
case 'i':
case 'o':
case 'u': continue;
}
*/



int main()
{
    char sz1[] = "Hello World";
    string_info(sz1);

    upper_case(sz1);
    printf("%s\n", sz1);    // 

    char sz2[] = "a1b2c3d4e5";
    printf("%d\n", string_sum(sz2));

    const char* psz = "Nice to meet you";
    // psz = "Hello C";

    strcpy(sz1, "Hello C");
    sz1[1] = 'E';   // 개별적 문자 수정 가능
    printf("%s\n", sz1);

    //strcpy(psz, "SBS");   // 포인터 문자열에 문자열 복사 불가능

    // psz에서 c출력해보기
    printf("%c\n", psz[2]);
    //psz[2] = 'C'; // 포인터 문자열은 값을 대입할 수 없음
       
    print_reverse(sz1);
    print_reverse(psz);

    //// 문자열의 길이: strlen
    //printf("sz1의 길이: %d\n", strlen(sz1));    
    //// 배열의 크기
    //printf("sz1 배열의 크기: %d\n", sizeof(sz1));

    return 0;
}
