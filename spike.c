#include <stdio.h>
typedef int number;
typedef float measure;
typedef char * Text;
typedef int(*calc)(int, int);

int addition(int a, int b){
	return a+b;
}

int main(){
	Text name,gender;
	measure weight, height;
	number mark, result,r;
	calc add;
	
	weight= 65.9;
	gender="male";
	height = 172.45;
	mark=100;
	add = addition;
	result = add(1,3);
	printf("%f\n", weight);
	printf("result= %d", result);
	result = (gender[1]);
	printf(" %c\n", result);
	return 0;
}

