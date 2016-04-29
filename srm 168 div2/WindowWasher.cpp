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

vector <int> v;
int W;
int memo[52][1002];
int mark[52][1002];
const int INF = 0x3f3f3f3f;

int f(int k, int left){
	if(left <= 0)return 0;
	if(k >= (int) v.size() -1)return v[k] * left;

	int &best = memo[k][left];
	if(mark[k][left])return best;
	mark[k][left] = true;

	best = INF;
	for(int i=0; i<=left; ++i){
		int next = f(k + 1, left - i);
		best = min(best, max(next, v[k] * i));
	}
	return best;
}

struct WindowWasher {
	int fastest(int width, int height, vector <int> washTimes) {
		v.assign(all(washTimes));
		for(int i=0, n = v.size(); i<n; ++i){
			v[i] *= height;
		}
		memset(mark, false, sizeof(mark));
		W = width;
		int res = f(0, W);
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
			int width                 = 10;
			int height                = 10;
			int washTimes[]           = {60};
			int expected              = 6000;

			return verify_case( casenum, expected, WindowWasher().fastest( width, height, vector <int>( washTimes, washTimes + ( sizeof washTimes / sizeof washTimes[0] ) ) ) );
		}
		case 1: {
			int width                 = 10;
			int height                = 10;
			int washTimes[]           = {60, 60};
			int expected              = 3000;

			return verify_case( casenum, expected, WindowWasher().fastest( width, height, vector <int>( washTimes, washTimes + ( sizeof washTimes / sizeof washTimes[0] ) ) ) );
		}
		case 2: {
			int width                 = 10;
			int height                = 10;
			int washTimes[]           = {60, 30};
			int expected              = 2100;

			return verify_case( casenum, expected, WindowWasher().fastest( width, height, vector <int>( washTimes, washTimes + ( sizeof washTimes / sizeof washTimes[0] ) ) ) );
		}
		case 3: {
			int width                 = 1000;
			int height                = 1000;
			int washTimes[]           = {1000};
			int expected              = 1000000000;

			return verify_case( casenum, expected, WindowWasher().fastest( width, height, vector <int>( washTimes, washTimes + ( sizeof washTimes / sizeof washTimes[0] ) ) ) );
		}
		case 4: {
			int width                 = 421;
			int height                = 936;
			int washTimes[]           = {111,56,931,22,445,90,14,222};
			int expected              = 2450448;

			return verify_case( casenum, expected, WindowWasher().fastest( width, height, vector <int>( washTimes, washTimes + ( sizeof washTimes / sizeof washTimes[0] ) ) ) );
		}
		case 5: {
			int width                 = 25;
			int height                = 25;
			int washTimes[]           = {1,625};
			int expected              = 625;

			return verify_case( casenum, expected, WindowWasher().fastest( width, height, vector <int>( washTimes, washTimes + ( sizeof washTimes / sizeof washTimes[0] ) ) ) );
		}
		case 6: {
			int width                 = 12;
			int height                = 754;
			int washTimes[]           = {728, 734, 147, 464, 6, 703, 254};
			int expected              = 54288;

			return verify_case( casenum, expected, WindowWasher().fastest( width, height, vector <int>( washTimes, washTimes + ( sizeof washTimes / sizeof washTimes[0] ) ) ) );
		}

		// custom cases

/*      case 7: {
			int width                 = ;
			int height                = ;
			int washTimes[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, WindowWasher().fastest( width, height, vector <int>( washTimes, washTimes + ( sizeof washTimes / sizeof washTimes[0] ) ) ) );
		}*/
/*      case 8: {
			int width                 = ;
			int height                = ;
			int washTimes[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, WindowWasher().fastest( width, height, vector <int>( washTimes, washTimes + ( sizeof washTimes / sizeof washTimes[0] ) ) ) );
		}*/
/*      case 9: {
			int width                 = ;
			int height                = ;
			int washTimes[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, WindowWasher().fastest( width, height, vector <int>( washTimes, washTimes + ( sizeof washTimes / sizeof washTimes[0] ) ) ) );
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
