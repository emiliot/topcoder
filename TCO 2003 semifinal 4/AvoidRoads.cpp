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

i64 memo[105][105];
bool markRows[105][105];
bool markCols[105][105];

struct AvoidRoads {
	long long numWays(int width, int height, vector <string> bad) {
		memset(markRows,false,sizeof(markRows));
		memset(markCols,false,sizeof(markCols));
		for(int i=0, n=bad.size(); i<n; ++i){
			istringstream iss (bad[i]);
			int a, b, c, d;
			iss >> a >> b >> c >> d;
			if(a == c){
				if(d < b)swap(b,d);
				for(int j=b; j<d; ++j)
					markRows[j][a] = true;
			}else if(b == d){
				if(c < a)swap(c,a);
				for(int j=a; j<c; ++j)
					markCols[b][j] = true;
			}
		}
		
		memo[0][0] = 0LL;
		bool ok = true;
		for(int i=1; i<=width; ++i){
			if(markCols[0][i-1])ok = false;
			memo[0][i] = ok? 1LL  : 0LL;
		}
		ok = true;
		for(int i=1; i<=height; ++i){
			if(markRows[i-1][0])ok = false;
			memo[i][0] = ok? 1LL : 0LL;
		}
		
		for(int i=1; i<=height; ++i){
			for(int j=1; j<=width; ++j){
				memo[i][j] = 0LL;
				int up = i-1, left = j-1;
				if(up >= 0 && (!markRows[up][j]))
					memo[i][j] += memo[up][j];
				if(left >= 0 && (!markCols[i][left]))
					memo[i][j] += memo[i][left];
			}
		}
		return memo[height][width];
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
	
	int verify_case( int casenum, const long long &expected, const long long &received ) { 
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
			int width                 = 6;
			int height                = 6;
			string bad[]              = {"0 0 0 1","6 6 5 6"};
			long long expected        = 252LL;

			return verify_case( casenum, expected, AvoidRoads().numWays( width, height, vector <string>( bad, bad + ( sizeof bad / sizeof bad[0] ) ) ) );
		}
		case 1: {
			int width                 = 1;
			int height                = 1;
			string bad[]              = {"0 0 0 0"};
			long long expected        = 2LL;

			return verify_case( casenum, expected, AvoidRoads().numWays( width, height, vector <string>( bad, bad + ( sizeof bad / sizeof bad[0] ) ) ) );
		}
		case 2: {
			int width                 = 35;
			int height                = 31;
			string bad[]              = {"0 0 0 0"};
			long long expected        = 6406484391866534976LL;

			return verify_case( casenum, expected, AvoidRoads().numWays( width, height, vector <string>( bad, bad + ( sizeof bad / sizeof bad[0] ) ) ) );
		}
		case 3: {
			int width                 = 2;
			int height                = 2;
			string bad[]              = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
			long long expected        = 0LL;

			return verify_case( casenum, expected, AvoidRoads().numWays( width, height, vector <string>( bad, bad + ( sizeof bad / sizeof bad[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			int width                 = ;
			int height                = ;
			string bad[]              = ;
			long long expected        = LL;

			return verify_case( casenum, expected, AvoidRoads().numWays( width, height, vector <string>( bad, bad + ( sizeof bad / sizeof bad[0] ) ) ) );
		}*/
/*      case 5: {
			int width                 = ;
			int height                = ;
			string bad[]              = ;
			long long expected        = LL;

			return verify_case( casenum, expected, AvoidRoads().numWays( width, height, vector <string>( bad, bad + ( sizeof bad / sizeof bad[0] ) ) ) );
		}*/
/*      case 6: {
			int width                 = ;
			int height                = ;
			string bad[]              = ;
			long long expected        = LL;

			return verify_case( casenum, expected, AvoidRoads().numWays( width, height, vector <string>( bad, bad + ( sizeof bad / sizeof bad[0] ) ) ) );
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
