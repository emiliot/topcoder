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

struct AlphabetPath {
	string doesItExist(vector <string> v) {
		pair <int, int> start; 
		int n=v.size();
		bool found = false;
		for(int i=0; i<n; ++i){
			for(int j=0, m=(int)v[i].size(); j<m; ++j){
				if(v[i][j] == 'A'){
					start.first = i, start.second = j;
					found = true;
				}
			}
		}
		if(!found)
			return "NO";
		int movi[] = {0,0,-1,1};
		int movj[] = {-1,1,0,0};
		int k = 1;
		bool ok = true;
		for(;k<26 && ok;){
			ok = false;
			for(int w = 0; w<4; ++w){
				int ni = start.first+movi[w], nj= start.second+movj[w];
				if(ni >= 0 && ni < n && nj >= 0 && nj <v[start.first].size() &&  v[ni][nj] == (v[start.first][start.second]+1)){
					start.first = ni, start.second = nj;
					k++;
					ok = true;
				}
			}
		}
		if(v[start.first][start.second]=='Z')return "YES";
		else return "NO";
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
			string letterMaze[]       = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
			string expected           = "YES";

			return verify_case( casenum, expected, AlphabetPath().doesItExist( vector <string>( letterMaze, letterMaze + ( sizeof letterMaze / sizeof letterMaze[0] ) ) ) );
		}
		case 1: {
			string letterMaze[]       = {"ADEHI..Z",  "BCFGJK.Y",  ".PONML.X",  ".QRSTUVW"} ;
			string expected           = "YES";

			return verify_case( casenum, expected, AlphabetPath().doesItExist( vector <string>( letterMaze, letterMaze + ( sizeof letterMaze / sizeof letterMaze[0] ) ) ) );
		}
		case 2: {
			string letterMaze[]       = {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"};
			string expected           = "NO";

			return verify_case( casenum, expected, AlphabetPath().doesItExist( vector <string>( letterMaze, letterMaze + ( sizeof letterMaze / sizeof letterMaze[0] ) ) ) );
		}
		case 3: {
			string letterMaze[]       = {"ABC.......",  "...DEFGHIJ",  "TSRQPONMLK",  "UVWXYZ...."};
			string expected           = "NO";

			return verify_case( casenum, expected, AlphabetPath().doesItExist( vector <string>( letterMaze, letterMaze + ( sizeof letterMaze / sizeof letterMaze[0] ) ) ) );
		}
		case 4: {
			string letterMaze[]       = {"..............",  "..............",  "..............",  "...DEFGHIJK...",  "...C......L...",  "...B......M...",  "...A......N...",  "..........O...",  "..ZY..TSRQP...",  "...XWVU.......",  ".............."};
			string expected           = "YES";

			return verify_case( casenum, expected, AlphabetPath().doesItExist( vector <string>( letterMaze, letterMaze + ( sizeof letterMaze / sizeof letterMaze[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string letterMaze[]       = ;
			string expected           = ;

			return verify_case( casenum, expected, AlphabetPath().doesItExist( vector <string>( letterMaze, letterMaze + ( sizeof letterMaze / sizeof letterMaze[0] ) ) ) );
		}*/
/*      case 6: {
			string letterMaze[]       = ;
			string expected           = ;

			return verify_case( casenum, expected, AlphabetPath().doesItExist( vector <string>( letterMaze, letterMaze + ( sizeof letterMaze / sizeof letterMaze[0] ) ) ) );
		}*/
/*      case 7: {
			string letterMaze[]       = ;
			string expected           = ;

			return verify_case( casenum, expected, AlphabetPath().doesItExist( vector <string>( letterMaze, letterMaze + ( sizeof letterMaze / sizeof letterMaze[0] ) ) ) );
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
