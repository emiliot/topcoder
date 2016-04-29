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

struct BunnyPuzzle {
  int theCount(vector <int> bunnies) {
	  int count = 2;
	  const int n = bunnies.size();
	  vector <int> &v = bunnies;
	  if(n == 2)return 2;
	  else if(n == 3){
		  if((v[1]*2)-v[0] < v[2])++count;
		  if((v[1]*2)-v[2] > v[0])++count;
		  return count;
	  }
	  if((v[1]*2)-v[0] <v[2])++count;
	  if((v[n-2]*2)-v[n-1] > v[n-3])++count;
	  if((v[2]*2)-v[1] <v[3])++count;
	  if((v[n-3]*2)-v[n-2] > v[n-4])++count;
	  if(n==4)return count;
	  for(int i=2; i<n-2; ++i){
		if((v[i+1]*2)-v[i] < v[i+2])++count;
		if((v[i-1]*2)-v[i] > v[i-2])++count;
	  }

	  return count;
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
			int bunnies[]             = {5, 8};
			int expected              = 2;

			return verify_case( casenum, expected, BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) ) );
		}
		case 1: {
			int bunnies[]             = {-1, 0, 1};
			int expected              = 2;

			return verify_case( casenum, expected, BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) ) );
		}
		case 2: {
			int bunnies[]             = {0, 1, 3};
			int expected              = 3;

			return verify_case( casenum, expected, BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) ) );
		}
		case 3: {
			int bunnies[]             = {-677, -45, -2, 3, 8, 29, 384, 867};
			int expected              = 7;

			return verify_case( casenum, expected, BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) ) );
		}
		case 4: {
			int bunnies[]             = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			int expected              = 2;

			return verify_case( casenum, expected, BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			int bunnies[]             = ;
			int expected              = ;

			return verify_case( casenum, expected, BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) ) );
		}*/
/*      case 6: {
			int bunnies[]             = ;
			int expected              = ;

			return verify_case( casenum, expected, BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) ) );
		}*/
/*      case 7: {
			int bunnies[]             = ;
			int expected              = ;

			return verify_case( casenum, expected, BunnyPuzzle().theCount( vector <int>( bunnies, bunnies + ( sizeof bunnies / sizeof bunnies[0] ) ) ) );
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
