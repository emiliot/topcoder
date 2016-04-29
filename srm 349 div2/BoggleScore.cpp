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

const i64 mod = 10000000000000LL;
i64 fastP(i64 a, i64 b){
	if(b <= 0)return 1LL;
	else if(b == 1LL)return a % mod;
	else if(b % 2LL == 0){
		i64 aux = fastP(a, b/2);
		return ((aux % mod) * (aux % mod))%mod;
	}else{
		i64 aux = fastP(a, b-1);
		return ((aux % mod) * (a % mod)) % mod;
	}
}

i64 memo[60][5][5];
bool mark[60][5][5];

int movi[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int movj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

i64 f(vector <string> &grid, string &word, int k, int i, int j){
	if(k >= (int)word.size())return 1LL;

	i64 &count = memo[k][i][j];
	if(mark[k][i][j])return count;
	mark[k][i][j] = true;

	count = 0LL;
	for(int w=0; w<8; ++w){
		int ni = movi[w] + i, nj = movj[w] + j;
		if(ni >= 0 && ni < 4 && nj >= 0 && nj < 4 && grid[ni][nj] == word[k]){
			i64 next = f(grid, word, k+1, ni, nj) % mod;
			count = (count % mod) + (next % mod) % mod;
		}
	}
	return count;
}

class BoggleScore {
public:
	long long bestScore( vector <string> grid, vector <string> words ) {
		i64 res = 0LL;
		for(int i=0, n=(int)words.size(); i<n; ++i){
			memset(mark, false, sizeof(mark));
			for(int k=0; k<16; ++k){
				int ni = k/4, nj = k%4;
				if(grid[ni][nj] == words[i][0]){ 
					i64 value = fastP((i64)words[i].size(), 2);
					i64 next = f(grid, words[i], 1, k/4, k%4) %mod;
					res = ((res % mod) + ((next % mod) * (value % mod)%mod))%mod;
				}
			}
		}
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			string grid[]             = {"XXEY",
 "XXXX",
 "XXXX",
 "XXXX"};
			string words[]            = {"EYE"};
			long long expected__      = 9;

			clock_t start__           = clock();
			long long received__      = BoggleScore().bestScore(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string grid[]             = {"XEYE",
 "XXXX",
 "XXXX",
 "XXXX"};
			string words[]            = {"EYE"};
			long long expected__      = 36;

			clock_t start__           = clock();
			long long received__      = BoggleScore().bestScore(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string grid[]             = {"TEXX",
 "REXX",
 "XXXX",
 "XXXX"};
			string words[]            = {"TREE"};
			long long expected__      = 32;

			clock_t start__           = clock();
			long long received__      = BoggleScore().bestScore(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string grid[]             = {"XXXX",
 "XSAX",
 "XDNX",
 "XXXX"};
			string words[]            = {"SANDS", "SAND", "SAD", "AND"};
			long long expected__      = 59;

			clock_t start__           = clock();
			long long received__      = BoggleScore().bestScore(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string grid[]             = {"TREX",
 "XXXX",
 "XXXX",
 "XXXX"};
			string words[]            = {"TREE"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = BoggleScore().bestScore(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string grid[]             = ;
			string words[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = BoggleScore().bestScore(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string grid[]             = ;
			string words[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = BoggleScore().bestScore(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string grid[]             = ;
			string words[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = BoggleScore().bestScore(vector <string>(grid, grid + (sizeof grid / sizeof grid[0])), vector <string>(words, words + (sizeof words / sizeof words[0])));
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
