#include <stdio.h>
#include "arrayutil.h"
#include <ctype.h>

int isEven(void* a){
	return (*((int*)a)%2==0) ? 1 : 0;
}

int isDivisible(void* a,void *b){
	return (*((int*)a)%*((int*)b) == 0) ? 1 : 0;
}

int areEqual(ArrayUtil arr1,ArrayUtil arr2) {
	int i;
	char *util1,*util2;
	util1 = ((char*)arr1.base),util2 = ((char*)arr2.base);
	if(arr1.length != arr2.length || arr1.typeSize != arr2.typeSize)
		return 0;
		
	for(i=0;i<arr1.length*arr1.typeSize;i++) {
		if(util1[i] != util2[i]) {
			return 0;
		}
	}
	return 1;
}

ArrayUtil create(int typeSize,int length) {
	ArrayUtil arr = {calloc(length,typeSize),typeSize,length};
	return arr;
}

ArrayUtil resize(ArrayUtil util,int length) {
	int i;
	ArrayUtil arr = {calloc(length,util.typeSize),util.typeSize,length};
	if(util.length == length)return util;
	for(i=0;i<length*util.typeSize;i++) {
		((char *)arr.base)[i] = ((char *)util.base)[i];
	}
	return arr;
}

int findIndex(ArrayUtil util,void* element){
	int i,j,len = sizeof(element);
	for(i=0;i<util.length*util.typeSize;i++){
		if(len == sizeof(int)){
			if(((int*)util.base)[i] == *((int*)element))
				return i;	
		}
		if(len == sizeof(float)){
			if(((float*)util.base)[i] == *((float*)element))
				return i;	
		}
	}
	for(i=0;i<util.length*util.typeSize;i++){
		if(((char*)util.base)[i] == *((char*)element))
			return i;
	}
	return -1;
}

void dispose(ArrayUtil util) {
	void *a;
	free(util.base);
	util.length = 0;
	util.base = a;
}

void* findFirst(ArrayUtil util,int (*f)(void* a), void* hint) {
	int i,res,tmp;
	void* result;
	for(i=0;i<util.length*util.typeSize;(i+=util.typeSize)){
		res = (*f)(&((char*)util.base)[i]);
		if(res==1){
			tmp = ((char*)util.base)[i];
			result = &tmp;
			return result;
		}
	}
	return NULL;
}

void* findLast(ArrayUtil util,int (*f)(void* p), void* hint) {
	int i,res,tmp;
	void* result;
	for(i=util.length*util.typeSize-util.typeSize;i>0;(i-=util.typeSize)){
		res = (*f)(&((char*)util.base)[i]);
		if(res==1){
			tmp = ((char*)util.base)[i];
			result = &tmp;
			return result;
		}
	}
	return NULL;
}

int count(ArrayUtil util, int (*f)(void* a,void* b), void* hint){
	int i,res,tmp,count = 0;
	for(i=0;i<util.length*util.typeSize;(i+=util.typeSize)){
		res = (*f)(&((char*)util.base)[i],hint);
		if(res==1){
			count++;
		}
	}
	return (count==0) ? -1 : count;	
}

int filter(ArrayUtil util, int (*f)(void*,void*), void* hint, void** destination, int maxItems ){
	int i,res,tmp,count = 0,size = 0;
	*destination = malloc(maxItems*util.typeSize);
	for(i=0;i<util.length*util.typeSize;i++){
		res = (*f)(&((int*)util.base)[i],hint);
		if(res==1){
			((int *)(*destination))[size] = ((int*)util.base)[i];
			count++;
			size ++;
			if(count == maxItems) return count;
		}
	}
	return (count==0) ? -1 : count;
}

void intConvertFunc(void* hint, void* sourceItem, void* destinationItem){
	*((int *)destinationItem) = *((int *)hint) + *((int *)sourceItem);
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	int i,size = 0;
	for(i=0;i<source.length*source.typeSize;i++){
		convert(hint,&((int *)source.base)[i],&((int *)destination.base)[i]);
	}
}

void intAddOperation(void* hint, void* item) {
	*((int *)item) = *((int *)hint) + *((int *)item);	
}

void forEach(ArrayUtil util, OperationFunc* operation, void* hint) {
	int i;
	for(i=0;i<util.length*util.typeSize;i++){
		operation(hint,&((int *)util.base)[i]);
	}	
}

void* addReducerFunc(void* hint, void* previousItem, void* item){
	*((int*)item) = *((int*)hint) + *((int*)previousItem) + *((int*)item);
	return item; 
}

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue){
	int i;
	for(i=0;i<util.length;i++){
		intialValue =  reducer(hint,&((int *)util.base)[i],intialValue);
	}
	return intialValue;
}


