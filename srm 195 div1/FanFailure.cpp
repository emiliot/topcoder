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

int memo[51][50001];
bool mark[51][50001];

const int INF = 0x3f3f3f3f;

int f(vector <int> &v, int low, int i, int cap){
	if(i >= (int)v.size()){
		return 0;
	}
	
	int &best = memo[i][cap];
	if(mark[i][cap])return best;
	mark[i][cap] = true;
	
	best = f(v, low, i+1, cap);
	if(cap - v[i] >= low){
		best = max(best, f(v, low, i+1, cap - v[i]) + 1);
	}
	
	return best;
}

int g(vector <int> &v, int low, int i, int cap){
	if(i >= (int)v.size()){
		if(cap < low)return 0;
		else return INF;
	}
	
	int &best = memo[i][cap];
	if(mark[i][cap])return best;
	mark[i][cap] = true;
	
	best = g(v, low, i+1, cap);
	best = min(best, g(v, low, i+1, cap - v[i]) + 1);
	
	return best;
}

class FanFailure {
public:
	vector <int> getRange( vector <int> capacities, int minCooling ) {
		vector <int> res(2, 0);
		int cap = 0;
		for(int i=0, n=capacities.size(); i<n; ++i)
			cap += capacities[i];
		
		memset(mark, false, sizeof(mark));
		res[0] = f(capacities, minCooling, 0, cap);
		
		memset(mark, false, sizeof(mark));
		res[1] = g(capacities, minCooling, 0, cap)-1;
		
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int capacities[]          = {1,2,3};
			int minCooling            = 2;
			int expected__[]          = { 2, 1 };

			clock_t start__           = clock();
			vector <int> received__   = FanFailure().getRange(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), minCooling);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int capacities[]          = {8,5,6,7};
			int minCooling            = 22;
			int expected__[]          = { 0, 0 };

			clock_t start__           = clock();
			vector <int> received__   = FanFailure().getRange(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), minCooling);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int capacities[]          = {676, 11, 223, 413, 823, 122, 547, 187, 28};
			int minCooling            = 1000;
			int expected__[]          = { 7, 2 };

			clock_t start__           = clock();
			vector <int> received__   = FanFailure().getRange(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), minCooling);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int capacities[]          = {955, 96, 161, 259, 642, 242, 772, 369, 311, 785, 92, 991, 620, 394, 128, 774, 973, 94, 681, 771, 916, 373, 523, 100, 220, 993, 472, 798, 132, 361, 33, 362, 573, 624, 722, 520, 451, 231, 37, 921, 408, 170, 303, 559, 866, 412, 339, 757, 822, 192};
			int minCooling            = 3619;
			int expected__[]          = { 46, 30 };

			clock_t start__           = clock();
			vector <int> received__   = FanFailure().getRange(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), minCooling);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int capacities[]          = ;
			int minCooling            = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = FanFailure().getRange(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), minCooling);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int capacities[]          = ;
			int minCooling            = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = FanFailure().getRange(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), minCooling);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int capacities[]          = ;
			int minCooling            = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = FanFailure().getRange(vector <int>(capacities, capacities + (sizeof capacities / sizeof capacities[0])), minCooling);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
