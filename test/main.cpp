#include <iostream>
#include "app.h"

using namespace vsite::oop::v3;
// read number of results
// read all student data
// read grade and output grade statistics
// read letter and output letter statistics
int main()
{
    std::cout << "Unesite broj studenata: ";
    int n;
    std::cin >> n;

    results r(n);

    for (int i = 0; i < n; ++i) {
        student s;
        std::cout << "Unesite ime i ocjenu za studenta " << (i + 1) << ": ";
        std::cin >> s.name >> s.grade;
        r.add(s);
    }

    std::cout << "Unesite ocjenu za koju zelite statistiku: ";
    int g;
    std::cin >> g;

    unsigned count_grade = r.has_grade(g);
    std::cout << "Broj studenata s ocjenom " << g << ": " << count_grade << "\n";

    std::cout << "Unesite pocetno slovo imena: ";
    char c;
    std::cin >> c;

    unsigned count_letter = r.starts_with_letter(c);
    std::cout << "Broj studenata koji pocinju na slovo '" << c
        << "': " << count_letter << "\n";
}
