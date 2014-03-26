//
//  ReverseSentence.h
//  DataStructure
//
//  Created by Dominic Chang on 3/25/14.
//  Copyright (c) 2014 Dominic Chang. All rights reserved.
//

#ifndef __DataStructure__ReverseSentence__
#define __DataStructure__ReverseSentence__

#include <iostream>

#include "Constant.h"

#include "Typedef.h"


class ReverseSentence {
    
    
public:
    
    static string reverseSentence(string sentence) {
        
        //reverse string
        std::reverse(sentence.begin(), sentence.end());
        
        std::string::iterator beginIter = sentence.begin();

        for (std::string::iterator iter = beginIter + 1; iter != sentence.end(); iter++) {
            
            if (!isalpha(*iter)) {
                std::reverse(beginIter , iter);
                beginIter = iter + 1;
            }
            
        }
        
        std::reverse(beginIter , sentence.end());

        return sentence;
    }
    
    static void testReverseSentence () {
        
        v_str testStr = {
            "My name is Dominic Chang",
            "Hello World"
        };
        
        
        for (v_str_iter iter = testStr.begin(); iter != testStr.end(); iter++) {
            
            cout << *iter << ":" << reverseSentence(*iter) << endl;
            
        }
        
        
    }
    
};




#endif /* defined(__DataStructure__ReverseSentence__) */
