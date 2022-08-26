#include <iostream>
#include <string>


namespace TEXT{
    namespace doc{
        class Document{
            private:
                std::string text;
            public:
                Document();
                Document(std::string t);
                std::string getText() const;
                void setText(std::string t);
                Document& operator=(const Document& d);
                friend std::ostream& operator<<(std::ostream& os, const Document& d);
                friend std::istream& operator>>(std::istream& is, Document& d);
        };
    };
    namespace email{
        class Email: public doc::Document{
            private:
                std::string sender;
                std::string recipient;
                std::string subject;
            public:
                Email();
                Email(std::string s, std::string r, std::string sub, std::string t);
                std::string getSender() const;
                std::string getRecipient() const;
                std::string getSubject() const;
                void setSender(std::string s);
                void setRecipient(std::string r);
                void setSubject(std::string sub);
                Email& operator=(const Email& e);
                friend std::ostream& operator<<(std::ostream& os, const Email& e);
                friend std::istream& operator>>(std::istream& is, Email& e);
        };
    };
};