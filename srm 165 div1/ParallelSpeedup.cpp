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
typedef long long i64;
// BEGIN CUT HERE
#define all(v) (v).begin(), (v).end()
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

i64 f(i64 p, i64 over){
	return (over*(p*(p-1)/2));
}

struct ParallelSpeedup {
	int numProcessors(int k, int overhead) {
		i64 spd = k, np = 1, ovh = (i64)(overhead);
		for(i64 i=2; i<=k; ++i){
			const i64 next = f(i,ovh) + ((k+i-1)/i);
			if(next < spd){
				spd = next;
				np = i;
			}
		}
		return (int)(np);
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
			int k                     = 12;
			int overhead              = 1;
			int expected              = 2;

			return verify_case( casenum, expected, ParallelSpeedup().numProcessors( k, overhead ) );
		}
		case 1: {
			int k                     = 50;
			int overhead              = 3;
			int expected              = 3;

			return verify_case( casenum, expected, ParallelSpeedup().numProcessors( k, overhead ) );
		}
		case 2: {
			int k                     = 9;
			int overhead              = 10;
			int expected              = 1;

			return verify_case( casenum, expected, ParallelSpeedup().numProcessors( k, overhead ) );
		}
		case 3: {
			int k                     = 3333;
			int overhead              = 2;
			int expected              = 12;

			return verify_case( casenum, expected, ParallelSpeedup().numProcessors( k, overhead ) );
		}
		case 4: {
			int k                     = 1000000;
			int overhead              = 4;
			int expected              = 63;

			return verify_case( casenum, expected, ParallelSpeedup().numProcessors( k, overhead ) );
		}

		// custom cases

/*      case 5: {
			int k                     = ;
			int overhead              = ;
			int expected              = ;

			return verify_case( casenum, expected, ParallelSpeedup().numProcessors( k, overhead ) );
		}*/
/*      case 6: {
			int k                     = ;
			int overhead              = ;
			int expected              = ;

			return verify_case( casenum, expected, ParallelSpeedup().numProcessors( k, overhead ) );
		}*/
/*      case 7: {
			int k                     = ;
			int overhead              = ;
			int expected              = ;

			return verify_case( casenum, expected, ParallelSpeedup().numProcessors( k, overhead ) );
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
