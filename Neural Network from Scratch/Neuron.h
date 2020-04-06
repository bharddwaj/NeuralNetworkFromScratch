//
//  Neuron.h
//  Neural Network from Scratch
//
//  Created by Bharddwaj Vemulapalli on 4/4/20.
//  Copyright © 2020 Bharddwaj Vemulapalli. All rights reserved.
//

#ifndef Neuron_h
#define Neuron_h

#include <iostream>
#include<vector>
#include <time.h>
#include <random>
struct Neuron{
    public:
        size_t inputDimensions;
        size_t numInputs;
        size_t maxBias;
        std::vector<std::vector<double>> inputs;
    
        Neuron(size_t _inputDimensions,std::vector<std::vector<double>> _inputs,size_t _maxBias):
            inputDimensions{_inputDimensions}, inputs{_inputs}, maxBias{_maxBias}
            {
                numInputs = inputs.size();
                initialize_all(maxBias);
            }
    
        void initialize_all(size_t max_bias){
            //randomly initialize weights from 0-1 (only tenths place)
            //randomly initialize bias from 0-max_bias
            initialize_random_weights();
            initialize_random_biases(max_bias);
        }
        
        void calculate_outputs(){
            //inputs*weights + bias -> output for one neuron
            double output = 0;
            for (size_t i = 0; i < numInputs; ++i) {
                for(size_t j = 0; j < inputDimensions; ++j){
                    
                    output += ((inputs)[i][j]) * ((weights)[i][j]);
                }
                output += biases[i];
                outputs.push_back(output);
                output = 0;
            }
            
        }
        std::vector<std::vector<double>> getWeights(){
            return weights;
        }
        std::vector<double> getBiases(){
            return biases;
        }
        std::vector<double> getOutputs(){
            return outputs;
        }
    private:
        std::vector<std::vector<double>> weights;
        std::vector<double> biases;
        std::vector<double> outputs;
        void initialize_random_weights(){
//            srand( (unsigned)time(NULL) );
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist_weights(1,10);
            std::vector<double> one_set_of_weights;
            for(size_t i = 0; i < numInputs; ++i){
                for(size_t j = 0; j < inputDimensions; ++j )
                {
                    //one_set_of_weights.push_back( (rand() % 10)/10.0 );
                    one_set_of_weights.push_back(dist_weights(rng)/10.0);
                }
                weights.push_back(one_set_of_weights);
                one_set_of_weights.clear();
            }
            
        }
        void initialize_random_biases(size_t max_bias){
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist_max_bias(1,(int)(max_bias));
            double bias = 0;
            for(size_t i = 0; i < numInputs; ++i){
                bias = (dist_max_bias(rng));
                biases.push_back(bias);
                bias = 0;
            }
            
                       
        }
        
    
};

#endif /* Neuron_h */
