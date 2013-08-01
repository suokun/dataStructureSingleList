//
//  ListNode.h
//  SingleList
//
//  Created by Suo Kun on 8/1/13.
//  Copyright (c) 2013 Suo Kun. All rights reserved.
//

#ifndef SingleList_ListNode_h
#define SingleList_ListNode_h

using namespace std;

template<typename Type> class SingleList;

template<typename Type> class ListNode{
private:
	friend class SingleList<Type>;
    
	ListNode():nextNode(NULL){}
	
        ListNode(const Type item,ListNode<Type> *next=NULL):nodeData(item),nextNode(next){}
	
        ~ListNode(){
		nextNode=NULL;
	}
    
public:
	Type GetData();
        friend ostream& operator<< <Type>(ostream& ,ListNode<Type>&);

private:
	Type nodeData;
	ListNode *nextNode;
};


template<typename Type> Type ListNode<Type>::GetData(){
	return this->nodeData;
}


template<typename Type> ostream& operator<<(ostream& os,ListNode<Type>& out){
	os<<out.GetData();
	return os;
}

#endif
