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

int areEqual(ArrayUtil,ArrayUtil);
ArrayUtil create(int typeSize,int length);
ArrayUtil resize(ArrayUtil,int);
int findIndex(ArrayUtil,void*);
void* findFirst(ArrayUtil,int (*f)(void*), void*);
int isEven(void*);
void* findLast(ArrayUtil,int (*f)(void*),void*);
int count(ArrayUtil,int (*f)(void*,void*), void*);
int filter(ArrayUtil, int (*f)(void*,void*), void*, void**, int);