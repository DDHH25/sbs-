#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_NAME    20

typedef struct
{
    char name[MAX_NAME];
    short kor;
    short eng;
    short math;
    short total;
    float avg;
    char grade;
} SCORE;


// 함수의 원형 정의: 함수를 호출하는쪽에 정보를 제공하기 위함
char get_grade(float);  // 원형 정의는 반드시 끝에 ;을 붙여야 함
void input_score(SCORE* psc);
void print_score(SCORE* psc);

void save_text(const char* filename);
void load_text(const char* filename);
long get_file_size(const char* filename);
