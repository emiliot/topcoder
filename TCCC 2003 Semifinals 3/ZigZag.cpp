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

int memo[100][100][2];
bool mark[100][100][2];

int f(vector <int> &v, int i, int j, bool flag){
	if(i>=(int)v.size())return 0;
	int &best = memo[i][j][flag];
	if(mark[i][j][flag])return best;
	mark[i][j][flag] = true;
	best = f(v,i+1,j,flag);
	if(v[i] > v[j] && flag){
		best = max(best, f(v,i+1,i,!flag)+1);
	}else if(v[i] < v[j] && !flag){
		best = max(best, f(v,i+1,i,!flag)+1);
	}
	return best;
}

struct ZigZag {
	int longestZigZag(vector <int> v) {
		memset(mark,false,sizeof(mark));
		return max(f(v,0,0,false)+1, f(v,0,0,true)+1);
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
			int sequence[]            = { 1, 7, 4, 9, 2, 5 };
			int expected              = 6;

			return verify_case( casenum, expected, ZigZag().longestZigZag( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) ) );
		}
		case 1: {
			int sequence[]            = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
			int expected              = 7;

			return verify_case( casenum, expected, ZigZag().longestZigZag( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) ) );
		}
		case 2: {
			int sequence[]            = { 44 };
			int expected              = 1;

			return verify_case( casenum, expected, ZigZag().longestZigZag( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) ) );
		}
		case 3: {
			int sequence[]            = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int expected              = 2;

			return verify_case( casenum, expected, ZigZag().longestZigZag( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) ) );
		}
		case 4: {
			int sequence[]            = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
			int expected              = 8;

			return verify_case( casenum, expected, ZigZag().longestZigZag( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) ) );
		}
		case 5: {
			int sequence[]            = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,  600, 947, 978, 46, 100, 953, 670, 862, 568, 188,  67, 669, 810, 704, 52, 861, 49, 640, 370, 908,  477, 245, 413, 109, 659, 401, 483, 308, 609, 120,  249, 22, 176, 279, 23, 22, 617, 462, 459, 244 } ;
			int expected              = 36;

			return verify_case( casenum, expected, ZigZag().longestZigZag( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) ) );
		}

		// custom cases

/*      case 6: {
			int sequence[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, ZigZag().longestZigZag( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) ) );
		}*/
/*      case 7: {
			int sequence[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, ZigZag().longestZigZag( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) ) );
		}*/
/*      case 8: {
			int sequence[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, ZigZag().longestZigZag( vector <int>( sequence, sequence + ( sizeof sequence / sizeof sequence[0] ) ) ) );
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
