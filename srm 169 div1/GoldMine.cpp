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
bool mark[60][305];
int choice[60][305];
double memo[60][305];
const double INF = 100000.0;
const double eps = 1e-9;

double getEsp(vector <int> &v, int k){
	if(k <= 0)return 0.0;
	double res = 0.0;
	for(int i=0; i<=6; ++i){
		if(v[i] == 0)continue;
		if(i < k){
			res += ((double)(v[i])/100.0) * (double)((i*50) - (k-i)*20);
		}else if(i == k){
			res += ((double)(v[i])/100.0 * (double)(i*50));
		}else{
			res += ((double)(v[i])/100.0 * (double)(k*60));
		}
	}
	return res;
}

double f(vector < vector <int> > &v, const int n, int i, int k){ //k==miners, i==mine
	if(i >= n){
		if(k <= 0)return 0.0; //no more mines
		else return -INF; //non valid miners unused
	}
	if(k <= 0)return 0.0; //no more miners

	double &best = memo[i][k];
	if(mark[i][k])return best;
	mark[i][k] = true;
	best = -INF;

	for(int w = min(6, k); w >= 0; --w){
		double next = getEsp(v[i], w) + f(v, n, i+1, k-w);
		//printf("DEBUG: next=%lf i=%d k=%d w=%d\n", next, i, k, w);
		if(next - best > eps){ //update only when is better
			best = next;
			choice[i][k] = w;
		}
	}
	return best;
}

vector <int> g(vector < vector <int> >&v, const int n, int i, int k){
	vector <int> res(n, 0);
	for(int i=0; i<n; ++i){
		int &ch = choice[i][k];
		res[i] = ch;
		k-=res[i];
	}
	return res;
}

struct GoldMine {
	vector <int> getAllocation(vector <string> mines, int miners) {
		vector < vector <int> > v(mines.size(), vector <int>(7));
		for(int i=0, n=mines.size(); i<n; ++i){
			for(int j=0, m=mines[i].size(); j<m; ++j){
				if(mines[i][j] == ',')mines[i][j] = ' ';
			}
			istringstream iss(mines[i]);
			for(int j=0; j<=6 && iss >> v[i][j]; ++j);
		}

		memset(mark, false, sizeof(mark));
		double r1 = f(v, (int)mines.size(), 0, miners);
		//printf("DEBUG: %lf\n", r1);
		vector <int> res = g(v, (int)mines.size(), 0, miners);
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
			string mines[]            = { "000, 030, 030, 040, 000, 000, 000",   "020, 020, 020, 010, 010, 010, 010" };
			int miners                = 4;
			int expected[]            = { 2,  2 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), GoldMine().getAllocation( vector <string>( mines, mines + ( sizeof mines / sizeof mines[0] ) ), miners ) );
		}
		case 1: {
			string mines[]            = { "100, 000, 000, 000, 000, 000, 000",   "100, 000, 000, 000, 000, 000, 000",   "100, 000, 000, 000, 000, 000, 000",   "100, 000, 000, 000, 000, 000, 000",   "100, 000, 000, 000, 000, 000, 000" };
			int miners                = 8;
			int expected[]            = { 6,  2,  0,  0,  0 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), GoldMine().getAllocation( vector <string>( mines, mines + ( sizeof mines / sizeof mines[0] ) ), miners ) );
		}
		case 2: {
			string mines[]            = { "050, 000, 000, 000, 000, 050, 000",   "050, 000, 000, 000, 000, 050, 000",   "050, 000, 000, 000, 000, 050, 000",   "050, 000, 000, 000, 000, 050, 000",   "050, 000, 000, 000, 000, 050, 000",   "050, 000, 000, 000, 000, 050, 000",   "050, 000, 000, 000, 000, 050, 000",   "050, 000, 000, 000, 000, 050, 000",   "050, 000, 000, 000, 000, 050, 000",   "050, 000, 000, 000, 000, 050, 000" };
			int miners                = 30;
			int expected[]            = { 4,  4,  4,  4,  4,  4,  4,  2,  0,  0 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), GoldMine().getAllocation( vector <string>( mines, mines + ( sizeof mines / sizeof mines[0] ) ), miners ) );
		}
		case 3: {
			string mines[]            = { "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004",   "026, 012, 005, 013, 038, 002, 004" };
			int miners                = 56;
			int expected[]            = { 2,  2,  2,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), GoldMine().getAllocation( vector <string>( mines, mines + ( sizeof mines / sizeof mines[0] ) ), miners ) );
		}
		case 4: {
			string mines[]            = { "100, 000, 000, 000, 000, 000, 000",   "090, 010, 000, 000, 000, 000, 000",   "080, 020, 000, 000, 000, 000, 000",   "075, 025, 000, 000, 000, 000, 000",   "050, 050, 000, 000, 000, 000, 000",   "025, 075, 000, 000, 000, 000, 000",   "020, 080, 000, 000, 000, 000, 000",   "010, 090, 000, 000, 000, 000, 000",   "000, 100, 000, 000, 000, 000, 000",   "000, 090, 010, 000, 000, 000, 000",   "000, 080, 020, 000, 000, 000, 000",   "000, 075, 025, 000, 000, 000, 000",   "000, 050, 050, 000, 000, 000, 000",   "000, 025, 075, 000, 000, 000, 000",   "000, 020, 080, 000, 000, 000, 000",   "000, 010, 090, 000, 000, 000, 000",   "000, 000, 100, 000, 000, 000, 000",   "000, 000, 090, 010, 000, 000, 000",   "000, 000, 080, 020, 000, 000, 000",   "000, 000, 075, 025, 000, 000, 000",   "000, 000, 050, 050, 000, 000, 000",   "000, 000, 025, 075, 000, 000, 000",   "000, 000, 020, 080, 000, 000, 000",   "000, 000, 010, 090, 000, 000, 000",   "000, 000, 000, 100, 000, 000, 000",   "000, 000, 000, 100, 000, 000, 000",   "000, 000, 000, 090, 010, 000, 000",   "000, 000, 000, 080, 020, 000, 000",   "000, 000, 000, 075, 025, 000, 000",   "000, 000, 000, 050, 050, 000, 000",   "000, 000, 000, 025, 075, 000, 000",   "000, 000, 000, 020, 080, 000, 000",   "000, 000, 000, 010, 090, 000, 000",   "000, 000, 000, 000, 100, 000, 000",   "000, 000, 000, 000, 090, 010, 000",   "000, 000, 000, 000, 080, 020, 000",   "000, 000, 000, 000, 075, 025, 000",   "000, 000, 000, 000, 050, 050, 000",   "000, 000, 000, 000, 025, 075, 000",   "000, 000, 000, 000, 020, 080, 000",   "000, 000, 000, 000, 010, 090, 000",   "000, 000, 000, 000, 000, 100, 000",   "000, 000, 000, 000, 000, 090, 010",   "000, 000, 000, 000, 000, 080, 020",   "000, 000, 000, 000, 000, 075, 025",   "000, 000, 000, 000, 000, 050, 050",   "000, 000, 000, 000, 000, 025, 075",   "000, 000, 000, 000, 000, 020, 080",   "000, 000, 000, 000, 000, 010, 090",   "000, 000, 000, 000, 000, 000, 100" };
			int miners                = 150;
			int expected[]            = { 0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  6,  6 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), GoldMine().getAllocation( vector <string>( mines, mines + ( sizeof mines / sizeof mines[0] ) ), miners ) );
		}

		// custom cases

/*      case 5: {
			string mines[]            = ;
			int miners                = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), GoldMine().getAllocation( vector <string>( mines, mines + ( sizeof mines / sizeof mines[0] ) ), miners ) );
		}*/
/*      case 6: {
			string mines[]            = ;
			int miners                = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), GoldMine().getAllocation( vector <string>( mines, mines + ( sizeof mines / sizeof mines[0] ) ), miners ) );
		}*/
/*      case 7: {
			string mines[]            = ;
			int miners                = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), GoldMine().getAllocation( vector <string>( mines, mines + ( sizeof mines / sizeof mines[0] ) ), miners ) );
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
