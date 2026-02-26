#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  // Standard Input/Output, 표준 입출력에 관련된 함수들 정의
#include <string.h> // 문자열 처리에 관련된 함수들이 정의


int main()
{
    // 0 == '\0'
    // '\0': null terminated character, 문자 배열에 이 값이 들어가야 문자열이 완성된다.

    // 'A' == 65

    // 배열로 문자열 만들기
    // 문자열은 배열이다.
    //char sz[] = {65, 66, 67, 68, 69, 70, 0};
    // char sz[] = { 'A', 'B', 'C', 'D', 'E', 'F','\0' };
    //char sz[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char sz[] = "Hello";  // 문자열(String)
    int len = sizeof(sz);    // 배열의 길이 구하기
    /*for (int i = 0; i < len; i++)
    {
        printf("%c", sz[i]);
    }*/
    printf("sz배열의 크기: %d\n", len);
    printf("%s\n", sz);
    // sz[1] = 'E';    // 1번 인덱스의 값을 'E'로 대입
    // printf("%s\n", sz);

    // 배열의 크기는 문자열의 길이와 같은가?
    // 문자열의 길이 구하기
    int slen = strlen(sz);
    printf("sz문자열의 길이: %d\n", slen);

    char sz2[] = "Hello";  // 문자열(String)
    // 문자열 비교하기
    // if (sz == sz2)
    if (strcmp(sz, sz2)==0)
        printf("%s와 %s는 서로 같음\n", sz, sz2);
    else
        printf("%s와 %s는 서로 다름\n", sz, sz2);


    // & : 주소연산자
    // 문자열의 입력
    char name[20];    // 알파벳 9글자까지 입력가능
    printf("이름을 입력하세요: ");
    // scanf()는 공백문자를 포함한 문자열을 입력받을 수 없다
    //scanf("%s", name);  // 문자열을 입력받을때는 주소연산자를 붙이지 않는다.
    //printf("%s\n", name);    

    // fgets(받을배열, 최대길이, stdin);
    // 표준입력장치로부터 문자열을 입력받아 name에 대입한다.
    fgets(name, 20, stdin);    
    len = strlen(name); // 입력받은 문자열의 길이 
    name[len - 1] = 0;      // \n 제거
    printf("name: %s\n", name);   // Tom Cruze\n

    /*
    입력 데이터: "Tom Cruze\n"
    scanf: "Tom"
    fgets: "Tom Cruze\n"
    */

    // 문자열길이: strlen
    // 문자열비교: strcmp
    

    printf("sz: %s\n", sz); // Hello
    
    // 배열 문자열대입:
    // sz <=== name
    // sz = "ABCDE";
    // 10 = "abc";
    strcpy(sz, "ABCDE");    // sz에 "ABCDE"를 대입
    printf("sz: %s\n", sz);  // ABCDE

    // sz의 공간이 6byte인데 7byte의 값을 대입시도하면서...
    // Overflow Runtime Error가 발생한다!!!
    // strcpy(sz, "ABCDEF");    // sz에 "ABCDEF"를 대입 시도
    // printf("sz: %s\n", sz);  // ABCDE

    // syntax error(comile error)
    // runtime error <--- debugging 
    // logical error

    // 문자열 추가
    // s = 'abc' 
    // s = s + 'def'
    // s == 'abcdef'
    // name[20]: 알파벳 19글자까지를 저장할 수 있다.
    strcat(name, "plus string"); // name = name + "plus string";
    printf("name: %s\n", name);



    return 0;
}
