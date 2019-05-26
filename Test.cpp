
#include <iostream>

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
#include "iostream"

using namespace std;
using namespace itertools;

template<typename Iterable>
string iterable_to_string( Iterable& iterable) {
    ostringstream ostr;
    for (decltype(*iterable.begin()) i: iterable)
        ostr << i << ",";
    return ostr.str();
}
int main() {
    badkan::TestCase testcase;
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {

        
        //rang check
        itertools::rangeClass<int> s1(1, 4);
		itertools::rangeClass<int> s2(10, 20);
		itertools::rangeClass<char> s3('a', 'g');
		itertools::rangeClass<double> s4(2.6, 8.6);
		itertools::rangeClass<int> s5(3, 4);
		itertools::rangeClass<double> s6(4.6, 7.6);
		itertools::rangeClass<char> s7('a', 'd');

        //chain check
        itertools::chainClass<itertools::rangeClass<int>, itertools::rangeClass<int>> s8(s1, s2);
		itertools::chainClass<itertools::rangeClass<char>, string> s9(s7, (string) "hello");
		itertools::chainClass<string, string> s10((string) "yael", (string) "naama");
		itertools::chainClass<itertools::rangeClass<double>, itertools::rangeClass<double>> s11(s4, s6);

        //zip check
        itertools::zipClass<itertools::rangeClass<int>, string> s12(s1, "567");
        itertools::zipClass<itertools::rangeClass<double>, string> s13(s6, "hel");
        itertools::zipClass<string, string> s14("abc", "xyz");
        itertools::zipClass<itertools::zipClass<itertools::rangeClass<int>, string>, itertools::zipClass<itertools::rangeClass<double>, string>> s15(s12, s13);

        //product check
        itertools::productClass<itertools::rangeClass<int>, itertools::rangeClass<int>> s16(s1, s5);
        itertools::productClass<itertools::rangeClass<char>, string> s17(s7, "h");
        itertools::productClass<string, string> s18("yae", "na");
        itertools::productClass<itertools::rangeClass<int>, string> s19(s5, "78");


        //powerset check
        itertools::powersetClass<itertools::rangeClass<int>> s20(s1);
		itertools::powersetClass<itertools::rangeClass<char>> s21(s7);
		itertools::powersetClass<string> s22("xyz");


		//***********output check******************
        testcase.setname("range")
                
			.CHECK_OUTPUT(iterable_to_string(s1),("1,2,3,") )
			.CHECK_OUTPUT(iterable_to_string(s2), ("10,11,12,13,14,15,16,17,18,19,"))
			.CHECK_OUTPUT(iterable_to_string(s3), ("a,b,c,d,e,f,"))
			.CHECK_OUTPUT(iterable_to_string(s4), ("2.6,3.6,4.6,5.6,6.6,7.6,"))
			.CHECK_OUTPUT(iterable_to_string(s5), ("3,"))
			.CHECK_OUTPUT(iterable_to_string(s6), ("4.6,5.6,6.6,"));

                

        testcase.setname("chain")
            .CHECK_OUTPUT(iterable_to_string(s8), ("1,2,3,10,11,12,13,14,15,16,17,18,19,"))
			.CHECK_OUTPUT(iterable_to_string(s9), ("a,b,c,h,e,l,l,o,"))
			.CHECK_OUTPUT(iterable_to_string(s10), ("y,a,e,l,n,a,a,m,a,"))
			.CHECK_OUTPUT(iterable_to_string(s11), ("2.6,3.6,4.6,5.6,6.6,7.6,4.6,5.6,6.6,"));
                ;

        testcase.setname("zip")
            .CHECK_OUTPUT(iterable_to_string(s12), ("1,5,2,6,3,7,"))
			.CHECK_OUTPUT(iterable_to_string(s13), ("4.6,h,5.6,e,6.6,l,"))
			.CHECK_OUTPUT(iterable_to_string(s14), ("a,x,b,y,c,z,"))
			.CHECK_OUTPUT(iterable_to_string(s15), ("1,5,4.6,h,2,6,5.6,e,3,7,6.6,l,"));
                

        testcase.setname("product")
            .CHECK_OUTPUT(iterable_to_string(s16), ("1,3,2,3,3,3,"))
			.CHECK_OUTPUT(iterable_to_string(s17), ("a,h,b,h,c,h,"))
			.CHECK_OUTPUT(iterable_to_string(s18), ("y,n,y,a,a,n,a,a,e,n,e,a,"))
			.CHECK_OUTPUT(iterable_to_string(s19), ("3,7,3,8,"));

                
        testcase.setname("powerset")
            .CHECK_OUTPUT(iterable_to_string(s20), ("{},{1},{2},{3},{12},{13},{23},{123},"))
			.CHECK_OUTPUT(iterable_to_string(s21), ("{},{a},{b},{c},{ab},{ac},{bc},{abc},"))
			.CHECK_OUTPUT(iterable_to_string(s22), ("{},{x},{y},{z},{xy},{xz},{yz},{xyz},"));
                

        grade = testcase.grade();
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: " << grade << endl;
    return 0;
}
