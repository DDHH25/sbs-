
#include <stdio.h>

int main()
{
    // 다차원 배열
    int dim[2][3];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dim[i][j] = (i*3)+j+1;
        }
    }

    return 0;
}
