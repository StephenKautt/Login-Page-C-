#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

bool logIn(){
        string username, password, un, pw;
        cout << "Enter Username: " << endl;
        cin >> username;
        cout << "\nEnter Password: " << endl;
        cin >> password;

        ifstream read("data\\"+username+".txt");
        getline(read, un);
        getline(read, pw);

        if(un == username && pw == password){
                return true;
        }else{
                return false;
        }
}
int main(){
        int option;

        cout << "Type 1 to Register or 2 to Login: " << endl;
        cin >> option;
        if(option == 1){
                string username, password;
                cout << "Enter a Username: "<< endl;
                cin >> username;
                cout <<"\nEnter a Password: " << endl;
                cin >> password;

                ofstream file;
                file.open("data\\" + username + ".txt");

                file << "username: " << username << endl << "password: " << password;
                file.close();
        }else if(option == 2){
                bool status = logIn();
                if(!status){
                        cout << "Invalid Username or Password!" << endl;
                        return 0;
                }else{
                        cout << "Successfuly Logged In" << endl;
                        return 1;
                }
        }
}
