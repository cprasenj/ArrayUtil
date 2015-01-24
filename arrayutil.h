#define INT_SIZE sizeof(int)
#define FLOAT_SIZE sizeof(float)
#define CHAR_SIZE sizeof(char)
#define STRING_SIZE sizeof(STRING)
#define DOUBLE_SIZE sizeof(double)


#define SIZEOF_INT sizeof(int)
#define SIZEOF_FLOAT sizeof(float)
#define SIZEOF_CHAR sizeof(char)
#define SIZEOF_DOUBLE sizeof(double)

;
// typedef char String[256];

struct utilArray {
	void *base;
	int typeSize;
	int length; 
};

struct rect {
	int length;
	int width;
};

typedef struct Student{
    int rollno;
    float age;
} student;



typedef int int10[10];
typedef float float5[5];
typedef struct Stud { char name[27]; int class; float percentage; } Student;
typedef void *void_star;
typedef char *char_star;
typedef int *int_star;
typedef float *float_star;
typedef char*  String;
// typedef char String[256];
typedef char* string;
typedef char* STRING;
typedef struct rect rectangle;
typedef struct utilArray ArrayUtil;
typedef	void (ConvertFunc)(void*,void*,void*);
typedef void (OperationFunc)(void*,void*);
typedef void* (ReducerFunc)(void*,void*,void*);
typedef int (MatchFunc)(void*,void*);


int areEqual(ArrayUtil,ArrayUtil);
ArrayUtil create(int typeSize,int length);
ArrayUtil resize(ArrayUtil,int);
int findIndex(ArrayUtil,void*);
void* findFirst(ArrayUtil, MatchFunc*, void*);
int isEven(void*);
void* findLast(ArrayUtil,MatchFunc*,void*);
int count(ArrayUtil,MatchFunc*, void*);
int filter(ArrayUtil, MatchFunc*, void*, void**, int);
int isDivisible(void*,void*);
void map(ArrayUtil,ArrayUtil,ConvertFunc*,void*);
void intConvertFunc(void*, void*, void*);
void dispose(ArrayUtil);
void forEach(ArrayUtil, OperationFunc*, void*);
void intAddOperation(void*,void*);
void* reduce(ArrayUtil, ReducerFunc*, void*,void*);
void* addReducerFunc(void*,void*,void*);
int isUpperCase(void*,void*);
int isLessthanFloat(void*,void*);
void charConvertFunc(void*,void*,void*);
void floatConvertFunc(void*,void*,void*);