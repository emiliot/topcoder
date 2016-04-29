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

class IncreasingSubsequences {
public:
	long long count( vector <int> a ) {
		vector <i64> end(a.size(), 0);
		end[0] = 1LL;

		//count how many sequences end in i
		for(int i=1, n=(int)a.size(); i<n; ++i){
			i64 sum = 0LL;
			for(int j=i-1, k = 0; j>=0; --j){
				if(a[j] < a[i] && a[j] > k){
					k = a[j];
					sum += end[j];
				}
			}
			
			if(sum == 0LL)end[i] = 1LL;
			else end[i] = sum;
		}

		//count all the sequences that end in i and keep the condition
		//the last element must be the highest in the segment a[i...n]
		i64 res = 0LL;
		for(int i=(int)end.size()-1, k=0; i>=0; --i){
			if(a[i] > k){
				k = a[i];
				res += end[i];
			}
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int a[]                   = {1,3,2,6,4,5};
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = IncreasingSubsequences().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {1000000000,100000000,10000000,1000000,100000,10000,1000,100,10,1};
			long long expected__      = 10;

			clock_t start__           = clock();
			long long received__      = IncreasingSubsequences().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = IncreasingSubsequences().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {564,234,34,4365,424,2234,306,21,934,592,195,2395,2396,29345,13295423,23945,2};
			long long expected__      = 41;

			clock_t start__           = clock();
			long long received__      = IncreasingSubsequences().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int a[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = IncreasingSubsequences().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int a[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = IncreasingSubsequences().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = IncreasingSubsequences().count(vector <int>(a, a + (sizeof a / sizeof a[0])));
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
