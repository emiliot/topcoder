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

bool mark[100][100];

struct TheMoviesLevelOneDivTwo {
	int find(int n, int m, vector <int> row, vector <int> seat) {
		memset(mark,false,sizeof(mark));
		for(int i=0, w=row.size(); i<w; ++i)
			mark[row[i]][seat[i]] = true;
		int res = 0;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m-1; ++j){
				if(!mark[i][j] && !mark[i][j+1])++res;
			}
		}
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
			int n                     = 2;
			int m                     = 3;
			int row[]                 = {1, 2};
			int seat[]                = {2, 3};
			int expected              = 1;

			return verify_case( casenum, expected, TheMoviesLevelOneDivTwo().find( n, m, vector <int>( row, row + ( sizeof row / sizeof row[0] ) ), vector <int>( seat, seat + ( sizeof seat / sizeof seat[0] ) ) ) );
		}
		case 1: {
			int n                     = 2;
			int m                     = 3;
			int row[]                 = {1, 1, 1, 2, 2, 2};
			int seat[]                = {1, 2, 3, 1, 2, 3};
			int expected              = 0;

			return verify_case( casenum, expected, TheMoviesLevelOneDivTwo().find( n, m, vector <int>( row, row + ( sizeof row / sizeof row[0] ) ), vector <int>( seat, seat + ( sizeof seat / sizeof seat[0] ) ) ) );
		}
		case 2: {
			int n                     = 4;
			int m                     = 7;
			int row[]                 = {1};
			int seat[]                = {1};
			int expected              = 23;

			return verify_case( casenum, expected, TheMoviesLevelOneDivTwo().find( n, m, vector <int>( row, row + ( sizeof row / sizeof row[0] ) ), vector <int>( seat, seat + ( sizeof seat / sizeof seat[0] ) ) ) );
		}
		case 3: {
			int n                     = 10;
			int m                     = 8;
			int row[]                 = {1, 9, 6, 10, 6, 7, 9, 3, 9, 2};
			int seat[]                = {7, 7, 3, 3, 7, 1, 5, 1, 6, 2};
			int expected              = 54;

			return verify_case( casenum, expected, TheMoviesLevelOneDivTwo().find( n, m, vector <int>( row, row + ( sizeof row / sizeof row[0] ) ), vector <int>( seat, seat + ( sizeof seat / sizeof seat[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int m                     = ;
			int row[]                 = ;
			int seat[]                = ;
			int expected              = ;

			return verify_case( casenum, expected, TheMoviesLevelOneDivTwo().find( n, m, vector <int>( row, row + ( sizeof row / sizeof row[0] ) ), vector <int>( seat, seat + ( sizeof seat / sizeof seat[0] ) ) ) );
		}*/
/*      case 5: {
			int n                     = ;
			int m                     = ;
			int row[]                 = ;
			int seat[]                = ;
			int expected              = ;

			return verify_case( casenum, expected, TheMoviesLevelOneDivTwo().find( n, m, vector <int>( row, row + ( sizeof row / sizeof row[0] ) ), vector <int>( seat, seat + ( sizeof seat / sizeof seat[0] ) ) ) );
		}*/
/*      case 6: {
			int n                     = ;
			int m                     = ;
			int row[]                 = ;
			int seat[]                = ;
			int expected              = ;

			return verify_case( casenum, expected, TheMoviesLevelOneDivTwo().find( n, m, vector <int>( row, row + ( sizeof row / sizeof row[0] ) ), vector <int>( seat, seat + ( sizeof seat / sizeof seat[0] ) ) ) );
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
