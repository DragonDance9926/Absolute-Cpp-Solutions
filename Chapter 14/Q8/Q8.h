#include <string>
#include <vector>
#include <iostream>

#ifndef Q8_BLOG_H
#define Q8_BLOG_H
namespace DragonBlog{
    class BlogText{
        private:
            std::string text;
            std::string author;
            std::string date;
            bool isValidDate(std::string date);
            bool isleapyear(int year);
        public:
            BlogText();
            BlogText(std::string t, std::string a, std::string d);
            BlogText(const BlogText& b);
            BlogText& operator=(const BlogText& b);
            std::string getText() const;
            std::string getAuthor() const;
            std::string getDate() const;
            friend std::ostream& operator<<(std::ostream& os, const BlogText& b);
            friend std::istream& operator>>(std::istream& is, BlogText& b);
    };
    class Blog{
        private:
            std::vector<BlogText> blog;
        public:
            Blog();
            void addBlog(BlogText b);
            void eraseBlog(int index);
            int size() const;
            friend std::ostream& operator<<(std::ostream& os, const Blog& b);
            friend std::istream& operator>>(std::istream& is, Blog& b);
            BlogText& operator[](int index);
            ~Blog();
    };
};
#endif //Q8_BLOG_H

#ifndef Q8_USER_H
#define Q8_USER_H
namespace Users{
    class normal_user{
        private:
            std::string username;
            std::string user_type;
        public:
            normal_user();
            normal_user(std::string u);
            normal_user(const normal_user& n);
            normal_user& operator=(const normal_user& n);
            void set_admin();
            std::string getUsername() const;
            std::string getUserType() const;
            friend std::ostream& operator<<(std::ostream& os, const normal_user& n);
            friend std::istream& operator>>(std::istream& is, normal_user& n);
    };
    class admin: public normal_user{
        public:
            admin();
            admin(std::string u);
            admin(const admin& a);
            admin& operator=(const admin& a);
            friend std::ostream& operator<<(std::ostream& os, const admin& a);
            friend std::istream& operator>>(std::istream& is, admin& a);
    };
};
#endif //Q8_USER_H