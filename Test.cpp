#include <iostream>
#include <sstream>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
#define COMMA ,
using namespace itertools;

int main(){
    
    badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		string s1, s2, s3, s4, s5;

        testcase.setname("range check"); 

		for(auto i : range(1,4)){
			s += i;
		}






    
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
    
    
    
    
    
    
    return 0;
}