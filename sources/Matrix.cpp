#include "Matrix.hpp"
#include <iostream>
#include <stdexcept>

namespace zich{
        //constructor
        Matrix::Matrix(std::vector<double> vec, int row, int col){
            //the size of the matrix need be positive
            if(col <=0 || row <= 0){
                throw std :: runtime_error("the size of the matrix is illegal");
            }
            //the size of the vector need to fit to the size of the matrix
            if(vec.size() != (row * col)){
                throw std :: runtime_error("the size of the matrix not correct");
            }
            this->col = col;
            this->row = row;
            int len = (row * col);
            for(unsigned i=0; i<len; i++){
                mat.push_back(vec.at(i));
            }
        }
        //copy constructor
        Matrix::Matrix(const Matrix& other){
            this->col = other.col;
            this->row = other.row;
            int len = (other.row * other.col);
            for(unsigned i=0; i<len; i++){
                mat.push_back(other.mat.at(i));
            }
        }
        //matrix+matrix
        Matrix Matrix :: operator+(Matrix& other){
            //the matrixes need be with same size
            if(this->col != other.get_col()){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            if(this->row != other.get_row()){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            std :: vector<double> ans_vec;
            int len = this->col * this->row;
            double temp = 0; 
            //create vector for the new matrix
            for(unsigned i=0; i<len; i++){
                temp = this->mat.at(i) + other.mat.at(i);
                ans_vec.push_back(temp);
            }
            Matrix new_mat{ans_vec, this->row, this->col};
            return new_mat;
        }
        //matrix-matrix
        Matrix Matrix :: operator-(Matrix& other){
            //the matrixes need be with same size
            if(this->col != other.get_col()){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            if(this->row != other.get_row()){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            std :: vector<double> ans_vec;
            int len = this->col * this->row;
            double temp = 0; 
            //create vector for the new matrix
            for(unsigned i=0; i<len; i++){
                temp = this->mat.at(i) - other.mat.at(i);
                ans_vec.push_back(temp);
            }
            Matrix new_mat{ans_vec, this->row, this->col};
            return new_mat;
        }
        //matrix+=matrix
        Matrix& Matrix :: operator+=(Matrix& other){
            //the matrixes need be with same size
            if(this->col != other.get_col()){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            if(this->row != other.get_row()){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            int len = this->col * this->row;
            //change the values in this matrix
            for(unsigned i= 0; i < len; i++){
                this->mat.at(i) = this->mat.at(i) + other.mat.at(i);
            }
            return *this;       
        }
        //matrix-=matrix
        Matrix& Matrix :: operator-=(Matrix& other){
            //the matrixes need be with same size
            if(this->col != other.get_col()){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            if(this->row != other.get_row()){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            int len = this->col * this->row;
            //change the values in this matrix
            for(unsigned i= 0; i < len; i++){
                this->mat.at(i) = this->mat.at(i) - other.mat.at(i);
            }
            return *this;       
        }
        //matrix < matrix
        bool Matrix :: operator<(const Matrix& other)const{
            //the matrixes need be with same size
            if(this->col != other.col){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            if(this->row != other.row){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            double size1 = 0;
            double size2 = 0;
            int len = this->col * this->row;
            //sum the 2 matrix
            for(unsigned i=0; i<len; i++){
                size1 += this->mat.at(i);
                size2 += other.mat.at(i);
            }
            return size1 < size2;
        }
        //matrix > matrix
        bool Matrix :: operator>(const Matrix& other)const{
            //the matrixes need be with same size
            if(this->col != other.col){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            if(this->row != other.row){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            double size1 = 0;
            double size2 = 0;
            int len = this->col * this->row;
            //sum the 2 matrix
            for(unsigned i=0; i<len; i++){
                size1 += this->mat.at(i);
                size2 += other.mat.at(i);
            }
            return size1 > size2;
        }
        //matrix <= matrix
        bool Matrix :: operator<=(const Matrix& other)const{
            //the matrixes need be with same size
            if(this->col != other.col){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            if(this->row != other.row){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            double size1 = 0;
            double size2 = 0;
            int len = this->col * this->row;
            //sum the 2 matrix
            for(unsigned i=0; i<len; i++){
                size1 += this->mat.at(i);
                size2 += other.mat.at(i);
            }
            return size1 <= size2;
        }
        //matrix >= matrix
        bool Matrix :: operator>=(const Matrix& other)const{
            //the matrixes need be with same size
            if(this->col != other.col){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            if(this->row != other.row){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            double size1 = 0;
            double size2 = 0;
            int len = this->col * this->row;
            //sum the 2 matrix
            for(unsigned i=0; i<len; i++){
                size1 += this->mat.at(i);
                size2 += other.mat.at(i);
            }
            return size1 >= size2;
        }
        //matrix == matrix
        bool Matrix :: operator==(const Matrix& other)const{
            //the matrixes need be with same size
            if(this->col != other.col){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            if(this->row != other.row){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            int len = this->col * this->row;
            //check if the matrixes have the same values
            for(unsigned i=0; i<len; i++){
                if(this->mat.at(i) != other.mat.at(i)){
                    return false;
                }
            }
            return true;
        }
        //matrix != matrix
        bool Matrix :: operator!=(const Matrix& other)const{
            //the matrixes need be with same size
            if(this->col != other.col){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            if(this->row != other.row){
                throw std :: runtime_error("the size of the matrixes not equal");
            }
            int len = this->col * this->row;
            //check if the matrixes have the same values
            for(unsigned i=0; i<len; i++){
                if(this->mat.at(i) != other.mat.at(i)){
                    return true;
                }
            }
            return false;
        }
        //++matrix
        Matrix& Matrix :: operator++(){
            int len = this->col * this->row;
            //increase all the values in the matrix
            for(unsigned i=0; i<len; i++){
                this->mat.at(i) = this->mat.at(i) + 1;
            }
            return *this;
        }
        //matrix++
        Matrix Matrix :: operator++(int num){
            //save the old matrix
            Matrix cpy = Matrix(*this);
            int len = this->col * this->row;
            //increase all the values in the matrix
            for(unsigned i=0; i<len; i++){
                this->mat.at(i) = this->mat.at(i) + 1;
            }
            //return the old matrix
            return cpy;
        }
        //--matrix
        Matrix& Matrix :: operator--(){
            int len = this->col * this->row;
            //decrease all the values in the matrix
            for(unsigned i=0; i<len; i++){
                this->mat.at(i) = this->mat.at(i) - 1;
            }
            return *this;
        }
        //matrix--
        Matrix Matrix :: operator--(int num){
            //save the old matrix
            Matrix cpy(*this);
            int len = this->col * this->row;
            //decrease all the values in the matrix
            for(unsigned i=0; i<len; i++){
                this->mat.at(i) = this->mat.at(i) - 1;
            }
            //return the old matrix
            return cpy;
        }
        //matrix*scalar
        Matrix Matrix :: operator*(double num){
            std :: vector<double> ans_vec;
            int len = this->col * this->row;
            double temp = 0;
            //mult the values of the matrix in the scalar
            for(unsigned i=0; i<len; i++){
                temp = this->mat.at(i) * num;
                //create vector to the new matrix
                ans_vec.push_back(temp);
            }
            Matrix ans = Matrix{ans_vec, this->row, this->col};
            return ans;
        }
        //matrix*=scalar
        Matrix& Matrix :: operator*=(double num){
            int len = this->col * this->row;
            double temp = 0;
            //mult the values of the matrix in the scalar
            for(unsigned i=0; i<len; i++){
                temp = this->mat.at(i) * num;
                //update the matrix
                this->mat.at(i) = temp;
            }
            return *this;
        }
        //matrix*matrix
        Matrix Matrix :: operator*(Matrix& other){
            //check if the mult is legal
            if(this->col != other.row){
                throw std :: runtime_error("this mult is illegal");
            }
            std :: vector<double> ans_vec;
            double sum = 0;
            //pass over all the rows of this matrix
            for(int j=0; j<this->row; j++){
                //pass over all the columns of the other matrix
                for(int k=0; k<other.col; k++){
                    //pass over all the columns of this matrix
                    for(int i=0; i<this->col; i++){                            
                        int index1 = (j*this->col)+i;
                        int index2 = (i*other.col)+k; //the number of the colmuns in this matrix is equal to the number of row in the other matrix
                        //mult
                        sum += (this->mat.at(unsigned(index1))*other.mat.at(unsigned(index2)));
                    }
                    ans_vec.push_back(sum);
                    sum = 0;
                }
            }
            //create new matrix
            Matrix ans = Matrix{ans_vec, this->row, other.col};
            return ans;
        }
        //matrix*=matrix
        Matrix& Matrix :: operator*=(Matrix& other){
            //check if the mult is legal
            if(this->col != other.row){
                throw std :: runtime_error("this mult is illegal");
            }
            int len = this->row * other.col;
            std :: vector<double> ans_vec;
            double sum = 0;
            //pass over all the rows of this matrix
            for(int j=0; j<this->row; j++){
                //pass over all the columns of the other matrix
                for(int k=0; k<other.col; k++){
                    //pass over all the columns of this matrix
                    for(int i=0; i<this->col; i++){         
                        int index1 = (j*this->col)+i;
                        int index2 = (i*other.col)+k;  //the number of the colmuns in this matrix is equal to the number of row in the other matrix
                        sum += (this->mat.at(unsigned(index1))*other.mat.at(unsigned(index2)));
                    }
                    ans_vec.push_back(sum);
                    sum = 0;
                }
            }
            //update this matrix
            this->mat.clear();
            for(unsigned i=0; i<len; i++){
                this->mat.push_back(ans_vec.at(i));
            }
            return *this;
        }
        Matrix :: ~Matrix(){

        }
        // +matrix
        Matrix operator+(Matrix& a){
            //call the copy constructor
            Matrix ans = Matrix(a);
            return ans;
        }
        //-matrix
        Matrix operator-(Matrix& a){
            int len = a.col * a.row;
            double temp = 0;
            std :: vector<double> ans_vec;
            //mult all the value in the matrix in -1
            for(unsigned i=0; i<len; i++){
                temp = a.mat.at(i) * (-1);
                ans_vec.push_back(temp);
            }
            Matrix ans = Matrix{ans_vec, a.row, a.col};
            return ans;
        }
        //scalar*matrix
        Matrix operator*(double num, Matrix& other){
            std :: vector<double> ans_vec;
            int len = other.col * other.row;
            double temp = 0;
            //mult all the values in the matrix
            for(unsigned i=0; i<len; i++){
                temp = other.mat.at(i) * num;
                //create vector to the new matrix
                ans_vec.push_back(temp);
            }
            Matrix ans = Matrix{ans_vec, other.row, other.col};
            return ans;
        }
        // << matrix
        std::ostream& operator<<(std::ostream& os, const Matrix& a){
            int len= a.col*a.row;
            double temp =0; 
            int j = 1;
            //first out [
            std :: operator<<(os, '[');
            //out all the matrix
            for(unsigned i=0; i<len; i++){
                temp = a.mat.at(i);
                os << temp;
                //check if the row is over
                if(j == a.col){   
                    j = 0;
                    std :: operator<<(os, ']');
                    //if this not the end- open new line
                    if(i != (len-1)){
                        std :: operator<<(os, '\n');
                        std :: operator<<(os, '[');
                    }
                }
                else{
                    // out space
                    std :: operator<<(os, ' '); 
                }
                j++;
            }
            return os;
        }
        //this function split string into vector
        std::vector<std::string> split(std::string str, char sep){
            int len = str.length();
            std::string s;
            std::vector<std::string> spl;
            for(unsigned i=0; i<len; i++){
                //if this is the seprator- enter to the vector
                if(str.at(i) == sep){
                    spl.push_back(s);
                    s = "";
                    if(sep == ','){
                        i++;
                    }
                    continue;
                }
                if(str.at(i) == '[' || str.at(i) == ']'){
                    continue;
                }
                s += str.at(i);
            }
            spl.push_back(s);
            return spl;
        }
        //>>matrix
        std::istream& operator>>(std::istream& is, Matrix& a){ 
            int num_row = 0;
            int num_col = 0;
            //clean the matrix
            a.mat.clear();
            std :: string str;
            //get the input to string
            getline(is, str);
            unsigned len = str.length();
            //the input must start with '['
            if(str.at(0) != '['){
                throw std::runtime_error("illegal input");
            }
            //the input must end with ']'
            if(str.at(len-1) != ']'){
                throw std::runtime_error("illegal input");
            }
            //after ',' must be ' '
            for(unsigned i = 0; i<len; i++){
                if(str.at(i) == ',' && str.at(i+1) != ' '){
                    throw std::runtime_error("this input is illegal");
                }
            }
            //split the string by ','
            std::vector<std::string> by_comma = split(str, ',');
            num_row = by_comma.size();
            //split all the strings in the vector by space
            std::vector<std::string> by_space = split(by_comma.at(0), ' ');
            num_col = by_space.size();
            for(unsigned j=0; j<num_col; j++){
                //casting the string to double and enter to the matrix
                a.mat.push_back(std::stod(by_space.at(j)));
            }
            for(unsigned i = 1; i<num_row; i++){
                by_space = split(by_comma.at(i), ' ');
                //check if the size is correct
                if(by_space.size() != num_col){
                    throw std::runtime_error("illegal input");
                }
                for(unsigned j=0; j<num_col; j++){
                    //casting the string to double and enter to the matrix
                    a.mat.push_back(std::stod(by_space.at(j)));
                }
            }
            return is;
        }
}