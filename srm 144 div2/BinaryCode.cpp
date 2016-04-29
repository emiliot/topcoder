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

string f(string &q, int p0){
	const int n = q.size();
	string p = q;
	p[0] = p0 + '0';
	int pn = (q[0]-'0') - (p[0]-'0');
	if(pn < 0 || pn > 1)return "NONE";
	p[1] = pn + '0';

	for(int i=1; i<n-1; ++i){
		pn = (q[i]-'0') - (p[i-1]-'0') - (p[i]-'0');
		if(pn < 0 || pn > 1)return "NONE";
		p[i+1] = pn + '0';
	}

	pn = (q[n-1]-'0') - (p[n-1]-'0') - (p[n-2]-'0');
	if(pn != 0)return "NONE";
	return p;
}

struct BinaryCode {
	vector <string> decode(string message) {
		vector <string> res(2, "");
		if(message.size() == 1)res[0] = message[0] == '0' ? message : "NONE";
		else res[0] = f(message, 0);
		if(message.size() == 1) res[1] = message[0] == '1' ? message : "NONE";
		else res[1] = f(message, 1);
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
			string message            = "123210122";
			string expected[]         = { "011100011",  "NONE" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BinaryCode().decode( message ) );
		}
		case 1: {
			string message            = "11";
			string expected[]         = { "01",  "10" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BinaryCode().decode( message ) );
		}
		case 2: {
			string message            = "22111";
			string expected[]         = { "NONE",  "11001" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BinaryCode().decode( message ) );
		}
		case 3: {
			string message            = "123210120";
			string expected[]         = { "NONE",  "NONE" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BinaryCode().decode( message ) );
		}
		case 4: {
			string message            = "3";
			string expected[]         = { "NONE",  "NONE" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BinaryCode().decode( message ) );
		}
		case 5: {
			string message            = "12221112222221112221111111112221111";
			string expected[]         = { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" };

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BinaryCode().decode( message ) );
		}

		// custom cases

      case 6: {
			string message            = "1";
			string expected[]         = {"NONE", "1"};

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BinaryCode().decode( message ) );
		}
/*      case 7: {
			string message            = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BinaryCode().decode( message ) );
		}*/
/*      case 8: {
			string message            = ;
			string expected[]         = ;

			return verify_case( casenum, vector <string>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BinaryCode().decode( message ) );
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
