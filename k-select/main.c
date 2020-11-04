#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num = 1;

int K_SELECT(int A[], int k)
{
    srand(time(NULL));

    int size = 0;
    for (int i = 0; i < 8; i++)
    {
        if (A[i] >= 0 && A[i] <= 9)
            size++;
    }
    int L[8], R[8], left = 0, right = 0, pivot = A[rand() % size];

    for (int i = 0; i < size; i++)
    {
        if (A[i] < pivot)
            L[left++] = A[i];
        else if (A[i] > pivot)
            R[right++] = A[i];
    }

    printf("#%d pivot=%d Left = ", num++, pivot);
    if (left == 0)
        printf("[] ");
    for (int i = 0; i < left; i++)
        printf("%d ", L[i]);
    printf("Right = ");
    if (right == 0)
        printf("[] ");
    for (int i = 0; i < right; i++)
        printf("%d ", R[i]);

    if (left >= k)
    {
        printf("## go to left ## select k = %d\n", k);
        return K_SELECT(L, k);
    }

    else if (left + 1 == k)
    {
        printf("## return %d ##\n", pivot);
        return pivot;
    }

    else
    {
        printf("## go to right ## select k = %d\n", k - left - 1);
        return K_SELECT(R, k - left - 1);
    }
}

int main(void)
{
    srand(time(NULL));

    int A[8], k = rand() % 8 + 1;//k´Â 1~8

    for (int i = 0; i < 8; i++)
    {
        scanf_s("%d", &A[i]);
    }

    printf("input array = [ ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", A[i]);
    }
    printf("], k= %d\n", k);
    K_SELECT(A, k);


    return 0;
}