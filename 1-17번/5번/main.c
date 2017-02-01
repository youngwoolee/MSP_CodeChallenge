#include <stdio.h>
#include <stdlib.h>

void main()
{
	int n;			// User Choice Number
	int i, j;		// 제어 변수
	int H, W;		// H : Height	W : Width  
	int value = 1;	// 배열 원소 값
	int ** nXn_array;	// 2차원 배열

	printf("Please enter any value for nXn array : ");
	scanf_s("%d", &n, 4);

	/* Dynamic Allocation */
	nXn_array = (int**)malloc(n*sizeof(int));
	for (i = 0; i<n; i++)
		nXn_array[i] = (int *)malloc(n*sizeof(int));

	/* Array Initialize */
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++)
		nXn_array[i][j] = 0;

	H = W = 0;
	/* Snail Array Algorithm : Loop( → ↓ ← ↑ )  */
	for (i = 0; n>0; i++)
	{
		/* → */
		while (1){ // Width++
			nXn_array[H][W++] = value++;
			if (W >= n - i)
				break;
		}
		W--; H++;

		/* Break 'For' */
		if (n % 2 == 1 && nXn_array[H][W] != 0)
			break;

		/* ↓ */
		while (1){ // Height++
			nXn_array[H++][W] = value++;
			if (H >= n - i)
				break;
		}
		H--; W--;

		/* ← */
		while (1){ // Width--
			nXn_array[H][W--] = value++;
			if (W <= i - 1)
				break;
		}
		W++; H--;

		/* Break 'For' */
		if (n % 2 == 0 && nXn_array[H][W] != 0)
			break;

		/* ↑ */
		while (1) { // Height--
			nXn_array[H--][W] = value++;
			if (H <= i)
				break;
		}
		H++; W++;
	}

	/* Print Array */
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
			printf("%4d", nXn_array[i][j]);
		printf("\n");
	}

	/* Free Allocation */
	for (i = 0; i<n; i++)
		free(nXn_array[i]);
	free(nXn_array);

	fflush(stdin);
	getchar();
}
