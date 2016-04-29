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
const int INF = 0x7FFFFFFF;

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

struct postmark{
	int cost, value;
	bool operator <(const postmark &other)const{
		if(cost < other.cost)return true;
		else if(cost > other.cost)return false;
		else return value > other.value;
	}
};

vector <postmark> f(vector <int> &prices, vector<int> &values, int a, int b){
	vector <postmark> res((1 << (b-a)));
	res[0].cost = 0, res[0].value = 0;
	for(int i=1, n=res.size(); i<n; ++i){
		res[i].cost = 0, res[i].value = 0;
		for(int j=0; j<b-a; ++j){
			if(i & (1 << j))res[i].cost += prices[a + j], res[i].value += values[a + j];
		}
	}
	return res;
}

bool ok(vector <postmark> &v1, vector <postmark> &v2, vector <int> &maxValues, int K, int budget){
	for(int i=0, n=v1.size(); i<n; ++i){
		if(v1[i].cost <= budget){
			int next = budget - v1[i].cost;
			//obtengo el valor apropiado en v2 con fuerza bruta
			/*for(int j=0, n=v2.size(); j<n; ++j){
				if(v2[j].cost <= next && v2[j].value + v1[i].value >= K)return true;
			}*/

			//obtengo el valor apropiado en v2 con bsearch
			int low = 0, high = v2.size();
			while(high - low > 1){
				int mid = (low + high) / 2;
				if(v2[mid].cost > next)high = mid;
				else low = mid;
			}

			//indexo en el arreglo precalculado con los valores maximos
			if(v1[i].value + maxValues[low] >= K)return true;
		}
	}
	return false;
}

struct CollectingPostmarks {
	int amountOfMoney(vector <int> prices, vector <int> have, vector <int> values, int K) {
		int maxValue = accumulate(all(values), 0);
		if(maxValue < K)return -1;
		int budget = 0;
		for(int i=0, n=have.size(); i<n; ++i)
			budget += prices[have[i]];

		vector <postmark> v1=f(prices, values, 0, (int)prices.size()/2), 
			v2 = f(prices, values, (int)prices.size()/2, (int)prices.size());
		
		sort(all(v1));
		sort(all(v2));

		vector <int> maxValues(v2.size(), 0);
		maxValues[0] = v2[0].value;
		for(int i=0, n=v2.size(); i<n-1; ++i){
			maxValues[i+1] = max(maxValues[i], v2[i+1].value);
		}

		int low = 0, high = accumulate(all(prices), 0) - budget;
		while(low < high){
			int mid = (low + high)/2;
			if(ok(v1, v2, maxValues, K, budget + mid))high = mid;
			else low = mid+1;
		}
		return low;
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
			int prices[]              = {0,2,15};
			int have[]                = {0};
			int values[]              = {0,2,21};
			int K                     = 13;
			int expected              = 15;

			return verify_case( casenum, expected, CollectingPostmarks().amountOfMoney( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( have, have + ( sizeof have / sizeof have[0] ) ), vector <int>( values, values + ( sizeof values / sizeof values[0] ) ), K ) );
		}
		case 1: {
			int prices[]              = {9,18,7,6,18};
			int have[]                = {4,0};
			int values[]              = {12,27,10,10,25};
			int K                     = 67;
			int expected              = 22;

			return verify_case( casenum, expected, CollectingPostmarks().amountOfMoney( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( have, have + ( sizeof have / sizeof have[0] ) ), vector <int>( values, values + ( sizeof values / sizeof values[0] ) ), K ) );
		}
		case 2: {
			int prices[]              = {14,14,12,6};
			int have[]                = {3,2,1};
			int values[]              = {19,23,20,7};
			int K                     = 10;
			int expected              = 0;

			return verify_case( casenum, expected, CollectingPostmarks().amountOfMoney( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( have, have + ( sizeof have / sizeof have[0] ) ), vector <int>( values, values + ( sizeof values / sizeof values[0] ) ), K ) );
		}
		case 3: {
			int prices[]              = {43,33,14,31,42,37,17,42,40,20};
			int have[]                = {6};
			int values[]              = {116,71,38,77,87,106,48,107,91,41};
			int K                     = 811;
			int expected              = -1;

			return verify_case( casenum, expected, CollectingPostmarks().amountOfMoney( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( have, have + ( sizeof have / sizeof have[0] ) ), vector <int>( values, values + ( sizeof values / sizeof values[0] ) ), K ) );
		}

		// custom cases

      case 4: {
			int prices[]              = {1412279, 2743706, 8352299, 919972, 6949206, 477740, 4240129, 808796, 2433839, 47292, 8559909, 7453219, 4335037, 1855158, 5281849, 6594181, 7548726, 4672557, 7444771, 2575015, 7661351, 5999219, 2097572, 6562353, 9139205};
			int have[]                = {2, 22};
			int values[]              = {10236198, 23903166, 30000000, 7492251, 30000000, 4196468, 30000000, 7408571, 18867119, 412007, 30000000, 30000000, 30000000, 16340231, 30000000, 30000000, 30000000, 30000000, 30000000, 23772538, 30000000, 30000000, 14011780, 30000000, 30000000};
			int K                     = 108376029;
			int expected              = 2346186;

			return verify_case( casenum, expected, CollectingPostmarks().amountOfMoney( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( have, have + ( sizeof have / sizeof have[0] ) ), vector <int>( values, values + ( sizeof values / sizeof values[0] ) ), K ) );
		}
/*      case 5: {
			int prices[]              = ;
			int have[]                = ;
			int values[]              = ;
			int K                     = ;
			int expected              = ;

			return verify_case( casenum, expected, CollectingPostmarks().amountOfMoney( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( have, have + ( sizeof have / sizeof have[0] ) ), vector <int>( values, values + ( sizeof values / sizeof values[0] ) ), K ) );
		}*/
/*      case 6: {
			int prices[]              = ;
			int have[]                = ;
			int values[]              = ;
			int K                     = ;
			int expected              = ;

			return verify_case( casenum, expected, CollectingPostmarks().amountOfMoney( vector <int>( prices, prices + ( sizeof prices / sizeof prices[0] ) ), vector <int>( have, have + ( sizeof have / sizeof have[0] ) ), vector <int>( values, values + ( sizeof values / sizeof values[0] ) ), K ) );
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
