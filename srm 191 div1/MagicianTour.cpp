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

bool visited[51];
int n;

struct state_t{
	int i;
	bool color;
	state_t(int _i, int _color):
	i(_i), color(_color){};
};

int dfs(vector <string> &roads, vector <int> &v, int start){
	visited[start] = true;
	int res = v[start];
	
	stack < state_t > stck;
	stck.push(state_t(start, false));
	
	while(!stck.empty()){
		state_t st = stck.top(); stck.pop();
		
		for(int k=0; k<n; ++k){
			if(roads[st.i][k] == '1' && (!visited[k])){
				visited[k] = true;
				res += st.color? v[k] : -v[k];
				stck.push(state_t(k, !st.color));
			}
		}
	}
	
	return abs(res);
}

/*bool mark[51];
int memo[51];

int f(vector <int> &v, int i){
	if(i >= (int)v.size()){
		return 0;
	}
	
	int &best = memo[i];
	if(mark[i])return best;
	mark[i] = true;
	
	int a = f(v, i+1) + v[i];
	int b = f(v, i+1) - v[i];
	
	if(abs(a-b) == 0)
	
	return best;
}*/

bool mark[51][1001];
int memo[51][1001];

int f(vector <int> &v, int i, int dif){
	if(i >= (int)v.size()){
		return dif;
	}
	
	int &best = memo[i][dif];
	if(mark[i][dif])return best;
	mark[i][dif] = true;
	
	int a = f(v, i+1, dif + v[i]);
	int b = f(v, i+1, abs(dif - v[i]));
	
	best = min(a, b);
	return best;
}

class MagicianTour {
public:
	int bestDifference( vector <string> roads, vector <int> v ) {
		memset(visited, false, sizeof(visited));
		n = (int)v.size();
		vector <int> diff;
		for(int i=0; i<n; ++i){
			if(!visited[i]){
				diff.push_back(dfs(roads, v, i));
				//printf("DEBUG: %d\n", diff[diff.size()-1]);
			}
		}
		
		memset(mark, false, sizeof(mark));
		int res = f(diff, 0, 0);
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
			string roads[]            = {"01","10"};
			int populations[]         = {15,20};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string roads[]            = {"0100",
 "1000",
 "0001",
 "0010"};
			int populations[]         = {2,4,2,4};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string roads[]            = {"0010",
 "0001",
 "1000",
 "0100"};
			int populations[]         = {2,2,2,2};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string roads[]            = {"000",
 "000",
 "000"};
			int populations[]         = {6,7,15};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string roads[]            = {"0000",
 "0010",
 "0101",
 "0010"};
			int populations[]         = {8,10,15,10};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string roads[]            = {"010",
 "101",
 "010"};
			int populations[]         = {5,1,5};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string roads[]            = {
"01000000000000000000000000000000000",
"10100000000000000000000000000000000",
"01010000000000000000000000000000000",
"00101000000000000000000000000000000",
"00010100000000000000000000000000000",
"00001010000000000000000000000000000",
"00000101000000000000000000000000000",
"00000010100000000000000000000000000",
"00000001010000000000000000000000000",
"00000000101000000000000000000000000",
"00000000010100000000000000000000000",
"00000000001010000000000000000000000",
"00000000000101000000000000000000000",
"00000000000010100000000000000000000",
"00000000000001010000000000000000000",
"00000000000000101000000000000000000",
"00000000000000010100000000000000000",
"00000000000000001010000000000000000",
"00000000000000000100000000000000000",
"00000000000000000000000000000000000",
"00000000000000000000010000000000000",
"00000000000000000000101000000000000",
"00000000000000000000010100000000000",
"00000000000000000000001010000000000",
"00000000000000000000000101000000000",
"00000000000000000000000010100000000",
"00000000000000000000000001010000000",
"00000000000000000000000000101000000",
"00000000000000000000000000010100000",
"00000000000000000000000000001010000",
"00000000000000000000000000000101000",
"00000000000000000000000000000010100",
"00000000000000000000000000000001010",
"00000000000000000000000000000000101",
"00000000000000000000000000000000010"
};
			int populations[]         = {8,15,12,9,12,6,4,6,16,1,15,3,18,15,14,8,6,6,12,13,14,15,17,15,3,8,7,8,3,19,12,9,14,19,9};
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string roads[]            = ;
			int populations[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string roads[]            = ;
			int populations[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string roads[]            = ;
			int populations[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicianTour().bestDifference(vector <string>(roads, roads + (sizeof roads / sizeof roads[0])), vector <int>(populations, populations + (sizeof populations / sizeof populations[0])));
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
