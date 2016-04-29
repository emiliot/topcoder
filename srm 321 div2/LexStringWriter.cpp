// Paste me into the FileEdit configuration dialog

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

vector <int> table[26];
bool mark[60][27];
int memo[60][27];

int f(int last, int k){
	if(k >= 26)return 0;
	
	int &best = memo[last][k];
	if(mark[last][k])return best;
	mark[last][k] = true;
	
	//no letters 'a'+k
	if(table[k].size() <= 0)best = f(last, k+1);
	else{
		//try to leave last the leftmost
		int ncost = 0, l = last;
		for(int i=(int)table[k].size()-1; i>=0; --i){
			ncost += abs(l - table[k][i]);
			l = table[k][i];
		}
		best = f(l, k+1) + ncost + table[k].size();
		
		//try to leave last the rightmost
		ncost = 0, l = last;
		for(int i=0, n=(int)table[k].size(); i<n; ++i){
			ncost += abs(l - table[k][i]);
			l = table[k][i];
		}
		best = min(best, f(l, k+1) + ncost + (int)table[k].size());
		
	}
	return best; 
}


class LexStringWriter {
public:
	int minMoves( string s ) {
		for(int j=0; j<26; ++j)table[j].clear();
		for(int i=0, n=s.size(); i<n; ++i){
			table[s[i] - 'a'].push_back(i);
		}
		
		memset(mark, false, sizeof(mark));
		int res = f(0, 0);
		return res;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string s                  = "aaa";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = LexStringWriter().minMoves(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "ba";
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = LexStringWriter().minMoves(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "abba";
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = LexStringWriter().minMoves(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "acbbc";
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = LexStringWriter().minMoves(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string s                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LexStringWriter().minMoves(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string s                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LexStringWriter().minMoves(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string s                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LexStringWriter().minMoves(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
