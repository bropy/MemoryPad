#include "MemoryBlock.h"

MemoryBlock::MemoryBlock(size_t size, bool isFree)
    : size(size), isFree(isFree), startAddress(0) {}

size_t MemoryBlock::getSize() const {
    return size;
}

bool MemoryBlock::isBlockFree() const {
    return isFree;
}

size_t MemoryBlock::getStartAddress() const {
    return startAddress;
}

void MemoryBlock::setSize(size_t newSize) {
    size = newSize;
}

void MemoryBlock::setFree(bool free) {
    isFree = free;
}

void MemoryBlock::setStartAddress(size_t address) {
    startAddress = address;
}
