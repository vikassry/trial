#include "CRevision.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int str_len(string str){
	int index = -1;
	while(str[++index] != 0);
	return index;
}

int fibo(int numberOfTerms, int *array){
	int i;
	for(i=0; i<numberOfTerms; i++){
		array[i] = (i<2) ? i : array[i-1] + array[i-2];
	}
	return (numberOfTerms<=0) ? 0 : 1;
}

int concat(int *array1, int len_of_array1, int *array2, int len_of_array2, int *result_array){
	int i,j,size;
	size = len_of_array1+len_of_array2;
	for (i = 0; i < len_of_array1; i++){
		result_array[i]=array1[i];
	}
	for (i = len_of_array1, j=0; i<size; i++,j++){
		result_array[i] = array2[j];
	}
	return (len_of_array1<=0 || len_of_array2<=0) ? 0 : 1;
};


int filter(int *array, int length, int threshold, int **result_array){
	int i, j=0 ,len=0;
	for(i=0; i<length; i++){
		(array[i] >= threshold) && len++;
	};
	*result_array = (int *)malloc(sizeof(int)*len);
	
	for(i=0; i<length; i++){
		if(array[i] >= threshold){
			(*result_array)[j] = array[i];
			j++;
		}
	}
	return (length<=0) ? 0 : len;
}

int reverse(int *array, int length){
	int i, temp, last = length-1;

	for(i=0; i<length/2; i++){
		temp = array[i];
		array[i]=array[last];
		array[last] = temp;
		last--;
	}
	return (length==0) ? 0 : 1;
}


int reverseNew(int *array, int length, int *result_array){
	int i, last = length-1;	
	for(i=0; i<length; i++){
		result_array[i]=array[last];
		last--;
	}
	return (length==0) ? 0 : 1;
}


int slice(int *array, int len_of_array, int start_index, int end_index, int **result){
	int i,j=0,result_len=0;
	for(i=start_index; i<end_index; i++){
		result_len++;
	}
	*result = (int *)malloc(sizeof(int)*result_len);
	
	for(i=start_index; i<end_index; i++){
		(*result)[j] = array[i];
		j++;
	}
	return result_len;
}

int primeNumbers(int start, int end, int **array){
	int i, half, prime=0;
	int j, prime_state;
	int *primes = (int *)0;

	primes = (int *)realloc(primes,sizeof(int));
	primes[prime] = 2;
	prime = prime +1;
	for(i=2; i<100; i++){
		if(i%2==1){
			prime_state=0;
			for(j=3; j< i/2; j++){
				(i%j == 0) && (prime_state=1);
			}
			if(prime_state==0){
				primes = (int *)realloc(primes,sizeof(int)*(prime+1));
				primes[prime] = i;  prime++;
			}
		}	
	}
	*array = primes;
	return prime;
}

int strCompare(char *arr1, char *arr2){
	int result=0,i;
	int len1 = strlen(arr1), len2 = strlen(arr2);
	int limit = (len1>len2) ? len1 : len2;

	for(i=0; i<limit; i++){
		if(arr1[i]!=arr2[i]){
			return arr1[i]-arr2[i];
		}
	}
	return 0;
}

int for_each(int x, int (*func)(int)){
	return func(x);
}

int makesqr(int x){
	return x*x*x;
}
int Increment(int a){
	return a+1;
}

int int_forEach(int *array, int length, int (*fun)(int x)){
	int i;
	for(i=0; i<length; i++){
		array[i] = (*fun)(array[i]);
	}
	return (length<=0) ? 0 : 1;
}

char upper_case(char ch){
	return ch - 32;
}
int char_forEach(char *array, int length, char(*fun)(char c)){
	int i;
	for(i=0; i<length; i++){
		array[i] = (*fun)(array[i]);
	}
	return (length<=0) ? 0 : 1;
}

int to_lower(char ch){
	return ch + 32;
}
void lower_case(string name){
	int i;
	for(i=0; i<str_len(name); i++){
		name[i] = name[i] +32;
	}
}

char give_firstChar(string name){
	return name[0];
}

int float_forEach(float *array, int length, float(*fun)(float x)){
	int i;
	for(i=0; i<length; i++){
		array[i] = (*fun)(array[i]);
	}
	return (length<=0) ? 0 : 1;
}
// int stringForEach(string *array, int length, char(*first)(string ch)){
// 	int i;
// 	for(i=0; i<length; i++){
// 		array[i] = first(array[i]);
// 	}
// 	return (length<=0) ? 0 : 1;
// }


int giveMultipleof5(int number){
	return (number%5==0) ? 1 : 0;
}
int int_filter(int *array, int length, int(*fun)(int num), int **filtered_array){
	int i, len=0;
	int  *filtered = (int *)0;
	for(i=0; i<length; i++){
		if((*fun)(array[i])){
			filtered = (int *)realloc(filtered,sizeof(int)*(len+1));
			filtered[len] = array[i]; len++;
		}
	}
	*filtered_array = filtered;
	return (length<=0) ? 0 : len;
}

int isCapital(char ch){
	return (ch<91 && ch>64) ? 1 : 0;
}
int char_filter(char *array, int length, int(*fun)(char ch), char **filtered_array){
	int i, len=0;
	char  *filtered = (char *)0;
	for(i=0; i<length; i++){
		if((*fun)(array[i])){
			filtered = (char *)realloc(filtered,sizeof(char)*(len+1));
			filtered[len] = array[i]; len++;
		}
	}
	*filtered_array = filtered;
	return (length<=0) ? 0 : len;
}

int isLargeString(string name){
	return (str_len(name)>3);
};

int string_filter(string *array, int length, int(*func)(string ch), string **result){
	int i, len=0;
	string *filtered = (string *)0;
	for(i=0; i<length; i++){
		if(func(array[i])){
			filtered = (string*)realloc(filtered, sizeof(string)*(i+1));
			filtered[len] = array[i]; len++;
		}
	}
	*result = filtered;
	return (length<=0) ? 0 : len;
};

int isSmallFloat(float num){
	return num < 10;
}
int float_filter(float *numbers, int length, int(predicate)(float n), float **result){
	int i=0, len=0;
	float *filtered = (float *)0;
	for(i=0; i<length; ++i){
		if(predicate(numbers[i])){
			filtered = (float *)realloc(filtered, sizeof(float)*(i+1));
			filtered[len] = numbers[i]; 
			len++;
		}
	}
	*result = filtered;
	return (length<=0) ? 0 : len;
}


int makeDouble(int num){
	return num * 2;
}

int *intMap(int *array, int length, calc multiply){
	int i, *result;
	result = (int *)malloc(sizeof(int)*length);
	for(i=0; i<length; i++){
		result[i] = multiply(array[i]);
	}
	return (length<=0) ? 0 : result;
}

int give_ascii(char ch){
	return ch;
}
int *charMap(char *array, int length, int(*ascii)(char ch)){
	int i, *result;
	result = (int *)malloc(length);
	for(i=0; i<length; i++){
		result[i] = ascii(array[i]);
	}
	return result;
}

int *stringMap(string *names, int length, int(*getLength)(string name)){
	int i, *result;
	result = (int*)malloc(sizeof(int)*length);
	for(i=0; i<length; i++){
		result[i] = getLength(names[i]);
	}  
	return result;
}

float increment(float value){
	return value + 1;
}
float *floatMap(float *numbers, int lenght, float(*inc)(float num)){
	int i;
	float *new_numbers = (float *)malloc(sizeof(float)*lenght);
	for(i=0; i<lenght; ++i){
		new_numbers[i] = inc(numbers[i]);
	}
	return new_numbers;
}

int indexOf(string text, string substr){
	int i, j, index=-1, status=0;
	for (i=0; i<str_len(substr); i++){
		for(j=0; j<str_len(text); j++){
			if(substr[i]==text[j]){
				status++; break;
			}
		}
	}
	if(status==str_len(substr)){
		for (i=0; i<str_len(text); ++i){
			(substr[0]==text[i]) && (index=i);
		}
	}
	return index;
}

int indexof(string text, char substr){
	int i, index=-1;
	for (i=0; i<str_len(text); ++i){
		(substr==text[i]) && (index=i);
	}
	return index;
}