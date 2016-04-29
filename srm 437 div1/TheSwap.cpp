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

int getNum(vector <int> &v){
	int res = 0;
	for(int i=0, n=(int)v.size(); i<n; ++i){
		(res *=10)+= v[i];
	}
	return res;
}

map < pair<int, int> , int> memo;

int f(vector <int> &v, int k){
	int next = -1;
	if(k <= 0){
		next = getNum(v);
		return next;
	}
	
	map< pair <int, int> , int>::iterator it = memo.find( pair <int, int>(getNum(v), k));
	if(it != memo.end())return it->second;
	
	for(int i=0, n=(int)v.size(); i<n-1; ++i){
		for(int j=i+1; j<n; ++j){
			if(i > 0 || (i == 0 && v[j] != 0)){
				swap(v[i], v[j]);
				next = max(next, f(v, k-1));
				swap(v[i], v[j]);
			}
		}
	}
	
	memo[ pair <int, int> (getNum(v), k) ] = next;
	return next;
}

class TheSwap {
public:
	int findMax( int n, int k ) {
		vector <int> v;
		for(int w=n; w>0; w/=10){
			v.push_back(w%10);
		}
		reverse(all(v));
		memo.clear();
		int res = f(v, k);
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
			int n                     = 16375;
			int k                     = 1;
			int expected__            = 76315;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 432;
			int k                     = 1;
			int expected__            = 423;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 90;
			int k                     = 4;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 5;
			int k                     = 2;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 436659;
			int k                     = 2;
			int expected__            = 966354;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int n                     = 900757;
			int k                     = 9;
			int expected__            = 977500;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheSwap().findMax(n, k);
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
