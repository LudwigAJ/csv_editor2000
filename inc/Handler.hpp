//
//  Handler.hpp
//  xcode_csv
//
//  Created by Ludwig Jonsson on 15/12/2019.
//  Copyright © 2019 Ludwig Jonsson. All rights reserved.
//

#ifndef Handler_hpp
#define Handler_hpp

#include <stdio.h>
#include "Column.hpp"
#include "Wrapper.hpp"

//I here decided to move the functions that handle opening files and such into a separate class. Maybe I'll change this
//in the future.

class Handler{
    
    
public:
    
    Wrapper open_csv(string name_input);
    void display_csv(Wrapper input);
    void save_csv(Wrapper input);
    void sum(Wrapper &input);
    void average(Wrapper &input);
    
    
};

#endif /* Handler_hpp */
