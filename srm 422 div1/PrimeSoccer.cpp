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

bool primes[19] = {false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false};
bool mark[19][19][19];
double memo[19][19][19];

double f(int k, double p1, double p2, int a, int b){
	if(k >= 18){
		if(primes[a] || primes[b])return 1.0;
		else return 0.0;
	}
	
	double &count = memo[k][a][b];;
	if(mark[k][a][b])return count;
	mark[k][a][b] = true;
	
	count = p1 * p2 * f(k+1, p1, p2, a+1, b+1);
	count += p1 * (1.0 - p2) * f(k+1, p1, p2, a+1, b);
	count += p2 * (1.0 - p1) * f(k+1, p1, p2, a, b+1);
	count += (1.0 - p1) * (1.0 - p2) * f(k+1, p1, p2, a, b);
	
	return count;
}

class PrimeSoccer {
public:
	double getProbability( int skillOfTeamA, int skillOfTeamB ) {
		memset(mark, false, sizeof(mark));
		double res = f(0, (double)skillOfTeamA/100.0, (double)skillOfTeamB/100.0, 0, 0);
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
			int skillOfTeamA          = 50;
			int skillOfTeamB          = 50;
			double expected__         = 0.5265618908306351;

			clock_t start__           = clock();
			double received__         = PrimeSoccer().getProbability(skillOfTeamA, skillOfTeamB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int skillOfTeamA          = 100;
			int skillOfTeamB          = 100;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = PrimeSoccer().getProbability(skillOfTeamA, skillOfTeamB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int skillOfTeamA          = 12;
			int skillOfTeamB          = 89;
			double expected__         = 0.6772047168840167;

			clock_t start__           = clock();
			double received__         = PrimeSoccer().getProbability(skillOfTeamA, skillOfTeamB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int skillOfTeamA          = ;
			int skillOfTeamB          = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PrimeSoccer().getProbability(skillOfTeamA, skillOfTeamB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int skillOfTeamA          = ;
			int skillOfTeamB          = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PrimeSoccer().getProbability(skillOfTeamA, skillOfTeamB);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int skillOfTeamA          = ;
			int skillOfTeamB          = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PrimeSoccer().getProbability(skillOfTeamA, skillOfTeamB);
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
