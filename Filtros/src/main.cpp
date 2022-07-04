#include "Imagen.h"

int main (int argc,char** argv){
    Imagen imagen1 ("image1.bmp");
    imagen1.aprueba();
    imagen1.write("image2_color.bmp");
    //imagen1.~Imagen();
    //Imagen imagen2 ("image2.bmp");
    //imagen2.negativo();
    //magen2.write("image2_negativo.bmp");
    //Imagen imagen3 ("image3.bmp");
    //imagen3.negativo();
   // imagen3.write("image3_negativo.bmp");
    return 0;
}
