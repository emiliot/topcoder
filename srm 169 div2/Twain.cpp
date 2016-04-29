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

string f(string s, int year){
	string res;
	if(year == 1){
		if(s[0] == 'x')res+="z";
		else res += s[0];
		for(int i=1, n=s.size(); i<n; ++i){
			if(s.substr(i-1,2)==" x")res+="z";
			else if(s[i] == 'x')res += "ks";
			else res+=s[i];
		}
	}else if(year == 2){
		for(int i=0, n=s.size(); i<n; ++i){
			if(s[i] == 'y')res+="i";
			else res+=s[i];
		}
	}else if(year == 3){
		for(int i=0, n=s.size()-1; i<n; ++i){
			if(s[i]=='c' && (s[i+1] == 'i' || s[i+1]=='e'))res+="s";
			else res+=s[i];
		}
		res+= s[s.size()-1];
	}else if(year == 4){
		reverse(s.begin(),s.end());
		for(int i=0, n=s.size(); i<n;){
			if(s[i]=='k'){
				res += "k";
				int j;
				for(j=i+1; j<n && s[j]=='c'; ++j);
				i = j;
			}else res+=s[i], ++i;
		}
		reverse(res.begin(),res.end());
	}else if(year == 5){
		for(int i=0, n=s.size(); i<n-1; ++i){
			if(s[i] == 'c' && s[i+1]!='h')s[i]='k';
		}
		if(s[s.size()-1] == 'c')s[s.size()-1] = 'k';

		int i=0, n=s.size();
		if(3 <= n && s.substr(0,3) == "sch")res += "sk", i=3;
		else if(3 <= n && s.substr(0,3)=="chr")res += "kr", i=3;
		else res+=s[0], ++i;
		for(; i<n;){
			if(i+3 < n && s.substr(i-1,4)==" sch") res +="sk",i+=3;
			else if(i+3 < n && s.substr(i,3)=="chr")res += "kr", i+=3;
			else res += s[i], ++i;
		}
	}else if(year == 6){
		int i = 0, n = s.size();
		if(2 <= n && s.substr(0,2) == "kn")res += "n", i=2;
		else res += s[0], i=1;
		for(;i<n;){
			if(i+2 < n && s.substr(i-1,3)==" kn")res +="n", i+=2;
			else res += s[i], ++i;
		}
	}else if(year == 7){
		for(int i=0, n=s.size(); i<n;){
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == ' '){
				res+=s[i];
				++i;
				continue;
			}
			res+=s[i];
			int j;
			for(j=i+1; j<n && s[j] == s[i]; ++j);
			i = j;
		}
	}
	return res;
}

struct Twain {
	string getNewSpelling(int year, string phrase) {
		if(year == 0 || phrase.size()==0)return phrase;
		for(int i=1; i<=year; ++i){
			phrase = f(phrase, i);
		}
		return phrase;
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
			int year                  = 1;
			string phrase             = "i fixed the chrome xerox by the cyclical church";
			string expected           = "i fiksed the chrome zeroks by the cyclical church";

			return verify_case( casenum, expected, Twain().getNewSpelling( year, phrase ) );
		}
		case 1: {
			int year                  = 2;
			string phrase             = "i fixed the chrome xerox by the cyclical church";
			string expected           = "i fiksed the chrome zeroks bi the ciclical church";

			return verify_case( casenum, expected, Twain().getNewSpelling( year, phrase ) );
		}
		case 2: {
			int year                  = 0;
			string phrase             = "this is unchanged";
			string expected           = "this is unchanged";

			return verify_case( casenum, expected, Twain().getNewSpelling( year, phrase ) );
		}
		case 3: {
			int year                  = 7;
			string phrase             = "sch kn x xschrx cknnchc cyck xxceci";
			string expected           = "sk n z zskrks nchk sik zksesi";

			return verify_case( casenum, expected, Twain().getNewSpelling( year, phrase ) );
		}
		case 4: {
			int year                  = 7;
			string phrase             = "  concoction   convalescence   cyclical   cello   ";
			string expected           = "  konkoktion   konvalesense   siklikal   selo   ";

			return verify_case( casenum, expected, Twain().getNewSpelling( year, phrase ) );
		}
		case 5: {
			int year                  = 7;
			string phrase             = "";
			string expected           = "";

			return verify_case( casenum, expected, Twain().getNewSpelling( year, phrase ) );
		}
		case 6: {
			int year                  = 7;
			string phrase             = "cck xzz aaaaa";
			string expected           = "k z aaaaa";

			return verify_case( casenum, expected, Twain().getNewSpelling( year, phrase ) );
		}

		// custom cases

     case 7: {
			int year                  = 7;
			string phrase             = " xx xx xxdxx knndsch sch     schrrhc  yiiyy knnsc ";
			string expected           = " zks zks zksdksks ndsch sk     skrhk  iiiii nsk ";

			return verify_case( casenum, expected, Twain().getNewSpelling( year, phrase ) );
		}
/*      case 8: {
			int year                  = ;
			string phrase             = ;
			string expected           = ;

			return verify_case( casenum, expected, Twain().getNewSpelling( year, phrase ) );
		}*/
/*      case 9: {
			int year                  = ;
			string phrase             = ;
			string expected           = ;

			return verify_case( casenum, expected, Twain().getNewSpelling( year, phrase ) );
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
