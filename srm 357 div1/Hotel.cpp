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

int memo[30][1010];
const int INF = 0x3f3f3f3f;

int f(const vector<int> &v, const vector <int> &cost, int i, int k){
	if(i >= v.size())return INF;
	else if(k <= 0)return 0;
	int &best = memo[i][k];
	if(best != -1)return best;
	best = f(v,cost,i+1,k); //no tomo el elemento
	int n = k%v[i] == 0? k/v[i] : (k/v[i])+1;
	best = min(best,(n*cost[i]));//tomo todos de un mismo elemento
	for(int j=1, w=cost[i]; j<n; ++j,w+=cost[i]){
		best = min(best,f(v,cost,i+1,k-(j*v[i]))+w);
	}

	return best;
}

struct Hotel {
	int	marketCost(int minCustomers, vector <int> customers, vector <int> cost) {
		memset(memo,-1,sizeof(memo));
		return f(customers,cost,0,minCustomers);
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
			int minCustomers          = 10;
			int customers[]           = {1,2,3};
			int cost[]                = {3,2,1};
			int expected              = 4;

			return verify_case( casenum, expected, Hotel().marketCost( minCustomers, vector <int>( customers, customers + ( sizeof customers / sizeof customers[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ) ) );
		}
		case 1: {
			int minCustomers          = 10;
			int customers[]           = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int cost[]                = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int expected              = 10;

			return verify_case( casenum, expected, Hotel().marketCost( minCustomers, vector <int>( customers, customers + ( sizeof customers / sizeof customers[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ) ) );
		}
		case 2: {
			int minCustomers          = 12;
			int customers[]           = {5, 1};
			int cost[]                = {3, 1};
			int expected              = 8;

			return verify_case( casenum, expected, Hotel().marketCost( minCustomers, vector <int>( customers, customers + ( sizeof customers / sizeof customers[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ) ) );
		}
		case 3: {
			int minCustomers          = 100;
			int customers[]           = {9, 11, 4, 7, 2, 8};
			int cost[]                = {4, 9, 3, 8, 1, 9};
			int expected              = 45;

			return verify_case( casenum, expected, Hotel().marketCost( minCustomers, vector <int>( customers, customers + ( sizeof customers / sizeof customers[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			int minCustomers          = ;
			int customers[]           = ;
			int cost[]                = ;
			int expected              = ;

			return verify_case( casenum, expected, Hotel().marketCost( minCustomers, vector <int>( customers, customers + ( sizeof customers / sizeof customers[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ) ) );
		}*/
/*      case 5: {
			int minCustomers          = ;
			int customers[]           = ;
			int cost[]                = ;
			int expected              = ;

			return verify_case( casenum, expected, Hotel().marketCost( minCustomers, vector <int>( customers, customers + ( sizeof customers / sizeof customers[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ) ) );
		}*/
/*      case 6: {
			int minCustomers          = ;
			int customers[]           = ;
			int cost[]                = ;
			int expected              = ;

			return verify_case( casenum, expected, Hotel().marketCost( minCustomers, vector <int>( customers, customers + ( sizeof customers / sizeof customers[0] ) ), vector <int>( cost, cost + ( sizeof cost / sizeof cost[0] ) ) ) );
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
