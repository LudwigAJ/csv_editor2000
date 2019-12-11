//
//  main.cpp
//  testing
//
//  Created by Ludwig Jonsson on 21/11/2019.
//  Copyright © 2019 Ludwig Jonsson. All rights reserved.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <typeinfo>
#include "Column.hpp"
#include "Wrapper.hpp"

Wrapper open_csv(string name_input);
void display_csv(Wrapper);

using namespace ::std;


int main(int argc, const char * argv[]) {
    
    string current_command = "";
    bool start_menu_shown = false;
    string csv_name;
    
    
    
    
    while (current_command != "exit"){
        
        if (start_menu_shown == false){
        cout << "Welcome to csv_editor2000! \n" << "Please type what you would want to do (Case sensitive)" << endl;
        cout << "1. Open csv file (open) \n" << "2. Exit program (exit) \n";
            cin >> current_command;
            start_menu_shown = true;
        } else {
            cout << "What do  you want to do next?" << endl;
            cout << "1. Open csv file (open) \n" << "2. Exit program (exit) \n";
            cin >> current_command;

        }
        
        if (current_command == "open"){
            
            cout << "\nPlease enter the name of your csv file and press enter: " << endl;
            cin >> csv_name;
            cout << endl;
            try {
            Wrapper wrapper(open_csv(csv_name));
            display_csv(wrapper);
            }
            catch (const ios::failure& bad) {
                cout << "\nSorry, but file could not be opened. Maybe it doesn't exist?\n" << endl;
            }
            
        } else if (current_command == "exit"){
            cout << "\nShutting down..." << endl;
        } else {
            cout << "\nNot a valid command. Please try again\n" << endl;
        }
        
        
    }//END OF PROGRAM LOOP
    
    return 0;
}

//Handles how we open .csv files
Wrapper open_csv(string name_input){
    
    vector<Column> column_vector;
    
    fstream INFILE;
    
    //INFILE.exceptions( ifstream::badbit );
    //exception handling
    
        INFILE.open(name_input, ifstream::in);
        if (!INFILE) throw ifstream::failure("INFILE.open error");
   
        string line;
        string word;
        
        getline(INFILE, line);
        stringstream in_line(line);
        
    
        while (getline(in_line, word, ',')){
            
            Column column(word);
            column_vector.push_back(column);
            
        } // Now we have extracted the first line which contains the names or titles.
        
        int column_iterator = 0;
        
        while (!INFILE.eof()){
            
            string rest_line;
            string rest_word;
            
            int iterator = 0;
            
            
            getline(INFILE, rest_line);
            stringstream rest_in_line(rest_line);
            
            while (getline(rest_in_line, rest_word, ',')){
               
                column_vector[iterator].change_contents().push_back(rest_word);
                
                iterator++;
            }
            column_iterator++;
        }
    
        Wrapper wrapper(column_vector);
        return wrapper;
        
    }



void display_csv(Wrapper input){
    
    const int WIDTH_SPACE = input.get_largest_name_size()+2;
    
    const int vector_size = input.access_matrix().size();
    const int largest_size = input.get_largest_size();
    
    const int l_width = (WIDTH_SPACE+1) * vector_size - 1;
    const string line = '|' + string(l_width, '-') + '|';
    
    cout << line << "\n";
    cout << setw(0) << left << '|';
    
    for (int p = 0; p < vector_size; p++){
        
        Column current = input.access_matrix()[p];
        
        cout << internal << setw(WIDTH_SPACE) << current.get_name() << '|';
    }
    
    cout << endl;
    cout << line;
    cout << "\n";
    
    for (int x = 0; x < largest_size; x++){
        
        cout << '|';

        for (int y = 0; y < vector_size; y++){
            
            int  temp_size = input.access_matrix()[y].get_size()-1;
            
            if (x > temp_size){
                
                cout << right << ' ';
                
            } else {
                string cont = static_cast<string>(input.access_matrix()[y].get_contents()[x]);
                
//                if (cont.size() > input.get_largest_name_size()){ //This part here is for really long strings as elements.
//                    int lns = input.get_largest_name_size();
//                    int divlns = cont.size()/lns;
//
//                    for (int too = 0; too <= divlns; too++)
//                        for (int foo = too*lns; foo < lns; foo++){
//                            cout << internal << setw(WIDTH_SPACE) << cont[foo] << '-' << '|'; //- symbolises longer string.
//                    }
//                } //Commented this out for now because there are some quricks left.
                
                cout << internal << setw(WIDTH_SPACE) << cont << '|'; //this is the normal case
            }
        }
        cout << endl;
    }
    cout << line << endl;
}
