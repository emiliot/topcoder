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

bool mark[20][20][20];
int memo[20][20][20];


int f(vector <int> &v, int wLeft, int a, int b){
	if(wLeft <= 1)return v[b] - v[a];
	if(abs(b-a) <= 0)return 0;

	int &best = memo[wLeft][a][b];
	if(mark[wLeft][a][b])return best;
	mark[wLeft][a][b] = true;

	best = max(v[a+1] - v[a], f(v, wLeft - 1, a+1, b));
	for(int i=a+2, n=b-wLeft+2; i<n; ++i){
		int next = max(v[i] - v[a], f(v, wLeft - 1, i, b));
		best = min(best, next);
	}
	
	return best;
}

struct FairWorkload {
	int getMostWork(vector <int> folders, int workers) {
		vector <int> v(folders.size()+1, 0);
		for(int i=0, n=folders.size(); i<n; ++i)
			v[i+1] = v[i] + folders[i];
		memset(mark, false, sizeof(mark));
		int res = f(v, workers, 0, folders.size());
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
			int folders[]             = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
			int workers               = 3;
			int expected              = 170;

			return verify_case( casenum, expected, FairWorkload().getMostWork( vector <int>( folders, folders + ( sizeof folders / sizeof folders[0] ) ), workers ) );
		}
		case 1: {
			int folders[]             = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
			int workers               = 5;
			int expected              = 110;

			return verify_case( casenum, expected, FairWorkload().getMostWork( vector <int>( folders, folders + ( sizeof folders / sizeof folders[0] ) ), workers ) );
		}
		case 2: {
			int folders[]             = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 };
			int workers               = 4;
			int expected              = 1785;

			return verify_case( casenum, expected, FairWorkload().getMostWork( vector <int>( folders, folders + ( sizeof folders / sizeof folders[0] ) ), workers ) );
		}
		case 3: {
			int folders[]             = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000 };
			int workers               = 2;
			int expected              = 1000;

			return verify_case( casenum, expected, FairWorkload().getMostWork( vector <int>( folders, folders + ( sizeof folders / sizeof folders[0] ) ), workers ) );
		}
		case 4: {
			int folders[]             = { 50, 50, 50, 50, 50, 50, 50 };
			int workers               = 2;
			int expected              = 200;

			return verify_case( casenum, expected, FairWorkload().getMostWork( vector <int>( folders, folders + ( sizeof folders / sizeof folders[0] ) ), workers ) );
		}
		case 5: {
			int folders[]             = {1,1,1,1,100};
			int workers               = 5;
			int expected              = 100;

			return verify_case( casenum, expected, FairWorkload().getMostWork( vector <int>( folders, folders + ( sizeof folders / sizeof folders[0] ) ), workers ) );
		}
		case 6: {
			int folders[]             = { 950, 650, 250, 250, 350, 100, 650, 150, 150, 700 };
			int workers               = 6;
			int expected              = 950;

			return verify_case( casenum, expected, FairWorkload().getMostWork( vector <int>( folders, folders + ( sizeof folders / sizeof folders[0] ) ), workers ) );
		}

		// custom cases

/*      case 7: {
			int folders[]             = ;
			int workers               = ;
			int expected              = ;

			return verify_case( casenum, expected, FairWorkload().getMostWork( vector <int>( folders, folders + ( sizeof folders / sizeof folders[0] ) ), workers ) );
		}*/
/*      case 8: {
			int folders[]             = ;
			int workers               = ;
			int expected              = ;

			return verify_case( casenum, expected, FairWorkload().getMostWork( vector <int>( folders, folders + ( sizeof folders / sizeof folders[0] ) ), workers ) );
		}*/
/*      case 9: {
			int folders[]             = ;
			int workers               = ;
			int expected              = ;

			return verify_case( casenum, expected, FairWorkload().getMostWork( vector <int>( folders, folders + ( sizeof folders / sizeof folders[0] ) ), workers ) );
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
