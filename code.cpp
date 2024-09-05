#include<iostream>
#include<vector>
using namespace std;

vector<string> controller;
int itr=-1;

void print(string &s){
    if(s.length() ==0){
        cout << "There is no string to display" << endl;
        return;
    }
    int num =1;
    cout << num << ". ";
    for(int i=0; i<s.length(); i++){
                if(s[i] == '.'){
                    i=i+1;
                    cout << endl;
                    if(i< s.length()){
                        num++;
                        cout << num << ". ";
                    }
                }
                cout << s[i];
            }
}

void add(string &s){
    cout << "Enter the string -> " << endl;
    string addString;
    getline(cin >> ws, addString);
    s = s + addString + "." ;
    for(int i=itr+1; i<controller.size(); i++){
        controller.pop_back();
    }
    controller.push_back(s);
    itr++;
}

void update(string &s){
    if(s.length() ==0){
        cout << "There is no string to update" << endl;
        return;
    }
    string updateString;
    print(s);
    cout << "Enter the Line number you want update ";
    int updLine, updFirstIndex, updLastIndex;
    cin>> updLine;
    int count=1, strLength=0;
    for(int i=0; i<s.length(); i++){
        if(count == updLine){
            updFirstIndex = i;
            while(i<s.length() && count == updLine){
                if(s[i] == '.'){
                    count++;
                }
                strLength++;
                i++;
            }
            if(i<s.length())
            updLastIndex = i;
            i=s.length();
        }
        if(i<s.length() && s[i] == '.'){
            count++;
        }
    }
    if(strLength == 0){
        cout << "There is no string to update" << endl;
        return;
    }
    cout << "Enter the string -> ";
    getline(cin >> ws, updateString);
    updateString = updateString + ".";
    s.replace(updFirstIndex, strLength, updateString);
    for(int i=itr+1; i<controller.size(); i++){
        controller.pop_back();
    }
    controller.push_back(s);
    itr++;
}

void del(string &s){
    if(s.length() ==0){
        cout << "There is no string to delete" << endl;
        return;
    }
    print(s);
    cout << "Enter the Line number you want delete ";
    int delLine, delFirstIndex, delLastIndex;
    cin>> delLine;
    int count=1, strLength=0;
    for(int i=0; i<s.length(); i++){
        if(count == delLine){
            delFirstIndex = i;
            while(i<s.length() && count == delLine){
                if(s[i] == '.'){
                    count++;
                }
                strLength++;
                i++;
            }
            delLastIndex = i;
            i=s.length();
        }
        if(i<s.length() && s[i] == '.'){
            count++;
        }
    }
    if(strLength == 0){
        cout << "There is no string to delete" << endl;
        return;
    }
    s.erase(delFirstIndex, strLength);
    for(int i=itr+1; i<controller.size(); i++){
        controller.pop_back();
    }
    controller.push_back(s);
    itr++;
}


int main(){
    string s="";
    while(1){
        cout << "1 -------> Add"<< endl;
        cout << "2 -------> Update"<< endl;
        cout << "3 -------> Delete"<< endl;
        cout << "4 -------> Undo"<< endl;
        cout << "5 -------> Redo"<< endl;
        cout << "6 -------> Display"<< endl;
        cout << "7 -------> To exit program"<< endl;
        cout << "Enter the Number to perform the operation ";
        int number;
        cin >> number;
        cout << endl;
        if(number<1 || number>7){
            exit(0);
        }
        if(number == 1){
            add(s);
        }
        
        if(number ==2){
            update(s);
        }
        
        if(number == 3){
            del(s);
        }
            
        
        if(number == 4){
            if(itr-1>=0){

            s = controller[--itr];
            }
        }
        
        if(number == 5){
            if(itr+1<controller.size()){

                s = controller[++itr];
            }
        }
        
        if(number ==6){
            print(s);
        }
        
        if(number == 7)
            exit(0);

        cout << "*****************************************************" << endl << endl;
    }
}
