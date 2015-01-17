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
float addition(float,float);
int findMaximum(int,int);
char findmaxChar(char, char);

int str_len(string);
int fibo(int, int *);
int concat(int *, int, int *, int, int *);
int filter(int *, int, int, int **);
int reverse(int *, int);
int reverseNew(int *, int, int *);
int isPrime(int);
int isLargeString(string);
int isSmallFloat(float);
string findSmallest(string, string);

void Slice(string, int, int, int );
int slice(int *, int, int, int, int **);
int primeNumbers(int, int, int **);
int strCompare(char *, char *);
int for_each(int, int(*)(int));

int int_forEach(int *, int, int(*)(int));
int char_forEach(char *, int, char(*)(char));
int float_forEach(float *, int, float(*)(float));
int string_forEach(string *, int, string(*)(string,int,int,int));

int int_filter(int *, int, int(*)(int), int **);
int char_filter(char *, int, int(*)(char), char **);
int string_filter(string *, int, int(*)(char *), string **);
int float_filter(float *, int, int(*)(float), float**);

int *int_map(int *, int, calc);
int *char_map(char *, int, int(*)(char));
int *string_map(string *, int, int(*)(string));
float *float_map(float *, int, float(*)(float));

int int_reduce(int *, int, int(*)(int,int),int);
float float_reduce(float *, int, float(*)(float,float),float);
char char_reduce(char *, int, char(*)(char,char),char);
string string_reduce(string*, int, string(*)(string,string),string);

int indexOf(string,string);
int indexof(string,char);
