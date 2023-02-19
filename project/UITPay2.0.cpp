#include<iostream>
#include <string.h>
#include <vector>

using namespace std; 

struct Student{
    string name; 
    int roll_number;
    int points;

    int view_points() const{
        return points; 
    }

    void spend_points(int amount){
        if(points >= amount){
            points -= amount; 
        }
    }
}


int main(){


    return 0; 
}