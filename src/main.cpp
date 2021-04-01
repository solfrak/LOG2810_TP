#include <iostream>
#include <bits/stdc++.h>
#include "Covid.h"
using namespace std;

int main() 
{
    Covid test;
    test.loadDoc();
    std::cout << test.contacts.size() << std::endl;
     for(auto& it : test.contacts){
       it->print();
    }
 
}