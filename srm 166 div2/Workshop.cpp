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

class Workshop {
public:
	int pictureFrames( vector <int> pieces ) {
		int a, b, c, res = 0;
		for (int i = 0, n = pieces.size(); i < n; ++i){
			a = pieces[i];
			for (int j = i + 1; j < n; ++j){
				b = pieces[j];
				for (int k = j + 1; k < n; ++k){
					c = pieces[k];
					if (a + b > c && b + c > a && a + c > b)
						res++;
				}
			}
		}
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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			int pieces[]              = {1,2,3,4,5};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Workshop().pictureFrames(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int pieces[]              = {8,5,3};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = Workshop().pictureFrames(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int pieces[]              = {4,23,76,22,87,3,1,99};
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = Workshop().pictureFrames(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int pieces[]              = {10000,9999,9998,9997,9996,1,2,3,4,5};
			int expected__            = 43;

			std::clock_t start__      = std::clock();
			int received__            = Workshop().pictureFrames(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int pieces[]              = {100};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = Workshop().pictureFrames(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int pieces[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Workshop().pictureFrames(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int pieces[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Workshop().pictureFrames(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int pieces[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Workshop().pictureFrames(vector <int>(pieces, pieces + (sizeof pieces / sizeof pieces[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
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
