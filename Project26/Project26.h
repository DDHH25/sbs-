#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <conio.h>

#define MAX_NAME	20
#define FILE_NAME	"score.dat"

typedef unsigned int	uint;

typedef struct {
	uint number;			//4
	char name[MAX_NAME];	//20
	uint kor;				// 4
	uint eng;	// 4
	uint math;	// 4
	uint total;	// 4
	float avg;	// 4
	char grade;	// 1
	uint rank;	// 
} SCORE;


void save_score(const SCORE* scores, size_t count);
size_t load_score(SCORE** ppScores);


void show_menu();
char select_menu();
char get_grade(float avg);
void wait();

int find_score(SCORE* pScores, size_t count, uint number);
void print_scores(const SCORE* pScores, size_t count);
size_t input_score(SCORE** ppScores, size_t count);
void select_update(SCORE* pScores, size_t count);
size_t remove_score(SCORE** ppScores, size_t count);
