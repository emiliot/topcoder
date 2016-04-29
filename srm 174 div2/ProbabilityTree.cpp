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
struct node{
	double px, pnx; int parent;
	node (double _px, int _parent):
	px(_px), parent(_parent){pnx = 1-px;}
	node(double _px, double _pnx, int _parent):
	px(_px),pnx(_pnx),parent(_parent){}
};
double memo[60];

double f(const vector <node> &v, int i){
	if(memo[i] > -0.1)return memo[i];
	memo[i] = (v[i].px * f(v,v[i].parent)) + (v[i].pnx * (1.0-f(v,v[i].parent)));
	return memo[i];
}

struct ProbabilityTree {
	vector <int> getOdds(vector <string> tree, int lowerBound, int upperBound) {
		vector <node> v;
		for(int i=0; i<60; ++i)memo[i] = -1.0;
		v.push_back(node((double)(atoi(tree[0].c_str()))/100.0,-1));
		
		for(int i=1, n=tree.size(); i<n; ++i){
			stringstream iss(tree[i]);
			int px, pnx, parent;
			iss >> parent >> px >> pnx;
			v.push_back(node((double)(px)/100.0,(double)(pnx)/100.0,parent));
		}
		double low = (double)(lowerBound)/100.0, high = (double)(upperBound)/100.0;
		vector <int> res;
		if(v[0].px < high && v[0].px > low)res.push_back(0);
		memo[0] = v[0].px;
		for(int i=1, n=v.size(); i<n; ++i){
			const double next = (v[i].px * f(v,v[i].parent)) + (v[i].pnx * (1.0-f(v,v[i].parent)));
			if(next < high && next > low)res.push_back(i);
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
			string tree[]             = {"40","0 70 10"};
			int lowerBound            = 30;
			int upperBound            = 50;
			int expected[]            = { 0,  1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ProbabilityTree().getOdds( vector <string>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), lowerBound, upperBound ) );
		}
		case 1: {
			string tree[]             = {"20","2 50 50","0 50 50"};
			int lowerBound            = 49;
			int upperBound            = 51;
			int expected[]            = { 1,  2 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ProbabilityTree().getOdds( vector <string>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), lowerBound, upperBound ) );
		}
		case 2: {
			string tree[]             = {"10","0 99 41","1 40 3","2 91 43"};
			int lowerBound            = 81;
			int upperBound            = 88;
			int expected[]            = {-1 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ProbabilityTree().getOdds( vector <string>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), lowerBound, upperBound ) );
		}
		case 3: {
			string tree[]             = {"79","0 64 52","1 70 87","0 38 99","1 24 8"};
			int lowerBound            = 47;
			int upperBound            = 81;
			int expected[]            = { 0,  1,  2,  3 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ProbabilityTree().getOdds( vector <string>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), lowerBound, upperBound ) );
		}
		case 4: {
			string tree[]             = {"51",  "29 58 3",  "6 56 86",  "18 97 1",  "44 99 25",  "33 69 90",  "27 67 49",  "32 15 19",  "33 1 21",  "45 12 33",  "29 24 40",  "45 86 74",  "40 30 65",  "0 18 27",  "1 90 65",  "0 47 62",  "40 81 72",  "42 25 56",  "45 16 81",  "8 94 92",  "29 41 92",  "24 4 29",  "32 56 91",  "20 16 77",  "1 35 79",  "45 77 61",  "6 50 19",  "20 69 43",  "4 6 16",  "15 55 26",  "42 73 90",  "40 8 49",  "33 16 33",  "15 95 47",  "9 66 40",  "25 80 39",  "35 72 70",  "27 10 36",  "40 36 10",  "32 2 48",  "33 44 23",  "22 51 45",  "25 8 43",  "18 32 96",  "45 41 74",  "0 51 6",  "18 48 15"};
			int lowerBound            = 8;
			int upperBound            = 82;
			int expected[]            = { 0,  1,  2,  3,  4,  5,  6,  7,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  20,  21,  23,  24,  25,  26,  27,  28,  29,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ProbabilityTree().getOdds( vector <string>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), lowerBound, upperBound ) );
		}

		// custom cases

/*      case 5: {
			string tree[]             = ;
			int lowerBound            = ;
			int upperBound            = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ProbabilityTree().getOdds( vector <string>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), lowerBound, upperBound ) );
		}*/
/*      case 6: {
			string tree[]             = ;
			int lowerBound            = ;
			int upperBound            = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ProbabilityTree().getOdds( vector <string>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), lowerBound, upperBound ) );
		}*/
/*      case 7: {
			string tree[]             = ;
			int lowerBound            = ;
			int upperBound            = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), ProbabilityTree().getOdds( vector <string>( tree, tree + ( sizeof tree / sizeof tree[0] ) ), lowerBound, upperBound ) );
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
