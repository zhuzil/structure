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

	
	node* head = nullptr;//�ʼ��ͷ��
	node* head2 = nullptr;//�ڶ���ͷ��
	node* tail = nullptr;//�ʼ��β��
	node* tail2 = nullptr;//�ڶ���β��
	int size = 0; //������ĳ���

};