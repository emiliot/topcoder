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

int arr[] = {10,11,12,13,14,15,16,17,18,19};

int to10(string s, int base){
	int res = 0;
	for(int i=0, n=s.size(); i<n; ++i){
		if(s[i] >= 'A' && s[i]<='Z'){
			(res*=base)+=arr[s[i]-'A'];
		}else (res*=base)+=s[i]-'0';
	}
	return res;
}

bool ok(string eq, int base){
	string op1="", op2="", res="";
	int k=0, n = eq.size();
	for(;k<n && eq[k]!='+';++k){
		op1+=eq[k];
		if(eq[k]>='A' && eq[k]<='Z'){
			if(arr[eq[k]-'A']>=base)return false;
		}else if(eq[k]-'0'>=base)return false;
	}
	for(k=k+1; k<n && eq[k]!='=';++k){
		op2+=eq[k];
		if(eq[k]>='A' && eq[k]<='Z'){
			if(arr[eq[k]-'A']>=base)return false;
		}else if(eq[k]-'0'>=base)return false;
	}
	for(k=k+1; k<n; ++k){
		res+=eq[k];
		if(eq[k]>='A' && eq[k]<='Z'){
			if(arr[eq[k]-'A']>=base)return false;
		}else if(eq[k]-'0'>=base)return false;
	}
	int a = to10(op1,base), b=to10(op2,base),c=to10(res,base);
	return (a+b == c);
}

struct BaseMystery {
	vector <int> getBase(string equation) {
		vector<int> v;
		for(int i=2; i<=20; ++i){
			if(ok(equation,i))v.push_back(i);
		}
		return v;
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
			string equation           = "1+1=2";
			int expected[]            = { 3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BaseMystery().getBase( equation ) );
		}
		case 1: {
			string equation           = "1+1=10";
			int expected[]            = { 2 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BaseMystery().getBase( equation ) );
		}
		case 2: {
			string equation           = "1+1=3";
			int expected[]            = { -1};

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BaseMystery().getBase( equation ) );
		}
		case 3: {
			string equation           = "ABCD+211=B000";
			int expected[]            = { 14 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BaseMystery().getBase( equation ) );
		}
		case 4: {
			string equation           = "ABCD+322=B000";
			int expected[]            = { 15 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BaseMystery().getBase( equation ) );
		}
		case 5: {
			string equation           = "1+0=1";
			int expected[]            = { 2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BaseMystery().getBase( equation ) );
		}
		case 6: {
			string equation           = "GHIJ+1111=HJ00";
			int expected[]            = { 20 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BaseMystery().getBase( equation ) );
		}
		case 7: {
			string equation           = "1234+8765=9999";
			int expected[]            = { 10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BaseMystery().getBase( equation ) );
		}

		// custom cases

/*      case 8: {
			string equation           = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BaseMystery().getBase( equation ) );
		}*/
/*      case 9: {
			string equation           = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BaseMystery().getBase( equation ) );
		}*/
/*      case 10: {
			string equation           = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), BaseMystery().getBase( equation ) );
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
