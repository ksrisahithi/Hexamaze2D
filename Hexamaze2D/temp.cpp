#include <GL/glut.h>  // Include the GLUT library
#include <CImg.h>     // Include the CImg library

using namespace cimg_library;  // Use the CImg namespace

void displayImage()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Set clear color to white
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

    // Load the image from disk using CImg
    CImg<unsigned char> image("image.jpg");

    // Create an OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    // Set the texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    
    // Upload the image data to the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width(), image.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, image.data());
    
    // Enable 2D texturing
    glEnable(GL_TEXTURE_2D);
    
    // Draw a rectangle with the image as a texture
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(-1.0f, -1.0f);  // Bottom-left corner
    
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(1.0f, -1.0f);   // Bottom-right corner
    
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);    // Top-right corner
    
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);   // Top-left corner
    glEnd();
    
    // Disable 2D texturing
    glDisable(GL_TEXTURE_2D);
    
    glFlush();  // Flush the OpenGL pipeline
}