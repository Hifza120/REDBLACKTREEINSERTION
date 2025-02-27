#include"Node.h"
class tree {
protected:
	Node* root;
public:
	tree() {
		root = nullptr;
	}
	virtual void insert(int)=0;
	virtual void inorderLNR()=0;
	virtual void inorderRNL()=0;
	virtual Node* Search(int)=0;
	virtual void preorderNLR()=0;
	virtual  void preorderNRL()=0;
	virtual void postorderLRN()=0;
	virtual void postorderRLN()=0;
	virtual Node* findparent(int)=0;
	virtual bool Destroy() = 0;

};