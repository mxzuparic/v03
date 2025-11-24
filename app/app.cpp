#include "app.h"
#include <algorithm>

namespace vsite::oop::v3 
{
    results::results(int n) {
        size = n;
        count = 0;
        arr = new student[n];
    }

    results::~results() {
        delete[] arr;
        arr = nullptr;
    }

    void results::add(const student& s) {
        arr[count] = s;
        count++;
    }

    unsigned results::has_grade(int g) const {
        unsigned c = 0;
        for (int i = 0; i < count; i++) {
            if (arr[i].grade == g)
                c++;
        }
        return c;
    }

    unsigned results::starts_with_letter(char c) const {
        unsigned b = 0;
        c = tolower(c);
        for (int i = 0; i < count; i++) {
            if (tolower(arr[i].name[0]) == c)
                b++;
        }
        return b;
    }

    array::array() {
        m_size = 0;
        m_data = nullptr;
    }

    array::array(unsigned size, double value) {
        m_size = size;
        m_data = new double[size];
        for (int i = 0; i < size; i++) {
            m_data[i] = value;
        }
    }

    array::array(const array& other) {
        m_size = other.m_size;
        if (m_size == 0) {
            m_data = nullptr;
            return;
        }
        m_data = new double[m_size];
        for (int i = 0; i < m_size; i++) {
            m_data[i] = other.m_data[i];
        }
    }

    array::array(array&& other) {
        m_size = other.m_size;
        m_data = other.m_data;

        other.m_size = 0;
        other.m_data = nullptr;
    }

    array::~array() {
        delete[] m_data;
    }

    unsigned array::size() const {
        return m_size;
    }

    double array::at(unsigned index) const {
        if (index >= m_size)
            return 0.;
        return m_data[index];
    }

    void array::push_back(double value) {
        double* temp = new double[m_size + 1];

        for (int i = 0; i < m_size; i++) {
            temp[i] = m_data[i];
        }

        temp[m_size] = value;

        delete[] m_data;
        m_data = temp;
        m_size++;
    }
}
