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

struct KiloMan {
	int hitsTaken(vector <int> v, string jumps) {
		int count = 0;
		for(int i=0, n=v.size(); i<n; ++i){
			if(jumps[i] == 'J' && v[i]>2)++count;
			else if(jumps[i] == 'S' && v[i] <= 2)++count;
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
			int pattern[]             = {1,3,2,3,3,1,2,2,1} ;
			string jumps              = "JJSSSJSSJ";
			int expected              = 4;

			return verify_case( casenum, expected, KiloMan().hitsTaken( vector <int>( pattern, pattern + ( sizeof pattern / sizeof pattern[0] ) ), jumps ) );
		}
		case 1: {
			int pattern[]             = {1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,  4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7};
			string jumps              = "SSSSSSSSSSSSSSJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ";
			int expected              = 49;

			return verify_case( casenum, expected, KiloMan().hitsTaken( vector <int>( pattern, pattern + ( sizeof pattern / sizeof pattern[0] ) ), jumps ) );
		}
		case 2: {
			int pattern[]             = {1,2,2,1} ;
			string jumps              = "SJJS";
			int expected              = 2;

			return verify_case( casenum, expected, KiloMan().hitsTaken( vector <int>( pattern, pattern + ( sizeof pattern / sizeof pattern[0] ) ), jumps ) );
		}
		case 3: {
			int pattern[]             = {1};
			string jumps              = "J";
			int expected              = 0;

			return verify_case( casenum, expected, KiloMan().hitsTaken( vector <int>( pattern, pattern + ( sizeof pattern / sizeof pattern[0] ) ), jumps ) );
		}

		// custom cases

/*      case 4: {
			int pattern[]             = ;
			string jumps              = ;
			int expected              = ;

			return verify_case( casenum, expected, KiloMan().hitsTaken( vector <int>( pattern, pattern + ( sizeof pattern / sizeof pattern[0] ) ), jumps ) );
		}*/
/*      case 5: {
			int pattern[]             = ;
			string jumps              = ;
			int expected              = ;

			return verify_case( casenum, expected, KiloMan().hitsTaken( vector <int>( pattern, pattern + ( sizeof pattern / sizeof pattern[0] ) ), jumps ) );
		}*/
/*      case 6: {
			int pattern[]             = ;
			string jumps              = ;
			int expected              = ;

			return verify_case( casenum, expected, KiloMan().hitsTaken( vector <int>( pattern, pattern + ( sizeof pattern / sizeof pattern[0] ) ), jumps ) );
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
