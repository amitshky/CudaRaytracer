#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cuda_runtime.h>
#include <cuda_gl_interop.h>

#include "utils/utils.h"


int32_t InitCudaDevice()
{
	int32_t dev;
	cudaDeviceProp prop;

	memset(&prop, 0, sizeof(cudaDeviceProp));
	// Compute capability >= 3.0
	prop.major = 3;
	prop.minor = 0;
	cudaCheckErrors(cudaChooseDevice(&dev, &prop)); // Choose a device with compute capability >= 3.0
	cudaCheckErrors(cudaGLSetGLDevice(dev));

	return dev;
}

void InitCudaTexture(cudaGraphicsResource_t& textureResource, cudaResourceDesc& resourceDesc, uint32_t textureID)
{
	// Register texture with CUDA resource
	cudaCheckErrors(cudaGraphicsGLRegisterImage(&textureResource, textureID, GL_TEXTURE_2D, cudaGraphicsRegisterFlagsSurfaceLoadStore));
	memset(&resourceDesc, 0, sizeof(resourceDesc));
	resourceDesc.resType = cudaResourceTypeArray;
}
