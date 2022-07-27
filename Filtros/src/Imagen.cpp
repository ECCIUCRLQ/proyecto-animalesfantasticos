#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Imagen.h"
#include "stb_image.h"
#include "stb_image_write.h"

extern "C" void filtro_negativo(uint8_t* pixels, size_t tamanyo);
extern "C" void filtro_difuminar(uint8_t* pixels, size_t tamanyo,int canales,float a,float b,float c);
extern "C" void aprueba_colores(uint8_t* pixels, size_t tamanyo,size_t a);

    Imagen::Imagen(const char* nombreArchivo){
        if (read(nombreArchivo)){
            printf("Se leyo el archivo: %s\n",nombreArchivo);
            tamanyo = l*a*canales;
        }
        else{
            printf("Error leyendo el archivo: %s\n",nombreArchivo);
        }
    }

    Imagen::Imagen(int l, int a,int canales): l(l) ,a(a) ,canales(canales){
        tamanyo = l*a*canales;
        datos = new uint8_t[tamanyo];
    }

    Imagen::Imagen(const Imagen& img): Imagen(img.l,img.a,img.canales){
        memcpy(datos,img.datos,tamanyo);
    }

    Imagen::~Imagen(){
        stbi_image_free(datos);
    }

    bool Imagen:: read(const char* nombreArchivo){
        datos = stbi_load(nombreArchivo, &l, &a, &canales, 0);
        return datos != NULL;
    }

    bool Imagen:: write(const char* nombreArchivo){
        int exito;
        exito = stbi_write_bmp(nombreArchivo,l,a,canales,datos);
        return exito != 0;

    }

    void Imagen::negativo() {
       //filtro_negativo(datos, tamanyo);
    }

    //Imagen& Imagen :: gris(){
       // datosCopia = datos;
        //este ciclo tiene que ir en ensamblador
        //hay que pasar por parametro a ensambla : tamanyo,canales , datos copia
        //for (int i = 0;i < tamanyo;i+=canales){
          //  int gris = (datosCopia[i]+datosCopia[i+1]+datosCopia[i+2])/3;
            //memset(datosCopia+i,gris,3);//?
        //}
       // datos = datosCopia;
        //return *this;
   // }


    void Imagen ::difuminar(float a,float b, float c){
        //vector bytes, tamanyo, canales , a , b, c 
        //datosCopia = datos;
        //for(int i = 0;i<tamanyo;i+=canales){
            //datos[i] += a;
            //datos[i+1] += b;
            //datos[i+2] += c;
       // }
        //datos = datosCopia;
        //filtro_difuminar(datos,tamanyo,canales,a,b,c);
       //filtro_negativo(datos,tamanyo);
    }

    void Imagen :: aprueba(){
        //size_t a = tamanyo/2; 
        //printf("tamanyo: %lu",tamanyo);
        aprueba_colores(datos,tamanyo,a);
    }

