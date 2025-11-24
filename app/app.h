#pragma once
#include <string>

namespace vsite::oop::v3 
{

    struct student {
        std::string name;
        int grade;
    };

    class results {
    public:
        results(int n);
        ~results();
        void add(const student& s);
        unsigned has_grade(int g) const;
        unsigned starts_with_letter(char c) const;

    private:
        student* arr;
        int size;
        int count;
    };

    class array {

    public:
        array();
        array(unsigned size, double value);
        array(const array& other);
        array(array&& other);
        ~array();

        unsigned size() const;
        double at(unsigned index) const;
        void push_back(double value);

    private:
        unsigned m_size;
        double* m_data;
    };
}
