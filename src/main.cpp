#include <iostream>
#include <bits/stdc++.h>
#include "Covid.h"
using namespace std;

int main() 
{
    Covid test;
    test.loadDoc();
    for(int i =0; i < test.contacts.size(); i++){
        std::cout<< test.getContact(i)->print();
    }
}