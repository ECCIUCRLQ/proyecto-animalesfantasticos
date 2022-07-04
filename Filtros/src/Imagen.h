#include <cstdio>
#include <stdint.h>

enum TipoImagen{
    BMP
};

struct Imagen{
    uint8_t* datos = NULL;
    uint8_t* datosCopia = NULL;//no es parte de la imagen
    size_t tamanyo = 0;
    int l;//largo de la imagen
    int a;//altura de la imagen
    int canales;


    Imagen (const char* nombreArchivo);
    Imagen (int l, int a,int canales);
    Imagen (const Imagen& img);
    ~Imagen();

    bool read(const char* nombreArchivo);
    bool write(const char* nombreArchivo);

    TipoImagen regresarTipo();

    void negativo();
    void difuminar(float a,float b,float c);
    void aprueba();
    
};
