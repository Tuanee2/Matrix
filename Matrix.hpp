//
//  Matrix.hpp
//  Matrix
//
//  Created by tuan on 29/02/2024.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#define Matrix_Version "0.0.4"  // Phiên bản của class Matrix, cập nhật lần cuối 10/10/2024

#include <iostream>
#include <stdio.h>
#include <vector>

/// Lớp Matrix dùng để biểu diễn và xử lý các ma trận cơ bản.
class Matrix {
private:
    std::vector<std::vector<double>> data;  // Lưu trữ dữ liệu của ma trận dưới dạng mảng 2 chiều.
    size_t rows;  // Số hàng của ma trận.
    size_t cols;  // Số cột của ma trận.

public:
    /// Constructor: Tạo một ma trận với số hàng và số cột xác định.
    /// @param rows: số lượng hàng của ma trận.
    /// @param cols: số lượng cột của ma trận.
    Matrix(size_t rows, size_t cols);

    /// Phương thức trả về số hàng của ma trận.
    /// @return số hàng của ma trận.
    size_t getRow();

    /// Phương thức trả về số cột của ma trận.
    /// @return số cột của ma trận.
    size_t getCol();
    
    /// Đặt giá trị cho một phần tử trong ma trận.
    /// @param row: vị trí hàng của phần tử.
    /// @param col: vị trí cột của phần tử.
    /// @param value: giá trị cần gán cho phần tử tại (row, col).
    void setValue(size_t row, size_t col, double value);

    /// Đặt toàn bộ giá trị cho ma trận từ một mảng 1 chiều kiểu double.
    /// @param arr: con trỏ đến mảng 1 chiều kiểu double.
    /// @param arrSize: kích thước của mảng.
    void setMatrix(const double* arr, size_t arrSize);

    /// Đặt toàn bộ giá trị cho ma trận từ một vector 1 chiều kiểu double.
    /// @param arr: vector chứa các giá trị cần gán cho ma trận.
    void setMatrix(const std::vector<double>& arr);
    
    /// Gán giá trị của ma trận `other` cho ma trận hiện tại (hai ma trận phải cùng kích thước).
    /// @param other: ma trận cần gán giá trị.
    void assign(const Matrix& other);
    
    /// Trả về giá trị của một phần tử trong ma trận tại vị trí (row, col).
    /// @param row: hàng của phần tử cần lấy.
    /// @param col: cột của phần tử cần lấy.
    /// @return giá trị của phần tử tại (row, col).
    double getValue(size_t row, size_t col);
    
    /// Lấy ma trận con từ ma trận lớn hơn.
    /// @param x: chỉ số bắt đầu từ hàng.
    /// @param y: chỉ số bắt đầu từ cột.
    /// @param row: số hàng của ma trận con.
    /// @param col: số cột của ma trận con.
    /// @return ma trận con có kích thước (row x col) bắt đầu từ vị trí (x, y).
    Matrix getsubmatrix(int x, int y, size_t row, size_t col);
    
    /// Tạo ma trận con bằng cách loại bỏ hàng và cột cụ thể.
    /// @param rowToRemove: hàng cần loại bỏ.
    /// @param colToRemove: cột cần loại bỏ.
    /// @return ma trận sau khi loại bỏ hàng và cột.
    Matrix subMatrix(size_t rowToRemove, size_t colToRemove) const;

    /// Tính định thức của ma trận.
    /// @return định thức của ma trận.
    double determinant() const;
    
    /// Tìm hạng của ma trận (rank).
    /// @return hạng của ma trận.
    size_t rank() const;
    
    /// Toán tử nhân hai ma trận.
    /// @param other: ma trận cần nhân.
    /// @return ma trận kết quả sau khi nhân.
    Matrix operator*(const Matrix& other) const;

    /// Toán tử nhân ma trận với một số vô hướng (scalar).
    /// @param scalar: số vô hướng cần nhân với ma trận.
    /// @return ma trận sau khi nhân với số vô hướng.
    Matrix operator*(double scalar) const;

    /// Toán tử cộng hai ma trận.
    /// @param other: ma trận cần cộng.
    /// @return ma trận kết quả sau khi cộng.
    Matrix operator+(const Matrix& other) const;

    /// Toán tử trừ hai ma trận.
    /// @param other: ma trận cần trừ.
    /// @return ma trận kết quả sau khi trừ.
    Matrix operator-(const Matrix& other) const;

    /// Toán tử gán ma trận.
    /// @param other: ma trận cần gán.
    /// @return ma trận hiện tại sau khi gán.
    Matrix& operator=(const Matrix& other);
    
    /// Phép chuyển vị ma trận.
    /// @return ma trận chuyển vị của ma trận hiện tại.
    Matrix transpose() const;

    /// Phép nghịch đảo ma trận (nếu tồn tại).
    /// @return ma trận nghịch đảo.
    Matrix inverse() const;

    /// Chuyển ma trận về dạng tam giác để tính rank.
    /// @return ma trận dạng tam giác.
    Matrix convertToTriangular();
    
    /// Đổi vị trí hai hàng trong ma trận.
    /// @param row1: hàng đầu tiên.
    /// @param row2: hàng thứ hai.
    void swapRows(size_t row1, size_t row2);

    /// Đổi vị trí hai cột trong ma trận.
    /// @param col1: cột đầu tiên.
    /// @param col2: cột thứ hai.
    void swapCols(size_t col1, size_t col2);
    
    /// Kiểm tra xem ma trận có kích thước 1x1 hay không.
    /// @return true nếu ma trận là ma trận 1x1, false nếu không.
    bool isSingleElementMatrix() const;
    
    /// Trả về giá trị duy nhất của ma trận 1x1 dưới dạng kiểu `double`.
    /// @return giá trị của ma trận nếu là 1x1.
    double getSingleElementValue() const;
    
    /// Tạo ma trận đơn vị (identity matrix) có kích thước size x size.
    /// @param size: kích thước của ma trận đơn vị.
    /// @return ma trận đơn vị.
    static Matrix identity(size_t size);

    /// Tạo ma trận 0 với kích thước rows x cols.
    /// @param rows: số hàng của ma trận.
    /// @param cols: số cột của ma trận.
    /// @return ma trận toàn 0.
    static Matrix zeros(size_t rows, size_t cols);
    
    /// In ma trận ra console.
    void print() const;
};

/// Lớp Matrix3 dùng để biểu diễn và xử lý các ma trận 3 chiều.
class Matrix3 {
private:
    std::vector<std::vector<std::vector<double>>> data;  // Dữ liệu ma trận 3 chiều.
    size_t depth;  // Số lớp (chiều sâu) của ma trận.
    size_t rows;   // Số hàng của mỗi lớp.
    size_t cols;   // Số cột của mỗi lớp.

public:
    /// Constructor: Tạo một ma trận 3D với số lớp, số hàng và số cột xác định.
    Matrix3(size_t depth, size_t rows, size_t cols);

    /// Phương thức trả về số lớp của ma trận.
    size_t getDepth() const;

    /// Phương thức trả về số hàng của ma trận.
    size_t getRow() const;

    /// Phương thức trả về số cột của ma trận.
    size_t getCol() const;

    /// Đặt giá trị cho một phần tử trong ma trận.
    void setValue(size_t d, size_t r, size_t c, double value);

    /// Lấy giá trị của phần tử tại (d, r, c).
    double getValue(size_t d, size_t r, size_t c) const;

    /// Gán giá trị cho toàn bộ ma trận từ vector 1 chiều.
    void setMatrix(const std::vector<double>& arr);

    /// Trả về một lớp (2D) từ ma trận 3D tại độ sâu `depthIndex`.
    Matrix getLayer(size_t depthIndex) const;

    /// Toán tử cộng hai ma trận 3D.
    Matrix3 operator+(const Matrix3& other) const;

    /// Toán tử trừ hai ma trận 3D.
    Matrix3 operator-(const Matrix3& other) const;

    /// Toán tử nhân ma trận 3D với số vô hướng.
    Matrix3 operator*(double scalar) const;

    /// Phương thức in toàn bộ ma trận ra console.
    void print() const;

    /// Tạo ma trận 3D toàn 0.
    static Matrix3 zeros(size_t depth, size_t rows, size_t cols);
};


/// Lớp MatrixArray dùng để lưu trữ và quản lý mảng các đối tượng ma trận.
class MatrixArray {
private:
    std::vector<Matrix> matrices;  // Lưu trữ một mảng các đối tượng ma trận.

public:
    /// Thêm một ma trận vào mảng.
    /// @param mat: ma trận cần thêm.
    void addMatrix(const Matrix& mat);

    /// Trả về ma trận tại chỉ mục index trong mảng.
    /// @param index: chỉ mục của ma trận cần lấy.
    /// @return ma trận tại chỉ mục index.
    Matrix& getMatrix(size_t index);

    /// In tất cả các ma trận trong mảng.
    void printAllMatrices() const;
};

#endif /* Matrix_hpp */