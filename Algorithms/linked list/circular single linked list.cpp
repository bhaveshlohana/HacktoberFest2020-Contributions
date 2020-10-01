#include <bits/stdc++.h>
using namespace std;
typedef int infotype;
typedef struct TElmtList *address;
typedef struct TElmtList{
    infotype info;
    address next;
}ElmtList;

typedef struct List{
    address first;
};
void CreateEmpty(List *L){
    (*L).first=NULL;
}
bool isEmpty(List L){
    return ((L).first==NULL);
}
address Allocation(infotype x){
    address NewElmt;
    NewElmt = (ElmtList*) malloc (sizeof(ElmtList));
    NewElmt->info=x;
    NewElmt->next=NULL;
    return NewElmt;
}
void Deallocation(address hapus){
    free(hapus);
}
void InsertFirst(List *L, infotype x){
    address NewElmt;
    NewElmt = Allocation(x);
    if(NewElmt!=NULL){
        if(isEmpty((*L))){
            NewElmt->next=NewElmt;
            (*L).first=NewElmt;
        }else{
            NewElmt->next=(*L).first;
            address p=(*L).first;
            while(p->next!=(*L).first){
                p=p->next;
            }
            p->next=NewElmt;
            (*L).first=NewElmt;
        }
    }
}
void InsertAfter(address *PredElmt, infotype x){
    address NewElmt;
    NewElmt = Allocation(x);
    if(NewElmt!=NULL){
        NewElmt->next=(*PredElmt)->next;
        (*PredElmt)->next=NewElmt;
    }
}
void InsertLast(List *L, infotype x){
    if(isEmpty((*L))){
        InsertFirst(&(*L),x);
    }
    else{
        address temp;
        temp = (*L).first;
        while(temp->next!=(*L).first){
            temp=temp->next;
        }
        InsertAfter(&temp,x);
        temp=temp->next;
        temp->next=(*L).first;
    }
}
void DeleteFirst(List *L, infotype *hapus){
    if(!isEmpty(*L)){
        address temp;
        if(temp->next==(*L).first){
            temp = (*L).first;
            temp->next=NULL;
            (*L).first=NULL;
            Deallocation(temp);
        }else{
            temp=(*L).first;
            while(temp->next!=(*L).first){
                temp=temp->next;
            }
            temp->next=(*L).first->next;
            (*L).first->next=NULL;
            Deallocation((*L).first);
            (*L).first=temp->next;
        }
    }
}
void DeleteAfter(address pred, infotype *hapus){
    if(pred->next!=NULL){
        address temp;
        temp=pred->next;
        *hapus=temp->info;
        pred->next=temp->next;
        temp->next=NULL;
        Deallocation(temp);
    }
}
void DeleteLast(List *L, infotype *hapus){
    if(!isEmpty(*L)){
        address temp, predTemp;
        predTemp = NULL;
        temp = (*L).first;
        while(temp->next!=(*L).first){
            predTemp=temp;
            temp=temp->next;
        }
        if(temp==(*L).first){
            DeleteFirst(&(*L), &(*hapus));
        }else{
            DeleteAfter(predTemp, &(*hapus));
            predTemp->next=(*L).first;
        }
    }
}
void printInfo (List L){
	/*	I.S. List mungkin kosong
		F.S. Jika list tidak kosong,
		Semua info yg disimpan pada elemen list diprint dengan format [elemen-1, elemen-2, elemen-3, ...]
		Jika list kosong, hanya menuliskan "[]"
	*/
	cout<<"[";
	if(!isEmpty(L)){
		address P = L.first;
		while(P->next!=L.first){
			cout<<P->info<<", ";
			P = P->next;
		}
		cout<<P->info;
	}
	cout<<"]"<<endl;
}
int main(){
	List L;
	CreateEmpty(&L);

	//Soal A
	int n,x;
	cin>>n;
	for (int i =0;i<n;i++){
		cin>>x;
		InsertLast(&(L),x);
	}
	printInfo(L);
}
