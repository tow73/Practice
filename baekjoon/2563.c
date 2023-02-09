#include <stdio.h>
int main(void)
{
	int paper[100][100] = {0};
	int num, i, j, l, x, y, sum = 0;

	scanf("%d", &num);
	for(i=0; i<num; i++) {
		scanf("%d %d", &x, &y);

		for(j=x; j<x+10; j++)
			for(l=y; l<y+10; l++)
				paper[j][l]++;
	}

	for(i=0; i<100; i++)
		for(j=0; j<100; j++)
			if(paper[i][j] != 0)
				sum++;

	printf("%d", sum);

	return 0;
}
