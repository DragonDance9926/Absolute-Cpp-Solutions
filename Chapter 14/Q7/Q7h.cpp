#include <iostream>
#include <string>
#include "Q7.h"
using namespace std;
namespace TEXT{
    namespace doc{
        Document::Document(){
            text = "";
        }
        Document::Document(std::string t){
            text = t;
        }
        std::string Document::getText() const{
            return text;
        }
        void Document::setText(std::string t){
            text = t;
        }
        Document& Document::operator=(const Document& d){
            text = d.text;
            return *this;
        }
        std::ostream& operator<<(std::ostream& os, const Document& d){
            os << "Document text: " << d.getText() << endl;
            return os;
        }
        std::istream& operator>>(std::istream& is, Document& d){
            cout << "Enter document text: ";
            getline(is, d.text);
            return is;
        }
    }
    namespace email{
        Email::Email(){
            sender = "";
            recipient = "";
            subject = "";
        }
        Email::Email(std::string s, std::string r, std::string sub, std::string t): doc::Document(t){
            sender = s;
            recipient = r;
            subject = sub;
        }
        std::string Email::getSender() const{
            return sender;
        }
        std::string Email::getRecipient() const{
            return recipient;
        }
        std::string Email::getSubject() const{
            return subject;
        }
        void Email::setSender(std::string s){
            sender = s;
        }
        void Email::setRecipient(std::string r){
            recipient = r;
        }
        void Email::setSubject(std::string sub){
            subject = sub;
        }
        Email& Email::operator=(const Email& e){
            sender = e.sender;
            recipient = e.recipient;
            subject = e.subject;
            doc::Document::operator=(e);
            return *this;
        }
        std::ostream& operator<<(std::ostream& os, const Email& e){
            os << "Sender: " << e.getSender() << endl;
            os << "Recipient: " << e.getRecipient() << endl;
            os << "Subject: " << e.getSubject() << endl;
            os << "Document text: " << e.getText() << endl;
            return os;
        }
        std::istream& operator>>(std::istream& is, Email& e){
            is >> static_cast<doc::Document&>(e);
            cout << "Enter sender: ";
            getline(is, e.sender);
            cout << "Enter recipient: ";
            getline(is, e.recipient);
            cout << "Enter subject: ";
            getline(is, e.subject);
            return is;
        }
    }
};