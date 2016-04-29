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

class DocumentSearch {
public:
	int nonIntersecting( vector <string> doc, string search ) {
		string s = doc[0];
		for(int i=1, n=(int)doc.size(); i<n; ++i){
			s += doc[i];
		}

		int res = 0, x;
		while((x = s.find(search))!=-1){
			res++;
			s = s.substr(x + (int)search.size(), s.size() - x - search.size());
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
			string doc[]              = {"ababababa"};
			string search             = "ababa";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string doc[]              = {"ababababa"};
			string search             = "aba";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string doc[]              = {"abcdefghijklmnop",
 "qrstuvwxyz"};
			string search             = "pqrs";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string doc[]              = {"aaa", "aa", "a", "a"};
			string search             = "aa";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			string doc[]              = {"rpjvowjtgmijyuwaq fvswwrdswiplxsbhmlng", "ubeombynlwxa dmfxnm", "hfucfchb aeucfhzkbwefgmzexicueplrycrywmjorbtlrqugk", "pawsgmowizeympgvimitsjzhxkmdigqpnnrleapkqcojieu", "znozinjhaqruwohfthuqb", "okvwixirzzg", "oboenlzwgkqfxgbbfder hrxniudjfatj poxdk", "iy n bgmzzuaklzwfqxuolcfaqvs vfrxf", "occcebxdijglkjsz", " cewpwlxkxcqygmmutkwoxprjdzebkhegocfbpu", "rtydoxemnjxdmwjf", "ogwisegwfqamubufukxtboswljrxsudrwccemxdinnzwgqws", "innrygiircuibqaliorqrzfwpq"};
			string search             = "q";
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			string doc[]              = ;
			string search             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string doc[]              = ;
			string search             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DocumentSearch().nonIntersecting(vector <string>(doc, doc + (sizeof doc / sizeof doc[0])), search);
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
