/* Trong siêu thị người ta xếp hàng để thực hiện thanh toán. 
Mỗi giỏ hàng với các hàng hoá được coi như một node trong một cấu trúc hàng đợi.
1. Khai báo cấu trúc hàng đợi. Các thông tin chứa ở mỗi node sinh viên tự đưa 
vào để đảm bảo các nội dung sau được thực hiện 
2. Loại bỏ từng người ra khỏi hàng đợi sau khi người đó đã thực hiện thanh toán xong 
3. Tính tổng số tiền mà thu ngân thu được tại quầy trong một phiên làm việc  
4. Xác định số lượng một sản phẩm A đã được bán tại quầy thu ngân
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Name {
    char Ho[100];
    char Dem[100];
    char Ten[100];
} Name;

typedef struct Date {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;
} Date;

typedef struct Price {
    float Cash;
    char currency[10];
} Price;

typedef struct Product {
    Price price;
    char Name[100];
    int quantity;
    struct Product* next;
} Product;

typedef struct Bill {
    Date payment_Date;
    Name customer_name;
    Product* product_list;
    float totalAmount; // Missing in your original code
    struct Bill* next;
} Bill;

typedef struct Queue {
    Bill* front;
    Bill* rear;
} Queue;

void init_Queue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(Queue* queue, Bill* newBill) {
    if (queue->rear == NULL) {
        queue->front = newBill;
        queue->rear = newBill;
    } else {
        queue->rear->next = newBill;
        queue->rear = newBill;
    }
    newBill->next = NULL;
}

Bill* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Hàng đợi rỗng.\n");
        return NULL;
    }
    Bill* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return temp;
}

Product* createProduct(const char* name, float price, const char* currency, int quantity) {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    if (!newProduct) {
        printf("Không thể cấp phát bộ nhớ cho sản phẩm.\n");
        return NULL;
    }
    strcpy(newProduct->Name, name);
    newProduct->price.Cash = price;
    strcpy(newProduct->price.currency, currency);
    newProduct->quantity = quantity;
    newProduct->next = NULL;
    return newProduct;
}

Bill* createBill(Name customerName, Date paymentDate, Product* productList) {
    Bill* newBill = (Bill*)malloc(sizeof(Bill));
    if (!newBill) {
        printf("Không thể cấp phát bộ nhớ cho hóa đơn.\n");
        return NULL;
    }
    newBill->customer_name = customerName;
    newBill->payment_Date = paymentDate;
    newBill->product_list = productList;
    newBill->totalAmount = 0;

    Product* current = productList;
    while (current != NULL) {
        newBill->totalAmount += current->price.Cash * current->quantity;
        current = current->next;
    }
    newBill->next = NULL;
    return newBill;
}

void displayQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Hàng đợi rỗng.\n");
        return;
    }

    Bill* currentBill = queue->front;
    printf("Danh sách hóa đơn trong hàng đợi:\n");

    while (currentBill != NULL) {
        // Hiển thị thông tin khách hàng
        printf("\nKhách hàng: %s %s %s\n", 
            currentBill->customer_name.Ho, 
            currentBill->customer_name.Dem, 
            currentBill->customer_name.Ten);

        // Hiển thị ngày thanh toán
        printf("Ngày thanh toán: %02d/%02d/%04d %02d:%02d:%02d\n",
            currentBill->payment_Date.day,
            currentBill->payment_Date.month,
            currentBill->payment_Date.year,
            currentBill->payment_Date.hour,
            currentBill->payment_Date.minute,
            currentBill->payment_Date.second);

        // Hiển thị danh sách sản phẩm
        printf("Danh sách sản phẩm:\n");
        Product* currentProduct = currentBill->product_list;
        while (currentProduct != NULL) {
            printf("  - Tên sản phẩm: %s\n", currentProduct->Name);
            printf("    Giá: %.2f %s\n", currentProduct->price.Cash, currentProduct->price.currency);
            printf("    Số lượng: %d\n", currentProduct->quantity);
            currentProduct = currentProduct->next;
        }

        // Hiển thị tổng tiền
        printf("Tổng số tiền: %.2f %s\n", currentBill->totalAmount, currentBill->product_list->price.currency);

        currentBill = currentBill->next; // Chuyển sang hóa đơn tiếp theo
    }
}


int main() {
    Queue queue;
    init_Queue(&queue);

    // Tạo danh sách sản phẩm cho hóa đơn 1
    Product* product1 = createProduct("Apple", 10.0, "VND", 3);
    Product* product2 = createProduct("Banana", 5.0, "VND", 2);
    product1->next = product2;

    // Tạo hóa đơn 1
    Name customer1 = {"Nguyen", "Van", "A"};
    Date date1 = {19, 11, 2024, 10, 30, 0};
    Bill* bill1 = createBill(customer1, date1, product1);

    // Thêm hóa đơn vào hàng đợi
    enqueue(&queue, bill1);

    // Tạo danh sách sản phẩm cho hóa đơn 2
    Product* product3 = createProduct("Orange", 7.0, "VND", 4);
    Product* product4 = createProduct("Mango", 15.0, "VND", 1);
    product3->next = product4;

    // Tạo hóa đơn 2
    Name customer2 = {"Le", "Thi", "B"};
    Date date2 = {19, 11, 2024, 11, 0, 0};
    Bill* bill2 = createBill(customer2, date2, product3);

    // Thêm hóa đơn vào hàng đợi
    enqueue(&queue, bill2);

    // Hiển thị danh sách hóa đơn trong hàng đợi
    displayQueue(&queue);

    // Loại bỏ hóa đơn đầu tiên
    Bill* removedBill = dequeue(&queue);
    if (removedBill) {
        printf("Đã xóa hóa đơn của khách hàng: %s %s\n", removedBill->customer_name.Ho, removedBill->customer_name.Dem, removedBill->customer_name.Ten);
        free(removedBill);
    }

    return 0;
}

