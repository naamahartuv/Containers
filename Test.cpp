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
		string s7, s8, s9, s10, s11;

		testcase.setname("range check");								//**range check**

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

				testcase.setname("chain check");							//**chain check**

		for (auto i : itertools::chain(itertools::range(1, 4), itertools::range(5,9)))
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

		for (auto i : itertools::chain(itertools::range(6,11), "8910"))
		{
			s10 += to_string(i);
		}

		for (auto i : itertools::chain(itertools::range(26.1, 28.1), itertools::range(4.6,7.6)))
		{
			s11 += to_string(i);
		}

		

		testcase
			.CHECK_OUTPUT(s7, "1235678")
			.CHECK_OUTPUT(s8, "abchello")
			.CHECK_OUTPUT(s9, "yaelnaama")
			.CHECK_OUTPUT(s10, "6789108910")
			.CHECK_OUTPUT(s11,"26.127.24.65.66.6");
			

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