#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <string>
#include "inp_oup.h"
#include "matrix_and_vector_functions.h"
#include "libaudio.h"

using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;

using vf = vector<float>;
using vvf= vector<vf>;


pred_t* libaudioAPI(const char* audiofeatures, pred_t* pred){
    vvf IP1_WT(250, vf (144));
    vvf IP2_WT(144, vf (144));
    vvf IP3_WT(144, vf (144));
    vvf IP4_WT(144, vf (12));
    read_weight_matrices_row_major(IP1_WT, IP2_WT, IP3_WT, IP4_WT);
    vvf IP1_BIAS(1, vf (144));
    vvf IP2_BIAS(1, vf (144));
    vvf IP3_BIAS(1, vf (144));
    vvf IP4_BIAS(1, vf (12));
    read_bias_row_vectors(IP1_BIAS, IP2_BIAS, IP3_BIAS, IP4_BIAS);

    ifstream inp_stream;
    inp_stream.open(audiofeatures);
    vvf input_feature_vector= read_row_vector(inp_stream);
    inp_stream.close();
    vvf dnn_matrix;
    dnn_matrix=dot_product_and_sum(input_feature_vector, IP1_WT, IP1_BIAS);
    dnn_matrix=compute_relu(dnn_matrix);
    dnn_matrix=dot_product_and_sum(dnn_matrix, IP2_WT, IP2_BIAS);
    dnn_matrix=compute_relu(dnn_matrix);
    dnn_matrix=dot_product_and_sum(dnn_matrix, IP3_WT, IP3_BIAS);
    dnn_matrix=compute_relu(dnn_matrix);
    dnn_matrix=dot_product_and_sum(dnn_matrix, IP4_WT, IP4_BIAS);
    vf prob_vec(12);
    for (int i = 0; i < 12; i++){
        prob_vec[i]=dnn_matrix[0][i];
    }
    prob_vec=softmax(prob_vec);

    int first, second, third;
    first=second=third=0;
    for (int i = 0; i < 12; i++){
        if (prob_vec[i]>prob_vec[first]){
            third=second;
            second=first;
            first=i;
        }
        else if (prob_vec[i]>prob_vec[second]){
            third=second;
            second=i;
        }
        else if (prob_vec[i]>prob_vec[third]){
            third=i;
        }
        else continue;
    }
    (pred[0]).label = first;
    (pred[0]).prob = prob_vec[first];
    (pred[1]).label = second;
    (pred[1]).prob = prob_vec[second];
    (pred[2]).label = third;
    (pred[2]).prob = prob_vec[third];
    return pred;
}