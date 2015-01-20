#include <stdio.h>
#include "arrayutil.h"
#include <ctype.h>
int areEqual(arrayutil arr1,arrayutil arr2) {
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

arrayutil create(int typeSize,int length) {
	arrayutil arr;
	arr.length = length;
	arr.typeSize = typeSize;
	arr.base = calloc(length,typeSize);
	return arr;
}

arrayutil resize(arrayutil util,int length) {
	int i;
	arrayutil arr;
	if(util.length == length)return util;
	arr.length = length;
	arr.typeSize = util.typeSize;
	arr.base = calloc(length,util.typeSize);
	for(i=0;i<length*util.typeSize;i++) {
		((char *)arr.base)[i] = ((char *)util.base)[i];
	}
	return arr;
}

int findIndex(arrayutil util,void* element){
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

void dispose(arrayutil util) {
	void *a;
	free(util.base);
	util.length = 0;
	util.base = a;
}

