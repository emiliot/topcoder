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

struct gSetInfo{
	int songs, guitarCount;
	vector <string> gNames;

	bool operator <(const gSetInfo &x)const{
		if(songs > x.songs)return true;
		else if(songs < x.songs)return false;
		else if(guitarCount < x.guitarCount)return true;
		else if(guitarCount > x.guitarCount)return false;
		else {
			/*for(int i=0, m=(int)gNames.size(); i<m; ++i){
				if(gNames[i] < x.gNames[i])return true;
				else if(gNames[i] > x.gNames[i])return false;
			}

			//this shouldnt be happening
			return false;*/

			return gNames < x.gNames;
		}
	}
};

class GuitarConcert {
public:
	vector <string> buyGuitars( vector <string> guitarNames, vector <string> guitarSongs ) {
		vector <gSetInfo > v((1 << guitarSongs.size()) + 1);
		const int n = (int) guitarSongs.size();

		//for every subset of guitars
		for(int k=0; k < (1 << n); ++k){
			i64 nMask = 0LL;
			v[k].guitarCount = 0, v[k].songs = 0;

			//find which songs this set can play and it's cost
			for(int i=0; i<n; ++i){
				if(k & (1 << i)){
					for(int j=0, m=(int)guitarSongs[0].size(); j<m; ++j){
						if(guitarSongs[i][j] == 'Y'){
							nMask |= (1LL << j);
						}
					}

					v[k].gNames.push_back(guitarNames[i]);
					v[k].guitarCount++;
				}
			}

			//count all the songs the set can play			
			for(int i=0, m=(int)guitarSongs[0].size(); i<m; ++i){
				if(nMask & (1LL << i))
					v[k].songs++;
			}

			//sort the guitar names in the set
			sort(v[k].gNames.begin(), v[k].gNames.end());
		}

		//printf("DEBUG: %d\n %d\n", v[4+16+128+256].songs, v[4+1+128+256].songs);

		sort(all(v));
		return v[0].gNames;
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
			string guitarNames[]      = {"GIBSON","FENDER", "TAYLOR"};
			string guitarSongs[]      = {"YNYYN", "NNNYY", "YYYYY"};
			string expected__[]       = {"TAYLOR" };

			clock_t start__           = clock();
			vector <string> received__ = GuitarConcert().buyGuitars(vector <string>(guitarNames, guitarNames + (sizeof guitarNames / sizeof guitarNames[0])), vector <string>(guitarSongs, guitarSongs + (sizeof guitarSongs / sizeof guitarSongs[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string guitarNames[]      = {"GIBSON", "CRAFTER", "FENDER", "TAYLOR"};
			string guitarSongs[]      = {"YYYNN", "NNNYY", "YYNNY", "YNNNN"};
			string expected__[]       = {"CRAFTER", "GIBSON" };

			clock_t start__           = clock();
			vector <string> received__ = GuitarConcert().buyGuitars(vector <string>(guitarNames, guitarNames + (sizeof guitarNames / sizeof guitarNames[0])), vector <string>(guitarSongs, guitarSongs + (sizeof guitarSongs / sizeof guitarSongs[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string guitarNames[]      = {"AB", "AA", "BA"};
			string guitarSongs[]      = {"YN", "YN", "NN"};
			string expected__[]       = {"AA" };

			clock_t start__           = clock();
			vector <string> received__ = GuitarConcert().buyGuitars(vector <string>(guitarNames, guitarNames + (sizeof guitarNames / sizeof guitarNames[0])), vector <string>(guitarSongs, guitarSongs + (sizeof guitarSongs / sizeof guitarSongs[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string guitarNames[]      = {"FENDER", "GIBSON", "CRAFTER", "EPIPHONE", "BCRICH"};
			string guitarSongs[]      = {"YYNNYNN", "YYYNYNN", "NNNNNYY", "NNYNNNN", "NNNYNNN"};
			string expected__[]       = {"BCRICH", "CRAFTER", "GIBSON" };

			clock_t start__           = clock();
			vector <string> received__ = GuitarConcert().buyGuitars(vector <string>(guitarNames, guitarNames + (sizeof guitarNames / sizeof guitarNames[0])), vector <string>(guitarSongs, guitarSongs + (sizeof guitarSongs / sizeof guitarSongs[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string guitarNames[]      = {"GIBSON","FENDER"};
			string guitarSongs[]      = {"NNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNN"};
			// string expected__[]    = empty, commented out for VC++;

			clock_t start__           = clock();
			vector <string> received__ = GuitarConcert().buyGuitars(vector <string>(guitarNames, guitarNames + (sizeof guitarNames / sizeof guitarNames[0])), vector <string>(guitarSongs, guitarSongs + (sizeof guitarSongs / sizeof guitarSongs[0])));
			return verify_case(casenum__, vector <string>(), received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string guitarNames[]      = {"EHVOXGL", "PVTVREOPNMMPBNGAELMEZDWHRFEWAMDREYECSBHYYAKR", "PMZNMLXTDFNKJNPZSDYQWZ", "KWHPLTXGQFURCJIUWVVCBZSGZOZGMRMTEMYXSYDQVMYYW", "DUEUT", "HHJHMW", "XSW", "BUQKZ", "EUHFLWJFHZOBIFTK"};
			string guitarSongs[]      = {"YNYNYYYYYYNNNYYYNYYYNNNNNYYNNNNNNYYYYYYNY", "YNNYNNYNNNNYYNNYYNNNNNNYYYYYNNYNYNNNYYYNY", "YNYNYNYNNNYNNYYYNYNNYYNNYNNYYYNNYYYYYNNYN", "YNYNYYYYNYYNNYNYYYYNNNNYYYYYYNNNNYYNYYNNN", "NYYYYYYNYYNNNNNNYNNYNNYYNNNYNYNNYYYYNYNYN", "NNYNYYNYNYNYNYNNNYNNYYNNYNNNNYYYNNYYNNYYY", "NNYNNYNNNYYYNNNYNNNNYYNYNYNYNNNYYYYNNYYNN", "NNYNYNNNNYNNNNNYYNNNNYNYYNNNNNNYYNYYYYNNY", "YYNYYNNYYNYYYNYYYYYNNYYYYYYYNNYNYNYYNYNNY"};
			string expected__[]       = {"BUQKZ", "EHVOXGL", "EUHFLWJFHZOBIFTK", "PMZNMLXTDFNKJNPZSDYQWZ"};

			clock_t start__           = clock();
			vector <string> received__ = GuitarConcert().buyGuitars(vector <string>(guitarNames, guitarNames + (sizeof guitarNames / sizeof guitarNames[0])), vector <string>(guitarSongs, guitarSongs + (sizeof guitarSongs / sizeof guitarSongs[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
/*      case 6: {
			string guitarNames[]      = ;
			string guitarSongs[]      = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = GuitarConcert().buyGuitars(vector <string>(guitarNames, guitarNames + (sizeof guitarNames / sizeof guitarNames[0])), vector <string>(guitarSongs, guitarSongs + (sizeof guitarSongs / sizeof guitarSongs[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string guitarNames[]      = ;
			string guitarSongs[]      = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = GuitarConcert().buyGuitars(vector <string>(guitarNames, guitarNames + (sizeof guitarNames / sizeof guitarNames[0])), vector <string>(guitarSongs, guitarSongs + (sizeof guitarSongs / sizeof guitarSongs[0])));
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
