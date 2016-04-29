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

int memo[60][60];
bool mark[60][60];
vector <int> v;
int n;

int f(int a, int b){
	if(a > b)return 0;
	
	int &best = memo[a][b];
	if(mark[a][b])return best;
	mark[a][b] = true;
	
	best = 0;
	int total = 0;
	for(int i=a; i<=b; ++i)total+=v[i];
	
	for(int i=a; i<=b; ++i){
		int na = f(a, i-1);
		int nb = f(i+1, b);
		
		best = max(best, total - na - nb);
	}
	return best;
}

class PickGuitars {
public:
	int maxValue( vector <int> guitarValues ) {
		int sum = 0;
		n = (int)guitarValues.size();
		
		for(int i=0; i<n; ++i){
			sum += guitarValues[i];
		}
		
		int best = 0;
		v.resize(n-1);
		
		for(int i=0; i<n; ++i){
			memset(mark,false, sizeof(mark));
			
			for(int j=(i+1)%n, k=0; k<n-1; ++k, j = (j + 1)% n){
				v[k] = guitarValues[j];
			}
			
			int next = f(0, n-2);
			best = max(best, sum - next);
		}
		
		return best;
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
			int guitarValues[]        = {1,5,3,4,5};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = PickGuitars().maxValue(vector <int>(guitarValues, guitarValues + (sizeof guitarValues / sizeof guitarValues[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int guitarValues[]        = {4,8,4};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = PickGuitars().maxValue(vector <int>(guitarValues, guitarValues + (sizeof guitarValues / sizeof guitarValues[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int guitarValues[]        = {2,1,4,1,2,1,8,1};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = PickGuitars().maxValue(vector <int>(guitarValues, guitarValues + (sizeof guitarValues / sizeof guitarValues[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int guitarValues[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PickGuitars().maxValue(vector <int>(guitarValues, guitarValues + (sizeof guitarValues / sizeof guitarValues[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int guitarValues[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PickGuitars().maxValue(vector <int>(guitarValues, guitarValues + (sizeof guitarValues / sizeof guitarValues[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int guitarValues[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PickGuitars().maxValue(vector <int>(guitarValues, guitarValues + (sizeof guitarValues / sizeof guitarValues[0])));
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
