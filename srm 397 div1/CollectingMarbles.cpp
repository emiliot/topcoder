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
int memo[1 << 14][11][21];
bool mark[1 << 14][11][21];

int f(vector <int> &v, const int bags, const int cap, int mask, int k, int left){
	if(mask == (1 << (int)v.size())-1){
		return 0;
	}
	if(k >= bags)return 0;
	int &best = memo[mask][k][left];
	if(mark[mask][k][left])return best;
	mark[mask][k][left] = true;

	best = f(v, bags, cap, mask, k+1, cap);
	for(int i=0, n=v.size(); i<n; ++i){
		if(!(mask & (1 << i))){
			if(v[i] <= left)
				best = max(best, f(v, bags, cap, mask | (1 << i), k, left - v[i]) + 1);
		}
	}
	return best;
}

struct CollectingMarbles {
	int mostMarbles(vector <int> v, int cap, int bags) {
		memset(mark, false, sizeof(mark));
		int res = f(v, bags, cap, 0, 0, cap);
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
			int marblesWeights[]      = { 2, 2, 2, 2, 2 };
			int bagCapacity           = 5;
			int numberOfBags          = 2;
			int expected              = 4;

			return verify_case( casenum, expected, CollectingMarbles().mostMarbles( vector <int>( marblesWeights, marblesWeights + ( sizeof marblesWeights / sizeof marblesWeights[0] ) ), bagCapacity, numberOfBags ) );
		}
		case 1: {
			int marblesWeights[]      = { 1, 3, 5, 2, 4 };
			int bagCapacity           = 5;
			int numberOfBags          = 2;
			int expected              = 4;

			return verify_case( casenum, expected, CollectingMarbles().mostMarbles( vector <int>( marblesWeights, marblesWeights + ( sizeof marblesWeights / sizeof marblesWeights[0] ) ), bagCapacity, numberOfBags ) );
		}
		case 2: {
			int marblesWeights[]      = { 7, 6, 6, 5 };
			int bagCapacity           = 12;
			int numberOfBags          = 2;
			int expected              = 4;

			return verify_case( casenum, expected, CollectingMarbles().mostMarbles( vector <int>( marblesWeights, marblesWeights + ( sizeof marblesWeights / sizeof marblesWeights[0] ) ), bagCapacity, numberOfBags ) );
		}
		case 3: {
			int marblesWeights[]      = { 2, 2, 2 };
			int bagCapacity           = 1;
			int numberOfBags          = 10;
			int expected              = 0;

			return verify_case( casenum, expected, CollectingMarbles().mostMarbles( vector <int>( marblesWeights, marblesWeights + ( sizeof marblesWeights / sizeof marblesWeights[0] ) ), bagCapacity, numberOfBags ) );
		}

		// custom cases

/*      case 4: {
			int marblesWeights[]      = ;
			int bagCapacity           = ;
			int numberOfBags          = ;
			int expected              = ;

			return verify_case( casenum, expected, CollectingMarbles().mostMarbles( vector <int>( marblesWeights, marblesWeights + ( sizeof marblesWeights / sizeof marblesWeights[0] ) ), bagCapacity, numberOfBags ) );
		}*/
/*      case 5: {
			int marblesWeights[]      = ;
			int bagCapacity           = ;
			int numberOfBags          = ;
			int expected              = ;

			return verify_case( casenum, expected, CollectingMarbles().mostMarbles( vector <int>( marblesWeights, marblesWeights + ( sizeof marblesWeights / sizeof marblesWeights[0] ) ), bagCapacity, numberOfBags ) );
		}*/
/*      case 6: {
			int marblesWeights[]      = ;
			int bagCapacity           = ;
			int numberOfBags          = ;
			int expected              = ;

			return verify_case( casenum, expected, CollectingMarbles().mostMarbles( vector <int>( marblesWeights, marblesWeights + ( sizeof marblesWeights / sizeof marblesWeights[0] ) ), bagCapacity, numberOfBags ) );
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
