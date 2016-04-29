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

struct CountingSeries {
	long long countThem(long long a, long long b, long long c, long long d, long long up) {
		i64 arith = up >= a? ((up - a)/b) +1 : 0LL;
		i64 geom = 0LL, both = 0LL;
		if(d == 1LL){
			geom = c <= up? 1LL:0;
			both = ((c-a) % b == 0 && c >= a && c <= up )? 1:0;
		}else{
			for(i64 i=c; i<=up; i*=d){
				++geom;
				both += (i >= a && (i-a)%b == 0)? 1LL:0LL;
			}
		}

		return arith + geom - both;
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
	
	int verify_case( int casenum, const long long &expected, const long long &received ) { 
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
			long long a               = 1LL;
			long long b               = 1LL;
			long long c               = 1LL;
			long long d               = 2LL;
			long long upperBound      = 1000LL;
			long long expected        = 1000LL;

			return verify_case( casenum, expected, CountingSeries().countThem( a, b, c, d, upperBound ) );
		}
		case 1: {
			long long a               = 3LL;
			long long b               = 3LL;
			long long c               = 1LL;
			long long d               = 2LL;
			long long upperBound      = 1000LL;
			long long expected        = 343LL;

			return verify_case( casenum, expected, CountingSeries().countThem( a, b, c, d, upperBound ) );
		}
		case 2: {
			long long a               = 40LL;
			long long b               = 77LL;
			long long c               = 40LL;
			long long d               = 100000LL;
			long long upperBound      = 40LL;
			long long expected        = 1LL;

			return verify_case( casenum, expected, CountingSeries().countThem( a, b, c, d, upperBound ) );
		}
		case 3: {
			long long a               = 452LL;
			long long b               = 24LL;
			long long c               = 4LL;
			long long d               = 5LL;
			long long upperBound      = 600LL;
			long long expected        = 10LL;

			return verify_case( casenum, expected, CountingSeries().countThem( a, b, c, d, upperBound ) );
		}
		case 4: {
			long long a               = 234LL;
			long long b               = 24LL;
			long long c               = 377LL;
			long long d               = 1LL;
			long long upperBound      = 10000LL;
			long long expected        = 408LL;

			return verify_case( casenum, expected, CountingSeries().countThem( a, b, c, d, upperBound ) );
		}

		// custom cases

/*      case 5: {
			long long a               = LL;
			long long b               = LL;
			long long c               = LL;
			long long d               = LL;
			long long upperBound      = LL;
			long long expected        = LL;

			return verify_case( casenum, expected, CountingSeries().countThem( a, b, c, d, upperBound ) );
		}*/
/*      case 6: {
			long long a               = LL;
			long long b               = LL;
			long long c               = LL;
			long long d               = LL;
			long long upperBound      = LL;
			long long expected        = LL;

			return verify_case( casenum, expected, CountingSeries().countThem( a, b, c, d, upperBound ) );
		}*/
/*      case 7: {
			long long a               = LL;
			long long b               = LL;
			long long c               = LL;
			long long d               = LL;
			long long upperBound      = LL;
			long long expected        = LL;

			return verify_case( casenum, expected, CountingSeries().countThem( a, b, c, d, upperBound ) );
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
