#include "expr_assert.h"
#include "arrayutil.h"
#include <stdlib.h>

void test_areEqual_returns_negative_if_array_lengths_are_different() {
	int expected = 0,actual;
	ArrayUtil a,b;
	a.length = 5;
	b.length = 6;
	actual = areEqual(a,b);
	assertEqual(expected,actual);
}

void test_areEqual_returns_0_if_array_lengths_are_same_and_values_are_different() {
	int *arr1,*arr2;
	ArrayUtil a,b;
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

void test_areEqual_returns_1_if_array_lengths_are_same_and_values_are_same_for_integers() {
	int *arr1,*arr2;
	ArrayUtil a,b;
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

void test_areEqual_returns_1_if_for_same_integer_arrayUtils() {
	ArrayUtil a = {(int[]){1,2},sizeof(int),2},b = {(int[]){1,2},sizeof(int),2};
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_0_if_for_different_integer_arrayUtils() {
	ArrayUtil a = {(int[]){1,2},sizeof(int),2},b = {(int[]){1,3},sizeof(int),2};
	assertEqual(areEqual(a,b),0);
}

void test_areEqual_returns_1_if_for_same_float_arrayUtils() {
	ArrayUtil a = {(float[]){1.2,2.2},sizeof(float),2},b = {(float[]){1.2,2.2},sizeof(float),2};
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_0_if_for_different_float_arrayUtils() {
	ArrayUtil a = {(float[]){1.2,2.2},sizeof(float),2},b = {(float[]){1.2,2.9},sizeof(float),2};
	assertEqual(areEqual(a,b),0);
}

void test_areEqual_returns_1_if_for_same_character_arrayUtils() {
	ArrayUtil a = {(char[]){'a','b'},sizeof(char),2},b = {(char[]){'a','b'},sizeof(char),2};
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_0_if_for_different_character_arrayUtils() {
	ArrayUtil a = {(char[]){'a','b'},sizeof(char),2},b = {(char[]){'a','c'},sizeof(char),2};
	assertEqual(areEqual(a,b),0);
}

void test_areEqual_returns_1_for_same_string_arrayUtils() {
	ArrayUtil a = {(string[]){"ab","cd"},sizeof(string),2},b = {(string[]){"ab","cd"},sizeof(string),2};
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_0_for_different_string_arrayUtils() {
	ArrayUtil a = {(string[]){"ab","cd"},sizeof(string),2},b = {(string[]){"ab","cD"},sizeof(string),2};
	assertEqual(areEqual(a,b),0);
}

void test_areEqual_returns_1_for_emptystring_arrayUtils() {
	ArrayUtil a = {(string[]){"ab",""},sizeof(string),2},b = {(string[]){"ab",""},sizeof(string),2};
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_0_for_different_array_containing_emptystring_arrayUtils() {
	ArrayUtil a = {(string[]){"","66"},sizeof(string),2},b = {(string[]){"ab",""},sizeof(string),2};
	assertEqual(areEqual(a,b),0);
}

void test_areEqual_returns_1_for_different_utils_containing_same_number_as_characters() {
	ArrayUtil a = {(char[]){'4','6'},sizeof(char),2},b = {(char[]){'4','6'},sizeof(char),2};
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_0_for_different_array_containing_number_as_strings() {
	ArrayUtil a = {(string[]){"34","66"},sizeof(string),2},b = {(string[]){"34","67"},sizeof(string),2};
	assertEqual(areEqual(a,b),0);
}

void test_areEqual_returns_1_for_same_array_containing_number_as_strings() {
	ArrayUtil a = {(string[]){"34","66"},sizeof(string),2},b = {(string[]){"34","66"},sizeof(string),2};
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_1_for_same_double_type_array_containing_numbers() {
	ArrayUtil a = {(double[]){34.34,66.66},sizeof(double),2},b = {(double[]){34.34,66.66},sizeof(double),2};
	assertEqual(areEqual(a,b),1);
}

void test_areEqual_returns_1_if_array_lengths_are_same_and_values_are_same_for_char() {
	char *arr1,*arr2;
	ArrayUtil a,b;
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

void test_resize_sets_new_elements_to_zero_in_double(){
	ArrayUtil util;
	double expectedArray[] = {1.0,0.0};
	ArrayUtil b = {expectedArray,sizeof(double),2};
	util = create(sizeof(double),1);
	((double*)util.base)[0] = 1.0;
	util = resize(util, 2);
	assert(areEqual(b, util));
}

//===================================================================================

void test_create_returns_same_array_if_array_lengths_are_same_and_values_are_same() {
	ArrayUtil a,b;
	int expected = 1,actual;
	a = create(sizeof(int),2);
	b = create(sizeof(int),2);
	assert(areEqual(a,b) == 1);
}

void test_create_creates_arrayutil_with_all_the_elements_0(){
	ArrayUtil a = {(int[]){0,0},sizeof(int),2},b;
	b = create(sizeof(int),2);
	assertEqual(areEqual(a,b),1);
}

//===================================================================================

void test_resize_returns_1_if_array_lengths_are_same_and_values_are_same() {
	ArrayUtil a,b;
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

void test_resize_trims_the_given_array_util_if_given_length_is_smaller_than_the_original_length() {
	ArrayUtil a = {(int[]){1,2},sizeof(int),2},b = {(int[]){1},sizeof(int),1};
	assert(areEqual(resize(a,1),b));
}

void test_resize_increases_the_given_array_util_if_given_length_is_greater_than_the_original_length_and_sets_extra_element_0() {
	ArrayUtil a = {(int[]){1,2},sizeof(int),2},b = {(int[]){1,2,0,0,0},sizeof(int),5};
	assert(areEqual(resize(a,5),b));
}

//====================================================================================

void test_indexof_returns_negative_1_if_element_if_element_not_found(){
	ArrayUtil a;
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
	ArrayUtil a;
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
	ArrayUtil a;
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
	ArrayUtil a;
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

void test_indexof_returns_negative_1_if_the_given_element_is_not_found_in_integer_array(){
	ArrayUtil a = {(int[]){1,2,3,0,5},sizeof(int),5};
	int x = 9;
	assertEqual(findIndex(a,&x),-1);
}

void test_indexof_returns_position_of_element_if_the_given_element_is_found_in_integer_array(){
	ArrayUtil a = {(int[]){1,2,3,0,5},sizeof(int),5};
	int x = 3;
	assertEqual(findIndex(a,&x),2);
}

void test_indexof_returns_position_of_element_if_the_given_element_is_found_in_double_array(){
	ArrayUtil a = {(double[]){1.0,2.0,3.0,0.0,5.0},sizeof(double),5};
	double x = 1.0;
	assertEqual(findIndex(a,&x),0);
}

void test_indexof_returns_position_of_element_if_the_given_element_is_found_in_float_array(){
	ArrayUtil a = {(float[]){1.4,2.4,3.4,0.4,5.4},sizeof(float),5};
	float x = 3.4;
	assertEqual(findIndex(a,&x),2);
}

void test_indexof_returns_negative_1_if_the_given_element_is_not_found_in_character_array(){
	ArrayUtil a = {(char[]){'1','2','3','0','5'},sizeof(char),5};
	char x = '9';
	assertEqual(findIndex(a,&x),-1);
}

void test_indexof_returns_position_of_element_if_the_given_element_is_found_in_character_array(){
	ArrayUtil a = {(char[]){'1','2','3','0','5'},sizeof(char),5};
	char x = '3';
	assertEqual(findIndex(a,&x),2);
}

void test_indexof_returns_position_of_element_if_the_given_element_is_found_in_special_character_array(){
	ArrayUtil a = {(char[]){'@','$','&','!','*'},sizeof(char),5};
	char x = '&';
	assertEqual(findIndex(a,&x),2);
}

void test_indexof_returns_position_of_element_if_the_given_element_is_found_in_string_array(){
	ArrayUtil a = {(string[]){"prasenjit","Buddha","Radhe","Ananthu","Herrrr"},sizeof(string),5};
	string x = "Herrrr";
	assertEqual(findIndex(a,&x),4);
}

void test_indexof_returns_position_of_element_if_the_given_element_is_found_in_special_string_array(){
	ArrayUtil a = {(string[]){"prasenjit&&","Buddha!!","Radhe**","Ananthu##","Herrrr__!"},sizeof(string),5};
	string x = "Herrrr__!";
	assertEqual(findIndex(a,&x),4);
}

//=============================================================================

void test_findFirst_returns_null_if_there_is_no_match(){
	ArrayUtil a;
	int x = 2;
	a = create(sizeof(int),1);
	((int*)a.base)[0]  = 9;
	assertEqual(findFirst(a,isEven,&x),NULL); 
}

void test_findFirst_returns_position_if_there_is_match_found(){
	ArrayUtil a;
	int x = 2;
	a = create(sizeof(int),5);
	((int*)a.base)[0] = 4;
	assertEqual(*((int*)findFirst(a,isEven,&x)),4); 
}

void test_findFirst_returns_null_if_there_is_no_match_in_integer_array(){
	ArrayUtil a = {(int[]){1,3,5,7,9},sizeof(int),5};
	int x = 2;
	assertEqual(findFirst(a,isEven,&x),NULL);
}


void test_findFirst_returns_the_first_element_if_there_is_match_in_integer_array(){
	ArrayUtil a = {(int[]){1,3,5,8,10},sizeof(int),5};
	int x = 2;
	assertEqual(*((int*)findFirst(a,isEven,&x)),8);
}

void test_findFirst_returns_the_first_element_if_there_is_match_in_character_array(){
	ArrayUtil a = {(char[]){'a','b','C','D','e'},sizeof(char),5};
	int x = 'S';
	assertEqual(*((char*)findFirst(a,isUpperCase,&x)),'C');
}

//===================================================================================

void test_findLast_returns_positions_if_there_is_match_found(){
	ArrayUtil a;
	int x = 2;
	a = create(sizeof(int),5);
	((int*)a.base)[0] = 4;
	((int*)a.base)[1] = 3;
	((int*)a.base)[2] = 6;
	((int*)a.base)[3] = 8;
	((int*)a.base)[4] = 7;
	assertEqual(*((int*)findLast(a,isEven,&x)),8); 
}

void test_findLast_returns_null_if_there_is_no_match_in_integer_array(){
	ArrayUtil a = {(int[]){1,3,5,7,9},sizeof(int),5};
	int x = 2;
	assertEqual(findLast(a,isEven,&x),NULL);
}


void test_findLast_returns_the_last_element_if_there_is_match_in_integer_array(){
	ArrayUtil a = {(int[]){1,3,5,8,10},sizeof(int),5};
	int x = 2;
	assertEqual(*((int*)findLast(a,isEven,&x)),10);
}

void test_findLast_returns_the_last_element_if_there_is_match_in_character_array(){
	ArrayUtil a = {(char[]){'a','b','C','D','e'},sizeof(char),5};
	int x = 'D';
	assertEqual(*((char*)findLast(a,isUpperCase,&x)),'D');
}

//====================================================================================

void test_count_returns_count_of_match_there_is_match_found(){
	ArrayUtil a;
	int x = 2;
	a = create(sizeof(int),5);
	((int*)a.base)[0] = 4;
	((int*)a.base)[1] = 3;
	((int*)a.base)[2] = 6;
	((int*)a.base)[3] = 8;
	((int*)a.base)[4] = 7;
	assertEqual(((int*)count(a,isEven,&x)),3); 
}

void test_count_returns_negative_if_there_is_no_match_found(){
	ArrayUtil a;
	int x = 2;
	a = create(sizeof(int),5);
	((int*)a.base)[0] = 11;
	((int*)a.base)[1] = 3;
	((int*)a.base)[2] = 9;
	((int*)a.base)[3] = 421;
	((int*)a.base)[4] = 7;
	assertEqual(((int*)count(a,isEven,&x)),-1); 
}
void test_count_returns_count_of_match_there_is_match_found_in_integer_array() {
	ArrayUtil a = {(int[]){2,4,6,8,10},sizeof(int),5};
	int x = 2;
	assertEqual(((int*)count(a,isEven,&x)),5);
}

void test_count_returns_negative_of_match_there_is_match_found_in_integer_array() {
	ArrayUtil a = {(int[]){1,3,5,7,9},sizeof(int),5};
	int x = 2;
	assertEqual(((int*)count(a,isEven,&x)),-1);
}

void test_count_returns_number_of_match_found_if_there_is_match_in_character_array(){
	ArrayUtil a = {(char[]){'a','b','C','D','e'},sizeof(char),5};
	int x = 'D';
	assertEqual(((char*)count(a,isUpperCase,&x)),2);
}

void test_count_returns_negative_if_there_is_no_match_in_character_array(){
	ArrayUtil a = {(char[]){'a','b','c','d','e'},sizeof(char),5};
	int x = 'D';
	assertEqual(((char*)count(a,isUpperCase,&x)),-1);
}

//=====================================================================================

void test_filter_gives_2_4_for_1_2_3_4_5(){
	ArrayUtil util = create(sizeof(int),5);
	int *arr,i,result,hint = 2,*lIst;
	void* list;
	arr = (int*)util.base;
	for(i=0;i<5;i++){
		arr[i] = i+1;
	}
	result = filter(util, isDivisible,&hint,&list,2);
	lIst = (int*)list;
	assertEqual(result,2);
	assertEqual(lIst[0],2);
	assertEqual(lIst[1],4);
	free(list); 
}

void test_filter_gives_D_E_for_a_b_c_D_E() {
	ArrayUtil a = {(char[]){'a','b','c','D','E'},sizeof(char),5};
	char *result,hint = 'a',*lIst;
	void* list;
	int count;
	count =  filter(a,isUpperCase,&hint,&list,2);
	lIst = (char*)list;
	assert(count==2);
	assertEqual(lIst[0],'D');
	assertEqual(lIst[1],'E');
	free(list); 
}

void test_filter_gives_number_of_filtered_elements_for_float_array() {
	ArrayUtil a = {(float[]){1.2,2.2,3.2,4.2,5.2},sizeof(float),5};
	float *result,hint = 3.3;
	void* list;
	int count;
	count =  filter(a,isUpperCase,&hint,&list,3);
	assertEqual(count,3);
	free(list);
}

//===========================================================================================

void test_map_gives_2_3_4_5_6_for_1_2_3_4_5(){
	ArrayUtil src = create(sizeof(int),5),dest = create(sizeof(int),5);
	int *arr,i,hint = 1,*list;
	arr = (int*)src.base;
	for(i=0;i<5;i++){
		arr[i] = i+1;
	}
	list = ((int*)dest.base);
	map(src,dest,intConvertFunc,&hint);
	assertEqual(list[0],2);
	assertEqual(list[1],3);
	assertEqual(list[2],4);
	assertEqual(list[3],5);
	assertEqual(list[4],6);
	free(list); 
	dispose(src);
}

void test_map_gives_2_3_4_5_6_for_1_2_3_4_5_for_integer_array(){
	ArrayUtil src = {(int[]){1,2,3,4,5},sizeof(int),5},dest = create(sizeof(int),5);
	ArrayUtil tmp = {(int[]){2,3,4,5,6},sizeof(int),5};
	int hint = 1;
	map(src,dest,intConvertFunc,&hint);
	assert(areEqual(dest,tmp)==1);
	dispose(dest);
}

void test_map_gives_A_B_C_D_E_for_a_b_c_d_e_for_character_array(){
	ArrayUtil src = {(char[]){'a','b','c','d','e'},sizeof(char),5},dest = create(sizeof(char),5);
	ArrayUtil tmp = {(char[]){'A','B','C','D','E'},sizeof(char),5};
	char hint = 32;
	map(src,dest,charConvertFunc,&hint);
	assertEqual(areEqual(dest,tmp),1);
	dispose(dest);
}

void test_map_gives_result_for_float_array(){
	ArrayUtil src = {(float[]){1.2,2.2,3.2,4.2,5.2},sizeof(float),5},dest = create(sizeof(float),5);
	ArrayUtil tmp = {(float[]){2.2,3.2,4.2,5.2,6.2},sizeof(float),5};
	float hint = 1.0;
	map(src,dest,floatConvertFunc,&hint);
	assertEqual(areEqual(dest,tmp),1);
	dispose(dest);
}

//==========================================================================================

void test_forEach_gives_2_3_4_5_6_for_1_2_3_4_5_in_same_array(){
	ArrayUtil src = create(sizeof(int),5);
	int *arr,i,hint = 1,*list;
	arr = (int*)src.base;
	for(i=0;i<5;i++){
		arr[i] = i+1;
	}
	list = ((int*)src.base);
	forEach(src,intAddOperation,&hint);
	assertEqual(list[0],2);
	assertEqual(list[1],3);
	assertEqual(list[2],4);
	assertEqual(list[3],5);
	assertEqual(list[4],6);
	dispose(src);
}

//===========================================================================================
void test_reduce_gives_20_for_1_2_3_4_5_in_same_array(){
	ArrayUtil src = create(sizeof(int),5);
	int *arr,i,hint = 1,*list,initval = 0;
	void *result;
	arr = (int*)src.base;
	for(i=0;i<5;i++){
		arr[i] = i+1;
	}
	result = reduce(src,addReducerFunc,&hint,&initval);
	assertEqual(*((int*)result),20);
	dispose(src);
}








