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

int dist[60][60];
bool visited[60];

bool valid(int n,int t){
	stack<int> st;
	st.push(0);
	memset(visited,false,sizeof(visited));
	while(!st.empty()){
		int state = st.top(); st.pop();
		if(visited[state])continue;
		visited[state] = true;
		for(int k=0; k<n; ++k){
			if(dist[state][k] <= t)
				st.push(k);
		}
	}
	for(int i=0; i<n; ++i)
		if(!visited[i])return false;
	return true;
}

struct CityLink {
	int timeTaken(vector <int> x, vector <int> y) {
		for(int i=0, n=x.size(); i<n; ++i)
			x[i]+=1000000, y[i]+=1000000; //avoid negative
		for(int i=0,n=x.size(); i<n; ++i){
			for(int j=i; j<n; ++j){
				const int dx = abs(x[i]-x[j]);
				const int dy = abs(y[i]-y[j]);
				if(dx == 0 || dy == 0)dist[i][j] = dist[j][i] = max((dx+1)/2,(dy+1)/2);
				else dist[i][j] = dist[j][i] = max(dx,dy);
			}
		}
		int low = 0, high = 3000000, mid = (low+high)/2;
		while(low < high){
			if(valid(x.size(),mid))high = mid;
			else low = mid+1;
			mid = (low+high)/2;
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
			int x[]                   = {0,5};
			int y[]                   = {0,5}	;
			int expected              = 5;

			return verify_case( casenum, expected, CityLink().timeTaken( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 1: {
			int x[]                   = {0,0};
			int y[]                   = {30,-59};
			int expected              = 45;

			return verify_case( casenum, expected, CityLink().timeTaken( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 2: {
			int x[]                   = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,  27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49}	;
			int y[]                   = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,  27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49};
			int expected              = 1;

			return verify_case( casenum, expected, CityLink().timeTaken( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 3: {
			int x[]                   = {100000};
			int y[]                   = {-1000000};
			int expected              = 0;

			return verify_case( casenum, expected, CityLink().timeTaken( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}
		case 4: {
			int x[]                   = {1593,-88517,14301,3200,6,-15099,3200,5881,-2593,11,57361,-92990};
			int y[]                   = {99531,-17742,-36499,1582,46,34001,-19234,1883,36001,0,233,485};
			int expected              = 73418;

			return verify_case( casenum, expected, CityLink().timeTaken( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			int expected              = ;

			return verify_case( casenum, expected, CityLink().timeTaken( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int expected              = ;

			return verify_case( casenum, expected, CityLink().timeTaken( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int expected              = ;

			return verify_case( casenum, expected, CityLink().timeTaken( vector <int>( x, x + ( sizeof x / sizeof x[0] ) ), vector <int>( y, y + ( sizeof y / sizeof y[0] ) ) ) );
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
