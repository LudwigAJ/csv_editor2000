//
//  Row.cpp
//  testing
//
//  Created by Ludwig Jonsson on 10/12/2019.
//  Copyright © 2019 Ludwig Jonsson. All rights reserved.
//

#include "Column.hpp"



Column::Column(){

    this->name = "";
    this->size = 0;
    
}
Column::Column(string name_input){
    this->name = name_input;
    this->size = 0;
}
Column::Column(string name_input, vector<string> vector_input){
    this->name = name_input;
    this->contents = vector_input;
    this->size = contents.size();
}
//Column::~Column(){
//    delete name;
//}

string Column::get_name(){
    return name;
}
void Column::set_name(string input){
    name = input;
}
vector<string> Column::get_contents(){
    return contents;
}
void Column::set_contents(vector<string> input){
    contents = input;
    this->size = contents.size();
}
vector<string>& Column::change_contents(){ //this is a bit iffy
    return contents;
}
void Column::set_size(){
    this->size = contents.size();
}
int Column::get_size(){
    set_size();
    return size;
}



