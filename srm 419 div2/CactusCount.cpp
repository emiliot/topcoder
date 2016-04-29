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

bool mark[205];

bool okEdge(int a1, int b1, int a2, int b2){
	if(b1 == b2){
		return a1 != a2;
	}else return true;
}

bool check(vector < vector <int> > &g, int src, int dest){
	vector <bool> mark2(g.size(), false);
	mark2[src] = true;
	queue < int > q;
	q.push(src);
	while(!q.empty()){
		int w = q.front(); q.pop();
		if(w == dest)
			return true;
		for(int i=0, n=g[w].size(); i<n; ++i){
			int next = g[w][i];
			if(!mark2[next] && okEdge(src, dest, w, g[w][i])){
				mark2[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}

bool f(vector < vector <int> > &g, int start){
	vector <bool> mark2(g.size(), false);
	queue < int > q;
	q.push(start);
	while(!q.empty()){
		int next = q.front(); q.pop();
		mark[next] = mark2[next] = true;
		for(int i=0, n=g[next].size(); i<n; ++i){
			int k = g[next][i];
			if(!mark2[k]){
				q.push(k);
			}
		}
	}
	bool res = true;
	for(int i=0, n=mark2.size(); i<n && res; ++i){
		if(mark2[i] && g[i].size() > 2){
			int count = 0;
			for(int j=0, m=g[i].size(); j<m; ++j){
				if(check(g,i,g[i][j]))
					count++;
			}
			if(count > 2)res = false;
		}
	}
	return res;
}

struct CactusCount {
	int countCacti(int n, vector <string> edges) {
		string s = accumulate(all(edges), string(""));
		for(int i=0, m=s.size(); i<m; ++i){
			if(s[i] == ' ')s[i] = ',';
			else if(s[i] == ',')s[i] = ' ';
		}
		vector < vector <int> > g(n);
		istringstream iss(s);
		int a, b; char c;
		while(iss >> a >> c >> b){
			g[a-1].push_back(b-1);
			g[b-1].push_back(a-1);
		}
		memset(mark,false,sizeof(mark));
		int res = 0;
		for(int i=0; i<n; ++i){
			if(!mark[i]){
				bool ok = f(g, i);
				if(ok)res++;
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
			int n                     = 3;
			string edges[]            = {"1 2,1 3,2 3"};
			int expected              = 1;

			return verify_case( casenum, expected, CactusCount().countCacti( n, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ) ) );
		}
		case 1: {
			int n                     = 10;
			string edges[]            = {"1 1"};
			int expected              = 10;

			return verify_case( casenum, expected, CactusCount().countCacti( n, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ) ) );
		}
		case 2: {
			int n                     = 5;
			string edges[]            = {"1 2,3 4,4 5"};
			int expected              = 2;

			return verify_case( casenum, expected, CactusCount().countCacti( n, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ) ) );
		}
		case 3: {
			int n                     = 17;
			string edges[]            = {"1 2,2 3,3 4,4 5,5 3,1 3,6 7,7 8,6 8,8 9,9 1",  "0,10 11,11 9,12 13,14 15,15 16,16 17,14 17,14 16"};
			int expected              = 2;

			return verify_case( casenum, expected, CactusCount().countCacti( n, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ) ) );
		}

		// custom cases

      case 4: {
			int n                     = 199;
			string edges[]            = {"94 81,28 ", "15,22 100,15 127,18", "2 54,18 175,13 140,31 20,85 81,49 144,1", "75 69,39 19,191 27,199 4", ",180 77,104 7", "7,17 147,198 67,60 122,195 5,1 8,", "152 156,81 164,86 134,191 31,179 63,196 193,164 ", "193,57 29,69 108,89 165,95 149,142 1", "30,188 120,131 101,176 133,189 3,63 176,65 177,10", "4 161,33 72,181 53,101 193,20 168,57 172,13 142,", "91 105,130 158,148 74,121 35,98 77,35 26,184 107", ",3 101,168 47,25 77,36 11,132 27,149 155,1", "22 195,54 13,52 175,73 5,90 79,45 104,171 144,150 ", "27,165 23,195 145,51 173,68 63,147 181,4 180,197 7", "7,137 69,114 121,149 59,133 49,129 34,101 95,89 19", "7,190 195,34 174,57 73,37 99,57 140,181 30,50 21,4", "3 175,165 94,11 55,97 91,92 168,145 132,67 19,42 4", "1,77 117,160 49,197 51,21 181,58 64,82 187,112 32,", "84 13,77 165,115 18,104 163,88 28,108 162,142 129,", "189 127,109 41,161 141,75 151,108 176,183 97,192 6", "8,123 71,70 100,14 33,138 8,186 133,187 194,48 104", ",155 101,172 47,56 1,40 110,165 15,142 107,156 199", ",119 33,80 118,51 101,7 121,59 4,15 48,41 158,128 ", "104,38 50,101 15,110 63,88 156,64 110,41 195,177 1", "12,62 119,129 76,157 54,125 97,80 76,107 46,78 97,", "99 149,135 128,143 133,127 164,165 35,155 169,61 1", "10,162 66,161 114,121 180,141 3,170 49,72 52,139 2", "0,106 162,156 94,159 79,117 59,103 88,83 170,34 12", "4,131 163,27 140,190 132,144 65,151 1,98 89,178 84", ",35 89,37 196,126 7,116 41,54 73,134 62,46 92,173 ", "131,6 120,168 194,161 88,187 21,9 161,193 9,127 99", ",30 147,174 184,190 124,100 134,185 97,113 46,136 ", "34,55 79,70 58,163 26,146 30,152 173,29 122,16 184", ",140 12,172 195,66 61,169 141,19 79,32 67,128 149,", "111 63,75 20,163 81,114 94,3 126,10 194,77 88,173 ", "193,25 126,35 155,71 66,193 169,166 127,2 55,145 1", "90,23 81,182 102,121 189,194 138,148 191,116 75,78", " 170,53 118,125 100,24 88,13 96,12 116,194 50,153 ", "14,26 180,142 34,16 142,154 100,135 165,47 129,96 ", "54,104 131,79 93,30 157,66 97,24 117,178 124,102 1", "7,34 30,124 30,158 146,93 120,46 138,74 57,13 46,1", "05 71,118 142,118 42,8 142,145 13,5 57,120 70,76 1", "68,44 12,21 44,87 118,167 179,59 126,124 54,35 196"};
			int expected              = 0;

			return verify_case( casenum, expected, CactusCount().countCacti( n, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ) ) );
		}
      case 5: {
			int n                     = 7;
			string edges[]            = {"1 2,2 3,3 4,4 5,5 2,2 6,6 7,7 1"};
			int expected              = 0;

			return verify_case( casenum, expected, CactusCount().countCacti( n, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ) ) );
		}
/*      case 6: {
			int n                     = ;
			string edges[]            = ;
			int expected              = ;

			return verify_case( casenum, expected, CactusCount().countCacti( n, vector <string>( edges, edges + ( sizeof edges / sizeof edges[0] ) ) ) );
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
