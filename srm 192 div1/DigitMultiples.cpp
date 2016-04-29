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
int memo[60][60];

string mult(string s, int fact){
	string res;
	for(int i=0, n=s.size(); i<n; ++i){
		int aux = (s[i]-'0')*fact;
		res+= ('0'+aux);
	}
	return res;
}

int f(string a, string b){
	const int n = a.size(), m = b.size();
	memset(memo,0,sizeof(memo));
	int best = 0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i-1]==b[j-1])memo[i][j] = memo[i-1][j-1]+1;
			else memo[i][j] = 0;
			best = max(best,memo[i][j]);
		}
	}
	return best;
}

struct DigitMultiples {
	int getLongest(string single, string multiple) {
		int best = 0;
		for(int i=0; i<10; ++i)
			best = max(best,f(mult(single,i),multiple));
		return best;
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
			string single             = "3211113321571";
			string multiple           = "5555266420";
			int expected              = 5;

			return verify_case( casenum, expected, DigitMultiples().getLongest( single, multiple ) );
		}
		case 1: {
			string single             = "100200300";
			string multiple           = "100400600";
			int expected              = 8;

			return verify_case( casenum, expected, DigitMultiples().getLongest( single, multiple ) );
		}
		case 2: {
			string single             = "111111111100000000000000000000000000000000000";
			string multiple           = "122333444455555666666777777788888888999999999";
			int expected              = 9;

			return verify_case( casenum, expected, DigitMultiples().getLongest( single, multiple ) );
		}
		case 3: {
			string single             = "000000000000";
			string multiple           = "000000000000";
			int expected              = 12;

			return verify_case( casenum, expected, DigitMultiples().getLongest( single, multiple ) );
		}
		case 4: {
			string single             = "11111111111";
			string multiple           = "11111111111";
			int expected              = 11;

			return verify_case( casenum, expected, DigitMultiples().getLongest( single, multiple ) );
		}
		case 5: {
			string single             = "89248987092734709478099";
			string multiple           = "00000000000000000000000";
			int expected              = 23;

			return verify_case( casenum, expected, DigitMultiples().getLongest( single, multiple ) );
		}
		case 6: {
			string single             = "11111111111111111111111111111111111111111111111111";
			string multiple           = "00000000000000000000000001111111111111111111111111";
			int expected              = 25;

			return verify_case( casenum, expected, DigitMultiples().getLongest( single, multiple ) );
		}

		// custom cases

     case 7: {
			string single             = "11111211312112212313113213321121222122323123223331";
			string multiple           = "12346612363621621636216126316363636216263661623261";
			int expected              = 4;

			return verify_case( casenum, expected, DigitMultiples().getLongest( single, multiple ) );
		}
/*      case 8: {
			string single             = ;
			string multiple           = ;
			int expected              = ;

			return verify_case( casenum, expected, DigitMultiples().getLongest( single, multiple ) );
		}*/
/*      case 9: {
			string single             = ;
			string multiple           = ;
			int expected              = ;

			return verify_case( casenum, expected, DigitMultiples().getLongest( single, multiple ) );
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
