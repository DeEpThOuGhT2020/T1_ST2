#include <iostream>
#include <exception>
#include "inp_oup.h"
#include "libaudio.h"

int main(int argc, char** argv){
    try{
        if (argc<3) std::cerr<<"Not enough arguments.\n";
        else{
            pred_t* pred = new pred_t[3];
            pred = libaudioAPI(argv[1], pred);
            write_keyword_probs (argv[2], pred);
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    return 0;
}