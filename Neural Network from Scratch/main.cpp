//
//  main.cpp
//  Neural Network from Scratch
//
//  Created by Bharddwaj Vemulapalli on 4/4/20.
//  Copyright © 2020 Bharddwaj Vemulapalli. All rights reserved.
//

#include <iostream>
#include<vector>
#include <time.h>
#include "Neuron.h"
#include "Network.h"
int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    std::vector<std::vector<double>> inputs;
    std::vector<double> arr;
    std::vector<double> arr2;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    inputs.push_back(arr);

    arr2.push_back(7);
    arr2.push_back(8);
    arr2.push_back(9);
  
    inputs.push_back(arr2);
    
//    std::cout << (inputs)[0][2]<< std::endl;

    Neuron * a = new Neuron(inputs[0].size(), inputs, 10);
    std::vector<std::vector<double>> weights = a->getWeights();
    a->calculate_outputs();
    std::vector<double> outputs = a->getOutputs();
    for(auto &output: outputs){
        std::cout << output << ",";
    }
    Network *b = new Network(10,inputs,10);
    b->getNeurons();
    std::vector<std::vector<double>> outputs2 = b->getAllOutputs();
    for(int i = 0; i < outputs2.size(); ++i){
        std::cout << "[";
        for(int j = 0; j < outputs2[0].size(); ++j){
            if(j!=outputs2[0].size()-1 ){
                std::cout << (outputs2)[i][j] << "," ;
            }
            else{
                std::cout << (outputs2)[i][j];
            }
        }
        std::cout << "]" <<std::endl;

    }

//    std::cout << "Now we are going to print out weights: " <<std::endl;
//    std::cout << b[0].getWeights()[0][0] << std::endl;
//    std::cout << b[0].getWeights()[0][1] << std::endl;
//    std::cout << b[0].getWeights()[0][2] << std::endl;
//    std::cout << b[0].getBiases()[0] <<std::endl;


    
    return 0;
}
