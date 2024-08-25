#ifndef MEMORYMANAGEMENTUNIT_H
#define MEMORYMANAGEMENTUNIT_H

#include "MemoryBlock.h"
#include <vector>

class MemoryManagementUnit {
public:
    MemoryManagementUnit(size_t totalSize);

    void allocate(size_t size);
    void deallocate(size_t address);
    void visualize() const;
    void printStatistics() const;

private:
    std::vector<MemoryBlock> memory;
    size_t initialTotalMemory;
    size_t currentTotalMemory; // Optionally keep track of current total memory

    void merge();
};

#endif // MEMORYMANAGEMENTUNIT_H
