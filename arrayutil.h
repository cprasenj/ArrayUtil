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
typedef struct utilArray arrayutil;

int areEqual(arrayutil,arrayutil);
arrayutil create(int typeSize,int length);
arrayutil resize(arrayutil,int);
int findIndex(arrayutil,void*);
void* findFirst(arrayutil,int (*f)(void*), void*);
int isEven(void*);
void* findLast(arrayutil,int (*f)(void*),void*);
int count(arrayutil,int (*f)(void*,void*), void*);
int filter(arrayutil, int (*f)(void*,void*), void*, void**, int);