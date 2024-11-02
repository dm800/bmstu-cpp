#include "SeqGen.h"
#include "Person.h"

int main()
{
    ArraySequence<Person>* seq = SeqGen<Person>(10);
    for (int i = 0; i < 10; i++)
    {
        std::cout << seq->Get(i).name << " " << seq->Get(i).surname << " " << seq->Get(i).height << " " << seq->Get(i).weight << " " << seq->Get(i).year << std::endl;
    }
    for (int i = 0; i < 100; i++) {
        seq->Append(*Person::getRandom());
    }
    for (int i = 0; i < 110; i++) {
        std::cout << seq->Get(i).name << " " << seq->Get(i).surname << " " << seq->Get(i).height << " " << seq->Get(i).weight << " " << seq->Get(i).year << std::endl;
    }
    /*seq->Append(*Person::getRandom());
    std::cout << seq->GetLast().name;
    for (int i = 0; i < 15; i++) {
        std::cout << seq->Get(i).name << " " << seq->Get(i).surname << " " << seq->Get(i).height << " " << seq->Get(i).weight << " " << seq->Get(i).year << std::endl;
    }*/
    return 0;
}