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

int cost[52][52];
int memo[52][3002];
bool mark[52][3002];

bool mark2[52][52][2];
int memo2[52][52][2];

enum{BLACK=0, WHITE};

int h(string &s, int i, int left, int prev){
	if(i >= (int)s.size())return 0;

	int &best = memo2[i][left][prev];
	if(mark2[i][left][prev])return best;
	mark2[i][left][prev] = true;

	int nextColor = (s[i] == 'B'? BLACK : WHITE);

	best = h(s, i+1, left, prev) + (nextColor == prev ? 0 : 1);
	if(prev != nextColor && left > 0){
		best = min(best, h(s, i+1, left - 1, nextColor));
	}
	return best;
}

void f(vector <string> &v){ //this function fill the cost/strokes matrix
	for(int i=0, n=(int)v.size(); i<n; ++i){
		cost[i][0] = (int)v[i].size(); //using no strokes the cost is mispaint all the row
		memset(mark2, false, sizeof(mark2));

		for(int j=1, m=(int)v[i].size(); j<=m; ++j){
			int scolor = (v[i][0] == 'B'? BLACK : WHITE);
			cost[i][j] = min(h(v[i], 1, j-1, BLACK) + (scolor == BLACK? 0 : 1), 
				h(v[i], 1, j-1, WHITE) + (scolor == WHITE? 0 : 1));
		}
	}

	/*for(int i=0, n=(int)v.size(); i<n; ++i){
		for(int j=0, m=(int)v[i].size(); j<=m; ++j){
			printf(" %d", cost[i][j]);
		}
		printf("\n");
	}*/
}

int g(const int n, const int m, int i, int left){
	if(i >= n)return 0;
	
	int &best = memo[i][left];
	if(mark[i][left])return best;
	mark[i][left] = true;

	best = g(n, m, i+1, left) + cost[i][0]; //start with the cost of no using strokes
	for(int k=1; k<=m && k<=left; ++k){ //try using k strokes
		best = min(best, g(n, m, i+1, left - k) + cost[i][k]);
	}

	return best;
}

struct MiniPaint {
	int leastBad(vector <string> picture, int maxStrokes) {
		f(picture);
		memset(mark, false, sizeof(mark));
		int res = g((int)picture.size(), (int)picture[0].size(), 0, maxStrokes);
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
			string picture[]          = { "BBBBBBBBBBBBBBB", "WWWWWWWWWWWWWWW", "WWWWWWWWWWWWWWW", "WWWWWBBBBBWWWWW"};
			int maxStrokes            = 6;
			int expected              = 0;

			return verify_case( casenum, expected, MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes ) );
		}
		case 1: {
			string picture[]          = { "BBBBBBBBBBBBBBB", "WWWWWWWWWWWWWWW", "WWWWWWWWWWWWWWW", "WWWWWBBBBBWWWWW"};
			int maxStrokes            = 4;
			int expected              = 5;

			return verify_case( casenum, expected, MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes ) );
		}
		case 2: {
			string picture[]          = { "BBBBBBBBBBBBBBB", "WWWWWWWWWWWWWWW", "WWWWWWWWWWWWWWW", "WWWWWBBBBBWWWWW"};
			int maxStrokes            = 0;
			int expected              = 60;

			return verify_case( casenum, expected, MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes ) );
		}
		case 3: {
			string picture[]          = { "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW"};
			int maxStrokes            = 100;
			int expected              = 40;

			return verify_case( casenum, expected, MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes ) );
		}
		case 4: {
			string picture[]          = {"B"};
			int maxStrokes            = 1;
			int expected              = 0;

			return verify_case( casenum, expected, MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes ) );
		}

		// custom cases

      case 5: {
			string picture[]          = {"BBWWWWWWWBBBBWWWBWWWWWWWWWBWWWBWBWBBBWBWBWWWBBWWWW", "WWBWBBBBWBWBBBBBWBWWWBWWBWBBBWWBBBWBBBWBBWBWWBBBBB", "BBWWBBBBWBWBBWWWBBWWWBWBWWBWBBWWBBWWBWWWWBBBBWBBBW", "WBBWWBBWBBBBWWBWBBWBBBBBBBWBBBBWWWWWWBBWWBWWWBBBBB", "WBBBBBWBWWBWWBBWBWBWWWBBBBWBBBBWBBBWBWBBWBBBWBBBBB", "WBBWWBWWBBWWWWBBBBBWWBBBBWBWBWBWWWWBWWBWBBBWWWBWWB", "WBWWBWBWBBBBWWWBWBBBWBBBWWWWBWWBBWBWWBWWWWWBBWWBWW", "WWBWBWBWBBBBWBBBBBBWWWBBBWWWWBWWBWWWBBBWBBBWBWWBBW", "WWBBBBBWBWBWWWBBWWWWBBWWWBBWWBBBBWBWWBWBBBBWWBWBWB", "BWWWWWWBBWBBWBWWWBWBBBWBBBBWBWBWBWWWWWBBWWWBWWWBWB", "WWWWBWBWBWBBWWBBWWBWBWWWBWWWBWBWWBBBWWWBWWBBWWWBBW", "BBWBWBBWBBBWBBWWWWWBBBBWBWBBBBBWBBWWWWBBBBWWWWBBWB", "BWBBBBBBWWBBBBBBBWBBBWWWBBBBWBWBBBBBBWBWBBBBWWBWWW", "BWBWBBBBWBWWWBWWBBWWBBWBWBWBWBBWWWWBWWWBWBBWBBWWWB", "BBWBBWWBBWBBWWBBWWBWWWBWBBWWWWWBWWBWBBWBBWWWWBBWBB", "BBBWBWBWBWWWWWBWBBWBWWWBWBWBBBWWBBWBBBBWWWBWWBWWBB", "BWWBWBWWWBBBBWWBBWBWWBBBBWWWBWWWWBWBWWWBBWBBWBBBBW", "WWWBWWWWBBWWBBBBBWBBBWWBBWWWWBWWBWWWWBBWBWWBBBBWWW", "BBWBBWWWBBWBBBBBWBWWWBWBBBBWBWBBWBBWWWBWWBWBBWBBBB", "WWWBWWWWWBBBBBWWBWWWBBWWWWWBBBWBBBWWWWWBBWWBBBBWBB", "WBBWWWBBBBBBBWWWBWBWBBWBBWBBBBBBBBBBWWWWBBBWBWWWBW", "WBBWBBWBWWBBWWWWBBBWWWBWBBBWWBWBWWWBWWBBWBWWWBBBWB", "BWWBWWWWBBWBBBWWBWWBBBBWBBBWWWBBBWBWBBWWWBBBWWWBWW", "WWWWWWWBWWBWBWBBBWBBBWWWBWWBWWWWBBBWWBBBWBWWWBWWBB", "WWWWBBWWWBWBWWBWWWWBBBBWWWWWBWBWBBBBWBBBBBWBWBWBWW", "WWBBWWBWWWWBWBBBWBWBWWWBBWBBWWWBWBBBWBBWWBBWWBBWWW", "BBBBWBWBWWWWWWBBBWBBWBWBWBWWBWWBWWBBWWBBBBBBBBBBBB", "BWWBWWBBBBBWWWWBBWBBBWBWWWBWBBWBBBWWBWWBBBWBBBBWBW", "WWWBWWBBWBWWWWBWBBBBBBWBBWWWWWBBBBWBBBBBWWBWWWBWWB", "BBWWWWBWBWWWWBWWWBWWWBBBWWBBBWBBWWBWWBWBBWWBWBBBWW", "BWWWBBWWWBBWWBBBBBWBWWBWWBWWWBWWWBBWBWBBWBBWWBBWWW", "WBWBWBWWBWBBWWBBBWBWBWWWWWBWWWBBWWWWWBWBWWBBWWWBWB", "BWWBWWWWWWBBBBWWWBWBBWBWBBBWWWBBBBWWBBWBBWWBWBBBWB", "WBBBBBWWWBBBBBBWWWWBWWBWWBBWBWBBWWWWBBWBWBWBWBBBWB", "BBWBWWBBWWBBWWBWWWWWWWWBBWWBBWBBWBBBBWBBWWWBWWWBWB", "BBWBWBWWBWBBWWBBWWBBWWBBBWBBWBWBBWBWBBBWBWBBWBWWWB", "WWBWWWWWBWWBWWBBWWBBBWWBBBBBWBBBBBBBBBWWWBBBBBBWBB", "BBBBWBWBWBWBWWBWBBBBWBWWWBWWWWBWWBWBBBBWWWWWBWWBBB", "WWWWWWBWWBBWWWBWWBWWWBBWBWWBWBWWWBWWWWBWBWBBBWWWWB", "BWWBWBWWBBBBWBBBWBWWBWWWBWBWWBBWWBBBWWWBWBWBWBBWWB", "WWBBWWWBBBBWBBBWWWBBWBWBWWBWWBWWWWBBWWWBWWWBBWBBWW", "WBWWBWWBWBBBBBBBWBWBWBBBBWBBBWWBWBWWWWWBWWBWBWBWWW", "BWBBWBWBWBWBWBBWBBBWWWBWBBBWWWWWBWBBWWBBBBBBWWWBWB", "WWWBWBBBBBBWBBBBWWBBWWWBWWWWBBBBWBWBBBWWBBBWBWWWWW", "BBBBBBBWBWBWBBBBWBBBWBWBBWWWWBBBWWWWWWWWWWBBWBBBWW", "BBBBBWWWWBWWBBWWBBWBBBBWBWWBBWWBBBBBBBBBWWWWWBBWBW", "WBWWBWBBWBWWWWBBBWBWWWBWBWBWBWWWWWWBBBBBBBBWWWWWWB", "WWBWBWWWWBWBBWBWWWWBWBWBWWBWWWBBBBBWWBBWBBBBWBBBBB", "BBWWBWBBWWBWWBWWBWWBWBWBBWBWBWBBWWBBBBBBBBBBBBBWWB", "WWBWWBWBWWBBWWBBWWBBBWBBBWWWBWBBWBBWBWBWBWWWBBWWWB"};
			int maxStrokes            = 599;
			int expected              = 333;

			return verify_case( casenum, expected, MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes ) );
		}
/*      case 6: {
			string picture[]          = ;
			int maxStrokes            = ;
			int expected              = ;

			return verify_case( casenum, expected, MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes ) );
		}*/
/*      case 7: {
			string picture[]          = ;
			int maxStrokes            = ;
			int expected              = ;

			return verify_case( casenum, expected, MiniPaint().leastBad( vector <string>( picture, picture + ( sizeof picture / sizeof picture[0] ) ), maxStrokes ) );
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
