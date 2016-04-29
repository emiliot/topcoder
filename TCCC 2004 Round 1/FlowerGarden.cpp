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

struct FlowerGarden {
	vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt) {
		vector <int> res(height.size());
		vector <bool>mark(height.size(), false);
		for(int i=0, n=height.size(); i<n; ++i){
			int best = -1;
			for(int j=0; j<n; ++j){
				if(!mark[j]){
					bool ok = true;
					for(int k=0; k<n; ++k){
						if(j != k && !mark[k] &&
							((bloom[j] >= bloom[k] && bloom[j] <= wilt[k]) || (bloom[k] >= bloom[j] && bloom[k] <= wilt[j]))
							&& height[j] > height[k]) ok = false;
					}
					if(ok && (best == -1 || height[best] < height[j]))best = j;
				}
			}
			res[i] = height[best];
			mark[best] = true;
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
			int height[]              = {5,4,3,2,1};
			int bloom[]               = {1,1,1,1,1};
			int wilt[]                = {365,365,365,365,365};
			int expected[]            = { 1,  2,  3,  4,  5 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), FlowerGarden().getOrdering( vector <int>( height, height + ( sizeof height / sizeof height[0] ) ), vector <int>( bloom, bloom + ( sizeof bloom / sizeof bloom[0] ) ), vector <int>( wilt, wilt + ( sizeof wilt / sizeof wilt[0] ) ) ) );
		}
		case 1: {
			int height[]              = {5,4,3,2,1};
			int bloom[]               = {1,5,10,15,20};
			int wilt[]                = {4,9,14,19,24};
			int expected[]            = { 5,  4,  3,  2,  1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), FlowerGarden().getOrdering( vector <int>( height, height + ( sizeof height / sizeof height[0] ) ), vector <int>( bloom, bloom + ( sizeof bloom / sizeof bloom[0] ) ), vector <int>( wilt, wilt + ( sizeof wilt / sizeof wilt[0] ) ) ) );
		}
		case 2: {
			int height[]              = {5,4,3,2,1};
			int bloom[]               = {1,5,10,15,20};
			int wilt[]                = {5,10,15,20,25};
			int expected[]            = { 1,  2,  3,  4,  5 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), FlowerGarden().getOrdering( vector <int>( height, height + ( sizeof height / sizeof height[0] ) ), vector <int>( bloom, bloom + ( sizeof bloom / sizeof bloom[0] ) ), vector <int>( wilt, wilt + ( sizeof wilt / sizeof wilt[0] ) ) ) );
		}
		case 3: {
			int height[]              = {5,4,3,2,1};
			int bloom[]               = {1,5,10,15,20};
			int wilt[]                = {5,10,14,20,25};
			int expected[]            = { 3,  4,  5,  1,  2 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), FlowerGarden().getOrdering( vector <int>( height, height + ( sizeof height / sizeof height[0] ) ), vector <int>( bloom, bloom + ( sizeof bloom / sizeof bloom[0] ) ), vector <int>( wilt, wilt + ( sizeof wilt / sizeof wilt[0] ) ) ) );
		}
		case 4: {
			int height[]              = {1,2,3,4,5,6};
			int bloom[]               = {1,3,1,3,1,3};
			int wilt[]                = {2,4,2,4,2,4};
			int expected[]            = { 2,  4,  6,  1,  3,  5 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), FlowerGarden().getOrdering( vector <int>( height, height + ( sizeof height / sizeof height[0] ) ), vector <int>( bloom, bloom + ( sizeof bloom / sizeof bloom[0] ) ), vector <int>( wilt, wilt + ( sizeof wilt / sizeof wilt[0] ) ) ) );
		}
		case 5: {
			int height[]              = {3,2,5,4};
			int bloom[]               = {1,2,11,10};
			int wilt[]                = {4,3,12,13};
			int expected[]            = { 4,  5,  2,  3 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), FlowerGarden().getOrdering( vector <int>( height, height + ( sizeof height / sizeof height[0] ) ), vector <int>( bloom, bloom + ( sizeof bloom / sizeof bloom[0] ) ), vector <int>( wilt, wilt + ( sizeof wilt / sizeof wilt[0] ) ) ) );
		}

		// custom cases

/*      case 6: {
			int height[]              = ;
			int bloom[]               = ;
			int wilt[]                = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), FlowerGarden().getOrdering( vector <int>( height, height + ( sizeof height / sizeof height[0] ) ), vector <int>( bloom, bloom + ( sizeof bloom / sizeof bloom[0] ) ), vector <int>( wilt, wilt + ( sizeof wilt / sizeof wilt[0] ) ) ) );
		}*/
/*      case 7: {
			int height[]              = ;
			int bloom[]               = ;
			int wilt[]                = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), FlowerGarden().getOrdering( vector <int>( height, height + ( sizeof height / sizeof height[0] ) ), vector <int>( bloom, bloom + ( sizeof bloom / sizeof bloom[0] ) ), vector <int>( wilt, wilt + ( sizeof wilt / sizeof wilt[0] ) ) ) );
		}*/
/*      case 8: {
			int height[]              = ;
			int bloom[]               = ;
			int wilt[]                = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), FlowerGarden().getOrdering( vector <int>( height, height + ( sizeof height / sizeof height[0] ) ), vector <int>( bloom, bloom + ( sizeof bloom / sizeof bloom[0] ) ), vector <int>( wilt, wilt + ( sizeof wilt / sizeof wilt[0] ) ) ) );
		}*/
		default:
			return -1;
		}
	}
}

int main() {
  moj_harness::run_test(4);
} 
// END CUT HERE
