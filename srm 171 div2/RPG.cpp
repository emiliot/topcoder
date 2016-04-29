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

struct RPG {
	vector <int> dieRolls(vector <string> dice) {
		int low = 0, high = 0;
		double avg = 0.0;
		for(int i=0, m=dice.size(); i<m; ++i){
			stringstream iss(dice[i]);
			int n, x; char crap;
			iss >> n >> crap >> x;
			low += n, high += (n*x);
			avg += ((double)(n*(x+1))/2.0);
		}
		avg = floor(avg);
		vector <int> res (3);
		res[0] = low, res[1] = high, res[2] = (int)(avg);
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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case( int casenum, const vector <int> &expected, const vector <int> &received ) { 
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
			string dice[]             = {"3d6"};
			int expected[]            = { 3,  18,  10 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) ) );
		}
		case 1: {
			string dice[]             = {"3d4","1d6"};
			int expected[]            = { 4,  18,  11 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) ) );
		}
		case 2: {
			string dice[]             = {"6d5","10d10","10d20"};
			int expected[]            = { 26,  330,  178 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) ) );
		}
		case 3: {
			string dice[]             = {"1d2","2d2","4d2","6d2","8d2"};
			int expected[]            = { 21,  42,  31 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			string dice[]             = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) ) );
		}*/
/*      case 5: {
			string dice[]             = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) ) );
		}*/
/*      case 6: {
			string dice[]             = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), RPG().dieRolls( vector <string>( dice, dice + ( sizeof dice / sizeof dice[0] ) ) ) );
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
