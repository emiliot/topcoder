// BEGIN CUT HERE
#pragma warning(disable:4018)  // signed/unsigned mistatch
#pragma warning(disable:4244)  // w64 to int cast
#pragma warning(disable:4267)  // big to small -- possible loss of data
#pragma warning(disable:4786)  // long identifiers
#pragma warning(disable:4800)  // forcing int to bool
#pragma warning(disable:4996)  // deprecations
// END CUT HERE
#include "assert.h"
#include "ctype.h"
#include "float.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdarg.h"
#include "time.h"
#include "algorithm"
#include "numeric"
#include "functional"
#include "utility"
#include "bitset"
#include "vector"
#include "list"
#include "set"
#include "map"
#include "queue"
#include "stack"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

#define all(v) (v).begin(), (v).end()
typedef long long i64;
template <class T> void make_unique(T& v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}

bool func(const pair <int, int> &a, const pair <int, int> &b){
	if (a.first < b.first)return true;
	else if (a.first > b.first)return false;
	else return a < b;
}

class BinaryCardinality {
public:

	int toBin(int n){
		int res = 0, k = n;
		while (k > 0){
			if (k & 1)
				res++;
			k >>= 1;
		}
		return res;
	}

	vector <int> arrange( vector <int> numbers ) {
		vector < pair < int, int> >v(numbers.size());
		for (int i = 0, n = numbers.size(); i < n; ++i){
			v[i].second = numbers[i];
			v[i].first = toBin(numbers[i]);
		}

		sort(all(v),func);

		vector<int> res(numbers.size());
		for (int i = 0, n = numbers.size(); i < n; ++i)
			res[i] = v[i].second;
		return res;
	}
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int numbers[]             = {4};
			int expected__[]          = { 4 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BinaryCardinality().arrange(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int numbers[]             = {31,15,7,3,2};
			int expected__[]          = { 2, 3, 7, 15, 31 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BinaryCardinality().arrange(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int numbers[]             = {10,9,8,7,6,5,4,3,2,1};
			int expected__[]          = { 1, 2, 4, 8, 3, 5, 6, 9, 10, 7 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BinaryCardinality().arrange(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int numbers[]             = {811385,340578,980086,545001,774872,855585,13848,863414,419523,190151,784903,127461};
			int expected__[]          = { 13848, 340578, 545001, 855585, 419523, 811385, 127461, 190151, 774872, 863414, 784903, 980086 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = BinaryCardinality().arrange(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int numbers[]             = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = BinaryCardinality().arrange(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int numbers[]             = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = BinaryCardinality().arrange(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int numbers[]             = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = BinaryCardinality().arrange(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
