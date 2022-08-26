#include <iostream>
#include <string>
#include "Q8.h"
#include <vector>
#include <sstream>
using namespace std;
namespace DragonBlog{
    BlogText::BlogText(){
        text = "";
        author = "";
        date = "";
    }
    BlogText::BlogText(std::string t, std::string a, std::string d){
        text = t;
        author = a;
        date = d;
    }
    BlogText::BlogText(const BlogText& b){
        text = b.text;
        author = b.author;
        date = b.date;
    }
    BlogText& BlogText::operator=(const BlogText& b){
        text = b.text;
        author = b.author;
        date = b.date;
        return *this;
    }
    std::string BlogText::getText() const{
        return text;
    }
    std::string BlogText::getAuthor() const{
        return author;
    }
    std::string BlogText::getDate() const{
        return date;
    }
    std::ostream& operator<<(std::ostream& os, const BlogText& b){
        os << "Author: " << b.getAuthor() << endl;
        os << "Date: " << b.getDate() << endl;
        os << "Text: " << b.getText() << endl;
        return os;
    }
    std::istream& operator>>(std::istream& is, BlogText& b){
        cout << "Enter author: ";
        getline(is, b.author);
        do{
            cout << "Enter date: ";
            getline(is, b.date);
        }while (!b.isValidDate(b.date));
        cout << "Enter text: ";
        getline(is, b.text);
        return is;
    }
    bool BlogText::isleapyear(int year){
        if(year % 4 == 0){
            if(year % 100 == 0){
                if(year % 400 == 0){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return true;
            }
        }
        else{
            return false;
        }
    }
    bool BlogText::isValidDate(std::string date){
        int year, month, day;
        stringstream ss(date);
        ss >> day;
        ss.ignore(1);
        ss >> month;
        ss.ignore(1);
        ss >> year;
        if(year < 0){
            return false;
        }
        if(month < 1 || month > 12){
            return false;
        }
        if(day < 1 || day > 31){
            return false;
        }
        if(month == 4 || month == 6 || month == 9 || month == 11){
            if(day > 30){
                return false;
            }
        }
        if(month == 2){
            if(isleapyear(year)){
                if(day > 29){
                    return false;
                }
            }
            else{
                if(day > 28){
                    return false;
                }
            }
        }
        return true;
    }
    Blog::Blog(){
        blog.clear();
    }
    void Blog::addBlog(BlogText b){
        blog.push_back(b);
    }
    int Blog::size() const{
        return blog.size();
    }
    void Blog::eraseBlog(int index){
        if (index < 0 || index >= blog.size()){
            cout << "Blog does not exist" << endl;
            return;
        }
        blog.erase(blog.begin() + index);
    }
    std::ostream& operator<<(std::ostream& os, const Blog& b){
        for(int i = 0; i < b.blog.size(); i++){
            os << "Blog " << i << ":" << endl;
            os << b.blog[i] << endl;
        }
        return os;
    }
    std::istream& operator>>(std::istream& is, Blog& b){
        BlogText bt;
        cout << "Enter number of blogs: ";
        int n;
        is >> n;
        is.ignore(1);
        for(int i = 0; i < n; i++){
            cout << "Enter blog " << i << ":" << endl;
            is >> bt;
            b.addBlog(bt);
        }
        return is;
    }
    BlogText& Blog::operator[](int index){
        if (index < 0 || index >= blog.size()){
            cout << "Blog does not exist. Showing first blog" << endl;
            return blog[0];
        }
        return blog[index];
    }
    Blog::~Blog(){
        blog.clear();
    }
};

namespace Users{
    normal_user::normal_user(){
        username = "";
        user_type = "";
    }
    normal_user::normal_user(std::string u){
        username = u;
        user_type = "normal";
    }
    normal_user::normal_user(const normal_user& n){
        username = n.username;
        user_type = n.user_type;
    }
    normal_user& normal_user::operator=(const normal_user& n){
        username = n.username;
        user_type = n.user_type;
        return *this;
    }
    void normal_user::set_admin(){
        user_type = "admin";
    }
    std::string normal_user::getUsername() const{
        return username;
    }
    std::string normal_user::getUserType() const{
        return user_type;
    }
    std::ostream& operator<<(std::ostream& os, const normal_user& n){
        os << "Username: " << n.getUsername() << endl;
        os << "User type: " << n.getUserType() << endl;
        return os;
    }
    std::istream& operator>>(std::istream& is, normal_user& n){
        cout << "Enter username: ";
        getline(is, n.username);
        n.user_type = "normal";
        return is;
    }
    admin::admin():normal_user(){
        //does nothing
    }
    admin::admin(std::string u): normal_user(u){
        set_admin();
    }
    admin::admin(const admin& a): normal_user(a){
        set_admin();
    }
    admin& admin::operator=(const admin& a){
        normal_user::operator=(a);
        set_admin();
        return *this;
    }
    std::ostream& operator<<(std::ostream& os, const admin& a){
        os << "Username: " << a.getUsername() << endl;
        os << "User type: " << a.getUserType() << endl;
        return os;
    }
    std::istream& operator>>(std::istream& is, admin& a){
        is >> static_cast<normal_user&>(a);
        a.set_admin();
        return is;
    }
};