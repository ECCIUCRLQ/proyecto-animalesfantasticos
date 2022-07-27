#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <inttypes.h>

#define CHARACTER_DEVICE_DRIVER_PATH "/dev/pci_capture_chr_dev-0"
#define WR_VALUE _IOW('a','a',int32_t *)
#define RD_VALUE _IOR('b','b',int32_t *)
#define READ_VALUE_FROM_PCI_DEVICE _IOR('c', 'c', int32_t *)
#define LOAD_PICTURE _IOR('d', 'd', int32_t *)
#define READ_IMAGE_BUFFER _IOW('e', 'e', int32_t *)
#define SET_CURRENT_CHUNK _IOW('f', 'f', int32_t *)
#define SET_FILTERS _IOW('g', 'g', int32_t *)

int main(){
    int fd;
    int32_t buffer_index, image;
    const char *chr_dev_name = CHARACTER_DEVICE_DRIVER_PATH;

    fd = open(chr_dev_name, O_RDWR);
    if (fd < 0) {
        printf("No se pudo abrir el dispositivo\n");
        return 0;
    }

    uint8_t filtros = 0;
    int32_t input;
    printf("Desea aplicar el filtro negativo(0=no): ");
    scanf("%d",&input);
    if(input){
      filtros += 0x1;
    }
    printf("Desea aplicar el filtro Blanco y negro(0=no): ");
    scanf("%d",&input);
    if(input){
      filtros += 0x2;
    }
    printf("Desea aplicar el filtro sepia(0=no): ");
    scanf("%d",&input);
    if(input){
      filtros += 0x4;
    }
    printf("Desea aplicar el filtro difuminado(0=no): ");
    scanf("%d",&input);
    if(input){
      filtros += 0x8;
    }
    ioctl(fd, SET_FILTERS, filtros);
    printf("Seleccione la imagen que desea leer(opciones de 1-4): ");
    scanf("%d",&image);
    ioctl(fd, LOAD_PICTURE, image);
    uint8_t* buffer = malloc(125185);

    //ciclo el cual llena el buffer con la imagen que deseamos leer
    for(int i =0;i<488;i++){
        ioctl(fd, SET_CURRENT_CHUNK, i);
        ioctl(fd, READ_IMAGE_BUFFER, buffer+(i*256));
    }

    FILE* pFile;
    pFile = fopen("image.bmp", "wb");
    fwrite(buffer, 1, 125185, pFile);
    fclose(pFile);

    close(fd);
    return 0;



}
