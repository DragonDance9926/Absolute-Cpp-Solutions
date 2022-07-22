#ifndef TWO2D_HPP
#define TWO2D_HPP
#include <iostream>
namespace t2d{
    class Two2D{
        private:
            int max_row, max_col;
            int** arr;
        public:
            Two2D();
            Two2D(int row, int col);
            Two2D(const Two2D& t);
            ~Two2D();
            int get(int row, int col) const;
            int get_max_row() const;
            int get_max_col() const;
            void set(int row, int col, int val);
            Two2D operator+(const Two2D& t);
            Two2D operator-(const Two2D& t);
            Two2D& operator=(const Two2D& t);
            friend std::ostream& operator<<(std::ostream& os, const Two2D& t);
            friend std::istream& operator>>(std::istream& is, Two2D& t);
    };
}
#endif // TWO2D_HPP