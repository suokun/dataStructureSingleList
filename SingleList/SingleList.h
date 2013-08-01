//
//  SingleList.h
//  SingleList
//
//  Created by Suo Kun on 8/1/13.
//  Copyright (c) 2013 Suo Kun. All rights reserved.
//

#ifndef SingleList_SingleList_h
#define SingleList_SingleList_h

#include "ListNode.h"

template<typename Type> class SingleList{
public:
	SingleList():head(new ListNode<Type>()){}
	~SingleList(){
		MakeEmpty();
		delete head;
	}
    
public:
    void MakeEmpty();                       //make the list empty
	int Length();                           //get the length
	ListNode<Type> *Find(Type value,int n); //find thd nth data which is equal to value
	ListNode<Type> *Find(int n);            //find the nth data
	bool Insert(Type item,int n=0);         //insert the data in the nth position
	Type Remove(int n=0);                   //remove the nth data
	bool RemoveAll(Type item);              //remove all the data which is equal to item
	Type Get(int n);                        //get the nth data
	void Print();                           //print the list
    
private:
	ListNode<Type> *head;
};


template<typename Type> void SingleList<Type>::MakeEmpty(){
	ListNode<Type> *pdel;
	while(head->nextNode!=NULL){
		pdel=head->nextNode;
		head->nextNode=pdel->nextNode;
		delete pdel;
	}
}


template<typename Type> int SingleList<Type>::Length(){
	ListNode<Type> *pmove=head->nextNode;
	int count=0;
	while(pmove!=NULL){
		pmove=pmove->nextNode;
		count++;
	}
	return count;
}


template<typename Type> ListNode<Type>* SingleList<Type>::Find(int n){
	if(n<0){
		cout<<"The n is out of boundary"<<endl;
		return NULL;
	}
	ListNode<Type> *pmove=head->nextNode;
	for(int i=0;i<n&&pmove;i++){
		pmove=pmove->nextNode;
	}
	if(pmove==NULL){
		cout<<"The n is out of boundary"<<endl;
		return NULL;
	}
	return pmove;
}


template<typename Type> ListNode<Type>* SingleList<Type>::Find(Type value,int n){
	if(n<1){
		cout<<"The n is illegal"<<endl;
		return NULL;
	}
	ListNode<Type> *pmove=head;
	int count=0;
	while(count!=n&&pmove){
		pmove=pmove->nextNode;
		if(pmove->nodeData==value){
			count++;
		}
	}
    if(pmove==NULL){
		cout<<"can't find the element"<<endl;
		return NULL;
	}
	return pmove;
}


template<typename Type> bool SingleList<Type>::Insert(Type item, int n){
	if(n<0){
		cout<<"The n is illegal"<<endl;
		return 0;
	}
	ListNode<Type> *pmove=head;
	ListNode<Type> *pnode=new ListNode<Type>(item);
	if(pnode==NULL){
		cout<<"Application error!"<<endl;
		return 0;
	}
	for(int i=0;i<n&&pmove;i++){
		pmove=pmove->nextNode;
	}
	if(pmove==NULL){
		cout<<"the n is illegal"<<endl;
		return 0;
	}
	pnode->nextNode=pmove->nextNode;
	pmove->nextNode=pnode;
    return 1;
}


template<typename Type> bool SingleList<Type>::RemoveAll(Type item){
	ListNode<Type> *pmove=head;
	ListNode<Type> *pdel=head->nextNode;
	while(pdel!=NULL){
		if(pdel->nodeData==item){
			pmove->nextNode=pdel->nextNode;
			delete pdel;
			pdel=pmove->nextNode;
			continue;
		}
		pmove=pmove->nextNode;
		pdel=pdel->nextNode;
	}
	return 1;
}


template<typename Type> Type SingleList<Type>::Remove(int n){
	if(n<0){
		cout<<"can't find the element"<<endl;
		exit(1);
	}
	ListNode<Type> *pmove=head,*pdel;
	for(int i=0;i<n&&pmove->nextNode;i++){
		pmove=pmove->nextNode;
	}
	if(pmove->nextNode==NULL){
		cout<<"can't find the element"<<endl;
		exit(1);
	}
	pdel=pmove->nextNode;
	pmove->nextNode=pdel->nextNode;
	Type temp=pdel->nodeData;
	delete pdel;
	return temp;
}


template<typename Type> Type SingleList<Type>::Get(int n){
	if(n<0){
		cout<<"The n is out of boundary"<<endl;
		exit(1);
	}
	ListNode<Type> *pmove=head->nextNode;
	for(int i=0;i<n;i++){
		pmove=pmove->nextNode;
		if(NULL==pmove){
			cout<<"The n is out of boundary"<<endl;
			exit(1);
		}
	}
	return pmove->nodeData;
}


template<typename Type> void SingleList<Type>::Print(){
	ListNode<Type> *pmove=head->nextNode;
	cout<<"head";
	while(pmove){
		cout<<"--->"<<pmove->nodeData;
		pmove=pmove->nextNode;
	}
	cout<<"--->over"<<endl<<endl<<endl;
}

#endif
