#include <stdio.h>
#include "arrayutil.h"
#include <ctype.h>

int isEven(void* a){
	return (*((int*)a)%2==0) ? 1 : 0;
}
int areEqual(ArrayUtil arr1,ArrayUtil arr2) {
	int i;
	if(arr1.length == arr2.length && arr1.typeSize == arr2.typeSize) {
		
		for(i=0;i<arr1.length*arr1.typeSize;i++) {
			if(((char*)arr1.base)[i] != (((char*)arr2.base)[i])) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

ArrayUtil create(int typeSize,int length) {
	ArrayUtil arr;
	arr.length = length;
	arr.typeSize = typeSize;
	arr.base = calloc(length,typeSize);
	return arr;
}

ArrayUtil resize(ArrayUtil util,int length) {
	int i;
	ArrayUtil arr;
	if(util.length == length)return util;
	arr.length = length;
	arr.typeSize = util.typeSize;
	arr.base = calloc(length,util.typeSize);
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
	int i,res,tmp,count = 0;
	for(i=0;i<util.length*util.typeSize;(i+=util.typeSize)){
		res = (*f)(&((char*)util.base)[i],hint);
		if(res==1){
			count++;
		}
	}
	return (count==0) ? -1 : count;
}

