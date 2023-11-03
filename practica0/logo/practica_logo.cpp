
//Practica 0 IG B1
// Raúl Cruz Arévalo

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>



void Circle (GLfloat radio, GLfloat cx, GLfloat cy, GLint n, GLenum modo)
{
int i;
if (modo==GL_LINE) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
else if (modo==GL_FILL) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
else glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
glBegin( GL_POLYGON );
for (i=0;i<n;i++)
glVertex2f( cx+radio*cos(2.0*M_PI*i/n), cy+radio*sin(2.0*M_PI*i/n));
glEnd();
}



void Ejes (int width)
{   
    glLineWidth(width);
    glBegin(GL_LINES);
       glColor3f(1.0,0.0,0.0);
       glVertex3f(-1.0,0.0,0.0);
       glVertex3f(1.0,0.0,0.0);
       glColor3f(0.0,1.0,0.0);
       glVertex3f(0.0,-1.0,0.0);
       glColor3f(1.0,1.0,0.0);
       glVertex3f(0.0,1.0,0.0);   
    glEnd();
   
       
}


void Monigote ()
{
  
 /*
// cara
   glLineWidth(1);
   glColor3f(1.0,0.8,0.6);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
   	// Vertices de la figura 
      glVertex3f(-0.2,0.0,0.0);
      glVertex3f(0.2,0.0,0.0);
      glVertex3f(0.2,0.55,0.0);
      glVertex3f(-0.2,0.55,0.0);
   glEnd();

   glColor3f(0.0,0.0,0.);
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glBegin(GL_POLYGON);
      glVertex3f(-0.2,0.0,0.0);
      glVertex3f(0.2,0.0,0.0);
      glVertex3f(0.2,0.55,0.0);
      glVertex3f(-0.2,0.55,0.0);
   glEnd(); */
   
   // Para hacer el circulo (añadido en clase de prácticas) 
   glLineWidth(4) ; 
   glColor3f(0, 0, 200); 
   Circle(0.1,-0.239,0.35,30,GL_LINE); // Aro Azul 
   glColor3f(0, 0, 0);
   Circle(0.1,0,0.35,30,GL_LINE); // Aro Negro
   glColor3f(10, 0, 0);
   Circle(0.1,0.239,0.35,30,GL_LINE); // Aro Rojo
   glColor3f(1, 1, 0);
   Circle(0.1,-0.1295,0.23,30,GL_LINE); // Aro Amarillo
   glColor3f(0, 1, 0);
   Circle(0.1,0.1295,0.23,30,GL_LINE); // Aro Amarillo
    
    
   
}


static void Init( )
{

   glShadeModel( GL_FLAT); // Hacemos que sea un solo color plano 
}


static void Reshape( int width, int height ) // Hace los calculos para adaptar la figura al nuevo tamaño de pantalla 
{
    //glMatrixMode(GL_PROJECTION); Para arreglar lo que produce el gh ortho si le cambias los numeros 
    
    glViewport(0, 0, (GLint)width, (GLint)height);
    glOrtho (-1.0, 1.0,-1.0, 1.0, -10, 10.0); // Si subes el valor al hacer el reshape se verá más pequeño y se hará mal el reshape 
}

static void Display( )
{

  glClearColor(0.5,0.5,0.5,0.0); // Cambiar color de fondo 
  //glMatrixMode(GL_MODELVIEW); 
  glClear( GL_COLOR_BUFFER_BIT ); // Si no lo pones mantiene el color que hubiera antes 
  
  
   
   Ejes(4);
   Monigote();
   
   glFlush();
}


static void Keyboard(unsigned char key, int x, int y )
{
 
  if (key==27)
      exit(0);

}


int main( int argc, char **argv )
{
   glutInit(&argc,argv); // iniciar el glut 
   glutInitDisplayMode( GLUT_RGB );

   glutInitWindowPosition( 20, 100 ); // coordenadas de la pantalla donde aparece por defecto la ventana 
   glutInitWindowSize(500, 500 );
   glutCreateWindow("Practica 0 IG");


   Init(); 

   glutReshapeFunc(Reshape); // Si se produce el evento de "Reshape" se llama a la funcion reshape (Se produce siempre que cambio el tamaño de ventana) 
   glutDisplayFunc(Display); //  Si se produce el evento de "Display" se llama a la funcion Display (Se produce la ventana de OpenGl se pone al principio de todas el resto de ventanas) 
   glutKeyboardFunc(Keyboard);  //  Si se produce el evento de "KeyBoard" se llama a la funcion Display (Se produce cuando lee algo por teclado); 
    
  
   glutMainLoop( ); // Mira en bucle los eventos, si se produce alguno los realiza 

   return 0;
}

