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

class RadarFinder {
public:
	int possibleLocations( int x1, int y1, int r1, int x2, int y2, int r2 ) {
		//two radars at same location
		if(x1 == x2 && y1 == y2){
			if(r1 == r2)return -1;
			else return 0;
		}

		i64 distance = ((i64)(x1 - x2) * (i64)(x1 - x2)) + ((i64)(y1-y2) * (i64)(y1 - y2));
		i64 radarP = ((i64)(r1) * (i64)(r1)) + (2 * (i64)(r1) * (i64)(r2)) + ((i64)(r2) * (i64)(r2));
		i64 radarM = ((i64)(r1) * (i64)(r1)) - (2 * (i64)(r1) * (i64)(r2)) + ((i64)(r2) * (i64)(r2));

		if(distance < radarM)return 0;
		if(distance == radarM)return 1;
		if(distance > radarM && distance < radarP)return 2;
		if(distance == radarP)return 1;
		if(distance > radarP)return 0;
		
		return 3;
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
			int x1                    = 0;
			int y1                    = 0;
			int r1                    = 13;
			int x2                    = 40;
			int y2                    = 0;
			int r2                    = 37;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = RadarFinder().possibleLocations(x1, y1, r1, x2, y2, r2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x1                    = 0;
			int y1                    = 0;
			int r1                    = 3;
			int x2                    = 0;
			int y2                    = 7;
			int r2                    = 4;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = RadarFinder().possibleLocations(x1, y1, r1, x2, y2, r2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x1                    = 0;
			int y1                    = 0;
			int r1                    = 5;
			int x2                    = 10;
			int y2                    = 10;
			int r2                    = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = RadarFinder().possibleLocations(x1, y1, r1, x2, y2, r2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x1                    = 0;
			int y1                    = 0;
			int r1                    = 1;
			int x2                    = 0;
			int y2                    = 0;
			int r2                    = 1;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = RadarFinder().possibleLocations(x1, y1, r1, x2, y2, r2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int x1                    = 0;
			int y1                    = 0;
			int r1                    = 5;
			int x2                    = 1;
			int y2                    = 0;
			int r2                    = 4;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = RadarFinder().possibleLocations(x1, y1, r1, x2, y2, r2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int x1                    = ;
			int y1                    = ;
			int r1                    = ;
			int x2                    = ;
			int y2                    = ;
			int r2                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RadarFinder().possibleLocations(x1, y1, r1, x2, y2, r2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x1                    = ;
			int y1                    = ;
			int r1                    = ;
			int x2                    = ;
			int y2                    = ;
			int r2                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RadarFinder().possibleLocations(x1, y1, r1, x2, y2, r2);
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
