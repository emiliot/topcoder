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

struct CorrectMultiplicationTwo {
	int getMinimum(int a, int b, int c) {
		int s = a + b + c - 3;
		for(int A=1; A<= c + s; ++A){
			for(int B=1; B <= (c+s)/A; ++B){
				int C = A*B;
				s = min(s, abs(A-a) + abs(B-b) + abs(C-c));
			}
		}
		return s;
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
			int a                     = 19;
			int b                     = 28;
			int c                     = 522;
			int expected              = 2;

			return verify_case( casenum, expected, CorrectMultiplicationTwo().getMinimum( a, b, c ) );
		}
		case 1: {
			int a                     = 10;
			int b                     = 30;
			int c                     = 500;
			int expected              = 11;

			return verify_case( casenum, expected, CorrectMultiplicationTwo().getMinimum( a, b, c ) );
		}
		case 2: {
			int a                     = 111;
			int b                     = 111;
			int c                     = 12321;
			int expected              = 0;

			return verify_case( casenum, expected, CorrectMultiplicationTwo().getMinimum( a, b, c ) );
		}
		case 3: {
			int a                     = 1000;
			int b                     = 100;
			int c                     = 10;
			int expected              = 1089;

			return verify_case( casenum, expected, CorrectMultiplicationTwo().getMinimum( a, b, c ) );
		}
		case 4: {
			int a                     = 399;
			int b                     = 522;
			int c                     = 199999;
			int expected              = 24;

			return verify_case( casenum, expected, CorrectMultiplicationTwo().getMinimum( a, b, c ) );
		}

		// custom cases

/*      case 5: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int expected              = ;

			return verify_case( casenum, expected, CorrectMultiplicationTwo().getMinimum( a, b, c ) );
		}*/
/*      case 6: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int expected              = ;

			return verify_case( casenum, expected, CorrectMultiplicationTwo().getMinimum( a, b, c ) );
		}*/
/*      case 7: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int expected              = ;

			return verify_case( casenum, expected, CorrectMultiplicationTwo().getMinimum( a, b, c ) );
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
