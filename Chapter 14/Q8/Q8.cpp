#include <iostream>
#include <string>
#include "Q8.h"
#include <vector>
#include <sstream>
using namespace std;
using namespace DragonBlog;




int main(){
    Blog b;
    cin >> b;
    int choice;
    int choice2;
    BlogText bt;
    do{
        Users::normal_user n;
        Users::admin a;
        cout << "1- Enter as admin" << endl;
        cout << "2- Enter as normal user" << endl;
        cout << "3- Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> a;
                cout << a;
                do{
                    int index;
                    cout << "1- Add blog" << endl;
                    cout << "2- Erase blog" << endl;
                    cout << "3- Exit" << endl;
                    cout << "4- Search blog" << endl;
                    cout << "5- Show all blogs" << endl;
                    cin >> choice2;
                    cin.ignore(1);
                    switch (choice2)
                    {
                        case 1:
                            cout << "Enter blog: " << endl;
                            cin >> bt;
                            b.addBlog(bt);
                            break;
                        case 2:
                            if (b.size() == 0){
                                cout << "No blogs to erase" << endl;
                            }
                            else{
                                cout << "Enter index of blog to erase: " << endl;
                                cin >> index;
                                b.eraseBlog(index);
                            }
                            break;
                        case 3:
                            cout << "Switching to next user" << endl;
                            break;
                        case 4:
                            if (b.size() == 0){
                                cout << "No blogs" << endl;
                            }
                            else{
                                cout << "Enter index: " << endl;
                                cin >> index;
                                cout << b[index];
                            }
                            break;
                        case 5:
                            cout << b;
                            break;
                    }
                }while(choice2 != 3);
                break;
            case 2:
                cin >> n;
                cout << n;
                do{
                    int index;
                    cout << "1- Add blog" << endl;
                    cout << "2- Erase blog" << endl;
                    cout << "3- Exit" << endl;
                    cout << "4- Search blog" << endl;
                    cout << "5- Show all blogs" << endl;
                    cin >> choice2;
                    cin.ignore(1);
                    switch (choice2)
                    {
                        case 1:
                            cout << "You are not allowed to add blogs" << endl;
                            break;
                        case 2:
                            cout << "You are not allowed to erase blogs" << endl;
                            break;
                        case 3:
                            cout << "Switching to next user" << endl;
                            break;
                        case 4:
                            if (b.size() == 0){
                                cout << "There is no blog" << endl;
                            }
                            else{
                                cout << "Enter index: " << endl;
                                cin >> index;
                                cout << b[index];
                            }
                            break;
                        case 5:
                            cout << "You are not allowed to see all blogs" << endl;
                            break;
                    }
                }while(choice2 != 3);
                break;
            case 3:
                cout << "Bye!" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }while (choice != 3);
    return 0;
}