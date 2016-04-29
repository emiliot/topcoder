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
const int INF = 0x3f3f3f3f;
struct SkipRope {
	vector <int> partners(vector <int> v, int height) {
		vector <int> res(2);
		int dh = abs(v[0]-height), indx = 0;
		for(int i=1, n=v.size(); i<n; ++i){
			const int next = abs(v[i]-height);
			if(next < dh || (next == dh && v[i]>v[indx])){
				dh = next, indx = i;
				if(dh == 0)break;
			}
		}
		res[0] = v[indx]; v[indx] = INF;
		dh = INF, indx = -1;
		for(int i=0,n=v.size(); i<n; ++i){
			const int next = abs(v[i]-height);
			if((next < dh) || (next == dh && v[i]>v[indx])){
				dh = next, indx = i;
				if(dh == 0)break;
			}
		}
		res[1] = v[indx];
		sort(res.begin(),res.end());
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
			int candidates[]          = {102, 99, 104};
			int height                = 100;
			int expected[]            = { 99,  102 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height ) );
		}
		case 1: {
			int candidates[]          = {102, 97, 104};
			int height                = 100;
			int expected[]            = { 97,  102 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height ) );
		}
		case 2: {
			int candidates[]          = {101, 100, 99};
			int height                = 100;
			int expected[]            = { 100,  101 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height ) );
		}
		case 3: {
			int candidates[]          = {75, 117, 170, 175, 168, 167, 167, 142, 170, 85, 89, 170};
			int height                = 169;
			int expected[]            = { 170,  170 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height ) );
		}
		case 4: {
			int candidates[]          = {134, 79, 164, 86, 131, 78, 99, 150, 105, 163, 150, 110, 90, 137, 127, 130, 121,   93, 97, 131, 170, 137, 171, 153, 137, 138, 92, 103, 149, 110, 156};
			int height                = 82;
			int expected[]            = { 79,  86 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height ) );
		}

		// custom cases

/*      case 5: {
			int candidates[]          = ;
			int height                = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height ) );
		}*/
/*      case 6: {
			int candidates[]          = ;
			int height                = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height ) );
		}*/
/*      case 7: {
			int candidates[]          = ;
			int height                = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), SkipRope().partners( vector <int>( candidates, candidates + ( sizeof candidates / sizeof candidates[0] ) ), height ) );
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
