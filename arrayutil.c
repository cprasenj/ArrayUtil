#include <stdio.h>
#include "arrayutil.h"
#include <ctype.h>

void* addReducerFunc(void* hint, void* previousItem, void* item){
	*((int*)item) = *((int*)hint) + *((int*)previousItem) + *((int*)item);
	return item; 
}

void intConvertFunc(void* hint, void* sourceItem, void* destinationItem){
	*((int *)destinationItem) = *((int *)hint) + *((int *)sourceItem);
}

void charConvertFunc(void* hint, void* sourceItem, void* destinationItem){
	*((char*)destinationItem) = *((char*)sourceItem) - 32;
}

void floatConvertFunc(void* hint, void* sourceItem, void* destinationItem){
	*((float*)destinationItem) = *((float*)sourceItem) + *((float*)hint);
}

void intAddOperation(void* hint, void* item) {
	*((int *)item) = *((int *)hint) + *((int *)item);	
}

int isDivisible(void* a,void *b){
	return (*((int*)a)%*((int*)b) == 0) ? 1 : 0;
}

int isEven(void* a){
	return (*((int*)a)%2==0) ? 1 : 0;
}

int isUpperCase(void* a,void *b){
	return (*((char*)a) >= 'A' && *((char*)a) <= 'Z') ? 1 : 0;
}

int isLessthanFloat(void* a,void* b) {
	return (*((float*)a)<*((char*)b)) ? 1 : 0;	
}

int areEqual(ArrayUtil arr1,ArrayUtil arr2) {
	int i;
	char *util1,*util2;
	util1 = ((char*)arr1.base),util2 = ((char*)arr2.base);
	if(arr1.length != arr2.length || arr1.typeSize != arr2.typeSize)
		return 0;
	for(i=0;i<arr1.length*arr1.typeSize;i++) {
		if(util1[i] != util2[i])
			return 0;
	}
	return 1;
}

ArrayUtil create(int typeSize,int length) {
	ArrayUtil arr = {calloc(length,typeSize),typeSize,length};
	return arr;
}

ArrayUtil resize(ArrayUtil util,int length) {
	int i,len;
	ArrayUtil arr = {calloc(length,util.typeSize),util.typeSize,length};
	if(util.length == length)return util;
	len = (length<util.length) ? length : util.length;
	memcpy(arr.base,util.base,len*util.typeSize);
	return arr;
}

int findIndex(ArrayUtil util,void* element){//not working for double
	int i,j,len = sizeof(element);
	for(i=0;i<util.length*util.typeSize;i++){
		if(len == sizeof(int)){
			if(((int*)util.base)[i] == *((int*)element))
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
	util.base = NULL;
	free(util.base);
	util.length = 0;
	util.typeSize = 0;
}

void* findFirst(ArrayUtil util,MatchFunc* f, void* hint) {
	int i,res,c = 2;
	void* result;
	for(i=0;i<util.length*util.typeSize;(i+=util.typeSize)){
		res = f(&((char*)util.base)[i],hint);
		if(res==1){
			result = &((char*)util.base)[i];
			return result;
		}
	}
	return NULL;
}

void* findLast(ArrayUtil util,MatchFunc* f, void* hint) {
	int i,res;
	void* result;
	for(i=util.length*util.typeSize-util.typeSize;i>0;(i-=util.typeSize)){
		res = f(&((char*)util.base)[i],hint);
		if(res==1){
			result = &((char*)util.base)[i];
			return result;
		}
	}
	return NULL;
}

int count(ArrayUtil util, MatchFunc* f, void* hint){
	int i,res,count = 0;
	for(i=0;i<util.length*util.typeSize;(i+=util.typeSize)){
		res = f(&((char*)util.base)[i],hint);
		if(res==1){
			count++;
		}
	}
	return (count==0) ? -1 : count;	
}

int filter(ArrayUtil util, MatchFunc* f, void* hint, void** destination, int maxItems ){
	int i,res,count = 0;
	for(i=0;i<util.length*util.typeSize;i++){
		res = f(&(util.base)[i*util.typeSize],hint);
		if(res==1){
			((float*)(*destination))[count] = ((float*)util.base)[i];
			if(count == maxItems) return count;	
			count++;
		}
	}
	return (count==0) ? -1 : count;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	int i,size = 0;
	for(i=0;i<source.length*source.typeSize;i+=source.typeSize){
		convert(hint,&((char*)source.base)[i],&((char*)destination.base)[i]);
	}
}


void forEach(ArrayUtil util, OperationFunc* operation, void* hint) {
	int i;
	for(i=0;i<util.length*util.typeSize;i+=util.typeSize){
		operation(hint,&((char*)util.base)[i]);
	}	
}


void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue){
	int i;
	for(i=0;i<util.length*util.typeSize;i+=util.typeSize){
		intialValue =  reducer(hint,&((char*)util.base)[i],intialValue);
	}
	return intialValue;
}


