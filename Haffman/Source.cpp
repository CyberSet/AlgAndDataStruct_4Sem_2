#include "list.h"
#include "queue.h"
#include "map.h"
#include "huffmanTree.h"
#include <string>
#include <iostream>

using namespace std;


string to_binary_string(char n)
{
	string result;
	do
	{
		result += ('0' + (n % 2));
		n = n / 2;
	} while (n > 0);
	return result;
}



int main() {
	string input;
	list<HuffmanTree> test;
	map<char, int> rb;
	cin >> input;
	int tempVal;
	for (int i = 0; i < input.length(); i++) {
		if (rb.find(input[i]) == 0) {
			rb.insert(input[i], 1);
		}
		else {
			tempVal = rb.find(input[i])->getValue();
			rb.remove(input[i]);
			rb.insert(input[i], tempVal + 1);
		}
	}
	rb<char, int>::iterator it(&rb);
	++it;
	cout << "symbol rate: \n";
	for (int i = 0; i < rbtree.getSize(); i++) {
		listOfHaffmanTrees.push(new HaffmanTree(*it, it.getValue()));
		cout << *it << " " << it.getValue() << endl;
		++it;
	}
	while (listOfHaffmanTrees.getSize() != 1) {
		listOfHaffmanTrees.sort();
		listOfHaffmanTrees.push(new HaffmanTree(listOfHaffmanTrees.pop(0), listOfHaffmanTrees.pop(1)));
	}

	HaffmanTree* haffmanTree = listOfHaffmanTrees.pop(0);
	//listOfHaffmanTrees[0] - Haffman tree

	cout << "First string: ";
	for (int i = 0; i < input.length(); i++) {
		for (int j = 0; j < (8 - to_binary_string(input[i]).length()); j++)
			cout << "0";
		cout << to_binary_string(input[i]) + " ";
	}

	haffmanTree->RLK(haffmanTree->getRoot());

	RBTree<char, string> haffmanTable;
	haffmanTree->toRbTree(&haffmanTable, haffmanTree->getRoot());

	cout << "\n\nstring weight: " << 8 * input.length() << " bits";


	string encodeInput = "";
	cout << "\n\nSecond string: ";
	for (int i = 0; i < input.length(); i++) {
		encodeInput += haffmanTable.find(input[i]);
		cout << haffmanTable.find(input[i]);
		cout << " ";
	}

	cout << "\n\nencode weight: " << encodeInput.length() << " bits";

	//Decode
	// cout << endl << encodeInput;
	cout << "\n\nDecode string: ";
	cout << haffmanTree->decode(encodeInput);


	// compression ratio
	cout << "\n\nCompression ratio: ";
	cout << (float(encodeInput.length()) / float((8 * input.length()))) * 100 << " %\n";

	return 0;
}