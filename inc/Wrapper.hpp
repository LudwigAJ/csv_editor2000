//
//  Wrapper.hpp
//  testing
//
//  Created by Ludwig Jonsson on 10/12/2019.
//  Copyright © 2019 Ludwig Jonsson. All rights reserved.
//

#ifndef Wrapper_hpp
#define Wrapper_hpp

#include <vector>
#include "Column.hpp"

class Wrapper{
    
private:
    vector<Column> csv_matrix;
    int largest_size;
    int largest_name_size;
    int string_length_sum;
    
public:
    
    
    Wrapper(vector<Column> input);
    
    void set_matrix(vector<Column> in);
    vector<Column>& access_matrix();
    void set_largest_size();
    int get_largest_size();
    void set_largest_name_size();
    int get_largest_name_size();
    void string_size_sum();
    int get_length_sum();
    
    Wrapper operator=(Wrapper& wrap);
    
};

#endif /* Wrapper_hpp */
