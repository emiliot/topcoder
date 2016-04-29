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

// BEGIN CUT HERE
#define all(v) (v).begin(), (v).end()
typedef long long i64;
template <class T> void make_unique(T& v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}
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

struct ColorfulBoxesAndBalls {
	int getMaximum(int r, int b, int onlyRed, int onlyBlue, int bothColors) {
		int res;
		if(r<b)res = (b-r)*onlyBlue + 2*r*bothColors; //mixed
		else res = (r-b)*onlyRed + 2*b*bothColors;
		res = max(res, (r*onlyRed) + (b*onlyBlue)); //max mixed, clean
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
			int numRed                = 2;
			int numBlue               = 3;
			int onlyRed               = 100;
			int onlyBlue              = 400;
			int bothColors            = 200;
			int expected              = 1400;

			return verify_case( casenum, expected, ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors ) );
		}
		case 1: {
			int numRed                = 2;
			int numBlue               = 3;
			int onlyRed               = 100;
			int onlyBlue              = 400;
			int bothColors            = 300;
			int expected              = 1600;

			return verify_case( casenum, expected, ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors ) );
		}
		case 2: {
			int numRed                = 5;
			int numBlue               = 5;
			int onlyRed               = 464;
			int onlyBlue              = 464;
			int bothColors            = 464;
			int expected              = 4640;

			return verify_case( casenum, expected, ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors ) );
		}
		case 3: {
			int numRed                = 1;
			int numBlue               = 4;
			int onlyRed               = 20;
			int onlyBlue              = -30;
			int bothColors            = -10;
			int expected              = -100;

			return verify_case( casenum, expected, ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors ) );
		}
		case 4: {
			int numRed                = 9;
			int numBlue               = 1;
			int onlyRed               = -1;
			int onlyBlue              = -10;
			int bothColors            = 4;
			int expected              = 0;

			return verify_case( casenum, expected, ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors ) );
		}

		// custom cases

      case 5: {
			int numRed                = 100;
			int numBlue               = 100;
			int onlyRed               = 1;
			int onlyBlue              = 1;
			int bothColors            = 1;
			int expected              = 200;

			return verify_case( casenum, expected, ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors ) );
		}
/*      case 6: {
			int numRed                = ;
			int numBlue               = ;
			int onlyRed               = ;
			int onlyBlue              = ;
			int bothColors            = ;
			int expected              = ;

			return verify_case( casenum, expected, ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors ) );
		}*/
/*      case 7: {
			int numRed                = ;
			int numBlue               = ;
			int onlyRed               = ;
			int onlyBlue              = ;
			int bothColors            = ;
			int expected              = ;

			return verify_case( casenum, expected, ColorfulBoxesAndBalls().getMaximum( numRed, numBlue, onlyRed, onlyBlue, bothColors ) );
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
