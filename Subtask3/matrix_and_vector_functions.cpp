#include <iostream>
#include <exception>
#include <assert.h>
#include <vector>
#include <string.h>
#include <math.h>
#include "matrix_and_vector_functions.h"

using vf = std::vector<float>;
using vvf= std::vector<vf>;

vvf dot_product_and_sum(vvf &input_matrix, vvf &weight_matrix, vvf &bias_matrix){
//Computes inner product of an input matrix and a weight matrix and adds to this product matrix a bias matrix.
    int a=input_matrix.size();
    int b=input_matrix[0].size();
    int c=weight_matrix[0].size(); 
    vvf ans_matrix(a, vf (c, 0.0));   
    for (int i = 0; i < a; i++){
        for (int j = 0; j < c; j++){
            for (int k = 0; k < b; k++){
                ans_matrix[i][j]+=(input_matrix[i][k] * weight_matrix[k][j]);
            }
            ans_matrix[i][j]+=bias_matrix[i][j];
        }
    }
    return ans_matrix;
}

vvf compute_relu(vvf &matrix){
    int r=matrix.size();
    int c=matrix[0].size();
    vvf activated_matrix(r, vf (c, 0.0));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            activated_matrix[i][j]=fmax(0.0, matrix[i][j]);
        }
    }
    return activated_matrix;
}

vvf compute_tanh(vvf& matrix){
    int r=matrix.size();
    int c=matrix[0].size();
    vvf activated_matrix(r, vf (c, 0.0));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            float x=matrix[i][j];
            activated_matrix[i][j]=(exp(2*x)-1.0)/(exp(2*x)+1.0);
        }
    }
    return activated_matrix;
}

vf sigmoid(vf &vec){
    int n=vec.size();
    vf ret(n);
    for (int i = 0; i < n; i++){
        ret[i]=1.0/(1.0+exp(-(vec[i])));
    }
    return ret;
}

vf softmax(vf &vec){
    int n=vec.size();
    vf ret(n);
    float exp_sum=0.0;
    for (int i = 0; i < n; i++){
        exp_sum+= exp(vec[i]);
    }
    for (int i = 0; i < n; i++){
        ret[i]= exp(vec[i])/exp_sum;
    }
    return ret;
}