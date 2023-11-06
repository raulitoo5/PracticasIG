//**************************************************************************
// Práctica 2 
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include <string>


const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID,SOLID_COLORS} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:

  
	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
vector<_vertex3f> colores_vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_colores();
void 	draw(_modo modo, float r, float g, float b, float grosor);

/* asignación de colores */
void 	colors_random();
void 	colors_chess(float r1, float g1, float b1, float r2, float g2, float b2);
void color_marron();
void color_negro();
void color_rojo();
void color_azul();
void color_amarillo();
void color_verde();
void color_azul_nube();


vector<_vertex3i> caras;
vector<_vertex3f> colores_caras;
};

//*************************************************************************
// objetos o modelos
//*************************************************************************

//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:
	_cubo(float tam=0.5, string color="negro");
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=1.0);
};

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

void  parametros(char *archivo);
};

//************************************************************************
// objeto por revolución
//************************************************************************


class _rotacion: public _triangulos3D
{
public:
       _rotacion();
       
void  parametros(vector<_vertex3f> perfil, int num,  
                 int tapa_in, int tapa_su, int tipo, string color);
};

// tapa_in=0 sin tapa, tapa_in=1 con tapa
// tapa_su=0 sin tapa, tapa_su=1 con tapa
// tipo=0 revolucion normal
// tipo=1 esfera
// tipo=2 cono

//************************************************************************
// objeto por extrusión
//************************************************************************

class _extrusion: public _triangulos3D
{
public:
       _extrusion(vector<_vertex3f> poligono, float x, float y, float z);
};


//************************************************************************
// objeto por revolución especiales
//************************************************************************

 
//************************************************************************
// cilindro
//************************************************************************

class _cilindro: public _rotacion
{
public:
       _cilindro(float radio=1.0, float altura=2.0, int num=12, int tapa_in=1, int tapa_su=1, string color="negro");
};

//************************************************************************
// cono
//************************************************************************

class _cono: public _rotacion
{
public:
       _cono(float radio=1.0, float altura=2.0, int num=12, string color="negro");
};

//************************************************************************
// esfera
//************************************************************************

// Latitud son las divisiones horizontales y longitud son las divisiones verticales
class _esfera: public _rotacion
{
public:
       _esfera(float radio=1.0, int latitud=6, int longitud=6, string color="negro");
};


//************************************************************************
// rotacion archivo PLY
//************************************************************************

class _rotacion_PLY: public _rotacion
{
public:
       _rotacion_PLY();
void  parametros_PLY(char *archivo, int num);
};


//************************************************************************
// práctica 3, objeto jerárquico articulado excavadora
//************************************************************************

//************************************************************************
// piezas
//************************************************************************

//************************************************************************
// pala
//************************************************************************

class _pala: public _triangulos3D
{
public:
      _pala(float radio=1.0, float ancho=2.0, int num=8);
};

//************************************************************************
// brazo
//************************************************************************

class _brazo: public _triangulos3D
{
public:
      _brazo();
void  draw(_modo modo, float r, float g, float b, float grosor);

float ancho;
float alto;
float fondo;

protected:
_cubo cubo;
};

//************************************************************************
// cabina
//************************************************************************

class _cabina: public _triangulos3D
{
public:
       _cabina();
void  draw(_modo modo, float r, float g, float b, float grosor);

float ancho;
float alto;
float fondo;

protected:
_cubo cubo;
};

//************************************************************************
// sustentación
//************************************************************************

class _sustentacion: public _triangulos3D
{
public:
      _sustentacion();
void  draw(_modo modo, float r, float g, float b, float grosor);
       
float ancho;
float alto;
float fondo;

float radio;

protected:
_cilindro rueda;
_cubo base;
};

//************************************************************************
// excavadora (montaje del objeto final)
//************************************************************************

class _excavadora: public _triangulos3D
{
public:
       _excavadora();
       
void  draw(_modo modo, float r, float g, float b, float grosor);

float giro_cabina;
float giro_primer_brazo;
float giro_segundo_brazo;
float giro_pala;

float giro_primer_brazo_max;
float giro_primer_brazo_min;
float giro_segundo_brazo_max;
float giro_segundo_brazo_min;
float giro_pala_max;
float giro_pala_min;

float tamanio_pala;

protected:
_pala pala;
_brazo brazo;
_cabina cabina;
_sustentacion sustentacion;
};

class _rectangulo: public _triangulos3D
{
	public:

	_rectangulo(float ancho=0.5, float al=0.5, float largo=1.5, string color="negro");
};



class _globo:_triangulos3D{
public:
       _globo();

void  draw(_modo modo, float r, float g, float b, float grosor);

float radio;
float latitud;
float longitud;


protected:
_esfera esfera;
};

class _cesta:_triangulos3D{
public:
       _cesta();

void  draw(_modo modo, float r, float g, float b, float grosor);

float radio;
float alto;
float caras;

protected:
_cilindro cilindro;

};

class _soporteHelice: _triangulos3D{
public:
       _soporteHelice();

void  draw(_modo modo, float r, float g, float b, float grosor);

float ancho;
float alto;
float largo;

protected:
_rectangulo rectangulo;
};

class _llama: _triangulos3D{
public:
       _llama();

void  draw(_modo modo, float r, float g, float b, float grosor);

float ancho;
float alto;
float largo;

protected:
_rectangulo rectangulo;
};


// Helice del globo
class _helice: _triangulos3D{
public:
       _helice();
void draw(_modo modo, float r, float g, float b, float grosor);

float ancho;
float alto;
float largo;

protected:
_rectangulo rectangulo;
};

class _base_cañon: _triangulos3D{
public: 
       _base_cañon();
void draw(_modo modo, float r, float g, float b, float grosor);

float tam;

protected: 
_cubo cubo;
};

class _cañon: _triangulos3D{
public: 
       _cañon();
void draw(_modo modo, float r, float g, float b, float grosor);

float radio;
float alto;
float caras;

protected:
_cilindro cilindro;
_base_cañon base;
};

class _suelo: _triangulos3D{
public:
       _suelo();

void  draw(_modo modo, float r, float g, float b, float grosor);

float ancho;
float alto;
float largo;

protected:
_rectangulo rectangulo;
};

class _soporteGlobo: _triangulos3D{
public:
       _soporteGlobo();
void  draw(_modo modo, float r, float g, float b, float grosor);

float ancho;
float alto;
float largo;

protected:
       _rectangulo rectangulo;
};

class _nube: _triangulos3D{
public:
       _nube();
void  draw(_modo modo, float r, float g, float b, float grosor);

float radio;
float latitud;
float longitud;


protected:
_esfera esfera_izquierda;
_esfera esfera_medio;
_esfera esfera_derecha;
};

// Globo completo
class _globoCompleto:_triangulos3D{
public:
       _globoCompleto();
void  draw(_modo modo, float r, float g, float b, float grosor);

float giro_helice_izquierda;
float giro_helice_derecha;
float giro_canion_izquierda;
float giro_canion_derecha;
float mov_posicion_nube;
float mov_posicion_globo;

protected:
_globo globo;
_cesta cesta;
_soporteHelice soporte;
_llama llama;       // He usado la misma clase que soporteHelice ya que simula donde se pone la llama del globo
_helice helice_derecha;
_helice helice_izquierda;
// _base_cañon base_izquierda;
// _base_cañon base_derecha;
_cañon cañon_izquierda;
_cañon cañon_derecha;
_suelo suelo;
_soporteGlobo soporteDerecha;
_soporteGlobo soporteIzquierda;
_nube nube;
};

