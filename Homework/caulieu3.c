/*Cài đặt giải thuật để in ra 2 đa thức */


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float coef; //Hệ số
    int exp; //Số mũ
    Node *link; //Con trỏ dạng Node
} Node; //Tạo struct tên Node mới

typedef struct {
    Node *first; 
    Node *last; //Khởi tạo con trỏ dạng Node để 1 cái trỏ vào vị trí Node đầu của List và 1 cái vào cuối List
} List; //Tạo struct tên List

void init(List *list) { //Khởi tạo List
    list->first = NULL;   
    list->last = NULL; //Cho con trỏ đầu và cuối của List lúc này là Null, vì chưa có Node nào 
}

Node* create_Node(float coef, int exp) {
    Node *newnode = (Node*)malloc(sizeof(Node)); //Tạo một con trỏ kiểu Node tên newnode, sau đó cấp phát một vùng nhớ cho đối tượng Node và gán địa chỉ của nó vào newnode
    newnode->coef = coef;
    newnode->exp = exp;
    newnode->link = NULL; //3 dòng trên để gán giá trị hệ số, số mũ cho trường coef và exp của Node mới, và khởi tạo con trỏ link của node này là null
    return newnode; //Trả về con trỏ newnode, trỏ tới vùng nhớ của node vừa được cấp phát và khởi tạo.
} 

void insert_Node(List *list, float coef, int exp) {
    Node* newNode = createNode(coef, exp); //Khởi tạo một node mới và lưu địa chỉ vào con trỏ newNode
    if (list->first == NULL || list->first->exp < exp) { //Điều kiện để Node mới tạo lên đầu List là con trỏ trỏ vị trí đầu của list đang là Null hoặc hệ số exponent của phần tử đầu tiên của list nhỏ hơn của Node đang cần thêm
        newNode->link = list->first; //Con trỏ link của newNode trỏ vào vị trí đầu tiên của list
        list->first = newNode; //Con trỏ first(trỏ vị trí đầu của list) lúc này sẽ cho trỏ vào cái node mà mình vừa thêm -> nghĩa là node vừa thêm được làm node đầu tiên của list
        if (list->last == NULL) list->last = newNode; //Nếu List lúc này mới chỉ có 1 Node(newNode) mình vừa thêm tức con trỏ last của List vẫn đang là Null -> cho nó trỏ vào Node duy nhất này (vừa là đầu vừa là cuối), và để sau này khi Node này không còn là Node đầu thì nó vẫn là Node cuối của List
    } else {
        Node* current = list->first; 
        while (current->link != NULL && current->link->exp > exp) {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
        if (newNode->link == NULL) list->last = newNode;
    }
}




int main() {

    return 0;
}