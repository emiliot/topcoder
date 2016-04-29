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

struct Animation {
	vector <string> animate(int speed, string s) {
		vector <string> res;
		bool rest = false;
		vector < vector <int> > v(s.size());
		for(int i=0, n = s.size(); i<n; ++i){
			if(s[i] == 'L')v[i].push_back(-speed), rest = true;
			else if(s[i] == 'R')v[i].push_back(speed), rest = true;
		}
		while(rest){
			string state = "";
			rest = false;
			vector < vector <int> > next(v.size());
			for(int i=0, n=v.size(); i<n; ++i){
				if(v[i].size()==0)state += ".";
				else state += "X";
			}
			//simular
			for(int i=0, n=v.size(); i<n; ++i){
				for(int j=0, m=v[i].size(); j<m; ++j){
					if((v[i][j] + i >= 0) && (v[i][j]+i < (int)(v.size()))){
						next[v[i][j]+i].push_back(v[i][j]);
						rest = true;
					}
				}
			}
			v = next;
			res.push_back(state);
		}
		string x;
		for(int i=0, n=s.size(); i<n; ++i)
			x+=".";
		res.push_back(x);
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
	template<> ostream& operator<<( ostream &os, const vector<string> &v ) { os << "{"; for ( vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case( int casenum, const vector <string> &expected, const vector <string> &received ) { 
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
			int speed                 = 2;
			string init               =  "..R...." ;
			string expected[]         = { "..X....",  "....X..",  "......X",  "......." };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Animation().animate( speed, init ) );
		}
		case 1: {
			int speed                 = 3;
			string init               = "RR..LRL" ;
			string expected[]         = { "XX..XXX",  ".X.XX..",  "X.....X",  "......." };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Animation().animate( speed, init ) );
		}
		case 2: {
			int speed                 = 2;
			string init               = "LRLR.LRLR";
			string expected[]         = { "XXXX.XXXX",  "X..X.X..X",  ".X.X.X.X.",  ".X.....X.",  "........." };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Animation().animate( speed, init ) );
		}
		case 3: {
			int speed                 = 10;
			string init               = "RLRLRLRLRL";
			string expected[]         = { "XXXXXXXXXX",  ".........." };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Animation().animate( speed, init ) );
		}
		case 4: {
			int speed                 = 1;
			string init               = "...";
			string expected[]         = { "..." };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Animation().animate( speed, init ) );
		}
		case 5: {
			int speed                 = 1;
			string init               = "LRRL.LR.LRR.R.LRRL.";
			string expected[]         = { "XXXX.XX.XXX.X.XXXX.",  "..XXX..X..XX.X..XX.",  ".X.XX.X.X..XX.XX.XX",  "X.X.XX...X.XXXXX..X",  ".X..XXX...X..XX.X..",  "X..X..XX.X.XX.XX.X.",  "..X....XX..XX..XX.X",  ".X.....XXXX..X..XX.",  "X.....X..XX...X..XX",  ".....X..X.XX...X..X",  "....X..X...XX...X..",  "...X..X.....XX...X.",  "..X..X.......XX...X",  ".X..X.........XX...",  "X..X...........XX..",  "..X.............XX.",  ".X...............XX",  "X.................X",  "..................." };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Animation().animate( speed, init ) );
		}

		// custom cases

/*      case 6: {
			int speed                 = ;
			string init               = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Animation().animate( speed, init ) );
		}*/
/*      case 7: {
			int speed                 = ;
			string init               = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Animation().animate( speed, init ) );
		}*/
/*      case 8: {
			int speed                 = ;
			string init               = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Animation().animate( speed, init ) );
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
