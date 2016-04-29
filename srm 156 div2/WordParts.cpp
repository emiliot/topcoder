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

bool mark[60][60];
int memo[60][60];
set < string > table;
const int INF = 0x3f3f3f3f;

int f(string &s, int i, int n){
	//if(i == 5 && n == 10)printf("DEBUG: Enter  %d %d\n", i, n);
	
	if(n <= 0){
		return 0;
	}
	if(i >= (int)s.size()){
		return 0;
	}
	if(table.find(s.substr(i, n)) != table.end()){
		return 1;
	}
	
	int &best = memo[i][n];
	if(mark[i][n])return best;
	mark[i][n] = true;
	
	best = INF;
	
	for(int k = 1; k<=n; ++k){
		if(table.find(s.substr(i, k)) != table.end()){
			//match for left then call for right
			int next = f(s, i+k, n-k);
			if(next > -1){
				//if exists a valid way to calculate the right
				best = min(best, next + 1);
			}
		}
	}
	
	if(best >= INF)best = -1;
	return best;
}

class WordParts {
public:
	int partCount( string original, string compound ) {
		table.clear();
		for(int i=1, n=original.size(); i<=n; ++i){
			table.insert(original.substr(0, i));
			table.insert(original.substr(n-i, i));
		}
		
		memset(mark, false, sizeof(mark));
		int res = f(compound, 0, (int)compound.size());
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
			string original           = "ANTIDISESTABLISHMENTARIANISM";
			string compound           = "ANTIDISIANISMISM";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = WordParts().partCount(original, compound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string original           = "ANTIDISESTABLISHMENTARIANISM";
			string compound           = "ESTABLISHMENT";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = WordParts().partCount(original, compound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string original           = "TOPCODERDOTCOM";
			string compound           = "TOMTMODERDOTCOM";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = WordParts().partCount(original, compound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string original           = "HELLO";
			string compound           = "HELLOHEHELLOLOHELLO";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = WordParts().partCount(original, compound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string original           = "DONTFORGETTHEEMPTYCASE";
			string compound           = "";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = WordParts().partCount(original, compound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string original           = "BAAABA";
			string compound           = "BAAABAAA";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = WordParts().partCount(original, compound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string original           = "ABBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABB";
			string compound           = "BBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABAA";
			int expected__            = 17;

			clock_t start__           = clock();
			int received__            = WordParts().partCount(original, compound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string original           = ;
			string compound           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WordParts().partCount(original, compound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string original           = ;
			string compound           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WordParts().partCount(original, compound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string original           = ;
			string compound           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WordParts().partCount(original, compound);
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
