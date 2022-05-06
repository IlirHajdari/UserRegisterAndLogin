#include <iostream>
#include <fstream> //this is for file handling
#include <cstring>

using namespace std;

bool IsloggedIn()
{
    string username, password, un, pw; //last two are comparison string

    cout << "Enter username:";
    cin >> username;

    cout <<"Enter password:";
    cin >> password;
    
    //for reading file that you have account of not
    //if stream for reading the file
    //read is variable here
    ifstream read("data\\" +username+".txt"); //here data.txt where out data will save for us
    //the file name is written in dhouble cout in file handling
    getline(read, un); //for reading the user name is user valid
    getline(read, pw); //for reading the password, is password valid

    //comparison

    if(un == username && pw == password)
    {
        return true; //user is valid and can log in
    }
    else
    {
        return false;
    }
}
 int main()
 {
     //system("color 3f"); for color output in console
     int choice;

     cout << "1 : Register \n2 :Login\nYour choice:";
     cin >> choice;
     if(choice==1)
     {
         string username, password;

         cout << "select a username:";
         cin >> username;
         cout << "select a password:";
         cin >> password;

         //

         ofstream file;
         //open file help of open function
         file.open("data\\" +username+ ".txt");

         //rewrite in the file
         file<<"username:"<<username<<endl<<"password:"<<password;
         //the data is registered into our file
         file.close();

         //return here in main because then again we going to log in
         //then we go ahead and register another one so:
         main();
     } 

     //if user already has account and want to log in then
     else if(choice==2)
     {
         //create a variable status and assign into islogged in function
         //and it proceed it from there
         bool status =IsloggedIn();

         if(!status) //if login goes wrong, user name and password incorrect
         {
             cout << "Invalid username and password!" << endl;
             system("PAUSE");

             //This is a Windows command that tells the OS to run the pause
             //program. The program waits to be terminated and halts execution
             //of the parent program
             return 0;
         }
         else //if successful then return 1 or proceed further
         {
             cout << "Successfully logged in" << endl;
             system("pause");
             return 1;

         }
     }
 }
