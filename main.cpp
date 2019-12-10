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
#include "Column.hpp"
#include "Wrapper.hpp"

Wrapper open_csv(string name_input);
void display_csv(Wrapper);

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
            
            cout << "Please enter the name of your csv file and press enter: " << endl;
            cin >> csv_name;
            cout << endl;
            
            Wrapper wrapper(open_csv(csv_name));
            
            display_csv(wrapper);
            
        } else if (current_command == "exit"){
            cout << "\nShutting down..." <<  endl;
        } else {
            cout << "\nI don't feel so good..." << endl;
            exit(EXIT_FAILURE);
        }
        
        
    }//END OF PROGRAM LOOP
    
    return 0;
}

//Handles how we open .csv files
Wrapper open_csv(string name_input){
    
    vector<Column> column_vector;
    
    fstream INFILE;
    
    
    INFILE.open(name_input, ios::in);
    
    if (INFILE.is_open()){
        
        string line;
        string word;
        
        getline(INFILE, line);
        stringstream in_line(line);
        
        while (getline(in_line, word, ',')){
            
            Column column(word);
            column_vector.push_back(column);
            
        } // Now we have extracted the first line which contains the names.
        
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
        
    } else {
        
        cout << "Invalid file name. Terminating program" << endl;
        
        exit(EXIT_FAILURE);
    }
}


void display_csv(Wrapper input){
    
    const int vector_size = input.access_matrix().size();
    const int largest_size = input.get_largest_size();
    
    for (int p = 0; p < vector_size; p++){
        cout.width(10);
        cout << left << input.access_matrix()[p].get_name();
    }
    cout << endl << endl;
    
    for (int x = 0; x < largest_size; x++){
        for (int y = 0; y < vector_size; y++){
            
            int  temp_size = input.access_matrix()[y].get_size()-1;
            
            if (x > temp_size){
                cout.width(10);
                cout << left << "";
                
            } else {
                cout.width(10);
                cout << left << input.access_matrix()[y].get_contents()[x];
                
            }
            
            
        }
        
        cout << endl << endl;
    }
}
