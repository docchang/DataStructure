//
//  Typedef.h
//  DataStructure
//
//  Created by Dominic Chang on 2/18/14.
//  Copyright (c) 2014 Dominic Chang. All rights reserved.
//

#ifndef DataStructure_Typedef_h
#define DataStructure_Typedef_h

#include <vector>

using namespace std;

typedef vector<string> v_str;
typedef v_str::iterator v_str_iter;


typedef vector<int> v_int;
typedef v_int::iterator v_int_iter;


typedef vector<v_int> v_v_int;
typedef v_v_int::iterator v_v_int_iter;

typedef pair<int,int> p_int_int;


typedef vector<p_int_int> v_p_int_int;
typedef v_p_int_int::iterator v_p_int_int_iter;





typedef vector<bool> v_bool;
typedef v_bool::iterator v_bool_iter;






#endif
