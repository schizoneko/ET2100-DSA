/*Cài đặt giải thuật để in ra 2 đa thức và tổng của 2 đa thức*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float coef; //Hệ số
    int exp; //Số mũ
    struct Node *link; //Con trỏ dạng Node
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
    Node* newNode = create_Node(coef, exp); //Khởi tạo một node mới và lưu địa chỉ vào con trỏ newNode
    
    if (list->first == NULL || list->first->exp < exp) { //Điều kiện để Node mới tạo lên đầu List là con trỏ trỏ vị trí đầu của list đang là Null hoặc hệ số exponent của phần tử đầu tiên của list nhỏ hơn của Node đang cần thêm
        newNode->link = list->first; //Con trỏ link của newNode trỏ vào vị trí đầu tiên của list
        list->first = newNode; //Con trỏ first(trỏ vị trí đầu của list) lúc này sẽ cho trỏ vào cái node mà mình vừa thêm -> nghĩa là node vừa thêm được làm node đầu tiên của list
        if (list->last == NULL) list->last = newNode; //Nếu List lúc này mới chỉ có 1 Node(newNode) mình vừa thêm tức con trỏ last của List vẫn đang là Null -> cho nó trỏ vào Node duy nhất này (vừa là đầu vừa là cuối), và để sau này khi Node này không còn là Node đầu thì nó vẫn là Node cuối của List
    }
    else {
        Node* current = list->first; //Tạo con trỏ current để duyệt List, tránh thay đổi vị trí của first và last, cho current bắt đầu từ first
        
        while (current->link != NULL && current->link->exp > exp) {
            current = current->link;
        } //Cho con trỏ current chạy qua List với điều kiện exponent của Node tiếp theo lớn hơn exponent của newNode (tức là đang bị ngược và đảo lại sắp xếp cho số mũ giảm dần) thì dịch con trỏ sang Node tiếp theo
        //Sẽ có 2 trường hợp thoát vòng while mà mình cần xét là trường hợp số mũ của node đằng sau current với newNode là bằng nhau hoặc bé hơn
        if (current->link != NULL && current->link->exp == exp) {
            //Nếu số mũ bằng nhau thì cộng hệ số
            current->link->coef += coef;
            free(newNode); //cộng hệ số xong thì giải phóng newNode tại không dùng nữa
        } 
        else {
            //Trường hợp còn lại là số mũ của newNode lớn hơn node mà current chỉ vào, tức là newNode đang ở đúng vị trí -> chèn luôn
            newNode->link = current->link;
            current->link = newNode; //2 dòng trên tương tự chèn vào đầu, nhưng thay vì chèn vào đầu thì nó là chèn vào current mà không thỏa mãn điều kiện vòng while ở trên (tức hiện tại số mũ của newNode lớn hơn số mũ của node đằng sau current)
            if (newNode->link == NULL) list->last = newNode; //Nếu dừng ở nút cuối cùng (tức exponent của newNode đang bé nhất) thì coi nó là node cuối luôn
        }
    }
}

void input_Polynomial(List *poly) {
    int n; //n sẽ là số hệ số trong 1 đa thức
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        float coef;
        int exp;

        printf("Enter the coefficient and exponent of term %d:\n", i + 1);
        printf("Coefficient: ");
        scanf("%f", &coef);
        printf("Exponent: ");
        scanf("%d", &exp);

        insert_Node(poly, coef, exp);
    } //Vòng lặp số số hạng có trong 1 phương trình, với mỗi phần tử là 1 Node và được khởi tạo bởi hàm insert_Node ngay sau khi nhập coef và exp
}

void print_Polynomial(List *list) {
    Node* current = list->first; //Tạo 1 con trỏ Node current cho nó trỏ vào giá trị đầu tiên
    while (current != NULL) {
        if (current->coef > 0 && current != list->first) {
            printf(" + ");
        }
        if (current->exp == 0) {
            printf("%.1f", current->coef);
        } 
        else if (current->exp == 1) {
            printf("%.1fx", current->coef);
        } 
        else {
            printf("%.1fx^%d", current->coef, current->exp);
        }
        current = current->link;
    } //Cho con trỏ current chạy qua List, tức duyệt qua cái đa thức đấy
    printf("\n"); //Và in đa thức dưới dạnga x^n + bx^(n-1) + ... + cx + d
}

Node* add_Polynomial(List *poly1, List *poly2) {
    List sum; 
    init(&sum);

    Node *p1 = poly1->first;
    Node *p2 = poly2->first;

    while (p1 != NULL || p2 != NULL) {
        float coef;
        int exp;

        if (p1 == NULL) { 
            // Nếu chỉ còn giá trị của đa thức 2 thì thêm trực tiếp vào tổng
            coef = p2->coef;
            exp = p2->exp;
            p2 = p2->link;
        }
        else if (p2 == NULL) {
            // Nếu chỉ còn giá trị của đa thức 1 thì thêm trực tiếp vào tổng
            coef = p1->coef;
            exp = p1->exp;
            p1 = p1->link;
        }
        else if (p1->exp > p2->exp) {
            // Nếu bậc của p1 lớn hơn, thêm giá trị của p1 vào tổng và di chuyển p1
            coef = p1->coef;
            exp = p1->exp;
            p1 = p1->link;
        } 
        else if (p1->exp < p2->exp) {
            // Nếu bậc của p2 lớn hơn, thêm giá trị của p2 vào tổng và di chuyển p2
            coef = p2->coef;
            exp = p2->exp;
            p2 = p2->link;
        } 
         else {
            // Nếu bậc của p1 và p2 bằng nhau, cộng hệ số và thêm vào tổng nếu khác 0
            coef = p1->coef + p2->coef;
            exp = p1->exp;

            // Lưu trữ các Node hiện tại để có thể giải phóng bộ nhớ nếu cần
            Node* temp1 = p1;
            Node* temp2 = p2;
            p1 = p1->link;
            p2 = p2->link;

            if (coef == 0) {
                free(temp1);  // Giải phóng bộ nhớ cho Node có hệ số bằng 0
                free(temp2);
                continue;  // Bỏ qua bước chèn và tiếp tục vòng lặp
            }
        }

        if (coef != 0) {
            insert_Node(&sum, coef, exp); // Thêm hệ số và bậc vào tổng
        }
    }

    return sum.first; // Trả về con trỏ đầu của danh sách kết quả
}


int main() {
    List poly1, poly2, sum;  // Khởi tạo List
    init(&poly1);
    init(&poly2);
    init(&sum);

    printf("Enter the first polynomial\n");
    input_Polynomial(&poly1);
    printf("Enter the second polynomial\n");
    input_Polynomial(&poly2);

    printf("First polynomial: ");
    print_Polynomial(&poly1);
    printf("Second polynomial: ");
    print_Polynomial(&poly2);

    printf("The sum of these polynomials is: ");
    sum.first = add_Polynomial(&poly1, &poly2);
    print_Polynomial(&sum);

    return 0;
}