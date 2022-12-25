#include "pch.h"

#include<iostream>
#include "linklist.h"

using namespace std;

void mylist::de_list(node* hh) {
	while (hh != nullptr) {
		node* cur = hh;
		hh = hh->next;
		delete cur;
		cur = nullptr;
	}
}
bool mylist::insert(int a) {
	if (head == nullptr) {
		head = new node(a);
		tail = head;
		if (tail == nullptr)return false;

		size++;
		return true;
	}

	node* tmp = new node(a);
	tail->next = tmp;
	tail = tmp;
	if (tail == nullptr)return false;

	size++;
	return true;
}

bool mylist::split(int a, int b) {
	node* tmp1 = nullptr;
	node* tmp2 = nullptr;
	node* cur = head;
	while (cur != nullptr) {//首先找到待切割的两个结点的位置
		if (cur->val == a && tmp1 == nullptr) {
			tmp1 = cur;
		}
		if (cur->val == b) {
			tmp2 = cur;
			break;
		}
		cur = cur->next;
	}
	if (tmp1 == nullptr || tmp2 == nullptr)return false;
	head2 = tmp2->next;//然后头节点2号就是n的下一个结点
	if (head2 == nullptr)return true;
	tail2 = tail;//尾部2号就是以前的尾
	tmp2->next = tmp1;//n指向m
	tail->next = tmp1;//以前的尾部也指向m
	tail = tmp2;//以前的尾部成为了结点n的位置
	return true;
}


node* mylist::ishuan(node* p) {

	node* tmp1 = p;
	node* tmp2 = p;
	while (tmp1 != nullptr&&tmp2!=nullptr) {
		tmp1 = tmp1->next;

		tmp2 = tmp2->next;
		if (tmp2 == nullptr)return nullptr;
		else {
			tmp2 = tmp2->next;
		}

		if (tmp1 == tmp2) { 
			
			return getrukou(tmp1,p);
		}
	}
	
	return nullptr;
	
}

node* mylist::getrukou(node* p2, node* p) {
	node* p1 = p;
	node* pn = nullptr;
	while (p1 != p2) {
		pn = p2;
		p1 = p1->next;
		p2 = p2->next;
	}

	return pn;
}

node* mylist::huanyuan() {
	if (head == nullptr || head2 == nullptr)return nullptr;
	tail->next = head2;
	tail2->next = nullptr;
	tail = tail2;
	tail2 = nullptr;
	head2 = nullptr;
	
	node* low = head;
	node* fast = head;

	while (fast != nullptr) {
		fast = fast->next;
		if (fast != nullptr) {
			low = low->next;
			fast = fast->next;
		}
	}

	return low;
}

node* mylist::checkxj(node* p1, node* p2) {
	if (p1 == nullptr || p2 == nullptr)return nullptr;
	node* tmp1 = ishuan(p1);
	node* tmp2 = ishuan(p2);
	if (tmp1 == nullptr && tmp2 == nullptr) {//两个都是直链
		node* a = p1;
		node* b = p2;

		while (a->next != nullptr) {
			a = a->next;
		}

		while (b->next != nullptr) {
			b = b->next;
		}

		if (a == b) {
			return a;
		}
		else {
			return nullptr;
		}

	}
	else if (tmp1 != nullptr && tmp2 != nullptr) {//两个环
		tmp1 = tmp1->next;//环1入口
		tmp2 = tmp2->next;//环2入口

		int tag = 0;

		node* cur = p2;
		while (cur != nullptr && tag != 2) {
			if (cur == tmp2)tag++;
			if (cur == tmp1)return tmp1;
			cur = cur->next;
		}

	}

	return nullptr;
}