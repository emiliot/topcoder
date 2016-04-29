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

struct P8XMatrixTransformation {
	string solve(vector <string> v0, vector <string> v1) {
		int a=0, b=0, n=v0.size(), m=v0[0].size();
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(v0[i][j] == '1')++a;
				if(v1[i][j] == '1')++b;
			}
		}
		return a==b?"YES":"NO";
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
			string original[]         = {"01" ,"11"};
			string target[]           = {"11" ,"10"};
			string expected           = "YES";

			return verify_case( casenum, expected, P8XMatrixTransformation().solve( vector <string>( original, original + ( sizeof original / sizeof original[0] ) ), vector <string>( target, target + ( sizeof target / sizeof target[0] ) ) ) );
		}
		case 1: {
			string original[]         = {"0111" ,"0011"};
			string target[]           = {"1011" ,"1100"};
			string expected           = "YES";

			return verify_case( casenum, expected, P8XMatrixTransformation().solve( vector <string>( original, original + ( sizeof original / sizeof original[0] ) ), vector <string>( target, target + ( sizeof target / sizeof target[0] ) ) ) );
		}
		case 2: {
			string original[]         = {"0"};
			string target[]           = {"1"};
			string expected           = "NO";

			return verify_case( casenum, expected, P8XMatrixTransformation().solve( vector <string>( original, original + ( sizeof original / sizeof original[0] ) ), vector <string>( target, target + ( sizeof target / sizeof target[0] ) ) ) );
		}
		case 3: {
			string original[]         = {"1111" ,"1111" ,"0000" ,"0000"};
			string target[]           = {"1111" ,"1111" ,"0000" ,"0000"};
			string expected           = "YES";

			return verify_case( casenum, expected, P8XMatrixTransformation().solve( vector <string>( original, original + ( sizeof original / sizeof original[0] ) ), vector <string>( target, target + ( sizeof target / sizeof target[0] ) ) ) );
		}
		case 4: {
			string original[]         = {"0110" ,"1001" ,"0110"};
			string target[]           = {"1111" ,"0110" ,"0000"};
			string expected           = "YES";

			return verify_case( casenum, expected, P8XMatrixTransformation().solve( vector <string>( original, original + ( sizeof original / sizeof original[0] ) ), vector <string>( target, target + ( sizeof target / sizeof target[0] ) ) ) );
		}
		case 5: {
			string original[]         = {"0000" ,"1111" ,"0000"};
			string target[]           = {"1111" ,"0000" ,"1111"};
			string expected           = "NO";

			return verify_case( casenum, expected, P8XMatrixTransformation().solve( vector <string>( original, original + ( sizeof original / sizeof original[0] ) ), vector <string>( target, target + ( sizeof target / sizeof target[0] ) ) ) );
		}

		// custom cases

/*      case 6: {
			string original[]         = ;
			string target[]           = ;
			string expected           = ;

			return verify_case( casenum, expected, P8XMatrixTransformation().solve( vector <string>( original, original + ( sizeof original / sizeof original[0] ) ), vector <string>( target, target + ( sizeof target / sizeof target[0] ) ) ) );
		}*/
/*      case 7: {
			string original[]         = ;
			string target[]           = ;
			string expected           = ;

			return verify_case( casenum, expected, P8XMatrixTransformation().solve( vector <string>( original, original + ( sizeof original / sizeof original[0] ) ), vector <string>( target, target + ( sizeof target / sizeof target[0] ) ) ) );
		}*/
/*      case 8: {
			string original[]         = ;
			string target[]           = ;
			string expected           = ;

			return verify_case( casenum, expected, P8XMatrixTransformation().solve( vector <string>( original, original + ( sizeof original / sizeof original[0] ) ), vector <string>( target, target + ( sizeof target / sizeof target[0] ) ) ) );
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
