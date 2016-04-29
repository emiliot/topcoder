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

bool ok(vector <int> &v){
	int sum = accumulate(v.begin(), v.begin()+3, 0);
	for(int i=1; i<3; ++i){
		int nextSum = 0;
		for(int j=0; j<3; ++j)
			nextSum += v[(i*3)+j];
		if(nextSum != sum)return false;
	}
	for(int i=0; i<3; ++i){
		int nextSum = 0;
		for(int j=i; j<9; j+=3)
			nextSum += v[j];
		if(nextSum != sum)return false;
	}
	return true;
}

struct MNS {
	int combos(vector <int> numbers) {
		vector<int> p(9), act(9);
		for(int i=0; i<9; ++i)p[i] = i;
		int res = 0;
		set <string> mark;
		while(next_permutation(all(p))){
			string next = "";
			for(int i=0; i<9; ++i){
				next += numbers[p[i]] + '0';
				act[i] = numbers[p[i]];
			}
			if(!mark.insert(next).second)continue;
			if(ok(act))++res;
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
			int numbers[]             = {1,2,3,3,2,1,2,2,2};
			int expected              = 18;

			return verify_case( casenum, expected, MNS().combos( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) ) );
		}
		case 1: {
			int numbers[]             = {4,4,4,4,4,4,4,4,4};
			int expected              = 1;

			return verify_case( casenum, expected, MNS().combos( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) ) );
		}
		case 2: {
			int numbers[]             = {1,5,1,2,5,6,2,3,2};
			int expected              = 36;

			return verify_case( casenum, expected, MNS().combos( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) ) );
		}
		case 3: {
			int numbers[]             = {1,2,6,6,6,4,2,6,4};
			int expected              = 0;

			return verify_case( casenum, expected, MNS().combos( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) ) );
		}

		// custom cases

/*      case 4: {
			int numbers[]             = ;
			int expected              = ;

			return verify_case( casenum, expected, MNS().combos( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) ) );
		}*/
/*      case 5: {
			int numbers[]             = ;
			int expected              = ;

			return verify_case( casenum, expected, MNS().combos( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) ) );
		}*/
/*      case 6: {
			int numbers[]             = ;
			int expected              = ;

			return verify_case( casenum, expected, MNS().combos( vector <int>( numbers, numbers + ( sizeof numbers / sizeof numbers[0] ) ) ) );
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
