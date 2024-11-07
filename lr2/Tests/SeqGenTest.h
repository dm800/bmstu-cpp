#pragma once
#include "../Base/Person.cpp"
#include "../SeqGen.h"
#include "TimeCheck.h"

inline bool SinglePersonGenTest(const Person* person) {
    if (person->height > 210 || person->height < 150) {
        return false;
    }
    if (person->weight > 150 || person->weight < 50) {
        return false;
    }
    if (person->year < 1950 || person->year > 2050) {
        return false;
    }
    if (person->surname.empty() || person->name.empty()) {
        return false;
    }
    return true;
}

inline bool RandomPersonGenCheck() {
    std::cout << "Started test for random person" << std::endl;
    Person* person = Person::getRandom();
    if (!SinglePersonGenTest(person)) {
        return false;
    }
    std::cout << "Finished test for random person" << std::endl;
    std::cout << std::endl;
    return true;
}

inline bool SeqGenCheck(int n) {
    ArraySequence<Person>* seq = SeqGen<Person>(n);
    std::cout << "Started test for " << n << std::endl;
    for (int i = 0; i < seq->GetLength();i++) {
        auto elem = seq->Get(i);
        if (!SinglePersonGenTest(&elem)) {
            std::cout << "Problem with index " << i << std::endl;
            return false;
        }
    }
    std::cout << "Finished test for " << n << std::endl;
    return true;
}

inline void SeqGenLowCheck() {
    TimeCheck(SeqGenCheck, 10);
    TimeCheck(SeqGenCheck, 100);
    TimeCheck(SeqGenCheck, 1000);
}

inline void SeqGenHighCheck() {
    TimeCheck(SeqGenCheck, 10000);
    TimeCheck(SeqGenCheck, 100000);
    TimeCheck(SeqGenCheck, 1000000);
}