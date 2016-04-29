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

int f(vector <int> src, vector <int> dest, vector <int> w, int st) {
	int worse = 0;
	for(int i=0, n=src.size(); i<n; ++i){
		if(src[i] == st){
			worse = max(worse, f(src, dest, w, dest[i]) + w[i]);
		}
	}
	return worse;
}

struct PowerOutage {
	int estimateTimeOut(vector <int> src, vector <int> dest, vector <int> w) {
		int res = 0;
		int worse = 0;
		for(int i=0, n=src.size(); i<n; ++i){
			res += w[i]*2;
			if(src[i] == 0)
				worse = max(worse, f(src, dest, w, dest[i])+w[i]);
		}
		return res - worse;
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
			int fromJunction[]        = {0};
			int toJunction[]          = {1};
			int ductLength[]          = {10};
			int expected              = 10;

			return verify_case( casenum, expected, PowerOutage().estimateTimeOut( vector <int>( fromJunction, fromJunction + ( sizeof fromJunction / sizeof fromJunction[0] ) ), vector <int>( toJunction, toJunction + ( sizeof toJunction / sizeof toJunction[0] ) ), vector <int>( ductLength, ductLength + ( sizeof ductLength / sizeof ductLength[0] ) ) ) );
		}
		case 1: {
			int fromJunction[]        = {0,1,0};
			int toJunction[]          = {1,2,3};
			int ductLength[]          = {10,10,10};
			int expected              = 40;

			return verify_case( casenum, expected, PowerOutage().estimateTimeOut( vector <int>( fromJunction, fromJunction + ( sizeof fromJunction / sizeof fromJunction[0] ) ), vector <int>( toJunction, toJunction + ( sizeof toJunction / sizeof toJunction[0] ) ), vector <int>( ductLength, ductLength + ( sizeof ductLength / sizeof ductLength[0] ) ) ) );
		}
		case 2: {
			int fromJunction[]        = {0,0,0,1,4};
			int toJunction[]          = {1,3,4,2,5};
			int ductLength[]          = {10,10,100,10,5};
			int expected              = 165;

			return verify_case( casenum, expected, PowerOutage().estimateTimeOut( vector <int>( fromJunction, fromJunction + ( sizeof fromJunction / sizeof fromJunction[0] ) ), vector <int>( toJunction, toJunction + ( sizeof toJunction / sizeof toJunction[0] ) ), vector <int>( ductLength, ductLength + ( sizeof ductLength / sizeof ductLength[0] ) ) ) );
		}
		case 3: {
			int fromJunction[]        = {0,0,0,1,4,4,6,7,7,7,20};
			int toJunction[]          = {1,3,4,2,5,6,7,20,9,10,31};
			int ductLength[]          = {10,10,100,10,5,1,1,100,1,1,5};
			int expected              = 281;

			return verify_case( casenum, expected, PowerOutage().estimateTimeOut( vector <int>( fromJunction, fromJunction + ( sizeof fromJunction / sizeof fromJunction[0] ) ), vector <int>( toJunction, toJunction + ( sizeof toJunction / sizeof toJunction[0] ) ), vector <int>( ductLength, ductLength + ( sizeof ductLength / sizeof ductLength[0] ) ) ) );
		}
		case 4: {
			int fromJunction[]        = {0,0,0,0,0};
			int toJunction[]          = {1,2,3,4,5};
			int ductLength[]          = {100,200,300,400,500};
			int expected              = 2500;

			return verify_case( casenum, expected, PowerOutage().estimateTimeOut( vector <int>( fromJunction, fromJunction + ( sizeof fromJunction / sizeof fromJunction[0] ) ), vector <int>( toJunction, toJunction + ( sizeof toJunction / sizeof toJunction[0] ) ), vector <int>( ductLength, ductLength + ( sizeof ductLength / sizeof ductLength[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			int fromJunction[]        = ;
			int toJunction[]          = ;
			int ductLength[]          = ;
			int expected              = ;

			return verify_case( casenum, expected, PowerOutage().estimateTimeOut( vector <int>( fromJunction, fromJunction + ( sizeof fromJunction / sizeof fromJunction[0] ) ), vector <int>( toJunction, toJunction + ( sizeof toJunction / sizeof toJunction[0] ) ), vector <int>( ductLength, ductLength + ( sizeof ductLength / sizeof ductLength[0] ) ) ) );
		}*/
/*      case 6: {
			int fromJunction[]        = ;
			int toJunction[]          = ;
			int ductLength[]          = ;
			int expected              = ;

			return verify_case( casenum, expected, PowerOutage().estimateTimeOut( vector <int>( fromJunction, fromJunction + ( sizeof fromJunction / sizeof fromJunction[0] ) ), vector <int>( toJunction, toJunction + ( sizeof toJunction / sizeof toJunction[0] ) ), vector <int>( ductLength, ductLength + ( sizeof ductLength / sizeof ductLength[0] ) ) ) );
		}*/
/*      case 7: {
			int fromJunction[]        = ;
			int toJunction[]          = ;
			int ductLength[]          = ;
			int expected              = ;

			return verify_case( casenum, expected, PowerOutage().estimateTimeOut( vector <int>( fromJunction, fromJunction + ( sizeof fromJunction / sizeof fromJunction[0] ) ), vector <int>( toJunction, toJunction + ( sizeof toJunction / sizeof toJunction[0] ) ), vector <int>( ductLength, ductLength + ( sizeof ductLength / sizeof ductLength[0] ) ) ) );
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
