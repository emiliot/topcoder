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

int memo[60][60];
bool mark[60][60];

int f(vector <int> &v, int i, int last){
	if(i >= (int)v.size())return 0;

	int &best = memo[i][last];
	if(mark[i][last])return best;
	mark[i][last] = true;

	best = f(v, i+1, last);
	if(v[last] < v[i]){
		best = max(best, f(v, i+1, i) + 1);
	}

	return best;
}

int memo2[60][60][60];
bool mark2[60][60][60];
int top;

int g(vector <int> &v, int i, int last, int k){
	if(i >= (int)v.size()){
		if(k >= top)return 1;
		else return 0;
	}

	int &count = memo2[i][last][k];
	if(mark2[i][last][k])return count;
	mark2[i][last][k] = true;

	count = g(v, i+1, last, k);
	if(v[last] < v[i]){
		count += g(v, i+1, i, k+1);
	}
	//printf("DEBUG: i=%d last=%d k=%d count=%d\n", i, last, k, count);

	return count;
}

struct ThePriceIsRight {
	vector <int> howManyReveals(vector <int> prices) {
		memset(mark, false, sizeof(mark));
		vector <int> res(2, 0);
		for(int i=0, n=(int)prices.size(); i<n; ++i){
			int next = f(prices, i+1, i) + 1;
			res[0] = max(res[0], next);
		}
		
		top = res[0];
		memset(mark2, false, sizeof(mark2));
		for(int i=0, n=(int)prices.size(); i<n; ++i){
			res[1] += g(prices, i+1, i, 1);
			//printf("DEBUG: %d\n", res[1]);
		}

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
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case( int casenum, const vector <int> &expected, const vector <int> &received ) { 
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
			int prices[]              = {30,10,20,40,50};
			int expected[]            = { 4,  1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ThePriceIsRight().howManyReveals( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ) ) );
		}
		case 1: {
			int prices[]              = {39,88,67,5,69,87,82,64,58,61};
			int expected[]            = { 4,  2 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ThePriceIsRight().howManyReveals( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ) ) );
		}
		case 2: {
			int prices[]              = {1,2,3,4,5,6,7,8,9,10};
			int expected[]            = { 10,  1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ThePriceIsRight().howManyReveals( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ) ) );
		}
		case 3: {
			int prices[]              = {10,9,8,7,6,5,4,3,2,1};
			int expected[]            = { 1,  10 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ThePriceIsRight().howManyReveals( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ) ) );
		}
		case 4: {
			int prices[]              = {29,31,73,70,14,5,6,34,53,30,15,86};
			int expected[]            = { 5,  2 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ThePriceIsRight().howManyReveals( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ) ) );
		}
		case 5: {
			int prices[]              = {100,99,1,2,3};
			int expected[]            = { 3,  1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ThePriceIsRight().howManyReveals( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ) ) );
		}
		case 6: {
			int prices[]              = {10,20,11,12};
			int expected[]            = { 3,  1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ThePriceIsRight().howManyReveals( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ) ) );
		}

		// custom cases

/*      case 7: {
			int prices[]              = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ThePriceIsRight().howManyReveals( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ) ) );
		}*/
/*      case 8: {
			int prices[]              = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ThePriceIsRight().howManyReveals( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ) ) );
		}*/
/*      case 9: {
			int prices[]              = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ThePriceIsRight().howManyReveals( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ) ) );
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
