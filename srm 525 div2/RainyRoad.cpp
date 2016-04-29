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

struct RainyRoad {
	string isReachable(vector <string> road) {
		queue < pair <int, int> > q;
		bool mark[3][60];
		q.push( make_pair(0,0));
		mark[0][0] = true;
		int n = road[0].size()-1;
		memset(mark, 0, sizeof(mark));
		int movi[] = {0,-1,1,-1,1};
		int movj[] = {1,0,0,1,1};
		while(!q.empty()){
			pair <int, int> st = q.front(); q.pop();
			if(st.first == 0 && st.second == n)return "YES";
			for(int i=0; i<5; ++i){
				int ni = st.first+movi[i], nj = st.second+movj[i];
				if(ni >=0 && ni < (int) road.size() && nj >=0 && nj <= n && !mark[ni][nj] && road[ni][nj] != 'W'){
					mark[ni][nj] = true;
					q.push(make_pair(ni,nj));
				}
			}
		}
		return "NO";
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
	
	int verify_case( int casenum, const string &expected, const string &received ) { 
		cerr << "Example " << casenum << "... "; 
		if ( expected == received ) {
			cerr << "PASSED" << endl;
			return 1;
		} else {
			cerr << "FAILED" << endl;
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
			return 0;
		}
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string road[]             = {".W.." ,"...."};
			string expected           = "YES";

			return verify_case( casenum, expected, RainyRoad().isReachable( vector <string>( road, road + ( sizeof road / sizeof road[0] ) ) ) );
		}
		case 1: {
			string road[]             = {".W.." ,"..W."};
			string expected           = "YES";

			return verify_case( casenum, expected, RainyRoad().isReachable( vector <string>( road, road + ( sizeof road / sizeof road[0] ) ) ) );
		}
		case 2: {
			string road[]             = {".W..W.." ,"...WWW."};
			string expected           = "NO";

			return verify_case( casenum, expected, RainyRoad().isReachable( vector <string>( road, road + ( sizeof road / sizeof road[0] ) ) ) );
		}
		case 3: {
			string road[]             = {".." ,"WW"};
			string expected           = "YES";

			return verify_case( casenum, expected, RainyRoad().isReachable( vector <string>( road, road + ( sizeof road / sizeof road[0] ) ) ) );
		}
		case 4: {
			string road[]             = {".WWWW." ,"WWWWWW"};
			string expected           = "NO";

			return verify_case( casenum, expected, RainyRoad().isReachable( vector <string>( road, road + ( sizeof road / sizeof road[0] ) ) ) );
		}
		case 5: {
			string road[]             = {".W.W.W." ,"W.W.W.W"};
			string expected           = "YES";

			return verify_case( casenum, expected, RainyRoad().isReachable( vector <string>( road, road + ( sizeof road / sizeof road[0] ) ) ) );
		}
		case 6: {
			string road[]             = {".............................................W." ,".............................................W."};
			string expected           = "NO";

			return verify_case( casenum, expected, RainyRoad().isReachable( vector <string>( road, road + ( sizeof road / sizeof road[0] ) ) ) );
		}

		// custom cases

/*      case 7: {
			string road[]             = ;
			string expected           = ;

			return verify_case( casenum, expected, RainyRoad().isReachable( vector <string>( road, road + ( sizeof road / sizeof road[0] ) ) ) );
		}*/
/*      case 8: {
			string road[]             = ;
			string expected           = ;

			return verify_case( casenum, expected, RainyRoad().isReachable( vector <string>( road, road + ( sizeof road / sizeof road[0] ) ) ) );
		}*/
/*      case 9: {
			string road[]             = ;
			string expected           = ;

			return verify_case( casenum, expected, RainyRoad().isReachable( vector <string>( road, road + ( sizeof road / sizeof road[0] ) ) ) );
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
