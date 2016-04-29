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
const int m =  1000000007;
typedef long long i64;
struct RabbitNumbering {
  int theCount(vector <int> maxNumber) {
	  vector <int> v(maxNumber.begin(),maxNumber.end());
	  sort (v.begin(),v.end());
	  i64 res = 1;
	  for(int i=0, n=v.size(); i<n; ++i){
		const int x = v[i]-i;
		if(x <= 0)return 0;
		res = (res%m)*(x%m)%m;
	  }
	  return (int)(res);
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
			int maxNumber[]           = {5};
			int expected              = 5;

			return verify_case( casenum, expected, RabbitNumbering().theCount( vector <int>( maxNumber, maxNumber + ( sizeof maxNumber / sizeof maxNumber[0] ) ) ) );
		}
		case 1: {
			int maxNumber[]           = {4, 4, 4, 4};
			int expected              = 24;

			return verify_case( casenum, expected, RabbitNumbering().theCount( vector <int>( maxNumber, maxNumber + ( sizeof maxNumber / sizeof maxNumber[0] ) ) ) );
		}
		case 2: {
			int maxNumber[]           = {5, 8};
			int expected              = 35;

			return verify_case( casenum, expected, RabbitNumbering().theCount( vector <int>( maxNumber, maxNumber + ( sizeof maxNumber / sizeof maxNumber[0] ) ) ) );
		}
		case 3: {
			int maxNumber[]           = {2, 1, 2};
			int expected              = 0;

			return verify_case( casenum, expected, RabbitNumbering().theCount( vector <int>( maxNumber, maxNumber + ( sizeof maxNumber / sizeof maxNumber[0] ) ) ) );
		}
		case 4: {
			int maxNumber[]           = {25, 489, 76, 98, 704, 98, 768, 39, 697, 8, 56, 74, 36, 95, 87, 2, 968, 4, 920, 54, 873, 90};
			int expected              = 676780400;

			return verify_case( casenum, expected, RabbitNumbering().theCount( vector <int>( maxNumber, maxNumber + ( sizeof maxNumber / sizeof maxNumber[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			int maxNumber[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, RabbitNumbering().theCount( vector <int>( maxNumber, maxNumber + ( sizeof maxNumber / sizeof maxNumber[0] ) ) ) );
		}*/
/*      case 6: {
			int maxNumber[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, RabbitNumbering().theCount( vector <int>( maxNumber, maxNumber + ( sizeof maxNumber / sizeof maxNumber[0] ) ) ) );
		}*/
/*      case 7: {
			int maxNumber[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, RabbitNumbering().theCount( vector <int>( maxNumber, maxNumber + ( sizeof maxNumber / sizeof maxNumber[0] ) ) ) );
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
