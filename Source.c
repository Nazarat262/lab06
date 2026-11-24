#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


///task919

int task919() {
	int a[10][10];
	int m, n, i, j, tmp;
	printf("Input n, m\n");
	scanf("%d %d", & n, &m);
	if (n < 1 || n>10 || m < 1 || m>10) {
		printf("wrong n, m\n");
		return 0;
	}
	printf("Input matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d", &a[i][j]);

	for (i = 0; i < n / 2; i++) {
		for (j = 0; j < m; j++) {
			tmp = a[i][j];
			a[i][j] = a[n - 1 - i][j];
			a[n - 1 - i][j] = tmp;
		}
	}
	printf("Result:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}

///task924

int task924() {
	int a[2][2];
	int m, n, i, j, min, max_i, max_j, max, k;
	printf("Input n, m\n");
	scanf("%d %d", &n, &m);
	if (n < 1 || n>2 || m < 1 || m>2) {
		printf("wrong n, m\n");
		return 0;
	}
	printf("Input matrix\n");
	for (i = 0;i < n;i++)

		for (j = 0;j < m;j++)
			scanf("%d", &a[i][j]);

	for (j = 0;j < m;j++) {
		min = a[0][j];
		k = 0;

		for (i = 1;i < n;i++)
			if (a[i][j] < min) {
				min = a[i][j];
				k = i;
			}
	
	if (j == 0 || min > max) {
		max = min;
		max_i = k;
		max_j = j;
	}
}
	printf("Max element: %d\n", max);
	printf("Row: %d\n", max_i + 1);
	printf("Column: %d\n", max_j + 1);
	return 0;
}

///task968
int task968() {
	int a[20][10];
		int i, j, n, m;
		srand(time(NULL));

		for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			a[i][j] = rand() % 12 + 1;
			}
		}
		int sum = 0;
		int row = 4; 

		for (j = 0; j < 10; j++) {
			sum += a[row][j];
		}

		float average = (float)sum / 10;

		printf("Average: %.2f\n", average);
		 
		return 0;
}

int task1001() {
	int a[10][10], v[55];
	int n, i, j, k, cnt;
	printf("Input n:\n");
	scanf("%d", &n);
	if (n < 1 || n > 10) {
		printf("n must be from 1 to 10\n");
		return 0;
	}

	cnt = n * (n + 1) / 2;
	printf("Input %d numbers:\n", cnt);
	for (i = 0; i < cnt; i++)
		scanf("%d", &v[i]);

	k = 0;
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			a[i][j] = v[k];
			a[j][i] = v[k];
			k++;
		}
	}

	printf("Matrix:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

	return 0;
}




int task1015() {
	double a[10][10], s;
	int n, i, p, q, ok = 1;
	printf("Input n:\n");
	scanf("%d", &n);
	if (n < 1 || n > 10) {
		printf("n must be from 1 to 10\n");
		return 0;
	}

	printf("Input matrix:\n");
	for (i = 0; i < n; i++)
		for (q = 0; q < n; q++)
			scanf("%lf", &a[i][q]);

	
	for (p = 0; p < n; p++) {
		for (q = p + 1; q < n; q++) {
			s = 0;
			for (i = 0; i < n; i++)
				s += a[p][i] * a[q][i];
			if (fabs(s) > 1e-9)
				ok = 0;
		}
	}

	
	for (p = 0; p < n; p++) {
		for (q = p + 1; q < n; q++) {
			s = 0;
			for (i = 0; i < n; i++)
				s += a[i][p] * a[i][q];
			if (fabs(s) > 1e-9)
				ok = 0;
		}
	}

	if (ok)
		printf("Matrix is orthogonal\n");
	else
		printf("Matrix is NOT orthogonal\n");

	return 0;
}




int main() {
	task919();
	task924();
	task968();
	task1001();
	task1015();
	return 0;
}