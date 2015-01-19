#include <stdio.h>
#include "arrayutil.h"

int areEqual(arrayutil arr1,arrayutil arr2) {
	int i;
	if(arr1.length == arr2.length && arr1.typeSize == arr2.typeSize) {
		for(i=0;i<arr1.length;i++) {
			if(((int*)arr1.base)[i] != ((int*)arr2.base)[i]) {
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
	((int*)arr.base) = calloc(length,typeSize);
	return arr;
}

arrayutil resize(arrayutil util,int length) {
	int i;
	arrayutil arr;
	if(util.length == length)return util;
	arr.length = length;
	arr.typeSize = util.typeSize;
	((int *)arr.base) = calloc(length,util.typeSize);
	for(i=0;i<length;i++) {
		((int *)arr.base)[i] = ((int *)util.base)[i];
	}
	return arr;
}

int findIndex(arrayutil util,void* element){
	int i;
	for(i=0;i<util.length;i++){
		if(((int*)util.base)[i] == ((int*)element))
			return i;
	}
	return -1;
}

void dispose(arrayutil util) {
	free(util.base);
	((void *)util.base) = calloc(0,0);
}

