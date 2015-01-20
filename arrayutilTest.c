#include "expr_assert.h"
#include "arrayutil.h"
#include <stdlib.h>

void test_areEqual_returns_0_if_array_lengths_are_different() {
	int expected = 0,actual;
	arrayutil a,b;
	a.length = 5;
	b.length = 6;
	actual = areEqual(a,b);
	assertEqual(expected,actual);
}

void test_areEqual_returns_1_if_array_lengths_are_same_and_values_are_same() {
	int *arr1,*arr2;
	arrayutil a,b;
	int expected = 1,actual;
	a.length = 1;
	a.typeSize = sizeof(int);
	b.length = 1;
	b.typeSize = sizeof(int);
	arr1 = (int *)malloc(sizeof(int)*a.length);
	arr1[0] = 7;
	a.base = arr1;
	arr2 = (int *)malloc(sizeof(int)*b.length);
	arr2[0] = 7;
	b.base = arr2;
	actual = areEqual(a,b);
	assertEqual(expected,actual);
}
	
void test_areEqual_returns_0_if_array_lengths_are_same_and_values_are_different() {
	int *arr1,*arr2;
	arrayutil a,b;
	int expected = 0,actual;
	a.length = 1;
	a.typeSize = sizeof(int);
	b.length = 1;
	b.typeSize = sizeof(int);
	arr1 = (int *)malloc(sizeof(int)*a.length);
	arr1[0] = 9;
	a.base = arr1;
	arr2 = (int *)malloc(sizeof(int)*b.length);
	arr2[0] = 7;
	b.base = arr2;
	actual = areEqual(a,b);
	assertEqual(expected,actual);
}

void test_isEqual_returns_1_if_array_lengths_are_same_and_values_are_same_for_char() {
	char *arr1,*arr2;
	arrayutil a,b;
	int expected = 0,actual;
	a.length = 1;
	a.typeSize = sizeof(int);
	b.length = 1;
	b.typeSize = sizeof(int);
	arr1 = (char *)malloc(sizeof(char)*a.length);
	arr1[0] = 'a';
	a.base = arr1;
	arr2 = (char *)malloc(sizeof(char)*b.length);
	arr2[0] = 'a';
	b.base = arr2;
	actual = areEqual(a,b);
	assertEqual(expected,actual);
}

void test_creates_returns_1_if_array_lengths_are_same_and_values_are_same() {
	arrayutil a,b;
	int expected = 1,actual;
	a = create(sizeof(int),2);
	b = create(sizeof(int),2);
	assert(areEqual(a,b) == 1);
	assert(((int*)a.base)[0]==0);
}

void test_resize_returns_1_if_array_lengths_are_same_and_values_are_same() {
	arrayutil a,b;
	int expected = 1,actual;
	a.length = 5;
	a.typeSize = sizeof(int);
	a = create(a.typeSize,a.length);
	((int*)a.base)[0] = 1;
	((int*)a.base)[1] = 2;
	b = resize(a,4);
	assert(b.length == 4);
	assert(((int*)b.base)[0] == 1);
}

void test_indexof_returns_negative_1_if_element_if_element_not_found(){
	arrayutil a;
	int b,x;
	int expected = 1,actual;
	a = create(sizeof(int),5);
	a.typeSize = sizeof(int);
	((int*)a.base)[0] = 1;
	((int*)a.base)[1] = 2;
	x = 4;
	b = findIndex(a,&x);
	assertEqual(b, -1);	
}

void test_indexof_returns_0_if_element_if_element_is_in_0_position(){
	arrayutil a;
	int b,x;
	int expected = 1,actual;
	a = create(sizeof(int),5);
	((int*)a.base)[0] = 1;
	((int*)a.base)[1] = 2;
	((int*)a.base)[2] = 420;
	x = 1;
	b = findIndex(a,&x);
	assertEqual(b, 0);
	x = 2;
	b = findIndex(a,&x);
	assertEqual(b, 1);	
	x = 420;
	b = findIndex(a,&x);
	assertEqual(b, 2);	
}

void test_indexof_returns_0_if_float_element_is_in_0_position(){
	arrayutil a;
	int b;
	float x;
	int expected = 1,actual;
	a = create(sizeof(float),5);
	((float*)a.base)[0] = 1.1;
	((float*)a.base)[1] = 2.1;
	((float*)a.base)[2] = 420.1;
	x = 1.1;
	b = findIndex(a,&x);
	assertEqual(b, 0);
	x = 2.1;
	b = findIndex(a,&x);
	assertEqual(b, 1);	
	x = 420.1;
	b = findIndex(a,&x);
	assertEqual(b, 2);	
}

void test_indexof_returns_0_if_char_element_is_in_0_position(){
	arrayutil a;
	int b;
	char x;
	int expected = 1,actual;
	a = create(sizeof(char),5);
	((char*)a.base)[0] = 'a';
	((char*)a.base)[1] = 'b';
	((char*)a.base)[2] = 'c';
	x = 'a';
	b = findIndex(a,&x);
	assertEqual(b, 0);
	x = 'b';
	b = findIndex(a,&x);
	assertEqual(b, 1);	
	x = 'c';
	b = findIndex(a,&x);
	assertEqual(b, 2);	
}

void test_findFirst_returns_null_if_there_is_no_match(){
	arrayutil a;
	int x = 2;
	a = create(sizeof(int),1);
	((int*)a.base)[0]  = 9;
	assertEqual(findFirst(a,isEven,&x),NULL); 
}

void test_findFirst_returns_position_if_there_is_match_found(){
	arrayutil a;
	int x = 2;
	a = create(sizeof(int),5);
	((int*)a.base)[0] = 4;
	assertEqual(*((int*)findFirst(a,isEven,&x)),4); 
}

void test_findList_returns_positions_if_there_is_match_found(){
	arrayutil a;
	int x = 2;
	a = create(sizeof(int),5);
	((int*)a.base)[0] = 4;
	((int*)a.base)[1] = 3;
	((int*)a.base)[2] = 6;
	((int*)a.base)[3] = 8;
	((int*)a.base)[4] = 7;
	assertEqual(*((int*)findLast(a,isEven,&x)),8); 
}

void test_findList_returns_count_of_match_there_is_match_found(){
	arrayutil a;
	int x = 2;
	a = create(sizeof(int),5);
	((int*)a.base)[0] = 4;
	((int*)a.base)[1] = 3;
	((int*)a.base)[2] = 6;
	((int*)a.base)[3] = 8;
	((int*)a.base)[4] = 7;
	assertEqual(((int*)count(a,isEven,&x)),3); 
}

void test_findList_returns_negative_if_there_is_no_match_found(){
	arrayutil a;
	int x = 2;
	a = create(sizeof(int),5);
	((int*)a.base)[0] = 11;
	((int*)a.base)[1] = 3;
	((int*)a.base)[2] = 9;
	((int*)a.base)[3] = 421;
	((int*)a.base)[4] = 7;
	assertEqual(((int*)count(a,isEven,&x)),-1); 
}