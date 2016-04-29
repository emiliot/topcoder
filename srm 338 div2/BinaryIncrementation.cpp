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

struct BinaryIncrementation {
	string plusOne(string x) {
		int ac = 1;
		for(int i = x.size()-1; i>=0; --i){
			if(ac == 1){
				if(x[i] == '1'){
					x[i] = '0';
				}else{
					x[i] = '1';
					ac = 0;
					break;
				}
			}
		}
		if(ac == 1)x.insert(x.begin(),'1');
		return x;
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
	
	int verify_case( int casenum, const string &expected, const string &received ) { 
		cerr << "Example " << casenum << "... "; 
		if ( expected == received ) {
			cerr << "PASSED" << endl;
			return 1;
		} else {
			cerr << "FAILED" << endl;
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
			return 0;
		}
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string x                  = "10011";
			string expected           = "10100";

			return verify_case( casenum, expected, BinaryIncrementation().plusOne( x ) );
		}
		case 1: {
			string x                  = "10000";
			string expected           = "10001";

			return verify_case( casenum, expected, BinaryIncrementation().plusOne( x ) );
		}
		case 2: {
			string x                  = "1111";
			string expected           = "10000";

			return verify_case( casenum, expected, BinaryIncrementation().plusOne( x ) );
		}
		case 3: {
			string x                  = "1";
			string expected           = "10";

			return verify_case( casenum, expected, BinaryIncrementation().plusOne( x ) );
		}
		case 4: {
			string x                  = "101010101010101010101010101010";
			string expected           = "101010101010101010101010101011";

			return verify_case( casenum, expected, BinaryIncrementation().plusOne( x ) );
		}

		// custom cases

/*      case 5: {
			string x                  = ;
			string expected           = ;

			return verify_case( casenum, expected, BinaryIncrementation().plusOne( x ) );
		}*/
/*      case 6: {
			string x                  = ;
			string expected           = ;

			return verify_case( casenum, expected, BinaryIncrementation().plusOne( x ) );
		}*/
/*      case 7: {
			string x                  = ;
			string expected           = ;

			return verify_case( casenum, expected, BinaryIncrementation().plusOne( x ) );
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
