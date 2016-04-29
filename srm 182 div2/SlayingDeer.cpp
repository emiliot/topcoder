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

struct SlayingDeer {
	int getTime(int A, int B, int C) {
		const int da = A*45, db = B*30;
		if(da <= db)return -1;
		int d45 = ((A-B)*30)+(A*15); 
		int n = C/d45, mod = C%d45;
		int res = n*45;
		if(mod == 0)return res;
		else if(mod > (A-B)*30)res += 30 + ((mod-((A-B)*30)+A-1)/A);
		else res += (mod+(A-B)-1)/(A-B);
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
			int A                     = 5;
			int B                     = 4;
			int C                     = 20;
			int expected              = 20;

			return verify_case( casenum, expected, SlayingDeer().getTime( A, B, C ) );
		}
		case 1: {
			int A                     = 5;
			int B                     = 4;
			int C                     = 47;
			int expected              = 34;

			return verify_case( casenum, expected, SlayingDeer().getTime( A, B, C ) );
		}
		case 2: {
			int A                     = 10;
			int B                     = 17;
			int C                     = 1;
			int expected              = -1;

			return verify_case( casenum, expected, SlayingDeer().getTime( A, B, C ) );
		}
		case 3: {
			int A                     = 133;
			int B                     = 198;
			int C                     = 7515;
			int expected              = 7515;

			return verify_case( casenum, expected, SlayingDeer().getTime( A, B, C ) );
		}
		case 4: {
			int A                     = 1;
			int B                     = 1000;
			int C                     = 15819;
			int expected              = -1;

			return verify_case( casenum, expected, SlayingDeer().getTime( A, B, C ) );
		}

		// custom cases
      case 5: {
			int A                     = 1;
			int B                     = 1;
			int C                     = 100000;
			int expected              = 300010;

			return verify_case( casenum, expected, SlayingDeer().getTime( A, B, C ) );
		}
/*      case 6: {
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int expected              = ;

			return verify_case( casenum, expected, SlayingDeer().getTime( A, B, C ) );
		}*/
/*      case 7: {
			int A                     = ;
			int B                     = ;
			int C                     = ;
			int expected              = ;

			return verify_case( casenum, expected, SlayingDeer().getTime( A, B, C ) );
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
