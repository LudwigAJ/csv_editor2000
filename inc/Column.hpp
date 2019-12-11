//
//  Row.hpp
//  testing
//
//  Created by Ludwig Jonsson on 10/12/2019.
//  Copyright © 2019 Ludwig Jonsson. All rights reserved.
//

#ifndef Row_hpp
#define Row_hpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace ::std;

class Column{
    
private:
    
    int size;
    string name;
    vector<string> contents;
    
protected:
    
public:
    
    
    Column();
    Column(string name_input);
    Column(string name_input, vector<string> vector_input);
//    ~Column();
    
    //helper functions :)
    string get_name();
    void set_name(string input);
    vector<string> get_contents();
    void set_contents(vector<string> input);
    vector<string>& change_contents();
    
    void open_csv(string name_input);
    void set_size();
    int get_size();
    
    Column& operator=(const Column& in) const;
    
    
    
    
};

#endif /* Row_hpp */
