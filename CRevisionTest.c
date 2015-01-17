#include "expr_assert.h"
#include "CRevision.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void test_fibonacci_returns_1_for_1(){
	int *array;
	array= (int *)malloc(sizeof(int));
	assertEqual(fibo(1,array),1);
	// printf("%p\n", *array);
	// printf("%p\n", array[0]);
	assert(array[0]==0);
	assert(array[1]!=1);
	free(array);
}
void test_fibonacci_returns_0_for_0(){
	int *array;
	array= (int *)malloc(sizeof(int));
	assertEqual(fibo(0,array),0);
	free(array);
}
void test_fibonacci_returns_3_for_5(){
	int *array;
	array= (int *)malloc(sizeof(int)*5);
	assertEqual(fibo(5,array),1);
	assert(array[0]==0);
	assert(array[1]==1);
	assert(array[2]==1);
	assert(array[3]==2);
	assert(array[4]==3);
	free(array);
}
void test_fibonacci_returns_0_for_negative_number(){
	int *array;
	array= (int *)malloc(sizeof(int));
	assertEqual(fibo(-3,array),0);
	free(array);
}
void test_fibonacci_works_for_decimal(){
	int *array;
	array= (int *)malloc(sizeof(int)*5);
	assertEqual(fibo(4,array),1);
	assert(array[0]==0);
	assert(array[1]==1);
	assert(array[2]==1);
	assert(array[3]==2);
	free(array);
}

void test_concat_concats_two_arrays_with_length_also(){
	int arr1[]={1,2,3};
	int arr2[]={3,4,5,6,8};
	int *arr3;
	arr3 = (int *)malloc(sizeof(int)*8);
	assertEqual(concat(arr1,3,arr2,5,arr3),1);
	free(arr3);
}
void test_concat_concats_two_arrays_with_elements(){
	int arr1[]={1,2,3};
	int arr2[]={3,4,5,6,8};
	int *arr3;
	arr3 = (int *)malloc(sizeof(int)*8);
	concat(arr1,3,arr2,5,arr3);
	assert(arr3[2]==3);
	assert(arr3[3]==3);
	assert(arr3[7]==8);
	free(arr3);
}
void test_concat_concats_gives_0_for_empty_array(){
	int arr1[0];
	int arr2[]={3,4,5,6,8};
	int *arr3;
	arr3 = (int *)malloc(sizeof(int)*8);
	assert(concat(arr1,0,arr2,5,arr3)==0);
	free(arr3);
}

void test_filter_filters_the_array(){
	int scores[3]={100,90,80};
	int *filtered_array;
	assertEqual(filter(scores,3,85,&filtered_array), 2);
	assert(filtered_array[0]==100);
	assert(filtered_array[1]==90);
	free(filtered_array);
}
void test_filters_the_array_(){
	int scores[5]={100,30,45,80,46};
	int *filtered_array;
	assertEqual(filter(scores,5,45,&filtered_array), 4);
	assert(filtered_array[0]==100);
	assert(filtered_array[1]==45);
	assert(filtered_array[2]==80);
	assert(filtered_array[3]==46);
	free(filtered_array);
}

void test_reverse_the_array_itself(){
	int array[4];
	array[0] = 1; array[1] = 2;
	array[2] = 3; array[3] = 4;
	assert(reverse(array,4)==1);
	assert(array[0]==4);
	assert(array[1]==3);
	assert(array[2]==2);
	assert(array[3]==1);
}

void test_reverses_array_to_new_array(){
	int *array;
	int reverse[4];
	array = (int *)malloc(sizeof(int)*4);
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	assert(reverseNew(array,4,reverse)==1);
	assert(reverse[0]==4);
	assert(reverse[1]==3);
	assert(reverse[2]==2);
	assert(reverse[3]==1);
	free(array);
}

void test_slice_gives_portion_of_array(){
	int numbers[] = {5,6,7,8,9,0};
	int *result;
	assertEqual(slice(numbers,6,1,5, &result), 4);
	assert(result[0]==6);
	assert(result[1]==7);
	assert(result[2]==8);
	assert(result[3]==9);
	free(result);
}


void test_slice_doesnt_modifies_array(){
	int numbers[] = {5,6,7,8,0};
	int *result;
	assertEqual(slice(numbers,5,1,3, &result), 2);
	assert(numbers[0]==5);
	assert(numbers[1]==6);
	assert(numbers[2]==7);
	assert(numbers[3]==8);
	assert(numbers[4]==0);
	free(result);
}

void test_primeNumber_gives_number_of_prime_numbers_in_given_range(){
	int *primes;
	assertEqual(primeNumbers(1,100,&primes), 25);
	free(primes);
}
void test_primeNumber_gives_array_of_prime_numbers_in_given_range(){
	int *primes;
	primeNumbers(1,100,&primes);
	assert(primes[0]==2);
	assert(primes[1]==3);
	assert(primes[24]==97);
	free(primes);
}

void test_strCompare_gives_0_for_same_strings(){
	assertEqual(strCompare("vikas","vikas"),0);
}
void test_strCompare_gives_negative_2_of_char_for_different_strings_of_same_length(){
	char str1[] = {'v','i','k','a','s','\0'};
	char str2[] = {'v','i','k','c','u','\0'};
	assert(strCompare(str1,str2)==-2);
}
void test_strCompare_gives_5_of_char_for_different_strings_of_same_length(){
	char str1[] = {'v','i','k','f','t','\0'};
	char str2[] = {'v','i','k','a','s','\0'};
	assert(strCompare(str1,str2)==5);
}
void test_strCompare_gives_97_for_char_for_strings_of_different_length(){
	char str1[] = {'v','i','k','a','s','\0'};
	char str2[] = {'v','i','k','\0'};
	assert(strCompare(str1,str2)==strcmp(str1,str2));
}
void test_strCompare_gives_10_for_different_chars_if_first_string_has_more_length(){
	char str1[] = {'v','i','k','a','\0'};
	char str2[] = {'v','i','a','\0'};
	char str3[] = {'a','b','c','d','\0'};
	char str4[] = {'a','t','c','\0'};
	assert(strCompare(str1,str2)==strcmp(str1,str2));
	assert(strCompare(str3,str4)==strcmp(str3,str4));
}
void test_strCompare_gives_negative_99_for_different_chars_if_second_string_has_more_length(){
	char str1[] = {'a','b','\0'};
	char str2[] = {'a','b','c','\0'};
	char str3[] = {'a','s','\0'};
	char str4[] = {'a','b','c','d','\0'};
	assert(strCompare(str1,str2)==-99);
	assert(strCompare(str3,str4)==17);
};
void test_strCompare_gives_difference_for_space_in_string(){
	char *str1 = "viAas";
	char *str2 = "vi as";
	char *str3 = "vi as";
	char *str4 = "vi as";
	assertEqual(strCompare(str1,str2),33);
	assertEqual(strCompare(str3,str4),0);
}
void test_strCompare_gives_difference_for_special_character(){
	assertEqual(strCompare("a ","a&"),-6);
	assert(strCompare("z","!")==89);
}
	
void test_for_each_gives_4_for_3_(){
	int (*increment)(int) = Increment;
	int (*sqr)(int) = makesqr;
	assertEqual(for_each(3,increment), 4);
	assertEqual(for_each(3,sqr),27);
}

void test_when_makesqr_is_passed_to_for_each_gives_square_of_array_elements(){
	int array[] = {1,2,3,4,5};
	int (*fun)(int) = &makesqr;
	assertEqual(int_forEach(array,5,fun), 1);
	assert(array[0]==1);
	assert(array[1]==8);
}
void test_forEach_gives_0_for_empty_array_otherwise_1(){
	int array[0];
	int array2[1];
	int (*fun)(int) = &makesqr;
	assertEqual(int_forEach(array, 0, fun),0);
	assertEqual(int_forEach(array2, 1, fun),1);
}

void test_upper_case_gives_UPPERCASE_of_given_char(){
	assert(upper_case('z')=='Z');
}
void test_char_forEach_converts_to_upper_case_(){
	char array[] = {'a','b','c','\0'};
	char (*upper)(char) = upper_case;
	assertEqual(char_forEach(array,3,upper),1);
	assertEqual(array[0],'A');
	assertEqual(array[1],'B');
	assertEqual(array[2],'C');
}

void test_float_forEach_increments_each_element(){
	float numbers[] = {3.5, 6.75, 2.25, 10.00};
	float(*inc)(float) = &increment;
	assertEqual(float_forEach(numbers, 4, inc),1);
	assert(numbers[0]==4.5);
}
// void test_string__forEach_converts_string_array_to_lower_case(){
// 	string names[] = {"VIKAS","JEEVAN","SURYAVANSHI",'\0'};
// 	char(*first)(string) = &give_firstChar;
// 	assertEqual(string_forEach(names, 3, first), 1);
// 	assert(names[0]=='V');
// 	assert(names[1]=='J');
// 	assert(names[2]=='S');
// }

void test_Filter_gives_0_for_empty_array_or_negative_length(){
	int numbers[0];
	int *filtered_terms;
	assertEqual(int_filter(numbers,-1,giveMultipleof5,&filtered_terms),0);
}
void test_Filter_doesnt_change_original_array(){
	int numbers[] = {4,5,90,35,43,67};
	int *filtered_terms;
	assertEqual(int_filter(numbers,6,giveMultipleof5,&filtered_terms),3);
	assertEqual(filtered_terms[0],5);
	assert(numbers[0]==4)	;
	free(filtered_terms);
}
void test_giveMultiplesof5_gives_1_for_multiples_of_5(){
	assertEqual(giveMultipleof5(25),1);
	assertEqual(giveMultipleof5(24),0);
}
void test_int_Filter_gives_multiples_of_5(){
	int numbers[] = {4,5,90,35,43,67};
	int *filtered_terms;
	assertEqual(int_filter(numbers,6,giveMultipleof5,&filtered_terms),3);
	assertEqual(filtered_terms[0],5);
	assert(filtered_terms[1]==90);	
	assert(filtered_terms[2]==35);
	assert(numbers[0]==4)	;
	free(filtered_terms);
}

void test_str_len_returns_5_for_vikas(){
	assertEqual(str_len("vikas"), 5);
	assertEqual(str_len("*~#_"), 4);
}

void test_isCapital_gives_1_for_capital_letter(){
	assert(isCapital('Q')==1);
	assert(isCapital('Z')==1);
	assert(isCapital('s')==0);
}
void test_charFilter_gives_filters_the_capital_letters(){
	char word[] = {'a','B','c','D','F','h','u','j','H','y','\0'};
	char *capitals;
	assertEqual(char_filter(word,10,isCapital,&capitals),4);
	assertEqual(capitals[0],'B');
	assertEqual(capitals[1],'D');
	assertEqual(capitals[2],'F');
	assert(capitals[3]=='H');
	assert(word[0]=='a');
}

void test_isLargeString_gives_1_for_vikas(){
	assertEqual(isLargeString("vikas"),1);
	assertEqual(isLargeString("vik"),0);
}

void test_stringFilter_returns_string_that_greater_than_3(){
	string words[] = {"hii","vikas","suryavanshi","foo","five"};
	int(*function)(string) = &isLargeString;
	string *filtered;
	int Filtered_number = string_filter(words,5,function,&filtered);
	assertEqual(Filtered_number, 3);
	assert(filtered[0]=="vikas");
	assert(filtered[1]=="suryavanshi");
	assert(filtered[2]=="five");
}

void test_isSmallFloat_gives_1_for_9_(){
	assert(isSmallFloat(9.9)==1);
	assert(isSmallFloat(11.8)==0);
}
void  test_float_Filter_gives_numbers_less_than_10(){
	float numbers[] = {1.5,8.25,1.75,90.0,45.5};
	float *filtered_number;
	assertEqual(float_filter(numbers, 5, isSmallFloat, &filtered_number),3);
	assert(filtered_number[0]==1.5);
	assert(filtered_number[1]==8.25);
	assert(filtered_number[2]==1.75);
}

void test_intMap_gives_double_of_each_elements_of_array(){
	int *result;
	calc Double;
	int numbers[] = {1,2,3,4};
	int expected[]= {2,4,6,8};
	Double = &makeDouble;
	result = intMap(numbers,4,Double);
	assertEqual(result[0], expected[0]);
	assertEqual(result[1], expected[1]);
	assertEqual(result[2], expected[2]);
	assertEqual(result[3], expected[3]);
}
void test_intMap_doesnot_changes_the_original_array(){
	int numbers[] = {1,2,3,4};
	assert(numbers[0]==1);
	assert(numbers[3]==4);
}

void test_charMap_gives_ascii_value_of_characters(){
	char characters[] = {'a','b','A','\0'};
	int (*ascii)(char) = give_ascii;
	int *result = charMap(characters, 3, ascii);
	assertEqual(result[0], 97);
	assertEqual(result[1], 98);
	assertEqual(result[2], 65);
	assertEqual(characters[0],'a');
}

int give_great_strings(char *str){
	return (strlen(str)>3) ? 1 : 0;
}
void test_stringMap_gives_strings_length_of_evry_string(){
	string name[] = {"vikas","jeevan","suryavanshi","\0"};
	int(*getLength)(char *) = str_len;
	int *result = stringMap(name,3,getLength);
	assertEqual(result[0],5);
	assertEqual(result[1],6);
	assertEqual(result[2],11);
	assert(name[0]=="vikas");
}

void test_float_increment(){
	assert(increment(4.5)==5.5);
	assert(increment(4.25)==5.25);
}
void test_float_Map_increments_float_values_(){
	float numbers[]={1.25,5.5,6.75};
	float(*function)(float) = &increment;
	float *result = floatMap(numbers, 3, function);
	assert(result[0]==2.25);
	assert(result[1]==6.5);
	assert(result[2]==7.75);
}

void test_indexOf_gives_index_only_when_substring_is_present_in_exact_sequence_of_substrings_characters_in_main_string(){
	string name="vikas";
	assertEqual(indexOf(name, "vik"), 0);
	assertEqual(indexOf(name, "ika"), 1);
	assertEqual(indexOf(name, "s"), 4);
}

void test_indexOf_gives_minus_1_when_substrings_characters_are_present_but_not_in_substrings_chars_sequence(){
	string name="vikas";
	assertEqual(indexOf(name, "via"), -1);
	assertEqual(indexOf(name, "isa"), -1);
	assertEqual(indexOf(name, "si"), -1);
}

void test_indexOf_gives_minus_1_for_h_in_vikas(){
	string name="vikas";
	assertEqual(indexOf(name, "h"), -1);
}

void test_indexof_gives_2_for_k_in_vikas(){
	string name="vikas";
	assertEqual(indexof(name, 'k'), 2);
	assertEqual(indexof(name, 's'), 4);
	assertEqual(indexof(name, 'j'), -1);
}


		// int array[] = {1,2};
		// int *a =array;
		// a=&array
		// myfn(array);

// char *array[2] = {"ananthu","dolly"};
// void test_isPrime_gives_0_for_negative_numbers() {
// 	int expected;
// 	expected = isPrime(-3);
// 	assertEqual(expected,0);
// }
