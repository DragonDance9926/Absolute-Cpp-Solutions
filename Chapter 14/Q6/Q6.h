#include <string>
#include <iostream>
#ifndef Q6_H
#define Q6_H
namespace Pay{
    class Payment{
        private:
            double amount;
        public:
            Payment();
            Payment(double);
            double getAmount() const;
            friend std::ostream& operator<<(std::ostream&, const Payment&);
            friend std::istream& operator>>(std::istream&, Payment&);
    };
    class CashPayment: public Payment{
        public:
            CashPayment();
            CashPayment(double);
            double getAmount() const;
            friend std::ostream& operator<<(std::ostream&, const CashPayment&);
            friend std::istream& operator>>(std::istream&, CashPayment&);
    };
    class CreditCardPayment: public Payment{
        private:
            std::string cardNumber;
            std::string cardHolder;
            std::string cardExpiry;
        public:
            CreditCardPayment();
            CreditCardPayment(double, std::string, std::string, std::string);
            double getAmount() const;
            std::string getCardNumber() const;
            std::string getCardHolder() const;
            std::string getCardExpiry() const;
            friend std::ostream& operator<<(std::ostream&, const CreditCardPayment&);
            friend std::istream& operator>>(std::istream&, CreditCardPayment&);
    };
};
#endif // Q6_H