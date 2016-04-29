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

bool mark[51][2600][2];
double memo[51][2600][2];

int n, high, least, s;

double f(int i, int sum, int flag){
	if(i >= n){
		return sum >= s && flag? 1.0 : 0.0;
	}

	double &count = memo[i][sum][flag];
	if(mark[i][sum][flag])return count;
	mark[i][sum][flag] = true;
	count = 0.0;

	double p = 1.0 / (double)(high);
	for(int k=1; k<=high; ++k){
		count += p * f(i+1, sum + k, flag || k == least);
	}

	return count;
}

class Conditional {
public:
	double probability( int nDice, int maxSide, int v, int theSum ) {
		memset(mark, false, sizeof(mark));
		n = nDice, high = maxSide, least = v, s = theSum;
		double res = f(0, 0, 0);
		double pall = 1.0 - pow((double)(high-1)/(double)(high), (double)(n)); 
		return res/pall;
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
	
	bool isinf(const double x) { return !_finite(x); }
	bool isnan(const double x) { return _isnan(x); }
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int nDice                 = 2;
			int maxSide               = 6;
			int v                     = 6;
			int theSum                = 12;
			double expected__         = 0.09090909090909091;

			clock_t start__           = clock();
			double received__         = Conditional().probability(nDice, maxSide, v, theSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int nDice                 = 2;
			int maxSide               = 6;
			int v                     = 6;
			int theSum                = 6;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = Conditional().probability(nDice, maxSide, v, theSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int nDice                 = 1;
			int maxSide               = 9;
			int v                     = 3;
			int theSum                = 3;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = Conditional().probability(nDice, maxSide, v, theSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int nDice                 = 2;
			int maxSide               = 3;
			int v                     = 2;
			int theSum                = 4;
			double expected__         = 0.6;

			clock_t start__           = clock();
			double received__         = Conditional().probability(nDice, maxSide, v, theSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int nDice                 = ;
			int maxSide               = ;
			int v                     = ;
			int theSum                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = Conditional().probability(nDice, maxSide, v, theSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int nDice                 = ;
			int maxSide               = ;
			int v                     = ;
			int theSum                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = Conditional().probability(nDice, maxSide, v, theSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int nDice                 = ;
			int maxSide               = ;
			int v                     = ;
			int theSum                = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = Conditional().probability(nDice, maxSide, v, theSum);
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
