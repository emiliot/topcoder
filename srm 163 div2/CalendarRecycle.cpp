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

bool isleap(int year){
	if((year%4 == 0 && year%100 != 0) || year%400 == 0)return true;
	return false;
}

struct CalendarRecycle {
	int useAgain(int year) {
		int offset = 1;
		for(int i=2002; i<year; offset = ((isleap(i)? 367%7 : 366%7)+offset)%7, ++i);
		bool leap = isleap(year);
		int next = (((isleap(year)? 366:365)%7)+offset)%7;
		for(int i=year+1;;++i){
			if(next == offset && leap == isleap(i))return i;
			next = (((isleap(i)?366:365)%7)+next)%7;
		}
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
			int year                  = 2002;
			int expected              = 2013;

			return verify_case( casenum, expected, CalendarRecycle().useAgain( year ) );
		}
		case 1: {
			int year                  = 2013;
			int expected              = 2019;

			return verify_case( casenum, expected, CalendarRecycle().useAgain( year ) );
		}
		case 2: {
			int year                  = 2008;
			int expected              = 2036;

			return verify_case( casenum, expected, CalendarRecycle().useAgain( year ) );
		}
		case 3: {
			int year                  = 9999;
			int expected              = 10010;

			return verify_case( casenum, expected, CalendarRecycle().useAgain( year ) );
		}
		case 4: {
			int year                  = 2525;
			int expected              = 2531;

			return verify_case( casenum, expected, CalendarRecycle().useAgain( year ) );
		}

		// custom cases

/*      case 5: {
			int year                  = ;
			int expected              = ;

			return verify_case( casenum, expected, CalendarRecycle().useAgain( year ) );
		}*/
/*      case 6: {
			int year                  = ;
			int expected              = ;

			return verify_case( casenum, expected, CalendarRecycle().useAgain( year ) );
		}*/
/*      case 7: {
			int year                  = ;
			int expected              = ;

			return verify_case( casenum, expected, CalendarRecycle().useAgain( year ) );
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
