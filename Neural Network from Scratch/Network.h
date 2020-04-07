//
//  Network.h
//  Neural Network from Scratch
//
//  Created by Bharddwaj Vemulapalli on 4/4/20.
//  Copyright © 2020 Bharddwaj Vemulapalli. All rights reserved.
//

#ifndef Network_h
#define Network_h
#include<vector>
#include "Neuron.h"
struct Network{
    //assumes all inputs are of the same size!
    public:
        std::vector<Neuron> neurons;
        size_t numNeurons;
        std::vector<std::vector<double>> inputs;
        size_t maxBias;
        Network(size_t _numNeurons, std::vector<std::vector<double>> _inputs, size_t _maxBias ):
        numNeurons{_numNeurons}, inputs{_inputs}, maxBias{_maxBias} {
                for(size_t i = 0; i < numNeurons; ++i){
                    neurons.push_back(Neuron(inputs[0].size(),inputs,maxBias));
                    
                }
                
            }
        void calculateAllOutputs(){
           for(auto &neuron:neurons){
                neuron.calculate_outputs();
            }
            calculatedOutputs = true;
        }
        
        //getters
        std::vector<Neuron> getNeurons(){
            return neurons;
        }
        std::vector<std::vector<double>> getAllOutputs(){
            std::vector<std::vector<double>> allOutputs;
            if(!calculatedOutputs){
                calculateAllOutputs();
                calculatedOutputs = true;
            }
            
            for(auto &neuron:neurons){
                allOutputs.push_back(neuron.getOutputs());
            }
            
            return allOutputs;
        }
    private:
        bool calculatedOutputs = false;
        
    
    
};

#endif /* Network_h */
