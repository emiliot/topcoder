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
int memo[60][1010];
bool mark[60][1010];

int f(const vector<int> &v,const int top, int i, int w){
	if(w<0 || w>top)return -1;
	if(i>=v.size())return w;
	int &best = memo[i][w];
	if(mark[i][w])return best;
	mark[i][w] = true;
	best = max(f(v,top,i+1,w+v[i]),f(v,top,i+1,w-v[i]));
	return best;
}

struct ChangingSounds {
  int maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) {
	  memset(mark,false,sizeof(mark));
	  return f(changeIntervals,maxLevel,0,beginLevel);
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
			int changeIntervals[]     = {5, 3, 7};
			int beginLevel            = 5;
			int maxLevel              = 10;
			int expected              = 10;

			return verify_case( casenum, expected, ChangingSounds().maxFinal( vector <int>( changeIntervals, changeIntervals + ( sizeof changeIntervals / sizeof changeIntervals[0] ) ), beginLevel, maxLevel ) );
		}
		case 1: {
			int changeIntervals[]     = {15, 2, 9, 10};
			int beginLevel            = 8;
			int maxLevel              = 20;
			int expected              = -1;

			return verify_case( casenum, expected, ChangingSounds().maxFinal( vector <int>( changeIntervals, changeIntervals + ( sizeof changeIntervals / sizeof changeIntervals[0] ) ), beginLevel, maxLevel ) );
		}
		case 2: {
			int changeIntervals[]     = {74,39,127,95,63,140,99,96,154,18,137,162,14,88};
			int beginLevel            = 40;
			int maxLevel              = 243;
			int expected              = 238;

			return verify_case( casenum, expected, ChangingSounds().maxFinal( vector <int>( changeIntervals, changeIntervals + ( sizeof changeIntervals / sizeof changeIntervals[0] ) ), beginLevel, maxLevel ) );
		}

		// custom cases

/*      case 3: {
			int changeIntervals[]     = ;
			int beginLevel            = ;
			int maxLevel              = ;
			int expected              = ;

			return verify_case( casenum, expected, ChangingSounds().maxFinal( vector <int>( changeIntervals, changeIntervals + ( sizeof changeIntervals / sizeof changeIntervals[0] ) ), beginLevel, maxLevel ) );
		}*/
/*      case 4: {
			int changeIntervals[]     = ;
			int beginLevel            = ;
			int maxLevel              = ;
			int expected              = ;

			return verify_case( casenum, expected, ChangingSounds().maxFinal( vector <int>( changeIntervals, changeIntervals + ( sizeof changeIntervals / sizeof changeIntervals[0] ) ), beginLevel, maxLevel ) );
		}*/
/*      case 5: {
			int changeIntervals[]     = ;
			int beginLevel            = ;
			int maxLevel              = ;
			int expected              = ;

			return verify_case( casenum, expected, ChangingSounds().maxFinal( vector <int>( changeIntervals, changeIntervals + ( sizeof changeIntervals / sizeof changeIntervals[0] ) ), beginLevel, maxLevel ) );
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
