#include <iostream>
using namespace std;
#include "badkan.hpp"
#define COMMA ,
using namespace itertools;

int main(){
    
    badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {


		


        testcase
        .CHECK_EQUAL();






    
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
    
    
    
    
    
    
    return 0;
}