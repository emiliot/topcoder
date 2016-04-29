// BEGIN CUT HERE
#pragma warning(disable:4018)  // signed/unsigned mistatch
#pragma warning(disable:4244)  // w64 to int cast
#pragma warning(disable:4267)  // big to small -- possible loss of data
#pragma warning(disable:4786)  // long identifiers
#pragma warning(disable:4800)  // forcing int to bool
#pragma warning(disable:4996)  // deprecations
// END CUT HERE
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
template <class T> void make_unique(T& v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}
// BEGIN CUT HERE

typedef long long i64;
#define TC_LOCAL_COMPILE
#ifdef TC_LOCAL_COMPILE
#include "hash_set"
#include "hash_map"
using namespace stdext;
#else
#include "ext/hash_set"
#include "ext/hash_map"
using namespace __gnu_cxx;
#endif
// END CUT HERE

vector <string> f(vector <string> v){
	vector <string> res;
	for(int i=0, n=v.size(); i<n; ++i){
		for(int j=0, m=v[i].size(); j<m; ++j){
			char &c = v[i][j];
			if(c >= 'a' && c <= 'z')c += 'A' - 'a';
			else if(c < 'A' || c > 'Z')c = ' ';
		}
	}
	for(int i=0, n=v.size(); i<n; ++i){
		stringstream iss(v[i]);
		string aux;
		while(iss >> aux)
			res.push_back(aux);
	}
	return res;
}

vector <string> f(string v){
	vector <string> res;
	for(int i=0, n=v.size(); i<n; ++i){
		char &c = v[i];
		if(c >= 'a' && c <= 'z')c += 'A' - 'a';
		else if(c < 'A' || c > 'Z')c = ' ';
	}
	stringstream iss(v);
	string aux;
	while(iss >> aux)
		res.push_back(aux);
	return res;
}

struct Spamatronic {
	vector <int> filter(vector <string> knownSpam, vector <string> newMail) {
		vector <int> res;
		vector <string> v = f(knownSpam); make_unique(v);
		for(int i=0, n=newMail.size(); i<n; ++i){
			vector <string> mail = f(newMail[i]);
			make_unique(mail);
			vector <bool> mark(v.size(),false);
			int spam = 0;
			for(int j=0, m=mail.size(); j<m; ++j){
				vector <string>::iterator it = find(all(v),mail[j]);
				if(it != v.end())
					++spam;
			}
			if(spam * 100 >= mail.size()*75){
				for(int k=0, m=mail.size(); k<m; ++k)
					v.push_back(mail[k]);
				make_unique(v);
			}else res.push_back(i);
		}
		return res;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
  int isinf(double x) {return !_finite(x);}
  int isnan(double x) {return _isnan(x);}
};
namespace moj_harness {
	int run_test_case(int);
	void run_test( int casenum ) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
			if ( x == -1 ) {
				if ( i >= 100 ) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if ( total == 0 ) {
			cerr << "No test cases run." << endl;
		} else if ( correct < total ) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	template<typename T> ostream& operator<<( ostream &os, const vector<T> &v ) { os << "{"; for ( typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi ) { if ( vi != v.begin() ) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case( int casenum, const vector <int> &expected, const vector <int> &received ) { 
		cerr << "Example " << casenum << "... "; 
		if ( expected == received ) {
			cerr << "PASSED" << endl;
			return 1;
		} else {
			cerr << "FAILED" << endl;
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
			return 0;
		}
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string knownSpam[]        = {"This is a vile piece of spam."};
			string newMail[]          = {"Spam is spiced ham.",  "Spam is VILE!",  "Spam is not vile."};
			int expected[]            = { 0 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Spamatronic().filter( vector <string>( knownSpam, knownSpam + ( sizeof knownSpam / sizeof knownSpam[0] ) ), vector <string>( newMail, newMail + ( sizeof newMail / sizeof newMail[0] ) ) ) );
		}
		case 1: {
			string knownSpam[]        = {"We have the best mortgage rates. Refinance today.",  "Money-making opportunity! $5000/week potential!!!",  "Don't Feel Short; try Elevator Shoes for increase.",  "All-new pics: Stacy, Tiffany, Donner, and Blitzen."};
			string newMail[]          = {"5000 bucks for shoes?",  "Short bucks for new shoes?"};
			int expected[]            = { 0 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Spamatronic().filter( vector <string>( knownSpam, knownSpam + ( sizeof knownSpam / sizeof knownSpam[0] ) ), vector <string>( newMail, newMail + ( sizeof newMail / sizeof newMail[0] ) ) ) );
		}
		case 2: {
			string knownSpam[]        = {"We have the best mortgage rates. Refinance today.",  "Money-making opportunity! $5000/week potential!!!",  "Don't Feel Short; try Elevator Shoes for increase.",  "All-new pics: Stacy, Tiffany, Donner, and Blitzen."};
			string newMail[]          = {"On, Dasher! On, Dancer! On, Donner and Blitzen!"};
			int expected[]            = { 0 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Spamatronic().filter( vector <string>( knownSpam, knownSpam + ( sizeof knownSpam / sizeof knownSpam[0] ) ), vector <string>( newMail, newMail + ( sizeof newMail / sizeof newMail[0] ) ) ) );
		}
		case 3: {
			string knownSpam[]        = {"We have the best mortgage rates. Refinance today.",  "Money-making opportunity! $5000/week potential!!!",  "Don't Feel Short; try Elevator Shoes for increase.",  "All-new pics: Stacy, Tiffany, Donner, and Blitzen."};
			string newMail[]          = {"Try the prime ribs.",  "Donner: New Prime Rates Today",  "Try the prime ribs."};
			int expected[]            = { 0 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Spamatronic().filter( vector <string>( knownSpam, knownSpam + ( sizeof knownSpam / sizeof knownSpam[0] ) ), vector <string>( newMail, newMail + ( sizeof newMail / sizeof newMail[0] ) ) ) );
		}
		case 4: {
			string knownSpam[]        = {"One, two, buckle my shoe.",  "Eins, zwei, polizei.",  "On the first day of Christmas, my true love",  "gave to me a partridge in a pear tree."};
			string newMail[]          = {"Christmas shoe buckle madness!",  "Partridge polizei madness day!",  "I did not shoot the deputy.",  "The second day of Christmas, a partridge bit me."};
			int expected[]            = { 2 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Spamatronic().filter( vector <string>( knownSpam, knownSpam + ( sizeof knownSpam / sizeof knownSpam[0] ) ), vector <string>( newMail, newMail + ( sizeof newMail / sizeof newMail[0] ) ) ) );
		}
		case 5: {
			string knownSpam[]        = {"ArnQ iGue ORAr tYMK GLPK pcdV QCOQ TJGj JFgv QuDv ",  "BbPq hpBp Quuv VsQe oJYB GuIh syuO XNTl tLgZ GlET ",  "LYUT feoz ArcZ SFED Txbg DTQd SCID Vztx ERDj hkXY ",  "qTLZ nDXV sDKm lUsS cQVI UElK JkNT xbcc oSvE tnzK ",  "ysrX jLeu vIJe NYmX oeRC SWfg UfCU Iumf xnuE Dsay ",  "sXKj DCSY LCbJ ovIj tTGm AYyL KcTV PJFZ ZIaH yPnk ",  "EJcc ESfL PaRN OMpb DJGZ VQlA AUoD mrXE afWW otpR ",  "njeP FDib qEEt sZjP Ybsv XplI dPvn tuUM rnhE sRdG ",  "Rtbd oCEF xECT VOZP aKdp ARuG ZyqG BpOx KiZg VwjP ",  "zkmC JuIK jEaC AjuA jXRX TUyI cpJP bmnE qXsI BYAM ",  "JcJO BEQN bTrL OpXy fKfx XGyV aMFv TNCG xrmH rnsq ",  "olSb fBig LuzT rJbq IEjR ygzg GgpS qaiS GDMT wMoN ",  "Ypxx tWrb WSEe COmB XwqK GOWj ZCQW qtkm riJO weoj ",  "uDHD nmTu yruZ zVEu Bhyl qheT KqwD YFTK frMk daSC ",  "ywfg arFu KGOk rciT PZQX tSll dpXd Aczq EYjW RQkh ",  "BJcC dJkr lWPM jaJI UCMt NQiy azlc encg srwA YhUH ",  "wqET eMLv kFYM GbDi hkQq sFvy ZwLi gvbu wdLz bZzl ",  "NIVA xpTx SUOz vhQM fYTn NkrJ pKYm sVpf DMxL RtAn ",  "kCXI TAzJ aaeQ zYqX TpfN nLpA bsmp GsAa rDhI kexj ",  "ibLo DWfO aEYD Dkzt gqOf IKeP jDJk iaAH viBk kbyz ",  "ArnQ iGue ORAr tYMK GLPK pcdV QCOQ TJGj JFgv QuDv ",  "BbPq hpBp Quuv VsQe oJYB GuIh syuO XNTl tLgZ GlET ",  "LYUT feoz ArcZ SFED Txbg DTQd SCID Vztx ERDj hkXY ",  "qTLZ nDXV sDKm lUsS cQVI UElK JkNT xbcc oSvE tnzK ",  "ysrX jLeu vIJe NYmX oeRC SWfg UfCU Iumf xnuE Dsay ",  "sXKj DCSY LCbJ ovIj tTGm AYyL KcTV PJFZ ZIaH yPnk ",  "EJcc ESfL PaRN OMpb DJGZ VQlA AUoD mrXE afWW otpR ",  "njeP FDib qEEt sZjP Ybsv XplI dPvn tuUM rnhE sRdG ",  "Rtbd oCEF xECT VOZP aKdp ARuG ZyqG BpOx KiZg VwjP ",  "zkmC JuIK jEaC AjuA jXRX TUyI cpJP bmnE qXsI BYAM ",  "JcJO BEQN bTrL OpXy fKfx XGyV aMFv TNCG xrmH rnsq ",  "olSb fBig LuzT rJbq IEjR ygzg GgpS qaiS GDMT wMoN ",  "Ypxx tWrb WSEe COmB XwqK GOWj ZCQW qtkm riJO weoj ",  "uDHD nmTu yruZ zVEu Bhyl qheT KqwD YFTK frMk daSC ",  "ywfg arFu KGOk rciT PZQX tSll dpXd Aczq EYjW RQkh ",  "BJcC dJkr lWPM jaJI UCMt NQiy azlc encg srwA YhUH ",  "wqET eMLv kFYM GbDi hkQq sFvy ZwLi gvbu wdLz bZzl ",  "NIVA xpTx SUOz vhQM fYTn NkrJ pKYm sVpf DMxL RtAn ",  "kCXI TAzJ aaeQ zYqX TpfN nLpA bsmp GsAa rDhI kexj ",  "ibLo DWfO aEYD Dkzt gqOf IKeP jDJk iaAH viBk kbyz ",  "ArnQ iGue ORAr tYMK GLPK pcdV QCOQ TJGj JFgv QuDv ",  "BbPq hpBp Quuv VsQe oJYB GuIh syuO XNTl tLgZ GlET ",  "LYUT feoz ArcZ SFED Txbg DTQd SCID Vztx ERDj hkXY ",  "qTLZ nDXV sDKm lUsS cQVI UElK JkNT xbcc oSvE tnzK ",  "ysrX jLeu vIJe NYmX oeRC SWfg UfCU Iumf xnuE Dsay ",  "sXKj DCSY LCbJ ovIj tTGm AYyL KcTV PJFZ ZIaH yPnk ",  "EJcc ESfL PaRN OMpb DJGZ VQlA AUoD mrXE afWW otpR ",  "njeP FDib qEEt sZjP Ybsv XplI dPvn tuUM rnhE sRdG ",  "Rtbd oCEF xECT VOZP aKdp ARuG ZyqG BpOx KiZg VwjP ",  "Rtbd oCEF xECT VOZP aKdp ARuG ZyqG BpOx KiZg VwjP "};
			string newMail[]          = {"qXsI hRfD viBk KGOk GLPK kFYM WSEe oCEF ysrX Gicz ",  "YMav Clmy LuzT wdLz nmTu jiCs gvbu sRdG aaeQ EMFM ",  "syuO pKYm ootQ UyOJ TpfN encg LuzT sRdG TJGj elbx ",  "LuzT nDXV boPm zOqG jLeu gcxH zOqG KqwD RQkh PJFZ ",  "srwA aKdp VOZP rJbq viBk WIlz kexj ysrX icKO OpXy ",  "Flij SHTh shhx EMFM pcdV viBk ESfL zkmC sHHV TNCG ",  "GDMT lWPM tWrb tnzK aEYD dJkr NQiy CyZJ GOWj Ybsv ",  "wBEy IEjR COmB bZzl vhQM iaAH EMFM bsmp GLPK lWPM ",  "tWrb HFzg XPoH ZCQW zOqG PZQX CyZJ qnsD Txbg tLgZ ",  "LYUT vODC DzEE bTrL Clmy AYyL lBJT EYjW fBig MGEK ",  "UbbN DTQd ysrX vhQM tSll bZzl qXsI DWfO LzXO UfCU ",  "BYAM wAAt Aczq Ckym lWPM lBJT KcTV Hbut rJbq ibLo ",  "feoz qaiS oSvE kFYM XGyV lWPM NIVA sDKm QuDv rnsq ",  "BYAM UDNV GuIh GuIh bKFz ootQ sFvy zpXB ZbWY NQiy ",  "cWfG oeRC LHJC NYmX ppzA NIVA rDhI QCOQ fBig aMFv ",  "RQkh SUOz WkoW wqET sRdG sRdG tnzK ARuG OMpb xbcc ",  "gvbu AjuA GgpS nLpA TUyI Swfg LCbJ aaeQ XGyV yruZ ",  "ygzg xnuE afWW tuUM KGOk GOWj ousC mrXE ZwLi FSll ",  "ckKT frMk McdI zVEu nVIK ygzg daSC ArcZ Dagc ryuQ ",  "bPhx zurF XAIM gqOf aRSX Ypxx dfwy aKdp chtc iCCo ",  "ovIj ywfg QuDv pKYm iaAH BbPq LHJC tTGm Vztx VwjP ",  "TpfN TAzJ Vztx tTGm sXKj IKeP AUoD qXsI DMxL azlc ",  "sRdG WYmV NQuu xnuE TUyI XPoH YhUH ousC AYyL jEaC ",  "RQkh BbPq UbbN GuIh oCEF tLgZ arFu qTLZ Dkzt zVEu ",  "NIVA FDib PZQX McdI GgpS Euso ppzA Dagc Vztx LHJC ",  "ZvMg Bhyl GOWj sDKm ywfg oJYB AjuA jaJI ZIaH Dkzt ",  "ygzg oSvE qheT encg SUOz vODC mDVo KcTV swcU Dkzt ",  "GgpS RtAn TpfN JFgv kexj qXsI DMxL MhEv ArnQ oSvE ",  "TEig YhUH SHTh KGOk EYjW XGyV yruZ GLPK oeRC QIEM ",  "Ybsv jXRX Iumf kFYM wdLz gvbu hkXY QCOQ COmB tLgZ ",  "EYjW vhQM xECT UfCU iaAH JuIK KqwD XNTl wdLz Ypxx ",  "rdmJ RQkh avBu TSWv UtFm VsQe bZzl bZzl MGEK KGOk ",  "LuzT Euso UbGd jiCs qaqp wAMV ywfg nVIK LuzT otpR ",  "aEjf jELm ibwU eUXx OBwq UyOJ BbPq QEut Flij ysrX ",  "srwA FSll RtAn VQlA SrZq FRJh OMpb JFgv srwA KiZg ",  "DCSY ZIaH cQVI frMk zYqX McdI wdLz qTLZ BYAM srwA ",  "mhEw rnhE tWrb aEjf tXuk RtPo aeGI ootQ kexj DTQd ",  "PJFZ GOWj bTrL tuUM bmnE sZjP aKdp GuIh XplI Txbg ",  "tuUM EYjW viBk nLpA jDJk LuzT lUsS PZQX Dkzt aEYD ",  "vIJe ERDj jXRX aRPM aKdp xbcc qXsI Uosx YhUH WSEe ",  "SoOP Ypxx XNTl SUOz tTGm rJbq xbcc NIVA jDJk rnsq ",  "pcdV riJO zkmC JFgv yruZ fYTn njeP dPvn VsQe xECT ",  "iaAH TUyI QIEM zVEu BbuB Aseu xpTx aKdp WSEe tWrb ",  "UhJb sFvy ArnQ dfwy eUXx ENkl elbx VwjP kbyz UElK ",  "daSC vpco bmnE NwgV LYUT JkNT nDXV YMav aKdp NwgV ",  "rDhI GOWj AjuA mrXE BbPq aaeQ FGcp ckKT GlET ESfL ",  "Bhyl tSIB njeP nDXV VwjP VOZP tXuk NYmX UCMt KcTV ",  "BpOx JwQv TUyI Blsk PJFZ sFvy cpJP RtAn sZjP NYmX ",  "SFED Ybsv ootQ QCOQ DTQd pcdV kCXI TAzJ zVEu QCOQ ",  "SFED Ybsv ootQ QCOQ DTQd pcdV kCXI TAzJ zVEu QCOQ "};
			int expected[]            = { 1,  2,  3,  5,  8,  9,  11,  13,  14,  18,  19,  22,  24,  26,  28,  31,  32,  33,  36,  42,  43,  44 };

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Spamatronic().filter( vector <string>( knownSpam, knownSpam + ( sizeof knownSpam / sizeof knownSpam[0] ) ), vector <string>( newMail, newMail + ( sizeof newMail / sizeof newMail[0] ) ) ) );
		}

		// custom cases

      case 6: {
			string knownSpam[]        = {"zixJ dpIK nckL InuQ xDiM foJh Rntr DTQw jWcy vSTm ", "lyAF xgov qKlp pTCc DNsl ruSZ Vouo Unpj EXrA lxMO ", "JNjf lqGv oaDM Rxwu SrMK TcfR iJFX KhPq Hvsq XoVr ", "TXtc WjJs whkx ggEv iSSn NuGe yFYd XWTE wsyp tNZL ", "dWUR fMYm EOrA PJfr smDd NIpF Xoym FzcS jgTF ULmy ", "dSTu rdMJ cjuB NNxP psNj wcPz wdhO oKNa LahU lYcn ", "iobz AOFy wIfO hZgv fVqX pVaT seDa dSPm GYMI Mrkl ", "GzFF gtpE ghWy RPOE SFEF HFBG EMYP fPBU lOBM lNsW ", "cJtE rBKi HPQt zqea sYjm QTSR vtNM BhfN xwIQ zXQF ", "aijy OcXP WvJC beLG fPgV CUZU MbZQ tgqw fMmf qJWA ", "Lyai wdqP JoiT OPiM KaiE pNXs GVHh ZyNS mAiX rIEm ", "FqnJ EamI WwmB jaLk HuIr yKiR fGBE UmWY MXfn TYdV ", "oupP PSiS TbUe hebU hwIm AMqM UPeH heML gEXq mxAj ", "oEWe Sajw aZqR RySY nEdj xjdp uVIN uNtG IYgm BFih ", "auOt BPtx sYuz sQqw GGgp RUOd GLmb GcZO vTad LIXK ", "Cbfc oRiH oeUx SKRF erWo WLSQ mHBl Lkkc rWzm DhRw ", "dWqy RZgF MGVK TZSO MrPX lQtn mxFp HVbM YuET mqmO ", "ssUV bGiV MzVw NEkK cbTc OdwG kdtO tILj qmNR kgxZ ", "hOhf jDLe fZpb zQAM rwFE rFDZ OMCl kBft ZUAi gGUW ", "sTJQ GrAm gDQc GCqo tCyB eBIm TPDS GQhT Yskx DdGq ", "zixJ dpIK nckL InuQ xDiM foJh Rntr DTQw jWcy vSTm ", "lyAF xgov qKlp pTCc DNsl ruSZ Vouo Unpj EXrA lxMO ", "JNjf lqGv oaDM Rxwu SrMK TcfR iJFX KhPq Hvsq XoVr ", "TXtc WjJs whkx ggEv iSSn NuGe yFYd XWTE wsyp tNZL ", "dWUR fMYm EOrA PJfr smDd NIpF Xoym FzcS jgTF ULmy ", "dSTu rdMJ cjuB NNxP psNj wcPz wdhO oKNa LahU lYcn ", "iobz AOFy wIfO hZgv fVqX pVaT seDa dSPm GYMI Mrkl ", "GzFF gtpE ghWy RPOE SFEF HFBG EMYP fPBU lOBM lNsW ", "cJtE rBKi HPQt zqea sYjm QTSR vtNM BhfN xwIQ zXQF ", "aijy OcXP WvJC beLG fPgV CUZU MbZQ tgqw fMmf qJWA ", "Lyai wdqP JoiT OPiM KaiE pNXs GVHh ZyNS mAiX rIEm ", "FqnJ EamI WwmB jaLk HuIr yKiR fGBE UmWY MXfn TYdV ", "oupP PSiS TbUe hebU hwIm AMqM UPeH heML gEXq mxAj ", "oEWe Sajw aZqR RySY nEdj xjdp uVIN uNtG IYgm BFih ", "auOt BPtx sYuz sQqw GGgp RUOd GLmb GcZO vTad LIXK ", "Cbfc oRiH oeUx SKRF erWo WLSQ mHBl Lkkc rWzm DhRw ", "dWqy RZgF MGVK TZSO MrPX lQtn mxFp HVbM YuET mqmO ", "ssUV bGiV MzVw NEkK cbTc OdwG kdtO tILj qmNR kgxZ ", "hOhf jDLe fZpb zQAM rwFE rFDZ OMCl kBft ZUAi gGUW ", "sTJQ GrAm gDQc GCqo tCyB eBIm TPDS GQhT Yskx DdGq ", "zixJ dpIK nckL InuQ xDiM foJh Rntr DTQw jWcy vSTm ", "lyAF xgov qKlp pTCc DNsl ruSZ Vouo Unpj EXrA lxMO ", "JNjf lqGv oaDM Rxwu SrMK TcfR iJFX KhPq Hvsq XoVr ", "TXtc WjJs whkx ggEv iSSn NuGe yFYd XWTE wsyp tNZL ", "dWUR fMYm EOrA PJfr smDd NIpF Xoym FzcS jgTF ULmy ", "dSTu rdMJ cjuB NNxP psNj wcPz wdhO oKNa LahU lYcn ", "iobz AOFy wIfO hZgv fVqX pVaT seDa dSPm GYMI Mrkl ", "GzFF gtpE ghWy RPOE SFEF HFBG EMYP fPBU lOBM lNsW ", "cJtE rBKi HPQt zqea sYjm QTSR vtNM BhfN xwIQ zXQF ", "aijy OcXP WvJC beLG fPgV CUZU MbZQ tgqw fMmf qJWA "};
			string newMail[]          = {"TIRn PZIV TPDS GYMI GLmb vQto OdwG MzVw sQqw hwIm ", "hhLX whkx tRXp fGBE zogg wdhO iOIq OdwG Iisk GJXN ", "RZgF DTQw Rxwu NuGe MzVw UmWY qKWl WHfH KaiE FqnJ ", "psNj pVaT wdhO WLSQ XoVr PuEI auOt aijy GGgp zqea ", "wdqP RPOE PJfr OcXP fPBU tAfF lqGv JNjf rwFE NuGe ", "oKNa vtNM AMqM gGUW hLcY SrMK AGOT lqGv GYMI rdMJ ", "bGiV GLmb TXtc HXon TIRn sYjm YuET pTCc jsHA KJbH ", "GLmb ELVH hebU fMmf OPiM GcZO rIEm NIpF uobt kgxZ ", "AMqM beLG oeUx Lyai qJWA fPBU FzcS dWUR dERc IoUm ", "gGUW uWxb pNXs Anjs LAuk IgpL ncls CEob xwIQ qJWA ", "ssUV uUhb Unpj SKRF qmNR UHeb KaiE wIfO CUZU DhRw ", "jDLe XoVr KVSQ MXgd LotM uRZg cPaZ NIpF wdqP heML ", "JoiT KdgW ULmy OcXP yFYd mhHF oEWe mxFp WjJs GGgp ", "fPgV pNXs mhHF REtY dWUR pNXs pkRi hhLX cwTS tNMf ", "SFEF BPtx fMYm MXfn iSSn hLcY Vouo fPgV NEkK Yskx ", "wIfO REtY RUOd foJh UMeV GYMI qKlp hhLX wdhO SrMK ", "ImBn oRiH QTSR tCyB ImBn tILj jaLk Hvsq smDd cwTS ", "mHBl IgpL AtdX FJPG lqGv cjuB kBft AGOT lQtn fGBE ", "WwmB eDVX auOt iobz kjiX vGnN mxAj gGUW qKWl oaDM ", "dpIK hwIm zVvF lQtn wIfO dWqy JcGA fffv nmSZ IoUm ", "sQqw NuGe RUOd sYuz WwmB IoUm dWUR dSPm jEcw seDa ", "eBIm aijy ZBpw gDQc WLSQ xgov ekZG lqGv UPeH rwFE ", "oaDM PZIV cjuB DdGq Aehz mHBl Gxrz lyAF PZIV sYuz ", "GLmb LIXK sYjm cjuB foJh NIpF IYgm IsXc KhPq kjiX ", "cOSp rWzm pNXs uNtG qJWA hZgv cbTc OPiM Mvqs xDiM ", "ZUAi IsXc foJh qKlp ULmy fPBU aijy xwIQ QTSR nsjU ", "DGHS BniQ NIpF pVaT AClY xqxr xwIQ rIEm VBdj bkiA ", "tNZL oKNa qKWl gBqr sgHZ yOGN KJbH HVbM vhWp UPeH ", "Hvsq QTSR hwIm RPOE mxFp fffv oeUx HuIr dWqy EamI ", "XoVr CUZU YuET Lkkc DhRw aCgS oRiH lOBM nsjU dSqG ", "SKRF TZSO URym erWo gngf hLcY iONk bkiA rIEm rwFE ", "FzcS jYAW oaDM oRiH rPBb OdwG eBIm Mgjw sTJQ hhLX ", "whkx vhWp jyHe tEhO nEdj Gxrz xxpV Tpnj CEob oEWe ", "wIfO fZpb oupP pTCc fPBU IYgm UPeH JoiT iobz OMCl ", "fVqX qmNR QTSR qJWA RUHr EOrA tNZL rFDZ GaQr oKNa ", "kBft heML HFBG uUhb gGUW pTCc lUyI kgxZ cVdI SrMK ", "NuGe OPiM eDVX dERc RUHr qKWl MXgd kXqo Wjse BFih ", "NuGe zOrD aQdw ZoAm beLG PXRL SrMK GrAm WjJs RkfJ ", "GJXN oaDM QTSR cVdI uobt OPiM OdwG pVaT jgTF Lkkc ", "dWUR dWqy EMYP OMCl lQtn CUZU mAiX lxMO RPOE vTad ", "LahU JImO rIEm beLG sYuz QTSR TWLA MGVK TXtc MrPX ", "TYdV mAiX PJfr wsyp Rntr lxMO beLG uFEn RSvV ULmy ", "EBJf IYgm lCgO TZSO xgLy whkx Wjse ZXld nigB OdwG ", "DhRw XWTE wsyp WjJs lqGv Lkkc zixJ Hvsq oKNa hCuc ", "kXqo XUea gIaC Mgjw UIDx iONk ZXld FqnJ ETrG PvyH ", "vhWp fVqX GYMI gDQc oRiH yOGN MzVw cbTc kgxZ HPQt ", "MbZQ RUOd tgqw XWTE GzFF jCRp JNjf sTJQ AMqM tNZL ", "bGiV LUCg GVHh ULmy HWuD hCuc ZBpw gtpE iobz TPDS ", "lqGv Lyai MXfn nEdj wsyp PuEI sTJQ zXQF sYuz yFYd ", "gBqr jCRp OcXP gtpE JImO GLmb OPiM YohS uobt ssUV "};
			int expected[]            = {0, 1, 6, 9, 11, 13, 15, 17, 18, 19, 22, 26, 27, 30, 31, 32, 36, 37, 42, 44};

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Spamatronic().filter( vector <string>( knownSpam, knownSpam + ( sizeof knownSpam / sizeof knownSpam[0] ) ), vector <string>( newMail, newMail + ( sizeof newMail / sizeof newMail[0] ) ) ) );
		}
      case 7: {
		  string knownSpam[]        = {"spam"};
		  string newMail[]          = {"spam spam spam spam lol"};
		  int expected[]            = {0};

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Spamatronic().filter( vector <string>( knownSpam, knownSpam + ( sizeof knownSpam / sizeof knownSpam[0] ) ), vector <string>( newMail, newMail + ( sizeof newMail / sizeof newMail[0] ) ) ) );
		}
/*      case 8: {
			string knownSpam[]        = ;
			string newMail[]          = ;
			int expected[]            = ;

			return verify_case( casenum, vector <int>( expected, expected + ( sizeof expected / sizeof expected[0] ) ), Spamatronic().filter( vector <string>( knownSpam, knownSpam + ( sizeof knownSpam / sizeof knownSpam[0] ) ), vector <string>( newMail, newMail + ( sizeof newMail / sizeof newMail[0] ) ) ) );
		}*/
		default:
			return -1;
		}
	}
}

int main() {
  moj_harness::run_test(-1);
} 
// END CUT HERE
