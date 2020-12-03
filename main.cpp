#include <iostream>
#include <fstream>

using namespace std;

int day_1_1(){
    string line;
    int allNumbers [200];
    ifstream myfile ("Expense_Report.txt");

    if(myfile.is_open()){
        int i=0;
        while(getline(myfile, line)){
            allNumbers[i] = stoi (line,nullptr);
            i++;
        }
    }

    for(int i = 0; i < 200; i++){
        for(int j=i;j<200;j++){
            if(allNumbers[i]+allNumbers[j]==2020){
                //cout<<allNumbers[i]<<" + "<< allNumbers[j]<<endl;
                return allNumbers[i]*allNumbers[j];
            }
        }

    }

    return 0;

}

int day_1_2(){
    string line;
    int allNumbers [200];
    ifstream myfile ("Expense_Report.txt");

    if(myfile.is_open()){
        int i=0;
        while(getline(myfile, line)){
            allNumbers[i] = stoi (line,nullptr);
            i++;
        }
    }

    for(int i = 0; i < 200; i++){
        for(int j=i;j<200;j++){
            for(int k=j;k<200;k++){
                if(allNumbers[i]+allNumbers[j]+allNumbers[k]==2020){
                //cout<<allNumbers[i]<<" + "<< allNumbers[j]<<" + "<<allNumbers[k]<<endl;
                return allNumbers[i]*allNumbers[j]*allNumbers[k];
                }
            }
        }

    }

    return 0;


}

int day_2_1(){
    string passwords [1000];
    string line;
    ifstream myfile ("Passwords.txt");

    if(myfile.is_open()){
        int i=0;
        while(getline(myfile, line)){
            passwords[i] = line;     //stoi (line,nullptr);
            i++;
        }
    }
    int amount = 0;
    for(int i=0;i<1000;i++){
        string password = passwords[i];
        int low = stoi(password.substr(0,password.find("-")), nullptr);
        int high= stoi(password.substr(password.find("-")+1,password.find(" ")-password.find("-")-1), nullptr);
        char target = password[password.find(" ")+1];
        int _count = 0;
        for(int j=password.find(target)+1;j<password.size();j++){
            if(password[j] == target){
                _count++;
            }
        }
        if(low <= _count && _count <= high){
            amount++;
        }
    }

    return amount;
}

int day_2_2(){
    string passwords [1000];
    string line;
    ifstream myfile ("Passwords.txt");

    if(myfile.is_open()){
        int i=0;
        while(getline(myfile, line)){
            passwords[i] = line;     //stoi (line,nullptr);
            i++;
        }
    }
    int amount = 0;
    for(int i=0;i<1000;i++){
        string password = passwords[i];
        int low = stoi(password.substr(0,password.find("-")), nullptr)-1;
        int high= stoi(password.substr(password.find("-")+1,password.find(" ")-password.find("-")-1), nullptr)-1;
        char target = password[password.find(" ")+1];
        int _count = 0;
        int k = 0;
        for(int j=password.find(target)+3;j<password.size();j++){
            if(password[j] == target){
                if(low == k | high == k){
                    _count++;
                }
            }
            k++;
        }
        if(_count == 1){
            amount++;
        }
    }

    return amount;
}

int day_3_1(){
    string line;
    ifstream myfile ("Slope.txt");
    int x = 0;
    int _count = 0;

    if(myfile.is_open()){
        while(getline(myfile, line)){
            if(line[x] == '#'){
                _count++;
            }
            x = (x+3) % line.size();
        }
    }

    return _count;
}

int theFunctionFor3_2(int iX, int iY){
    string line;
    ifstream myfile ("Slope.txt");
    int x = 0;
    int y = 0;
    int _count = 0;
    if(myfile.is_open()){
        while(getline(myfile, line)){
            if(y % iY == 0){
                if(line[x] == '#'){
                    _count++;
                }
                x = (x+iX) % line.size();
            }
            y++;
        }
    }
    return _count;
}

int day_3_2(){
    return theFunctionFor3_2(1,1)*theFunctionFor3_2(3,1)*theFunctionFor3_2(5,1)*theFunctionFor3_2(7,1)*theFunctionFor3_2(1,2);
}

int main(){

cout << "Day 1 question 1 = " << day_1_1() << endl;
cout << "Day 1 question 2 = " << day_1_2() << endl;
cout << "Day 2 question 1 = " << day_2_1() << endl;
cout << "Day 2 question 2 = " << day_2_2() << endl;
cout << "Day 3 question 1 = " << day_3_1() << endl;
cout << "Day 3 question 2 = " << day_3_2() << endl;

return 0;
}


