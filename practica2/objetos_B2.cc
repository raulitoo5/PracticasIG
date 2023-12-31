//**************************************************************************
// Práctica 2 
//**************************************************************************

#include "objetos_B2.h"
#include "file_ply_stl.hpp"


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

void _triangulos3D::coloresRandom(){
  for(int i=0; i<colores_caras.size(); i++){
  colores_caras[i]._0 = (rand()%1000)/1000.0;
  colores_caras[i]._1 = (rand()%1000)/1000.0;
  colores_caras[i]._2 = (rand()%1000)/1000.0; 
  }
}

void _triangulos3D::colores_cambio(){
  int n_c;
  n_c=caras.size();
  colores_caras.resize(n_c);

  for(int i = 0; i<n_c; i++){
    if(vertices[caras[i]._0].y>=0.0){
      colores_caras[i].r=0.0;
      colores_caras[i].g=0.2;
      colores_caras[i].b=0.7;
    }
    else{
      colores_caras[i].r=0.7;
      colores_caras[i].g=0.0;
      colores_caras[i].b=0.3;
    }
  }
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
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r, float g, float b, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r, g, b, grosor);break;
	case EDGES:draw_aristas(r, g, b, grosor);break;
	case SOLID:draw_solido(r, g, b);break;
	case SOLID_COLORS:draw_solido_colores();break;
	}
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
coloresRandom();

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
coloresRandom();


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

//*************************************************************************
// clase objeto ply
//*************************************************************************


_objeto_ply::_objeto_ply() 
{
   // leer lista de coordenadas de vértices y lista de indices de vértices
 
}



void _objeto_ply::parametros(char *archivo)
{
int n_ver,n_car;

vector<float> ver_ply ;
vector<int>   car_ply ;
 
_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
n_car=car_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

vertices.resize(n_ver);
caras.resize(n_car);
colores_caras.resize(n_car);

// vertices

for(int i=0; i<n_ver; i++){
  vertices[i].x=ver_ply[i*3];
  vertices[i].y=ver_ply[i*3+1];
  vertices[i].z=ver_ply[i*3+2];
}

// caras
for(int i=0; i<n_car; i++){
  caras[i]._0=car_ply[i*3];
  caras[i]._1=car_ply[i*3+1];
  caras[i]._2=car_ply[i*3+2];
}

// colores_caras
//coloresRandom();
colores_cambio();

}


//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{

}


// El parámetro num es el número de caras que vamos a tener, y perfil es el conjunto de los vértices del perfil
void _rotacion::parametros(vector<_vertex3f> perfil, int num, int tapa_in, int tapa_su)
{
int i,j;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=perfil.size();  // De aquí sacamos el número de vértices del perfil
vertices.resize(num_aux*num); // Esto lo hacemos ya que el número de vértices reales va a ser el número de vértices del perfil por el número de caras
for (j=0;j<num;j++)
  {for (i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }

// tratamiento de las caras 
for(int j=0;j<num; j++){  // Este for se hace tantas veces como caras vamos a tener
  for(int i =0; i<num_aux-1; i++){  // Este for se hace tantas veces como números de vértices en el perfil 
    cara_aux._0=i+j*num_aux;
    cara_aux._1=i+((j+1)%num)*num_aux;
    cara_aux._2=i+1+j*num_aux;

    caras.push_back(cara_aux);

    cara_aux._0=i+((j+1)%num)*num_aux;
    cara_aux._1=i+1+((j+1)%num)*num_aux;
    cara_aux._2=i+1+j*num_aux;

    caras.push_back(cara_aux);
  }
}
     
// tapa inferior
if(tapa_in==1){

  // punto central de la tapa
  vertice_aux.x=0.0;
  vertice_aux.y=perfil[0].y;
  vertice_aux.z=0.0;
  vertices.push_back(vertice_aux);

  for(int j=0; j<num; j++){
    cara_aux._0=num_aux*num;
    cara_aux._1=((j+1)%num)*num_aux;
    cara_aux._2=j*num_aux;
    caras.push_back(cara_aux);
  }
}
 
// tapa superior

if(tapa_su==1){
  int sup;

  // punto cnetral de la tapa
  vertice_aux.x=0.0;
  vertice_aux.y=perfil[num_aux-1].y;
  vertice_aux.z=0.0;
  vertices.push_back(vertice_aux);

  if(tapa_in==1)
    sup = num_aux*num+1;
  else 
    sup = num_aux*num;

    for(int j=0; j<num; j++){
      cara_aux._0=sup;
      cara_aux._1=j*num_aux+num_aux-1;
      cara_aux._2=((j+1)%num)*num_aux+num_aux-1;
      caras.push_back(cara_aux);

    }

}

// colores
colores_caras.resize(caras.size());
coloresRandom();
// colores_cambio();
}



//************************************************************************
// objeto por extrusión
//************************************************************************


_extrusion::_extrusion(vector<_vertex3f> poligono, float x, float y, float z)
{
int i;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=poligono.size();
vertices.resize(num_aux*2);
for (i=0;i<num_aux;i++)
    {
      vertices[2*i]=poligono[i];
      vertices[2*i+1].x=poligono[i].x+x;
      vertices[2*i+1].y=poligono[i].y+y;
      vertices[2*i+1].z=poligono[i].z+z;
    }
    
// tratamiento de las caras 

caras.resize(num_aux*2);
int c=0;
for (i=0;i<num_aux;i++)         
  {
   caras[c]._0=i*2;
   caras[c]._1=(i*2+2)%(num_aux*2);
   caras[c]._2=i*2+1;    
   c=c+1;
   caras[c]._0=(i*2+2)%(num_aux*2);
   caras[c]._1=(i*2+2)%(num_aux*2)+1;
   caras[c]._2=i*2+1;    
   c=c+1;    
      
   }   

   colores_caras.resize(poligono.size()*2);
   coloresRandom();
}

_cilindro::_cilindro(float radio, float altura, int lados){
  vector<_vertex3f> perfil;
  _vertex3f aux;

  aux.x=radio;
  aux.y=-altura/2.0;
  aux.z=0.0;
  perfil.push_back(aux);

  aux.x=radio;
  aux.y=altura/2;
  aux.z=0.0;
  perfil.push_back(aux);

// CON ESTO MAS LO DE ARRIBA PODEMOS HACER UNA RUEDA
  // aux.x=radio*2;
  // aux.y=altura/2;
  // aux.z=0.0;
  // perfil.push_back(aux);

  // aux.x=radio*2;
  // aux.y=-altura/2;
  // aux.z=0.0;
  // perfil.push_back(aux);

  parametros(perfil,lados,1,1);
}

_cono::_cono(float radio, float altura, int lados){
   vector<_vertex3f> perfil;
  _vertex3f aux;

  aux.x=0.0;
  aux.y=altura;
  aux.z=0.0;
  perfil.push_back(aux);

  aux.x=radio;
  aux.y=0.0;
  aux.z=0.0;
  perfil.push_back(aux);

// CON ESTO MAS LO DE ARRIBA PODEMOS HACER UNA RUEDA
//   aux.x=radio*2;
//   aux.y=altura/2;
//   aux.z=0.0;
//   perfil.push_back(aux);

//   aux.x=radio*2;
//   aux.y=-altura/2;
//   aux.z=0.0;
//   perfil.push_back(aux);

  cout << "cilindro llama a parametros" << endl;
  parametros(perfil,lados,1,1);
}

_esfera::_esfera( float radio, int latitud, int longitud){
  _vertex3f aux;
  vector<_vertex3f> perfil;

  // for(int i =1; i<latitud; i++){
  //   aux.x=radio*cos(M_PI/i);
  //   aux.y=radio*sin(M_PI/i);
  //   aux.z=0.0;
  //   perfil.push_back(aux);
  // }

  for(int i =0; i<=latitud; i++){
    aux.x=radio*cos(M_PI*i/latitud-M_PI/2.0);
    aux.y=radio*sin(M_PI*i/latitud-M_PI/2.0);
    aux.z=0.0;
    perfil.push_back(aux);
  }
  parametros(perfil,longitud,1,1);
}

void _objeto_ply_rotacion::parametros_rotacion(char *archivo, int tapa_in, int tapa_su)
{
int n_ver,n_car;

vector<float> ver_ply ;
vector<int>   car_ply ;
 
_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
//n_car=car_ply.size()/3;

printf("Number of vertices=%d", n_ver);

vertices.resize(n_ver);
//caras.resize(n_car);
//colores_caras.resize(n_car);

// vertices

for(int i=0; i<n_ver; i++){
  vertices[i].x=ver_ply[i*3];
  vertices[i].y=ver_ply[i*3+1];
  vertices[i].z=ver_ply[i*3+2];
}

parametros(vertices,10,tapa_in,tapa_su);

// // caras
// for(int i=0; i<n_car; i++){
//   caras[i]._0=car_ply[i*3];
//   caras[i]._1=car_ply[i*3+1];
//   caras[i]._2=car_ply[i*3+2];
// }

// colores_caras
//coloresRandom();
colores_cambio();

}

_objeto_ply_rotacion::_objeto_ply_rotacion(){

}



