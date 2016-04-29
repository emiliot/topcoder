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

bool mark[60][60];

int f(string row, int i, int j,int size){
	int count = 0;
	for(int k=j, n=row.size(); k<n && row[k]=='.'; ++k){
		++count;
		mark[i][k] = true;
	}
	if(count == size)return 1;
	else return 0;
}

struct CrossWord {
	int countWords(vector <string> board, int size) {
		int count = 0;
		memset(mark,false,sizeof(mark));
		for(int i=0, n=board.size(); i<n; ++i){
			for(int j=0, m=board[i].size(); j<m;++j){
				if(board[i][j] == '.' && !mark[i][j])count += f(board[i],i,j,size);
			}
		}
		return count;
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
			string board[]            = {"X....X",  "X.XX.X",  "...X..",  "X.XX.X",  "..X..."};
			int size                  = 3;
			int expected              = 2;

			return verify_case( casenum, expected, CrossWord().countWords( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), size ) );
		}
		case 1: {
			string board[]            = {"...X...",  ".X...X.",  "..X.X..",  "X..X..X",  "..X.X..",  ".X...X.",  "...X..."};
			int size                  = 3;
			int expected              = 6;

			return verify_case( casenum, expected, CrossWord().countWords( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), size ) );
		}
		case 2: {
			string board[]            = {".....X....X....",  ".....X....X....",  "..........X....",  "....X....X.....",  "...X....X....XX",  "XXX...X....X...",  ".....X....X....",  ".......X.......",  "....X....X.....",  "...X....X...XXX",  "XX....X....X...",  ".....X....X....",  "....X..........",  "....X....X.....",  "....X....X....."} ;
			int size                  = 5;
			int expected              = 8;

			return verify_case( casenum, expected, CrossWord().countWords( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), size ) );
		}
		case 3: {
			string board[]            = {"...",  "...",  "..."};
			int size                  = 50;
			int expected              = 0;

			return verify_case( casenum, expected, CrossWord().countWords( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), size ) );
		}
		case 4: {
			string board[]            = {"....",  "....",  "...."};
			int size                  = 3;
			int expected              = 0;

			return verify_case( casenum, expected, CrossWord().countWords( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), size ) );
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int size                  = ;
			int expected              = ;

			return verify_case( casenum, expected, CrossWord().countWords( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), size ) );
		}*/
/*      case 6: {
			string board[]            = ;
			int size                  = ;
			int expected              = ;

			return verify_case( casenum, expected, CrossWord().countWords( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), size ) );
		}*/
/*      case 7: {
			string board[]            = ;
			int size                  = ;
			int expected              = ;

			return verify_case( casenum, expected, CrossWord().countWords( vector <string>( board, board + ( sizeof board / sizeof board[0] ) ), size ) );
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
