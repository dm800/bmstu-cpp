#include "TestModule.h"
#include <cstdlib>

int main()
{
    system("chcp 65001");
    std::cout << std::endl;

    /*auto* seq = SeqGen<Person>(100000);
    auto start = std::chrono::steady_clock::now();
    std::qsort(seq->_array->arr, 100000, sizeof(Person), [](const void* a, const void* b) {
        return ((Person*)a)->year - ((Person*)b)->year;
    });
    std::cout << "completed in: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms\n";
    seq = SeqGen<Person>(1000000);
    start = std::chrono::steady_clock::now();
    std::qsort(seq->_array->arr, 1000000, sizeof(Person), [](const void* a, const void* b) {
        return ((Person*)a)->year - ((Person*)b)->year;
    });
    std::cout << "completed in: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms\n"; */
    std::cout << "Ну прям сейчас короче отношение получается 12 -> 37 -> 81. Поидее должно быть 12 -> 12 -> 12. "
                 "С чем это связано? Хз. Единственная зависимость которая может себя так вести - факториал. Но откуда он у мя там - хз. " << std::endl;
    std::cout << "Райт нау у тебя оба массива открыты, поэтому не забудь их спрятать когда сдавать будешь" << std::endl;
    QuickSortGeneralCheck();
    SwapCheck();
    RandomPersonGenCheck();
    SeqGenLowCheck();
    SeqGenHighCheck();
    return 0;
}