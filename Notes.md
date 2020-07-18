# OpenGL development project

- OpenGL serves as an interface specification to which GPU manufacturers adhere to ==> what kind of OpenGL version etc depends from the GPU you are using

- GLFW serves as a "windows window provider" that hosts an OpenGl context

- GLEW loads in and exposes OpenGL functions to our environment and handles the communication with the GPU

- the word "SHADER" in the context of computer graphics programming (CGP) just means: "An application/piece of code running on the GPU" nothing else, nothing more

- the word "BUFFER" in the context of computer graphics programming can be understood as "collection data structure" similar to an array that holds the data on the GPU
    - glVertexBuffer is basically a collection of Vertex objects in a Buffer on the GPU


- OpenGL is a STATE MACHINE, it loads existing shaders and buffers by switching state
    - this makes the standard understanding of function calling context dependant
    -  the specific order of selected shaders and buffers greatly affects the rendered result
    - understand the code execution as you providing to the machine a series of instructions as how to use its own functions