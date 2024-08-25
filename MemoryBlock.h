#ifndef MEMORYBLOCK_H
#define MEMORYBLOCK_H

class MemoryBlock {
public:
    MemoryBlock(size_t size, bool isFree);

    size_t getSize() const;
    bool isBlockFree() const;
    size_t getStartAddress() const;
    void setSize(size_t newSize);
    void setFree(bool free);
    void setStartAddress(size_t address);

private:
    size_t size;
    bool isFree;
    size_t startAddress;
};

#endif // MEMORYBLOCK_H
