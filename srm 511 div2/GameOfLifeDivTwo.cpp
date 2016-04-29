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

struct GameOfLifeDivTwo {
	string theSimulation(string init, int T) {
		string aux = init;
		for(int t=0; t<T; ++t){
			for(int i=0, n=init.size(); i<n; ++i){
				int k;
				if(i==0)
					k = init[n-1] - '0' + init[i] - '0' + init[(i+1)%n] - '0';
				else
					k = init[i-1] - '0' + init[i] - '0' + init[(i+1)%n] - '0';
				if(k >=2)aux[i] = '1';
				else aux[i] = '0';
			}
			init = aux;
		}
		return init;
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
			string init               = "01010";
			int T                     = 2;
			string expected           = "00000";

			return verify_case( casenum, expected, GameOfLifeDivTwo().theSimulation( init, T ) );
		}
		case 1: {
			string init               = "010101";
			int T                     = 5;
			string expected           = "101010";

			return verify_case( casenum, expected, GameOfLifeDivTwo().theSimulation( init, T ) );
		}
		case 2: {
			string init               = "111010";
			int T                     = 58;
			string expected           = "111111";

			return verify_case( casenum, expected, GameOfLifeDivTwo().theSimulation( init, T ) );
		}
		case 3: {
			string init               = "111111111";
			int T                     = 511;
			string expected           = "111111111";

			return verify_case( casenum, expected, GameOfLifeDivTwo().theSimulation( init, T ) );
		}
		case 4: {
			string init               = "110010000010111110010100001001";
			int T                     = 1000;
			string expected           = "110000000001111110000000000001";

			return verify_case( casenum, expected, GameOfLifeDivTwo().theSimulation( init, T ) );
		}
		case 5: {
			string init               = "00101110011";
			int T                     = 0;
			string expected           = "00101110011";

			return verify_case( casenum, expected, GameOfLifeDivTwo().theSimulation( init, T ) );
		}

		// custom cases

/*      case 6: {
			string init               = ;
			int T                     = ;
			string expected           = ;

			return verify_case( casenum, expected, GameOfLifeDivTwo().theSimulation( init, T ) );
		}*/
/*      case 7: {
			string init               = ;
			int T                     = ;
			string expected           = ;

			return verify_case( casenum, expected, GameOfLifeDivTwo().theSimulation( init, T ) );
		}*/
/*      case 8: {
			string init               = ;
			int T                     = ;
			string expected           = ;

			return verify_case( casenum, expected, GameOfLifeDivTwo().theSimulation( init, T ) );
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
