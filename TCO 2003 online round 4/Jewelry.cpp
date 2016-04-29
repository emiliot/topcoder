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

i64 waysBelow[30003];
i64 waysAbove[30003];

i64 c[50][50];

void pascT(){
	for(int i=0; i<50; ++i)c[i][0] = c[0][i] = 1;
	for(int i=1; i<50; ++i)
		for(int j=1; j<50; ++j)
			c[i][j] = c[i-1][j] + c[i][j-1];
}

int choose(int n, int m){
	return c[n-m][m];
}

void calcWaysBelow(const vector <int> &v, int a, int b){
	memset(waysBelow, 0LL, sizeof(waysBelow));
	//if(a >= b)return;
	waysBelow[0] = 1LL;
	for(int i=a; i<b; ++i){
		for(int j=30000; j>=0 && j-v[i] >=0; --j)
			waysBelow[j] += waysBelow[j-v[i]];
	}
}

void calcWaysAbove(const vector <int> &v, int a, int b){
	memset(waysAbove, 0LL, sizeof(waysAbove));
	//if(a >= b)return;
	waysAbove[0] = 1LL;
	for(int i=a; i<b; ++i){
		for(int j=30000; j>=0 && j-v[i] >= 0; --j)
			waysAbove[j] += waysAbove[j-v[i]];
	}
}

struct Jewelry {
	long long howMany(vector <int> v) {
		pascT();
		
		sort(all(v));
		
		vector < pair <int, int> >groups;
		for(int i=0, n=v.size(), j; i<n;){
			for(j=i+1; j<n && v[i]==v[j]; ++j);
			groups.push_back(make_pair(i,j-i));
			i=j;
		}

		i64 count = 0LL;
		for(int g=0, G=groups.size(); g<G; ++g){
			int i = groups[g].first, size = groups[g].second;
			
			//calcWaysBelow
			calcWaysBelow(v,0,i);

			for(int k=1; k<=size; ++k){
				//CalcWaysAbove 
				calcWaysAbove(v,i+k,(int)v.size());
				
				for(int s=k*v[i]; s < 30001; ++s){
					count += choose(size,k) * waysBelow[s-(v[i]*k)] * waysAbove[s];
				}
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
			int values[]              = {1,2,5,3,4,5};
			long long expected        = 9LL;

			return verify_case( casenum, expected, Jewelry().howMany( vector <int>( values, values + ( sizeof values / sizeof values[0] ) ) ) );
		}
		case 1: {
			int values[]              = {1000,1000,1000,1000,1000,  1000,1000,1000,1000,1000,  1000,1000,1000,1000,1000,  1000,1000,1000,1000,1000,  1000,1000,1000,1000,1000,  1000,1000,1000,1000,1000};
			long long expected        = 18252025766940LL;

			return verify_case( casenum, expected, Jewelry().howMany( vector <int>( values, values + ( sizeof values / sizeof values[0] ) ) ) );
		}
		case 2: {
			int values[]              = {1,2,3,4,5};
			long long expected        = 4LL;

			return verify_case( casenum, expected, Jewelry().howMany( vector <int>( values, values + ( sizeof values / sizeof values[0] ) ) ) );
		}
		case 3: {
			int values[]              = {7,7,8,9,10,11,1,2,2,3,4,5,6};
			long long expected        = 607LL;

			return verify_case( casenum, expected, Jewelry().howMany( vector <int>( values, values + ( sizeof values / sizeof values[0] ) ) ) );
		}
		case 4: {
			int values[]              = {123,217,661,678,796,964,54,111,417,526,917,923};
			long long expected        = 0LL;

			return verify_case( casenum, expected, Jewelry().howMany( vector <int>( values, values + ( sizeof values / sizeof values[0] ) ) ) );
		}

		// custom cases

      case 5: {
		  int values[]              = {1,1,2};
			long long expected        = 3LL;

			return verify_case( casenum, expected, Jewelry().howMany( vector <int>( values, values + ( sizeof values / sizeof values[0] ) ) ) );
		}
/*      case 6: {
			int values[]              = ;
			long long expected        = LL;

			return verify_case( casenum, expected, Jewelry().howMany( vector <int>( values, values + ( sizeof values / sizeof values[0] ) ) ) );
		}*/
/*      case 7: {
			int values[]              = ;
			long long expected        = LL;

			return verify_case( casenum, expected, Jewelry().howMany( vector <int>( values, values + ( sizeof values / sizeof values[0] ) ) ) );
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
