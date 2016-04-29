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
const int INF = 0x3f3f3f3f;
struct Packhorses {
	int horses(int p, int x, int y) {
		int best = INF;
		for(int i=0; i<=p; ++i){
			int next = p;
			int dx = max(0, x -(i*2));
			int dy = max(0, y -(p-i));
			next += (dx+2)/3;
			next += (dy+1)/2;
			best = min(best,next);
		}
		return best;
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
			int p                     = 1;
			int x                     = 5;
			int y                     = 0;
			int expected              = 2;

			return verify_case( casenum, expected, Packhorses().horses( p, x, y ) );
		}
		case 1: {
			int p                     = 1;
			int x                     = 6;
			int y                     = 0;
			int expected              = 3;

			return verify_case( casenum, expected, Packhorses().horses( p, x, y ) );
		}
		case 2: {
			int p                     = 20;
			int x                     = 15;
			int y                     = 7;
			int expected              = 20;

			return verify_case( casenum, expected, Packhorses().horses( p, x, y ) );
		}
		case 3: {
			int p                     = 1;
			int x                     = 3;
			int y                     = 1;
			int expected              = 2;

			return verify_case( casenum, expected, Packhorses().horses( p, x, y ) );
		}

		// custom cases

      case 4: {
			int p                     = 100;
			int x                     = 222;
			int y                     = 333;
			int expected              = 274;

			return verify_case( casenum, expected, Packhorses().horses( p, x, y ) );
		}
/*      case 5: {
			int p                     = ;
			int x                     = ;
			int y                     = ;
			int expected              = ;

			return verify_case( casenum, expected, Packhorses().horses( p, x, y ) );
		}*/
/*      case 6: {
			int p                     = ;
			int x                     = ;
			int y                     = ;
			int expected              = ;

			return verify_case( casenum, expected, Packhorses().horses( p, x, y ) );
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
