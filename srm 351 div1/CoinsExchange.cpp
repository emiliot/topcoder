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

class CoinsExchange {
public:
	int countExchanges( int g1, int s1, int b1, int g2, int s2, int b2 ) {
		int res = 0;

		while(g1 < g2){
			if(s1 >= 11){
				res++;
				s1 -= 11;
				g1++;
			}else if(b1 >= 11){
				res++;
				s1++;
				b1 -= 11;
			}else return -1;
		}

		while(s1 < s2){
			if(g1 > g2){
				res++;
				s1 += 9;
				g1--;
			}else if(b1 >= 11){
				res++;
				s1++;
				b1 -= 11;
			}else return -1;
		}

		while(b1 < b2){
			if(s1 > s2){
				res++;
				b1 += 9;
				s1--;
			}else if(g1 > g2){
				res++;
				s1 += 9;
				g1--;
			}else return -1;
		}
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
			int G1                    = 1;
			int S1                    = 0;
			int B1                    = 0;
			int G2                    = 0;
			int S2                    = 0;
			int B2                    = 81;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = CoinsExchange().countExchanges(G1, S1, B1, G2, S2, B2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int G1                    = 1;
			int S1                    = 100;
			int B1                    = 12;
			int G2                    = 5;
			int S2                    = 53;
			int B2                    = 33;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = CoinsExchange().countExchanges(G1, S1, B1, G2, S2, B2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int G1                    = 1;
			int S1                    = 100;
			int B1                    = 12;
			int G2                    = 5;
			int S2                    = 63;
			int B2                    = 33;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CoinsExchange().countExchanges(G1, S1, B1, G2, S2, B2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int G1                    = 5;
			int S1                    = 10;
			int B1                    = 12;
			int G2                    = 3;
			int S2                    = 7;
			int B2                    = 9;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CoinsExchange().countExchanges(G1, S1, B1, G2, S2, B2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int G1                    = ;
			int S1                    = ;
			int B1                    = ;
			int G2                    = ;
			int S2                    = ;
			int B2                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CoinsExchange().countExchanges(G1, S1, B1, G2, S2, B2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int G1                    = ;
			int S1                    = ;
			int B1                    = ;
			int G2                    = ;
			int S2                    = ;
			int B2                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CoinsExchange().countExchanges(G1, S1, B1, G2, S2, B2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int G1                    = ;
			int S1                    = ;
			int B1                    = ;
			int G2                    = ;
			int S2                    = ;
			int B2                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CoinsExchange().countExchanges(G1, S1, B1, G2, S2, B2);
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
