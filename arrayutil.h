struct utilArray {
	void *base;
	int typeSize;
	int length; 
};

typedef struct utilArray arrayutil;

int areEqual(arrayutil,arrayutil);
arrayutil create(int typeSize,int length);
arrayutil resize(arrayutil,int);
int findIndex(arrayutil,void*);