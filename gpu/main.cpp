//
//  main.cpp
//  gpu
//
//  Created by David Rose on 2/10/23.
//

#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>
#include <iostream>
#include <CoreVideo/CVDisplayLink.h>
#include <chrono>
#include <thread>

int main()
{
    MTL::Device *pDevice = MTL::CreateSystemDefaultDevice();
    if (!pDevice)
    {
        std::cout << "Failed to create Metal device." << std::endl;
        return 1;
    }
    // Print the name of the device
    std::cout << "Device: " << pDevice->name() << std::endl;

    // Check whether it uses unified memory
    std::cout << "Uses unified memory: " << pDevice->hasUnifiedMemory() << std::endl;

    // Current allocated size
    std::cout << "Current allocated size: " << pDevice->currentAllocatedSize() << std::endl;

    MTL::HeapDescriptor* pHeapDescriptor = MTL::HeapDescriptor::alloc()->init();
    pHeapDescriptor->setStorageMode( MTL::StorageModeShared );
    pHeapDescriptor->setSize( 1024 * 1024 * 1024 );
    
    MTL::Heap* pHeap = pDevice->newHeap( pHeapDescriptor );

    MTL::HeapDescriptor* pHeapDescriptor2 = MTL::HeapDescriptor::alloc()->init();
    pHeapDescriptor2->setStorageMode( MTL::StorageModePrivate );
    pHeapDescriptor2->setSize( 1024 * 1024 * 1024 );
    
    MTL::ResourceOptions options = MTL::ResourceStorageModeShared;



    while (true)
    {
        size_t usedBytes = pHeap->getUsedSize();
        size_t totalBytes = pHeap->getSize();
        std::cout << "Used memory: " << usedBytes << " bytes, Available memory: " << totalBytes - usedBytes << " bytes." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    return 0;
}
