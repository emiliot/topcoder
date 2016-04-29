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

bool f(vector <string> A, vector <string> B){ //true b < a false otherwise
	int n = A.size();
	for(int i=0; i<n; ++i){
		if(A[i] < B[i])return false;
		else if(B[i] < A[i])return true;
	}
	return false;
}

struct MatrixGame {
	vector <string> getMinimal(vector <string> matrix) {
		vector <string> res(all(matrix));
		sort (all(res));
		vector <int> rotation(matrix[0].size());
		for(int j=0,n=matrix[0].size(); j<n; ++j)
			rotation[j] = j+1;

		for(;next_permutation(all(rotation));){
			vector <string> next(matrix.size());
			for(int i=0, n=matrix.size(); i<n; ++i){
				for(int j=0, m = rotation.size(); j<m; ++j){
					next[i] += matrix[i][rotation[j]-1];
				}
			}
			sort(all(next));
			if(f(res,next))res.assign(all(next));
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
			string matrix[]           = {"000",  "000",  "000"};
			string expected[]         = {"000", "000", "000" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), MatrixGame().getMinimal( vector <string>( matrix, matrix + ( sizeof matrix / sizeof matrix[0] ) ) ) );
		}
		case 1: {
			string matrix[]           = {"010",  "000",  "110"};
			string expected[]         = {"000", "001", "011" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), MatrixGame().getMinimal( vector <string>( matrix, matrix + ( sizeof matrix / sizeof matrix[0] ) ) ) );
		}
		case 2: {
			string matrix[]           = {"111",  "111",  "111"};
			string expected[]         = {"111", "111", "111" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), MatrixGame().getMinimal( vector <string>( matrix, matrix + ( sizeof matrix / sizeof matrix[0] ) ) ) );
		}
		case 3: {
			string matrix[]           = {"01010",  "10101",  "01010",  "10101"};
			string expected[]         = {"00011", "00011", "11100", "11100" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), MatrixGame().getMinimal( vector <string>( matrix, matrix + ( sizeof matrix / sizeof matrix[0] ) ) ) );
		}
		case 4: {
			string matrix[]           = {"11010100",  "11110001",  "00011101",  "11111111",  "01110100",  "10000110",  "00001001",  "11010111"};
			string expected[]         = {"00000011", "00001111", "00110100", "01011100", "01111101", "11001100", "11011001", "11111111" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), MatrixGame().getMinimal( vector <string>( matrix, matrix + ( sizeof matrix / sizeof matrix[0] ) ) ) );
		}

		// custom cases

      case 5: {
			string matrix[]           = {"0110"};
			string expected[]         = {"0011"};

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), MatrixGame().getMinimal( vector <string>( matrix, matrix + ( sizeof matrix / sizeof matrix[0] ) ) ) );
		}
/*      case 6: {
			string matrix[]           = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), MatrixGame().getMinimal( vector <string>( matrix, matrix + ( sizeof matrix / sizeof matrix[0] ) ) ) );
		}*/
/*      case 7: {
			string matrix[]           = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), MatrixGame().getMinimal( vector <string>( matrix, matrix + ( sizeof matrix / sizeof matrix[0] ) ) ) );
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
