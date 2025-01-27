#include <iostream>
#include <vector>
#include <string>
#define NIL (-1)
using namespace std;

/// LeftMost-Child Right-Sibling Tree
struct LCRSTreeNode {
	int p;// the parent
	int l;// the leftmost child
	int r;// the immediate right sibling 
	int d;// the depth of this node
	string type;// the type of this node; root, leaf, internal node
};

void print(vector<LCRSTreeNode> &T) {
	for (int i=0; i<T.size(); ++i) {
		// set type
		if (T[i].p == NIL) {
			T[i].type = "root";
		} else if (T[i].l == NIL) {
			T[i].type = "leaf";
		} else {
			T[i].type = "internal node";
		}	
		// node id: parent = p , depth = d, type, [c1...ck] 
		cout << "node " << i << ": parent = ";
		cout << T[i].p << ", depth = ";
		cout << T[i].d << ", ";
		cout << T[i].type << ", [";
	  int c = T[i].l;
		while (c != NIL) {
			cout << c;
			c = T[c].r;
			if (c != NIL) {
				cout << ", ";
			}
		}	
		cout << "]" << endl;
	}
}

void set_depth(int id, int depth, vector<LCRSTreeNode> &T) {
	if (id == NIL) return;
	T[id].d = depth;
	set_depth(T[id].r, depth,   T); 
	set_depth(T[id].l, depth+1, T);
}

int main() {
	int n;
	cin >> n;

	vector<LCRSTreeNode> T(n);
	for (int i=0; i<n; ++i) {
		T[i].p = T[i].l = T[i].r = NIL;
		T[i].d = NIL;
		T[i].type = "";
	}

	for (int i=0; i<n; ++i) {
		int id, k, child_id; 
		cin >> id >> k;
		if (k==0) continue;
		for (int j=0;j<k;++j) {
			cin >> child_id;
			T[child_id].p = id;
			int immediate_left_child_id;
			/// leftmost child
			if (j==0) {
				T[id].l = child_id;
			} else {
				/// immediate right siblings
				T[immediate_left_child_id].r = child_id;
			}
			immediate_left_child_id = child_id;
		}
	}

	/// find the root 
	int root_id = NIL;
	for (int i=0; i<n; ++i) {
		if (T[i].p == NIL) {
			root_id = i;
			break;
		}
	}

	/// set depths
	set_depth(root_id, 0, T);

	/// print
	print(T);
	return 0;
}



