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
// BEGIN CUT HERE
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

struct DiskSpace {
	int minDrives(vector <int> used, vector <int> total) {
		int x = 0;
		for(int i=0, n=used.size(); i<n; x+=used[i],++i);
		sort(total.rbegin(),total.rend());
		int count = 0;
		for(int i=0, n=total.size(); i<n; ++i){
			if(x > 0)x-=total[i],++count;
			else break;
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
			int used[]                = {300,525,110};
			int total[]               = {350,600,115};
			int expected              = 2;

			return verify_case( casenum, expected, DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) ) );
		}
		case 1: {
			int used[]                = {1,200,200,199,200,200};
			int total[]               = {1000,200,200,200,200,200};
			int expected              = 1;

			return verify_case( casenum, expected, DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) ) );
		}
		case 2: {
			int used[]                = {750,800,850,900,950};
			int total[]               = {800,850,900,950,1000};
			int expected              = 5;

			return verify_case( casenum, expected, DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) ) );
		}
		case 3: {
			int used[]                = {49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,  49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49,49};
			int total[]               = {50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,  50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50};
			int expected              = 49;

			return verify_case( casenum, expected, DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) ) );
		}
		case 4: {
			int used[]                = {331,242,384,366,428,114,145,89,381,170,329,190,482,246,2,38,220,290,402,385};
			int total[]               = {992,509,997,946,976,873,771,565,693,714,755,878,897,789,969,727,765,521,961,906};
			int expected              = 6;

			return verify_case( casenum, expected, DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			int used[]                = ;
			int total[]               = ;
			int expected              = ;

			return verify_case( casenum, expected, DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) ) );
		}*/
/*      case 6: {
			int used[]                = ;
			int total[]               = ;
			int expected              = ;

			return verify_case( casenum, expected, DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) ) );
		}*/
/*      case 7: {
			int used[]                = ;
			int total[]               = ;
			int expected              = ;

			return verify_case( casenum, expected, DiskSpace().minDrives( vector <int>( used, used + ( sizeof used / sizeof used[0] ) ), vector <int>( total, total + ( sizeof total / sizeof total[0] ) ) ) );
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
