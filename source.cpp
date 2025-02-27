#include"RedBlacktree.h"
#include<stdexcept>
#include<fstream>
#include<string>
#include <windows.h>

RBT  readFromFile(RBT Tree) {
	ifstream fin;
	fin.open("input.txt");
	if (!fin) {
		
		throw  runtime_error("Unable to open the input file.");
	}

		string characters;
		while (fin >> characters) {
			//Convert strings into integer
			int number =stoi(characters);
		     Tree.insert(number);

		}
		fin.close();

		return Tree;
	
}

int main() {
	//FOR ADJUSTMENT OF COLORS
	// Get console handle

     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	 // Set the background to white (0xF0) and text to black (0x0)

	 SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | 0x0 | 0xF0);

	 system("cls");

	int option = 0;
	cout << "Press 1 to insert values in the tree (one by one)" << endl;
	cout << "Press 2 for searching a value from the tree" << endl;
	cout << "Press 3 for pre-order traversal NLR" << endl;
	cout << "Press 4 for in-order traversal LNR" << endl;
	cout << "Press 5 for post-order traversal LRN" << endl;
	cout << "Press 6 for pre-order traversal 2 NRL" << endl;
	cout << "Press 7 for in-order traversal 2 RNL" << endl;
	cout << "Press 8 for post-order traversal 2 RLN" << endl;
	cout << "Press 9 for displaying parent of a node present in Tree" << endl;
	cout << "Press 10 to read integer values from the file input.txt to create a red-black tree" << endl;
	cout << "Press 11 to destroy the complete tree" << endl;
	cout << "Press 12 to EXIT" << endl;
	RBT Tree;
	do {
		cout << "Enter  : ";
		cin >> option;

		if (option == 1) {
			int val = 0;
			cout << "Enter Value : ";
			cin >> val;
			Tree.insert(val);

		}
		else if (option == 2) {
			int val = 0;
			cout << "Enter Value : ";
			cin >> val;
			Node* t = Tree.Search(val);
			if (t != nullptr) {
				cout << "\033[0m" << endl;

				if (t->colour == 'B') {
					cout << "\033[30m"; // Black text
				}
				else {
					cout << "\033[31m"; // Red text
				
			}
				// The value is found in the tree, and `t` now points to the node containing the value.
				cout << "The value " << val << " is found in the tree." << endl;
			}
			else {
				// The value is not found in the tree.
				cout << "The value " << val << " is not found in the tree." << endl;
			}

		}
		else if (option == 3) {
			cout << "preorderNLR" << endl;
			Tree.preorderNLR();
		}
		else if (option==4) {
			cout << "inorderLNR" << endl;
			Tree.inorderLNR();
		}
		else if (option == 5) {
			cout << "postorderLRN" << endl;
			Tree.postorderLRN();
		}
		else if (option == 6) {
			cout << "preorderNRL" << endl;
			Tree.preorderNRL();
		}
		else if (option == 7) {
			cout << "inorderRNL" << endl;
			Tree.inorderRNL();

		}
		else if (option == 8) {
			cout << "postorderRLN" << endl;
			Tree.postorderRLN();
		}
		else if (option == 9) {
			int val = 0;
			cout << "Enter Value : ";
			cin >> val;
			try {
				Node*parent=Tree.findparent(val);
				if (parent->colour == 'B') {
					cout << "\033[30m"; // Black text
				}
				else {
					cout << "\033[31m"; // Red text
				}

				cout << parent->data << endl;

			}
			catch (const exception& e) {
				cout << e.what() << endl;
			}


		}
		else if (option == 10) {
			try {
				Tree = readFromFile(Tree);
			}
			catch (const exception& e) {
				cout << e.what() << endl;
			}
		}
		else if (option == 11) {
			if (Tree.Destroy()) {
				cout << "SuccessFully Destroyed" << endl;
			}
		}
		else if (option == 12) {
			break;
		}
		else {
			try {
				throw invalid_argument("This option is not valid ");
			}
			catch (const exception &e) {
				cout << e.what() << endl;
			}
		}

	} while (true);



	return 0;
}