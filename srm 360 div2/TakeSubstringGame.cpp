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

bool memo[1000001];

class TakeSubstringGame {
public:
	int winningMove( int n ) {
		//if the number has only one digit, no one can win
		for(int i=0; i<10; ++i)memo[i] = false;
		
		int best = 0x3f3f3f3f;
		vector <int> v;
		v.reserve(100);

		for(int i=10; i<=n; ++i){
			memo[i] = false;
			int w = i;

			v.clear();
			do{
				v.push_back(w%10);
				w/=10;
			}while(w > 0);

			reverse(all(v));
			
			for(int m=1, k=(int)v.size(); m<k; ++m){
				for(int j=0; j<k-m+1; ++j){
					int next = 0;
					for(int w=j; w<j+m; ++w)
						(next *= 10) += v[w];
					
					
					if(next <=0 || next >= i)continue;
					if(!memo[i - next]){
						memo[i] = true;
						if(i == n)
							best = min(best, next);
					}
				}
			}
		}

		if(memo[n])return best;
		else return -1;
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
			int n                     = 5;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TakeSubstringGame().winningMove(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 10;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TakeSubstringGame().winningMove(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 17;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TakeSubstringGame().winningMove(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 239;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = TakeSubstringGame().winningMove(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 566;
			int expected__            = 66;

			clock_t start__           = clock();
			int received__            = TakeSubstringGame().winningMove(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 398765;
			int expected__            = 8765;

			clock_t start__           = clock();
			int received__            = TakeSubstringGame().winningMove(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			int n                     = 1000000;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TakeSubstringGame().winningMove(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TakeSubstringGame().winningMove(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TakeSubstringGame().winningMove(n);
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
