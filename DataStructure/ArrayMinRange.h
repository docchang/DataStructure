//
//  ArrayMinRange.h
//  DataStructure
//
//  Created by Dominic Chang on 2/25/14.
//  Copyright (c) 2014 Dominic Chang. All rights reserved.
//

#ifndef DataStructure_ArrayMinRange_h
#define DataStructure_ArrayMinRange_h

#include "Typedef.h"

#include "Constant.h"


class ArrayMinRange {
    
public:
    
    static void resetArrayBool(v_bool & arrayBool) {
        for(v_bool_iter iter = arrayBool.begin(); iter != arrayBool.end(); iter++) {
            *iter = false;
        }
    }
    
    
    static bool pairCompare(const p_int_int& firstElem, const p_int_int& secondElem) {
        return firstElem.first < secondElem.first;
    }
    
    
    static bool checkHitList(vector<v_p_int_int_iter> list , v_p_int_int_iter checkAgainst) {
        for(int i = 0; i < list.size(); i++) {
            if (list[i] == checkAgainst) {return false;}
        }
        return true;
    }
    
    
    //find minimum
    static v_p_int_int_iter findMinHitList(vector<v_p_int_int_iter> & list) {
        
        v_p_int_int_iter minValueIter = list[0];
        
        for(int i = 1; i < list.size(); i++) {

            if (minValueIter->first > list[i]->first) {
                minValueIter = list[i];
            }
            
        }
        
        return minValueIter;
    }
    
    
    static void printPair(v_p_int_int_iter pairIter) {
        cout << pairIter->first << ":(" << pairIter->second << ")" << endl;
    }
    
    
    static void printMinRangeIter(pair<v_p_int_int_iter , v_p_int_int_iter> minRange) {
        cout << "Minimum:";
        printPair(minRange.first);
        cout << "Maxmum:";
        printPair(minRange.second);
    }
    
    static int calculateMinRangeValue(pair<v_p_int_int_iter , v_p_int_int_iter> minRange) {
        return minRange.second->first - minRange.first->first;
    }
    
    
    static pair<int,int> FindMinRange(v_v_int ArrayList) {
        
        //combine ArrayList
        
        v_p_int_int combinedArray;
        
        //pair <Value , Array#>
        
        for (int ai = 0; ai < ArrayList.size(); ai++) {

            for (v_int_iter itemIter = ArrayList[ai].begin(); itemIter != ArrayList[ai].end(); itemIter++) {
                
                pair<int , int> valuePair = make_pair(*itemIter , ai);
                
                combinedArray.push_back(valuePair);
                
            }
        }
        
        //sort combined arraylist by first element
        sort(combinedArray.begin(), combinedArray.end(), pairCompare);
        
        for (v_p_int_int_iter iter = combinedArray.begin(); iter != combinedArray.end(); iter++) {
            
//            cout << iter->first << ":(" << iter->second << ")" << endl;
            
            printPair(iter);
            
        }
        
        
        
        vector<v_p_int_int_iter> ArrayHitList;
        
        //initialize to the end of pointer
        for (int i = 0; i < ArrayList.size(); i++) {
            ArrayHitList.push_back(combinedArray.end());
        }

        pair<v_p_int_int_iter , v_p_int_int_iter> minRange = make_pair(combinedArray.end(), combinedArray.end());
        
        
        //walking through the list
        for (v_p_int_int_iter iter = combinedArray.begin(); iter != combinedArray.end(); iter++) {

//            cout << iter->first << ":(" << iter->second << ")" << endl;
            printPair(iter);
            
            //replace the ArrayHitList iterator
            ArrayHitList[iter->second] = iter;

            bool hitAll = checkHitList(ArrayHitList , combinedArray.end());
            
            if (hitAll) {
                v_p_int_int_iter minIter = findMinHitList(ArrayHitList);
//                cout << "minimum iter:" << minIter->first << ":(" << minIter->second << ")" << endl;
                
                //empty minRange
                if (minRange.first == combinedArray.end()) {
                    minRange.first = minIter;
                    minRange.second = iter;
                    
                    printMinRangeIter(minRange);
                    continue;
                }
                
                //minRange exist
                if (minRange.first != minIter) {
                    
                    //new min range
                    pair<v_p_int_int_iter , v_p_int_int_iter> newMinRange = make_pair(minIter , iter);
                    
                    if (calculateMinRangeValue(newMinRange) < calculateMinRangeValue(minRange)) {
                        minRange = newMinRange;
                        printMinRangeIter(minRange);
                    }

                }
                
            }
            
        }
        
        return make_pair(minRange.first->first , minRange.second->first);
    }
    
    
    static void testArrayMinRange() {
        
        const int maxArray = 5;
        
        const int maxNumber = 40;
        
        const int maxSize = 10;
        
        const int arrayCount = ARC4RANDOM(maxArray) + 1;
        
        v_v_int problem;
        
        for (int i = 0; i < arrayCount; i++) {
            
            const int arraySize = ARC4RANDOM(maxSize) + 1;
            
            v_int array;
            
            cout << "Array(" << i << "):";
            
            for (int s = 0; s < arraySize; s++) {
                
                int value = ARC4RANDOM(maxNumber) + 1;
                
                array.push_back(value);
                
                
            }
            
            //sort the array
            std::sort(array.begin() , array.end());
            
            //print it out
            for (v_int_iter iter = array.begin(); iter != array.end(); iter++) {
                cout << *iter << " ";
            }
            cout << endl;
            
            
            problem.push_back(array);

        }
        
        pair<int , int> answer = FindMinRange(problem);
        
        cout << "(" << answer.first << " , " << answer.second << ")" << endl;

    }
    
};


#endif
