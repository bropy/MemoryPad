#include "MemoryManagementUnit.h"
#include <iostream>

MemoryManagementUnit::MemoryManagementUnit(size_t totalSize)
    : initialTotalMemory(totalSize), currentTotalMemory(totalSize) {
    // Initialize memory with one large free block
    memory.emplace_back(totalSize, true);
    memory.back().setStartAddress(0);
}

void MemoryManagementUnit::allocate(size_t size) {
    size_t address = 0;
    for (auto& block : memory) {
        if (block.isBlockFree() && block.getSize() >= size) {
            size_t remainingSize = block.getSize() - size;
            if (remainingSize > 0) {
                // Split the block
                block.setSize(size);
                block.setFree(false);
                address = block.getStartAddress();
                // Create a new free block
                MemoryBlock newBlock(remainingSize, true);
                newBlock.setStartAddress(address + size);
                memory.push_back(newBlock);
            }
            else {
                // Exact fit
                block.setFree(false);
                address = block.getStartAddress();
            }
            currentTotalMemory -= size;
            std::cout << "Allocated " << size << " units at address " << address << ".\n";
            return;
        }
    }
    std::cout << "No sufficient memory block found.\n";
}

void MemoryManagementUnit::deallocate(size_t address) {
    for (auto& block : memory) {
        if (!block.isBlockFree() && block.getStartAddress() == address) {
            block.setFree(true);
            merge();
            std::cout << "Deallocated memory at address " << address << ".\n";
            return;
        }
    }
    std::cout << "No allocated block found at address " << address << ".\n";
}

void MemoryManagementUnit::visualize() const {
    std::cout << "Memory Blocks:\n";
    for (const auto& block : memory) {
        std::cout << "Address: " << block.getStartAddress()
            << ", Size: " << block.getSize()
            << ", Free: " << (block.isBlockFree() ? "Yes" : "No") << "\n";
    }
}

void MemoryManagementUnit::printStatistics() const {
    size_t freeMemory = 0;
    size_t allocatedMemory = 0;

    for (const auto& block : memory) {
        if (block.isBlockFree()) {
            freeMemory += block.getSize();
        }
        else {
            allocatedMemory += block.getSize();
        }
    }

    std::cout << "Total Memory: " << initialTotalMemory << "\n";
    std::cout << "Free Memory: " << freeMemory << "\n";
    std::cout << "Allocated Memory: " << allocatedMemory << "\n";
}

void MemoryManagementUnit::merge() {
    std::vector<MemoryBlock> mergedMemory;
    size_t lastSize = 0;
    size_t lastStartAddress = 0;

    for (auto& block : memory) {
        if (block.isBlockFree()) {
            if (!mergedMemory.empty() && mergedMemory.back().isBlockFree()) {
                mergedMemory.back().setSize(mergedMemory.back().getSize() + block.getSize());
            }
            else {
                mergedMemory.push_back(block);
            }
        }
        else {
            mergedMemory.push_back(block);
        }
    }

    memory = std::move(mergedMemory);
}
