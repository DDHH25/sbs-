

#include "Project25.h"

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


void input_score(SCORE* psc)
{
    if (!psc)
        return;

    // 문자열 입력을 쉽게 받기 위하여 모든 자리를 0으로 채워둔다
    memset(psc, 0, sizeof(SCORE));

    // 공백 입력 가능한 입력함수는???
    printf("이름을 입력하세요 >>> ");
    fgets(psc->name, MAX_NAME, stdin);  // 공백문자도 입력할 수 있다.
    int len = strlen(psc->name);
    psc->name[len - 1] = '\0';  // enter key code가 입력된 자리에 null terminated 문자를 넣어서 마감해준다.

    printf("국어점수를 입력하세요 >>> ");
    scanf("%d", &(psc->kor));

    printf("영어점수를 입력하세요 >>> ");
    scanf("%d", &(psc->eng));

    printf("수학점수를 입력하세요 >>> ");
    scanf("%d", &(psc->math));

    // 총점구하기
    psc->total = psc->kor + psc->eng + psc->math;

    // 평균구하기
    psc->avg = psc->total / 3.f;

    psc->grade = get_grade(psc->avg);
}



void print_score(SCORE* psc)
{
    if (!psc)
        return;

    printf("이름: %s\n", psc->name);
    printf("점수: 국어(%d), 영어(%d), 수학(%d)\n", psc->kor, psc->eng, psc->math);
    printf("총점: %d\n", psc->total);
    printf("평균: %.2f\n", psc->avg);
    printf("등급: %c\n", psc->grade);
}


// open mode
// "r": read mode, 파일을 읽기위해 오픈한다, 파일이 없으면 에러
// "w": write mode, 파일을 저장하기위해 오픈한다. 파일을 항상 새파일로 만든다.
// "a": append mode, 파일을 저장하기위해 오픈, 기존 데이터에 추가로 저장하기 위해 오픈한다. 
//                   파일이 없으면 "w"모드와 동일하게 동작함

// "b": binary file을 읽고 쓰기 위함
// "t": text file을 읽고 쓰기 위함

void save_text(const char* filename)
{
    if (!filename)
        return;

    FILE* fp = NULL;    // 파일 핸들
    fp = fopen(filename, "wt");

    const char* sz1 = "Hello World\n";
    const char* sz2 = "Welcome to my house\n";
    const char* sz3 = "Good bye, see you\n";

    // element_size: 저장할 데이터의 단위 크기
    // element_count: 저장할 데이터의 개수    
    fwrite(sz1, sizeof(char), strlen(sz1), fp);
    fwrite(sz2, sizeof(char), strlen(sz2), fp);
    fwrite(sz3, sizeof(char), strlen(sz3), fp);

    fclose(fp);
}

long get_file_size(const char* filename)
{
    if (!filename)
        return 0;

    // cursor를 파일의 끝지점(EOF)으로 이동시킨다.
    // 커서의 위치를 알려달라고 한다. ===> 파일의 크기
    FILE* fp = NULL;    // 파일 핸들
    fp = fopen(filename, "r"); // 파일을 읽기모드로 연다
    if (!fp)
    {
        printf("파일을 오픈할 수 없습니다\n");
        return 0;
    }

    // offset: 이동시킬 거리
    // origin: 기준점, 여기서부터 offset만큼 이동함
    // SEEK_SET : BOF, Begin Of File, 파일의 시작점
    // SEEK_CUR : 현재 커서의 위치
    // SEEK_END : EOF, End Of File, 파일의 마지막 위치
    // fseek(fp, offset, origin);
    fseek(fp, 0, SEEK_END); // 파일의 마지막 지점부터 0만큼 이동 ==> 커서를 EOF지점으로 이동시킴
    
    // 여기에서 커서의 위치를 알려달라고 함
    long loc = ftell(fp);

    fclose(fp);

    return loc;
}


void load_text(const char* filename)
{
    if (!filename)
        return;

    long size = get_file_size(filename);
    if (!size)
        return;

    FILE* fp = NULL;    // 파일 핸들
    fp = fopen(filename, "rt"); // 파일을 읽기모드로 연다
    if (!fp)
    {
        printf("파일을 오픈할 수 없습니다\n");
        return;
    }

    // 파일의 크기를 구할 수 있어야 한다.
    // 그만큼의 메모리를 확보한다.
    // 확보된 메모리에 데이터를 읽는다.
    char* buf = (char*)malloc(size);
    if (!buf)
    {
        fclose(fp);
        return;
    }

    // 문자열 처리를 안정적으로 하기위 읽을 버퍼를 모두 0으로 채워둠
    memset(buf, 0, size);
        
    fread(buf, sizeof(char), size, fp);

    printf("%s\n", buf);

    fclose(fp);
    fp = NULL;

    if (buf)
    {
        free(buf);
        buf = NULL;
    }
}