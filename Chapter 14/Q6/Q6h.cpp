#include <iostream>
#include <string>
#include "Q6.h"
using namespace std;

namespace Pay{
    Payment::Payment(){
        amount = 0;
    }
    Payment::Payment(double a){
        amount = a;
    }
    double Payment::getAmount() const{
        return amount;
    }
    std::ostream& operator<<(std::ostream& os, const Payment& p){
        os << "Payment amount: " << p.getAmount() << endl;
        return os;
    }
    std::istream& operator>>(std::istream& is, Payment& p){
        double a;
        cout << "Enter payment amount: ";
        is >> a;
        p.amount = a;
        return is;
    }
    CashPayment::CashPayment(): Payment(){
        // do nothing
    }
    CashPayment::CashPayment(double a): Payment(a){
        // do nothing
    }
    double CashPayment::getAmount() const{
        return Payment::getAmount();
    }
    std::ostream& operator<<(std::ostream& os, const CashPayment& cp){
        os << "Cash payment amount: " << cp.getAmount() << endl;
        return os;
    }
    std::istream& operator>>(std::istream& is, CashPayment& cp){
        cout << "Payment Type: Cash" << endl;
        is >> static_cast<Payment&>(cp);
        return is;
    }
    CreditCardPayment::CreditCardPayment(): Payment(){
        // do nothing
    }
    CreditCardPayment::CreditCardPayment(double a, std::string cn, std::string ch, std::string ce): Payment(a){
        cardNumber = cn;
        cardHolder = ch;
        cardExpiry = ce;
    }
    double CreditCardPayment::getAmount() const{
        return Payment::getAmount();
    }
    std::string CreditCardPayment::getCardNumber() const{
        return cardNumber;
    }
    std::string CreditCardPayment::getCardHolder() const{
        return cardHolder;
    }
    std::string CreditCardPayment::getCardExpiry() const{
        return cardExpiry;
    }
    std::ostream& operator<<(std::ostream& os, const CreditCardPayment& ccp){
        os << "Credit card payment amount: " << ccp.getAmount() << endl;
        os << "Credit card number: " << ccp.getCardNumber() << endl;
        os << "Credit card holder: " << ccp.getCardHolder() << endl;
        os << "Credit card expiry: " << ccp.getCardExpiry() << endl;
        return os;
    }
    std::istream& operator>>(std::istream& is, CreditCardPayment& ccp){
        cout << "Payment Type: Credit Card" << endl;
        is >> static_cast<Payment&>(ccp);
        cout << "Enter credit card number: ";
        is >> ccp.cardNumber;
        cout << "Enter credit card holder: ";
        is >> ccp.cardHolder;
        cout << "Enter credit card expiry: ";
        is >> ccp.cardExpiry;
        return is;
    }

};