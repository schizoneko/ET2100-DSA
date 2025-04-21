# ASSIGNMENT 8

## 1. Cài Đặt Cây Nhị Phân - Đệ Quy

### 1.1. Dựng Cây Nhị Phân Từ Một Dãy Số (Đệ Quy)
- **Mục Tiêu**: Cài đặt cây nhị phân lưu trữ các giá trị số nguyên. Sử dụng đệ quy để dựng cây từ một mảng số.
- **Các Bước**:
  - Bắt đầu từ nút gốc của cây.
  - Đối với mỗi nút, chèn con trái nếu giá trị hiện tại nhỏ hơn và chèn con phải nếu giá trị hiện tại lớn hơn.
  - Lặp lại quá trình này cho mỗi nút cho đến khi cây được xây dựng hoàn chỉnh.

### 1.2. Duyệt Cây Theo Thứ Tự Trước (Pre-order) (Đệ Quy)
- **Mục Tiêu**: Duyệt cây theo thứ tự trước (Root, Left, Right) và in giá trị mỗi nút.
- **Các Bước**:
  - Truy cập nút gốc.
  - Duyệt cây con trái.
  - Duyệt cây con phải.

### 1.3. Duyệt Cây Theo Thứ Tự Giữa (In-order) (Đệ Quy)
- **Mục Tiêu**: Duyệt cây theo thứ tự giữa (Left, Root, Right) và in giá trị mỗi nút.
- **Các Bước**:
  - Duyệt cây con trái.
  - Truy cập nút gốc.
  - Duyệt cây con phải.

### 1.4. Duyệt Cây Theo Thứ Tự Sau (Post-order) (Đệ Quy)
- **Mục Tiêu**: Duyệt cây theo thứ tự sau (Left, Right, Root) và in giá trị mỗi nút.
- **Các Bước**:
  - Duyệt cây con trái.
  - Duyệt cây con phải.
  - Truy cập nút gốc.

### 1.5. Tính Chiều Cao Của Cây (Đệ Quy)
- **Mục Tiêu**: Tính chiều cao của cây nhị phân. Chiều cao là số cạnh của đường đi dài nhất từ gốc tới lá.
- **Các Bước**:
  - Nếu nút là null, trả về -1.
  - Tính chiều cao của cây con trái và cây con phải một cách đệ quy.
  - Trả về chiều cao của cây là giá trị lớn nhất giữa chiều cao cây con trái và phải cộng thêm 1.

### 1.6. Tính Tổng Các Phần Tử Của Cây (Đệ Quy)
- **Mục Tiêu**: Tính tổng tất cả các phần tử trong cây.
- **Các Bước**:
  - Nếu nút là null, trả về 0.
  - Tính tổng của cây con trái và cây con phải một cách đệ quy.
  - Trả về tổng các phần tử là giá trị nút gốc cộng với tổng của các cây con trái và phải.

## 2. Cài Đặt Cây Nhị Phân - Không Đệ Quy

### 2.1. Dựng Cây Nhị Phân Từ Một Dãy Số (Không Đệ Quy)
- **Mục Tiêu**: Cài đặt cây nhị phân từ dãy số mà không sử dụng đệ quy, sử dụng vòng lặp thay vì các gọi hàm đệ quy.
- **Các Bước**:
  - Bắt đầu từ nút gốc và duyệt qua cây để tìm đúng vị trí của mỗi phần tử trong mảng.
  - Thêm phần tử vào đúng vị trí trong cây bằng cách sử dụng vòng lặp thay vì gọi đệ quy.

### 2.2. Duyệt Cây Theo Thứ Tự Trước (Pre-order) (Không Đệ Quy)
- **Mục Tiêu**: Duyệt cây theo thứ tự trước mà không sử dụng đệ quy, sử dụng ngăn xếp (stack) thay vì gọi đệ quy.
- **Các Bước**:
  - Bắt đầu từ nút gốc và đẩy nó vào ngăn xếp.
  - Duyệt qua các nút, in giá trị của chúng và đẩy các con của nút vào ngăn xếp.

### 2.3. Duyệt Cây Theo Thứ Tự Giữa (In-order) (Không Đệ Quy)
- **Mục Tiêu**: Duyệt cây theo thứ tự giữa mà không sử dụng đệ quy, sử dụng ngăn xếp thay vì gọi đệ quy.
- **Các Bước**:
  - Bắt đầu từ nút gốc và đẩy tất cả các nút con trái vào ngăn xếp.
  - Duyệt qua cây bằng cách lấy nút từ ngăn xếp, in giá trị của nó và đẩy các nút con phải vào ngăn xếp.

### 2.4. Duyệt Cây Theo Thứ Tự Sau (Post-order) (Không Đệ Quy)
- **Mục Tiêu**: Duyệt cây theo thứ tự sau mà không sử dụng đệ quy, sử dụng ngăn xếp.
- **Các Bước**:
  - Sử dụng ngăn xếp để giữ các nút và duyệt cây theo thứ tự sau.
  - Đẩy các nút vào ngăn xếp và xử lý chúng theo đúng thứ tự sau bằng cách sử dụng cách tiếp cận không đệ quy.

### 2.5. Tính Chiều Cao Của Cây (Không Đệ Quy)
- **Mục Tiêu**: Tính chiều cao của cây bằng cách sử dụng phương pháp không đệ quy.
- **Các Bước**:
  - Sử dụng hàng đợi để duyệt cây theo từng mức.
  - Đếm số mức của cây để xác định chiều cao.

### 2.6. Tính Tổng Các Phần Tử Của Cây (Không Đệ Quy)
- **Mục Tiêu**: Tính tổng các phần tử trong cây bằng cách sử dụng phương pháp không đệ quy.
- **Các Bước**:
  - Sử dụng hàng đợi hoặc ngăn xếp để duyệt cây.
  - Tính tổng tất cả các giá trị của các nút trong quá trình duyệt cây.
