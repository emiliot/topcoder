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
const int INF = 0x3f3f3f3f;
int memo[60][60];
bool mark[60][60];
int n, m;

int f(vector <string> &h, vector <string> &v, int i, int j){
	if(i == n && j == m)return 0;
	if(i > n || j > m)return INF;

	int &best = memo[i][j];
	if(mark[i][j])return best;
	mark[i][j] = true;
	best = 0;

	if(i < n)best = max(best, f(h, v, i+1, j) + v[i][j] - '0');
	if(j < m)best = max(best, f(h, v, i, j+1) + h[i][j] - '0');

	return best;
}

struct PasswordXGrid {
	int minSum(vector <string> horizontal, vector <string> vertical) {
		memset(mark, false, sizeof(mark));
		n = (int) vertical.size(), m = (int) horizontal[0].size();
		return f(horizontal, vertical, 0, 0);
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
			string horizontal[]       = {"1","4"};
			string vertical[]         = {"32"};
			int expected              = 7;

			return verify_case( casenum, expected, PasswordXGrid().minSum( vector <string>( horizontal, horizontal + ( sizeof horizontal / sizeof horizontal[0] ) ), vector <string>( vertical, vertical + ( sizeof vertical / sizeof vertical[0] ) ) ) );
		}
		case 1: {
			string horizontal[]       = {"47", "59"};
			string vertical[]         = {"361"};
			int expected              = 19;

			return verify_case( casenum, expected, PasswordXGrid().minSum( vector <string>( horizontal, horizontal + ( sizeof horizontal / sizeof horizontal[0] ) ), vector <string>( vertical, vertical + ( sizeof vertical / sizeof vertical[0] ) ) ) );
		}
		case 2: {
			string horizontal[]       = {"36", "23", "49"};
			string vertical[]         = {"890", "176"};
			int expected              = 28;

			return verify_case( casenum, expected, PasswordXGrid().minSum( vector <string>( horizontal, horizontal + ( sizeof horizontal / sizeof horizontal[0] ) ), vector <string>( vertical, vertical + ( sizeof vertical / sizeof vertical[0] ) ) ) );
		}
		case 3: {
			string horizontal[]       = {"8888585","5888585"};
			string vertical[]         = {"58585858"};
			int expected              = 58;

			return verify_case( casenum, expected, PasswordXGrid().minSum( vector <string>( horizontal, horizontal + ( sizeof horizontal / sizeof horizontal[0] ) ), vector <string>( vertical, vertical + ( sizeof vertical / sizeof vertical[0] ) ) ) );
		}
		case 4: {
			string horizontal[]       = {"7777777","7777777","7777777","7777777"};
			string vertical[]         = {"44444444","44444444","44444444"};
			int expected              = 61;

			return verify_case( casenum, expected, PasswordXGrid().minSum( vector <string>( horizontal, horizontal + ( sizeof horizontal / sizeof horizontal[0] ) ), vector <string>( vertical, vertical + ( sizeof vertical / sizeof vertical[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string horizontal[]       = ;
			string vertical[]         = ;
			int expected              = ;

			return verify_case( casenum, expected, PasswordXGrid().minSum( vector <string>( horizontal, horizontal + ( sizeof horizontal / sizeof horizontal[0] ) ), vector <string>( vertical, vertical + ( sizeof vertical / sizeof vertical[0] ) ) ) );
		}*/
/*      case 6: {
			string horizontal[]       = ;
			string vertical[]         = ;
			int expected              = ;

			return verify_case( casenum, expected, PasswordXGrid().minSum( vector <string>( horizontal, horizontal + ( sizeof horizontal / sizeof horizontal[0] ) ), vector <string>( vertical, vertical + ( sizeof vertical / sizeof vertical[0] ) ) ) );
		}*/
/*      case 7: {
			string horizontal[]       = ;
			string vertical[]         = ;
			int expected              = ;

			return verify_case( casenum, expected, PasswordXGrid().minSum( vector <string>( horizontal, horizontal + ( sizeof horizontal / sizeof horizontal[0] ) ), vector <string>( vertical, vertical + ( sizeof vertical / sizeof vertical[0] ) ) ) );
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
