#include <iostream>
#include <fstream>

using namespace std;

int day_1_1(){
    string line;
    int allNumbers [200];
    ifstream myfile ("Expense_Report.txt");

    int i=0;

    if(myfile.is_open()){
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

    int i=0;

    if(myfile.is_open()){
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

int main(){

cout << "Day 1 question 1 = " << day_1_1() << endl;
cout << "Day 1 question 2 = " << day_1_2() << endl;

return 0;
}


