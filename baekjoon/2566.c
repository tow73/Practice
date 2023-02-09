#include <stdio.h>
int main(void)
{
	int num[9][9];
	int i, j, max = 0;
	int r=0;
	int c=0;

	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
			scanf("%d", &num[i][j]);

	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
			if(max < num[i][j]) {
				max = num[i][j];
				r = i;
				c = j;
			}
	
	printf("%d\n%d %d", max, r+1, c+1);

	return 0;
}
