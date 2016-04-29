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
#define INF 0x3f3f3f3f
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

bool markRow[100];
bool markCol[100];

int f(vector < pair <int, int> > &v, int n, int m, int ci, int cj, bool flag){
	memset(markRow, false, sizeof(markRow));
	memset(markCol, false, sizeof(markCol));
	int row = 0, col = 0;
	for(int i=0, w=v.size(); i<w; ++i){
		row += abs(v[i].first - ci);
		col += abs(v[i].second - cj);
		markRow[v[i].second] = true;
		markCol[v[i].first] = true;
	}
	int left = cj, right = cj, up = ci, down = ci;
	for(int i=cj-1; i>=0; --i){
		if(markRow[i]){
			--left;
			row += abs(i-left);
		}
	}
	for(int i=ci-1; i>=0; --i){
		if(markCol[i]){
			--down;
			col += abs(i-down);
		}
	}

	for(int i=cj+1; i<m; ++i){
		if(markRow[i]){
			++right;
			row += abs(i-right);
		}
	}
	for(int i=ci+1; i<n; ++i){
		if(markCol[i]){
			++up;
			col += abs(i-up);
		}
	}
	if(!flag){
		return min(row + min(abs(left - cj), abs(right -cj)), col + min(abs(up - ci), abs(down - ci)));
	}else return min(row,col);
}

struct DucksAlignment {
	int minimumTime(vector <string> v) {
		int best = INF;
		vector <pair <int, int> > ducks;
		for(int i=0, n=v.size(); i<n; ++i){
			for(int j=0, m=v[i].size(); j<m; ++j){
				if(v[i][j] == 'o'){
					ducks.push_back(make_pair(i,j));
				}
			}
		}
		for(int i=0, n=v.size(); i<n; ++i){
			for(int j=0, m=v[i].size(); j<m; ++j){
				best = min(best, f(ducks, n, m, i, j, v[i][j]=='o'));
			}
		}
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
			string grid[]             = {".o",  "o."};
			int expected              = 1;

			return verify_case( casenum, expected, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) ) );
		}
		case 1: {
			string grid[]             = {".o...",  "..o..",  "....o"};
			int expected              = 3;

			return verify_case( casenum, expected, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) ) );
		}
		case 2: {
			string grid[]             = {"o..........",  "..o........",  ".......o...",  "...........",  "...........",  "...........",  "........o..",  "..........."};
			int expected              = 16;

			return verify_case( casenum, expected, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) ) );
		}
		case 3: {
			string grid[]             = {".........",  "....o....",  "........."};
			int expected              = 0;

			return verify_case( casenum, expected, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) ) );
		}
		case 4: {
			string grid[]             = {"...o..........................",  "............................o.",  ".o............................",  "............o.................",  ".................o............",  "......................o.......",  "......o.......................",  "....o.........................",  "...............o..............",  ".......................o......",  "...........................o..",  ".......o......................"};
			int expected              = 99;

			return verify_case( casenum, expected, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string grid[]             = ;
			int expected              = ;

			return verify_case( casenum, expected, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) ) );
		}*/
/*      case 6: {
			string grid[]             = ;
			int expected              = ;

			return verify_case( casenum, expected, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) ) );
		}*/
/*      case 7: {
			string grid[]             = ;
			int expected              = ;

			return verify_case( casenum, expected, DucksAlignment().minimumTime( vector <string>( grid, grid + ( sizeof grid / sizeof grid[0] ) ) ) );
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
