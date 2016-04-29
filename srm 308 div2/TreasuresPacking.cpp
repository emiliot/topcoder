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

struct treasure{
	int w, c;
	double ratio;
	treasure(int _w, int _c, double _ratio):
	w(_w), c(_c), ratio(_ratio){}
	bool operator < (const treasure &other)const{
		return ratio > other.ratio;
	}
};

int memo[60][10005];
bool mark[60][10005];

int f(vector <pair <int, int> > &v, int i, int w){
	if(i >= (int)v.size())return 0;
	if(w <= 0)return 0;
	int &best = memo[i][w];
	if(mark[i][w])return best;
	mark[i][w] = true;
	
	best = f(v, i+1, w);
	
	if(v[i].first <= w){
		best = max(best, f(v,i+1,w-v[i].first) + v[i].second);
	}
	return best;
}

struct TreasuresPacking {
	double maximizeCost(vector <string> treasures, int W) {
		vector< pair < int, int> > v;
		vector <treasure> v1;
		for(int i=0, n=treasures.size(); i<n; ++i){
			istringstream iss(treasures[i]);
			int w, c; char x;
			iss >> w >> c >> x;
			if(x == 'N')v.push_back(make_pair(w,c));
			else{
				v1.push_back(treasure(w,c,c/(double)(w)));
			}
		}
		memset(mark, false,sizeof(mark));
		sort(all(v1));
		double res = 0.0;
		for(int w1 = 0; w1 <= W; ++w1){
			int next = f(v, 0, w1);
			double nextDiv = 0.0;
			for(int i=0, n=v1.size(), k=W-w1; i<n && k>0; ++i){
				int aux = min(v1[i].w, k);
				nextDiv += (double)(aux) * v1[i].ratio;
				k-=aux;
			}
			res = max(res, (double)(next) + nextDiv);
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ( double expected, double result ) { if ( isnan( expected ) ) { return isnan( result ); } else if ( isinf( expected ) ) { if ( expected > 0 ) { return result > 0 && isinf( result ); } else { return result < 0 && isinf( result ); } } else if ( isnan( result ) || isinf( result ) ) { return false; } else if ( fabs( result - expected ) < MAX_DOUBLE_ERROR ) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error( double expected, double result ) { if ( isnan( expected ) || isinf( expected ) || isnan( result ) || isinf( result ) || expected == 0 ) return 0; return fabs( result-expected ) / fabs( expected ); }
	
	int verify_case( int casenum, const double &expected, const double &received ) { 
		cerr << "Example " << casenum << "... "; 
		cerr.precision(9); 
		if ( topcoder_fequ( expected, received ) ) {
			cerr << "PASSED"; 
			double rerr = moj_relative_error( expected, received ); 
			if ( rerr > 0 ) cerr << " (relative error " << rerr << ")";
			cerr << endl;
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
			string treasures[]        = {"100 100 N", "100 100 N", "130 10 Y"};
			int W                     = 150;
			double expected           = 103.84615384615384;

			return verify_case( casenum, expected, TreasuresPacking().maximizeCost( vector <string>( treasures, treasures + ( sizeof treasures / sizeof treasures[0] ) ), W ) );
		}
		case 1: {
			string treasures[]        = {"100 100 N", "100 100 N", "100 1000 Y"};
			int W                     = 150;
			double expected           = 1000.0;

			return verify_case( casenum, expected, TreasuresPacking().maximizeCost( vector <string>( treasures, treasures + ( sizeof treasures / sizeof treasures[0] ) ), W ) );
		}
		case 2: {
			string treasures[]        = {"207 1459 Y", "150 6867 N", "694 3494 Y", "417 7479 N"};
			int W                     = 650;
			double expected           = 14931.00966183575;

			return verify_case( casenum, expected, TreasuresPacking().maximizeCost( vector <string>( treasures, treasures + ( sizeof treasures / sizeof treasures[0] ) ), W ) );
		}
		case 3: {
			string treasures[]        = {"350 2765 Y", "258 560 Y", "120 9325 N", "879 302 Y",  "611 2674 Y", "774 2273 Y", "318 1572 Y"};
			int W                     = 3301;
			double expected           = 19467.907849829353;

			return verify_case( casenum, expected, TreasuresPacking().maximizeCost( vector <string>( treasures, treasures + ( sizeof treasures / sizeof treasures[0] ) ), W ) );
		}

		// custom cases

/*      case 4: {
			string treasures[]        = ;
			int W                     = ;
			double expected           = ;

			return verify_case( casenum, expected, TreasuresPacking().maximizeCost( vector <string>( treasures, treasures + ( sizeof treasures / sizeof treasures[0] ) ), W ) );
		}*/
/*      case 5: {
			string treasures[]        = ;
			int W                     = ;
			double expected           = ;

			return verify_case( casenum, expected, TreasuresPacking().maximizeCost( vector <string>( treasures, treasures + ( sizeof treasures / sizeof treasures[0] ) ), W ) );
		}*/
/*      case 6: {
			string treasures[]        = ;
			int W                     = ;
			double expected           = ;

			return verify_case( casenum, expected, TreasuresPacking().maximizeCost( vector <string>( treasures, treasures + ( sizeof treasures / sizeof treasures[0] ) ), W ) );
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
