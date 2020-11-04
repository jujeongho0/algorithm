#include <stdio.h>

void mergeSort(int num[], int start, int end);
void merge(int num[], int start, int pivot, int end);

int main(void)
{
	int num[8];
	for (int a = 0; a < 8; a++)
	{
		scanf_s("%d", &num[a]);
	}

	printf("-----------------\n");
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");

	mergeSort(num, 0, 1);
	mergeSort(num, 2, 3);
	mergeSort(num, 4, 5);
	mergeSort(num, 6, 7);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");

	mergeSort(num, 0, 3);
	mergeSort(num, 4, 7);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");

	mergeSort(num, 0, 7);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n-----------------");
	return 0;
}

void mergeSort(int num[], int start, int end)
{
	int pivot;
	if (start < end)
	{
		pivot = (start + end) / 2;
		mergeSort(num, start, pivot);
		mergeSort(num, pivot + 1, end);
		merge(num, start, pivot, end);		
	}
}

void merge(int num[], int start, int pivot, int end)
{
	int i = start, j = pivot + 1, k = start;
	int temp[8];
	while (i <= pivot && j <= end)
	{
		if (num[i] <= num[j])
		{
			temp[k] = num[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = num[j];
			k++;
			j++;
		}
	}
	while (i <= pivot)
	{
		temp[k] = num[i];
		k++;
		i++;
	}
	while (j <= end)
	{
		temp[k] = num[j];
		k++;
		j++;
	}
	for (int z = start; z <= end; z++)
		num[z] = temp[z];
}