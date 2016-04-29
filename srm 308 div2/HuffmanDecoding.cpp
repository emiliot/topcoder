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

struct HuffmanDecoding {
	string decode(string archive, vector <string> dictionary) {
		map <string, char> m;
		for(int i=0, n=dictionary.size(); i<n; ++i){
			m.insert(make_pair(dictionary[i],'A'+i));
		}
		string res = "";
		for(int i=0, n=archive.size(); i<n;){
			for(int j=i+1; j<=n; ++j){
				string next = archive.substr(i,j-i);
				map<string, char>::iterator it = m.find(next);
				if(it != m.end()){
					res+=it->second;
					i=j;
					break;
				}
			}
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
			string archive            = "101101";
			string dictionary[]       = {"00","10","01","11"};
			string expected           = "BDC";

			return verify_case( casenum, expected, HuffmanDecoding().decode( archive, vector <string>( dictionary, dictionary + ( sizeof dictionary / sizeof dictionary[0] ) ) ) );
		}
		case 1: {
			string archive            = "10111010";
			string dictionary[]       = {"0","111","10"};
			string expected           = "CBAC";

			return verify_case( casenum, expected, HuffmanDecoding().decode( archive, vector <string>( dictionary, dictionary + ( sizeof dictionary / sizeof dictionary[0] ) ) ) );
		}
		case 2: {
			string archive            = "0001001100100111001";
			string dictionary[]       = {"1","0"};
			string expected           = "BBBABBAABBABBAAABBA";

			return verify_case( casenum, expected, HuffmanDecoding().decode( archive, vector <string>( dictionary, dictionary + ( sizeof dictionary / sizeof dictionary[0] ) ) ) );
		}
		case 3: {
			string archive            = "111011011000100110";
			string dictionary[]       = {"010","00","0110","0111","11","100","101"};
			string expected           = "EGGFAC";

			return verify_case( casenum, expected, HuffmanDecoding().decode( archive, vector <string>( dictionary, dictionary + ( sizeof dictionary / sizeof dictionary[0] ) ) ) );
		}
		case 4: {
			string archive            = "001101100101100110111101011001011001010";
			string dictionary[]       = {"110","011","10","0011","00011","111","00010","0010","010","0000"};
			string expected           = "DBHABBACAIAIC";

			return verify_case( casenum, expected, HuffmanDecoding().decode( archive, vector <string>( dictionary, dictionary + ( sizeof dictionary / sizeof dictionary[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string archive            = ;
			string dictionary[]       = ;
			string expected           = ;

			return verify_case( casenum, expected, HuffmanDecoding().decode( archive, vector <string>( dictionary, dictionary + ( sizeof dictionary / sizeof dictionary[0] ) ) ) );
		}*/
/*      case 6: {
			string archive            = ;
			string dictionary[]       = ;
			string expected           = ;

			return verify_case( casenum, expected, HuffmanDecoding().decode( archive, vector <string>( dictionary, dictionary + ( sizeof dictionary / sizeof dictionary[0] ) ) ) );
		}*/
/*      case 7: {
			string archive            = ;
			string dictionary[]       = ;
			string expected           = ;

			return verify_case( casenum, expected, HuffmanDecoding().decode( archive, vector <string>( dictionary, dictionary + ( sizeof dictionary / sizeof dictionary[0] ) ) ) );
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
