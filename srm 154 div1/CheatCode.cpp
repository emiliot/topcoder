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
bool memo[60][60];
bool mark[60][60];

bool match(string &s, string &code, int i, int j){
	if(j >= (int) code.size())return true;
	if(i >= (int) s.size())return false;

	bool &res = memo[i][j];
	if(mark[i][j])return res;
	mark[i][j] = true;

	res = match(s, code, i+1, 0);
	for(int k=0, n=(int)s.size(); k+i<n && s[i+k] == code[j]; ++k){
		res = res || match(s, code, i+k+1, j+1);
	}
	return res;
}

struct CheatCode {
	vector <int> matches(string keyPresses, vector <string> codes) {
		vector <int> res;
		for(int i=0, n=(int)codes.size(); i<n; ++i){
			memset(mark, false, sizeof(mark));
			if(match(keyPresses, codes[i], 0, 0))res.push_back(i);
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
			string keyPresses         = "UUDDLRRLLRBASS";
			string codes[]            = {"UUDDLRLRBA","UUDUDLRLRABABSS","DDUURLRLAB","UUDDLRLRBASS","UDLRRLLRBASS"};
			int expected[]            = { 0,  3,  4 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CheatCode().matches( keyPresses, vector <string>( codes, codes + ( sizeof codes / sizeof codes[0] ) ) ) );
		}
		case 1: {
			string keyPresses         = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
			string codes[]            = {"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"};
			int expected[]            = { 0 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CheatCode().matches( keyPresses, vector <string>( codes, codes + ( sizeof codes / sizeof codes[0] ) ) ) );
		}
		case 2: {
			string keyPresses         = "IDDQDDTSFHHALL";
			string codes[]            = {"FHHALL", "FHSHH", "IDBEHOLDA", "IDBEHOLDI", "IDBEHOLDL",  "IDBEHOLDR", "IDBEHOLDS", "IDBEHOLDV", "IDCHOPPERS", "IDCLEV",  "IDCLIP", "IDDQD", "IDDT", "IDFA", "IDKFA", "IDMYPOS", "IDMUS"};
			int expected[]            = { 0,  11 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CheatCode().matches( keyPresses, vector <string>( codes, codes + ( sizeof codes / sizeof codes[0] ) ) ) );
		}
		case 3: {
			string keyPresses         = "AABBCCDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYY";
			string codes[]            = {"ABCDE", "BCDEF", "CDEFG", "DEFGH", "EFGHI",  "FGHIJ", "GHIJK", "HIJKL", "IJKLM", "JKLMN",  "KLMNO", "LMNOP", "MNOPQ", "NOPQR", "OPQRS",  "PQRST", "QRSTU", "RSTUV", "STUVW", "TUVWX",  "UVWXY", "VWXYZ", "WXYZA", "XYZAB", "YZABC",  "ZABCD"};
			int expected[]            = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CheatCode().matches( keyPresses, vector <string>( codes, codes + ( sizeof codes / sizeof codes[0] ) ) ) );
		}
		case 4: {
			string keyPresses         = "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ";
			string codes[]            = {"LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSS", "LAKJDGSJKGLSDKHFKDFHDGHSDKKSJDHFHJGKDKLSLSLJKAHSJ",  "LAKJDGSJKGLSDKHFKDFHDHHSDKKSJDHFHJGKDKLSLSLJKASSJ",  "AKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",  "LAJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKHHSJ",  "LAKDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",  "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDFHJGKDKLSLSLJKAHS",   "KJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",  "LAKJDGSJKGLSDKHFKDFHDHHSDKKSJDHFHJGKDKLLSLJKAHS",    "LAKGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",  "LAKJDGJKGLSDKHFKDFHDGHHDKKSJDHFHJGKDKLSLSLJKAHS",    "LAKJDGJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHSJ",  "LAKJDGSJKGLSDKHFKDFHGHHSDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSL",  "LAKJDGSJKGLSDKHFDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLJKAHSJ",  "LAKJDGSJKGLSDHFKDFHDGHHSDKKSJDHFHJGKDKLSLSJKAHS",    "KGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSL",  "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJHFHJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDSLSLJKAHSJ",  "LAKJDGSJKGLSDKHFKDFHDGHHSDKSJHFHJGKDKLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKKLSLSLJKAHSJ",  "LAKJDGSJKGLSDKHFKFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGDKLSLSLJKAHSJ",  "LAKJDGSJKGLSDKHFKDFHDGHHSDKSJHFHJGKDKLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJKDKLSLSLJKAHSJ",  "LKJDGSJKGLSDKHFKDFHDGHHSDKKJDHFHJGKDKLSLSLJKAHS",    "AKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDKLSLSLJKAHS",  "LAJDGSJKGLSDKHFKDFHDGHHSDKKSJDFHJGKDKLSLSLKAHS",     "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFGKDKLSLSLJKAHSJ",  "LKJDGSJKLSDKHFKDFHDGHHSDKSJDHFHJGKDKLSLSLJKAHS",     "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHHJGKDKLSLSLJKAHSJ",  "AKJDGSJKGLSDKFKDFHDGHHSSJDHFJGKDKLSLSLJKAHS",        "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDFHJGKDKLSLSLJKAHSJ",  "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJDHFJGKDKLSLSLJKAHS",   "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSJHFHJGKDKLSLSLJKAHSJ",  "LAKJDSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSDKKSDHFHJGKDKLSLSLJKAHSJ",  "LAKJDSJKGLSDKHFKDFHDGHHSDKKSJDHFHJGKDLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSDKKJDHFHJGKDKLSLSLJKAHSJ",  "LAKJDGSJKGLSDKHFKDFHDHHSDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKDGSJKGLSDKHFKDFHDGHHSDKSJDHFHJGKDKLSLSLJKAHSJ",  "LAKJDGSJKGLSDKHFKDFHDGHHSDKSJDHFHJGKDKLSLSLJKAS",    "KJDGSJKGLSDKHFKDFHDGHSDKKSJDHFHJGKDKLSLSLJKAH",  "LAKJDGSJKGLSDKHFKDFHDGHHDKKSJDHFHJGKDKLSLSLJKAHS",   "LAKDGSJKGLSDKFHDGHHSDKSJDHFHJGKDKLSLSLJKAHSJ",  "LAKJDGSJKGLSKHFKDFHDHHSDKKSJDHFHJGKDKLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHSKKSJDHFHJGKDKLSLSLJKAHSJ",  "LAKJDGSJGLSDKHFKDFHDGHHSDKKSJDFHJGKDKLSLSLJKAHS",    "LAKJDGSJKGLSDKHFKDFHDGHHDKKSJDHFHJGKDKLSLSLJKAHSJ"} ;
			int expected[]            = { 1,  3,  7,  13,  17,  27,  43 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CheatCode().matches( keyPresses, vector <string>( codes, codes + ( sizeof codes / sizeof codes[0] ) ) ) );
		}

		// custom cases

/*      case 5: {
			string keyPresses         = ;
			string codes[]            = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CheatCode().matches( keyPresses, vector <string>( codes, codes + ( sizeof codes / sizeof codes[0] ) ) ) );
		}*/
/*      case 6: {
			string keyPresses         = ;
			string codes[]            = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CheatCode().matches( keyPresses, vector <string>( codes, codes + ( sizeof codes / sizeof codes[0] ) ) ) );
		}*/
/*      case 7: {
			string keyPresses         = ;
			string codes[]            = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), CheatCode().matches( keyPresses, vector <string>( codes, codes + ( sizeof codes / sizeof codes[0] ) ) ) );
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
