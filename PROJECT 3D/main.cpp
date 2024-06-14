#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint texture; // Variable to store the texture ID
GLuint texture2;
GLuint texture3;
GLuint texture4;
GLuint texture5;
GLuint texture6;
GLuint texture7;

float cameraX = 0.0f;
float cameraY = 1.0f;
float cameraZ = 15.0f;
float cameraSpeed = 0.5f; // Speed of camera movement

//sudut awal kamera(look at)
GLfloat angleX = 0.0f;
GLfloat angleY = 0.0f;

int lastMouseX;
int lastMouseY;

void init() {
    glClearColor(0, 0, 0, 0);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering

    // Tekstur 1 (kayu penyangga)
    int width, height, channels;
    unsigned char* image = stbi_load("C:/Users/USER/Desktop/PHanny Poke/PROJECT 3D/texture/lantai.png", &width, &height, &channels, STBI_rgb_alpha);
    if (image == NULL) {
        printf("Error loading texture\n");
        exit(1);
    }
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    stbi_image_free(image);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //tekstur 2 (lantai)
     int width2, height2, channels2;
    unsigned char* image2 = stbi_load("C:/Users/USER/Desktop/PHanny Poke/PROJECT 3D/texture/papanhitam.jpg", &width2, &height2, &channels2, STBI_rgb_alpha);
    if (image2 == NULL) {
        printf("Error loading texture 2\n");
        exit(1);
    }

    // Generate and bind texture 2
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width2, height2, 0, GL_RGBA, GL_UNSIGNED_BYTE, image2);
    stbi_image_free(image2);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


     int width4, height4, channels4;
    unsigned char* image4 = stbi_load("C:/Users/USER/Desktop/PHanny Poke/PROJECT 3D/texture/berkayu.jpg", &width4, &height4, &channels4, STBI_rgb_alpha);
    if (image4 == NULL) {
        printf("Error loading texture 2\n");
        exit(1);
    }

    glGenTextures(1, &texture4);
    glBindTexture(GL_TEXTURE_2D, texture4);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width4, height4, 0, GL_RGBA, GL_UNSIGNED_BYTE, image4);
    stbi_image_free(image4);

    // Set texture parameters (same as before)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width5, height5, channels5;
    unsigned char* image5 = stbi_load("C:/Users/USER/Desktop/PHanny Poke/PROJECT 3D/texture/dinding.png", &width5, &height5, &channels5, STBI_rgb_alpha);
    if (image == NULL) {
        printf("Error loading texture5\n");
        exit(1);
    }
    glGenTextures(1, &texture5);
    glBindTexture(GL_TEXTURE_2D, texture5);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width5, height5, 0, GL_RGBA, GL_UNSIGNED_BYTE, image5);
    stbi_image_free(image5);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    int width6, height6, channels6;
    unsigned char* image6 = stbi_load("C:/Users/USER/Desktop/PHanny Poke/PROJECT 3D/texture/glass.png", &width6, &height6, &channels6, STBI_rgb_alpha);
    if (image == NULL) {
        printf("Error loading texture5\n");
        exit(1);
    }
    glGenTextures(6, &texture6);
    glBindTexture(GL_TEXTURE_2D, texture6);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width6, height6, 0, GL_RGBA, GL_UNSIGNED_BYTE, image6);
    stbi_image_free(image6);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width7, height7, channels7;
    unsigned char* image7 = stbi_load("C:/Users/USER/Desktop/PHanny Poke/PROJECT 3D/texture/whitewall.jpg", &width7, &height7, &channels7, STBI_rgb_alpha);
    if (image7 == NULL) {
        printf("Error loading texture 9\n");
        exit(1);
    }
    glGenTextures(7, &texture7);
    glBindTexture(GL_TEXTURE_2D, texture7);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width7, height7, 0, GL_RGBA, GL_UNSIGNED_BYTE, image7);
    stbi_image_free(image7);

    // Set texture parameters (same as before)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    //Mengaktifkan pencahayaan
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); // satu sumber cahaya

    // Set up Sumber cahaya


// Define the diffuse and ambient light colors
    GLfloat light_diffuse[] = { 0.6, 0.6, 0.6, 0.0 }; // Diffuse color (r, g, b, a)
    GLfloat light_ambient[] = { 0.6, 0.6, 0.6, 0.0 }; // Ambient color (r, g, b, a)

// Set light properties

glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
}

void drawCube(GLuint textures) {
    glBindTexture(GL_TEXTURE_2D, textures);
    glBegin(GL_QUADS);
    // Front face
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, 1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, 1);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, 1);

    // Back face
    glNormal3f(0.0, 0.0, -1.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, 1, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(1, -1, -1);

    // Top face
    glNormal3f(0.0, 1.0, 0.0); // Normal for the top face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, 1, 1);
    glTexCoord2f(1.0, 0.0); glVertex3f(1, 1, 1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1);

    // Bottom face
    glNormal3f(0.0, -1.0, 0.0); // Normal for the bottom face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, -1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(1, -1, 1);

    // Right face
    glNormal3f(1.0, 0.0, 0.0); // Normal for the right face
    glTexCoord2f(0.0, 0.0); glVertex3f(1, -1, 1);
    glTexCoord2f(1.0, 0.0); glVertex3f(1, -1, -1);
    glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, -1);
    glTexCoord2f(0.0, 1.0); glVertex3f(1, 1, 1);

    // Left face
    glNormal3f(-1.0, 0.0, 0.0); // Normal for the left face
    glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1, 1, 1);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, -1);
    glEnd();
}

void drawCubeNC() {
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glBegin(GL_QUADS);

    glColor3f(0, 0, 1); // Set color to blue

    // Front face
    glNormal3f(0.0, 0.0, 1.0); // Normal for the front face
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);

    // Back face
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);

    // Top face
    glNormal3f(0.0, 1.0, 0.0); // Normal for the top face
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);

    // Bottom face
    glNormal3f(0.0, -1.0, 0.0); // Normal for the bottom face
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);

    // Right face
    glNormal3f(1.0, 0.0, 0.0); // Normal for the right face
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);

    // Left face
    glNormal3f(-1.0, 0.0, 0.0); // Normal for the left face
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);

    glEnd();
    glEnable(GL_TEXTURE_2D);  // Re-enable textures if needed elsewhere
    glEnable(GL_LIGHTING);
}

void drawjendela(){
glPushMatrix();
glScalef(0.6,0.7,0.05);
glTranslatef(-6,3,-98);
drawCube(texture6);
glPopMatrix();

glPushMatrix();
glScalef(0.6,0.7,0.05);
glTranslatef(-2,3,-98);
drawCube(texture6);
glPopMatrix();

glPushMatrix();
glScalef(0.6,0.7,0.05);
glTranslatef(2,3,-98);
drawCube(texture6);
glPopMatrix();

glPushMatrix();
glScalef(0.6,0.7,0.05);
glTranslatef(6,3,-98);
drawCube(texture6);
glPopMatrix();
}

void drawpanggung(){
glPushMatrix();
glScalef(1,0.3,2);
glTranslatef(-3.8,0,0);
drawCube(texture);
glPopMatrix();
}
void drawclassblock() {
    glPushMatrix();
    glScalef(5, 0.1, 5);
    glTranslatef(0, -1, 0);
    drawCube(texture);
    glPopMatrix();

    glPushMatrix();
    glScalef(5, 0.1, 5);
    glTranslatef(0, 35, 0);
    drawCube(texture4);
    glPopMatrix();
    //TEMBOK KIRI
    glPushMatrix();
    glScalef(0.1,1.7, 5);
    glTranslatef(-48.9, 1, 0);
    drawCube(texture7);
    glPopMatrix();
    //TEMBOK KANAN
    glPushMatrix();
    glScalef(0.1, 1.7, 5);
    glTranslatef(48.9,1, 0);
    drawCube(texture7);
    glPopMatrix();

    //PAPAN TULIS
    glPushMatrix();
    glScalef(0.05,1,2);
    glTranslatef(-95,1.8,0);
    drawCube(texture2);
    glPopMatrix();

    //TEMBOK BELAKANG
    glPushMatrix();
    glScalef(4.8,0.7,0.1);
    glTranslatef(0,1,-49);
    drawCube(texture7);
    glPopMatrix();

    glPushMatrix();
    glScalef(4.8,0.35,0.1);
    glTranslatef(0,9,-49);
    drawCube(texture7);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.6,0.7,0.1);
    glTranslatef(-4,3,-49);
    drawCube(texture7);
    glPopMatrix();

     glPushMatrix();
    glScalef(0.6,0.7,0.1);
    glTranslatef(0,3,-49);
    drawCube(texture7);
    glPopMatrix();

     glPushMatrix();
    glScalef(0.6,0.7,0.1);
    glTranslatef(4,3,-49);
    drawCube(texture7);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.3,0.7,0.1);
    glTranslatef(15,3,-49);
    drawCube(texture7);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.3,0.7,0.1);
    glTranslatef(-15,3,-49);
    drawCube(texture7);
    glPopMatrix();

    //JENDELA
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(0,0,0);
    drawjendela();
    glPopMatrix();

    //PANGGUNG
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(0,0,0);
    drawpanggung();
    glPopMatrix();
}

void meja(){
glPushMatrix();
glScalef(0.05,0.27,0.05);
glTranslatef(2.7*10+2,1,3.3*10);
drawCube(texture4);
glPopMatrix();

glPushMatrix();
glScalef(0.05,0.27,0.05);
glTranslatef(3.8*10+2,1,3.3*10);
drawCube(texture4);
glPopMatrix();

glPushMatrix();
glScalef(0.05,0.27,0.05);
glTranslatef(2.7*10+2,1,2.2*10);
drawCube(texture4);
glPopMatrix();

glPushMatrix();
glScalef(0.05,0.27,0.05);
glTranslatef(3.8*10+2,1,2.2*10);
drawCube(texture4);
glPopMatrix();

glPushMatrix();
glScalef(0.4,0.05,0.4);
glTranslatef(4.3,12,3.45);
drawCube(texture4);
glPopMatrix();
}

void drawkursi(){
glPushMatrix();
glScalef(0.6,0.6,0.6);
glTranslatef(2.5,0,0.9);
meja();
glPopMatrix();

glPushMatrix();
glScalef(0.02,0.27,0.2);
glTranslatef(13.75 * 10,2.45,6.85);
drawCube(texture4);
glPopMatrix();
}

void drawCylinder() {
    glDisable(GL_TEXTURE_2D);
    GLUquadric* quadric = gluNewQuadric();  // Membuat objek quadric
    glPushMatrix();                         // Save current state of transformations
    glTranslatef(0.0f, 3.5f, 0.0f);        // Translasi silinder ke posisi yang diinginkan
    glColor3f(1,1,1);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    // Gambar silinder
    gluCylinder(quadric, 0.05, 0.05, 0.8, 32, 32);
    glPopMatrix();                          // Restore the previous state
    gluDeleteQuadric(quadric);              // Hapus objek quadric
    glEnable(GL_TEXTURE_2D);
}

void drawcamera(){
glPushMatrix();
glTranslatef(-0.01,2.7,0.2);
glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
glScalef(1.5,0.1,1.5);
drawCylinder();
glPopMatrix();


}
void drawprojector() {
    // Draw cylinder part of the projector
    glPushMatrix();
    glColor3f(1, 1, 1);  // Set the color of the cylinder to white
    drawCylinder();
    glPopMatrix();

    // Draw cube part of the projector
    glPushMatrix();
    glDisable(GL_TEXTURE_2D);  // Disable textures for the cube
    glColor3f(0, 0, 1);  // Set the color of the cube to blue
    glTranslatef(0, 2.7, 0);
    glScalef(0.6, 0.2, 0.8);
    glutSolidCube(1);
    //drawCubeNC();
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);  // Re-enable textures if needed elsewhere
}

void drawmejakursi(){
glPushMatrix();
glScalef(1,1,1);
glTranslatef(0.5,0,2);
meja();
drawkursi();
glPopMatrix();
}

void drawlemari(){
glPushMatrix();
glScalef(0.4,1.3,0.4);
glTranslatef(10.8,1,-10);
drawCube(texture2);
glPopMatrix();

glPushMatrix();
glScalef(0.05,1.1,0.4);
glTranslatef(77.5,1.2,-10);
drawCube(texture4);
glPopMatrix();
}

void draw3lemari(){
for(int i = 0 ; i < 3;i++){
    int newz = i * 1;
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(0,0,newz);
    drawlemari();
    glPopMatrix();
}
}

void drawkursimejaguru(){
glPushMatrix();
glScalef(1,1,2);
glTranslatef(-5,0,-3);
meja();
glPopMatrix();

glPushMatrix();
glScalef(1,1,1);
glTranslatef(-1.5,0,-2);
glRotatef(180,0,1,0);
drawkursi();
glPopMatrix();
}

void mejakursi9(){

for(int i = 0 ; i< 3;i++){
    int xbaru = 0 - i * 2;
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(xbaru,0,0);
    drawmejakursi();
    glPopMatrix();
}
for(int i = 0 ; i< 3;i++){
    int xbaru = 0 - i * 2;
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(xbaru,0,-3.4);
    drawmejakursi();
    glPopMatrix();
}

for(int i = 0 ; i< 3;i++){
    int xbaru = 0 - i * 2;
    glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(xbaru,0,-6.8);
    drawmejakursi();
    glPopMatrix();
}
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case 'a': // Move camera left
        cameraX -= cameraSpeed;
        break;
    case 'd': // Move camera right
        cameraX += cameraSpeed;
        break;
    case 'w': // Move camera forward
        cameraZ -= cameraSpeed;
        break;
    case 's': // Move camera backward
        cameraZ += cameraSpeed;
        break;
    case 'i':
        cameraY += 1;
        break;
    case 'o':
        cameraY -= 1;
        break;
    }
    glutPostRedisplay(); // Redraw the scene with the updated camera position
}
void display(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(cameraX,cameraY,cameraZ,
          angleY,angleX,-5,
          0,1,0);

GLfloat light_position[] = { -4.0, 2.0, 10.0, 1.0 }; // Light position (x, y, z, w)
glLightfv(GL_LIGHT0, GL_POSITION, light_position);
drawclassblock();
mejakursi9();
drawcamera();
drawkursimejaguru();
draw3lemari();
drawprojector();
glutSwapBuffers();
}

void mouse(int x, int y) {
    int deltaX = x - lastMouseX;
    int deltaY = y - lastMouseY;

    angleY += deltaX * 0.1f;
    angleX -= deltaY * 0.1f;

    lastMouseX = x;
    lastMouseY = y;

    glutPostRedisplay();
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        lastMouseX = x;
        lastMouseY = y;
        glutMotionFunc(mouse);
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        glutMotionFunc(NULL);
    }
}

void reshape(int width, int height){
glClearColor(0,0,0,0);
glViewport(0,0,width,height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0 ,(double)width/(double)height,1.0,100.0);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char**argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
glutInitWindowSize(800,600);
glutCreateWindow("Project 3D");
init();
glEnable(GL_DEPTH_TEST);

glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(handleKeypress);
glutMouseFunc(mouseButton);

glutMainLoop();
return 0;
}
