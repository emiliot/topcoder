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

int fact[11];

int f(const int n, int pos){
	int res = fact[n-1];
	for(int i=1; i<=pos; ++i){
		res += (fact[pos]/fact[pos-i])*fact[n-1-i];
	}
	return res;
}

struct BagOfHolding {
	double oddsReachable(vector <int> v, int item) {
		int value = v[item],n = v.size(),pos=0;
		fact[0] = 1; for(int i=1; i<=n;++i)fact[i]=fact[i-1]*i;
		sort(v.begin(),v.end());
		
		pos = lower_bound(v.begin(),v.end(),value) - v.begin();
		double res;
		if(pos == n-1)return 1.0;//cable
		else if(pos == 0)res = (double)(fact[n-1])/double(fact[n]);
		else res = (double)(f(n,pos))/double(fact[n]);
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	
	int verify_case( int casenum, const double &expected, const double &received ) { 
		cerr << "Example " << casenum << "... "; 
		cerr.precision(9); 
		if ( topcoder_fequ( expected, received ) ) {
			cerr << "PASSED"; 
			double rerr = moj_relative_error( expected, received ); 
			if ( rerr > 0 ) cerr << " (relative error " << rerr << ")";
			cerr << endl;
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
			int sizes[]               = {1,2,3};
			int item                  = 1;
			double expected           = 0.5;

			return verify_case( casenum, expected, BagOfHolding().oddsReachable( vector <int>( sizes, sizes + ( sizeof sizes / sizeof sizes[0] ) ), item ) );
		}
		case 1: {
			int sizes[]               = {1,2,3};
			int item                  = 2;
			double expected           = 1.0;

			return verify_case( casenum, expected, BagOfHolding().oddsReachable( vector <int>( sizes, sizes + ( sizeof sizes / sizeof sizes[0] ) ), item ) );
		}
		case 2: {
			int sizes[]               = {1,1,2,3};
			int item                  = 2;
			double expected           = 0.5;

			return verify_case( casenum, expected, BagOfHolding().oddsReachable( vector <int>( sizes, sizes + ( sizeof sizes / sizeof sizes[0] ) ), item ) );
		}
		case 3: {
			int sizes[]               = {1,2,3,4,5,6,7,8,9,10};
			int item                  = 4;
			double expected           = 0.16666666666666666;

			return verify_case( casenum, expected, BagOfHolding().oddsReachable( vector <int>( sizes, sizes + ( sizeof sizes / sizeof sizes[0] ) ), item ) );
		}

		// custom cases

/*      case 4: {
			int sizes[]               = ;
			int item                  = ;
			double expected           = ;

			return verify_case( casenum, expected, BagOfHolding().oddsReachable( vector <int>( sizes, sizes + ( sizeof sizes / sizeof sizes[0] ) ), item ) );
		}*/
/*      case 5: {
			int sizes[]               = ;
			int item                  = ;
			double expected           = ;

			return verify_case( casenum, expected, BagOfHolding().oddsReachable( vector <int>( sizes, sizes + ( sizeof sizes / sizeof sizes[0] ) ), item ) );
		}*/
/*      case 6: {
			int sizes[]               = ;
			int item                  = ;
			double expected           = ;

			return verify_case( casenum, expected, BagOfHolding().oddsReachable( vector <int>( sizes, sizes + ( sizeof sizes / sizeof sizes[0] ) ), item ) );
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
