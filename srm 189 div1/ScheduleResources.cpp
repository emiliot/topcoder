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

int memo[1 << 20];
int sum[1 << 20];

class ScheduleResources {
public:
	int schedule( vector <int> A, vector <int> B ) {
		memset(memo, INF, sizeof(memo));
		
		memo[0] = 0; //empty subset cost 0
		sum[0] = 0;
		for(int k=0, n = (int)A.size(); k < (1 << n); k++){
			for(int i=0; i<n; ++i){
				if(!(k & (1 << i))){
					sum[k | (1 << i)] = sum[k] + A[i];
					int &best = memo[k | (1 << i)];
					best = min(best, max(memo[k], sum[k | (1 << i)]) + B[i]);
					//printf("mask %d best %d\n", k |(1 << i), best);
				}
			}
		}
		return memo[(1 << (int)A.size()) - 1]; 
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
			int A[]                   = {7,6,3};
			int B[]                   = {9,7,3};
			int expected__            = 25;

			clock_t start__           = clock();
			int received__            = ScheduleResources().schedule(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {8,1,6};
			int B[]                   = {1,6,3};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = ScheduleResources().schedule(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int B[]                   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = ScheduleResources().schedule(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {4,5,6};
			int B[]                   = {1,1,6};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = ScheduleResources().schedule(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ScheduleResources().schedule(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ScheduleResources().schedule(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ScheduleResources().schedule(vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
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
