#include <stdio.h>
#include <stdlib.h>

int main() {
	int limit,num,i,count=0,isPrime;
	int  *primeList = (int *)0;

	scanf("%d",&limit);
	for(num=2;num<=limit;num++){
		isPrime = 1;
		for(i=0;(i<count) && ((primeList[i]-1)*(primeList[i]-1) < num);i++){
			if(num % primeList[i] == 0){
				isPrime=0;
				break;
			}
		}
		if(isPrime==1){
			count++;
			primeList = (int *)realloc(primeList,sizeof(int)*count);
			primeList[count-1] = num;
		}
	}
	printf("%d\n", count);
	return 0;
}