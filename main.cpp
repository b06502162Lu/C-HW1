#include <iostream>


using namespace std ;
void select_service() ;
void ask_next_step() ;
void withdraw() ;
void remain() ;
void transfer() ;


int deposit = 5000 ;

int main() {
    cout<<"WELCOME TO Liang-Yu BANK, PLEASE SELECT THE SERVICE YOU NEED!"<<endl;
    select_service() ;
    return 0;
}

void ask_next_step(){
    cout<<"Please select \'c\' to continue or select \'q\' to quit"<<endl;
    char command ;
    cin>>command ;
    if (command == 'c'){
        cout<<"PLEASE SELECT THE SERVICE YOU NEED!"<<endl;
        select_service() ;
    }
    else if (command == 'q'){
        cout<<"THANK YOU AND SEE YOU SOON."<<endl;
    }
    else {
        ask_next_step() ;
    }
}

void select_service(){
    char command ;
    cin>>command ;
    if (command == 'W'){
        withdraw() ;
    }
    else if (command == 'R'){
        remain() ;
    }
    else if (command == 'T'){
        transfer() ;
    }
    else {
        cout<<"Please select the valid service"<<endl ;
        select_service();
    }
}

void withdraw(){
    cout<<"Please enter the money you want to withdraw"<<endl ;
    int money ;
    cin>>money ;
    if (money>deposit){
        cout<<"the deposit is insufficient, please re-enter the money you want to withdraw"<<endl ;
        cout<<"Deposit:"<<deposit<<"NTD"<<endl ;
        withdraw() ;
    }
    else{
        cout<<"WITHDRAW:"<<money<<"NTD"<<endl ;
        deposit -= money ;
        cout<<"Deposit:"<<deposit<<"NTD"<<endl ;
        ask_next_step();
    }
}

void remain(){
    cout<<"Deposit : "<<deposit<<"NTD"<<endl ;
    ask_next_step();
}
void transfer() {
    unsigned long long id ;
    int trans_amount ;
    cout<<"Please enter the recipient ID "<<endl ;
    cin>>id ; //notice the id is a 10 digits number, and the first digit is not zero.
    if (id>9999999999 || id<1000000000){
        cout<<"RECIPIENT ACCOUNT CONSISTS OF 10 DIGITS"<<endl ;
        transfer() ;
    }
    else {
        cout<<"Please enter the amount you want to transfer"<<endl ;
        cin>>trans_amount ;
        if (trans_amount > deposit){
            cout<<"The deposit is insufficient, please re-enter the recipient and amount you want to transfer"<<endl;
            cout<<"Deposit : "<<deposit<<"NTD"<<endl ;
            transfer();
        }
        else { 
            cout<<"TRANSFER DONE"<<endl ;
            deposit -= trans_amount ;
            cout<<"Deposit:"<<deposit<<"NTD"<<endl ;
            ask_next_step();
        }

    }

}

