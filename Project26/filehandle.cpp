#include "Project26.h"


long get_file_size(const char* filename)
{
	if (!filename)
	{
		printf("파일명은 주어져야 합니다\n");
		return -1;
	}

	FILE* fp = NULL;
	fp = fopen(filename, "rb");
	if (!fp)
	{
		printf("파일을 열 수 없습니다.\n");
		return -1;
	}

	// 커서를 파일의 끝으로 이동시킨다
	fseek(fp, 0, SEEK_END);

	long size = ftell(fp);	// 현재 커서의 위치를 알려줌 ===> 파일의 끝에서 커서의 위치는 파일의 크기와 같다

	if (fp)
	{
		fclose(fp);
		fp = NULL;
	}

	return size;
}


void save_score(const SCORE* scores, size_t count)
{
	if (!scores)	// score == NULL
	{
		printf("score가 NULL입니다.\n");	// Debugging 용도
		return;
	}

	// 파일 핸들 변수를 초기화한다.
	FILE* fp = NULL;
	fp = fopen(FILE_NAME, "wb");	// wb: binaray 파일 write(저장)
	if (!fp) // fp == NULL
	{
		printf("score.dat파일을 열 수 없습니다.\n");
		return;	// 파일을 열 수 없다면 바로 종료
	}

	fwrite(scores, sizeof(SCORE), count, fp);


	if (fp)	// fp != NULL
	{
		fclose(fp);
		fp = NULL;
	}	
}

/*
파일로부터 데이터들을 읽어서 동적 배열에 로딩한다.
읽은 데이터들의 개수를 반환한다.
*/
size_t load_score(SCORE** ppScores)
{
	long size = get_file_size(FILE_NAME);
	if (size <= 0)
	{
		printf("저장된 데이터가 없습니다\n");
		return 0;
	}

	FILE* fp = NULL;
	fp = fopen(FILE_NAME, "rb");	// rb: binaray 파일 read(읽기)
	if (!fp) // fp == NULL
	{
		printf("score.dat파일을 열 수 없습니다.\n");
		return 0;	// 파일을 열 수 없다면 바로 종료
	}

	// 동적 메모리 할당
	SCORE* score = (SCORE*)malloc(size);
	if (!score)
	{
		printf("메모리 할당 실패!\n");
		if (fp)
		{
			fclose(fp);
			fp = NULL;
		}
		return 0;
	}

	fread(score, size, 1, fp);
	
	if (fp)
	{
		fclose(fp);
		fp = NULL;
	}

	size_t count = size / sizeof(SCORE);	// 개수 구하기
	*ppScores = score;	// 배열 업데이트

	return count;
}