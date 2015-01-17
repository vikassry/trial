typedef int(*calc)(int);
typedef char *string;

int makeDouble(int);
int give_ascii(char);
int isCapital(char);
char upper_case(char ch);
int to_lower(char ch);
void lower_case(string);
int makesqr(int x);
int Increment(int a);
int giveMultipleof5(int number);
char give_firstChar(string);
float increment(float);

int str_len(string);
int fibo(int, int *);
int concat(int *, int, int *, int, int *);
int filter(int *, int, int, int **);
int reverse(int *, int);
int reverseNew(int *, int, int *);
int isPrime(int);
int isLargeString(string);
int isSmallFloat(float);

int slice(int *, int, int, int, int **);
int primeNumbers(int, int, int **);
int strCompare(char *, char *);
int for_each(int, int(*)(int));

int int_forEach(int *, int, int(*)(int));
int char_forEach(char *, int, char(*)(char));
int string_forEach(string *, int, char(*)(string));
int float_forEach(float *, int, float(*)(float));

int int_filter(int *, int, int(*)(int), int **);
int char_filter(char *, int, int(*)(char), char **);
int string_filter(string *, int, int(*)(char *), string **);
int float_filter(float *, int, int(*)(float), float**);

int *intMap(int *, int, calc);
int *charMap(char *, int, int(*)(char));
int *stringMap(string *, int, int(*)(string));
float *floatMap(float *, int, float(*)(float));

int indexof(string,char);
int indexOf(string,string);