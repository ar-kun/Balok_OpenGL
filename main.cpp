#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
//deklarasi fungsi
void display();
void init();
void reshape(int, int);
void keyboard(unsigned char, int, int); //+1
//main program
int main (int argc, char** argv){
 //inisialisasi
 glutInit(&argc, argv);
 glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); //+2 GLUT_DEPTH : mengalokasikan sumbu z
 glutInitWindowPosition(200, 100); //atur sumbu x dan y
 glutInitWindowSize(500, 500); //atur lebar dan tinggi jendela
 glutCreateWindow("Kubus [ Adam Ramdan ]");
 glutDisplayFunc(display); //memanggil fungsi display
 glutReshapeFunc(reshape); //memanggil fungsi reshape
 glutKeyboardFunc(keyboard); // +3 memanggil fungsi keyboard
 init();
 glutMainLoop(); //looping program utama
}
void init(){
 glEnable(GL_DEPTH_TEST); //+4
 glClearColor(0.5, 05, 1.0, 0.5);

}
void display(){
 //reset
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //+5

    glBegin(GL_QUADS); //Depan
        glColor3f(0.0, 0.0, 1.0);
    glVertex3f(3.0, 3.0, 0.0);
    glVertex3f(3.0, -3.0, 0.0);
    glVertex3f(-3.0, -3.0, 0.0);
    glVertex3f(-3.0, 3.0, 0.0);
    glEnd();

    glBegin(GL_QUADS); //Belakang
        glColor3f(1.0, 0.0, 0.0);
    glVertex3f(3.0, 3.0, -6.0);
    glVertex3f(3.0, -3.0, -6.0);
    glVertex3f(-3.0, -3.0, -6.0);
    glVertex3f(-3.0, 3.0, -6.0);
    glEnd();

    glBegin(GL_QUADS);  //Samping Kanan
        glColor3f(0.0, 0.0, 1.0);
    glVertex3f(3.0, 3.0, 0.0);
        glColor3f(1.0, 1.0, 0.0);
    glVertex3f(3.0, -3.0, 0.0);
        glColor3f(1.0, 0.0, 0.0);
    glVertex3f(3.0, -3.0, -6.0);
        glColor3f(0.0, 1.0, 0.0);
    glVertex3f(3.0, 3.0, -6.0);
    glEnd();

    glBegin(GL_QUADS);  //Samping Kiri
        glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-3.0, 3.0, -6.0);
        glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-3.0, -3.0, -6.0);
        glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-3.0, -3.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-3.0, 3.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);  //Atas
        glColor3f(0.0, 1.0, 0.0);
    glVertex3f(3.0, 3.0, 0.0);
    glVertex3f(3.0, 3.0, -6.0);
    glVertex3f(-3.0, 3.0, -6.0);
    glVertex3f(-3.0, 3.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);  //Bawah
        glColor3f(1.0, 1.0, 0.0);
    glVertex3f(3.0, -3.0, -6.0);
    glVertex3f(3.0, -3.0, 0.0);
    glVertex3f(-3.0, -3.0, 0.0);
    glVertex3f(-3.0, -3.0, -6.0);
    glEnd();

    glFlush();
    glutSwapBuffers();
}
//fungsi untuk setting viewport
void reshape(int w, int h){
 glViewport(0,0, (GLsizei)w, (GLsizei)h); //membuat viewport sesuai ukuran jendela
 glMatrixMode(GL_PROJECTION); //merubah matrix mode menjadi gl_projection
 glLoadIdentity(); //reset transformasi misalnya rotasi pada display
 //gluOrtho2D(-10, 10, -10, 10); //setting spesifikasi proyeksi yang diinginkan (2D)
 glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); //+6 proyeksi 3D
 glMatrixMode(GL_MODELVIEW); //merubah matrix mode menjadi gl_modelview
}
//+7
void keyboard(unsigned char key, int x, int y)
{
/* Program Keyboard Untuk Rotate & Translate [ Memutar & Menggeser ] */
switch (key)
{
        case 'u':
        case 'U':
        glRotatef(3.0, 1.0, 0.0, 0.0); /* rotate Atas */
    break;
        case 'd':
        case 'D':
        glRotatef(-3.0, 1.0, 0.0, 0.0); /* rotate Bawah */
    break;
        case 'r':
        case 'R':
        glRotatef(3.0, 0.0, 1.0, 0.0); /* rotate Kanan Sumbu Y */
    break;
        case 'l':
        case 'L':
        glRotatef(-3.0, 0.0, 1.0, 0.0); /* rotate Kiri Sumbu Y */
    break;
        case 'n':
        case 'N':
        glRotatef(-3.0, 0.0, 0.0, 1.0); /* rotate Kanan Sumbu Z */
    break;
        case 'b':
        case 'B':
        glRotatef(3.0, 0.0, 0.0, 1.0); /* rotate Kiri Sumbu Z */
    break;
        case '>':
        case '.':
        glTranslated(3.0, 0.0, 0.0); //geser ke Kanan
     break;
        case '<':
        case ',':
        glTranslated(-3.0, 0.0, 0.0); //geser ke Kiri
     break;
        case 'w':
        case 'W':
        glTranslated(0.0, 3.0, 0.0); //geser ke Atas
     break;
        case 's':
        case 'S':
        glTranslated(0.0, -3.0, 0.0); //geser ke Bawah
     break;
        case 'o':
        case 'O':
        glTranslated(0.0, 0.0, 3.0); //geser ke Dalam
     break;
        case 'p':
        case 'P':
        glTranslated(0.0, 0.0, -3.0); //geser ke Luar
     break;
}
display(); //memanggil fungsi display atau bisa pakai glutPostRedisplay();
}
