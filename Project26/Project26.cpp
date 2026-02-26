
#include "Project26.h"

int main()
{
    // 메인 데이터들이 저장될 배열 -> 
    SCORE* scores = NULL;   // 동적인 배열
    size_t count = 0;       // 배열의 현재 아이템들의 개수

    count = load_score(&scores);

    char menu;
    do {
        show_menu();
        menu = select_menu();
        switch (menu)
        {
        case '1':   // 점수 입력
            count = input_score(&scores, count);
            save_score(scores, count);
            print_scores(scores, count);
            break;

        case '2':   // 점수 출력
            print_scores(scores, count);
            break;

        case '3':   // 점수 수정
            select_update(scores, count);
            save_score(scores, count);
            print_scores(scores, count);
            break;

        case '4':   // 점수 삭제
            count = remove_score(&scores, count);
            save_score(scores, count);
            print_scores(scores, count);
            break;


        case 'x':
            printf("프로그램을 종료합니다!\n");
        }

        // 잠깐 멈추기...
        if (menu != 'x') wait();

    } while (menu != 'x');

    // Heap에 할당된 메모리 삭제하기
    if (scores)
    {
        free(scores);
        scores = NULL;
    }

    return 0;
}
