# OpenGL development project

- OpenGL serves as an interface specification to which GPU manufacturers adhere to ==> what kind of OpenGL version we code with depends on the supported version by the GPU you are using

- GLFW serves as a "windows window provider" that hosts an OpenGl context

- GLEW loads in and exposes OpenGL functions to our environment and handles the communication with the GPU

- the word **"SHADER"** in the context of computer graphics programming (CGP) just means: "An application/code running on the GPU" nothing else, nothing more

- the word **"BUFFER"** in the context of computer graphics programming can be understood as "collection data structure" similar to an array that holds the data on the GPU
    - glVertexBuffer is basically a collection of Vertex objects in a Buffer on the GPU


- OpenGL is a **STATE MACHINE**, it loads existing shaders and buffers by switching state
    - This makes the standard understanding of function calling **context** dependant
    - The specific **order** of selected shaders and buffers greatly affects the rendered result
    - Understand the code execution as you providing  the machine with a series of instructions as how to use its own functions
    - The concept of the state machine is valid for everything that runs on the GPU -> **shaders** also follow this paradigm