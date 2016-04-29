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

struct RollingDiceDivTwo {
	int minimumFaces(vector <string> rolls) {
		vector <int> v(rolls[0].size(), 0);
		for(int i=0, n=rolls.size(); i<n; ++i){
			sort(all(rolls[i]));
			for(int j=0, m=rolls[i].size(); j<m; ++j){
				v[j] = max(v[j], rolls[i][j] - '0');
			}
		}
		int res = 0;
		for(int i=0, n=v.size(); i<n; ++i)res+=v[i];
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
			string rolls[]            = {"137", "364", "115", "724"};
			int expected              = 14;

			return verify_case( casenum, expected, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof rolls[0] ) ) ) );
		}
		case 1: {
			string rolls[]            = {"1112", "1111", "1211", "1111"};
			int expected              = 5;

			return verify_case( casenum, expected, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof rolls[0] ) ) ) );
		}
		case 2: {
			string rolls[]            = {"24412", "56316", "66666", "45625"};
			int expected              = 30;

			return verify_case( casenum, expected, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof rolls[0] ) ) ) );
		}
		case 3: {
			string rolls[]            = {"931", "821", "156", "512", "129", "358", "555"};
			int expected              = 19;

			return verify_case( casenum, expected, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof rolls[0] ) ) ) );
		}
		case 4: {
			string rolls[]            = {"3", "7", "4", "2", "4"};
			int expected              = 7;

			return verify_case( casenum, expected, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof rolls[0] ) ) ) );
		}
		case 5: {
			string rolls[]            = {"281868247265686571829977999522", "611464285871136563343229916655", "716739845311113736768779647392", "779122814312329463718383927626", "571573431548647653632439431183", "547362375338962625957869719518", "539263489892486347713288936885", "417131347396232733384379841536"};
			int expected              = 176;

			return verify_case( casenum, expected, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof rolls[0] ) ) ) );
		}

		// custom cases

/*      case 6: {
			string rolls[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof rolls[0] ) ) ) );
		}*/
/*      case 7: {
			string rolls[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof rolls[0] ) ) ) );
		}*/
/*      case 8: {
			string rolls[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, RollingDiceDivTwo().minimumFaces( vector <string>( rolls, rolls + ( sizeof rolls / sizeof rolls[0] ) ) ) );
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
