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
const double INF = 100000000.0;
int n;

bool mark[1 << 17];
double memo[1 << 17];

double f(vector <int> &v, vector <int> &w, int mask){
	if(mask == (1 << n) -1){
		return 0.0;
	}
	
	double &best = memo[mask];
	if(mark[mask])return best;
	mark[mask] = true;
	
	best = 0.0;
	
	int sum = 0;
	for(int i=0; i<n; ++i){
		if(!(mask&(1 << i)))sum += w[i];
	}
	double x = (double)(sum + 100);
	double p0;
	//printf("mask %d p0=%lf\n", mask, p0);
	
	for(int i=0; i<n; ++i){
		if(!(mask & (1 << i))){
			double next = (double)(v[i]);
			x = (double)(sum - w[i] + 100);
			
			for(int j=0; j<n; ++j){
				if(i == j)continue;
				if(!(mask & (1 << j))){
					double p = (double)(w[j])/x;
					next += p * f(v, w, mask | (1 << i) | (1 << j));
				}
			}
			
			p0 = 100.0 / x;
			next += p0 * f(v, w, mask | (1 << i));
			best = max(best, next);
			//printf("Debug next=%lf best=%lf\n", next, best);
		}
	}
	
	return best;
}

class BagOfDevouring {
public:
	double expectedYield( vector <int> values, vector <int> weights ) {
		if(values.size() == 0)return 0.0;
		n = (int)values.size();
		
		memset(mark, false, sizeof(mark));
		double res = f(values, weights, 0);
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
			int values[]              = {100,100};
			int weights[]             = {100,100};
			double expected__         = 150.0;

			clock_t start__           = clock();
			double received__         = BagOfDevouring().expectedYield(vector <int>(values, values + (sizeof values / sizeof values[0])), vector <int>(weights, weights + (sizeof weights / sizeof weights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int values[]              = {100,200,300};
			int weights[]             = {100,200,300};
			double expected__         = 462.5;

			clock_t start__           = clock();
			double received__         = BagOfDevouring().expectedYield(vector <int>(values, values + (sizeof values / sizeof values[0])), vector <int>(weights, weights + (sizeof weights / sizeof weights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int values[]              = {100,200,300};
			int weights[]             = {300,200,100};
			double expected__         = 470.8333333333333;

			clock_t start__           = clock();
			double received__         = BagOfDevouring().expectedYield(vector <int>(values, values + (sizeof values / sizeof values[0])), vector <int>(weights, weights + (sizeof weights / sizeof weights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int values[]              = {};
			int weights[]             = {};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = BagOfDevouring().expectedYield(vector <int>(values, values + (sizeof values / sizeof values[0])), vector <int>(weights, weights + (sizeof weights / sizeof weights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int values[]              = {10,100,150,250,500,750,1000,2500,5000,7500,10000};
			int weights[]             = {100,200,300,400,500,1000,2000,1500,3000,6000,4000};
			double expected__         = 20622.364509064962;

			clock_t start__           = clock();
			double received__         = BagOfDevouring().expectedYield(vector <int>(values, values + (sizeof values / sizeof values[0])), vector <int>(weights, weights + (sizeof weights / sizeof weights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int values[]              = ;
			int weights[]             = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = BagOfDevouring().expectedYield(vector <int>(values, values + (sizeof values / sizeof values[0])), vector <int>(weights, weights + (sizeof weights / sizeof weights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int values[]              = ;
			int weights[]             = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = BagOfDevouring().expectedYield(vector <int>(values, values + (sizeof values / sizeof values[0])), vector <int>(weights, weights + (sizeof weights / sizeof weights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int values[]              = ;
			int weights[]             = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = BagOfDevouring().expectedYield(vector <int>(values, values + (sizeof values / sizeof values[0])), vector <int>(weights, weights + (sizeof weights / sizeof weights[0])));
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
