//
//  TopBox.h
//  DataStructure
//
//  Created by Dominic Chang on 3/11/14.
//  Copyright (c) 2014 Dominic Chang. All rights reserved.
//

#ifndef __DataStructure__TopBox__
#define __DataStructure__TopBox__


#include <iostream>

#include "Constant.h"

#include "Typedef.h"



static vector<vector<char>> TopBoxSet = {
    {'a' , 'b' , 'c' , 'd' , 'e'},
    {'f' , 'g' , 'h' , 'i' , 'j'},
    {'k' , 'l' , 'm' , 'n' , 'o'},
    {'p' , 'q' , 'r' , 's' , 't'},
    {'u' , 'v' , 'w' , 'x' , 'y'},
    {'z'}
};



//http://www.careercup.com/question?id=5127611667709952


class TopBox {
    
public:
    

    
    static string generateTopBoxString() {
        const int size = 3 + ARC4RANDOM(4);
        
        char cstr[size+1];
        
        for (int i = 0; i < size; i++) {
            
            //randomly generate a character
            cstr[i] = 'a' + (char)ARC4RANDOM(26);
            
        }
        
        cstr[size] = NULL;
        
        return string(cstr);
    }
    
    static p_int_int charToIndex(char c) {
        int index = c - 'a';
        return make_pair((int)(index / TopBoxSet[0].size()) , (int)(index % TopBoxSet[0].size()));
    }
    
    
    static char TopBoxChar(p_int_int index) { return TopBoxSet[index.first][index.second]; }
    
    
    //index0 -> index1
    //index(column , row)
    static void TopBoxSolverHelper(p_int_int index0 , p_int_int index1) {
        
        if (index0.first == index1.first && index0.second == index1.second) { return; }
        
        if (index1.first > index0.first && index0.second < TopBoxSet[index0.first+1].size()) {
            
            cout << "DOWN" << endl;
            
            index0.first++;

        } else if (index1.first < index0.first && index0.second < TopBoxSet[index0.first-1].size()) {
            
            cout << "UP" << endl;
            
            index0.first--;

        } else if (index1.second > index0.second && index0.second + 1 < TopBoxSet[index0.first].size()) {
            
            cout << "RIGHT" << endl;
            
            index0.second++;

        } else if (index1.second < index0.second && index0.second - 1 >= 0) {
            
            cout << "LEFT" << endl;
            
            index0.second--;

        }
        
        
        TopBoxSolverHelper(index0 , index1);

    }
    
    static void PrintIndexPair(string text , p_int_int indexPair) {
        cout << text << ":(" << indexPair.first << "," << indexPair.second << ")";
    }
    
    static void TopBoxSolver(string str) {
        
        cout << "Solving:" << str << endl;
        
        p_int_int preIndexPair = make_pair(0, 0);
        
        for(int i = 0; i < str.length(); i++) {
            p_int_int curIndexPair = charToIndex(str[i]);
            
            
            PrintIndexPair("From" , preIndexPair);
            cout << TopBoxChar(preIndexPair) << " ";
            PrintIndexPair("To" , curIndexPair);
            cout << TopBoxChar(curIndexPair) << endl;
            
            
            //solver
            TopBoxSolverHelper(preIndexPair , curIndexPair);
            
            cout << "OK <---- to select:" << TopBoxChar(curIndexPair) << endl;

            
            preIndexPair = curIndexPair;
        }
        
        cout << endl;
        cout << endl;
        
    }

    static void testTopBox() {

        for (int i = 0; i < 100; i++) {
            
            TopBoxSolver(TopBox::generateTopBoxString());
            
        }

    }
    
    
};

#endif /* defined(__DataStructure__TopBox__) */
