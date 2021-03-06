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

int memo[60][60];
bool mark[60][60];
const int INF = 0x3f3f3f3f;

int f(string &s, int i, int j){
	if(i > j)return 0;
	if(i==j)return 1;

	int &best = memo[i][j];
	if(mark[i][j])return best;
	mark[i][j] = true;
	
	if(s[i] == ')')best = f(s,i+1,j) + 1;
	else{
		best = f(s, i+1, j) + 1;
		for(int k=i+1; k<=j; ++k){
			if(s[k] == ')'){
				best = min(best, f(s, i+1,k-1) + f(s,k+1,j));
			}
		}
	}
	
	return best;
}

struct MissingParentheses {
	int countCorrections(string par) {
		memset(mark, false, sizeof(mark));
		return f(par, 0, (int)par.size()-1);
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
			string par                = "(()(()";
			int expected              = 2;

			return verify_case( casenum, expected, MissingParentheses().countCorrections( par ) );
		}
		case 1: {
			string par                = "()()(()";
			int expected              = 1;

			return verify_case( casenum, expected, MissingParentheses().countCorrections( par ) );
		}
		case 2: {
			string par                = "(())(()())";
			int expected              = 0;

			return verify_case( casenum, expected, MissingParentheses().countCorrections( par ) );
		}
		case 3: {
			string par                = "())(())((()))))()((())))()())())())()()()";
			int expected              = 7;

			return verify_case( casenum, expected, MissingParentheses().countCorrections( par ) );
		}

		// custom cases

      case 4: {
			string par                = "((";
			int expected              = 2;

			return verify_case( casenum, expected, MissingParentheses().countCorrections( par ) );
		}
/*      case 5: {
			string par                = ;
			int expected              = ;

			return verify_case( casenum, expected, MissingParentheses().countCorrections( par ) );
		}*/
/*      case 6: {
			string par                = ;
			int expected              = ;

			return verify_case( casenum, expected, MissingParentheses().countCorrections( par ) );
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
