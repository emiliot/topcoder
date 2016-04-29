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

bool mark[31][2][1 << 10];
bool memo[31][2][1 << 10];
int choice[31][2][1 << 10];

bool f(const string &s, int k, int i, int greater, int mask){
	int bn = 0;
	for(int w=0; w<10; ++w){
		if(mask & (1 << w))++bn;
	}
	
	if(bn > k)return false; //too much different digits
	if(i >= (int)(s.size()))return bn == k; //there is no place for more digits check if it is solution
	
	bool &ok = memo[i][greater][mask];
	int &ch = choice[i][greater][mask];
	if(mark[i][greater][mask])return ok;
	mark[i][greater][mask] = true;
	
	ok = false;
	ch = -1;
	
	//try modifying digit i with value d
	for(int d=0; d<10 && !ok; ++d){
		//avoid leading zeroes
		if(i==0 && d == 0)continue;
		
		//avoid lower numbers than the number given
		if(!greater && d < s[i] - '0')continue;
		
		//check if the next number is greater
		int ngreater = greater || d > s[i] - '0'? 1 : 0;
		ok = f(s, k, i+1, ngreater, mask | (1 << d));
		if(ok)ch = d;
	}
	
	return ok;
}

string g(string &s){
	string res(s.size(), ' ');
	int mask = 0, greater = 0;
	for(int i=0, n=(int)s.size(); i<n; ++i){
		int &ch = choice[i][greater][mask];
		res[i] = '0' + ch;
		mask = mask | (1 << ch);
		if(!greater && ch > s[i] - '0')greater = 1;
	}
	return res;
}


class TheInteger {
public:
	long long find( long long n, int k ) {
		char buffer[30];
		sprintf(buffer, "%lld", n);
		const string s(buffer);
		i64 res = 0LL;
		
		for(int i=s.size(); i<30; ++i){
			memset(mark, false, sizeof(mark));
			string next = string(i - s.size(), '0') + s;
			bool ok = f(next, k, 0, 0, 0);
			if(ok){
				istringstream iss(g(next));
				iss >> res;
				return res;
			}
		}
		
		//this shouldnt be happenning
		return -1;
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
			long long n               = 47;
			int k                     = 1;
			long long expected__      = 55;

			clock_t start__           = clock();
			long long received__      = TheInteger().find(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long n               = 7;
			int k                     = 3;
			long long expected__      = 102;

			clock_t start__           = clock();
			long long received__      = TheInteger().find(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long n               = 69;
			int k                     = 2;
			long long expected__      = 69;

			clock_t start__           = clock();
			long long received__      = TheInteger().find(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long n               = 12364;
			int k                     = 3;
			long long expected__      = 12411;

			clock_t start__           = clock();
			long long received__      = TheInteger().find(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			long long n               = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheInteger().find(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			long long n               = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheInteger().find(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long n               = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TheInteger().find(n, k);
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
