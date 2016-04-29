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

struct LevelUp {
	int toNextLevel(vector <int> v, int exp) {
		int i =0, n=v.size();
		for(;i<n && exp >= v[i]; ++i);
		return i<n? v[i]-exp: v[n-1]<exp;
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
			int expNeeded[]           = {150,450,900,1800};
			int received              = 133;
			int expected              = 17;

			return verify_case( casenum, expected, LevelUp().toNextLevel( vector <int>( expNeeded, expNeeded + ( sizeof expNeeded / sizeof expNeeded[0] ) ), received ) );
		}
		case 1: {
			int expNeeded[]           = {150,450,900,1800};
			int received              = 312;
			int expected              = 138;

			return verify_case( casenum, expected, LevelUp().toNextLevel( vector <int>( expNeeded, expNeeded + ( sizeof expNeeded / sizeof expNeeded[0] ) ), received ) );
		}
		case 2: {
			int expNeeded[]           = {150,450,900,1800};
			int received              = 612;
			int expected              = 288;

			return verify_case( casenum, expected, LevelUp().toNextLevel( vector <int>( expNeeded, expNeeded + ( sizeof expNeeded / sizeof expNeeded[0] ) ), received ) );
		}
		case 3: {
			int expNeeded[]           = {150,450,900,1800};
			int received              = 450;
			int expected              = 450;

			return verify_case( casenum, expected, LevelUp().toNextLevel( vector <int>( expNeeded, expNeeded + ( sizeof expNeeded / sizeof expNeeded[0] ) ), received ) );
		}

		// custom cases

/*      case 4: {
			int expNeeded[]           = ;
			int received              = ;
			int expected              = ;

			return verify_case( casenum, expected, LevelUp().toNextLevel( vector <int>( expNeeded, expNeeded + ( sizeof expNeeded / sizeof expNeeded[0] ) ), received ) );
		}*/
/*      case 5: {
			int expNeeded[]           = ;
			int received              = ;
			int expected              = ;

			return verify_case( casenum, expected, LevelUp().toNextLevel( vector <int>( expNeeded, expNeeded + ( sizeof expNeeded / sizeof expNeeded[0] ) ), received ) );
		}*/
/*      case 6: {
			int expNeeded[]           = ;
			int received              = ;
			int expected              = ;

			return verify_case( casenum, expected, LevelUp().toNextLevel( vector <int>( expNeeded, expNeeded + ( sizeof expNeeded / sizeof expNeeded[0] ) ), received ) );
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
