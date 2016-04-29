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

double f(int n, double dw, int size, int src, int dest, bool dir){
	double res = 360.0 * (double)(n);
	int offset = 0;
	if(!dir)swap(src,dest);
	if(src > dest)offset = size - (src - dest);
	else offset = dest -src;
	res += dw * (int)(offset);
	return res;
}

struct CombinationLock {
	double degreesTurned(vector <int> combo, int size, int start) {
		int n = combo.size(), p = start;
		double dw = 360.0/(double)(size);
		double res = 0.0; 
		bool dir = true;
		for(int i=0; i<n; ++i){
			res += f(n-i,dw,size,p,combo[i],dir);
			p = combo[i];
			dir = !dir;
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
			int combo[]               = {10,20,30};
			int size                  = 40;
			int start                 = 6;
			double expected           = 2556.0;

			return verify_case( casenum, expected, CombinationLock().degreesTurned( vector <int>( combo, combo + ( sizeof combo / sizeof combo[0] ) ), size, start ) );
		}
		case 1: {
			int combo[]               = {0,50,99};
			int size                  = 100;
			int start                 = 65;
			double expected           = 2642.4;

			return verify_case( casenum, expected, CombinationLock().degreesTurned( vector <int>( combo, combo + ( sizeof combo / sizeof combo[0] ) ), size, start ) );
		}
		case 2: {
			int combo[]               = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};
			int size                  = 10;
			int start                 = 5;
			double expected           = 79344.0;

			return verify_case( casenum, expected, CombinationLock().degreesTurned( vector <int>( combo, combo + ( sizeof combo / sizeof combo[0] ) ), size, start ) );
		}
		case 3: {
			int combo[]               = {64,93,87,3,22,53,64,53,11,90,11,59,30,6,11,17,72,0,38,55};
			int size                  = 97;
			int start                 = 26;
			double expected           = 79166.59793814432;

			return verify_case( casenum, expected, CombinationLock().degreesTurned( vector <int>( combo, combo + ( sizeof combo / sizeof combo[0] ) ), size, start ) );
		}

		// custom cases

/*      case 4: {
			int combo[]               = ;
			int size                  = ;
			int start                 = ;
			double expected           = ;

			return verify_case( casenum, expected, CombinationLock().degreesTurned( vector <int>( combo, combo + ( sizeof combo / sizeof combo[0] ) ), size, start ) );
		}*/
/*      case 5: {
			int combo[]               = ;
			int size                  = ;
			int start                 = ;
			double expected           = ;

			return verify_case( casenum, expected, CombinationLock().degreesTurned( vector <int>( combo, combo + ( sizeof combo / sizeof combo[0] ) ), size, start ) );
		}*/
/*      case 6: {
			int combo[]               = ;
			int size                  = ;
			int start                 = ;
			double expected           = ;

			return verify_case( casenum, expected, CombinationLock().degreesTurned( vector <int>( combo, combo + ( sizeof combo / sizeof combo[0] ) ), size, start ) );
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
