#include "pch.h"
#include<iostream>

using namespace std;

class node {
public:
	int val;
	node* next;
	node():val(-1),next(nullptr){}
	node(int a) :val(a),next(nullptr) {}
	~node(){}
};

class mylist {
public:


	void de_list(node* head);
	mylist() {}
	~mylist() { 
		de_list(head); 
		de_list(head2);
	}
	bool insert(int a);
	bool split(int a, int b);
	node* ishuan(node* p);
	node* getrukou(node* p2, node* p);
	node* huanyuan();
	node* checkxj(node* p1,node* p2);

	
	node* head = nullptr;//最开始的头部
	node* head2 = nullptr;//第二个头部
	node* tail = nullptr;//最开始的尾部
	node* tail2 = nullptr;//第二个尾部
	int size = 0; //单链表的长度

};