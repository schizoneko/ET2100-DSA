#include<iostream>
using namespace std;
struct Node{
    int infor;
    Node*next; 
};
// dat ten 
typedef Node*PNode; 
typedef Node* LinkedList;
// khai bao danh sach 
void initList(LinkedList& list){
    list = NULL; 
}
// kiem tra danh sach rong
int isEmpty(LinkedList list){
    return (list==NULL); 
}
// bo sung phan tu vao dau danh sach
void insertBegin(LinkedList &list, int k){
    Node*newNode =new Node; // tao mot node , moi dc cai thung phai dua gia tri vao 
    newNode->infor=k; // infor cua newnode
    //kiem tra neu rong thi sao
    if(isEmpty(list)){
      list=newNode;// hai con tro bang nhau thi nghia la cung tro ve 1 cho 
      newNode->next=NULL; 
      return; // khong co return la chay tiep , danh sach van rong van thuc hien ngoai if 
    }
    newNode->next=list; 
    list = newNode; 

}
void insertAfter(LinkedList & list, int k, PNode p){
    Node*newNode=new Node; 
    newNode->infor=k; 
    if(isEmpty(list)){// neu danh sach rong 
        list = newNode; 
        newNode->next=NULL; 
        return; 

    }
    if(p==NULL)
        return; 
    newNode->next=p->next; 
    p->next=newNode; 
}
// bosung phan tu k vao truoc phan tu duoc tro boi p
void insertBefore1(LinkedList & list, int k, PNode p){
    Node*newNode =new Node; 
   if(isEmpty(list)){
    list =newNode;
    newNode->next=NULL; 
    return;
   }
   if(p==NULL) 
   return;
   // dat mot con tro trung gian
   Node*ptr=list;
   while(ptr!=NULL&&ptr->next!=p){
    ptr=ptr->next;
   }
   newNode->next=p;
   ptr->next=newNode; 
}
/*cach 2:
void insertBefore2(LinkedList & list, int k, PNode p){
  Node*newNode =new Node; 
   if(isEmpty(list)){
    list =newNode;
    newNode->next=NULL; 
    return;
   }
   if(p==NULL) 
   return;
   newNode->infor=p->infor;
   p->infor=k;
   newNode->next=p->next;
   p->next=newNode; 


}*/
PNode search(LinkedList list, int k){
    PNode ptr=list; 
    while (ptr!=NULL){
        if(ptr->infor==k){        /*cach viet khac
                                    while(ptr!=NULL&&ptr->infor!=k)
                                       ptr=ptr->next
                                    return ptr; */
            return ptr; 
        }
        else 
        ptr=ptr->next; 
    }
    return NULL; 
}
void hienThi(LinkedList list){
    if(isEmpty(list)){
        cout<<"\n danh sach rong!";
        return; 
    }
    cout<<"danh sach gom:"; 
    // khai bao mot con tro trung gian
    Node*ptr=list; 
    while(ptr!=NULL){
        cout<<ptr->infor<<"\t";
        ptr=ptr->next; 
    }
}
int main(){
    LinkedList l;
    initList(l);
    insertBegin(l,11);
    insertBegin(l,22);
    insertBegin(l,33);
    insertBegin(l,44);
    insertBegin(l,55);
    hienThi(l); 
    cout<<endl;
    // bo sung 88 vao sau 44 
    Node*temp=search(l,44);
    insertAfter(l,88,temp);
    hienThi(l); 
    cout<<endl; 
    // bo sung 88 vao truoc 44
    insertBefore1(l,99,temp);
    hienThi(l); 
    
}
