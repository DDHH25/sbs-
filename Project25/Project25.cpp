#include "Project25.h"


int main()
{
    SCORE sc;

    SCORE arr[10];

    //input_score(&sc);   // sc에 입력을 받아옴
    //print_score(&sc);   // sc에 있는 내용을 출력함

    save_text("test.txt");

    printf("%d\n", get_file_size("test.txt"));

    load_text("test.txt");

    return 0;
}

