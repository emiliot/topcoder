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
// BEGIN CUT HERE

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

bool mark[60][60];
bool mark2[60];
int memo[60];
vector <int> v;
vector <string> g;

int f(int i){
	int &best = memo[i];
	if(mark2[i])return memo[i];
	mark2[i] = true;
	best = 0;
	for(int j=0, n=g.size(); j<n; ++j){
		if(g[i][j]=='Y')best = max(best,f(j));
	}
	best += v[i];
	return best;
}

struct ParallelProgramming {
	int minTime(vector <int> time, vector <string> prec) {
		v.assign(all(time));
		g.assign(all(prec));
		memset(mark,false,sizeof(mark));
		for(int i=0, n=prec.size(); i<n; ++i)
			mark[i][i] = true;
		for(int i=0, n=prec.size(); i<n; ++i){ //establezco los links
			for(int j=0; j<n; ++j){
				mark[i][j] = prec[i][j]=='Y';
				for(int k=0; k<n; ++k)
					mark[i][j] = mark[i][j] || (mark[i][k] && mark[k][j]);
			}
		}
		for(int i=0, n=prec.size(); i<n; ++i){
			for(int j=0; j<n; ++j){
				if(i==j)continue;
				if(mark[i][j] && mark[j][i])return -1; //si hay un ciclo ..
			}
		}
		memset(mark2,false,sizeof(mark2));
		int best = 0;
		for(int i=0, n=prec.size(); i<n; ++i)
			best = max(best,f(i));
		return best;
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
			int time[]                = {150,200,250};
			string prec[]             = {"NNN",  "NNN",  "NNN"};
			int expected              = 250;

			return verify_case( casenum, expected, ParallelProgramming().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <string>( prec, prec + ( sizeof prec / sizeof prec[0] ) ) ) );
		}
		case 1: {
			int time[]                = {150,200,250};
			string prec[]             = {"NNN",  "YNN",  "NNN"};
			int expected              = 350;

			return verify_case( casenum, expected, ParallelProgramming().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <string>( prec, prec + ( sizeof prec / sizeof prec[0] ) ) ) );
		}
		case 2: {
			int time[]                = {150,200,250};
			string prec[]             = {"NYN",  "NNY",  "NNN"};
			int expected              = 600;

			return verify_case( casenum, expected, ParallelProgramming().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <string>( prec, prec + ( sizeof prec / sizeof prec[0] ) ) ) );
		}
		case 3: {
			int time[]                = {150,200,250};
			string prec[]             = {"NYN",  "NNY",  "YNN"};
			int expected              = -1;

			return verify_case( casenum, expected, ParallelProgramming().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <string>( prec, prec + ( sizeof prec / sizeof prec[0] ) ) ) );
		}
		case 4: {
			int time[]                = {345,335,325,350,321,620};
			string prec[]             = {"NNNNNN",  "NNYYYY",  "YNNNNN",  "NNYNYN",  "NNNNNN",  "NNNNNN"};
			int expected              = 1355;

			return verify_case( casenum, expected, ParallelProgramming().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <string>( prec, prec + ( sizeof prec / sizeof prec[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			int time[]                = ;
			string prec[]             = ;
			int expected              = ;

			return verify_case( casenum, expected, ParallelProgramming().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <string>( prec, prec + ( sizeof prec / sizeof prec[0] ) ) ) );
		}*/
/*      case 6: {
			int time[]                = ;
			string prec[]             = ;
			int expected              = ;

			return verify_case( casenum, expected, ParallelProgramming().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <string>( prec, prec + ( sizeof prec / sizeof prec[0] ) ) ) );
		}*/
/*      case 7: {
			int time[]                = ;
			string prec[]             = ;
			int expected              = ;

			return verify_case( casenum, expected, ParallelProgramming().minTime( vector <int>( time, time + ( sizeof time / sizeof time[0] ) ), vector <string>( prec, prec + ( sizeof prec / sizeof prec[0] ) ) ) );
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
