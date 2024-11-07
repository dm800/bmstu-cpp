#pragma once
#include "SeqGenTest.h"
#include "QuickSortTest.h"
#include "HeapSortTest.h"


inline void FullCheck() {
    SeqGenLowCheck();
    SeqGenHighCheck();
    QuickSortGeneralCheck();
    QuickSortDiffCheck();
    HeapSortGeneralCheck();
    HeapSortDiffCheck();
}