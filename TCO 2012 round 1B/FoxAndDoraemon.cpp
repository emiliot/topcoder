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
const int INF = 0x3f3f3f3f;
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

bool ok(vector <int> &v, int cost, int t){
	const int n = v.size();
	vector <int> aux(60, -1);
	int k = 1;
	aux[0] = 0;
	bool flag = true;

	for(; k<n && flag;){
		flag = false;
		for(int i=0; i<k && k < n; ++i){
			if(aux[i] + cost + v[i] <= t){
				//if the fox i can be splited and get its work done before the fixed time, then split it
				//then you have two foxes ready at time aux[i] + cost
				aux[k] = aux[i] + cost;
				aux[i] += cost;
				k++;
				flag = true;
			}
		}
	}

	if(!flag)return false;
	for(int i=0; i<n; ++i){
		//if the time to create the fox plus time to do its work is greater than the fixed time return false
		if(aux[i] + v[i] > t)return false;
	}
	return true;
}

struct FoxAndDoraemon {
	int minTime(vector <int> workCost, int splitCost) {
		sort(all(workCost), greater<int>());
		int low = 0, high = INF;
		while(low < high){
			int mid = (low + high)/2;
			if(ok(workCost, splitCost, mid))high = mid;
			else low = mid + 1;
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
			int workCost[]            = {1,2};
			int splitCost             = 1000;
			int expected              = 1002;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}
		case 1: {
			int workCost[]            = {3,6,9,12};
			int splitCost             = 1000;
			int expected              = 2012;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}
		case 2: {
			int workCost[]            = {1000,100,10,1};
			int splitCost             = 1;
			int expected              = 1001;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}
		case 3: {
			int workCost[]            = {1712,1911,1703,1610,1697,1612};
			int splitCost             = 100;
			int expected              = 2012;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}
		case 4: {
			int workCost[]            = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
			int splitCost             = 3000;
			int expected              = 15000;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}
		case 5: {
			int workCost[]            = {58};
			int splitCost             = 3600;
			int expected              = 58;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}

		// custom cases

/*      case 6: {
			int workCost[]            = ;
			int splitCost             = ;
			int expected              = ;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}*/
/*      case 7: {
			int workCost[]            = ;
			int splitCost             = ;
			int expected              = ;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
		}*/
/*      case 8: {
			int workCost[]            = ;
			int splitCost             = ;
			int expected              = ;

			return verify_case( casenum, expected, FoxAndDoraemon().minTime( vector <int>( workCost, workCost + ( sizeof workCost / sizeof workCost[0] ) ), splitCost ) );
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
