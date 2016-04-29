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

int setExp(vector < vector <int> > &v, int &act){
	int best = -1, col = -1;
	for(int j=0, m=v[0].size(); j<m; ++j){
		int next = 0;
		for(int i=0, n=v.size(); i<n; ++i)
			next += v[i][j];
		if(next > best)best = next, col = j;
	}
	int a = act, b = col;
	if(a > b)swap(a,b);
	int res = min(b-a, (int)v[0].size()-b+a);
	act = col;
	return res;
}

struct VendingMachine {
	int motorUse(vector <string> prices, vector <string> purchases) {
		for(int i=0, n=purchases.size(); i<n; ++i){
			for(int j=0, m=purchases[i].size(); j<m; ++j)
				if(purchases[i][j] == ':' || purchases[i][j] == ',')
					purchases[i][j] = ' ';
		}
		vector < vector <int> > table(prices.size());
		for(int i=0, n=prices.size(); i<n; ++i){
			istringstream iss(prices[i]);
			for(int j=0, k; iss >> k; ++j)
				table[i].push_back(k);
		}
		int res = 0, act = 0;
		res += setExp(table, act);
		//simulate
		int row, col, time, a, b;
		istringstream aux(purchases[0]);
		aux >> row >> col >> time; a = act, b = col;
		if(table[row][col]<= 0)return -1;
		if(a > b)swap(a,b);
		res +=  min(b-a, (int)table[0].size()-b+a);
		act = col;
		table[row][col] = 0;

		for(int i=1, n=purchases.size(); i<n; ++i){
			int nextRow, nextCol, nextTime;
			istringstream iss(purchases[i]);
			iss >> nextRow >> nextCol >> nextTime;
			if(table[nextRow][nextCol]<= 0)return -1;
			if(nextTime - time >= 5)res += setExp(table,act);
			a = act, b = nextCol;
			if(a > b)swap(a,b);
			res += min(b-a, (int)table[0].size()-b+a);
			act = nextCol;
			table[nextRow][nextCol] = 0;
			time = nextTime;
		}
		//end
		res += setExp(table, act);
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
			string prices[]           = {"100 100 100"};
			string purchases[]        = {"0,0:0", "0,2:5", "0,1:10"};
			int expected              = 4;

			return verify_case( casenum, expected, VendingMachine().motorUse( vector <string>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <string>( purchases, purchases + ( sizeof purchases / sizeof purchases[0] ) ) ) );
		}
		case 1: {
			string prices[]           = {"100 200 300 400 500 600"};
			string purchases[]        = {"0,2:0", "0,3:5", "0,1:10", "0,4:15"};
			int expected              = 17;

			return verify_case( casenum, expected, VendingMachine().motorUse( vector <string>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <string>( purchases, purchases + ( sizeof purchases / sizeof purchases[0] ) ) ) );
		}
		case 2: {
			string prices[]           = {"100 200 300 400 500 600"};
			string purchases[]        = {"0,2:0", "0,3:4", "0,1:8", "0,4:12"};
			int expected              = 11;

			return verify_case( casenum, expected, VendingMachine().motorUse( vector <string>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <string>( purchases, purchases + ( sizeof purchases / sizeof purchases[0] ) ) ) );
		}
		case 3: {
			string prices[]           = {"100 100 100"};
			string purchases[]        = {"0,0:10", "0,0:11"};
			int expected              = -1;

			return verify_case( casenum, expected, VendingMachine().motorUse( vector <string>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <string>( purchases, purchases + ( sizeof purchases / sizeof purchases[0] ) ) ) );
		}
		case 4: {
			string prices[]           = {"100 200 300",  "600 500 400"};
			string purchases[]        = {"0,0:0", "1,1:10", "1,2:20",  "0,1:21", "1,0:22", "0,2:35"};
			int expected              = 6;

			return verify_case( casenum, expected, VendingMachine().motorUse( vector <string>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <string>( purchases, purchases + ( sizeof purchases / sizeof purchases[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string prices[]           = ;
			string purchases[]        = ;
			int expected              = ;

			return verify_case( casenum, expected, VendingMachine().motorUse( vector <string>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <string>( purchases, purchases + ( sizeof purchases / sizeof purchases[0] ) ) ) );
		}*/
/*      case 6: {
			string prices[]           = ;
			string purchases[]        = ;
			int expected              = ;

			return verify_case( casenum, expected, VendingMachine().motorUse( vector <string>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <string>( purchases, purchases + ( sizeof purchases / sizeof purchases[0] ) ) ) );
		}*/
/*      case 7: {
			string prices[]           = ;
			string purchases[]        = ;
			int expected              = ;

			return verify_case( casenum, expected, VendingMachine().motorUse( vector <string>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <string>( purchases, purchases + ( sizeof purchases / sizeof purchases[0] ) ) ) );
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
