#pragma once
#include "SeqGenTest.h"
#include "QuickSortTest.h"


inline void FullCheck() {
    SeqGenLowCheck();
    SeqGenHighCheck();
    QuickSortGeneralCheck();
    QuickSortDiffCheck();
}