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

i64 memo[101][101][51];
bool mark[101][101][51];
int movi[16]={-2,-2,-1,-1,1,1,2,2,-1,-1,-1,0,0,1,1,1};
int movj[16]={-1,1,-2,2,-2,2,-1,1,-1,0,1,-1,1,-1,0,1};

i64 f(const vector <int> &end, const int n, const int size, int i, int j, int k){
	if(k==n){
		if(i == end[0] && j == end[1])return 1LL;
		else return 0LL;
	}

	i64 &count = memo[i][j][k];
	if(mark[i][j][k])return count;
	mark[i][j][k] = true;
	count = 0LL;
	for(int x=0; x<16; ++x){
		int ni = movi[x] + i, nj = movj[x] + j;
		if(ni >=0 && ni < size && nj >= 0 && nj < size){
			count += f(end, n, size, ni, nj, k+1);
		}
	}
	return count;
}

struct ChessMetric {
	long long howMany(int size, vector <int> start, vector <int> end, int numMoves) {
		//topDown approach
		memset(mark,false,sizeof(mark));
		return f(end,numMoves,size,start[0], start[1],0);
		
		//Bottom Up approach
		/*memset(memo,0LL,sizeof(memo));
		memo[start[0]][start[1]][0] = 1LL;
		for(int k=0; k<numMoves; ++k){
			for(int i=0; i<size; ++i){
				for(int j=0; j<size; ++j){
					for(int w=0; w<16; ++w){
						int ni = movi[w] + i, nj = movj[w] + j;
						if(ni >= 0 && ni < size && nj >= 0 && nj < size){
							memo[i][j][k+1] += memo[ni][nj][k];
						}
					}
				}
			}
		}
		return memo[end[0]][end[1]][numMoves];*/
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
			int size                  = 3;
			int start[]               = {0,0};
			int end[]                 = {1,0};
			int numMoves              = 1;
			long long expected        = 1LL;

			return verify_case( casenum, expected, ChessMetric().howMany( size, vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( end, end + ( sizeof end / sizeof end[0] ) ), numMoves ) );
		}
		case 1: {
			int size                  = 3;
			int start[]               = {0,0};
			int end[]                 = {1,2};
			int numMoves              = 1;
			long long expected        = 1LL;

			return verify_case( casenum, expected, ChessMetric().howMany( size, vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( end, end + ( sizeof end / sizeof end[0] ) ), numMoves ) );
		}
		case 2: {
			int size                  = 3;
			int start[]               = {0,0};
			int end[]                 = {2,2};
			int numMoves              = 1;
			long long expected        = 0LL;

			return verify_case( casenum, expected, ChessMetric().howMany( size, vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( end, end + ( sizeof end / sizeof end[0] ) ), numMoves ) );
		}
		case 3: {
			int size                  = 3;
			int start[]               = {0,0};
			int end[]                 = {0,0};
			int numMoves              = 2;
			long long expected        = 5LL;

			return verify_case( casenum, expected, ChessMetric().howMany( size, vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( end, end + ( sizeof end / sizeof end[0] ) ), numMoves ) );
		}
		case 4: {
			int size                  = 100;
			int start[]               = {0,0};
			int end[]                 = {0,99};
			int numMoves              = 50;
			long long expected        = 243097320072600LL;

			return verify_case( casenum, expected, ChessMetric().howMany( size, vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( end, end + ( sizeof end / sizeof end[0] ) ), numMoves ) );
		}

		// custom cases

/*      case 5: {
			int size                  = ;
			int start[]               = ;
			int end[]                 = ;
			int numMoves              = ;
			long long expected        = LL;

			return verify_case( casenum, expected, ChessMetric().howMany( size, vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( end, end + ( sizeof end / sizeof end[0] ) ), numMoves ) );
		}*/
/*      case 6: {
			int size                  = ;
			int start[]               = ;
			int end[]                 = ;
			int numMoves              = ;
			long long expected        = LL;

			return verify_case( casenum, expected, ChessMetric().howMany( size, vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( end, end + ( sizeof end / sizeof end[0] ) ), numMoves ) );
		}*/
/*      case 7: {
			int size                  = ;
			int start[]               = ;
			int end[]                 = ;
			int numMoves              = ;
			long long expected        = LL;

			return verify_case( casenum, expected, ChessMetric().howMany( size, vector <int>( start, start + ( sizeof start / sizeof start[0] ) ), vector <int>( end, end + ( sizeof end / sizeof end[0] ) ), numMoves ) );
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
