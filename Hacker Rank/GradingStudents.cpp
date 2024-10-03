#include<bits/stdc++.h>
using namespace std;

int roundGrade(int num){
        while(num % 5 != 0)
            num++;
        return num;    
}

vector<int> gradingStudents(vector<int> &grades) {
    vector<int>result;
    
    for(int i =0;i<grades.size();i++){
            if(grades[i] >= 38){
                int no = roundGrade(grades[i]);
                if((no - grades[i]) < 3)    
                    result.push_back(no);
                else 
                    result.push_back(grades[i]);    
          
            }else{
                result.push_back(grades[i]);
            }
    } 

    return result;         
}

int main(){
    vector<int> grades = {73,67,38,33};
    vector<int> result = gradingStudents(grades);
    
    for (auto i : result){
        cout<<" "<<i;
    }

    
    
}