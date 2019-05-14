#include <iostream>
using namespace std;
#include "badkan.hpp"

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"

int main()
{

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0)
	{

		string s1, s2, s3, s4, s5, s6;

		testcase.setname("range check"); //********range check*******

		for (auto i : itertools::range(1, 4))
		{
			s1 += to_string(i);
		}

		for (auto i : itertools::range(10, 20))
		{
			s2 += to_string(i);
		}

		for (auto i : itertools::range('a', 'g'))
		{
			s3 += to_string(i);
		}

		for (auto i : itertools::range(2.6, 8.6))
		{
			s4 += to_string(i);
		}

		for (auto i : itertools::range(3, 4))
		{
			s5 += to_string(i);
		}

		for (auto i : itertools::range(4.6, 7.6))
		{
			s6 += to_string(i);
		}

		testcase
			.CHECK_OUTPUT(s1, "123")
			.CHECK_OUTPUT(s2, "10111213141516171819")
			.CHECK_OUTPUT(s3, "abcdef")
			.CHECK_OUTPUT(s4, "2.63.64.65.66.67.6")
			.CHECK_OUTPUT(s5, "3")
			.CHECK_OUTPUT(s6, "4.65.66.6");

		string s7, s8, s9, s10, s11;

		testcase.setname("chain check"); //*********chain check********

		for (auto i : itertools::chain(itertools::range(1, 4), itertools::range(5, 9)))
		{
			s7 += to_string(i);
		}

		for (auto i : itertools::chain(itertools::range('a', 'd'), "hello"))
		{
			s8 += to_string(i);
		}

		for (auto i : itertools::chain("yael", "naama"))
		{
			s9 += to_string(i);
		}

		for (auto i : itertools::chain(itertools::range(6, 11), "8910"))
		{
			s10 += to_string(i);
		}

		for (auto i : itertools::chain(itertools::range(26.1, 28.1), itertools::range(4.6, 7.6)))
		{
			s11 += to_string(i);
		}

		testcase
			.CHECK_OUTPUT(s7, "1235678")
			.CHECK_OUTPUT(s8, "abchello")
			.CHECK_OUTPUT(s9, "yaelnaama")
			.CHECK_OUTPUT(s10, "6789108910")
			.CHECK_OUTPUT(s11, "26.127.14.65.66.6");

		string s12, s13, s14, s15, s16;

		testcase.setname("zip check"); //**********zip check***********

		for (auto i : itertools::zip(itertools::range(1, 4), itertools::range(5, 8)))
		{
			s12 += to_string(i);
		}

		for (auto i : itertools::zip(itertools::range('a', 'd'), "hel"))
		{
			s13 += to_string(i);
		}

		for (auto i : itertools::zip("yaeli", "naama"))
		{
			s14 += to_string(i);
		}

		for (auto i : itertools::zip(itertools::range(6, 10), "789"))
		{
			s15 += to_string(i);
		}

		for (auto i : itertools::zip(itertools::range(26.1, 28.1), itertools::range(4.6, 6.6)))
		{
			s16 += to_string(i);
		}

		testcase
			.CHECK_OUTPUT(s7, "1,52,63,7")
			.CHECK_OUTPUT(s8, "a,hb,ec,l")
			.CHECK_OUTPUT(s9, "y,na,ae,al,ai,a")
			.CHECK_OUTPUT(s10, "6,77,88,9")
			.CHECK_OUTPUT(s11, "26.1,4.627.1,5.6");

		string s17, s18, s19, s20;

		testcase.setname("product check"); //**********product check***********

		for (auto i : itertools::product(itertools::range(1, 2), itertools::range(5, 6)))
		{
			s17 += to_string(i);
		}

		for (auto i : itertools::product(itertools::range('a', 'c'), "h"))
		{
			s18 += to_string(i);
		}

		for (auto i : itertools::product("yae", "na"))
		{
			s19 += to_string(i);
		}

		for (auto i : itertools::product(itertools::range(6, 7), "78"))
		{
			s20 += to_string(i);
		}

		testcase
			.CHECK_OUTPUT(s7, "1,5")
			.CHECK_OUTPUT(s8, "a,hb,ec,l")
			.CHECK_OUTPUT(s9, "y,ny,aa,na,ae,ne,a")
			.CHECK_OUTPUT(s10, "6,76,8");

		string s21, s22, s23, s24;

		testcase.setname("powerset check"); //**********powerset check***********

		for (auto i : itertools::powerset(itertools::range(1, 3)))
		{
			s21 += to_string(i);
		}

		for (auto i : itertools::powerset(itertools::range('a', 'c'))
		{
			s22 += to_string(i);
		}

		for (auto i : itertools::powerset("ya", "n"))
		{
			s23 += to_string(i);
		}

		for (auto i : itertools::powerset(itertools::range(6, 7), "78"))
		{
			s24 += to_string(i);
		}

		testcase
			.CHECK_OUTPUT(s7, "{}{1}{2}{12}")
			.CHECK_OUTPUT(s8, "{}{a}{b}{ab}")
			.CHECK_OUTPUT(s9, "{}{y}{a}{n}{ya}{yn}{an}{yan}")
			.CHECK_OUTPUT(s10, "{}{6}{7}{8}{67}{68}{78}{678}");

		grade = testcase.grade();
	}
	else
	{
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: " << grade << endl;

	return 0;
}