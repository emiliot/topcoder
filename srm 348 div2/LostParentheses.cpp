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
const int INF = 0x3f3f3f3f;

int memo[100][100][2];
bool mark[100][100][2];
int operators[100];

int f(string &s, int low, int high, int m){
	//printf("DEBUG low = %d high = %d m = %d\n" , low, high, m);
	int a, b;
	bool ops = false;
	
	for(int i=low; i<high && !ops; ++i)
		if(s[i] == '+' || s[i] == '-')ops = true;
	
	if(!ops){
		istringstream iss(s.substr(low, high-low));
		iss >> a;
		return a;
	}	
	
	int &best = memo[low][high][m];
	if(mark[low][high][m])return best;
	mark[low][high][m] = true;
	
	best = m == 0?INF: -INF;
	for(int i=low; i<high; ++i){
		if(s[i] == '+'){
			a = f(s, low, i, 0);
			b = f(s, i+1, high, 0);
			if(m == 0)best = min(best, a + b);
			else best = max(best, a+b);
		}else if(s[i] == '-'){
			a = f(s, low, i, 0);
			b = f(s, i+1, high, 1);
			if(m == 0)best = min(best, a-b);
			else best = max(best, a - b);
		}
		//printf("DEBUG low = %d high = % d m = %d best = %d", low, high, m, best);
	}
	return best;
}

class LostParentheses {
public:
	int minResult( string e ) {		
		memset(mark, false, sizeof(mark));
		int res = f(e, 0, (int)e.size(), 0);
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
			string e                  = "55-50+40";
			int expected__            = -35;

			clock_t start__           = clock();
			int received__            = LostParentheses().minResult(e);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string e                  = "10+20+30+40";
			int expected__            = 100;

			clock_t start__           = clock();
			int received__            = LostParentheses().minResult(e);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string e                  = "00009-00009";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = LostParentheses().minResult(e);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string e                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LostParentheses().minResult(e);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			string e                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LostParentheses().minResult(e);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string e                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LostParentheses().minResult(e);
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
