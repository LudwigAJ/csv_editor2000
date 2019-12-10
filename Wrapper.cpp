//
//  Wrapper.cpp
//  testing
//
//  Created by Ludwig Jonsson on 10/12/2019.
//  Copyright © 2019 Ludwig Jonsson. All rights reserved.
//

#include "Wrapper.hpp"



Wrapper::Wrapper(vector<Column> input){
    csv_matrix = input;
    set_largest_size();
}

void Wrapper::set_matrix(vector<Column> in){
    csv_matrix = in;
    set_largest_size();
}

vector<Column>& Wrapper::access_matrix(){
    return csv_matrix;
}

void Wrapper::set_largest_size(){
    int l_int = 0;
    const int wrap_size = csv_matrix.size();
    
    for (int x = 0; x < wrap_size; x++){
        
        int temp_size = csv_matrix[x].get_size();
        
        if (temp_size > l_int){
            l_int = temp_size;
        }
    }
    this->largest_size = l_int;
}

int Wrapper::get_largest_size(){
    return largest_size;
}

Wrapper Wrapper::operator=(Wrapper& wrap){
    return Wrapper(wrap.access_matrix());
}
