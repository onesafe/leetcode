#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <string.h>
#include <stdio.h>

using namespace std;

typedef struct ListNode{
	int val;
	struct ListNode *next;
}node;

node *addTwoNumbers(node *l1, node *l2){
    
    node *ret, *s, *p, *t, *q;
    ret = (node *)malloc(sizeof(node));
    ret->next = NULL;
    p = ret;
    t = l1;
    q = l2;
    int temp = 0, up = 0, real = 0;
    while(t != NULL && q != NULL){
        temp = t->val + q->val + up;
        if(temp < 10){
            real = temp;
            up = 0;
        }else{
            real = temp%10;
            up = 1;
        }

        s = (node *)malloc(sizeof(node));
        s->val = real;
        s->next = NULL;

        p->next = s;
        p = s;

        t = t->next;
        q = q->next;
    }


    while(t != NULL){
        s = (node *)malloc(sizeof(node));
        temp = t->val + up;
        if(temp < 10){
            real = temp;
            up = 0;
        }else{
            real = temp%10;
            up = 1;
        }

        s->val = real;
        s->next = NULL;

        p->next = s;
        p = s;
        t = t->next;
    }

    while(q != NULL){
        s = (node *)malloc(sizeof(node));
        temp  = q->val + up;
        if(temp < 10){
            real = temp;
            up = 0;
        }else{
            real = temp%10;
            up = 1;
        }

        s->val = real;
        s->next = NULL;

        p->next = s;
        p = s;
        q = q->next;
    }

    if(t == NULL && q == NULL && up == 1){
        s = (node *)malloc(sizeof(node));
        s->val = up;
        s->next = NULL;

        p->next = s;
        p = s;
    }
    
    return ret->next;
}

int main(){

    int n =0, m = 0, num = 0, val = 0;
    node *l1, *l2, *p, *q, *ret;
    node *temp;
    cout<< "please input l1 node  number ";
    cin>>n;
    l1 = (node *)malloc(sizeof(node));
    l1->next = NULL;
    temp = l1;
    while(n--){
        cout<<"input: ";
        p = (node *)malloc(sizeof(node));
        cin>>val;
        p->val = val;
        p->next = temp->next;
        temp->next = p;
    }
    

    cout<<"please input l2 node number: ";
    cin>>m;
    l2 = (node *)malloc(sizeof(node));
    l2->next = NULL;
    temp = l2;
    while(m--){
        cout<<"input: ";
        p = (node *)malloc(sizeof(node));
        cin>>val;
        p->val = val;
        p->next = temp->next;
        temp->next = p;
    }
/*
    ret = l1->next;
    while(ret != NULL){
        cout<<ret->val;
        ret = ret->next;
        if(ret != NULL){
            cout<<" -> ";
        }
    }
    cout<<endl;
    ret = l2->next;
    while(ret != NULL){
        cout<<ret->val;
        ret = ret->next;
        if(ret != NULL){
            cout<<" -> ";
        }
    }
    cout<<endl;
*/
    p = l1->next;
    q = l2->next;
    ret = addTwoNumbers(p, q);
    while(ret != NULL){
        cout<<ret->val;
        ret = ret->next;
        if(ret != NULL){
            cout<<" -> ";
        }
    }
    cout<<endl; 
}
