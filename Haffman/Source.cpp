#include "list.h"
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
	setlocale(LC_ALL, "rus");
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
	map<char, int>::map_iterator it(&rb);
	cout << "������� ��������: \n";
	++it;
	for (int i = 0; i < rb.getSize(); i++) {
		test.push_back(new HuffmanTree(*it, it.getValue()));
		cout << *it << " " << it.getValue() << endl;
		++it;
	}
	while (test.getSize() != 1) {
		test.sort();
		test.push_back(new HuffmanTree(test.at(0), test.at(1)));
		test.pop_front();
		test.pop_front();
	}
	HuffmanTree* huff = test.at(0);
	test.pop_front();
	cout << "������ ������: ";
	for (int i = 0; i < input.length(); i++) {
		for (int j = 0; j < (8 - to_binary_string(input[i]).length()); j++)
			cout << "0";
		cout << to_binary_string(input[i]) + " ";
	}
	huff->RLK(huff->getRoot());
	map<char, string> table;
	huff->toRbTree(&table, huff->getRoot());
	cout << "\n����� ������ ������ ������: " << 8 * input.length() << " ���";
	string encode = "";
	cout << "\n������ ������: ";
	for (int i = 0; i < input.length(); i++) {
		encode += table.find(input[i])->getValue();
		cout << table.find(input[i])->getValue();
		cout << " ";
	}
	cout << "\n����� �������������� ������: " << encode.length() << " ���";
	//Decode
	cout << "\n�������������� ������: ";
	cout << huff->decode(encode);
	// compression ratio
	cout << "\n\n����������� ������: ";
	cout << (float(encode.length()) / float((8 * input.length()))) * 100 << " %\n";

	return 0;
}