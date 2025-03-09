# ASSIGNMENT 2

## 1. Ứng dụng Stack để kiểm tra tính hợp lệ của các cặp dấu ngoặc `()`
- Nhập vào một chuỗi ký tự từ bàn phím.
- Kiểm tra xem các dấu ngoặc trong chuỗi có được đóng mở hợp lệ hay không.
- Ví dụ:
  - **Hợp lệ**: `(()())`, `()()`
  - **Không hợp lệ**: `(()`, `())(`

---

## 2. Ứng dụng Stack để tính giá trị biểu thức hậu tố
- Tính giá trị của một biểu thức hậu tố chứa các toán hạng và các toán tử `+`, `-`, `*`, `:`, `^` (mũ).
- Ví dụ:
  - Biểu thức trung tố: `(3+4)*5 - (44+5)/3`
  - Biểu thức hậu tố tương ứng: `3 4 + 5 * 44 5 + 3 / -`

---

## 3. Ứng dụng Stack để kiểm tra tính đối xứng của một chuỗi
- Kiểm tra xem một chuỗi có đối xứng hay không (Palindrome).
- Ví dụ:
  - **Chuỗi đối xứng**: `11211`, `madam`, `racecar`
  - **Chuỗi không đối xứng**: `hello`, `stack`

---

## 4. Ứng dụng hàng đợi (Queue) để mô phỏng hoạt động của một máy in
- Mô phỏng hàng đợi tài liệu chờ in theo cơ chế FIFO (First In, First Out).

### Các thao tác chính:
- **Thêm tài liệu vào hàng đợi in (enqueue)**
- **In tài liệu theo thứ tự FIFO (dequeue)**
- **Hiển thị danh sách tài liệu chờ in**
- **Thoát chương trình**

### Cấu trúc tài liệu:
```c
struct Document {
    char name[];
    char content[];
    float size; // Kích thước tài liệu (MB)
};
```

