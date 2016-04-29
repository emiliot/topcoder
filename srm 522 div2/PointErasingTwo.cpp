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

int f(vector <int> &v, int x0, int x1){
	if(x0 > x1)swap(x0,x1);
	int res = 0, y0=v[x0], y1=v[x1];
	if(y0 > y1)swap(y0,y1);
	for(int i=x0+1; i<x1; ++i){
		if(v[i] > y0 && v[i] < y1)++res;
	}
	return res;
}

struct PointErasingTwo {
	int getMaximum(vector <int> y) {
		int n = y.size();
		int best = 0;
		for(int i=0; i<n; ++i){
			for(int j=i+1; j<n; ++j){
				best = max(best, f(y,i,j));
			}
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
			int y[]                   = { 1, 2, 1, 1, 0, 4, 3 };
			int expected              = 2;

			return verify_case( casenum, expected, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 1: {
			int y[]                   = { 0, 1 };
			int expected              = 0;

			return verify_case( casenum, expected, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 2: {
			int y[]                   = { 0, 1, 2, 3, 4 };
			int expected              = 3;

			return verify_case( casenum, expected, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 3: {
			int y[]                   = { 10, 19, 10, 19 };
			int expected              = 0;

			return verify_case( casenum, expected, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 4: {
			int y[]                   = { 0, 23, 49, 50, 32, 0, 18, 50, 0, 28, 50, 27, 49, 0 };
			int expected              = 5;

			return verify_case( casenum, expected, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			int y[]                   = ;
			int expected              = ;

			return verify_case( casenum, expected, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}*/
/*      case 6: {
			int y[]                   = ;
			int expected              = ;

			return verify_case( casenum, expected, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}*/
/*      case 7: {
			int y[]                   = ;
			int expected              = ;

			return verify_case( casenum, expected, PointErasingTwo().getMaximum( vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
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
