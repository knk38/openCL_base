// clang -framework OpenCL dumpcl.c -o dumpcl && ./dumpcl
#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_HPP_MINIMUM_OPENCL_VERSION 120
#define CL_HPP_TARGET_OPENCL_VERSION 120

#include "opencl.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

const int numElements = 32;

int main(void)
{
    // Filter for a 2.0 platform and set it as the default
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);
    std::vector<cl::Device> devices;
    for (auto &p : platforms) {
      std::cout <<  p.getInfo<CL_PLATFORM_VENDOR>() << std::endl;
      p.getDevices(CL_DEVICE_TYPE_ALL, &devices);
      for (auto &d : devices) {
        std::cout << "  " << d.getInfo<CL_DEVICE_NAME>() << std::endl;
      }
    }
    return 0;
}