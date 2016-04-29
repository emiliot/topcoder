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
#define maxN 31
#define INF 0x3f3f3f3f
int memo[maxN][maxN][maxN][maxN];
bool mark[maxN][maxN][maxN][maxN];

int f(vector <string> &v, int k, int left, int right, int bottom, int top){
	int coins = 0;
	for(int i=bottom; i<top; ++i){
		for(int j=left; j<right; ++j){
			if(v[i][j] == 'o')coins++;
		}
	}
	if(coins == k)return 0;
	if(left >= right || bottom >= top)return INF;

	int &best = memo[left][right][bottom][top];
	if(mark[left][right][bottom][top])return best;
	mark[left][right][bottom][top] = true;

	int dtop = v.size() - top, dright = v[0].size() - right;
	best = INF;

	if(bottom <= dtop)best = min(best, f(v,k,left,right,bottom,top-1) + 1);
	else best = min(best, f(v,k,left,right,bottom,top-1) + 1 + bottom - dtop);

	if(bottom >= dtop)best = min(best, f(v,k,left,right,bottom+1,top) + 1);
	else best = min(best,f(v,k,left,right,bottom+1,top) + 1 + dtop - bottom);

	if(left <= dright)best = min(best,f(v,k,left,right-1,bottom,top) + 1);
	else best = min(best, f(v,k,left,right-1,bottom,top) + 1 + left - dright);

	if(left >= dright)best = min(best,f(v,k,left+1,right,bottom,top) + 1);
	else best = min(best, f(v,k,left+1,right,bottom,top) + 1 + dright - left);

	return best;
}


struct DropCoins {
	int getMinimum(vector <string> board, int K) {
		memset(mark, false, sizeof(mark));
		
		int res = f(board,K,0,board[0].size(),0,board.size());
		if(res >= INF)return -1;
		else return res;
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
			string board[]            = {".o.." ,"oooo" ,"..o."} ;
			int K                     = 3;
			int expected              = 2;

			return verify_case( casenum, expected, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K ) );
		}
		case 1: {
			string board[]            = {".....o" ,"......" ,"oooooo" ,"oooooo" ,"......" ,"o....."} ;
			int K                     = 12;
			int expected              = 3;

			return verify_case( casenum, expected, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K ) );
		}
		case 2: {
			string board[]            = {"...." ,".oo." ,".oo." ,"...."} ;
			int K                     = 3;
			int expected              = -1;

			return verify_case( casenum, expected, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K ) );
		}
		case 3: {
			string board[]            = {"......." ,"..ooo.." ,"ooooooo" ,".oo.oo." ,"oo...oo"} ;
			int K                     = 12;
			int expected              = 4;

			return verify_case( casenum, expected, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K ) );
		}
		case 4: {
			string board[]            = {"................." ,".ooooooo...oooo.." ,".ooooooo..oooooo." ,".oo.......oo..oo." ,".oo.......oo..oo." ,".ooooo.....oooo.." ,".ooooooo...oooo.." ,".....ooo..oo..oo." ,"......oo..oo..oo." ,".ooooooo..oooooo." ,".oooooo....oooo.." ,"................."} ;
			int K                     = 58;
			int expected              = 6;

			return verify_case( casenum, expected, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K ) );
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int K                     = ;
			int expected              = ;

			return verify_case( casenum, expected, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K ) );
		}*/
/*      case 6: {
			string board[]            = ;
			int K                     = ;
			int expected              = ;

			return verify_case( casenum, expected, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K ) );
		}*/
/*      case 7: {
			string board[]            = ;
			int K                     = ;
			int expected              = ;

			return verify_case( casenum, expected, DropCoins().getMinimum( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), K ) );
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
