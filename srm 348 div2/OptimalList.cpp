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

class OptimalList {
public:
	string optimize( string inst ) {
		int di = 0, dj= 0;
		for(int i=0, n=(int)inst.size(); i<n; ++i){
			if(inst[i] == 'N')di++;
			else if(inst[i] == 'S')di--;
			else if(inst[i] == 'E')dj++;
			else dj--;
		}
		
		string res = "";
		while(dj > 0)res+='E', dj--;
		while(di > 0)res+='N', di--;
		while(di < 0)res+='S', di++;
		while(dj < 0)res+='W', dj++;
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string inst               = "NENENNWWWWWS";
			string expected__         = "NNNWWW";

			clock_t start__           = clock();
			string received__         = OptimalList().optimize(inst);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string inst               = "NNEESSWW";
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = OptimalList().optimize(inst);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string inst               = "NEWSNWESWESSEWSENSEWSEWESEWWEWEEWESSSWWWWWW";
			string expected__         = "SSSSSSSSWWW";

			clock_t start__           = clock();
			string received__         = OptimalList().optimize(inst);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string inst               = "NENENE";
			string expected__         = "EEENNN";

			clock_t start__           = clock();
			string received__         = OptimalList().optimize(inst);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string inst               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = OptimalList().optimize(inst);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string inst               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = OptimalList().optimize(inst);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string inst               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = OptimalList().optimize(inst);
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
