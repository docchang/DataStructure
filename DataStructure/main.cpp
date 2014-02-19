//
//  main.cpp
//  DataStructure
//
//  Created by Dominic Chang on 1/21/14.
//  Copyright (c) 2014 Dominic Chang. All rights reserved.
//

#include <iostream>

#include <sstream>

#include "BinaryTree.h"

#include "Constant.h"

// Source:  http://www.careercup.com/question?id=4787357697966080
void testBinaryTree() {
    BinaryTree * b = new BinaryTree();
    
    b->insertRandom(10);
    
    b->PreOrderTraversal();
    b->InOrderTraversal();
    b->PostOrderTraversal();
    
    
    std::stringstream ss;
    
    ss << *b;
    
    std::string serializedTree(ss.str());
    
    std::cout << DebugLog << serializedTree << endl;
    
    BinaryTree * deserialized;
    
    ss >> deserialized;
    
    deserialized->PreOrderTraversal();
    deserialized->InOrderTraversal();
    deserialized->PostOrderTraversal();
}


void testBSTValidation() {
    
    BinaryTree * b = new BinaryTree();
    
    b->insertRandom(20);
    
//    for (int i = 0; i < 20; i++) {
//        b->insert(ARC4RANDOM(1000));
//    }
    
    
    b->InOrder(b->head);
    
    
    Node<int> * previousNode = NULL;
    
    bool isValid = b->BSTValidation(b->head, previousNode);
    
    cout << "BST valid:" << isValid << endl;
    
}

void testBottomUpTraversal() {
    BinaryTree * b = new BinaryTree();
    
    b->insertRandom(10);

    b->InOrderTraversal();
    
    std::queue<Node<int> *> q;
    
    q.push(b->head);
    
    b->BottomUpTraversal(q);
    
}

#include <vector>
using namespace std;


#include <ctype.h>



// Determine the most frequent letter in a string:
char determineMostFrequentLetter(string text)
{
    // Your code goes here
    
    if (text.length() == 0) {
        return NULL;
    }
    
    if (text.length() == 1) {
        return text[0];
    }
    
    
    // sort text
    
    //convert string to char[]
    char * cstr = (char *)text.c_str();
    
    //remember the text length
    const int cstrLength = (int)strlen(cstr);
    
    //sort O(n log n)
    std::sort(cstr , cstr + cstrLength);
    
    
    //initialize to integer minimum
    int maxCount = INT_MIN;
    int maxCharIndex = -1;
    
    
    //runtime: O(n)
    
    char occuring = cstr[0];
    int occuringCount = 0;
    for (int i = 1; i < cstrLength; i++) {
            
        if (!isalpha(cstr[i])) { continue; }
        
        if (cstr[i] == occuring) {
            occuringCount++;
        } else {
            occuring = cstr[i];
            occuringCount = 0;
        }
        
        
        if (maxCount < occuringCount) {
            maxCount = occuringCount;
            maxCharIndex = i;
        }
        
    }
    
    
    
    return cstr[maxCharIndex];
}

//assert(determineMostFrequentLetter("The lazy brown dog jumped on it") == 'o');
//assert(determineMostFrequentLetter("The lazy brown dog jumped on it") == 'o');


// Source:  http://www.careercup.com/question?id=15206700
void test_TwoSum() {
    //generate vector
    
    vector<int> sumarray;
    
    const int size = 1000;
    const int maxNum = 100;
    
    
    //generate an integer array
    for (int i = 0; i < size; i++) {
        sumarray.push_back(ARC4RANDOM(maxNum));
    }
    //sorted
    sort(sumarray.begin(), sumarray.end());
    
    
    //genearte a sum to find
    const int sum = 2 * ARC4RANDOM(maxNum);
    
    int count = 0;
    {
        
        unsigned int i = 0;
        unsigned int j = (unsigned int)sumarray.size() - 1;
        
        while (j > i) {
            if (sumarray[i] + sumarray[j] > sum) {
                j--;
            } else if (sumarray[i] + sumarray[j] < sum) {
                i++;
            } else {
                
                const unsigned int indexI = i;
                const unsigned int indexJ = j;
                while (j > i) {
                    if (sumarray[i] != sumarray[indexI] && sumarray[j] != sumarray[indexJ]) {break;}
                    if (sumarray[i] == sumarray[indexI]) {i++;}
                    if (sumarray[j] == sumarray[indexJ]) {j--;}
                }
                
                for (int c = indexI; c < i; c++) {
                    for (int b = indexJ; b > j; b--) {
                        cout << DebugLog << "(" << c << " , " << b << ") : " << sumarray[c] << " + " << sumarray[b] << " = " << sum << endl;
                        count++;
                    }
                }
            }
        }
        
        cout << DebugLog << "Sum Count:" << count << endl;
    }
}


/* Function to print permutations of string
 This function takes three parameters:
 1. String
 2. Starting index of the string
 3. Ending index of the string. */
void permute(string str, int i, int n) {
    
    if (i == n) { cout << str << endl; return; }

    for (int j = i; j <= n; j++) {
        std::swap(str[i], str[j]);
        
        permute(str, i+1, n);
        
        //switchback
        std::swap(str[i], str[j]);
    }
}



#include <vector>
using namespace std;

//initialize isComposite array of maxNum size of booleans
//upper bound is 1M
#define MAX_UPPERBOUND 1000000
vector<bool> isPrime(MAX_UPPERBOUND , true);


//http://www.careercup.com/question?id=5686016069337088
vector<int> SieveEratosthenes(int maxNum) {
    
    double timestamp = timeintervalSinceEvolution();
    
    if (maxNum > MAX_UPPERBOUND - 1) {
        maxNum = MAX_UPPERBOUND - 1;
        cout << "Max number exceed upper bound: " << MAX_UPPERBOUND << endl;
    }
    
    //calculate upperbound
    const int upperBound = (int)sqrt((double)maxNum);
    
//    //initialize isComposite array of maxNum size of booleans
//    vector<bool> isPrime(maxNum , true);
    
    
    //go through isPrime and cross out composites
    for (int i = 2; i <= upperBound; i++) {
        
        if (isPrime[i] == false) { continue; }
        
        //break when exceed maxnum
        if (i * i > maxNum) { break; }
        
        for (int k = i * i; k <= maxNum; k = k + i) {
            isPrime[k] = false;
        }
        
    }
    
    cout << "Runtime:" << timeintervalSinceEvolution() - timestamp << "for upper bound " << maxNum << endl;
    
    //prepare result
    vector<int> PrimeNumber;
    for(int i = 2; i <= maxNum; i++) {
        if (isPrime[i] == false) { continue; }
        PrimeNumber.push_back(i);
//        cout << i << endl;
    }
    
    
    
    return PrimeNumber;
}


int up_10pow(int n) {
    int ans = 1;
    while (ans < n) ans *= 10;
    return ans;
}

bool LexicalLess(int v1, int v2) {
    
    int ceil1 = up_10pow(v1);
    int ceil2 = up_10pow(v2);
    
    cout << ceil1 << ":" << v1 << endl;
    cout << ceil2 << ":" << v2 << endl;
    
    while ( ceil1 != 0 && ceil2 != 0) {
        if (v1 / ceil1  < v2 / ceil2) return true;
        else if (v1 / ceil1 > v2 / ceil2) return false;
        ceil1 /= 10;
        ceil2 /= 10;
    }
    
    return (v1 < v2) ? true : false;
}


// write a function that sort numbers in lexicographic order
// e.g. { 1 , 10 , 11 , 100 , 112 , 2 , ...
// assuming all positive numbers




//helper function that generates 10^digits of a number
// e.g. number:12345 result: 1000000
int TenBaseGen(int number) {
    if (number == 0) return 1;
    return powf(10.0f, floorf( log10f(number) ));
}


bool LexicoLess2(int v1 , int v2) {
    
    int v1TenBase = TenBaseGen(v1);
    int v2TenBase = TenBaseGen(v2);
    
    while (v1TenBase > 0 || v2TenBase > 0) {
        
        const int digitV1 = v1TenBase == 0 ? 0 : v1 / v1TenBase;
        const int digitV2 = v2TenBase == 0 ? 0 : v2 / v2TenBase;
        
        if (digitV1 < digitV2) { return true; }
        if (digitV1 > digitV2) { return false; }
        
        v1TenBase /= 10;
        v2TenBase /= 10;
    }
    
    return false;
}

#define ARC4RANDOM(max) (arc4random() % (int)(max))
//#define ARC4RANDOM(min , max) (arc4random() % (int)(max))
//[min , max)
inline int getRandom(int min, int max) { return (arc4random() % (max - min)) + min; }

vector<int> numberList;
void testLexico() {
    
    for (int i = 0; i < 100; i++) {
        numberList.push_back(ARC4RANDOM(1000));
    }
    
    std::sort(numberList.begin() , numberList.end(), LexicoLess2);
    
    for (vector<int>::iterator iter = numberList.begin(); iter != numberList.end(); iter++) {
        cout << *iter << endl;
    }
}


char * sortCharacter(string str) {
    //convert string to char array
    char * cstr = (char*)str.c_str();
    
    //sort by character
    std::sort(cstr, cstr + strlen(cstr));
    
    
    return cstr;
    
//    //create return string
//    string retStr(cstr);
//    
//    //return
//    return retStr;
}


bool anagramCompareLess(string str1 , string str2) {
    
    char * sortcStr1 = sortCharacter(str1);
    char * sortcStr2 = sortCharacter(str2);
    
    
    
    int cmpValue = strcmp(sortcStr1 , sortcStr2);
    
    
//    cout << sortcStr1 << " " << sortcStr2 << ":" << cmpValue << endl;
    
    return cmpValue > 0;
    
    
//    return cmpValue;
}


//there are 26 letters

string generateCharacter(const unsigned int size) {
    if (size == 0) return NULL;
    
    //allocate memory
    char * newChar = new char(size + 1);
    
    //null delimites
    newChar[size] = NULL;
    
    //generate characters
    for (int i = 0; i < size; i++) {
        newChar[i] = (char)('a' + ARC4RANDOM(26));
    }
    
    //create string object
    string retStr(newChar);
    
    //delete allocated memory
    delete newChar;
    
    return retStr;
}


#include "Typedef.h"

//typedef vector<string> v_str;
//typedef v_str::iterator v_str_iter;

void testAnagramCompareSort() {
    
    
    
    v_str stringVector;
    for(int i = 0; i < 10000; i++) {
        stringVector.push_back(generateCharacter(getRandom(4, 5)));
    }
    
    
//    v_str stringVector = {
//        "asdf" ,
//        "a" ,
//        "slsla" ,
//        "qwopq" ,
//        "awoij" ,
//        "lsals" ,
//        "sfda"
//    };
    

    std::sort(stringVector.begin(), stringVector.end(), anagramCompareLess);
//    std::sort(stringVector.begin(), stringVector.end());
    
    
    //print
    for (v_str_iter iter = stringVector.begin(); iter != stringVector.end(); iter++) {
        cout << *iter << endl;
    }
    
    

    
}

v_str Number_Singles ({
    " Zero",
    " One",
    " Two",
    " Three",
    " Four",
    " Five",
    " Six",
    " Seven",
    " Eight",
    " Nine",
    " Ten",
    " Eleven",
    " Twelve",
    " Thirteen",
    " Fourteen",
    " Fifteen",
    " Sixteen",
    " Seventeen",
    " Eighteen",
    " Nineteen"
});

v_str Number_Tens({
    "",
    " Ten",
    " Twenty",
    " Thirty",
    " Forty",
    " Fifty",
    " Sixty",
    " Seventy",
    " Eighty",
    " Ninety"
});

v_str Number_Thousands({
    " Hundred",
    " Thousand",
    " Million",
    " Billion",
    " Trillion"
});

string ThousandWriter(unsigned int hundred , unsigned int ten , unsigned int single) {
    
    string result;
    
    //ten , eleven , ... nineteen
    if (ten == 1) {
        
        result = Number_Singles[10 + single];
        
    } else {
        
        //singles
        if (single > 0) {
            result = Number_Singles[single];
        }
        
        //Twenty ...
        if (ten > 1) {
            result = Number_Tens[ten] + result;
        }
        
    }
    
    //hundreds
    if (hundred > 0) {
        result = Number_Singles[hundred] + Number_Thousands[0] + result;
    }
    
    
    return result;
}

string numberWriter(unsigned long value , unsigned int level) {
    
    if (value == 0 && level == 0) {
        return Number_Singles[0];
    }
    
    
    if (value == 0) {
        return "";
    }
    

    //parse 3 digits
    unsigned int single = value % 10;
    
    value /= 10;
    
    unsigned int ten = value % 10;
    
    value /= 10;
    
    unsigned int hundred = value % 10;
    
    value /= 10;
    
//    cout << hundred << ":" << ten << ":" << single << endl;
    
    
    string levelString;
    if (level > 0 && hundred + ten + single > 0) {
        levelString = Number_Thousands[level];
    }

    
    return numberWriter(value , level + 1) + ThousandWriter(hundred, ten, single) + levelString;
}


typedef vector<unsigned long> v_ulong;
typedef v_ulong::iterator v_ulong_iter;

void testNumberWriter() {
    for (int i = 0; i < 1000; i++) {
        unsigned long number = ARC4RANDOM(10000000);
        cout << number << " :" << numberWriter(number , 0) << endl;
    }
    
    v_ulong specialCasesNumbers({
        10000000000000,
        9000000000,
        10000,
        100,
        10,
        0
    });
    
    for (v_ulong_iter iter = specialCasesNumbers.begin(); iter != specialCasesNumbers.end(); iter++) {
        cout << *iter << " :" << numberWriter(*iter, 0) << endl;
    }

}



#include <unordered_map>

class StringHashFunction {
public:
    std::size_t operator ()(const std::string & str) const {
        std::hash<std::string> hash_fn;
        std::size_t str_hash = hash_fn(str);
        return str_hash;
    }
};
class StringEqual {
public:
    bool operator ()(const std::string & str1, const std::string & str2) const {
        return strcmp(str1.c_str(), str2.c_str()) == 0;
    }
};


typedef unordered_map<string, unsigned long> um_s_l;
typedef um_s_l::iterator um_s_l_iter;


typedef unordered_map<char, bool> um_c_b;
typedef um_c_b::iterator um_c_b_iter;



void testHashTable() {
//    unordered_map<string, unsigned long, StringHashFunction, StringEqual> stringHashTable;
//    um_s_l stringHashTable;
//    stringHashTable.insert({
//        {"Pimp",411},
//        {"Hoes",242},
//        {"Money",123},
//        {"More Hoes",1411}
//    });
//    for (auto& x: stringHashTable)
//        std::cout << x.first << ": " << x.second << std::endl;
    
    
    um_c_b charMap;
    
    //ASCII set common keyboard characters <space> 32 -> <del> 127
    for (int i = 0; i < 100; i++) {
        
        //generate keyboard visible characters
        const char generatedChar = getRandom((int)' ', (int)'~' + 1);

        //search using hash table
        um_c_b_iter iter = charMap.find(generatedChar);

        //check exist
        if (iter == charMap.end()) {
            cout << "inserting... " << generatedChar << endl;
            charMap.insert({{generatedChar , true}});
            continue;
        }

        cout << "Collusion detected after " << i << " iterations : " << iter->first << endl;
        return;
    }
}


bool multipleOf(const int value , const int multiple) {
    
    unsigned int mask = multiple;
    
    while (mask < value) {
//        cout << "Mask:" << mask << endl;
        mask += multiple;
    }
    
    return mask == value;
}


void testMultipleOf() {

    for (int i = 0; i < 1000; i++) {
        
        const int value = ARC4RANDOM(100000);
        
        const int multiple = 5;
        
        string notStr = multipleOf(value, multiple) ? " is " : " is NOT ";
        
        cout << value <<  notStr << "a multiple of" << multiple << endl;
    }

}


#include "RPNEvaluate.h"

int main(int argc, const char * argv[])
{
    std::cout << DebugLog << "Hello, World!\n";
    
    string input;
    
    do {
        
        RPNEvaluate::testRPNEvaluate();
        
//        cout << determineMostFrequentLetter("Hello World 1 2 3 mah mah sooo") << endl;
    
//        testBinaryTree();
        
//        testBSTValidation();
        
//        testBottomUpTraversal();
        
        
        
//        testHashTable();
        
//        testMultipleOf();
        
//        test_TwoSum();
//
//        string str("abcd");
//        permute(str, 0, (int)str.length()-1);
        

//        int maxNum = atoi(input.c_str());
//        vector<int> primes = SieveEratosthenes(maxNum);
//        
//        
//        //sort
//        std::sort(primes.begin(), primes.end(), LexicalLess);
//        for (vector<int>::iterator iter = primes.begin(); iter != primes.end(); iter++) {
//            cout << *iter << endl;
//        }

        
//        testLexico();
        
        
//        anagramCompareLess("fiwoa;asllks" , "World");
        
        
//        testAnagramCompareSort();
        
//        testNumberWriter();
        
        
    }while (cin >> input && input != "q");
    
    return 0;
}

