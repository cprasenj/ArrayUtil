struct utilArray {
	void *base;
	int typeSize;
	int length; 
};

struct rect {
	int length;
	int width;
};

typedef struct rect rectangle;
typedef struct utilArray ArrayUtil;
typedef	void (ConvertFunc)(void*,void*,void*);
typedef void (OperationFunc)(void*,void*);
typedef void* (ReducerFunc)(void*,void*,void*);

int areEqual(ArrayUtil,ArrayUtil);
ArrayUtil create(int typeSize,int length);
ArrayUtil resize(ArrayUtil,int);
int findIndex(ArrayUtil,void*);
void* findFirst(ArrayUtil,int (*f)(void*), void*);
int isEven(void*);
void* findLast(ArrayUtil,int (*f)(void*),void*);
int count(ArrayUtil,int (*f)(void*,void*), void*);
int filter(ArrayUtil, int (*f)(void*,void*), void*, void**, int);
int isDivisible(void*,void*);
void map(ArrayUtil,ArrayUtil,ConvertFunc*,void*);
void intConvertFunc(void*, void*, void*);
void dispose(ArrayUtil);
void forEach(ArrayUtil, OperationFunc*, void*);
void intAddOperation(void*,void*);
void* reduce(ArrayUtil, ReducerFunc*, void*,void*);
void* addReducerFunc(void*,void*,void*);