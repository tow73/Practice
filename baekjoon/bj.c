#include <stdio.h>
int main(void)
{
	int r, c, i, j;

	scanf("%d %d", &r, &c);
	int a[r][c];
	int b[r][c];

	for(i=0; i<r; i++)
		for(j=0; j<c; j++)
			scanf("%d", &a[i][j]);
    for(i=0; i<r; i++)
	    for(j=0; j<c; j++)
    	    scanf("%d", &b[i][j]);

	for(i=0; i<r; i++) {
		for(j=0; j<c; j++)
			printf("%d ", a[i][j]+b[i][j]);
		printf("\n");
	}

	return 0;
}