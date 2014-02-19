//
//  RPNEvaluate.h
//  DataStructure
//
//  Created by Dominic Chang on 2/18/14.
//  Copyright (c) 2014 Dominic Chang. All rights reserved.
//

#ifndef __DataStructure__RPNEvaluate__
#define __DataStructure__RPNEvaluate__

#include <iostream>

#include <string>

#include <sstream>

#include <algorithm>

#include <iterator>

#include "Typedef.h"

#include <stack>

using namespace std;

class RPNEvaluate {
    
public:
    
    static vector<string> tokenize(string expr) {
        
        istringstream iss(expr);
        
        vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
        
        return tokens;
        
    }
    
#define EVAL_STACK(stack , operation) { \
    if (stack.size() == 0) { stack.push(999); break; } \
    int right = stack.top(); \
    stack.pop(); \
    if (stack.size() == 0) { stack.push(999); break; } \
    int left = stack.top(); \
    stack.pop(); \
    stack.push(left operation right); \
}

    
    static int evaluate (string expr) {
        
        stack<int> evalStack;
        
        v_str tokens = tokenize(expr);
        
        for (v_str_iter iter = tokens.begin(); iter != tokens.end(); iter++) {
            cout << *iter << endl;

            //determine if operator or number
            if (*iter == "+") {

                EVAL_STACK(evalStack , +);
                
            } else if (*iter == "-") {
                
                EVAL_STACK(evalStack , -);
                
            } else if (*iter == "*") {
                
                EVAL_STACK(evalStack , *);
                
            } else if (*iter == "~") {
                
                int left = evalStack.top();
                evalStack.pop();
                evalStack.push(-left);
                
            } else {    //number
                
                int value = atoi(iter->c_str());
                evalStack.push(value);
                
            }

        }

        return evalStack.top();
    }
    
    
    static void testRPNEvaluate() {
        vector<string> testExpr = {
            "2 3 + 6 ~ 7 * -" ,
            "5 ~ ~ ~",
            "9 8 7 * * 4 5 - -",
            "1 + 2 + 3",
            "1 9 ~ 2 * * +"
        };
        
        for (v_str_iter iter = testExpr.begin(); iter != testExpr.end(); iter++) {
            
            cout << evaluate(*iter) << endl;
            
        }
        
    }
    
};

#endif /* defined(__DataStructure__RPNEvaluate__) */
