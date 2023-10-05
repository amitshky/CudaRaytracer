# CudaRaytracer
(WIP) This is a GPU accelerated Raytracer using CUDA. I have used OpenGL to display the results in a window. This project was built using CUDA 10.2 in Visual Studio 2019.

## References:
* [Accelerated Ray Tracing in One Weekend in CUDA](https://developer.nvidia.com/blog/accelerated-ray-tracing-cuda/)
* [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

# Getting Started
For Windows
## Prerequisites
* Visual studio 2019
* CUDA compatible GPU with compute capability >= 3.0
* [CUDA Toolkit v10.2](https://developer.nvidia.com/cuda-10.2-download-archive) or higher
* [CMake](https://cmake.org/download/)

## Set up
* Run ```WinGenerateProjectFiles.bat``` file
* In Visual Studio,
	* in Project properties>CUDA C/C++>Common
		* set ```Generate Relocatable Device Code``` to ```yes```
		* set ```Target Machine Platform``` to ```64-bit```
	* you might also have to exclude all .cu files and include them again and refresh the solution explorer (because vs2019 starts to compile with MSVC instead of NVCC initially)
* Then build and run the project

## Alternative Using CMake
* Configure and build the project (this builds the project in Release mode)
```
cmake -S . -B build
cmake --build build --config Release
```
* Run the project
```
.\build\Release\CudaRaytracer.exe
``

# Output:
This project was built and run on Intel i5-9300H cpu and Nvidia GTX 1050 gpu.\
Screenshots during development:

Positionable Camera with Defocus Blur (showing Metal, Diffuse, and Dielectric material) also showing console output (Render samples = 1024, apperture = 0.44, vFOV = 20)\
![](img/metalDiffGlassMat.png)

Positionable Camera with Defocus Blur (Only diffuse materials) (Render samples = 256, apperture = 2.0, vFOV = 30)\
![](img/positionableCamWithDefocusBlur.png)

Diffuse Material (Render samples = 256)\
![](img/diffuseMat.png)

Normal-colored Sphere with Ground\
![](img/normalSphereWithGround.png)

Visualizing Normals\
![](img/visualizingNormals.png)

First Sphere\
![](img/firstSphere.png)

Gradient Sky\
![](img/gradientSky.png)

# ToDo:
- [x] Ray Tracing in One Weekend
- [ ] Ray Tracing: The Next Week
- [ ] Ray Tracing: The Rest of Your Life
- [ ] keyboard and mouse support (make it interactive)