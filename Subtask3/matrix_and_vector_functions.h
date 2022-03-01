using vf = std::vector<float>;
using vvf= std::vector<vf>;

vvf dot_product_and_sum(vvf &input_matrix, vvf &weight_matrix, vvf &bias_matrix);
vvf compute_relu(vvf &matrix);
vvf compute_tanh(vvf& matrix);
vf sigmoid(vf &vec);
vf softmax(vf &vec);