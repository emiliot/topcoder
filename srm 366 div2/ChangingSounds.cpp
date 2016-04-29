// Paste me into the FileEdit configuration dialog

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

int memo[60][1001];
bool mark[60][1001];

int f(vector <int> &v, int high, int i, int volume){
	if(i >= (int)v.size())return volume;
	
	int &best = memo[i][volume];
	if(mark[i][volume])return best;
	mark[i][volume] = true;

	best = -1;
	if(volume + v[i] <= high)best = max(best, f(v, high, i+1, volume + v[i]));
	if(volume - v[i] >= 0)best = max(best, f(v, high, i+1, volume - v[i]));

	return best;
}

class ChangingSounds {
public:
	int maxFinal( vector <int> changeIntervals, int beginLevel, int maxLevel ) {
		memset(mark, false, sizeof(mark));
		int res = f(changeIntervals, maxLevel, 0, beginLevel);
		return res;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
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
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int changeIntervals[]     = {5, 3, 7};
			int beginLevel            = 5;
			int maxLevel              = 10;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = ChangingSounds().maxFinal(vector <int>(changeIntervals, changeIntervals + (sizeof changeIntervals / sizeof changeIntervals[0])), beginLevel, maxLevel);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int changeIntervals[]     = {15, 2, 9, 10};
			int beginLevel            = 8;
			int maxLevel              = 20;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ChangingSounds().maxFinal(vector <int>(changeIntervals, changeIntervals + (sizeof changeIntervals / sizeof changeIntervals[0])), beginLevel, maxLevel);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int changeIntervals[]     = {74,39,127,95,63,140,99,96,154,18,137,162,14,88};
			int beginLevel            = 40;
			int maxLevel              = 243;
			int expected__            = 238;

			clock_t start__           = clock();
			int received__            = ChangingSounds().maxFinal(vector <int>(changeIntervals, changeIntervals + (sizeof changeIntervals / sizeof changeIntervals[0])), beginLevel, maxLevel);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int changeIntervals[]     = ;
			int beginLevel            = ;
			int maxLevel              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ChangingSounds().maxFinal(vector <int>(changeIntervals, changeIntervals + (sizeof changeIntervals / sizeof changeIntervals[0])), beginLevel, maxLevel);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int changeIntervals[]     = ;
			int beginLevel            = ;
			int maxLevel              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ChangingSounds().maxFinal(vector <int>(changeIntervals, changeIntervals + (sizeof changeIntervals / sizeof changeIntervals[0])), beginLevel, maxLevel);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int changeIntervals[]     = ;
			int beginLevel            = ;
			int maxLevel              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ChangingSounds().maxFinal(vector <int>(changeIntervals, changeIntervals + (sizeof changeIntervals / sizeof changeIntervals[0])), beginLevel, maxLevel);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
