// BEGIN CUT HERE
#pragma warning(disable:4018)  // signed/unsigned mistatch
#pragma warning(disable:4244)  // w64 to int cast
#pragma warning(disable:4267)  // big to small -- possible loss of data
#pragma warning(disable:4786)  // long identifiers
#pragma warning(disable:4800)  // forcing int to bool
#pragma warning(disable:4996)  // deprecations
// END CUT HERE
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
// BEGIN CUT HERE
#define TC_LOCAL_COMPILE
#ifdef TC_LOCAL_COMPILE
#include "hash_set"
#include "hash_map"
using namespace stdext;
#else
#include "ext/hash_set"
#include "ext/hash_map"
using namespace __gnu_cxx;
#endif
// END CUT HERE

struct ProfitCalculator {
	int percent(vector <string> items) {
		double paid = 0.0, cost = 0.0;
		for(int i=0, n=items.size(); i<n; ++i){
			istringstream iss(items[i]);
			double p, c; iss >> p >> c;
			paid += p, cost += c;
		}
		int res = ((paid-cost) * 100.0)/paid;
		return res;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
  int isinf(double x) {return !_finite(x);}
  int isnan(double x) {return _isnan(x);}
};
namespace moj_harness {
	int run_test_case(int);
	void run_test( int casenum ) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
			if ( x == -1 ) {
				if ( i >= 100 ) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if ( total == 0 ) {
			cerr << "No test cases run." << endl;
		} else if ( correct < total ) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case( int casenum, const int &expected, const int &received ) { 
		cerr << "Example " << casenum << "... "; 
		if ( expected == received ) {
			cerr << "PASSED" << endl;
			return 1;
		} else {
			cerr << "FAILED" << endl;
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
			return 0;
		}
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string items[]            = {"012.99 008.73","099.99 050.00","123.45 101.07"};
			int expected              = 32;

			return verify_case( casenum, expected, ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}
		case 1: {
			string items[]            = {"000.00 049.99","999.99 936.22","033.99 025.64","249.99 211.87"};
			int expected              = 4;

			return verify_case( casenum, expected, ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}
		case 2: {
			string items[]            = {"822.77 704.86","829.42 355.45","887.18 949.38"};
			int expected              = 20;

			return verify_case( casenum, expected, ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}
		case 3: {
			string items[]            = {"612.72 941.34","576.46 182.66","787.41 524.70","637.96 333.23","345.01 219.69",  "567.22 104.77","673.02 885.77"};
			int expected              = 23;

			return verify_case( casenum, expected, ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}
		case 4: {
			string items[]            = {"811.22 275.32","433.89 006.48","141.28 967.41","344.47 786.23","897.47 860.61",  "007.42 559.29","255.72 460.00","419.35 931.19","419.25 490.52","199.78 114.44",  "505.63 276.58","720.96 735.00","719.90 824.46","816.58 195.94","498.68 453.05",  "399.48 921.39","930.88 017.63","422.20 075.39","380.22 917.27","630.83 995.87",  "821.07 126.87","715.73 985.62","246.23 134.64","168.28 550.33","707.28 046.72",  "117.76 281.87","595.43 410.45","345.28 532.42","554.24 264.34","195.73 814.87",  "131.98 041.28","595.13 939.47","576.04 107.70","716.00 404.75","524.24 029.96",  "673.49 070.97","288.09 849.43","616.34 236.34","401.96 316.33","371.18 014.27",  "809.63 508.33","375.68 290.84","334.66 477.89","689.54 526.35","084.77 316.51",  "304.76 015.91","460.63 636.56","357.84 436.20","752.24 047.64","922.10 573.12"};
			int expected              = 10;

			return verify_case( casenum, expected, ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string items[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}*/
/*      case 6: {
			string items[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}*/
/*      case 7: {
			string items[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, ProfitCalculator().percent( vector <string>( items, items + ( sizeof items / sizeof items[0] ) ) ) );
		}*/
		default:
			return -1;
		}
	}
}

int main() {
  moj_harness::run_test(-1);
} 
// END CUT HERE
