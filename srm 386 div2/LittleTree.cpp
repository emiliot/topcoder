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

int memo[105][105];
bool mark[105][105];
const int INF = 0x3f3f3f3f;

int buildGraph(vector < vector <int> > &v, string &x){
	bool isRoot[105];
	memset(isRoot, false, sizeof(isRoot));
	int a, b; char c;
	istringstream iss(x);
	while(iss >> a >> c >> b){
		v[a].push_back(b);
		isRoot[b] = true;
	}
	for(int i=0, n=v.size(); i<n; ++i)if(!isRoot[i])return i;
	return 0;
}

int f(const vector < vector <int> > &v, const int height, int root, int k){
	if(v[root].size() <= 0){
		if(k <= height)return 0;
		else return 1;
	}
	int &best = memo[root][k];
	if(mark[root][k])return best;
	mark[root][k] = true;
	
	best = INF;
	for(int i=1; i<k; ++i){
		best = min(best, (k-i) + f(v,height,root,i));
	}
	
	if(k <= height){
		int aux = 0;
		for(int i=0,  n=v[root].size(); i<n; ++i){
			aux += f(v,height, v[root][i], k+1);
		}
		best = min(best, aux);
	}
	return best;
}

struct LittleTree {
	int minCost(int N, vector <string> edges, int height) {
		vector < vector < int > > v(N);
		string x = accumulate(all(edges), string(""));
		int root = buildGraph(v, x);

		memset(mark,false,sizeof(mark));
		int res = f(v, height, root, 0); 
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
			int N                     = 5;
			string edges[]            = {"0,1 1,2 2,3 2,4"};
			int height                = 2;
			int expected              = 1;

			return verify_case( casenum, expected, LittleTree().minCost( N, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), height ) );
		}
		case 1: {
			int N                     = 5;
			string edges[]            = {"0,1 1,2 2,3 2,4"};
			int height                = 1;
			int expected              = 3;

			return verify_case( casenum, expected, LittleTree().minCost( N, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), height ) );
		}
		case 2: {
			int N                     = 3;
			string edges[]            = {"0,1 1,2"};
			int height                = 2;
			int expected              = 0;

			return verify_case( casenum, expected, LittleTree().minCost( N, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), height ) );
		}
		case 3: {
			int N                     = 9;
			string edges[]            = {"0,3 3,1 1,8 ","8,","6 2,7 4,2 0,4 7",",5"};
			int height                = 3;
			int expected              = 2;

			return verify_case( casenum, expected, LittleTree().minCost( N, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), height ) );
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			string edges[]            = ;
			int height                = ;
			int expected              = ;

			return verify_case( casenum, expected, LittleTree().minCost( N, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), height ) );
		}*/
/*      case 5: {
			int N                     = ;
			string edges[]            = ;
			int height                = ;
			int expected              = ;

			return verify_case( casenum, expected, LittleTree().minCost( N, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), height ) );
		}*/
/*      case 6: {
			int N                     = ;
			string edges[]            = ;
			int height                = ;
			int expected              = ;

			return verify_case( casenum, expected, LittleTree().minCost( N, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ), height ) );
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
