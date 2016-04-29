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

struct FormatAmt {
	string amount(int dollars, int cents) {
		string res;
		char buffer[100];
		sprintf(buffer,"$%d.%.2d",dollars,cents);
		res = buffer;
		for(int i=res.size()-6; i > 1; i-=3)
			res.insert(i, ",");
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
	
	int verify_case( int casenum, const string &expected, const string &received ) { 
		cerr << "Example " << casenum << "... "; 
		if ( expected == received ) {
			cerr << "PASSED" << endl;
			return 1;
		} else {
			cerr << "FAILED" << endl;
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
			return 0;
		}
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int dollars               = 123456;
			int cents                 = 0;
			string expected           = "$123,456.00";

			return verify_case( casenum, expected, FormatAmt().amount( dollars, cents ) );
		}
		case 1: {
			int dollars               = 49734321;
			int cents                 = 9;
			string expected           = "$49,734,321.09";

			return verify_case( casenum, expected, FormatAmt().amount( dollars, cents ) );
		}
		case 2: {
			int dollars               = 0;
			int cents                 = 99;
			string expected           = "$0.99";

			return verify_case( casenum, expected, FormatAmt().amount( dollars, cents ) );
		}
		case 3: {
			int dollars               = 249;
			int cents                 = 30;
			string expected           = "$249.30";

			return verify_case( casenum, expected, FormatAmt().amount( dollars, cents ) );
		}
		case 4: {
			int dollars               = 1000;
			int cents                 = 1;
			string expected           = "$1,000.01";

			return verify_case( casenum, expected, FormatAmt().amount( dollars, cents ) );
		}

		// custom cases

/*      case 5: {
			int dollars               = ;
			int cents                 = ;
			string expected           = ;

			return verify_case( casenum, expected, FormatAmt().amount( dollars, cents ) );
		}*/
/*      case 6: {
			int dollars               = ;
			int cents                 = ;
			string expected           = ;

			return verify_case( casenum, expected, FormatAmt().amount( dollars, cents ) );
		}*/
/*      case 7: {
			int dollars               = ;
			int cents                 = ;
			string expected           = ;

			return verify_case( casenum, expected, FormatAmt().amount( dollars, cents ) );
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
