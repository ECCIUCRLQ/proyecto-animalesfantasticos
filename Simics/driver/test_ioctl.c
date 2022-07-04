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

int main()
{
    int fd;
    int32_t buffer_index, image;
    const char *chr_dev_name = CHARACTER_DEVICE_DRIVER_PATH;

    printf("*********************************\n");
    printf(">>> Opening character device\n");
    fd = open(chr_dev_name, O_RDWR);
    if (fd < 0) {
        printf("Cannot open character device file...\n");
        return 0;
    }
    printf("Enter the image to read: ");
    scanf("%d",&image);
    ioctl(fd, LOAD_PICTURE, image);

    printf("Enter the buffer to read: ");
    scanf("%d",&buffer_index);

    ioctl(fd, SET_CURRENT_CHUNK, buffer_index);
    uint8_t* buffer = malloc(256);
    ioctl(fd, READ_IMAGE_BUFFER, buffer);

    printf("Printing buffer\n");
    for (size_t i = 0; i < 256; i++) {
      printf("0x%1x\t", (unsigned)buffer[i] );
    }
    printf("\n");


    printf("Closing character device file\n");
    close(fd);
}
