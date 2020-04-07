//
//  forTesting.h
//  Neural Network from Scratch
//
//  Created by Bharddwaj Vemulapalli on 4/6/20.
//  Copyright © 2020 Bharddwaj Vemulapalli. All rights reserved.
//

#ifndef forTesting_h
#define forTesting_h
#include <iostream>
void print_Output_Neuron(std::vector<double> &outputs){
    std::cout << "[ ";
    for (double &output: outputs) {
        std::cout << output <<",";
    }
    std::cout << "]" << std::endl;
}
void print_Output_Network(std::vector<std::vector<double>> &outputs){
    for(int i = 0; i < outputs.size(); ++i){
        std::cout << "[";
        for(int j = 0; j < outputs[i].size(); ++j){
            if(j!=outputs[0].size()-1 ){
                std::cout << (outputs)[i][j] << "," ;
            }
            else{
                std::cout << (outputs)[i][j];
            }
        }
        std::cout << "]" <<std::endl;

    }
}

#endif /* forTesting_h */
