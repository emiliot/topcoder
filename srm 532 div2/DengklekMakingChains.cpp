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


bool isDigit(char x){
	return x >= '0' && x <= '9';
}

int f(string &s){
	if(isDigit(s[0]) && isDigit(s[1]) && isDigit(s[2]))return 0;
	else if(isDigit(s[0]) && isDigit(s[2]))return 3;
	else if(isDigit(s[0]))return 2;
	else if(isDigit(s[2]))return 1;
	return -1;
}

int g(string &s, int type){
	int res = 0;
	if(type == 0)for(int i=0; i<3; ++i)res+= (s[i]-'0');
	else if(type == 1)for(int i=2; i>=0; --i){
		if(s[i] == '.')break;
		res += (s[i]-'0');
	}else if(type == 2)for(int i=0; i<3; ++i){
		if(s[i] == '.')break;
		res += (s[i]-'0');
	}else if(type == -1 && s[1] != '.'){
		res = (s[1]-'0');
	}
	return res;
}

struct DengklekMakingChains {
	int maxBeauty(vector <string> v) {
		int res = 0, pr = 0, prV = 0, suf = 0, sufV = 0, next, alone = 0;
		for(int i=0, n=v.size(); i<n; ++i){
			int type = f(v[i]);
			if(type == -1){
				alone = max(alone, g(v[i], type));
				continue;
			}
			
			if(type == 0)res += g(v[i], type);
			else if(type == 1){
				next = g(v[i], type);
				if(suf == -1)sufV = next, suf = i;
				else if(next > sufV)sufV = next, suf = i;
			}else if(type == 2){
				next = g(v[i], type);
				if(pr == -1)prV = next, pr = i;
				else if(next > prV)prV = next, pr = i;
			}else if(type == 3){
				next = g(v[i], 1);
				if(suf == -1)sufV = next, suf = i;
				else if(next > sufV)sufV = next, suf = i;

				next = g(v[i],2);
				if(pr == -1)prV = next, pr = i;
				else if(next > prV)prV = next, pr = i;
			}
		}
		if(pr != suf)res += prV + sufV;
		else{
			int aux = -1, auxV = 0, best;
			for(int i=0, n=v.size(); i<n; ++i){
				int type = f(v[i]);
				if(i == pr || type == -1 || type == 0 || type == 2)continue;
				if(type == 1){
					next = g(v[i], type);
					if(aux == -1)auxV = next, aux = i;
					else if(next > auxV)auxV = next, aux = i;
				}else if(type == 3){
					next = g(v[i], 1);
					if(aux == -1)auxV = next, aux = i;
					else if(next > auxV)auxV = next, aux = i;
				}
			}
			best = auxV + prV;
			auxV = 0, aux=-1;
			for(int i=0, n=v.size(); i<n; ++i){
				int type = f(v[i]);
				if(i == suf || type == -1 || type == 0 || type == 1)continue;
				if(type == 2){
					next = g(v[i], type);
					if(aux == -1)auxV = next, aux = i;
					else if(next > auxV)auxV = next, aux = i;
				}else if(type == 3){
					next = g(v[i], 2);
					if(aux == -1)auxV = next, aux = i;
					else if(next > auxV)auxV = next, aux = i;
				}
			}

			best = max(best, auxV + sufV);
			res += best;
		}

		return max(res, alone);
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
	
	int verify_case( int casenum, const int &expected, const int &received ) { 
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
			string chains[]           = {".15", "7..", "402", "..3"};
			int expected              = 19;

			return verify_case( casenum, expected, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) ) );
		}
		case 1: {
			string chains[]           = {"..1", "7..", "567", "24.", "8..", "234"};
			int expected              = 36;

			return verify_case( casenum, expected, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) ) );
		}
		case 2: {
			string chains[]           = {"...", "..."};
			int expected              = 0;

			return verify_case( casenum, expected, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) ) );
		}
		case 3: {
			string chains[]           = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"};
			int expected              = 28;

			return verify_case( casenum, expected, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) ) );
		}
		case 4: {
			string chains[]           = {"..1", "3..", "2..", ".7."};
			int expected              = 7;

			return verify_case( casenum, expected, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) ) );
		}
		case 5: {
			string chains[]           = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"};
			int expected              = 58;

			return verify_case( casenum, expected, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) ) );
		}

		// custom cases

      case 6: {
			string chains[]           = {"4.5", "3.4"};
			int expected              = 8;

			return verify_case( casenum, expected, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) ) );
		}
/*      case 7: {
			string chains[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) ) );
		}*/
/*      case 8: {
			string chains[]           = ;
			int expected              = ;

			return verify_case( casenum, expected, DengklekMakingChains().maxBeauty( vector <string>( chains, chains + ( sizeof chains / sizeof chains[0] ) ) ) );
		}*/
		default:
			return -1;
		}
	}
}

int main() {
  moj_harness::run_test(6);
} 
// END CUT HERE
