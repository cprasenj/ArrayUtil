#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_areEqual_returns_negative_if_array_lengths_are_different,test_areEqual_returns_1_if_array_lengths_are_same_and_values_are_same,test_areEqual_returns_0_if_array_lengths_are_same_and_values_are_different,test_isEqual_returns_1_if_array_lengths_are_same_and_values_are_same_for_char,test_creates_returns_1_if_array_lengths_are_same_and_values_are_same,test_resize_returns_1_if_array_lengths_are_same_and_values_are_same,test_indexof_returns_negative_1_if_element_if_element_not_found,test_indexof_returns_0_if_element_if_element_is_in_0_position,test_indexof_returns_0_if_float_element_is_in_0_position,test_indexof_returns_0_if_char_element_is_in_0_position,test_findFirst_returns_null_if_there_is_no_match,test_findFirst_returns_position_if_there_is_match_found,test_findList_returns_positions_if_there_is_match_found,test_findList_returns_count_of_match_there_is_match_found,test_findList_returns_negative_if_there_is_no_match_found,test_filter_gives_2_4_for_1_2_3_4_5,test_map_gives_2_3_4_5_6_for_1_2_3_4_5,test_forEach_gives_2_3_4_5_6_for_1_2_3_4_5_in_same_array,test_reduce_gives_20_for_1_2_3_4_5_in_same_array;
Test test[] = {"test_areEqual_returns_negative_if_array_lengths_are_different",test_areEqual_returns_negative_if_array_lengths_are_different,"test_areEqual_returns_1_if_array_lengths_are_same_and_values_are_same",test_areEqual_returns_1_if_array_lengths_are_same_and_values_are_same,"test_areEqual_returns_0_if_array_lengths_are_same_and_values_are_different",test_areEqual_returns_0_if_array_lengths_are_same_and_values_are_different,"test_isEqual_returns_1_if_array_lengths_are_same_and_values_are_same_for_char",test_isEqual_returns_1_if_array_lengths_are_same_and_values_are_same_for_char,"test_creates_returns_1_if_array_lengths_are_same_and_values_are_same",test_creates_returns_1_if_array_lengths_are_same_and_values_are_same,"test_resize_returns_1_if_array_lengths_are_same_and_values_are_same",test_resize_returns_1_if_array_lengths_are_same_and_values_are_same,"test_indexof_returns_negative_1_if_element_if_element_not_found",test_indexof_returns_negative_1_if_element_if_element_not_found,"test_indexof_returns_0_if_element_if_element_is_in_0_position",test_indexof_returns_0_if_element_if_element_is_in_0_position,"test_indexof_returns_0_if_float_element_is_in_0_position",test_indexof_returns_0_if_float_element_is_in_0_position,"test_indexof_returns_0_if_char_element_is_in_0_position",test_indexof_returns_0_if_char_element_is_in_0_position,"test_findFirst_returns_null_if_there_is_no_match",test_findFirst_returns_null_if_there_is_no_match,"test_findFirst_returns_position_if_there_is_match_found",test_findFirst_returns_position_if_there_is_match_found,"test_findList_returns_positions_if_there_is_match_found",test_findList_returns_positions_if_there_is_match_found,"test_findList_returns_count_of_match_there_is_match_found",test_findList_returns_count_of_match_there_is_match_found,"test_findList_returns_negative_if_there_is_no_match_found",test_findList_returns_negative_if_there_is_no_match_found,"test_filter_gives_2_4_for_1_2_3_4_5",test_filter_gives_2_4_for_1_2_3_4_5,"test_map_gives_2_3_4_5_6_for_1_2_3_4_5",test_map_gives_2_3_4_5_6_for_1_2_3_4_5,"test_forEach_gives_2_3_4_5_6_for_1_2_3_4_5_in_same_array",test_forEach_gives_2_3_4_5_6_for_1_2_3_4_5_in_same_array,"test_reduce_gives_20_for_1_2_3_4_5_in_same_array",test_reduce_gives_20_for_1_2_3_4_5_in_same_array};
char testFileName[] = {"arrayutilTest.c"};
void _setup(){/*CALL_SETUP*/}
void _teardown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("**  %s\n",name);
	_setup();
		test();
	_teardown();
	if(!currentTestFailed) passCount++;	
}
int main(int argc, char const *argv[]){		
	int i,total = sizeof(test)/sizeof(Test);	
	fixtureSetup();
	testCount=0,passCount=0;
	printf("**------ %s ------\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);	
	printf("** Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();	
	return 0;
}