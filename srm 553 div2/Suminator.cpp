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

i64 f(vector <int> &v, int x){
	int aux = 0;
	for(int i=0, n=(int)v.size(); i<n; ++i)
		if(v[i] == -1)v[i] = x, aux = i;
	
	stack <i64> st;
	for(int i=0, n=(int)v.size(); i<n; ++i){
		if(v[i] == 0){
			i64 a = st.empty()? 0 : st.top();
			if(!st.empty())st.pop();
			i64 b = st.empty()? 0 : st.top();
			if(!st.empty())st.pop();

			st.push(a + b);
		}else{
			st.push(v[i]);
		}
	}

	v[aux] = -1;
	return st.top();
}

class Suminator {
public:
	int findMissing( vector <int> program, int wantedResult ) {
		int low = 0, high = 1000000001; i64 r = wantedResult;
		int res = -1;
		if(f(program, 0) == r)return 0;
		
		while(high - low > 1){
			int mid = (low + high)/2;
			//printf("%d %d %d\n", low, high, mid);
			i64 next = f(program, mid);
			
			if(next > r)high = mid;
			else if(next == r)high = mid, res = mid;
			else low = mid + 1;
		}
		if(f(program, low) == r)return low;
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
			int program[]             = {7,-1,0};
			int wantedResult          = 10;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Suminator().findMissing(vector <int>(program, program + (sizeof program / sizeof program[0])), wantedResult);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int program[]             = {100, 200, 300, 0, 100, -1};
			int wantedResult          = 600;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Suminator().findMissing(vector <int>(program, program + (sizeof program / sizeof program[0])), wantedResult);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int program[]             = {-1, 7, 3, 0, 1, 2, 0, 0};
			int wantedResult          = 13;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Suminator().findMissing(vector <int>(program, program + (sizeof program / sizeof program[0])), wantedResult);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int program[]             = {-1, 8, 4, 0, 1, 2, 0, 0};
			int wantedResult          = 16;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = Suminator().findMissing(vector <int>(program, program + (sizeof program / sizeof program[0])), wantedResult);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int program[]             = {1000000000, 1000000000, 1000000000, 1000000000, -1, 0, 0, 0, 0};
			int wantedResult          = 1000000000;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = Suminator().findMissing(vector <int>(program, program + (sizeof program / sizeof program[0])), wantedResult);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int program[]             = {7, -1, 3, 0};
			int wantedResult          = 3;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = Suminator().findMissing(vector <int>(program, program + (sizeof program / sizeof program[0])), wantedResult);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			int program[]             = {315291978, -1, 0, 55598902, 0};
			int wantedResult          = 703034801;
			int expected__            = 332143921;

			clock_t start__           = clock();
			int received__            = Suminator().findMissing(vector <int>(program, program + (sizeof program / sizeof program[0])), wantedResult);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int program[]             = ;
			int wantedResult          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Suminator().findMissing(vector <int>(program, program + (sizeof program / sizeof program[0])), wantedResult);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int program[]             = ;
			int wantedResult          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Suminator().findMissing(vector <int>(program, program + (sizeof program / sizeof program[0])), wantedResult);
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
