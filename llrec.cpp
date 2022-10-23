#include "llrec.h"
#include<bits/stdc++.h>
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
  if (head==nullptr){
  	smaller = nullptr;
  	larger = nullptr;
  	return;
  }
  Node* temp = head->next;
  if (head->val <= pivot){
    smaller = head;
    Node* temp1 = smaller;
    llpivot(temp, smaller->next, larger, pivot);
    smaller = temp1;
  }else{
    larger = head;
    Node* temp1 = larger;
    llpivot(temp, smaller, larger->next, pivot);
    larger = temp1;
  }
  head = temp;
  return;
}
template <typename Comp>
Node* llfilter(Node* head, Comp pred){
  if (head==nullptr) return nullptr;
  if (!pred(head->val)){
  	Node* p = head;
  	p->next = llfilter(head->next, pred);
  	return p;
  }else{
  	Node* temp = head->next;
  	delete head;
  	head = temp;
  	return llfilter(head, pred);
  }
}


