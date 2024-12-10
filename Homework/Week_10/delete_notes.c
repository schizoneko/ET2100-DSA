/*Cài đặt giải thuật xoá node trong 1 danh sách ở 3 vị trí: 
Đầu danh sách, cuối danh sách và sau 1 node cho trước*/


//References: 
//Đã sử dụng ChatGPT để thiết kế hàm main() tránh muộn thời gian nộp


#include <stdio.h>
#include <stdlib.h>

typedef struct Node { //Tạo struct Node
    int data;
    struct Node *next;
} Node;

typedef struct List { //Tạo struct List
    Node *first;
    Node *last;
} List;

void init_List(List *list) { //Hàm khởi tạo List
    list->first = NULL;
    list->last = NULL;
}

Node* create_Node(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node)); //Tạo một con trỏ kiểu Node tên newnode, sau đó cấp phát một vùng nhớ cho đối tượng Node và gán địa chỉ của nó vào newNode
    Node->data = data;
    Node->next = NULL;
    return newNode; //Trả về con trỏ newNode trỏ tới vùng nhớ của node vừa được cấp phát và khởi tạo.
}

void insert_Node_last(List* list, int data) { //Thêm Node vào last
    Node *newNode = create_Node(data); //Phải có Node trước đã

    if (list->first == NULL) { //Trường hợp List không có Node thì cho con trỏ first và last của List vào Node mới này
        list->first = newNode;
        list->last = newNode;
    }
    else { 
        list->last->next = newNode; //Nếu đã có Node thì cho con trỏ next của Node cuối trỏ vào Node mới
        list->last = newNode; //Sau đó cho con trỏ last trỏ vào đánh dấu Node mới thêm là Node cuối
    }
}

void delete_Node_first(List* list) {
    if (list->first == NULL) { //Đầu tiên vẫn phải check xem List có phần tử hay không
        printf("Danh sách rỗng.\n");
        return; //Rỗng thì out luôn
    }

    if (list->first == list->last) { //Trường hợp List chỉ có 1 Node
        free(list->first); //Giải phóng luôn 
        list->first = NULL;
        list->last = NULL;
        return; //Sau đó cập nhật list về trạng thái NULL và out
    }

    Node* temp = list->first; //Lưu lại địa chỉ của Node đầu tiên trong danh sách để free nếu không sẽ mất dấu nó và rò rỉ bộ nhớ
    list->first = list->first->next; //gán con trỏ first của list (lúc này đang trỏ vào Node đầu) sang Node thứ 2

    free(temp); //Giải phóng vùng dữ liệu mà temp trỏ tới (lúc này đang là Node 1 cũ)
    printf("Đã xóa Node đầu!"); //Chỉ để đánh dấu nếu hàm hoạt động thôi
}

void delete_Node_last(List *list) {
    if (list->first == NULL) { //Tương tự
        printf("Danh sách rỗng.\n");
        return;
    }

    if (list->first == list->last) { //Cũng tương tự
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        return;
    }

    //Khởi tạo một con trỏ làm biến chạy current để duyệt đến phần tử áp chót
    Node *current = list->first;
    while (current->next != list->last) {
        current = current->next;
    }

    free(list->last); //Sau khi tìm được phần tử áp chót rồi sẽ giải phóng Node cuối cùng
    current->next = NULL; //Rồi cho next của phần tử áp chót nãy mình đánh dấu vào NULL -> giờ nó thành node cuối
    list->last = current; //Đánh dấu rằng đây là node cuối
    printf("Đã xóa node cuối!.\n");
}

void delete_Node_next(List *list, Node *prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) { 
        printf("ERROR.\n");
        return;
    }

    Node *temp = prevNode->next;
    prevNode->next = temp->next;

    // Nếu node bị xóa là node cuối cùng, cập nhật lại `last`
    if (temp == list->last) {
        list->last = prevNode;
    }

    free(temp);
    printf("Đã xóa Node sau Node mang data: %d.\n", prevNode->data);
}

void display_List(List *list) {
    Node *current = list->first;
    if (current == NULL) {
        printf("Danh sách rỗng.\n");
        return;
    }

    printf("Danh sách: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    List list;
    init_List(&list);

    // Thêm các phần tử vào danh sách
    insert_Node_last(&list, 10);
    insert_Node_last(&list, 20);
    insert_Node_last(&list, 30);
    insert_Node_last(&list, 40);

    // Hiển thị danh sách ban đầu
    printf("Danh sách ban đầu:\n");
    display_List(&list);

    // Xóa node đầu tiên
    delete_Node_first(&list);
    printf("Sau khi xóa node đầu tiên:\n");
    display_List(&list);

    // Xóa node cuối cùng
    delete_Node_last(&list);
    printf("Sau khi xóa node cuối cùng:\n");
    display_List(&list);

    // Xóa node sau node có giá trị 20
    Node *current = list.first;
    while (current != NULL && current->data != 20) {
        current = current->next;
    }
    delete_Node_next(&list, current);
    printf("Sau khi xóa node sau node có giá trị 20:\n");
    display_List(&list);

    return 0;
}

