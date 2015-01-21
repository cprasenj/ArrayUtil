struct utilArray {
	void *base;
	int typeSize;
	int length; 
};

struct rect {
	int length;
	int width;
};

typedef char* string;
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