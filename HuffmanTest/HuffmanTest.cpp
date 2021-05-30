#include "pch.h"
#include "CppUnitTest.h"
#include "..//Haffman/huffmanTree.h"
#include "..//Haffman/list.h"
#include "..//Haffman/map.h"
#include "..//Haffman/node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HuffmanTest
{
	TEST_CLASS(HuffmanTest)
	{
	public:
		
		TEST_METHOD(DecodeTest)
		{
			string input = "Huffman";
			list<HaffmanTree*> listOfHaffmanTrees;
			RBTree<char, int> rbtree;
			int tempVal;
			for (int i = 0; i < input.length(); i++) {
				if (rbtree.find(input[i]) == 0) {
					rbtree.insert(input[i], 1);
				}
				else {
					tempVal = rbtree.find(input[i]);
					rbtree.remove(input[i]);
					rbtree.insert(input[i], tempVal + 1);
				}
			}
			RBTree<char, int>::iterator it(&rbtree);
			++it;
			for (int i = 0; i < rbtree.getSize(); i++) {
				listOfHaffmanTrees.push(new HaffmanTree(*it, it.getValue()));
				++it;
			}
			while (listOfHaffmanTrees.getSize() != 1) {
				listOfHaffmanTrees.sort();
				listOfHaffmanTrees.push(new HaffmanTree(listOfHaffmanTrees.pop(0), listOfHaffmanTrees.pop(1)));
			}

			HaffmanTree* haffmanTree = listOfHaffmanTrees.pop(0);


			haffmanTree->RLK(haffmanTree->getRoot());

			RBTree<char, string> haffmanTable;
			haffmanTree->toRbTree(&haffmanTable, haffmanTree->getRoot());

			string encodeInput = "";
			for (int i = 0; i < input.length(); i++) {
				encodeInput += haffmanTable.find(input[i]);
			}

			Assert::IsTrue(haffmanTree->decode(encodeInput) == "Huffman");
		}

		TEST_METHOD(RLKTest)
		{
			string input = "Huffman";
			list<HaffmanTree*> listOfHaffmanTrees;
			RBTree<char, int> rbtree;
			int tempVal;
			for (int i = 0; i < input.length(); i++) {
				if (rbtree.find(input[i]) == 0) {
					rbtree.insert(input[i], 1);
				}
				else {
					tempVal = rbtree.find(input[i]);
					rbtree.remove(input[i]);
					rbtree.insert(input[i], tempVal + 1);
				}
			}
			RBTree<char, int>::iterator it(&rbtree);
			++it;
			for (int i = 0; i < rbtree.getSize(); i++) {
				listOfHaffmanTrees.push(new HaffmanTree(*it, it.getValue()));
				++it;
			}
			while (listOfHaffmanTrees.getSize() != 1) {
				listOfHaffmanTrees.sort();
				listOfHaffmanTrees.push(new HaffmanTree(listOfHaffmanTrees.pop(0), listOfHaffmanTrees.pop(1)));
			}

			HaffmanTree* haffmanTree = listOfHaffmanTrees.pop(0);


			haffmanTree->RLK(haffmanTree->getRoot());

			RBTree<char, string> haffmanTable;
			haffmanTree->toRbTree(&haffmanTable, haffmanTree->getRoot());

			Assert::IsTrue(haffmanTable.find('h') == "0" && haffmanTable.find('u') == "11" && haffmanTable.find('m') == "10");
		}
	};
}
