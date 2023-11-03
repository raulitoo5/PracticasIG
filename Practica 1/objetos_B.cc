//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos_B.h"


//*************************************************************************
// _puntos3D
//*************************************************************************


_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}



//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}



//*************************************************************************
// dibujar en modo sólido con un único color
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glColor3f(r,g,b);
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido con colores diferentes para cada cara
//*************************************************************************

void _triangulos3D::draw_solido_colores( )
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glBegin(GL_TRIANGLES);
for (i=0;i<colores_caras.size();i++){
	glColor3f(colores_caras[i]._0,colores_caras[i]._1,colores_caras[i]._2);
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}



//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
//vertices
vertices.resize(8);
vertices[0].x=0;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=0;
vertices[3].x=0;vertices[3].y=0;vertices[3].z=0;
vertices[4].x=0;vertices[4].y=tam;vertices[4].z=tam;
vertices[5].x=tam;vertices[5].y=tam;vertices[5].z=tam;
vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=0;
vertices[7].x=0;vertices[7].y=tam;vertices[7].z=0;



// triangulos
caras.resize(12);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=3;	// vertices 1-2-4
caras[1]._0=1;caras[1]._1=2;caras[1]._2=3;	// vertices 2-3-4
caras[2]._0=0;caras[2]._1=1;caras[2]._2=4;	// vertices 1-2-5
caras[3]._0=1;caras[3]._1=4;caras[3]._2=5;	// vertices 2-5-6
caras[4]._0=1;caras[4]._1=2;caras[4]._2=5;	// vertices 2-3-6
caras[5]._0=2;caras[5]._1=5;caras[5]._2=6;	// vertices 3-6-7
caras[6]._0=4;caras[6]._1=6;caras[6]._2=7;	// vertices 5-7-8
caras[7]._0=0;caras[7]._1=4;caras[7]._2=7;	// vertices 1-5-8
caras[8]._0=0;caras[8]._1=3;caras[8]._2=7;	// vertices 1-4-8
caras[9]._0=7;caras[9]._1=6;caras[9]._2=3;	// vertices 4-7-8
caras[10]._0=6;caras[10]._1=2;caras[10]._2=3;	// vertices 3-4-7
caras[11]._0=4;caras[11]._1=5;caras[11]._2=6;	// vertices 5-6-7
//caras[12]._0=4;caras[12]._1=5;caras[12]._2=6;

// colores triangulos
colores_caras.resize(12);
colores_caras[0]._0=1.0;colores_caras[0]._1=0;colores_caras[0]._2=0;
colores_caras[1]._0=0.1;colores_caras[1]._1=1;colores_caras[1]._2=0;
colores_caras[2]._0=1.0;colores_caras[2]._1=0;colores_caras[2]._2=1;
colores_caras[3]._0=0.9;colores_caras[3]._1=0;colores_caras[3]._2=0;
colores_caras[4]._0=0.8;colores_caras[4]._1=1;colores_caras[4]._2=0;
colores_caras[5]._0=0.7;colores_caras[5]._1=0;colores_caras[5]._2=1;
colores_caras[6]._0=0.6;colores_caras[6]._1=1;colores_caras[6]._2=1;
colores_caras[7]._0=0.5;colores_caras[7]._1=1;colores_caras[7]._2=1;
colores_caras[8]._0=0.4;colores_caras[8]._1=0;colores_caras[8]._2=0;
colores_caras[9]._0=0.3;colores_caras[9]._1=0;colores_caras[9]._2=0;
colores_caras[10]._0=0.2;colores_caras[10]._1=1;colores_caras[10]._2=0;
colores_caras[11]._0=0;colores_caras[11]._1=0;colores_caras[11]._2=1;

}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

//vertices 
vertices.resize(5); 
vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

caras.resize(6);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;

colores_caras.resize(6);
colores_caras[0]._0=1.0;colores_caras[0]._1=0;colores_caras[0]._2=0;
colores_caras[1]._0=0.9;colores_caras[1]._1=1;colores_caras[1]._2=0;
colores_caras[2]._0=0.8;colores_caras[2]._1=0;colores_caras[2]._2=0;
colores_caras[3]._0=1.7;colores_caras[3]._1=0;colores_caras[3]._2=0;
colores_caras[4]._0=0.6;colores_caras[4]._1=0;colores_caras[4]._2=0;
colores_caras[5]._0=0.5;colores_caras[5]._1=1.0;colores_caras[5]._2=0;


}

// clase rectángulo

_rectangulo::_rectangulo(float ancho, float al, float largo){

//vertices
vertices.resize(8);
vertices[0].x=0;vertices[0].y=0;vertices[0].z=ancho;
vertices[1].x=largo;vertices[1].y=0;vertices[1].z=ancho;
vertices[2].x=largo;vertices[2].y=0;vertices[2].z=0;
vertices[3].x=0;vertices[3].y=0;vertices[3].z=0;
vertices[4].x=0;vertices[4].y=al;vertices[4].z=ancho;
vertices[5].x=0;vertices[5].y=al;vertices[5].z=0;
vertices[6].x=largo;vertices[6].y=al;vertices[6].z=0;
vertices[7].x=largo;vertices[7].y=al;vertices[7].z=ancho;

// triangulos
caras.resize(12);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=2;	// vertices 1-2-3
caras[1]._0=0;caras[1]._1=2;caras[1]._2=3;	// vertices 1-3-4
caras[2]._0=0;caras[2]._1=1;caras[2]._2=4;	// vertices 1-2-5
caras[3]._0=1;caras[3]._1=4;caras[3]._2=7;	// vertices 2-5-8
caras[4]._0=1;caras[4]._1=2;caras[4]._2=6;	// vertices 2-3-7
caras[5]._0=1;caras[5]._1=6;caras[5]._2=7;	// vertices 2-7-8
caras[6]._0=4;caras[6]._1=6;caras[6]._2=7;	// vertices 5-7-8
caras[7]._0=0;caras[7]._1=4;caras[7]._2=5;	// vertices 1-5-6
caras[8]._0=0;caras[8]._1=3;caras[8]._2=5;	// vertices 1-4-6
caras[9]._0=2;caras[9]._1=5;caras[9]._2=6;	// vertices 3-6-7
caras[10]._0=5;caras[10]._1=2;caras[10]._2=3;	// vertices 3-4-6
caras[11]._0=4;caras[11]._1=5;caras[11]._2=6;	// vertices 5-6-7

// colores triangulos
colores_caras.resize(12);
colores_caras[0]._0=1.0;colores_caras[0]._1=0;colores_caras[0]._2=0;
colores_caras[1]._0=0.1;colores_caras[1]._1=1;colores_caras[1]._2=0;
colores_caras[2]._0=1.0;colores_caras[2]._1=0;colores_caras[2]._2=1;
colores_caras[3]._0=0.9;colores_caras[3]._1=0;colores_caras[3]._2=0;
colores_caras[4]._0=0.8;colores_caras[4]._1=1;colores_caras[4]._2=0;
colores_caras[5]._0=0.7;colores_caras[5]._1=0;colores_caras[5]._2=1;
colores_caras[6]._0=0.6;colores_caras[6]._1=1;colores_caras[6]._2=1;
colores_caras[7]._0=0.5;colores_caras[7]._1=1;colores_caras[7]._2=1;
colores_caras[8]._0=0.4;colores_caras[8]._1=0;colores_caras[8]._2=0;
colores_caras[9]._0=0.3;colores_caras[9]._1=0;colores_caras[9]._2=0;
colores_caras[10]._0=0.2;colores_caras[10]._1=1;colores_caras[10]._2=0;
colores_caras[11]._0=0;colores_caras[11]._1=0;colores_caras[11]._2=1;
}
