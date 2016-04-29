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

bool ok(i64 loan, i64 a, int term, i64 pay){
	for(int i=0; i<(term * 12) && loan > 0LL; ++i){
		i64 last = loan;
		loan -= pay;
		loan = loan + ((a * loan) + 11999)/12000;
		if(loan >= last)return false;
	}
	return loan <= 0LL;
}

struct Mortgage {
	int monthlyPayment(int loan, int interest, int term) {
		i64 high = loan+1, low = 1;
		while(low < high){
			int mid = (low + high)/2;
			if(ok(loan, interest, term, mid))high = mid;
			else low = mid + 1;
		}
		return (int)low;
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
			int loan                  = 1000;
			int interest              = 50;
			int term                  = 1;
			int expected              = 86;

			return verify_case( casenum, expected, Mortgage().monthlyPayment( loan, interest, term ) );
		}
		case 1: {
			int loan                  = 2000000000;
			int interest              = 6000;
			int term                  = 1;
			int expected              = 671844808;

			return verify_case( casenum, expected, Mortgage().monthlyPayment( loan, interest, term ) );
		}
		case 2: {
			int loan                  = 1000000;
			int interest              = 1000000;
			int term                  = 1000;
			int expected              = 988143;

			return verify_case( casenum, expected, Mortgage().monthlyPayment( loan, interest, term ) );
		}
		case 3: {
			int loan                  = 1000000;
			int interest              = 129;
			int term                  = 30;
			int expected              = 10868;

			return verify_case( casenum, expected, Mortgage().monthlyPayment( loan, interest, term ) );
		}
		case 4: {
			int loan                  = 1999999999;
			int interest              = 1000000;
			int term                  = 1;
			int expected              = 1976284585;

			return verify_case( casenum, expected, Mortgage().monthlyPayment( loan, interest, term ) );
		}

		// custom cases

/*      case 5: {
			int loan                  = ;
			int interest              = ;
			int term                  = ;
			int expected              = ;

			return verify_case( casenum, expected, Mortgage().monthlyPayment( loan, interest, term ) );
		}*/
/*      case 6: {
			int loan                  = ;
			int interest              = ;
			int term                  = ;
			int expected              = ;

			return verify_case( casenum, expected, Mortgage().monthlyPayment( loan, interest, term ) );
		}*/
/*      case 7: {
			int loan                  = ;
			int interest              = ;
			int term                  = ;
			int expected              = ;

			return verify_case( casenum, expected, Mortgage().monthlyPayment( loan, interest, term ) );
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
