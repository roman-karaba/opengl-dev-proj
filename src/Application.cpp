#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    // array of values representing points/"vertecies" in 2D (x,y)
    float positions[6] = {
        -0.5f, -0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f
    };

    // create a variable for our buffer
    unsigned int buffer;
    // request a number of buffers, and generate the ids at the address,
    // of our buffer variable: 
    // (how_many_buffers = 1, bufferId || &our_buffer_variable) // & ... memory address
    glGenBuffers(1, &buffer);

    // bind the buffer (id) to a buffer structure, Array
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    // manually fill the buffer with vertex data, array analogy:
    // arr[0] = {x0, y0}; arr[1] = {x1, y1}; arr[2] = {x2, y2}; 
    // 6 comes from the length of the positions array
    // GL_STATIC_DRAW is a "hint" to the gpu on how to treat the buffer, static -> doesnt update much
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);


    // specify the memory layout for the data structure
    // (index_of_attribute, component_count_or_size, type_of_data, should_normalize?,
    //  stride_number_of_bytes_between_elements, size_of_the_whole_vertex_in_bytes)
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,
                          sizeof(float) * 2, 0); // no attributes on vertex so 0
    
    // enable the vertexAttributeArray
    glEnableVertexAttribArray(0);

   

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // (draw_what, starting_index, how_many)
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}