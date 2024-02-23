#include <stdio.h>
#include <string.h>

int main() {
	int n, i, j, score, plus;
	char z[81];
	scanf("%d", &n);
	
	for( i = 0; i < n; i++ ) {
		score = 0;
		plus = 1;
		scanf("%s", z);
		
		for ( j = 0; j < strlen(z); j++ ) {
			if ( z[j] == 'O' ) {
				score += plus;
				plus++;
			}
			else plus = 1;
		}
		printf("%d\n", score);
	}
	
	return 0;
}
