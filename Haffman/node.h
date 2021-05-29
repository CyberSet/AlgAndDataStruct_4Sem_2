#pragma once
#include <string>
#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H
#define black false
#define red true
template<class T1, class T2>
class node {
private:
	T1 key;
	T2 value;
	node<T1, T2>* parent;
	bool color; // false - black, true - red
	node<T1, T2>* left, * right;
public:
	node() {
		parent = nullptr;
		color = red;
		left = nullptr;
		right = nullptr;
	}

	node(T1 node_key, T2 node_value, node<T1, T2>* node_parent = nullptr, node<T1, T2>* node_leftChild = nullptr, node<T1, T2>* node_rightChild = nullptr, bool node_color = red) {
		key = node_key;
		value = node_value;
		parent = node_parent;
		color = node_color;
		left = node_leftChild;
		right = node_rightChild;
	}

	node<T1, T2>& operator= (node<T1, T2> equated_node) {
		key = equated_node.key;
		value = equated_node.value;
		parent = equated_node.parent;
		color = equated_node.color;
		left = equated_node.left;
		right = equated_node.right;
	}

	friend bool operator> (const node<T1, T2>& firstCompared, const node<T1, T2>& secondCompared) {
		return firstCompared.key > secondCompared.key;
	}

	friend bool operator< (const node<T1, T2>& firstCompared, const node<T1, T2>& secondCompared) {
		return firstCompared.key < secondCompared.key;
	}

	friend bool operator== (const node<T1, T2>& firstCompared, const node<T1, T2>& secondCompared) {
		return firstCompared.key == secondCompared.key;
	}

	friend bool operator!= (const node<T1, T2>& firstCompared, const node<T1, T2>& secondCompared) {
		return firstCompared.key != secondCompared.key;
	}

	~node() {
		
	}

	T1 getKey() {
		return key;
	}

	T2 getValue() {
		return value;
	}

	void setParent(node<T1, T2>* node_parent) {
		parent = node_parent;
	}

	node<T1, T2>* getParent() {
		return parent;
	}

	void setLeftChild(node<T1, T2>* leftChild) {
		left = leftChild;
	}

	node<T1, T2>* getLeftChild() {
		return left;
	}

	void setRightChild(node<T1, T2>* rightChild) {
		right = rightChild;
	}

	node<T1, T2>* getRightChild() {
		return right;
	}

	bool isRed() {
		return color;
	}

	void setColor(bool node_color) {
		color = node_color;
	}

	void changeColor() {
		color = !color;
	}

	void showInfo() {
		cout << "Элемент с ключом " << key << " и значением " << value << (isRed() ? " красного " : " черного ") << "цвета, предок с ключом " << parent->key << ", левый ребенок с ключом " << left->key << ", правый ребенок с ключом " << right->key << endl;
	}
	
	void print(node<T1, T2>* nil) {
		showInfo();
		if (left != nil) left->print(nil);
		if (right != nil) right->print(nil);
	}
};
#endif