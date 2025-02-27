#include"tree.h"
class RBT :public tree {
	void INORDERLNR(Node*);
	void INORDERRNL(Node*);
	void PREORDERNLR(Node*);
	void PREORDERNRL(Node*);
	void POSTORDERLRN(Node*);
	void POSTORDERRLN(Node*);
	void CheckViolation(Node*, Node*, Node*, Node*);
	Node* Searchhelper(Node*, int);
	Node* findparenthelper(Node*, Node*);
	bool destroyHelper(Node*);
public:
	void insert(int);
	void inorderLNR();
	void inorderRNL();
	Node* Search(int);
	void preorderNLR();
	void preorderNRL();
	void postorderLRN();
	void postorderRLN();
	Node* findparent(int);
	bool Destroy();
};
bool RBT::Destroy() {
	if (root == nullptr) {
		return true;
	}
	else if (root->leftchild == nullptr && root->rightchild == nullptr) {
		delete root;
		root = nullptr;
		return true;
	}
	else {
		return destroyHelper(root);
	}
}
bool RBT::destroyHelper(Node* rt) {
	if (rt == nullptr) {
		return true;
	}
	destroyHelper(rt->leftchild);
	destroyHelper(rt->rightchild);
	delete rt;
	rt = nullptr;

}
void RBT::PREORDERNLR(Node* t ) {
	if (t != nullptr) {
		cout << "\033[";
		if (t->colour == 'B') {
			cout << 30 << "m";
		}
		else {
			cout << 31 << "m";
		}
		cout << t->data << endl;
		PREORDERNLR(t->leftchild);
		PREORDERNLR(t->rightchild);
	}

}
void RBT::PREORDERNRL(Node*t) {
	if (t != nullptr) {
		cout << "\033[";
		if (t->colour == 'B') {
			cout << 30 << "m";
		}
		else {
			cout << 31 << "m";
		}
		cout << t->data << endl;
		PREORDERNRL(t->rightchild);
		PREORDERNRL(t->leftchild);
	}

}
void  RBT::POSTORDERLRN(Node*t) {
	if (t != nullptr) {
		POSTORDERLRN(t->leftchild);
		POSTORDERLRN(t->rightchild);
		cout << "\033[";
		if (t->colour == 'B') {
			cout << 30 << "m";
		}
		else {
			cout << 31 << "m";
		}
		cout << t->data << endl;

	}


}
void RBT::POSTORDERRLN(Node*t) {
	if (t != nullptr) {
		POSTORDERRLN(t->rightchild);
		POSTORDERRLN(t->leftchild);
		cout << "\033[";
		if (t->colour == 'B') {
			cout << 30 << "m";
		}
		else {
			cout << 31 << "m";
		}
		cout << t->data << endl;

	}

}
void RBT::preorderNLR() {
		if (root == nullptr) {
		cout << "Tree is Empty" << endl;
	}
	else {
		PREORDERNLR(root);
		cout << "\033[0m" << endl;

	}

}
void RBT::preorderNRL() {
	if (root == nullptr) {
		cout << "Tree is Empty" << endl;
	}
	else {
		PREORDERNRL(root);
		cout << "\033[0m" << endl;

	}

}
void RBT::postorderLRN() {
	if (root == nullptr) {
		cout << "Tree is Empty" << endl;
	}
	else {
		POSTORDERLRN(root);
		cout << "\033[0m" << endl;

	}

}
void RBT::postorderRLN() {
	if (root == nullptr) {
		cout << "Tree is Empty" << endl;
	}
	else {
		POSTORDERRLN(root);
		cout << "\033[0m" << endl;

	}

}
void RBT::inorderLNR() {
	if (root == nullptr) {
		cout << "Tree is Empty" << endl;
	}
	else {
		INORDERLNR(root);
		cout << "\033[0m" << endl;

	}
}
void RBT::INORDERLNR(Node* t) {
	if (t != nullptr) {
		INORDERLNR(t->leftchild);
		cout << "\033[";
		if (t->colour == 'B') {
			cout << 30 << "m";
		}
		else {
			cout << 31 << "m";
		}
		cout << t->data << endl;
		INORDERLNR(t->rightchild);
	}
}
void RBT::inorderRNL() {
	if (root == nullptr) {
		cout << "Tree is Empty" << endl;
	}
	else {
		INORDERRNL(root);
		cout << "\033[0m" << endl;

	}
}
void RBT::INORDERRNL(Node* t) {
	if (t != nullptr) {
		INORDERRNL(t->rightchild);

		cout << "\033[";
		if (t->colour == 'B') {
			cout << 30 << "m";
		}
		else {
			cout << 31 << "m";
		}
		cout << t->data << endl;
		INORDERRNL(t->leftchild);

	}
}
Node* RBT::Search(int value) {
	if (root == nullptr) {
		return nullptr; // Tree is empty
	}
	else {
		return Searchhelper(root, value);
	}
}
Node* RBT::Searchhelper(Node* rt, int val) {
	if (rt == nullptr) {
		return nullptr; // Node not found
	}
	if (rt->data == val) {
		return rt; // Node found
	}
	if (rt->data > val) {
		return Searchhelper(rt->leftchild, val); // Recur left
	}
	else {
		return Searchhelper(rt->rightchild, val); // Recur right
	}
}
void RBT::insert(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->leftchild = nullptr;
	newNode->rightchild = nullptr;
	newNode->colour = 'R';

	if (root == nullptr) {
		newNode->colour = 'B';
		root = newNode;
		return;
	}

	if (root->leftchild == nullptr && root->rightchild == nullptr) {
		if (root->data > value) {
			root->leftchild = newNode;
		}
		else {
			root->rightchild = newNode;
		}
		return;
	}

	Node* t = root;
	while (t != nullptr) {
		if (t->data > value) {
			if (t->leftchild == nullptr) {
				t->leftchild = newNode;
				break;
			}
			else {
				t = t->leftchild;
			}
		}
		else {
			if (t->rightchild == nullptr) {
				t->rightchild = newNode;
				break;
			}
			else {
				t = t->rightchild;
			}
		}
	}

	Node* G1 = root;
	Node* G = root;
	Node* p = root;
	Node* c = root;

	while (true) {
		if (t == c) {
			break;
		}
		if (c->data > value) {
			G1 = G;
			G = p;
			p = c;
			c = c->leftchild;
		}
		else {
			G1 = G;
			G = p;
			p = c;
			c = c->rightchild;
		}
	}

	if (p->colour == 'R' && c->colour == 'R') {
		if (G->leftchild != p && G->rightchild == p) {
			if (G->leftchild != nullptr && G->leftchild->colour == 'R') {
				if (G == root) {
					p->colour = 'B';
					G->leftchild->colour = 'B';
				}
				else {
					char temp = G->colour;
					G->colour = p->colour;
					p->colour = temp;
					G->leftchild->colour = 'B';
				}
			}
			else {
				if (p->leftchild == c) { // Right-Left Case
					G->rightchild = c;
					p->leftchild = c->rightchild;
					c->rightchild = p;
					char temp = c->colour;
					c->colour = G->colour;
					G->colour = temp;

					if (G == root) {
						root = c;
						root->colour = 'B';
					}
					else {
						if (G1->rightchild == G) {
							G1->rightchild = c;
						}
						else {
							G1->leftchild = c;
						}
					}
				}
				else { // Right-Right Case
					char temp = p->colour;
					p->colour = G->colour;
					G->colour = temp;
					G->rightchild = p->leftchild;
					p->leftchild = G;

					if (G == root) {
						root = p;
						root->colour = 'B';
					}
					else {
						if (G1->rightchild == G) {
							G1->rightchild = p;
						}
						else {
							G1->leftchild = p;
						}
					}
				}
			}
		}
		else if (G->leftchild == p && G->rightchild != p) {
			if (G->rightchild != nullptr && G->rightchild->colour == 'R') {
				if (G == root) {
					p->colour = 'B';
					G->rightchild->colour = 'B';
				}
				else {
					char temp = G->colour;
					G->colour = p->colour;
					p->colour = temp;
					G->rightchild->colour = 'B';
				}
			}
			else {
				if (p->rightchild == c) { // Left-Right Case
					G->leftchild = c;
					p->rightchild = c->leftchild;
					c->leftchild = p;
					char temp = c->colour;
					c->colour = G->colour;
					G->colour = temp;

					if (G == root) {
						root = c;
						root->colour = 'B';
					}
					else {
						if (G1->rightchild == G) {
							G1->rightchild = c;
						}
						else {
							G1->leftchild = c;
						}
					}
				}
				else { // Left-Left Case
					char temp = p->colour;
					p->colour = G->colour;
					G->colour = temp;
					G->leftchild = p->rightchild;
					p->rightchild = G;

					if (G == root) {
						root = p;
						root->colour = 'B';
					}
					else {
						if (G1->rightchild == G) {
							G1->rightchild = p;
						}
						else {
							G1->leftchild = p;
						}
					}
				}
			}
		}
	}
	CheckViolation(root, root, root, root);
}
void RBT::CheckViolation(Node* G1, Node* G, Node* p, Node* c) {
	if (c != nullptr) {
		CheckViolation(G, p, c, c->leftchild);

		if (p->colour == 'R' && c->colour == 'R') {
			// Recoloring Case
			if ((G->leftchild == p && G->rightchild && G->rightchild->colour == 'R') ||
				(G->rightchild == p && G->leftchild && G->leftchild->colour == 'R')) {
				G->leftchild->colour = 'B';
				G->rightchild->colour = 'B';
				if (G != root) G->colour = 'R';
			}
			else {
				// Rotation Cases
				if (G->leftchild == p) {
					if (p->leftchild == c) {
						// Left-Left Case
						G->leftchild = p->rightchild;
						p->rightchild = G;
						char temp = p->colour;
						p->colour = G->colour;
						G->colour = temp;
						if (G == root) {
							root = p;
						}
						else {
							if (G1->leftchild == G) G1->leftchild = p;
							else if (G1->rightchild == G) G1->rightchild = p;
						}
					}
					else if (p->rightchild == c) {
						// Left-Right Case
						p->rightchild = c->leftchild;
						c->leftchild = p;
						G->leftchild = c->rightchild;
						c->rightchild = G;
						char temp = c->colour;
						c->colour = G->colour;
						G->colour = temp;
						if (G == root) {
							root = c;
						}
						else {
							if (G1->leftchild == G) G1->leftchild = c;
							else if (G1->rightchild == G) G1->rightchild = c;
						}
					}
				}
				else if (G->rightchild == p) {
					if (p->rightchild == c) {
						// Right-Right Case
						G->rightchild = p->leftchild;
						p->leftchild = G;
						char temp = p->colour;
						p->colour = G->colour;
						G->colour = temp;
						if (G == root) {
							root = p;
						}
						else {
							if (G1->leftchild == G) G1->leftchild = p;
							else if (G1->rightchild == G) G1->rightchild = p;
						}
					}
					else if (p->leftchild == c) {
						// Right-Left Case
						p->leftchild = c->rightchild;
						c->rightchild = p;
						G->rightchild = c->leftchild;
						c->leftchild = G;
						char temp = c->colour;
						c->colour = G->colour;
						G->colour = temp;
						if (G == root) {
							root = c;
						}
						else {
							if (G1->leftchild == G) G1->leftchild = c;
							else if (G1->rightchild == G) G1->rightchild = c;
						}
					}
				}
			}
		}

		CheckViolation(G, p, c, c->rightchild);
	}
}
Node* RBT::findparent(int childval) {
	// Check if the tree is empty
	if (root == nullptr) {
		throw invalid_argument("The tree is empty.");
	}

	// The root node cannot have a parent
	if (childval == root->data) {
		throw invalid_argument("Root has no parent.");
	}

	// Search for the node with the given value
	Node* childNode = Search(childval);
	if (childNode == nullptr) {
		cout << "This node is not available in the tree." << endl;
		return nullptr;
	}

	// Pass the root and the child node to the helper function
	return findparenthelper(root, childNode);
}

Node* RBT::findparenthelper(Node* parent, Node* childNode) {
	if (parent == nullptr) {
		return nullptr;
	}

	// Check if the current node is the parent of the target childNode
	if ((parent->leftchild == childNode) || (parent->rightchild == childNode)) {
		return parent;
	}


	if (childNode->data < parent->data) {
		return findparenthelper(parent->leftchild, childNode);
	}
	else {
		return findparenthelper(parent->rightchild, childNode);
	}
}
