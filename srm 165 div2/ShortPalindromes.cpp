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

int memo[60][60];
bool mark[60][60];
int choice[60][60];

const int INF = 0x3f3f3f3f;
enum {TAKE=1, A, B, AB};

int f(const string &s, int i, int j){
	if(i>=j)return 0;
	
	int &best = memo[i][j];
	int &ch = choice[i][j];

	if(mark[i][j])return best;
	mark[i][j] = true;

	best = INF;
	if(s[i] == s[j]){
		best = f(s, i+1, j-1);
		ch = TAKE;
	}else{
		best = f(s,i+1,j)+1;
		int next = f(s,i,j-1)+1;
		if(best < next){
			ch = A;
		}else if(next < best){
			best = next;
			ch = B;
		}else{
			ch = AB;
		}
	}
	return best;
}

string g(string &s, int i, int j){
	if(i == j)return s.substr(i,1);
	if(i > j)return "";

	int &ch = choice[i][j];
	string aux = "";
	if(ch == TAKE){
		aux = g(s,i+1,j-1);
		aux.insert(aux.begin(),s[i]);
		aux += s[j];
	}else if(ch == A){
		aux = g(s,i+1,j) + s[i];
		aux.insert(aux.begin(),s[i]);
	}else if(ch == B){
		aux = g(s,i,j-1) + s[j];
		aux.insert(aux.begin(), s[j]);
	}else{
		if(s[j] < s[i]){
			aux = g(s,i,j-1) + s[j];
			aux.insert(aux.begin(),s[j]);
		}else{
			aux = g(s,i+1,j) + s[i];
			aux.insert(aux.begin(), s[i]);
		}
	}
	return aux;
}

struct ShortPalindromes {
	string shortest(string base) {
		memset(mark,false,sizeof(mark));
		memset(choice, 0, sizeof(choice));
		f(base,0,base.size()-1);
		string x = base;
		return g(x,0,x.size()-1);
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
			string base               = "RACE";
			string expected           = "ECARACE";

			return verify_case( casenum, expected, ShortPalindromes().shortest( base ) );
		}
		case 1: {
			string base               = "TOPCODER";
			string expected           = "REDTOCPCOTDER";

			return verify_case( casenum, expected, ShortPalindromes().shortest( base ) );
		}
		case 2: {
			string base               = "Q";
			string expected           = "Q";

			return verify_case( casenum, expected, ShortPalindromes().shortest( base ) );
		}
		case 3: {
			string base               = "MADAMIMADAM";
			string expected           = "MADAMIMADAM";

			return verify_case( casenum, expected, ShortPalindromes().shortest( base ) );
		}
		case 4: {
			string base               = "ALRCAGOEUAOEURGCOEUOOIGFA";
			string expected           = "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA";

			return verify_case( casenum, expected, ShortPalindromes().shortest( base ) );
		}

		// custom cases

/*      case 5: {
			string base               = ;
			string expected           = ;

			return verify_case( casenum, expected, ShortPalindromes().shortest( base ) );
		}*/
/*      case 6: {
			string base               = ;
			string expected           = ;

			return verify_case( casenum, expected, ShortPalindromes().shortest( base ) );
		}*/
/*      case 7: {
			string base               = ;
			string expected           = ;

			return verify_case( casenum, expected, ShortPalindromes().shortest( base ) );
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
