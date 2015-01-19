#include "expr_assert.h"
#include "arrayutil.h"
#include <stdlib.h>

void test_isEqual_returns_0_if_array_lengths_are_different() {
	int expected = 0,actual;
	arrayutil a,b;
	a.length = 5;
	b.length = 6;
	actual = areEqual(a,b);
	assertEqual(expected,actual);
}

void test_isEqual_returns_1_if_array_lengths_are_same_and_values_are_same() {
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

void test_isEqual_returns_0_if_array_lengths_are_same_and_values_are_different() {
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
	a = create(sizeof(int),5);
	((int*)a.base)[0] = 1;
	((int*)a.base)[1] = 2;
	b = resize(a,4);
	assert(b.length == 4);
	assert(((int*)b.base)[0] == 1);
}

void test_indexof_returns_0_if_element_if_element_not_found(){
	arrayutil a;
	int b;
	int expected = 1,actual;
	a = create(sizeof(int),5);
	((int*)a.base)[0] = 1;
	((int*)a.base)[1] = 2;
	b = findIndex(a,4);
	assertEqual(b, -1);	
}

void test_indexof_returns_0_if_element_if_element_is_in_0_position(){
	arrayutil a;
	int b;
	int expected = 1,actual;
	a = create(sizeof(int),5);
	((int*)a.base)[0] = 1;
	((int*)a.base)[1] = 2;
	b = findIndex(a,1);
	assertEqual(b, 0);	
}

