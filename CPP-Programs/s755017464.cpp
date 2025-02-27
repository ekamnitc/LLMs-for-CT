#include <iostream>
#include <algorithm> // next_permutation
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstdio>
#include <stack>
#include <queue>
#include <list>
#include <numeric> //accumulate
//#include <unordered_map> //???????????\??¢??°
#include <fstream> //ifstream, ofstream

//#define NDEBUG //NDEBUG???#include <cassert>???????????????????????????????????´???assert?????????????????????????????????NDEBUG?????????????????????????????????????????????
#include <cassert> //assert


using namespace std;

//???????????°??????TEST????????????????????¬???????????????????????????????????¢????????????
#define TEST //*******************************************************************************************************************************************
//?????????????????¨??§?????\????????????????????????????????°?????????????¨???????????????????dout???????????????????????§???????????¬??????????????????????????????????????????
//??????????????????????????????????????????????????????????§?CPU???????£??????????????????§???TLE?????????????????????????????????????????§????????¨???                           ????????????????????????cerr????????£????????????????????????????????????
#ifdef TEST
#define dout cout
#else
stringstream dummy; //???????????°??????dout?????????????????????????????????
#define dout dummy.str(""); dummy.clear(stringstream::goodbit); dummy //dummy?????????????????????????????????????????¨?????¢?????¢???????????????
//???????????¨??????????????????goodbit?????????????????????????????¨???????????´????????????????????????????????¨?????°?????????????????§???????????????????????????????????? http://d.hatena.ne.jp/linden/20060427/p1
#endif

//?¨??????????????????????????????????????????????????????´??????OUTPUT2TEXTFILE????????????????????¬???????????????????????????????????¢????????????
//#define OUTPUT2TEXTFILE //*******************************************************************************************************************************************
#ifdef OUTPUT2TEXTFILE
#define dout outputfile //??¨????????????TLE????????§?????????dout?????¨??¨??????????????¢????????????????????????????????????????????§????¨????????????´??????????????£??????????????????????¨?????????????????????????????????????????????§?????????????????????
//TEST??????????????????????????¨???outputfile??????????????????????????????
#define OUTPUTFILENAME "output.txt"
ofstream outputfile(OUTPUTFILENAME);
#define OutputFilePath "/Users/Nag/Documents/Prgm/Test/DerivedData/Test/Build/Products/Debug/output.txt"
#endif

#define disp(A) dout << #A << " = " << (A) << endl
#define disP(A) dout << setw(3) << (A) << " " // << setw(3) ??????????????\????????????
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)

#define dispAll(A,n) dout << #A << " = "; rep(j, 0, (n)) {disP(A[j]);} dout << endl

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef unsigned long long ll;

const int INF = 1e9-1;



class Node {
public:
    Node(int value) {
        v = value;
        p = NULL;
        l = NULL;
        r = NULL;
    }
    
    
    int v;
    Node* p;
    Node* l;
    Node* r;
};



class BinaryTree {
public:
    BinaryTree() {
        root = NULL;
    }
    
    
    Node* root;
    
    
    void insert(int value) {
        Node* x = new Node(value); //????????????????????????
        
        
        Node* ptr = root; //tree??°?????¨???????????????
        Node* ptr_parent = NULL;
        while( ptr!=NULL ) { //NULL????????????????????§?????????????????¨???ptr_parent????????????????????????
            ptr_parent = ptr;
            if( x->v < ptr->v ) ptr = ptr->l;
            else ptr = ptr->r;
        }
        
        
        if(ptr_parent==NULL) { //tree???????????£?????????????????¨????????????????????????
            root = x;
            return;
        }
        else if( x->v < ptr_parent->v) {
            ptr_parent->l = x;
        }
        else {
            ptr_parent->r = x;
        }
    }
    
    
    bool find(int key) {
        Node* ptr = root; //tree??°?????¨???????????????
        while( ptr!=NULL ) {
            if( key == ptr->v ) return true;
            else if( key < ptr->v ) ptr = ptr->l;
            else ptr = ptr->r;
        }
        
        return false;
    }
    
    
    static void printInorder(Node* x) {
        if(x==NULL) return;
        
        printInorder(x->l);
        cout << " " << x->v;
        printInorder(x->r);
    }
    
    
    static void printPreorder(Node* x) {
        if(x==NULL) return;
        
        cout << " " << x->v;
        printPreorder(x->l);
        printPreorder(x->r);
    }
    
    
};


int main(){
    BinaryTree tree;
    
    int numOfQuery; cin >> numOfQuery;
    string command;
    int x;
    rep(i,0,numOfQuery) {
        cin >> command;
        if(command[0]=='i') {
            cin >> x;
            tree.insert(x);
        }
        else if(command[0]=='f') {
            cin >> x;
            cout << (tree.find(x) ? "yes" : "no") << endl;
        } else {
            BinaryTree::printInorder(tree.root);
            cout << endl;
            BinaryTree::printPreorder(tree.root);
            cout << endl;
        }
    }
    
#ifdef OUTPUT2TEXTFILE
    outputfile.close();
    cout << "\"" << OutputFilePath << "\"" << endl;
#endif
    
    return 0;
}