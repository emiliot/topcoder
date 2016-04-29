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

struct LotteryTicket {
	string buy(int price, int b1, int b2, int b3, int b4) {
		int b[] = {b1,b2,b3,b4};
		for(int i=0; i<16; ++i){
			int sum = 0;
			for(int j=0; j<4; ++j)
				if(i&(1<<j))sum+=b[j];
			if(sum == price)return "POSSIBLE";
		}
		return "IMPOSSIBLE";
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
	
	int verify_case( int casenum, const string &expected, const string &received ) { 
		cerr << "Example " << casenum << "... "; 
		if ( expected == received ) {
			cerr << "PASSED" << endl;
			return 1;
		} else {
			cerr << "FAILED" << endl;
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
			return 0;
		}
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int price                 = 10;
			int b1                    = 1;
			int b2                    = 5;
			int b3                    = 10;
			int b4                    = 50;
			string expected           = "POSSIBLE";

			return verify_case( casenum, expected, LotteryTicket().buy( price, b1, b2, b3, b4 ) );
		}
		case 1: {
			int price                 = 15;
			int b1                    = 1;
			int b2                    = 5;
			int b3                    = 10;
			int b4                    = 50;
			string expected           = "POSSIBLE";

			return verify_case( casenum, expected, LotteryTicket().buy( price, b1, b2, b3, b4 ) );
		}
		case 2: {
			int price                 = 65;
			int b1                    = 1;
			int b2                    = 5;
			int b3                    = 10;
			int b4                    = 50;
			string expected           = "POSSIBLE";

			return verify_case( casenum, expected, LotteryTicket().buy( price, b1, b2, b3, b4 ) );
		}
		case 3: {
			int price                 = 66;
			int b1                    = 1;
			int b2                    = 5;
			int b3                    = 10;
			int b4                    = 50;
			string expected           = "POSSIBLE";

			return verify_case( casenum, expected, LotteryTicket().buy( price, b1, b2, b3, b4 ) );
		}
		case 4: {
			int price                 = 1000;
			int b1                    = 999;
			int b2                    = 998;
			int b3                    = 997;
			int b4                    = 996;
			string expected           = "IMPOSSIBLE";

			return verify_case( casenum, expected, LotteryTicket().buy( price, b1, b2, b3, b4 ) );
		}
		case 5: {
			int price                 = 20;
			int b1                    = 5;
			int b2                    = 5;
			int b3                    = 5;
			int b4                    = 5;
			string expected           = "POSSIBLE";

			return verify_case( casenum, expected, LotteryTicket().buy( price, b1, b2, b3, b4 ) );
		}
		case 6: {
			int price                 = 2;
			int b1                    = 1;
			int b2                    = 5;
			int b3                    = 10;
			int b4                    = 50;
			string expected           = "IMPOSSIBLE";

			return verify_case( casenum, expected, LotteryTicket().buy( price, b1, b2, b3, b4 ) );
		}

		// custom cases
      case 7: {
			int price                 = 7;
			int b1                    = 1;
			int b2                    = 2;
			int b3                    = 3;
			int b4                    = 3;
			string expected           = "POSSIBLE";

			return verify_case( casenum, expected, LotteryTicket().buy( price, b1, b2, b3, b4 ) );
		}
/*      case 8: {
			int price                 = ;
			int b1                    = ;
			int b2                    = ;
			int b3                    = ;
			int b4                    = ;
			string expected           = ;

			return verify_case( casenum, expected, LotteryTicket().buy( price, b1, b2, b3, b4 ) );
		}*/
/*      case 9: {
			int price                 = ;
			int b1                    = ;
			int b2                    = ;
			int b3                    = ;
			int b4                    = ;
			string expected           = ;

			return verify_case( casenum, expected, LotteryTicket().buy( price, b1, b2, b3, b4 ) );
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
