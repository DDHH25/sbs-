#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>

// typedef: 형(Data type) 재정의
typedef unsigned int    UINT;
typedef unsigned short  JUMSU;
typedef unsigned long long TIME;



// 구조체(Structure)
typedef struct {
    char name[20];
    int age;
    float height;
} PERSON;

typedef struct 
{
    char name[20];
    short kor;
    short eng;
    short math;
    short total;
    float avg;
    char grade;
} SCORE;

void print_person(PERSON* p)
{
    printf("이름: %s\n", p->name);
    printf("나이: %d\n", p->age);
    printf("키: %.2f\n", p->height);
}

void print_score(SCORE* s)
{
    // 구현해보세요
}

int main()
{
    PERSON hong;
    hong.age = 30;
    hong.height = 180.5F;
    strcpy(hong.name, "홍길동");
    print_person(&hong);    

    SCORE score;
    strcpy(score.name, "홍길동");
    score.kor = 100;
    score.eng = 100;
    score.math = 100;
    score.total = score.kor + score.eng + score.math;
    score.avg = score.total / 3.F;

    print_score(&score);

    printf("hong의 크기: %llu 바이트\n", sizeof(hong));
    printf("score의 크기: %llu 바이트\n", sizeof(SCORE));

    return 0;
}
