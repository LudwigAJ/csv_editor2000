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
    set_largest_name_size();
    string_size_sum();
}

void Wrapper::set_matrix(vector<Column> in){
    csv_matrix = in;
    set_largest_size();
    set_largest_name_size();
    string_size_sum();
}

vector<Column>& Wrapper::access_matrix(){
    return csv_matrix;
}

void Wrapper::set_largest_size(){
    int l_int = 0;
    const int wrap_size = csv_matrix.size();
    
    for (int x = 0; x < wrap_size; x++){
        
        int temp_size = csv_matrix[x].get_size();
        
        if (temp_size > l_int) l_int = temp_size;
        
    }
    this->largest_size = l_int;
}

int Wrapper::get_largest_size(){
    return largest_size;
}

void Wrapper::set_largest_name_size(){
    
    int name_int = 0;
    const int wrap_size = csv_matrix.size();
    
    for (int ind = 0; ind < wrap_size; ind++){
        
        int temp_name_size = csv_matrix[ind].get_name().length();
        if (temp_name_size > name_int) name_int = temp_name_size;
        
    }
    this->largest_name_size = name_int;
}

void Wrapper::string_size_sum(){
    
    int total_int = 0;
    const int wrap_size = csv_matrix.size();
    
    for (int ind = 0; ind < wrap_size; ind++){
        
        total_int += csv_matrix[ind].get_name().length();
    }
    this->string_length_sum = total_int;
    
}
int Wrapper::get_length_sum(){
    return this->string_length_sum;
}

int Wrapper::get_largest_name_size(){
    return this->largest_name_size;
}

Wrapper Wrapper::operator=(Wrapper& wrap){
    return Wrapper(wrap.access_matrix());
}
