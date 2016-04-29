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

struct car{
	int init, tax, e;
	double total;
	bool operator <(const car &other)const{
		return total < other.total;
	}
};

class CarBuyer {
public:
	double lowestCost( vector <string> cars, int fuelPrice, int annualDistance, int years ) {
		vector < car > v(cars.size());
		for(int i=0, n=(int)cars.size(); i<n; ++i){
			istringstream iss(cars[i]);
			iss >> v[i].init >> v[i].tax >> v[i].e;
			v[i].total = (double)v[i].init + (double)(v[i].tax * years) + ((double)(fuelPrice * annualDistance * years)/(double)(v[i].e));
		}
		sort(all(v));
		return v[0].total;
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
			string cars[]             = {"10000 50 50","12000 500 10","15000 100 65","20000 20 80","25000 10 90"};
			int fuelPrice             = 2;
			int annualDistance        = 5000;
			int years                 = 2;
			double expected__         = 10500.0;

			clock_t start__           = clock();
			double received__         = CarBuyer().lowestCost(vector <string>(cars, cars + (sizeof cars / sizeof cars[0])), fuelPrice, annualDistance, years);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string cars[]             = {"10000 50 50","12000 500 10","15000 100 65","20000 20 80","25000 10 90"};
			int fuelPrice             = 8;
			int annualDistance        = 25000;
			int years                 = 10;
			double expected__         = 45200.0;

			clock_t start__           = clock();
			double received__         = CarBuyer().lowestCost(vector <string>(cars, cars + (sizeof cars / sizeof cars[0])), fuelPrice, annualDistance, years);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string cars[]             = {"8426 774 19","29709 325 31","30783 853 68","20796 781 3"
,"27726 4 81","20788 369 69","17554 359 34","12039 502 24"
,"6264 230 69","14151 420 65","25115 528 70","22234 719 55"
,"2050 926 40","18618 714 29","173 358 57"};
			int fuelPrice             = 33;
			int annualDistance        = 8673;
			int years                 = 64;
			double expected__         = 254122.44444444444;

			clock_t start__           = clock();
			double received__         = CarBuyer().lowestCost(vector <string>(cars, cars + (sizeof cars / sizeof cars[0])), fuelPrice, annualDistance, years);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string cars[]             = ;
			int fuelPrice             = ;
			int annualDistance        = ;
			int years                 = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CarBuyer().lowestCost(vector <string>(cars, cars + (sizeof cars / sizeof cars[0])), fuelPrice, annualDistance, years);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			string cars[]             = ;
			int fuelPrice             = ;
			int annualDistance        = ;
			int years                 = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CarBuyer().lowestCost(vector <string>(cars, cars + (sizeof cars / sizeof cars[0])), fuelPrice, annualDistance, years);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string cars[]             = ;
			int fuelPrice             = ;
			int annualDistance        = ;
			int years                 = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CarBuyer().lowestCost(vector <string>(cars, cars + (sizeof cars / sizeof cars[0])), fuelPrice, annualDistance, years);
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
