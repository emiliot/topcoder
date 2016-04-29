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
typedef long long i64;
i64 memo[25][1010];
bool mark[25][1010];

i64 f(const int s, const int k, int i, int sum){
	if(i<1)return 0;
	if(i == 1)return s-sum;
	i64 &best = memo[i][sum];
	if(mark[i][sum])return best;
	mark[i][sum] = true;
	best = -1;
	for(int j=1; j<=s-sum; ++j)
		best = max(best,f(s,k,i-1,sum+j)*j);
	return best;
}

struct MaximalProduct {
  long long maximalProduct(int s, int k) {
	  memset(mark,false,sizeof(mark));
	  return(f(s,k,k,0));
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
	
	int verify_case( int casenum, const long long &expected, const long long &received ) { 
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
			int s                     = 10;
			int k                     = 3;
			long long expected        = 36LL;

			return verify_case( casenum, expected, MaximalProduct().maximalProduct( s, k ) );
		}
		case 1: {
			int s                     = 10;
			int k                     = 1;
			long long expected        = 10LL;

			return verify_case( casenum, expected, MaximalProduct().maximalProduct( s, k ) );
		}
		case 2: {
			int s                     = 10;
			int k                     = 10;
			long long expected        = 1LL;

			return verify_case( casenum, expected, MaximalProduct().maximalProduct( s, k ) );
		}
		case 3: {
			int s                     = 13;
			int k                     = 8;
			long long expected        = 32LL;

			return verify_case( casenum, expected, MaximalProduct().maximalProduct( s, k ) );
		}
		case 4: {
			int s                     = 7;
			int k                     = 2;
			long long expected        = 12LL;

			return verify_case( casenum, expected, MaximalProduct().maximalProduct( s, k ) );
		}

		// custom cases

/*      case 5: {
			int s                     = ;
			int k                     = ;
			long long expected        = LL;

			return verify_case( casenum, expected, MaximalProduct().maximalProduct( s, k ) );
		}*/
/*      case 6: {
			int s                     = ;
			int k                     = ;
			long long expected        = LL;

			return verify_case( casenum, expected, MaximalProduct().maximalProduct( s, k ) );
		}*/
/*      case 7: {
			int s                     = ;
			int k                     = ;
			long long expected        = LL;

			return verify_case( casenum, expected, MaximalProduct().maximalProduct( s, k ) );
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
