//
//  Handler.cpp
//  xcode_csv
//
//  Created by Ludwig Jonsson on 15/12/2019.
//  Copyright © 2019 Ludwig Jonsson. All rights reserved.
//

#include "Handler.hpp"

using namespace ::std;


//Handles how we open .csv files
Wrapper Handler::open_csv(string name_input){
    
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
    
    INFILE.close();
    
        Wrapper wrapper(column_vector);
    
        return wrapper;
        
    }



void Handler::display_csv(Wrapper input){
    
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
                
                cout << internal << setw(WIDTH_SPACE) << ' ' << '|';
                
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

void Handler::save_csv(Wrapper input){
    
    fstream OUTFILE;
    OUTFILE.open("output.csv", ofstream::out);
    
    const int vector_size = input.access_matrix().size();
    const int largest_col = input.get_largest_size();
    
    for (int v = 0; v < vector_size; v++){
        
        OUTFILE << input.access_matrix()[v].get_name();
        
        if (v < vector_size - 1){
            OUTFILE << ',';
        }
    }
    OUTFILE << endl;
    
    for (int x = 0; x < largest_col; x++){
        
        for (int y = 0; y < vector_size; y++){
            
            if (x < input.access_matrix()[y].get_contents().size()){
            string out = input.access_matrix()[y].get_contents()[x];
            
            OUTFILE << out;
            
            if (y < vector_size - 1){
                OUTFILE << ',';
            }
            } else {
                OUTFILE << ',';
            }
            
        }
        OUTFILE << endl;
    }
    
    OUTFILE.close();
}

void Handler::sum(Wrapper &input){
    
    string column;
    double sum = 0;
    stringstream push_string;
    
    cout << "\nPlease enter the name of the column to sum: ";
    cin >> column;
    
    for (int x = 0; x < input.access_matrix().size(); x++){
        
        if (input.access_matrix()[x].get_name() == column){
            vector<string> vec = input.access_matrix()[x].get_contents();
            
            for (int y = 0; y < vec.size(); y++){
                
                if (vec[y] != ""){
                sum += stod(vec[y]);
                }
            }
            
            double tmp_sum = (int)(sum * 100 + 0.5);
            double final_sum = (double)tmp_sum/100;
            push_string << final_sum;
            input.access_matrix()[x].change_contents().push_back(push_string.str());
            cout << "\nSum was equal to: " << final_sum << " and is stored at the end of its corresponding column" << endl;
            input.set_largest_size();
            return;
        }
        
    }
    
    //It will only get to this point if the column cannot be found
    cout << "\nColumn name not found. Please try again" << endl;
    return;
}

void Handler::average(Wrapper &input){
    
    
    string column;
    double sum = 0;
    stringstream push_string;
    int count = 0;
       
    cout << "\nPlease enter the name of the column to average: ";
    cin >> column;
    
    for (int x = 0; x < input.access_matrix().size(); x++){
           
        if (input.access_matrix()[x].get_name() == column){
            vector<string> vec = input.access_matrix()[x].get_contents();
            
            for (int y = 0; y < vec.size(); y++){
                   
                if (vec[y] != ""){
                    sum += stod(vec[y]);
                    count++;
                   }
               }
            
            if (count != 0){
            
                double avg_sum = sum/count;
            
                double tmp_sum = (int)(avg_sum * 100 + 0.5);
                double final_sum = (double)tmp_sum/100;
            
               
               push_string << final_sum;
               input.access_matrix()[x].change_contents().push_back(push_string.str());
               cout << "\nAverage was equal to: " << final_sum << " and is stored at the end of its corresponding column" << endl;
               input.set_largest_size();
            }
               return;
           }
           
       }
       
       //It will only get to this point if the column cannot be found
       cout << "\nColumn name not found. Please try again" << endl;
       return;
    
}
