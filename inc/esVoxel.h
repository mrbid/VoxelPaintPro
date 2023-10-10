/*
--------------------------------------------------
    James William Fletcher (github.com/mrbid)
        August 2023 - esVoxel.h v3.0
--------------------------------------------------

    A pretty good color converter: https://www.easyrgb.com/en/convert.php

    A voxel is: vec4(x,y,z,color)

    Requires:
        - vec.h: https://gist.github.com/mrbid/77a92019e1ab8b86109bf103166bd04e
        - mat.h: https://gist.github.com/mrbid/cbc69ec9d99b0fda44204975fcbeae7c
    
*/

#ifndef AUX_H
#define AUX_H

#include "vec.h"
#include "mat.h"

//*************************************
// VOXEL STRUCTURE
//*************************************
typedef struct
{
    GLuint vid; // Vertex Array Buffer ID
    GLuint iid;	// Index Array Buffer ID
    GLuint nid;	// Normal Array Buffer ID
    GLuint tid;	// TexCoord Array Buffer ID
} ESModel;
const GLfloat voxel_vertices[] = {-0.5,0.5,0.5,0.5,-0.5,0.5,0.5,0.5,0.5,0.5,-0.5,0.5,-0.5,-0.5,-0.5,0.5,-0.5,-0.5,-0.5,-0.5,0.5,-0.5,0.5,-0.5,-0.5,-0.5,-0.5,0.5,0.5,-0.5,-0.5,-0.5,-0.5,-0.5,0.5,-0.5,0.5,0.5,0.5,0.5,-0.5,-0.5,0.5,0.5,-0.5,-0.5,0.5,0.5,0.5,0.5,-0.5,-0.5,0.5,-0.5,-0.5,-0.5,0.5,-0.5,-0.5,0.5,-0.5,0.5,0.5,0.5,-0.5,-0.5,0.5,-0.5,0.5,0.5,0.5,0.5,0.5,0.5,-0.5};
const GLfloat voxel_normals[] = {0,0,1,0,0,1,0,0,1,0,-1,0,0,-1,0,0,-1,0,-1,0,0,-1,0,0,-1,0,0,0,0,-1,0,0,-1,0,0,-1,1,0,-0,1,0,-0,1,0,-0,0,1,-0,0,1,-0,0,1,-0,0,-0,1,0,-1,0,-1,0,0,0,0,-1,1,0,0,0,1,-0,0,1,-0};
const GLubyte voxel_indices[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,0,18,1,3,19,4,6,20,7,9,21,10,12,22,13,15,23,24};
const GLsizeiptr voxel_numind = 36;
ESModel mdlVoxel;

const GLfloat hud_vertices[] = {-1,1,0,1,-1,0,1,1,0,-1,-1,0};
const GLfloat hud_uvmap[] = {0,0, 1,1, 1,0, 0,1};
const GLubyte hud_indices[] = {0,1,2,0,3,1};
const GLsizeiptr hud_numind = 6;
ESModel mdlPlane;
SDL_Surface* sHud;
GLuint hudmap;

//*************************************
// SHADER
//*************************************
void makeHud();
void shadeHud(GLint* position, GLint* texcoord, GLint* sampler);
void flipHud()
{
    glBindTexture(GL_TEXTURE_2D, hudmap);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sHud->w, sHud->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, sHud->pixels);
}

void makeVoxel();
void shadeVoxel(GLint* projection, GLint* view, GLint* position, GLint* normal, GLint* voxel);

//*************************************
// UTILITY CODE
//*************************************
GLuint esRand(const GLuint min, const GLuint max)
{
    return (rand()%(max+1-min))+min;
}
GLfloat esRandFloat(const GLfloat min, const GLfloat max)
{
    static GLfloat rrndmax = 1.f/(GLfloat)RAND_MAX;
    return (((GLfloat)rand()) * rrndmax) * (max-min) + min;
}
void esBind(const GLenum target, GLuint* buffer, const void* data, const GLsizeiptr datalen, const GLenum usage)
{
    glGenBuffers(1, buffer);
    glBindBuffer(target, *buffer);
    glBufferData(target, datalen, data, usage);
}
void esRebind(const GLenum target, GLuint* buffer, const void* data, const GLsizeiptr datalen, const GLenum usage)
{
    glBindBuffer(target, *buffer);
    glBufferData(target, datalen, data, usage);
}
GLuint esLoadTextureA(const GLuint w, const GLuint h, const unsigned char* data, const GLuint linear)
{
    GLuint textureId;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    if(linear == 0)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    else
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    return textureId;
}

//*************************************
// SHADER CODE
//*************************************
const GLchar* v0 =
    "#version 100\n"
    "attribute vec4 position;\n"
    "attribute vec2 texcoord;\n"
    "varying vec2 vtc;\n"
    "void main()\n"
    "{\n"
        "vtc = texcoord;\n"
        "gl_Position = position;\n"
    "}\n";

const GLchar* f0 =
    "#version 100\n"
    "precision highp float;\n"
    "varying vec2 vtc;\n"
    "uniform sampler2D tex;\n"
    "void main()\n"
    "{\n"
        "gl_FragColor = texture2D(tex, vtc);\n"
    "}\n";

///

const GLchar* v1 =
    "#version 100\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "uniform vec4 voxel;\n"
    "attribute vec4 position;\n"
    "attribute vec3 normal;\n"
    "varying float lambertian;\n"
    "varying vec3 color;\n"
    "void main()\n"
    "{\n"
        "mat4 model;\n"
        "model[0] = vec4(1.0, 0.0, 0.0, 0.0);\n"
        "model[1] = vec4(0.0, 1.0, 0.0, 0.0);\n"
        "model[2] = vec4(0.0, 0.0, 1.0, 0.0);\n"
        "model[3] = vec4(voxel.x, voxel.y, voxel.z, 1.0);\n"
        "mat4 modelview = view * model;\n"
        "vec4 vertPos4 = modelview * position;\n"
        "vec3 vertPos = vertPos4.xyz / vertPos4.w;\n"
#ifdef SKYBLUE
        "lambertian = clamp(max(dot(normalize(-vertPos), normalize(vec3(modelview * vec4(normal, 0.0)))), 0.0), 0.64, 1.0);\n"
#else
        "lambertian = clamp(max(dot(normalize(-vertPos), normalize(vec3(modelview * vec4(normal, 0.0)))), 0.0), 0.64, 1.0) * clamp(1.0 - (length(vertPos)*0.00023), 0.0, 1.0);\n"
#endif
        "color = vec3(0.0, 0.0, 0.0);\n"
        // this is the Aurora Palette (https://lospec.com/palette-list/aurora)
        "if(voxel.w == 0.0){color = vec3(0.00,0.00,0.00);}\n"
        "else if(voxel.w == 1.0){color = vec3(0.07,0.07,0.07);}\n"
        "else if(voxel.w == 2.0){color = vec3(0.13,0.13,0.13);}\n"
        "else if(voxel.w == 3.0){color = vec3(0.20,0.20,0.20);}\n"
        "else if(voxel.w == 4.0){color = vec3(0.27,0.27,0.27);}\n"
        "else if(voxel.w == 5.0){color = vec3(0.33,0.33,0.33);}\n"
        "else if(voxel.w == 6.0){color = vec3(0.40,0.40,0.40);}\n"
        "else if(voxel.w == 7.0){color = vec3(0.47,0.47,0.47);}\n"
        "else if(voxel.w == 8.0){color = vec3(0.53,0.53,0.53);}\n"
        "else if(voxel.w == 9.0){color = vec3(0.60,0.60,0.60);}\n"
        "else if(voxel.w == 10.0){color = vec3(0.67,0.67,0.67);}\n"
        "else if(voxel.w == 11.0){color = vec3(0.73,0.73,0.73);}\n"
        "else if(voxel.w == 12.0){color = vec3(0.80,0.80,0.80);}\n"
        "else if(voxel.w == 13.0){color = vec3(0.87,0.87,0.87);}\n"
        "else if(voxel.w == 14.0){color = vec3(0.93,0.93,0.93);}\n"
        "else if(voxel.w == 15.0){color = vec3(1.00,1.00,1.00);}\n"
        "else if(voxel.w == 16.0){color = vec3(0.00,0.50,0.50);}\n"
        "else if(voxel.w == 17.0){color = vec3(0.25,0.75,0.75);}\n"
        "else if(voxel.w == 18.0){color = vec3(0.00,1.00,1.00);}\n"
        "else if(voxel.w == 19.0){color = vec3(0.75,1.00,1.00);}\n"
        "else if(voxel.w == 20.0){color = vec3(0.51,0.51,1.00);}\n"
        "else if(voxel.w == 21.0){color = vec3(0.00,0.00,1.00);}\n"
        "else if(voxel.w == 22.0){color = vec3(0.25,0.25,0.75);}\n"
        "else if(voxel.w == 23.0){color = vec3(0.00,0.00,0.50);}\n"
        "else if(voxel.w == 24.0){color = vec3(0.06,0.06,0.31);}\n"
        "else if(voxel.w == 25.0){color = vec3(0.50,0.00,0.50);}\n"
        "else if(voxel.w == 26.0){color = vec3(0.75,0.25,0.75);}\n"
        "else if(voxel.w == 27.0){color = vec3(0.96,0.00,0.96);}\n"
        "else if(voxel.w == 28.0){color = vec3(0.99,0.51,1.00);}\n"
        "else if(voxel.w == 29.0){color = vec3(1.00,0.75,0.80);}\n"
        "else if(voxel.w == 30.0){color = vec3(1.00,0.51,0.51);}\n"
        "else if(voxel.w == 31.0){color = vec3(1.00,0.00,0.00);}\n"
        "else if(voxel.w == 32.0){color = vec3(0.75,0.25,0.25);}\n"
        "else if(voxel.w == 33.0){color = vec3(0.50,0.00,0.00);}\n"
        "else if(voxel.w == 34.0){color = vec3(0.33,0.08,0.08);}\n"
        "else if(voxel.w == 35.0){color = vec3(0.50,0.25,0.00);}\n"
        "else if(voxel.w == 36.0){color = vec3(0.75,0.50,0.25);}\n"
        "else if(voxel.w == 37.0){color = vec3(1.00,0.50,0.00);}\n"
        "else if(voxel.w == 38.0){color = vec3(1.00,0.75,0.51);}\n"
        "else if(voxel.w == 39.0){color = vec3(1.00,1.00,0.75);}\n"
        "else if(voxel.w == 40.0){color = vec3(1.00,1.00,0.00);}\n"
        "else if(voxel.w == 41.0){color = vec3(0.75,0.75,0.25);}\n"
        "else if(voxel.w == 42.0){color = vec3(0.50,0.50,0.00);}\n"
        "else if(voxel.w == 43.0){color = vec3(0.00,0.50,0.00);}\n"
        "else if(voxel.w == 44.0){color = vec3(0.25,0.75,0.25);}\n"
        "else if(voxel.w == 45.0){color = vec3(0.00,1.00,0.00);}\n"
        "else if(voxel.w == 46.0){color = vec3(0.69,1.00,0.69);}\n"
        "else if(voxel.w == 47.0){color = vec3(0.00,0.75,1.00);}\n"
        "else if(voxel.w == 48.0){color = vec3(0.00,0.50,1.00);}\n"
        "else if(voxel.w == 49.0){color = vec3(0.29,0.49,0.78);}\n"
        "else if(voxel.w == 50.0){color = vec3(0.74,0.69,0.75);}\n"
        "else if(voxel.w == 51.0){color = vec3(0.80,0.67,0.54);}\n"
        "else if(voxel.w == 52.0){color = vec3(0.65,0.63,0.56);}\n"
        "else if(voxel.w == 53.0){color = vec3(0.49,0.58,0.58);}\n"
        "else if(voxel.w == 54.0){color = vec3(0.43,0.51,0.53);}\n"
        "else if(voxel.w == 55.0){color = vec3(0.49,0.43,0.38);}\n"
        "else if(voxel.w == 56.0){color = vec3(0.63,0.41,0.37);}\n"
        "else if(voxel.w == 57.0){color = vec3(0.75,0.47,0.45);}\n"
        "else if(voxel.w == 58.0){color = vec3(0.82,0.54,0.45);}\n"
        "else if(voxel.w == 59.0){color = vec3(0.88,0.61,0.49);}\n"
        "else if(voxel.w == 60.0){color = vec3(0.92,0.67,0.55);}\n"
        "else if(voxel.w == 61.0){color = vec3(0.96,0.73,0.61);}\n"
        "else if(voxel.w == 62.0){color = vec3(0.96,0.78,0.69);}\n"
        "else if(voxel.w == 63.0){color = vec3(0.96,0.88,0.82);}\n"
        "else if(voxel.w == 64.0){color = vec3(0.50,0.00,1.00);}\n"
        "else if(voxel.w == 65.0){color = vec3(0.34,0.23,0.23);}\n"
        "else if(voxel.w == 66.0){color = vec3(0.45,0.25,0.24);}\n"
        "else if(voxel.w == 67.0){color = vec3(0.56,0.33,0.33);}\n"
        "else if(voxel.w == 68.0){color = vec3(0.67,0.45,0.45);}\n"
        "else if(voxel.w == 69.0){color = vec3(0.78,0.56,0.56);}\n"
        "else if(voxel.w == 70.0){color = vec3(0.89,0.67,0.67);}\n"
        "else if(voxel.w == 71.0){color = vec3(0.97,0.82,0.85);}\n"
        "else if(voxel.w == 72.0){color = vec3(0.89,0.78,0.67);}\n"
        "else if(voxel.w == 73.0){color = vec3(0.77,0.62,0.45);}\n"
        "else if(voxel.w == 74.0){color = vec3(0.56,0.45,0.34);}\n"
        "else if(voxel.w == 75.0){color = vec3(0.45,0.34,0.23);}\n"
        "else if(voxel.w == 76.0){color = vec3(0.23,0.18,0.12);}\n"
        "else if(voxel.w == 77.0){color = vec3(0.25,0.25,0.14);}\n"
        "else if(voxel.w == 78.0){color = vec3(0.45,0.45,0.23);}\n"
        "else if(voxel.w == 79.0){color = vec3(0.56,0.56,0.34);}\n"
        "else if(voxel.w == 80.0){color = vec3(0.64,0.64,0.33);}\n"
        "else if(voxel.w == 81.0){color = vec3(0.71,0.71,0.45);}\n"
        "else if(voxel.w == 82.0){color = vec3(0.78,0.78,0.56);}\n"
        "else if(voxel.w == 83.0){color = vec3(0.85,0.85,0.67);}\n"
        "else if(voxel.w == 84.0){color = vec3(0.93,0.93,0.78);}\n"
        "else if(voxel.w == 85.0){color = vec3(0.78,0.89,0.67);}\n"
        "else if(voxel.w == 86.0){color = vec3(0.67,0.78,0.56);}\n"
        "else if(voxel.w == 87.0){color = vec3(0.56,0.75,0.33);}\n"
        "else if(voxel.w == 88.0){color = vec3(0.45,0.56,0.34);}\n"
        "else if(voxel.w == 89.0){color = vec3(0.35,0.49,0.24);}\n"
        "else if(voxel.w == 90.0){color = vec3(0.27,0.31,0.20);}\n"
        "else if(voxel.w == 91.0){color = vec3(0.10,0.12,0.06);}\n"
        "else if(voxel.w == 92.0){color = vec3(0.14,0.31,0.22);}\n"
        "else if(voxel.w == 93.0){color = vec3(0.23,0.34,0.23);}\n"
        "else if(voxel.w == 94.0){color = vec3(0.31,0.39,0.31);}\n"
        "else if(voxel.w == 95.0){color = vec3(0.23,0.45,0.29);}\n"
        "else if(voxel.w == 96.0){color = vec3(0.34,0.56,0.34);}\n"
        "else if(voxel.w == 97.0){color = vec3(0.45,0.67,0.45);}\n"
        "else if(voxel.w == 98.0){color = vec3(0.39,0.75,0.51);}\n"
        "else if(voxel.w == 99.0){color = vec3(0.56,0.78,0.56);}\n"
        "else if(voxel.w == 100.0){color = vec3(0.64,0.85,0.64);}\n"
        "else if(voxel.w == 101.0){color = vec3(0.88,0.97,0.98);}\n"
        "else if(voxel.w == 102.0){color = vec3(0.71,0.93,0.79);}\n"
        "else if(voxel.w == 103.0){color = vec3(0.67,0.89,0.77);}\n"
        "else if(voxel.w == 104.0){color = vec3(0.53,0.71,0.56);}\n"
        "else if(voxel.w == 105.0){color = vec3(0.31,0.49,0.37);}\n"
        "else if(voxel.w == 106.0){color = vec3(0.06,0.41,0.27);}\n"
        "else if(voxel.w == 107.0){color = vec3(0.12,0.18,0.14);}\n"
        "else if(voxel.w == 108.0){color = vec3(0.14,0.25,0.27);}\n"
        "else if(voxel.w == 109.0){color = vec3(0.23,0.45,0.45);}\n"
        "else if(voxel.w == 110.0){color = vec3(0.39,0.67,0.67);}\n"
        "else if(voxel.w == 111.0){color = vec3(0.56,0.78,0.78);}\n"
        "else if(voxel.w == 112.0){color = vec3(0.67,0.89,0.89);}\n"
        "else if(voxel.w == 113.0){color = vec3(0.78,0.95,0.95);}\n"
        "else if(voxel.w == 114.0){color = vec3(0.75,0.82,0.94);}\n"
        "else if(voxel.w == 115.0){color = vec3(0.67,0.78,0.89);}\n"
        "else if(voxel.w == 116.0){color = vec3(0.66,0.73,0.86);}\n"
        "else if(voxel.w == 117.0){color = vec3(0.56,0.67,0.78);}\n"
        "else if(voxel.w == 118.0){color = vec3(0.34,0.56,0.78);}\n"
        "else if(voxel.w == 119.0){color = vec3(0.34,0.45,0.56);}\n"
        "else if(voxel.w == 120.0){color = vec3(0.23,0.34,0.45);}\n"
        "else if(voxel.w == 121.0){color = vec3(0.06,0.10,0.18);}\n"
        "else if(voxel.w == 122.0){color = vec3(0.12,0.12,0.23);}\n"
        "else if(voxel.w == 123.0){color = vec3(0.23,0.23,0.34);}\n"
        "else if(voxel.w == 124.0){color = vec3(0.29,0.29,0.45);}\n"
        "else if(voxel.w == 125.0){color = vec3(0.34,0.34,0.56);}\n"
        "else if(voxel.w == 126.0){color = vec3(0.45,0.43,0.67);}\n"
        "else if(voxel.w == 127.0){color = vec3(0.46,0.46,0.79);}\n"
        "else if(voxel.w == 128.0){color = vec3(0.56,0.56,0.78);}\n"
        "else if(voxel.w == 129.0){color = vec3(0.67,0.67,0.89);}\n"
        "else if(voxel.w == 130.0){color = vec3(0.82,0.85,0.97);}\n"
        "else if(voxel.w == 131.0){color = vec3(0.89,0.89,1.00);}\n"
        "else if(voxel.w == 132.0){color = vec3(0.67,0.56,0.78);}\n"
        "else if(voxel.w == 133.0){color = vec3(0.56,0.34,0.78);}\n"
        "else if(voxel.w == 134.0){color = vec3(0.45,0.34,0.56);}\n"
        "else if(voxel.w == 135.0){color = vec3(0.34,0.23,0.45);}\n"
        "else if(voxel.w == 136.0){color = vec3(0.24,0.14,0.24);}\n"
        "else if(voxel.w == 137.0){color = vec3(0.27,0.20,0.27);}\n"
        "else if(voxel.w == 138.0){color = vec3(0.45,0.25,0.45);}\n"
        "else if(voxel.w == 139.0){color = vec3(0.56,0.34,0.56);}\n"
        "else if(voxel.w == 140.0){color = vec3(0.67,0.34,0.67);}\n"
        "else if(voxel.w == 141.0){color = vec3(0.67,0.45,0.67);}\n"
        "else if(voxel.w == 142.0){color = vec3(0.92,0.67,0.88);}\n"
        "else if(voxel.w == 143.0){color = vec3(1.00,0.86,0.96);}\n"
        "else if(voxel.w == 144.0){color = vec3(0.89,0.78,0.89);}\n"
        "else if(voxel.w == 145.0){color = vec3(0.88,0.73,0.82);}\n"
        "else if(voxel.w == 146.0){color = vec3(0.84,0.63,0.75);}\n"
        "else if(voxel.w == 147.0){color = vec3(0.78,0.56,0.73);}\n"
        "else if(voxel.w == 148.0){color = vec3(0.78,0.49,0.63);}\n"
        "else if(voxel.w == 149.0){color = vec3(0.76,0.35,0.57);}\n"
        "else if(voxel.w == 150.0){color = vec3(0.29,0.16,0.22);}\n"
        "else if(voxel.w == 151.0){color = vec3(0.20,0.09,0.14);}\n"
        "else if(voxel.w == 152.0){color = vec3(0.16,0.04,0.12);}\n"
        "else if(voxel.w == 153.0){color = vec3(0.25,0.09,0.07);}\n"
        "else if(voxel.w == 154.0){color = vec3(0.38,0.09,0.00);}\n"
        "else if(voxel.w == 155.0){color = vec3(0.65,0.08,0.04);}\n"
        "else if(voxel.w == 156.0){color = vec3(0.85,0.13,0.06);}\n"
        "else if(voxel.w == 157.0){color = vec3(0.84,0.32,0.29);}\n"
        "else if(voxel.w == 158.0){color = vec3(1.00,0.24,0.04);}\n"
        "else if(voxel.w == 159.0){color = vec3(0.96,0.35,0.20);}\n"
        "else if(voxel.w == 160.0){color = vec3(1.00,0.38,0.38);}\n"
        "else if(voxel.w == 161.0){color = vec3(0.96,0.74,0.19);}\n"
        "else if(voxel.w == 162.0){color = vec3(1.00,0.65,0.24);}\n"
        "else if(voxel.w == 163.0){color = vec3(0.84,0.61,0.06);}\n"
        "else if(voxel.w == 164.0){color = vec3(0.85,0.43,0.04);}\n"
        "else if(voxel.w == 165.0){color = vec3(0.71,0.35,0.00);}\n"
        "else if(voxel.w == 166.0){color = vec3(0.63,0.29,0.02);}\n"
        "else if(voxel.w == 167.0){color = vec3(0.37,0.20,0.08);}\n"
        "else if(voxel.w == 168.0){color = vec3(0.33,0.31,0.04);}\n"
        "else if(voxel.w == 169.0){color = vec3(0.38,0.38,0.00);}\n"
        "else if(voxel.w == 170.0){color = vec3(0.55,0.50,0.35);}\n"
        "else if(voxel.w == 171.0){color = vec3(0.67,0.58,0.00);}\n"
        "else if(voxel.w == 172.0){color = vec3(0.69,0.69,0.04);}\n"
        "else if(voxel.w == 173.0){color = vec3(0.90,0.84,0.35);}\n"
        "else if(voxel.w == 174.0){color = vec3(1.00,0.84,0.06);}\n"
        "else if(voxel.w == 175.0){color = vec3(1.00,0.92,0.29);}\n"
        "else if(voxel.w == 176.0){color = vec3(0.78,1.00,0.25);}\n"
        "else if(voxel.w == 177.0){color = vec3(0.61,0.94,0.27);}\n"
        "else if(voxel.w == 178.0){color = vec3(0.59,0.86,0.10);}\n"
        "else if(voxel.w == 179.0){color = vec3(0.45,0.78,0.02);}\n"
        "else if(voxel.w == 180.0){color = vec3(0.42,0.66,0.02);}\n"
        "else if(voxel.w == 181.0){color = vec3(0.24,0.43,0.08);}\n"
        "else if(voxel.w == 182.0){color = vec3(0.16,0.20,0.02);}\n"
        "else if(voxel.w == 183.0){color = vec3(0.13,0.27,0.03);}\n"
        "else if(voxel.w == 184.0){color = vec3(0.05,0.36,0.05);}\n"
        "else if(voxel.w == 185.0){color = vec3(0.08,0.59,0.02);}\n"
        "else if(voxel.w == 186.0){color = vec3(0.04,0.84,0.04);}\n"
        "else if(voxel.w == 187.0){color = vec3(0.08,0.90,0.04);}\n"
        "else if(voxel.w == 188.0){color = vec3(0.49,1.00,0.45);}\n"
        "else if(voxel.w == 189.0){color = vec3(0.29,0.94,0.35);}\n"
        "else if(voxel.w == 190.0){color = vec3(0.00,0.77,0.08);}\n"
        "else if(voxel.w == 191.0){color = vec3(0.02,0.71,0.31);}\n"
        "else if(voxel.w == 192.0){color = vec3(0.11,0.55,0.31);}\n"
        "else if(voxel.w == 193.0){color = vec3(0.07,0.22,0.20);}\n"
        "else if(voxel.w == 194.0){color = vec3(0.07,0.60,0.50);}\n"
        "else if(voxel.w == 195.0){color = vec3(0.02,0.77,0.57);}\n"
        "else if(voxel.w == 196.0){color = vec3(0.00,0.87,0.42);}\n"
        "else if(voxel.w == 197.0){color = vec3(0.18,0.92,0.66);}\n"
        "else if(voxel.w == 198.0){color = vec3(0.24,1.00,0.65);}\n"
        "else if(voxel.w == 199.0){color = vec3(0.42,1.00,0.80);}\n"
        "else if(voxel.w == 200.0){color = vec3(0.57,0.92,1.00);}\n"
        "else if(voxel.w == 201.0){color = vec3(0.33,0.90,1.00);}\n"
        "else if(voxel.w == 202.0){color = vec3(0.49,0.84,0.94);}\n"
        "else if(voxel.w == 203.0){color = vec3(0.03,0.87,0.84);}\n"
        "else if(voxel.w == 204.0){color = vec3(0.06,0.61,0.87);}\n"
        "else if(voxel.w == 205.0){color = vec3(0.02,0.35,0.36);}\n"
        "else if(voxel.w == 206.0){color = vec3(0.09,0.17,0.32);}\n"
        "else if(voxel.w == 207.0){color = vec3(0.06,0.22,0.49);}\n"
        "else if(voxel.w == 208.0){color = vec3(0.00,0.29,0.61);}\n"
        "else if(voxel.w == 209.0){color = vec3(0.20,0.39,0.59);}\n"
        "else if(voxel.w == 210.0){color = vec3(0.00,0.32,0.96);}\n"
        "else if(voxel.w == 211.0){color = vec3(0.09,0.42,0.74);}\n"
        "else if(voxel.w == 212.0){color = vec3(0.14,0.47,0.86);}\n"
        "else if(voxel.w == 213.0){color = vec3(0.41,0.62,0.76);}\n"
        "else if(voxel.w == 214.0){color = vec3(0.29,0.64,1.00);}\n"
        "else if(voxel.w == 215.0){color = vec3(0.56,0.69,1.00);}\n"
        "else if(voxel.w == 216.0){color = vec3(0.35,0.77,1.00);}\n"
        "else if(voxel.w == 217.0){color = vec3(0.75,0.73,0.98);}\n"
        "else if(voxel.w == 218.0){color = vec3(0.47,0.43,0.94);}\n"
        "else if(voxel.w == 219.0){color = vec3(0.29,0.35,1.00);}\n"
        "else if(voxel.w == 220.0){color = vec3(0.38,0.25,0.96);}\n"
        "else if(voxel.w == 221.0){color = vec3(0.24,0.24,0.96);}\n"
        "else if(voxel.w == 222.0){color = vec3(0.06,0.11,0.85);}\n"
        "else if(voxel.w == 223.0){color = vec3(0.00,0.06,0.74);}\n"
        "else if(voxel.w == 224.0){color = vec3(0.14,0.06,0.58);}\n"
        "else if(voxel.w == 225.0){color = vec3(0.05,0.13,0.28);}\n"
        "else if(voxel.w == 226.0){color = vec3(0.31,0.06,0.69);}\n"
        "else if(voxel.w == 227.0){color = vec3(0.38,0.06,0.82);}\n"
        "else if(voxel.w == 228.0){color = vec3(0.53,0.20,0.82);}\n"
        "else if(voxel.w == 229.0){color = vec3(0.61,0.25,1.00);}\n"
        "else if(voxel.w == 230.0){color = vec3(0.74,0.38,1.00);}\n"
        "else if(voxel.w == 231.0){color = vec3(0.73,0.57,1.00);}\n"
        "else if(voxel.w == 232.0){color = vec3(0.84,0.65,1.00);}\n"
        "else if(voxel.w == 233.0){color = vec3(0.84,0.76,0.98);}\n"
        "else if(voxel.w == 234.0){color = vec3(0.97,0.78,0.99);}\n"
        "else if(voxel.w == 235.0){color = vec3(0.90,0.45,1.00);}\n"
        "else if(voxel.w == 236.0){color = vec3(1.00,0.32,1.00);}\n"
        "else if(voxel.w == 237.0){color = vec3(0.85,0.13,0.88);}\n"
        "else if(voxel.w == 238.0){color = vec3(0.74,0.16,1.00);}\n"
        "else if(voxel.w == 239.0){color = vec3(0.74,0.06,0.77);}\n"
        "else if(voxel.w == 240.0){color = vec3(0.55,0.08,0.75);}\n"
        "else if(voxel.w == 241.0){color = vec3(0.35,0.09,0.48);}\n"
        "else if(voxel.w == 242.0){color = vec3(0.39,0.08,0.39);}\n"
        "else if(voxel.w == 243.0){color = vec3(0.25,0.00,0.38);}\n"
        "else if(voxel.w == 244.0){color = vec3(0.20,0.04,0.27);}\n"
        "else if(voxel.w == 245.0){color = vec3(0.33,0.10,0.22);}\n"
        "else if(voxel.w == 246.0){color = vec3(0.63,0.10,0.51);}\n"
        "else if(voxel.w == 247.0){color = vec3(0.78,0.00,0.47);}\n"
        "else if(voxel.w == 248.0){color = vec3(1.00,0.31,0.75);}\n"
        "else if(voxel.w == 249.0){color = vec3(1.00,0.42,0.77);}\n"
        "else if(voxel.w == 250.0){color = vec3(0.98,0.63,0.73);}\n"
        "else if(voxel.w == 251.0){color = vec3(0.99,0.23,0.55);}\n"
        "else if(voxel.w == 252.0){color = vec3(0.90,0.12,0.47);}\n"
        "else if(voxel.w == 253.0){color = vec3(0.74,0.06,0.22);}\n"
        "else if(voxel.w == 254.0){color = vec3(0.60,0.20,0.30);}\n"
        "else if(voxel.w == 255.0){color = vec3(0.57,0.08,0.22);}\n"
        "gl_Position = projection * vertPos4;\n"
    "}\n";

const GLchar* f1 =
    "#version 100\n"
    "precision highp float;\n"
    "varying float lambertian;\n"
    "varying vec3 color;\n"
    "void main()\n"
    "{\n"
#ifdef SKYBLUE
        "gl_FragColor = vec4((color*0.11)+(lambertian*color), 1.0);\n"
#else
        "gl_FragColor = vec4(lambertian*color, 1.0);\n"
#endif
    "}\n";

//

GLuint shdHud;
GLint  shdHud_position;
GLint  shdHud_texcoord;
GLint  shdHud_sampler;

GLuint shdVoxel;
GLint  shdVoxel_projection;
GLint  shdVoxel_view;
GLint  shdVoxel_position;
GLint  shdVoxel_normal;
GLint  shdVoxel_voxel;

//

void makeVoxel()
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &v1, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &f1, NULL);
    glCompileShader(fragmentShader);

    shdVoxel = glCreateProgram();
        glAttachShader(shdVoxel, vertexShader);
        glAttachShader(shdVoxel, fragmentShader);
    glLinkProgram(shdVoxel);

    shdVoxel_position   = glGetAttribLocation(shdVoxel,  "position");
    shdVoxel_normal     = glGetAttribLocation(shdVoxel,  "normal");
    //<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    shdVoxel_projection = glGetUniformLocation(shdVoxel, "projection");
    shdVoxel_view       = glGetUniformLocation(shdVoxel, "view");
    shdVoxel_voxel      = glGetUniformLocation(shdVoxel, "voxel");

    esBind(GL_ARRAY_BUFFER,         &mdlVoxel.vid, voxel_vertices, sizeof(voxel_vertices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER,         &mdlVoxel.nid, voxel_normals,  sizeof(voxel_normals),  GL_STATIC_DRAW);
    esBind(GL_ELEMENT_ARRAY_BUFFER, &mdlVoxel.iid, voxel_indices,  sizeof(voxel_indices),  GL_STATIC_DRAW);
}
void shadeVoxel(GLint* projection, GLint* view, GLint* position, GLint* normal, GLint* voxel)
{
    *position = shdVoxel_position;
    *projection = shdVoxel_projection;
    *view = shdVoxel_view;
    *voxel = shdVoxel_voxel;
    *normal = shdVoxel_normal;
    glUseProgram(shdVoxel);
}

//

void makeHud()
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &v0, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &f0, NULL);
    glCompileShader(fragmentShader);

    shdHud = glCreateProgram();
        glAttachShader(shdHud, vertexShader);
        glAttachShader(shdHud, fragmentShader);
    glLinkProgram(shdHud);

    shdHud_position   = glGetAttribLocation(shdHud,  "position");
    shdHud_texcoord   = glGetAttribLocation(shdHud,  "texcoord");
    //<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
    shdHud_sampler    = glGetUniformLocation(shdHud, "tex");

    esBind(GL_ARRAY_BUFFER, &mdlPlane.vid, &hud_vertices, sizeof(hud_vertices), GL_STATIC_DRAW);
    esBind(GL_ELEMENT_ARRAY_BUFFER, &mdlPlane.iid, &hud_indices, sizeof(hud_indices), GL_STATIC_DRAW);
    esBind(GL_ARRAY_BUFFER, &mdlPlane.tid, &hud_uvmap, sizeof(hud_uvmap), GL_STATIC_DRAW);
}
void shadeHud(GLint* position, GLint* texcoord, GLint* sampler)
{
    *position = shdHud_position;
    *texcoord = shdHud_texcoord;
    *sampler = shdHud_sampler;
    glUseProgram(shdHud);
}

//

#endif
