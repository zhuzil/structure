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
	while (cur != nullptr) {//�����ҵ����и����������λ��
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
	head2 = tmp2->next;//Ȼ��ͷ�ڵ�2�ž���n����һ�����
	if (head2 == nullptr)return true;
	tail2 = tail;//β��2�ž�����ǰ��β
	tmp2->next = tmp1;//nָ��m
	tail->next = tmp1;//��ǰ��β��Ҳָ��m
	tail = tmp2;//��ǰ��β����Ϊ�˽��n��λ��
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
	if (tmp1 == nullptr && tmp2 == nullptr) {//��������ֱ��
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
	else if (tmp1 != nullptr && tmp2 != nullptr) {//������
		tmp1 = tmp1->next;//��1���
		tmp2 = tmp2->next;//��2���

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