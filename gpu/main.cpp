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

int main()
{
    MTL::Device *device = MTL::CreateSystemDefaultDevice();

    // Print the name of the device
    std::cout << "Device: " << device->name() << std::endl;

    // Check whether it uses unified memory
    std::cout << "Uses unified memory: " << device->hasUnifiedMemory() << std::endl;

    // Current allocated size
    std::cout << "Current allocated size: " << device->currentAllocatedSize() << std::endl;

    device->release();
    return 0;
}
