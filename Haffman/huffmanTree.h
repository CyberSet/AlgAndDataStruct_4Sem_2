#pragma once
#include "map.h"

class nodeHuffman {
private:
	nodeHuffman* parent;
	nodeHuffman* left, *right;
	string line;
	char value;
public:

	nodeHuffman(nodeHuffman* node_parent, nodeHuffman* node_left, nodeHuffman* node_right, char node_value) {
		parent = node_parent;
		left = node_left;
		right = node_right;
		value = node_value;
	}

	void setParent(nodeHuffman* node_parent) {
		parent = node_parent;
	}

	void setCode(string node_line) {
		line = node_line;
	}

	nodeHuffman* getLeft() {
		return left;
	}

	nodeHuffman* getRight() {
		return right;
	}

	string getLine() {
		return line;
	}

	void setLine(string node_line) {
		line = node_line;
	}

	char getValue() {
		return value;
	}

};
class HuffmanTree {
private:
	int power;
	nodeHuffman* root;

public:
	nodeHuffman* getRoot() {
		return root;
	}

	int getPower() {
		return power;
	}

	HuffmanTree(char tree_value, int tree_power) {
		root = new nodeHuffman(nullptr, nullptr, nullptr, tree_value);
		power = tree_value;
	}

	HuffmanTree(HuffmanTree* leftTree, HuffmanTree* rightTree) {
		power = leftTree->getPower() + rightTree->getPower();
		root = new nodeHuffman(nullptr, leftTree->getRoot(), rightTree->getRoot(), NULL);
		root->getLeft()->setParent(root);
		root->getRight()->setParent(root);
	}

	void RLK(nodeHuffman* node)
	{
		if (node != nullptr)
		{
			if (node->getRight() != nullptr) {
				node->getRight()->setLine(node->getLine() + "1");
				RLK(node->getRight());
			}
			if (node->getLeft() != nullptr) {
				node->getLeft()->setLine(node->getLine() + "0");
				RLK(node->getLeft());
			}
		}
	}

	void toRbTree(map<char, string>* tree, nodeHuffman* node)
	{
		if (node != nullptr)
		{
			if (node->getRight() != nullptr) {
				toRbTree(tree, node->getRight());
			}
			if (node->getLeft() != nullptr) {
				toRbTree(tree, node->getLeft());
			}
			if (node->getValue() != 0)
				tree->insert(node->getValue(), node->getLine());

		}
	}

	string decode(string encode) {
		string out = "";
		nodeHuffman* node = root;
		for (int i = 0; i < encode.length(); i++) {
			if (encode[i] == '0')
				node = node->getLeft();
			else if (encode[i] == '1')
				node = node->getRight();
			if (node->getValue() != 0) {
				out += node->getValue();
				node = root;
			}
		}
		return out;
	}
};