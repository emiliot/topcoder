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

int ok(int i, int j, const vector<string> &board){
	int movi[] = {-1,-1,-1,0,0,1,1,1};
	int movj[] = {-1,0,1,-1,1,-1,0,1};
	if(board[i][j]=='B')return 0;
	for(int k=0; k<8; ++k){
		int ni = movi[k]+i, nj = movj[k]+j;
		if(ni >=0 && ni<board.size() && nj>=0 && nj <= board[i].size()){
			if(board[ni][nj]=='B')return -1;
		}
	}
	return 1;
}

struct BombSweeper {
	double winPercentage(vector <string> board) {
		int loses = 0, win = 0;
		for(int i=0, n=board.size(); i<n; ++i){
			for(int j=0, m=board[i].size(); j<m; ++j){
				int aux =ok(i,j,board); 
				if(aux == 1)++win;
				else if(aux == 0)++loses;
			}
		}
		double res = ((double)(win)/(double)(loses+win))*100.0;
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	
	int verify_case( int casenum, const double &expected, const double &received ) { 
		cerr << "Example " << casenum << "... "; 
		cerr.precision(9); 
		if ( topcoder_fequ( expected, received ) ) {
			cerr << "PASSED"; 
			double rerr = moj_relative_error( expected, received ); 
			if ( rerr > 0 ) cerr << " (relative error " << rerr << ")";
			cerr << endl;
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
			string board[]            = {".....",  ".....",  "..B..",  ".....",  "....."};
			double expected           = 94.11764705882354;

			return verify_case( casenum, expected, BombSweeper().winPercentage( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}
		case 1: {
			string board[]            = {"BBBBB",  "B...B",  "B...B",  "B...B",  "BBBBB"};
			double expected           = 5.882352941176471;

			return verify_case( casenum, expected, BombSweeper().winPercentage( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}
		case 2: {
			string board[]            = {".........",  ".B..B..B.",  ".........",  ".........",  ".B..B..B.",  ".........",  ".........",  ".B..B..B.",  "........."};
			double expected           = 0.0;

			return verify_case( casenum, expected, BombSweeper().winPercentage( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}
		case 3: {
			string board[]            = {".........................",  ".........................",  ".........................",  "........................."};
			double expected           = 100.0;

			return verify_case( casenum, expected, BombSweeper().winPercentage( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}
		case 4: {
			string board[]            = {"......B.......B..B...........................B....",  "..............B..................BB..B............",  "B.B.B.............B.....B..............B..........",  "...................B...B....................BB....",  "...B.....B.........................B.......B.....B",  "B.B.........B.....B.......B..B......B.B...B.BB....",  "..B...................BB...............B..........",  ".........B...B................B..B................",  ".......BB.......B....B................B.....BBB...",  ".......BB..........B..............B......BB.......",  "...................BB.....................B.......",  "...B.B.B......B..............B...B......B.........",  "B................B................................",  "....B..........B.....B..BB....B...............BB..",  "..B....B.....B.............B.....B............B...",  "...................B.B........B..B.........B.B....",  ".....B.....B......................................",  "...........BB......BB...B.B........B...B..........",  ".....BBB..........................................",  ".B...........B....B...BB......B......B...B.B......",  "..................B........BB................B....",  "...............................B..B....BBB.B....B.",  "..........B.......................................",  ".....B..........B....BB......B.B......B......B....",  ".....B..................B........B................",  "............B.....B..B....BB...B....BB........B...",  "..B.................B.........B...................",  ".BB..............B................................",  "...B....B..................B.................B....",  "......B...B......B......................B.B.......",  "..............B..................B.......B........",  ".....B........BB...B.....B........................",  ".......B......B.B..B..........B...........B....B..",  "B...B...........B...B...B......B.B...B..B......B..",  "....B..B.....B.B.......BB..B............B.B....B..",  "B.......B..........B.........B...B.BB......B......",  "....B...............................B.............",  ".....B.B..........................................",  "..........B............B......B.B..B....B.........",  "....B...B.......................B.................",  "B.................B...........B..B....B...........",  "...B.....B........................................",  "...B..B......................................BBB..",  ".B...B....................................B....B..",  "...B...B..........B...B.B.........................",  ".....B.............B...BB..........B..BBB.BB......",  "....................B.....B.......................",  "........B..BB..........B.B....B...........B......B",  ".........B.....BB..B.............B....BB..........",  "....B..B..............B...B..B..........B........."};
			double expected           = 77.67558528428094;

			return verify_case( casenum, expected, BombSweeper().winPercentage( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}

		// custom cases

      case 5: {
			string board[]            = {"BBBB.B.BB..B....BB.B.BB..B.B....B..B"};
			double expected           = 19.047619047619047;

			return verify_case( casenum, expected, BombSweeper().winPercentage( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}
/*      case 6: {
			string board[]            = ;
			double expected           = ;

			return verify_case( casenum, expected, BombSweeper().winPercentage( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
		}*/
/*      case 7: {
			string board[]            = ;
			double expected           = ;

			return verify_case( casenum, expected, BombSweeper().winPercentage( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ) ) );
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
