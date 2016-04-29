// Paste me into the FileEdit configuration dialog

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "algorithm"
#include "bitset"
#include "vector"
#include "string"
#include "sstream"
#include "iostream"
using namespace std;

#define all(v) (v).begin(), (v).end()
typedef long long i64;
template <class T> void make_unique(T& v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}

bool func(const string &a, const string &b){
	if(a.size() < b.size())return true;
	else if(b.size() < a.size())return false;
	else{
		int x = 0, y = 0;
		for(int i=0, n=(int)a.size(); i<n; ++i){
			if(a[i] >= '0' && a[i] <= '9')x += a[i] - '0';
		}

		for(int i=0, n=(int)b.size(); i<n; ++i){
			if(b[i] >= '0' && b[i] <= '9')y += b[i] - '0';
		}

		//printf("DEBUG: %s %s %d %d\n", a.c_str(), b.c_str(), x, y);

		if(x < y)return true;
		else if(y < x)return false;
		else return a < b;
	}
}

class SerialNumbers {
public:
	vector <string> sortSerials( vector <string> serialNumbers ) {
		sort(all(serialNumbers), func);
		return serialNumbers;
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string serialNumbers[]    = {"ABCD","145C","A","A910","Z321"};
			string expected__[]       = {"A", "ABCD", "Z321", "145C", "A910" };

			clock_t start__           = clock();
			vector <string> received__ = SerialNumbers().sortSerials(vector <string>(serialNumbers, serialNumbers + (sizeof serialNumbers / sizeof serialNumbers[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string serialNumbers[]    = {"Z19", "Z20"};
			string expected__[]       = {"Z20", "Z19" };

			clock_t start__           = clock();
			vector <string> received__ = SerialNumbers().sortSerials(vector <string>(serialNumbers, serialNumbers + (sizeof serialNumbers / sizeof serialNumbers[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string serialNumbers[]    = {"34H2BJS6N","PIM12MD7RCOLWW09","PYF1J14TF","FIPJOTEA5"};
			string expected__[]       = {"FIPJOTEA5", "PYF1J14TF", "34H2BJS6N", "PIM12MD7RCOLWW09" };

			clock_t start__           = clock();
			vector <string> received__ = SerialNumbers().sortSerials(vector <string>(serialNumbers, serialNumbers + (sizeof serialNumbers / sizeof serialNumbers[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string serialNumbers[]    = {"ABCDE", "BCDEF", "ABCDA", "BAAAA", "ACAAA"};
			string expected__[]       = {"ABCDA", "ABCDE", "ACAAA", "BAAAA", "BCDEF" };

			clock_t start__           = clock();
			vector <string> received__ = SerialNumbers().sortSerials(vector <string>(serialNumbers, serialNumbers + (sizeof serialNumbers / sizeof serialNumbers[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string serialNumbers[]    = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SerialNumbers().sortSerials(vector <string>(serialNumbers, serialNumbers + (sizeof serialNumbers / sizeof serialNumbers[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string serialNumbers[]    = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SerialNumbers().sortSerials(vector <string>(serialNumbers, serialNumbers + (sizeof serialNumbers / sizeof serialNumbers[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string serialNumbers[]    = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SerialNumbers().sortSerials(vector <string>(serialNumbers, serialNumbers + (sizeof serialNumbers / sizeof serialNumbers[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
