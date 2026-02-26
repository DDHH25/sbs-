#include "Project26.h"

void show_menu()
{
	system("cls");	// 콘솔화면 클리어하기

	printf("1. 점수 입력\n");
	printf("2. 점수 출력\n");
	printf("3. 점수 수정\n");
	printf("4. 점수 삭제\n");
	printf("============\n");
	printf("x. 종료\n");
	printf("============\n");
}

char select_menu()
{
	int menu;
	do
	{
		printf("메뉴를 선택해주세요 >>> ");
		menu = _getch();		

		if (menu >= '1' && menu <= '4')
			return (char)menu;

		if (menu == 'x' || menu == 'X')
			return 'x';

		printf("잘 못 입력했습니다, 다시 입력해주세요...\n");
	} while (1);

	return 0;
}



char get_grade(float avg)
{
	int tmp = (int)avg / 10;
	switch (tmp)
	{
	case 10:
	case 9:
		return 'A';

	case 8:
		return 'B';

	case 7:
		return 'C';

	case 6:
		return 'D';
	}

	return 'F';
}


/*
한 명의 성적데이터를 입력받아서 반환하는 함수

ppScores에는 main함수의 동적 메모리 배열의 주소가 저장되어 있음
*/
size_t input_score(SCORE** ppScores, size_t count)
{
	if (!ppScores)
	{
		printf("잘 못된 호출입니다.\n");
		return count;
	}
	// printf("SCORE 구조체의 크기: %llubytes\n", sizeof(SCORE));

	system("cls");

	SCORE sc;	// 입력을 받을 임시 구조체 변수

	printf("번호를 입력하세요 >>> ");
	scanf("%d", &sc.number);

	char tmp;
	scanf("%c", &tmp);

	printf("이름을 입력하세요 >>> ");
	fgets(sc.name, MAX_NAME, stdin); // 공백포함 문자열 입력받기
	sc.name[strlen(sc.name) - 1] = '\0';  // 입력된 엔터키(\n) 제거하기

	printf("국어,영어,수학 점수를 차례로 입력하세요 >>> ");
	scanf("%d %d %d", &sc.kor, &sc.eng, &sc.math);

	// total 구하기
	sc.total = sc.kor + sc.eng + sc.math;
	sc.avg = sc.total / 3.F;

	sc.grade = get_grade(sc.avg); // 등급구하기

	// 배열 생성하기
	size_t new_count = count + 1;	// 1개 입력처리를 해야 하므로 기존 개수보다 1더큰 개수를 만듬
	size_t old_size = sizeof(SCORE) * count;
	size_t new_size = sizeof(SCORE) * new_count;	// 새로운 배열의 크기(바이트 단위)를 구함

	// Heap영역에 배열을 새롭게 생성
	SCORE* pNew = (SCORE*)malloc(new_size);
	if (!pNew)
	{
		printf("배열 생성 실패!\n");
		return count;
	}

	// 기존 배열을 새배열에 모두 복사하기
	SCORE* pOldScore = *ppScores;
	if (pOldScore)
	{
		// 기존에 데이터가 있다면
		memcpy(pNew, pOldScore, old_size);
		free(pOldScore);	// 기존 배열 삭제하기		
	}

	// 지금 입력받은 데이터를 새로운 배열에 복사하기
	memcpy(pNew + count, &sc, sizeof(SCORE));

	// 배열의 주소를 새 배열주소로 업데이트해줌
	*ppScores = pNew;

	return new_count;
}


void print_scores(const SCORE* pScores, size_t count)
{
	if (!pScores)
	{
		printf("점수 데이터 출력 실패!\n");
		return;
	}

	system("cls");
	printf("번호\t이름\t국어\t영어\t수학\t총점\t평균\t등급\n");
	for (int i = 0; i < count; i++)
	{
		printf("%d\t", pScores[i].number);
		printf("%s\t", pScores[i].name);
		printf("%d\t", pScores[i].kor);
		printf("%d\t", pScores[i].eng);
		printf("%d\t", pScores[i].math);
		printf("%d\t", pScores[i].total);
		printf("%.2f\t", pScores[i].avg);
		printf("%c\n", pScores[i].grade);
	}
}


void wait()
{
	printf("\n\n계속하려면 아무키나 입력하세요...\n");
	_getch();
}


int find_score(SCORE* pScores, size_t count, uint number)
{
	for (int i = 0; i < count; i++)
	{
		if (pScores[i].number == number)
			return i;
	}

	return -1;
}


void select_update(SCORE* pScores, size_t count)
{
	if (!pScores || !count)
	{
		printf("수정할 데이터가 없습니다.\n");
		return;
	}
		

	print_scores(pScores, count);

	printf("=================================================\n");		

	int idx = -1;
	do
	{
		uint number;

		printf("수정하고자 하는 학생의 번호를 입력하세요 >>> ");
		scanf("%d", &number);
		idx = find_score(pScores, count, number);
	} while (idx == -1);

	char tmp;
	scanf("%c", &tmp);
	
	printf("번호: %d\n", pScores[idx].number);
	printf("이름: %s\n", pScores[idx].name);
	printf("점수(국,영,수): %3d %3d %3d\n", pScores[idx].kor, pScores[idx].eng, pScores[idx].math);
	printf("총점: %3d\n", pScores[idx].total);
	printf("평균: %.2f\n", pScores[idx].avg);

	printf("=================================================\n");

	printf("이름을 입력하세요 >>> ");
	fgets(pScores[idx].name, MAX_NAME, stdin); // 공백포함 문자열 입력받기
	pScores[idx].name[strlen(pScores[idx].name) - 1] = '\0';  // 입력된 엔터키(\n) 제거하기

	printf("국어,영어,수학 점수를 차례로 입력하세요 >>> ");
	scanf("%d %d %d", &pScores[idx].kor, &pScores[idx].eng, &pScores[idx].math);

	// total 구하기
	pScores[idx].total = pScores[idx].kor + pScores[idx].eng + pScores[idx].math;
	pScores[idx].avg = pScores[idx].total / 3.F;

	pScores[idx].grade = get_grade(pScores[idx].avg); // 등급구하기
}

size_t remove_score(SCORE** ppScores, size_t count)
{
	SCORE* pScores = *ppScores;

	if (!pScores || !count)
	{
		printf("삭제할 데이터가 없습니다.\n");
		return 0;
	}

	int idx = -1;
	do
	{
		print_scores(pScores, count);
		printf("삭제하려는 번호를 입력하세요 >>> ");

		uint number;
		scanf("%u", &number);

		// 입력된 번호의 인덱스를 저장한다.
		idx = find_score(pScores, count, number);
	} while (idx == -1);

	// 새로 할당받을 배열의 바이트 단위 크기를 구함
	size_t new_count = count - 1;
	if (!new_count)
	{
		// 기존에 데이터가 1개밖에 없는 상황이면
		free(pScores);
		*ppScores = NULL;
		return 0;
	}


	size_t new_size = sizeof(SCORE) * new_count;
	SCORE* pNewScores = (SCORE*)malloc(new_size);
	if (!pNewScores)
	{
		printf("데이터를 삭제할 수 없습니다.\n");
		return count;
	}

	for (int i = 0, j = 0; i < count; i++)
	{
		if (i == idx)	// 현재 복사 대상이 삭제할 아이템이면 스킵!!!
			continue;

		// 기존 배열의 내용을 새로운 배열에 복사하기
		memcpy(pNewScores + j, pScores + i, sizeof(SCORE));
		j++;
	}

	// 메인 배열 주소 업데이트
	*ppScores = pNewScores;

	// 기존의 배열은 삭제시킴
	free(pScores);

	return new_count;
}