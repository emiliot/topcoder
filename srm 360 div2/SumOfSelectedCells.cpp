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

class SumOfSelectedCells {
public:
	string hypothesis( vector <string> table ) {
		vector < vector < int > >t(table.size());

		for(int i=0, n=(int)table.size(); i<n; ++i){
			istringstream iss(table[i]);
			int k;
			while(iss >> k){
				t[i].push_back(k);
			}
		}

		bool res = true;
		int n = (int)t.size(), m=(int)t[0].size();

		if(t.size() > t[0].size()){
			for(int i=0; i<n-1 && res; ++i){
				res = res && table[i] == table[i+1];
			}
		}else if(t.size() < t[0].size()){
			for(int i=0; i<n && res; ++i){
				for(int j=0; j<m-1 && res; ++j){
					res = res && t[i][j] == t[i][j+1];
				}
			}
		}else{
			for(int i=1; i<n && res; ++i){
				for(int j=1; j<m && res; ++j){
					res = res && (t[0][0] + t[i][j] == t[0][j] + t[i][0]);
				}
			}
		}

		if(res)return "CORRECT";
		else return "INCORRECT";
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
			string table[]            = {"5 6 6"};
			string expected__         = "INCORRECT";

			clock_t start__           = clock();
			string received__         = SumOfSelectedCells().hypothesis(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string table[]            = {"11 12 13 14",
 "21 22 23 24",
 "31 32 33 34",
 "41 42 43 44"};
			string expected__         = "CORRECT";

			clock_t start__           = clock();
			string received__         = SumOfSelectedCells().hypothesis(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string table[]            = {"3 7",
 "3 7",
 "3 7"};
			string expected__         = "CORRECT";

			clock_t start__           = clock();
			string received__         = SumOfSelectedCells().hypothesis(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string table[]            = {"1 2 3",
 "4 5 6",
 "9 8 7"};
			string expected__         = "INCORRECT";

			clock_t start__           = clock();
			string received__         = SumOfSelectedCells().hypothesis(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string table[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SumOfSelectedCells().hypothesis(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string table[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SumOfSelectedCells().hypothesis(vector <string>(table, table + (sizeof table / sizeof table[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string table[]            = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = SumOfSelectedCells().hypothesis(vector <string>(table, table + (sizeof table / sizeof table[0])));
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
