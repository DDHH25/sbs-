#include <stdio.h>

// 배열을 매개변수로 받는 함수를 정의할때는 반드시
// 배열의 주소와 배열의 아이템들의 개수를 같이 넘겨주어야 한다!
void print_array(int arr[], size_t count)
{
    printf("arr의 주소: %p\n", arr);

    // printf("print_array함수에서 출력함: arr[5] = %d\n", arr[5]);
    for (int i = 0; i < count; i++)
    {
        printf("%d\t", arr[i]);
    }
}


void print_value(int n)
{
    printf("%d\n", n);
}

int main()
{
    int* p; // 8바이트
    char sz[100];

    int arr[100];   // 배열명은 주소 그 자체이다.
    printf("arr의 주소: %p\n", arr);
    printf("arr[0]의 주소: %p\n", &arr[0]);
    printf("arr[1]의 주소: %p\n", &arr[1]);

    int arr2[200];

    p = arr;
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < 200; i++)
    {
        arr2[i] = (i + 1)*2;
    }

    printf("arr[5] = %d\n", arr[5]);
    printf("p[5] = %d\n", p[5]);

    // 배열을 전달하는 함수를 호출
    print_array(arr, 100);
    printf("\n\n\n");
    print_array(arr2, 200);

    return 0;
}
