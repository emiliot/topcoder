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

int chart[20][20];

int memo[1 << 16];
bool mark[1 << 16];
const int INF = 0x3f3f3f3f;

int f(vector <int> &v, int mask){
	int bossLeft = 0, n=(int)v.size();
	for(int i=0; i<n; ++i){
		if(!(mask & (1 << i)))++bossLeft;
	}
	if(bossLeft <= 0)return 0;
	int &best = memo[mask];
	if(mark[mask])return best;
	mark[mask] = true;

	best = INF;
	for(int next=0; next < n; ++next){
		//choose the next boss to kill
		if(!(mask & (1 << next))){
			//select the best weapon we have so far
			int bWeapon = 1;
			for(int k=0; k<n; ++k){
				if(mask & (1 << k)){
					bWeapon = max(bWeapon, chart[k][next]);
				}
			}
			best = min(best, f(v, mask | (1 << next)) + (v[next]+bWeapon-1)/bWeapon);
		}
	}
	return best;
}

struct KiloManX {
	int leastShots(vector <string> damageChart, vector <int> bossHealth) {
		memset(chart, 0, sizeof(chart));
		for(int i=0, n=(int)damageChart.size(); i<n; ++i){
			for(int j=0; j<n; ++j){
				chart[i][j] = (int)(damageChart[i][j] - '0');
			}
		}
		memset(mark, false, sizeof(mark));
		int res = f(bossHealth, 0);
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
			string damageChart[]      = {"070","500","140"};
			int bossHealth[]          = {150,150,150};
			int expected              = 218;

			return verify_case( casenum, expected, KiloManX().leastShots( vector <string>( damageChart, damageChart + ( sizeof damageChart / sizeof damageChart[0] ) ), vector <int>( bossHealth, bossHealth + ( sizeof bossHealth / sizeof bossHealth[0] ) ) ) );
		}
		case 1: {
			string damageChart[]      = {"1542", "7935", "1139", "8882"};
			int bossHealth[]          = {150,150,150,150};
			int expected              = 205;

			return verify_case( casenum, expected, KiloManX().leastShots( vector <string>( damageChart, damageChart + ( sizeof damageChart / sizeof damageChart[0] ) ), vector <int>( bossHealth, bossHealth + ( sizeof bossHealth / sizeof bossHealth[0] ) ) ) );
		}
		case 2: {
			string damageChart[]      = {"07", "40"};
			int bossHealth[]          = {150,10};
			int expected              = 48;

			return verify_case( casenum, expected, KiloManX().leastShots( vector <string>( damageChart, damageChart + ( sizeof damageChart / sizeof damageChart[0] ) ), vector <int>( bossHealth, bossHealth + ( sizeof bossHealth / sizeof bossHealth[0] ) ) ) );
		}
		case 3: {
			string damageChart[]      = {"198573618294842",  "159819849819205",  "698849290010992",  "000000000000000",  "139581938009384",  "158919111891911",  "182731827381787",  "135788359198718",  "187587819218927",  "185783759199192",  "857819038188122",  "897387187472737",  "159938981818247",  "128974182773177",  "135885818282838"};
			int bossHealth[]          = {157, 1984, 577, 3001, 2003, 2984, 5988, 190003, 9000, 102930, 5938, 1000000, 1000000, 5892, 38};
			int expected              = 260445;

			return verify_case( casenum, expected, KiloManX().leastShots( vector <string>( damageChart, damageChart + ( sizeof damageChart / sizeof damageChart[0] ) ), vector <int>( bossHealth, bossHealth + ( sizeof bossHealth / sizeof bossHealth[0] ) ) ) );
		}
		case 4: {
			string damageChart[]      = {"02111111", "10711111", "11071111", "11104111",  "41110111", "11111031", "11111107", "11111210"};
			int bossHealth[]          = {28,28,28,28,28,28,28,28};
			int expected              = 92;

			return verify_case( casenum, expected, KiloManX().leastShots( vector <string>( damageChart, damageChart + ( sizeof damageChart / sizeof damageChart[0] ) ), vector <int>( bossHealth, bossHealth + ( sizeof bossHealth / sizeof bossHealth[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string damageChart[]      = ;
			int bossHealth[]          = ;
			int expected              = ;

			return verify_case( casenum, expected, KiloManX().leastShots( vector <string>( damageChart, damageChart + ( sizeof damageChart / sizeof damageChart[0] ) ), vector <int>( bossHealth, bossHealth + ( sizeof bossHealth / sizeof bossHealth[0] ) ) ) );
		}*/
/*      case 6: {
			string damageChart[]      = ;
			int bossHealth[]          = ;
			int expected              = ;

			return verify_case( casenum, expected, KiloManX().leastShots( vector <string>( damageChart, damageChart + ( sizeof damageChart / sizeof damageChart[0] ) ), vector <int>( bossHealth, bossHealth + ( sizeof bossHealth / sizeof bossHealth[0] ) ) ) );
		}*/
/*      case 7: {
			string damageChart[]      = ;
			int bossHealth[]          = ;
			int expected              = ;

			return verify_case( casenum, expected, KiloManX().leastShots( vector <string>( damageChart, damageChart + ( sizeof damageChart / sizeof damageChart[0] ) ), vector <int>( bossHealth, bossHealth + ( sizeof bossHealth / sizeof bossHealth[0] ) ) ) );
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
