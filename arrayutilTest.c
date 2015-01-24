#include "expr_assert.h"
#include "arrayutil.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#define CHAR_SIZE sizeof(char)
#define INT_SIZE sizeof(int)
#define null '/0'
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#define SIZEOF_INT sizeof(int)
#define log(test_description) int log = (printf("\t     %s\n\n", test_description))
#define sizeOf_char sizeof(char)
#define sizeOf_int sizeof(int)
#define sizeOf_float sizeof(float)
#define sizeOf_double sizeof(double)
#define sizeOf_String sizeof(String)
#define sizeOf_Student sizeof(Student)
#define sizeOf_int10 sizeof(int10)
#define sizeOf_float5 sizeof(float5)
#define sizeOf_void_star sizeof(void_star)
#define sizeOf_char_star sizeof(char_star)
#define sizeOf_int_star sizeof(int_star)
#define sizeOf_float_star sizeof(float_star)
#define YES 1
#define NO 0
ArrayUtil utils[3];
int array_1[1] = {1};
int array_1_2[2] = {1, 2};
int array_1_3[2] = {1, 3};
int array_0_0[2] = {0, 0};
int array_1_0[2] = {1, 0};
char array_null_null[2] = {'\0', '\0'};
float array_flt_flt[2] = {0, 0};
double array_dble_dble[2] = {0, 0};
String array_empty_strings[2] = {"", ""};
void_star array_void_stars[1] = {0x0};
char_star array_char_stars[1] = {(char *)('\0')};
int_star array_int_stars[1] = {(int *)(0)};
int10 array_int10_0s[1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
float5 array_float5_0s[1] = {{0.0, 0.0, 0.0, 0.0, 0.0}};
Student array_Students[1] = {{"", 0, 0.0}};
;
typedef struct studentForm {
    int roll;
    int marks;
} students;



void test_areEqual_should_return_1_when_two_array_util_are_same () {
    ArrayUtil util1 = { (int[]){1, 2}, INT_SIZE, 2};
    ArrayUtil util2 = { (int[]){1, 2}, INT_SIZE, 2};
    assertEqual(areEqual(util1, util2), 1);
}

void test_areEqual_should_return_0_when_two_array_util_are_not_same () {
    ArrayUtil util1 = { (int[]){1, 2, 3}, INT_SIZE, 3};
    ArrayUtil util2 = { (int[]){1, 2}, INT_SIZE, 2};
    assertEqual(areEqual(util1, util2), 0);
}

void test_areEqual_should_return_0_when_two_array_util_elements_are_not_same () {
    ArrayUtil util1 = { (int[]){1, 2}, INT_SIZE, 2};
    ArrayUtil util2 = { (int[]){3, 2}, INT_SIZE, 2};
    assertEqual(areEqual(util1, util2), 0);
}

void test_areEqual_for_float_should_return_1_when_two_array_util_elements_are_same () {
    ArrayUtil util1 = { (float[]){1.1, 2.2}, FLOAT_SIZE, 2};
    ArrayUtil util2 = { (float[]){1.1, 2.2}, FLOAT_SIZE, 2};
    assertEqual(areEqual(util1, util2), 1);
}

void test_areEqual_for_float_should_return_1_when_two_array_util_elements_are_not_same () {
    ArrayUtil util1 = { (float[]){1.2, 2.2}, FLOAT_SIZE, 2};
    ArrayUtil util2 = { (float[]){1.1, 2.2}, FLOAT_SIZE, 2};
    assertEqual(areEqual(util1, util2), 0);
}

void test_areEqual_for_char_should_return_1_when_two_array_util_elements_are_same () {
    ArrayUtil util1 = { (char[]){'a', 'b'}, CHAR_SIZE, 2};
    ArrayUtil util2 = { (char[]){'a', 'b'}, CHAR_SIZE, 2};
    assertEqual(areEqual(util1, util2), 1);
}

void test_areEqual_for_char_should_return_0_when_two_array_util_elements_are_not_same () {
    ArrayUtil util1 = { (char[]){'a', 'b'}, CHAR_SIZE, 2};
    ArrayUtil util2 = { (char[]){'c', 'b'}, CHAR_SIZE, 2};
    assertEqual(areEqual(util1, util2), 0);
}

void test_areEqual_for_Students_should_return_1_when_sets_of_data_are_same () {
    ArrayUtil util1 = { (students[]){{1, 100}, {2, 200}}, sizeof(students), 2};
    ArrayUtil util2 = { (students[]){{1, 100}, {2, 200}}, sizeof(students), 2};
    assertEqual(areEqual(util1, util2), 1);
}

void test_areEqual_for_Students_should_return_0_when_sets_of_data_not_are_same () {
    ArrayUtil util1 = { (students[]){{1, 100}, {2, 200}}, sizeof(students), 2};
    ArrayUtil util2 = { (students[]){{1, 100}, {2, 100}}, sizeof(students), 2};
    assertEqual(areEqual(util1, util2), 0);
}
void test_should_return_0_when_two_different_size_of_array_are_created_as_int_type () {
    ArrayUtil util1, util2;
    util1 = create(INT_SIZE, 2);
    util2 = create(INT_SIZE, 3);
    assertEqual(areEqual(util1, util2), 0);
    dispose(util1);
    dispose(util2);
}

void test_should_return_0_when_two_different_type_of_array_are_created () {
    ArrayUtil util1, util2;
    util1 = create(INT_SIZE, 2);
    util2 = create(FLOAT_SIZE, 2);
    ((float*)util2.base)[0] = 1.1;
    assertEqual(areEqual(util1, util2), 0);
    dispose(util1);
    dispose(util2);
}

void test_should_return_1_when_two_float_type_of_array_are_created_whose_length_are_same () {
    ArrayUtil util1, util2;
    util1 = create(FLOAT_SIZE, 2);
    util2 = create(FLOAT_SIZE, 2);
    assertEqual(areEqual(util1, util2), 1);
    dispose(util1);
    dispose(util2);
}

void test_should_return_0_when_one_float_and_one_char_type_of_array_are_created_whose_length_are_same () {
    ArrayUtil util1, util2;
    util1 = create(INT_SIZE, 2);
    util2 = create(CHAR_SIZE, 2);
    assertEqual(areEqual(util1, util2), 0);
    dispose(util1);
    dispose(util2);
}

void test_should_return_1_when_two_char_type_of_array_are_created_whose_length_are_same () {
    ArrayUtil util1, util2;
    util1 = create(CHAR_SIZE, 2);
    util2 = create(CHAR_SIZE, 2);
    assertEqual(areEqual(util1, util2), 1);
    dispose(util1);
    dispose(util2);
}

void test_should_return_1_when_two_students_type_of_array_are_created_whose_length_are_same () {
    ArrayUtil util1, util2;
    util1 = create(sizeof(students), 2);
    util2 = create(sizeof(students), 2);
    assertEqual(areEqual(util1, util2), 1);
    dispose(util1);
    dispose(util2);
}

void test_should_return_0_when_two_students_type_of_array_are_created_whose_length_are_not_same () {
    ArrayUtil util1, util2;
    util1 = create(sizeof(students), 2);
    util2 = create(sizeof(students), 3);
    assertEqual(areEqual(util1, util2), 0);
    dispose(util1);
    dispose(util2);
}

void test_should_compress_the_size_of_an_array_from_length_3_to_2 () {
    ArrayUtil util1, util2;
    util1 = create(CHAR_SIZE, 2);
    ((char*)(util1.base))[0] = 'c';
    ((char*)(util1.base))[1] = 'd';
    util2 = resize(util1, 3);
    assertEqual(util2.length, 3);
    assertEqual(areEqual(util1, util2), 0);
    assertEqual(((char*)(util2.base))[0], 'c');
    assertEqual(((char*)(util2.base))[1], 'd');
    assertEqual(((char*)(util2.base))[2], 0);
    dispose(util1);
}

void test_should_compress_the_size_of_an_array_when_new_size_is_smaller_than_the_previous_size () {
    ArrayUtil array1;
    int isSuccess, sizeofChar;
    sizeofChar = sizeof(char);
    array1 = create(sizeofChar, 2);
    ((char*)(array1.base))[0] = 'c';
    ((char*)(array1.base))[1] = 'd';
    array1 = resize(array1, 1);
    assertEqual(array1.length, 1);
    assertEqual(((char*)(array1.base))[0], 'c');
}

void test_findIndex_should_give_2_as_index_of_the_array () {
    ArrayUtil array1;
    int *a, element;
    array1 = create(INT_SIZE, 2);
    a = ((int*)(array1.base));
    a[0] = 1;
    a[1] = 2;
    element = 2;
    assertEqual(findIndex(array1, &element), 1);
    element = 1;
    assertEqual(findIndex(array1, &element), 0);
    dispose(array1);
}

void test_findIndex_should_give_minus_1_as_index_of_the_array () {
    ArrayUtil array1;
    int *a, sizeofInt, element;
    sizeofInt = sizeof(int);
    array1 = create(sizeofInt, 2);
    a = ((int*)(array1.base));
    a[0] = 1;
    a[1] = 2;
    element = 3;
    assertEqual(findIndex(array1, &element), -1);
}

void test_areEqual_returns_negative_if_array_lengths_are_different() {
	int expected = 0,actual;
	ArrayUtil a,b;
	a.length = 5;
	b.length = 6;
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

void test_resize_sets_new_elements_to_zero_in_double(){
	ArrayUtil util;
	double expectedArray[] = {1.0,0.0};
	ArrayUtil b = {expectedArray,sizeof(double),2};
	util = create(sizeof(double),1);
	((double*)util.base)[0] = 1.0;
	util = resize(util, 2);
	assert(areEqual(b, util));
}

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

void test_filter_gives_2_4_for_1_2_3_4_5(){
	ArrayUtil util = create(sizeof(int),5);
	int *arr,i,result,hint = 2,*lIst;
	void* list = malloc(2*sizeof(int));
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
	void* list = malloc(sizeof(char)*2);
	int count;
	count =  filter(a,isUpperCase,&hint,&list,2);
	lIst = (char*)list;
	assert(count==2);
	// assertEqual(lIst[0],'D');
	// assertEqual(lIst[1],'E');
	free(list); 
}

void test_filter_gives_number_of_filtered_elements_for_float_array() {
	ArrayUtil a = {(float[]){1.2,2.2,3.2,4.2,5.2},sizeof(float),5};
	float *result,hint = 3.3;
	void* list = malloc(3*sizeof(float));
	int count;
	count =  filter(a,isUpperCase,&hint,&list,3);
	assertEqual(count,3);
	free(list);
}

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

void test_areEqual_return_1_when_both_int_array_lenght_base_and_typesize_and_elements_are_same(){
	int array1[]={1,2,3,4,5};
	int array2[]={1,2,3,4,5};
	ArrayUtil u1={array1,INT_SIZE,5};
	ArrayUtil u2={array2,INT_SIZE,5};
	assertEqual(areEqual(u1,u2), 1);
}

void test_areEqual_return_1_when_both_float_array_lenght_base_and_typesize_and_elements_are_same(){
	float array1[]={1.5,2.5,3.5,4.5,5.5};
	float array2[]={1.5,2.5,3.5,4.5,5.5};
	ArrayUtil u1={array1,FLOAT_SIZE,5};
	ArrayUtil u2={array2,FLOAT_SIZE,5};
	assertEqual(areEqual(u1,u2), 1);
}

void test_areEqual_return_0_when_both_float_base_and_typesizeare_same_but_one_has_less_element(){
	float array1[]={1.5,2.5,3.5,4.5};
	float array2[]={1.5,2.5,3.5,4.5,5.5};
	ArrayUtil u1={array1,FLOAT_SIZE,5};
	ArrayUtil u2={array2,FLOAT_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_both_float_base_and_typesizeare_same_but_second_has_less_element(){
	float array1[]={1.5,2.5,3.5,4.5};
	float array2[]={1.5,2.5,3.5};
	ArrayUtil u1={array1,FLOAT_SIZE,4};
	ArrayUtil u2={array2,FLOAT_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_both_float_array_length_are_different(){
	float array1[]={1.5,2.5,3.5,4.5};
	float array2[]={1.5,2.5,3.5};
	ArrayUtil u1={array1,FLOAT_SIZE,4};
	ArrayUtil u2={array2,FLOAT_SIZE,3};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_one_is_float_array_and_second_is_int_array_typesize_different(){
	float array1[]={1.0,2.0,3.0,4.0};
	int array2[]={1,2,3,4};
	ArrayUtil u1={array1,FLOAT_SIZE,4};
	ArrayUtil u2={array2,INT_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_one_is_float_array_and_second_is_int_array_typesize_same(){
	float array1[]={1.0,2.0,3.0,4.0};
	int array2[]={1,2,3,4};
	ArrayUtil u1={array1,FLOAT_SIZE,4};
	ArrayUtil u2={array2,FLOAT_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_both_have_same_float_array_typesize_different(){
	float array1[]={1.0,2.0,3.0,4.0};
	float array2[]={1.0,2.0,3.0,4.0};
	ArrayUtil u1={array1,FLOAT_SIZE,4};
	ArrayUtil u2={array2,CHAR_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_1_when_both_doube_array_lenght_base_and_typesize_and_elements_are_same(){
	double array1[]={1.5,2.5,3.5,4.5,5.5};
	double array2[]={1.5,2.5,3.5,4.5,5.5};
	ArrayUtil u1={array1,DOUBLE_SIZE,5};
	ArrayUtil u2={array2,DOUBLE_SIZE,5};
	assertEqual(areEqual(u1,u2), 1);
}

void test_areEqual_return_0_when_both_double_base_and_typesizeare_same_but_one_has_less_element(){
	double array1[]={1.5,2.5,3.5,4.5};
	double array2[]={1.5,2.5,3.5,4.5,5.5};
	ArrayUtil u1={array1,DOUBLE_SIZE,5};
	ArrayUtil u2={array2,DOUBLE_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_both_double_base_and_typesizeare_same_but_second_has_less_element(){
	double array1[]={1.5,2.5,3.5,4.5};
	double array2[]={1.5,2.5,3.5};
	ArrayUtil u1={array1,DOUBLE_SIZE,4};
	ArrayUtil u2={array2,DOUBLE_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_both_double_array_length_are_different(){
	double array1[]={1.5,2.5,3.5,4.5};
	double array2[]={1.5,2.5,3.5};
	ArrayUtil u1={array1,DOUBLE_SIZE,4};
	ArrayUtil u2={array2,DOUBLE_SIZE,3};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_one_is_double_array_and_second_is_int_array_typesize_different(){
	double array1[]={1.0,2.0,3.0,4.0};
	int array2[]={1,2,3,4};
	ArrayUtil u1={array1,DOUBLE_SIZE,4};
	ArrayUtil u2={array2,INT_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_one_is_int_array_and_second_is_int_array_typesize_same(){
	double array1[]={1.0,2.0,3.0,4.0};
	int array2[]={1,2,3,4};
	ArrayUtil u1={array1,DOUBLE_SIZE,4};
	ArrayUtil u2={array2,DOUBLE_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_both_have_same_double_array_typesize_different(){
	double array1[]={1.0,2.0,3.0,4.0};
	double array2[]={1.0,2.0,3.0,4.0};
	ArrayUtil u1={array1,DOUBLE_SIZE,4};
	ArrayUtil u2={array2,CHAR_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_1_when_both_characetr_array_lenght_base_and_typesize_and_elements_are_same(){
	char array1[]={'a','b','c','d','\0'};
	char array2[]={'a','b','c','d','\0'};
	ArrayUtil u1={array1,CHAR_SIZE,5};
	ArrayUtil u2={array2,CHAR_SIZE,5};
	assertEqual(areEqual(u1,u2), 1);
}

void test_areEqual_return_0_when_both_characetr_array_lenght_are_same_but_typesize_is_different(){
	int array1[]={1,2,3,4,5};
	char array2[]={'a','b','c','d','\0'};
	ArrayUtil u1={array1,INT_SIZE,5};
	ArrayUtil u2={array2,CHAR_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_both_characetr_array_typesize_are_same_but_length_is_different(){
	char array1[]={'a','b','c','\0'};
	char array2[]={'a','b','c','d','\0'};
	ArrayUtil u1={array1,INT_SIZE,4};
	ArrayUtil u2={array2,CHAR_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_1_for_array_of_string_if_everything_is_same(){
	STRING array1[]={"abc","abc","abc","abc","abc"};
	STRING array2[]={"abc","abc","abc","abc","abc"};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,5};
	assertEqual(areEqual(u1,u2), 1);
}

void test_areEqual_return_0_for_array_of_string_if_lenghts_are_different(){
	STRING array1[]={"abc","abc","abc","abc","abc"};
	STRING array2[]={"abc","abc","abc","abc","abc"};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_1_when_length_and_typesize_are_same_and_each_ele_is_empty_string(){
	STRING array1[]={"","","","",""};
	STRING array2[]={"","","","",""};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,5};
	assertEqual(areEqual(u1,u2), 1);
}

void test_areEqual_return_0_when_typesize_and_length_are_same_but_first_has_less_element(){
	STRING array1[]={"","","",""};
	STRING array2[]={"","","","",""};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_typesize_is_same_but_second_has_less_element_and_less_length(){
	STRING array1[]={"ank","aks","ank","aks","ank"};
	STRING array2[]={"ank","aks","ank","aks"};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_1_typesize_is_STRING_SIZE_and_2_is_INT_SIZE(){
	STRING array1[]={"abc","abc","abc","abc","abc"};
	int array2[]={1,2,3,4,5};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,INT_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_returns_0_when_lenght_are_not_equal(){
	int array1[]={1,2,3,4};
	int array2[]={1,2,3,4,5};
	ArrayUtil u1={array1,INT_SIZE,4};
	ArrayUtil u2={array2,INT_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_create_creates_a_given_length_array_of_5_elements_initialized_to_0_when_given_length_is_5(){
	int array[]={0,0,0,0,0};
	ArrayUtil util=create(INT_SIZE,5);
	ArrayUtil expected={array,INT_SIZE,5};
	assert(areEqual(util,expected));
	free(util.base);
}

void test_create_creates_a_given_length_array_of_3_elements_initialized_to_0_when_given_length_is_3(){
	int array[]={0,0,0};
	ArrayUtil util=create(INT_SIZE,3);
	ArrayUtil expected={array,INT_SIZE,3};
	assert(areEqual(util,expected));
	free(util.base);
}

void test_create_creates_a_given_length_char_array_all_elements_slash_0(){
	char array[]={'\0','\0','\0'};
	ArrayUtil util=create(CHAR_SIZE,3);
	ArrayUtil expected={array,CHAR_SIZE,3};
	assert(areEqual(util,expected));
	free(util.base);
}

void test_if_new_length_is_less_than_old_length_resize_gives_an_array_of_starting_elements_till_given_length(){
	int array[]={1,2,3,4,5};
	int newArray[]={1,2,3};
	ArrayUtil util={array,INT_SIZE,5},resized;
	ArrayUtil expected={newArray,INT_SIZE,3};
	resized=resize(util,3);
	assert(areEqual(resized,expected));
	free(resized.base);
}

void test_if_new_length_is_greter_than_old_length_then_in_resized_array_extra_elements_of_new_array_should_be_0(){
	int array[]={1,2,3};
	int newArray[]={1,2,3,0,0};
	ArrayUtil util={array,INT_SIZE,3},resized;
	ArrayUtil expected={newArray,INT_SIZE,5};
	resized=resize(util,5);
	assert(areEqual(resized,expected));
	free(resized.base);
}

void test_findindex_returns_index_when_element_is_present(){
	int array[]={1,2,3,4,5,6};
	int x=5;
	ArrayUtil util={array,INT_SIZE,6};
	assertEqual(findIndex(util,&x), 4);
}

void test_findindex_returns_minus_one_when_element_is_not_present(){
	int array[]={1,2,3,4,5,6};
	int x=9;
	ArrayUtil util={array,INT_SIZE,6};
	assertEqual(findIndex(util,&x), -1);
}

void test_findindex_returns_index_when_element_is_present_for_character_array(){
	char array[]={'a','b','c','d','e','f','\0'};
	char x='c';
	ArrayUtil util={array,sizeof(char),7};
	assertEqual(findIndex(util,&x), 2);
}

void test_findFirst_returns_even_number_from_array_on_first_when_condition_matches(){
	int array[]={1,2,3,4,5,6,7,8};
	ArrayUtil util={array,INT_SIZE,8};
	void *hint;
	int *result;
	result =(int *)findFirst(util,isEven,&hint);
	assertEqual(*result, 2);
}

void test_findFirst_returns_0_when_no_element_matches_condition(){
	int array[]={1,3,5,7};
	ArrayUtil util={array,INT_SIZE,4};
	void *hint;
	int *result;
	result =findFirst(util,isEven,&hint);
	assertEqual((int )result, 0);
}

void test_findLast_returns_last_even_number_from_array_when_condition_matches(){
	int array[]={1,2,3,4,5,6,7,8};
	ArrayUtil util={array,INT_SIZE,8};
	void *hint;
	int *result;
	result =(int *)findLast(util,isEven,&hint);
	assertEqual(*result, 8);
}

void test_findLast_returns_0_when_no_element_matches_condition(){
	int array[]={1,3,5,7};
	ArrayUtil util={array,INT_SIZE,4};
	void *hint;
	int *result;
	result =findLast(util,isEven,&hint);
	assertEqual((int )result, 0);
}

void test_count_returns_4_for_1_2_3_4_5_6_7_8_when_checked_for_even_no(){
	int array[]={1,2,3,4,5,6,7,8};
	ArrayUtil util={array,INT_SIZE,8};
	void *hint;
	int result=count(util,isEven,&hint);
	assertEqual(result, 4);
}

void test_count_returns_0_for_1_3_5_7_when_checked_for_even_no(){
	int array[]={1,3,5,7};
	ArrayUtil util={array,INT_SIZE,4};
	void *hint;
	int result=count(util,isEven,&hint);
	assertEqual(result, -1);
}

void element_plus_one(void* hint, void* item){
	*((int *)item)= *((int *)item) + 1;
}

void test_forEach_icrements_each_element_by_one(){
	void *hint;
	int array[]={1,2,3,4,5};
	int incremented[]={2,3,4,5,6};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={incremented,INT_SIZE,5};
	forEach(util,element_plus_one,&hint);
	assert(areEqual(util,expected));
}


// void square_elements(void *hint, void *sourceItem, void *destinationItem){
// 	*(int*)destinationItem=*(int*)sourceItem * *(int*)sourceItem;
// }

// void test_map_returns_square_of_each_element_in_array(){
// 	void *hint;
// 	int array[]={1,2,3,4,5};
// 	int newArray[]={1,4,9,16,25};
// 	ArrayUtil util={array,INT_SIZE,5};
// 	ArrayUtil expected={newArray,INT_SIZE,5};
// 	ArrayUtil mapped={calloc(5,INT_SIZE),INT_SIZE,5};
// 	map(util,mapped,square_elements,&hint);
// 	assert(areEqual(expected, mapped));
// 	assert(arrayEqual(newArray,expected.base));
// }

void element_into_element_plus_one(void* hint, void* item){
	*((int *)item)= *((int *)item) * ((*((int *)item))+1);
}

void test_ForEach_does_multiplication_of_item_with_item_plus_one(){
	void *hint;
	int array[]={1,2,3,4,5};
	int incremented[]={2,6,12,20,30};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={incremented,INT_SIZE,5};
	forEach(util,element_into_element_plus_one,&hint);
	assert(areEqual(util,expected));
}

void test_rEsize_returns_CHAR_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	ArrayUtil util = {(char[]){'a','e','i','o'},sizeof(char),4};
	ArrayUtil expectedUtil = {(char[]){'a','e','i','o',0,0},sizeof(char),6};
	resizedArray = resize(util,6);
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(util);
	dispose(resizedArray);
	dispose(expectedUtil);
}

void test_rEsize_returns_CHAR_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	ArrayUtil  util = (ArrayUtil){(char []){'a','e','i','o','u'},sizeof(char),5};
	ArrayUtil  expectedUtil = (ArrayUtil){(char []){'a','e'},sizeof(char),2};
	resizedArray = resize(util,2);
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(util);
	dispose(resizedArray);
	dispose(expectedUtil);
}

void test_areEqual_gives_0_if_arrayUtil_are_not_same(){
    int first_array[]={1,2,3,4,5};
    int second_array[]={1,2,3,4,5,6};
    ArrayUtil array1 = {first_array,sizeof(int),5};
    ArrayUtil array2 = {second_array,sizeof(int),6};
	assertEqual(areEqual(array1, array2),0);
};

void test_for_the_length_of_two_array_are_equal2(){
    int first_array[]={1,2,3,4};
    int second_array[]={1,2,3,4};
    ArrayUtil array1 = {first_array,sizeof(int),4};
    ArrayUtil array2 = {second_array,sizeof(int),4};
	assertEqual(areEqual(array1, array2),1);
};

void test_of_ArrayUtil_for_the_float_are_equall(){
    float first_array[]={1.0,2.6,3.2,4.1};
    float second_array[]={1.0,2.6,3.2,4.1};
    ArrayUtil array1 = {first_array,sizeof(float),4};
    ArrayUtil array2 = {second_array,sizeof(float),4};
	assertEqual(areEqual(array1, array2),1);
};

void test_for_the_ArrayUtil_for_float_are_not_equall(){
    float first_array[]={1.0,2.6,3.2,4.1};
    float second_array[]={1.0,2.9,3.2,4.1};
    ArrayUtil array1 = {first_array,sizeof(float),4};
    ArrayUtil array2 = {second_array,sizeof(float),4};
	assertEqual(areEqual(array1, array2),0);
};

void test_foR_the_ArrayUtil_for_charecter_and_int_are_not_equal(){
    char first_array[]={'c','d','e','f'};
    int second_array[]={2,5,8,4};
    ArrayUtil array1 = {first_array,sizeof(char),4};
    ArrayUtil array2 = {second_array,sizeof(int),4};
	assertEqual(areEqual(array1, array2),0);
};

void test_for_create_new_array_of_integertype(){
    ArrayUtil newArray;
    newArray = create(sizeof(int),5);
	assertEqual(newArray.typeSize,4);
	assertEqual(newArray.length,5);
}

void test_for_create_new_array_of_charectertype(){
    ArrayUtil array;
    array = create(sizeof(char),6);
	assertEqual(array.typeSize,1);
	assertEqual(array.length,6);
};

void test_for_create_new_array_of_StringType(){
    ArrayUtil array;
    array = create(sizeof(char*),6);
	assertEqual(array.typeSize,4);
	assertEqual(array.length,6);
};

void test_findIndex_return_the_index_of_existing_element_in_the_array(){
    int x=3;
    int arr[] = {2,4,3,7};
    ArrayUtil array = {arr, sizeof(int) , 4};
    assertEqual(findIndex(array, &x),2);
};

void test_findIndex_retruns_the_index_of_an_element_in_an_char_array(){
    char array[]= {'a','b','c','d'};
    char element ='c';
    ArrayUtil util = {array,sizeof(char),4};
    assertEqual(findIndex(util,&element),2);
};

void test_fIndIndex_retruns_the_index_of_an_element_in_an_string_array(){
    char array[]= {"heloo"};
    char element ='o';
    ArrayUtil util = {array,sizeof(char),4};
    assertEqual(findIndex(util,&element),3);
};


void test_findIndex_return_first_index_of_multiple_existing_element_in_the_array(){
    int x=7;
    int arr[] = {2,4,3,7,5,7,7,7};
    ArrayUtil array={arr, sizeof(int), 8};
    assertEqual(findIndex(array, &x),3);
};

void test_ArrayUtil_to_find_indexOf_float_type_value_it_gives_1(){
    float x=4.3;
    float y=3.0;
    float arr[] = {3.2,4.3,6.3,8.6};
    ArrayUtil array ={arr,sizeof(float),4};
    assertEqual(findIndex(array, &x),1);
    // assertEqual(findIndex(array, &y), -1);
};

void test_ArrayUtil_dispose_to_free_the_memory_allocated_for_the_intType_array(){
    ArrayUtil array1,array2;
    array1 = create(sizeof(int),5);
    array2 = create(sizeof(float),7);
    dispose(array1);
    dispose(array2);
    assertEqual(areEqual(array1,array2),0);
}

void test_ArrayUtil_dispose_to_free_the_memory_allocated_for_the_charType_array(){
    ArrayUtil array1,array2;
    array1 = create(sizeof(char),7);
    array2 = create(sizeof(char*),5);
    dispose(array1);
    dispose(array2);
}

int isEvenNumber(void* element,void* hint ){
   	 return ((*(int*)element) % (*(int*)hint)==0) ;
};

void test_for_findFirst_gives_the_first_element_of_an_array(){
    int hint = 2;
    int *result;
    MatchFunc *match = &isEvenNumber;
    ArrayUtil util = {(int[]){3,5,8,8,7,2},sizeof(int),6};
    result = (int*)findFirst(util,match,&hint);
    assertEqual(*result,8);
}

int isCompareCharecter(void* element,void* hint){
    return (*((char*)hint) == *((char*)element)) ? 1 : 0;
}

void test_for_findFirst_gives_the_first_element_of_charecter_an_array(){
    char hint = 'c';
    char *result;
    MatchFunc *match = &isCompareCharecter;
    ArrayUtil util = {(char[]){'a','b','c','c','d','c'},sizeof(char),6};
    result = findFirst(util,match,&hint);
    assertEqual(*result,'c');
}

void test_for_findLast_gives_the_last_element_of_an_array(){
    int hint = 2;
    int *result;
    MatchFunc *match = &isEvenNumber;
    ArrayUtil util = {(int[]){3,5,8,8,7,2,5},sizeof(int),7};
    result = findLast(util,match,&hint);
    assertEqual(*result,2);
};

void test_for_findLast_gives_the_null_if_charecter_is_not_existing_in_an_array(){
    char hint = 'e';
    char *result;
    MatchFunc *match = &isCompareCharecter;
    ArrayUtil util = {(char[]){'a','b','c','c','d','c'},sizeof(char),6};
    result = (char*)findFirst(util,match,&hint);
    assert(result == NULL);
}

void test_create_allocates_space_for_INT_array_and_assigns_zero_to_all_bytes(){
	ArrayUtil util = create(sizeof(int),4);
	int intArray[] = {0,0,0,0};
	ArrayUtil expectedUtil;
	expectedUtil.base = intArray;
	expectedUtil.typeSize = sizeof(int);
	expectedUtil.length = 4;

	assertEqual(areEqual(expectedUtil,util),1);
}

void test_when_an_array_is_resized_into_smaller_size_the_array_is_trimmed(){
	ArrayUtil util = create( sizeof(char) , 3);
	ArrayUtil resizedUtil = resize(util, 2);
	char array[]={0,0,0};
	ArrayUtil expected = { (void *)array, sizeof(char), 2};
	assert(areEqual(expected, resizedUtil));
}

void test_findIndex_returns_1_if_the_search_char_is_found_on_1st_location (){
	int x = 'a';
	char array[] = "car";
	ArrayUtil util = create(CHAR_SIZE,3);
	util.base = (void*)array;
	assertEqual(findIndex(util,&x),1);
}

void* sum (void* hint, void* pv, void* cv){
	int* _pv = (int*)pv;
	int* _cv = (int*)cv;
	int* result = (int*)malloc(INT_SIZE); 
	*result = *_pv + *_cv;
	return result;
}

void test_reduce_returns_sum_of_all_integers_of_array (){
	int hint = 2,result;
	int initial_value = 0;
	int array[] = {1,2,3};
	void* (*fn_ptr)(void*,void*,void*) = &sum;
	ArrayUtil util = create(INT_SIZE,3);
	util.base = (void*)array;
	result = *(int*)reduce(util,fn_ptr,(void*)&hint,(void*)&initial_value);
	assertEqual(result,6);
}

void test_that_function_creates_new_array_or_not(){
	ArrayUtil array = create(sizeof(int),3);
	int *createArray  = (int*)array.base;
	assertEqual(createArray[0], 0);
	assertEqual(createArray[2], 0);
	assertEqual(array.length, 3);
	assertEqual(array.typeSize, 4);
}

int isCapital(void *item, void *hint) {
    return((*(char *)item >=65) && (*(char *)item <= 91));
}

int isGreaterThan5(void *item, void *hint) {
    return(*(float *)item > 5);
}

void test_areEqual_returns_0_if_typeSize_of_two_arrays_are_not_equal(){
    int array1[] = {1,2,3,4};
    char array2[] = {'m','a','h','e'};
    ArrayUtil util1 = {array1,sizeof(int),4};
    ArrayUtil util2 = {array2,sizeof(char),4};
    assertEqual(areEqual(util1, util2), 0);
}

void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_capital(){
    char array1[] = {'k','M','k'};
    ArrayUtil util1 = {array1,sizeof(char),3};
    assertEqual(*(char *)(findFirst(util1,&isCapital,0)), 'M');
}

void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_even(){
    int array1[] = {1,2,3,4,5};
    int x = 0;
    ArrayUtil util1 = {array1,sizeof(int),5};
    assertEqual(*(int *)(findFirst(util1,isEven,&x)), 2);
}

void test_findFirst_returns_the_adsdress_of_first_element_in_the_array_greater_than_5() {
    float array1[] = {1.1,6.6,5.5,8.8,2.2};
    ArrayUtil util1 ={array1, sizeof(float),5};
    assertEqual(*(float *)(findFirst(util1,&isGreaterThan5,0)), (float)6.6);
}

void test_findIndex_returns_index_of_the_String_element_where_it_presents(){
    String array1[] = {"Mahesh","Kumar","Kolla"};
    String element = "Kumar";
    ArrayUtil util1 = {array1,sizeof(String),3};
    assertEqual(findIndex(util1,&element), 1);
}

void test_findIndex_returns_index_of_the_char_element_where_it_presents(){
    char array1[] = {'m','a','h','e','s','h'};
    char element = 's';
    ArrayUtil util1 = {array1,sizeof(char),6};
    assertEqual(findIndex(util1,&element), 4);
}

void test_findIndex_returns_index_of_the_float_element_where_it_presents(){
    float array1[] = {1.1,2.2,3.3,4.4};
    float element = 4.4;
    ArrayUtil util1 = {array1,sizeof(float),4};
    assertEqual(findIndex(util1,&element), 3);
}

void test_findIndex_returns_index_of_the_integer_element_where_it_presents(){
    int array1[] = {1,2,3,4,5};
    int element = 2;
    ArrayUtil util1 = {array1,sizeof(int),5};
    assertEqual(findIndex(util1,&element), 1);
}

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_double(){
	double a [] = {2.34};
	double b [] = {2.34};
	ArrayUtil array1 = {a, sizeof(double), 1};
	ArrayUtil array2 = {b, sizeof(double), 1};

	assert(areEqual(array1,array2));
};

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_string(){
	String a [] = {"hello"};
	String b [] = {"hello"};
	ArrayUtil array1 = {a, sizeof(String), 1};
	ArrayUtil array2 = {b, sizeof(String), 1};

	assert(areEqual(array1,array2));
};

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_not_be_equal_String(){
	String a [] = {"hallo"};
	String b [] = {"hello"};
	ArrayUtil array1 = {a, sizeof(String), 1};
	ArrayUtil array2 = {b, sizeof(String), 1};

	assertEqual(areEqual(array1,array2),0);
};

int compare(void *item,void* hint){
	if(*(char*)item=='a')
		return 1;
	return 0;
};

int isEqual(void* item, void* hint){
	if(*(int*)item==8 ||*(float*)item == 9.0 || *(double*)item==8.9)
		return 1;
	return 0;
}

int stringCompare(void *item, void* hint){
	String str ="hello";
	String getItem = *(String*)item;
	if(getItem==str)
		return 1;
	return 0;
}

void test_filter_will_return_the_array_a_a_a(){
	char a[]={'a','a','a','b','d'},hint=3;
	int length;
	void* result;
	ArrayUtil array = {a, sizeof(char), 5};
	result = malloc(3*sizeof(char));
	length = filter(array,compare,&hint,&result,5);

	assertEqual(((char*)result)[1],'a');
	assertEqual(length,3);
	free(result);
};

void test_filter_will_return_the_array_of_8_8_8(){
	int a[]={1,8,8,7,8,9},hint=3,length;
	void* result = malloc(3*sizeof(char));
	ArrayUtil array = {a, sizeof(int), 6};
	length = filter(array,isEqual,&hint,&result,5);

	assertEqual(((int*)result)[0],8);
	assertEqual(length,3);
	free(result);
};

void test_filter_will_return_the_array_of_only_two_8(){
	int a[]={1,8,8,7,8,9},hint=3,length;
	void* result = malloc(2*sizeof(int));
	ArrayUtil array = {a, sizeof(int), 6};
	length = filter(array,isEqual,&hint,&result,2);

	assertEqual(((int*)result)[1],8);
	assertEqual(length,2);
	free(result);
};

void test_filter_will_return_the_array_of_only_two_8_point_7_in_float(){
	float a[]={1.4,8.4,8.9,7,8,9.0},hint=3;
	int length;
	void* result = malloc(2*sizeof(float));
	ArrayUtil array = {a, sizeof(float), 6};
	length = filter(array,isEqual,&hint,&result,2);

	assertEqual(((float*)result)[0],9.0);
	assertEqual(length,1);
	free(result);
};

void test_fiLter_will_return_the_array_of_only_two_8_point_7_in_float(){
	float a[]={1.4,8.4,8.9,7,8,9.0},hint=3;
	int length;
	void* result = malloc(2*sizeof(float));
	ArrayUtil array = {a, sizeof(float), 6};
	length = filter(array,isEqual,&hint,&result,2);

	assertEqual(((float*)result)[0],9.0);
	assertEqual(length,1);
	free(result);
};

void test_filTer_will_return_the_array_a_a_a(){
	char a[]={'a','a','a','b','d'},hint=3;
	int length;
	void* result = malloc(5*sizeof(char));
	ArrayUtil array = {a, sizeof(char), 5};
	length = filter(array,compare,&hint,&result,5);

	assertEqual(((char*)result)[1],'a');
	assertEqual(length,3);
	free(result);
};

void test_filter_will_return_the_array_of_only_one_element_8_point_9_in_double(){
	double a[]={8.4,8.4,8.9},hint=3.9;
	int length;
	void* result = malloc(1*sizeof(double));
	ArrayUtil array = {a, sizeof(double), 3};
	length = filter(array,isEqual,&hint,&result,2);
	assertEqual(length,1);
};

void test_filter_will_return_the_array_string_contain_hello(){
	int length,hint=9;
	void* result = malloc(1*sizeof(String)),*expected;
	ArrayUtil array = create(sizeof(String),2);
	((char**)array.base)[0]="hello";
	((char**)array.base)[1]="gello";
	length = filter(array,stringCompare,&hint,&result,2);
	expected = ((String*)result)[0];
	
	assertEqual(length,1);
	assertEqual(strcmp(expected,"hello"),0);
};

void test_areEqual_returns_1_if_two_int_array_are_equal(){
	int array1[] = {1,2,3};
	int array2[] = {1,2,3};
	ArrayUtil a1 = create(4,3);
	ArrayUtil a2 = create(4,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_0_if_two_int_array_are_not_equal(){
	int array1[] = {1,2,4};
	int array2[] = {1,2,3};
	ArrayUtil a1 = create(4,3);
	ArrayUtil a2 = create(4,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),0);
}

void test_areEqual_returns_1_if_two_char_array_are_equal(){
	char array1[] = {'a','b','c'};
	char array2[] = {'a','b','c'};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_0_if_two_char_array_are_not_equal(){
	char array1[] = {'a','a','c'};
	char array2[] = {'a','b','c'};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),0);
}

void test_areEqual_returns_1_if_two_float_array_are_equal(){
	float array1[] = {1.0,0.2,3.4};
	float array2[] = {1.0,0.2,3.4};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_0_if_two_float_array_are_not_equal(){
	float array1[] = {1.0,1.2,3.4};
	float array2[] = {1.0,0.2,3.4};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),1);
}

void test_create_creates_an_int_array_initializes_with_0(){
	int typeSize = 4,length = 3;
	int arrOf0[3] = {0,0,0};
	ArrayUtil array = create(typeSize,length);
	ArrayUtil array1;
    array1.base = arrOf0;
    array1.typeSize = 4;
    array1.length = 3;
	assertEqual(areEqual(array, array1),1);
}

void test_create_creates_char_array_initializes_with_0(){
	int typeSize = 1,length = 4;
	char arrOf0[4] = {0,0,0,0};
	ArrayUtil array = create(typeSize,length);
	ArrayUtil array1;
	array1.base = arrOf0;
	array1.typeSize = 1;
	array1.length = 4;
	assertEqual(areEqual(array, array1),1);
}

void test_to_create_int_with_array_diffferent_typeSize_initializes_with_0(){
	int typeSize = 3,length = 4,*result;
	ArrayUtil array = create(typeSize,length);
    result=(int*)array.base;
	assertEqual(*result,0);
	assertEqual(*(result+1),0);
	assertEqual(*(result+2),0);
	assertEqual(array.typeSize,3);
}	

void test_to_change_the_length_of_int_array_to_greater_length(){
	int newLength = 5,*num,number[] = {1,2,3,0,0};
	ArrayUtil a1 = create(SIZEOF_INT,3),a3,expected = {number,SIZEOF_INT, 5};
	num = a1.base;
	num[0]=1;num[1]=2,num[2]=3;
	a3 = resize(a1, newLength);
	assertEqual(areEqual(expected,a3),1);
}

void test_to_change_the_length_of_array_to_small_array_length(){
	int newLength = 3,*num;
	int number[] = {1,2,3};
	ArrayUtil a1 = create(SIZEOF_INT,5);
	ArrayUtil a3;
	ArrayUtil expected = {number,sizeof(int), 3};
	num = a1.base;
	num[0]=1;num[1]=2,num[2]=3,num[3]=4,num[4]=5;
	a3 = resize(a1, newLength);
	assert(areEqual(expected,a3));
}

ArrayUtil util, resultUtil, expectedUtil;
int sample[] = {1,2,3,4,5};

int iSEven(void *item, void *hint){
	int *numberPtr = (int*)item;
	return *numberPtr % 2 ? 0 : 1;
}

void increment(void* hint, void* sourceItem, void* destinationItem){
	int *hintPtr = (int*)hint;
	int *numberPtr = (int*)sourceItem;
	int *resultPtr = (int*)destinationItem;

	*resultPtr = *numberPtr + *hintPtr;
}

void toChar(void* hint, void* sourceItem, void* destinationItem){
	int *numberPtr = (int*)sourceItem;
	int *charPtr = (int*)destinationItem;
	*charPtr = *numberPtr;
}


void test_create_should_set_the_length_and_typeSize_fields_of_array_to_the_values_passed_to_create_function(){
	ArrayUtil a = create(1,3);
	assert(a.length == 3);
	assert(a.typeSize == 1);
	dispose(a);
}


void test_resize_should_not_change_length_of_array_when_new_size_is_same_as_old_size(){
	ArrayUtil a = create(1,5);
	int i;
	a = resize(a,5);
	assert(a.length == 5);
	dispose(a);
}

ArrayUtil util,expectedUtil;

void test_array_util_areEqual_returns_0_if_both_array_are_not_equal_in_length_and_elements(){
	int a[]={0,3,8,5,2,3,4,5}, b[]={1,5,2,3,7};
	ArrayUtil a_array = {a,sizeof(int),8};
	ArrayUtil b_array = {b,sizeof(int),5};
	assertEqual(areEqual(a_array, b_array),0);
}

int isLessThanTheHints(void* element,void* hint){
    return (*(float*)element) < (*(float*)hint);

}
void test_findIndex_retruns_the_index_of_an_element_in_an_string_array(){
    char array[]= {"heloo"};
    char element ='o';
    ArrayUtil util = {array,sizeof(char),4};
    assertEqual(findIndex(util,&element),3);
};
void test_for_the_ArrayUtil_for_charecter_and_int_are_not_equal(){
    char first_array[]={'c','d','e','f'};
    int second_array[]={2,5,8,4};
    ArrayUtil array1 = {first_array,sizeof(char),4};
    ArrayUtil array2 = {second_array,sizeof(int),4};
	assertEqual(areEqual(array1, array2),0);
};
ArrayUtil util1,util2;

void test_Create_creates_new_charArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(char[]){0,0,0},CHAR_SIZE,3};
	assertEqual(areEqual(expectedUtil, create(CHAR_SIZE, 2)), 0);
}
void test_Create_creates_new_doubleArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(double[]){0,0},DOUBLE_SIZE,2};
	assertEqual(areEqual(expectedUtil, create(DOUBLE_SIZE, 3)), 0);
}
void test_Create_creates_new_intArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(int[]){0,0,0},INT_SIZE,3};
	assertEqual(areEqual(expectedUtil, create(INT_SIZE, 2)), 0);
}

void test_Create_creates_new_floatArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(float[]){0,0},FLOAT_SIZE,2};
	assertEqual(areEqual(expectedUtil, create(FLOAT_SIZE, 3)), 0);
}

int isGreaterThanHint (void* element, void* hint) {
	return (*((float*)element) > *((float*)hint)) ? 1 : 0;
}


void test_findFirst_gives_occurence_of_first_element_in_floatArray_greaterThan5 (){
	float hint = 5.1;
	float *result;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){3.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	result = (float*)findFirst(util,match,(void*)&hint);
	assertEqual(*result,8.3);
}

void test_findIndex_returns_4_for_float_array_if_search_element_is_at_4th_location (){
	float element = 7.8;
	ArrayUtil util = {(float[]){4.2,2.9,1.4,3.1,7.8,8.7},FLOAT_SIZE,6};
	assertEqual(findIndex(util, &element),4);
}
void test_findLast_gives_occurence_of_last_element_in_floatArray_greaterThan5 (){
	float hint = 5.1;
	float *result;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){7.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	result = (float*)findLast(util,match,&hint);
	assertEqual(*result,8.3);
}

void test_findIndex_will_return_the_minus_1_if_array_element_is_not_present(){
	int array[]={1,2,3,4,5};
	int x=7;
	ArrayUtil arr={array,sizeof(int),5};
	assertEqual(findIndex(arr,&x),-1);
}


void test_create_Structures_with_all_fields_NULL(){
    student temp = {0,0.0};
    student Student[1] = {temp};
    ArrayUtil expected = {Student,sizeof(student),1};
    util1 = create(sizeof(student),1);    
    assert(areEqual(expected,util1));
}

void test_create_allocates_space_for_DOUBLE_array_and_assigns_zero_to_all_bytes(){
	double doubleArray[] = {0,0,0,0};
	expectedUtil = (ArrayUtil){doubleArray,sizeof(double),4};
	util = create(sizeof(double),4);
	assertEqual(areEqual(expectedUtil,util),1);
	dispose(util);
}

void multiplyBy(void* hint, void* sourceItem, void* destinationItem){
    *(int*)destinationItem = *(int*)sourceItem * *(int*)(hint);
}

void test_for_findLast_gives_the_last_element_of_less_than_float_value_an_array(){
    float hint = 6.3;
    float *result;
    MatchFunc *match = &isLessThanTheHints;
    ArrayUtil util = {(float[]){2.3,4.5,6.3,4.5,6.0},sizeof(float),5};
    result = findFirst(util,match,&hint);
    assertEqual(*result,2.3);
};

void test_create_Allocates_space_for_INT_array_and_assigns_zero_to_all_bytes(){
	int intArray[] = {0,0,0,0};
	expectedUtil = (ArrayUtil){intArray,sizeof(int),4};
	util = create(sizeof(int),4);
	assertEqual(areEqual(expectedUtil,util),1);
	dispose(util);
}

void test_map_should_map_source_to_destination_using_the_provided_convert_function(){
	int hint = 1, result[] = {2,3,4,5,6};
	
	util = (ArrayUtil){sample, sizeof(int), 5};
	resultUtil = create(util.typeSize, util.length);
	expectedUtil = (ArrayUtil){result, sizeof(int), 5};

	map(util, resultUtil, increment, &hint);
	
	assert(areEqual(expectedUtil, resultUtil));
	dispose(resultUtil);
}

void test_to_change_the_length_of_char_array_to_grater_length(){
	int newLength = 5;
	char *num;
	char number[] = {'a','b','c',0,0};
	ArrayUtil a1 = create(sizeof(char),3);
	ArrayUtil a3;
	ArrayUtil expected = {number,sizeof(char), 5};
	num = a1.base;
	num[0]='a',num[1]='b',num[2]='c';
	a3 = resize(a1, newLength);
	assert(areEqual(expected,a3));
}

void test_map_converts_each_element_source_array_and_put_it_to_destination_array(){
    int hint =10;
    ArrayUtil expected={(int[]){10,20,30,40,50},sizeof(int),5};
    util1=(ArrayUtil){(int[]){1,2,3,4,5},sizeof(int),5};
    util2 =create(sizeof(int),5);
    
    map(util1,util2,multiplyBy,&hint);
    assert(areEqual(expected, util2));
}

void increment_by_1(void *hint, void *sourceItem, void *destinationItem){
	*(int*)destinationItem = *(int*)sourceItem+1;
}


void test_map_increments_by_one_all_array_elements(){
	void *hint;
	int array[]={1,2,3,4,5};
	int newArray[]={2,3,4,5,6};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={newArray,INT_SIZE,5};
	ArrayUtil mapped={calloc(5,INT_SIZE),INT_SIZE,5};
	map(util,mapped,increment_by_1,hint);
	assert(areEqual(expected, mapped));
}

void square_elements(void *hint, void *sourceItem, void *destinationItem){
	*(int*)destinationItem=*(int*)sourceItem * *(int*)sourceItem;
}



void test_map_returns_square_of_each_element_in_array(){
	void *hint;
	int array[]={1,2,3,4,5};
	int newArray[]={1,4,9,16,25};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={newArray,INT_SIZE,5};
	ArrayUtil mapped={calloc(5,INT_SIZE),INT_SIZE,5};
	map(util,mapped,square_elements,&hint);
	assert(areEqual(expected, mapped));
}

void *add_all(void* hint, void* previousItem, void* item){
	*((int*)item)= *((int*)previousItem) + *((int*)item);
	return ((int*)item);
}


void test_reduce_gives_15_when_elements_are_1_2_3_4_5_and_initial_value_is_0(){
	void *hint;
	int intialValue=0;
	int array[]={1,2,3,4,5};
	ArrayUtil util={array,INT_SIZE,5};
	void *return_value=reduce(util,add_all,&hint,&intialValue);
	assertEqual(*((int*)return_value),15);
}

void test_reduce_gives_30_when_elements_are_1_2_3_4_5_and_initial_value_is_15(){
	void *hint;
	int intialValue=15;
	int array[]={1,2,3,4,5};
	ArrayUtil util={array,INT_SIZE,5};
	void *return_value=reduce(util,add_all,&hint,&intialValue);
	assertEqual(*((int*)return_value),30);
}

void test_areEqual_returns_0_when_length_is_equal_but_typeSize_is_not_equal(){
	int array1[]={1,2,3,4,5};
	char array2[]={'a','b','c','d','\0'};
	ArrayUtil u1={array1,INT_SIZE,5};
	ArrayUtil u2={array2,CHAR_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_create_001(){
	log("returns an ArrayUtil with bytes initialized to ZERO for int");
	ArrayUtil util1 = {array_0_0, sizeOf_int, 2};
	ArrayUtil util2 = create(sizeOf_int, 2);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}

void test_create_002(){
	log("returns an ArrayUtil with bytes initialized to NULL for char");
	ArrayUtil util1 = {array_null_null, sizeOf_char, 2};
	ArrayUtil util2 = create(sizeOf_char, 2);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}

void test_create_003(){
	log("returns an ArrayUtil with bytes initialized to ZERO for float");
	ArrayUtil util1 = {array_flt_flt, sizeOf_float, 2};
	ArrayUtil util2 = create(sizeOf_float, 2);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}

void test_create_004(){
	log("returns an ArrayUtil with bytes initialized to ZERO for double");
	ArrayUtil util1 = {array_dble_dble, sizeOf_double, 2};
	ArrayUtil util2 = create(sizeOf_double, 2);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}

void test_create_007(){
	log("returns an ArrayUtil with bytes initialized to ZERO for float[5]");
	ArrayUtil util1 = {array_float5_0s, sizeOf_float5, 1};
	ArrayUtil util2 = create(sizeOf_float5, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}

void test_create_008(){
	log("returns an ArrayUtil with bytes initialized to ZERO for struct");
	ArrayUtil util1 = {array_Students, sizeOf_Student, 1};
	ArrayUtil util2 = create(sizeOf_Student, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}

void test_create_009(){
	log("returns an ArrayUtil with bytes initialized to ZERO for void *");
	ArrayUtil util1 = {array_void_stars, sizeOf_void_star, 1};
	ArrayUtil util2 = create(sizeOf_void_star, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}

void test_create_010(){
	log("returns an ArrayUtil with bytes initialized to ZERO for char *");
	ArrayUtil util1 = {array_char_stars, sizeOf_char_star, 1};
	ArrayUtil util2 = create(sizeOf_char_star, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}

void test_create_011(){
	log("returns an ArrayUtil with bytes initialized to ZERO for int *");
	ArrayUtil util1 = {array_int_stars, sizeOf_int_star, 1};
	ArrayUtil util2 = create(sizeOf_int_star, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}

void test_forEach_does_multiplication_of_item_with_item_plus_one(){
	void *hint;
	int array[]={1,2,3,4,5};
	int incremented[]={2,6,12,20,30};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={incremented,INT_SIZE,5};
	forEach(util,element_into_element_plus_one,&hint);
	assert(areEqual(util,expected));
}

void test_resize_an_existing_array_to_resize_decrease_its_length(){
    int *resArray;
    ArrayUtil array,resizeArray;
    array = create(sizeof(int),5);
    ((int*)array.base)[0]=90;
    ((int*)array.base)[1]=40;
    ((int*)array.base)[2]=550;
    ((int*)array.base)[3]=550;
    ((int*)array.base)[4]=40;
    resizeArray=resize(array,4);
    resArray = resizeArray.base;
    assertEqual(resArray[2],550);
    assertEqual(areEqual(resizeArray,array),0);
};

void test_resize_an_existing_array_to_resize_increase_its_length(){
    ArrayUtil array = create(sizeof(int),3),resultArray;
    ((int*)array.base)[0]=90;
    ((int*)array.base)[1]=40;
    ((int*)array.base)[2]=550;
    resultArray = resize(array,5);
    assertEqual(((int *)resultArray.base)[0],90);
    assertEqual(((int *)resultArray.base)[1],40);
    assertEqual(((int *)resultArray.base)[2],550);
    assertEqual(((int *)resultArray.base)[3],0);
    assertEqual(((int *)resultArray.base)[4],0);
};

void test_resize_returns_CHAR_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(char []){'a','e','i','o'},sizeof(char),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(char []){'a','e','i','o',0,0},sizeof(char),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

void test_resize_returns_CHAR_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(char []){'a','e','i','o','u'},sizeof(char),5};
	resizedArray = resize(util,2);
	expectedUtil = (ArrayUtil){(char []){'a','e'},sizeof(char),2};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

void test_resize_returns_DOUBLE_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89},sizeof(double),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89,0,0},sizeof(double),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

void test_resize_returns_DOUBLE_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89},sizeof(double),4};
	resizedArray = resize(util,2);
	expectedUtil = (ArrayUtil){(double []){1.0,2.11111},sizeof(double),2};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

void test_resize_returns_FLOAT_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(float []){1.0,2.11111,3.123,4.89},sizeof(float),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(float []){1.0,2.11111,3.123,4.89,0,0},sizeof(float),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

void test_resize_returns_INT_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(int []){1,2,3,4},sizeof(int),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(int []){1,2,3,4,0,0},sizeof(int),6}; 
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

void test_filter_should_filter_those_elements_which_are_matching_given_the_criteria(){
	ArrayUtil array = create(sizeof(int),5);
	int arr[] = {1,2,3,4,5},result,i,expected[] = {2,4};
	void *destination = malloc(5*sizeof(int));
	array.base = arr;
	result = filter(array, isEven, null, &destination, 5);	
	for (i = 0; i < 2; ++i)
	{
		assert(((int*)destination)[i] == expected[i]);
	}
	free(destination);
}

void test_resize_should_grow_length_of_array_and_set_them_to_zero_when_new_size_is_more(){
	ArrayUtil a = create(sizeof(int),2);
	int i;
	a = resize(a,5);
	assert(a.length == 5);
	for (i = 0; i < 20; ++i){
		assert(((char*)a.base)[i] == 0);
	}
	dispose(a);
}

void test_to_change_the_length_of_float_array_to_greater_length(){
	int newLength = 5;
	float *num;
	float number[] = {1.0,0.2,3.0,0,0};
	ArrayUtil a1 = create(sizeof(float),3);
	ArrayUtil a3;
	ArrayUtil expected = {number,sizeof(float), 5};
	num = a1.base;
	num[0]=1.0;num[1]=0.2,num[2]=3.0;
	a3 = resize(a1, newLength);
	assert(areEqual(expected,a3));
}

void test_resize_add_0_to_the_new_places_created_in_integer_array(){
	int array[] = {1,2,3}, arr[] = {1,2,3,0,0};
	ArrayUtil array2, util1 = {array, SIZEOF_INT, 3};
	ArrayUtil expected = {arr, SIZEOF_INT ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}

void test_resize_add_0_to_the_new_places_created_in_float_array(){
	float array[] = {1.1,2.2,3.2}, arr[] = {1.1,2.2,3.2,0.0,0.0};
	ArrayUtil array2, util1 = {array, SIZEOF_FLOAT, 3};
	ArrayUtil expected = {arr, SIZEOF_FLOAT ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}

void test_resize_add_0_to_the_new_places_created_in_char_array(){
	char *array= "abc";
	char arr[] = {'a','b','c',0,0};
	ArrayUtil array2, util1 = {array, SIZEOF_CHAR, 3};
	ArrayUtil expected = {arr, SIZEOF_CHAR ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}

void test_resize_add_0_to_the_new_places_created_in_double_array(){
	double array[] = {1,2,3}, arr[] = {1,2,3,0.0,0.0};
	ArrayUtil array2, util1 = {array, SIZEOF_DOUBLE, 3};
	ArrayUtil expected = {arr, SIZEOF_DOUBLE ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}

void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_putting_0s_in_new_created_spaces(){
    String array1[] = {"Mahesh","Kumar"}, array2[] = {"Mahesh","Kumar",0,0,0};
    ArrayUtil util1 = {array1,sizeof(char *),2};
    ArrayUtil util2 = {array2,sizeof(char *),5};
    assertEqual(areEqual(resize(util1, 5), util2), 1);    
}

void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_removing_extra_values(){
    String array1[] = {"Mahesh","Kumar","Kolla"}, array2[] = {"Mahesh","Kumar"};
    ArrayUtil util1 = {array1,sizeof(char *),3};
    ArrayUtil util2 = {array2,sizeof(char *),2};
    assertEqual(areEqual(resize(util1, 2), util2), 1);    
}

void test_filter_filters_the_util_intArray_which_matches_the_criteria (){
	int hint = 4;
	ArrayUtil util = {(int[]){7,2,6,3,8,9},INT_SIZE,6};
	int *destination = malloc(4*sizeof(int));
	destination = malloc(INT_SIZE*4);
	assertEqual(filter(util,isGreaterThanHint,&hint,&destination,4),4);
	assertEqual(destination[0], 7);
	assertEqual(destination[1], 6);
	assertEqual(destination[2], 8);
	assertEqual(destination[3], 9);
}

void test_create_006(){
	log("returns an ArrayUtil with bytes initialized to ZERO for int[10]");
	ArrayUtil util1 = {array_int10_0s, sizeOf_int10, 1};
	ArrayUtil util2 = create(sizeOf_int10, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}

void test_Create_creates_new_array_of_float_containing_all_elements_0 (){
	ArrayUtil expectedUtil = {(float[]){0,0},FLOAT_SIZE,2};
	assertEqual(areEqual(expectedUtil, create(FLOAT_SIZE, 2)), 1);
}

void test_resize_should_contain_the_initial_array_element(){
	int src[]={5,3},i;
	ArrayUtil util={src,sizeof(int),4},array;
	int* base;
	array = resize(util,15);
	base = (int *)(array.base);
	assertEqual(base[0], 5);
	assertEqual(base[1], 3);
	assertEqual(base[14], 0);
	free(array.base);
}

int isEVen(void *item,void *hint){
	return *((int*)item)%2==0;
}

void test_filter_fills_filtered_array_with_even_numbers_of_existing_array_and_returns_count(){
	int array[]={1,2,3,4,5,6,7,8};
	int newArray[]={2,4,6,8};
	ArrayUtil util={array,INT_SIZE,8};
	int *filtered=(int *)malloc(INT_SIZE*4);
	int counter=filter(util,isEVen,0,(void**)&filtered,4);
 	assertEqual(counter,4);
 	free(filtered);
}

// void test_filter_filters_the_util_floatArray_which_matches_the_criteria (){
// 	float hint = 5.1;
// 	MatchFunc *match = &isGreaterThanHint;
// 	ArrayUtil util = {(float[]){7.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
// 	float *destination = malloc(2*sizeof(float));
// 	destination = malloc(FLOAT_SIZE*2);
// 	assertEqual(filter(util, match,&hint,&destination, 4),2);
// 	assertEqual(destination[0], (float)7.1);
// 	assertEqual(destination[1], (float)8.3);
// }

// void test_filter_returns_0_when_there_are_no_enven_no_in_existing_array(){
// 	int array[]={1,3,5,7};
// 	ArrayUtil util={array,INT_SIZE,4};
// 	int *filtered=(int *)malloc(INT_SIZE*2);
// 	int counter=filter(util,isEven,0,(void**)&filtered,2);
//  	assertEqual(counter,0);
//  	free(filtered);
// }



// void test_filter_populate_destination_array_with_evenNumbers(){
//     int maxItem=6;
//     int *evens[maxItem];
//     util1 = (ArrayUtil){(int[]){101,22,12,13},sizeof(int),4};
// 	assertEqual(filter(util1,isEven,0,(void**)evens,maxItem),2);
// 	assertEqual((evens[0]),22);
// 	assertEqual((evens[1]),12);
// }

// void test_filter_populate_destination_array_until_hits_max_size_and_return_no_element_added_to_id(){
//     int maxItem=2;
//     int *evens [maxItem];
//     util1 = (ArrayUtil){(int[]){101,22,12,14},sizeof(int),4};   	 
// 	assertEqual(filter(util1,isEven,0,(void**)evens,maxItem),2);
// 	assertEqual(*(evens[0]),22);
// 	assertEqual(*(evens[1]),12);    
// }
// void multiplyBy(void* hint, void* sourceItem, void* destinationItem){
//     *(int*)destinationItem = *(int*)sourceItem * *(int*)(hint);
// }

// void test_areEqual_returns_0_when_length_is_equal_but_typeSize_is_not_equal(){
// 	int array1[]={1,2,3,4,5};
// 	char array2[]={'a','b','c','d'};
// 	ArrayUtil u1={array1,INT_SIZE,5};
// 	ArrayUtil u2={array2,CHAR_SIZE,5};
// 	assertEqual(areEqual(u1,u2), 0);
// }

// int is_FloorEven(void* item, void* hint){
// 	double* _item = (double*)item;
// 	int ceil_item = floor(*_item);
// 	return (ceil_item % 2) == 0 ? 1 : 0;
// }
// void test_count_should_count_matched_element_in_DOUBLE_array(){
// 	double array[5] = {99.89,167.88,22.66,36.10,15.47908};
// 	double x = 'a';
// 	ArrayUtil util = create(sizeof(double),5);
// 	util.base = array;
// 	assertEqual(count(util,&is_FloorEven,&x),2);
// 	dispose(util);
// }
