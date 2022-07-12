#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width, height, max_val;
    int i, j, k, l;
    int new_width, new_height;

    // Read the header
    scanf("P2\n%d %d\n%d\n", &width, &height, &max_val);

    // Calculate the new width and height
    new_width = 300;
    // Height is proportional to width
    new_height = height * new_width / width;

    // Use malloc to allocate memory for the source and destination data, each pixel is 1 byte
    unsigned char *src = (unsigned char *)malloc(width * height);
    unsigned char *dst = (unsigned char *)malloc(new_width * new_height);

    // Read the data from stdin
    for (i = 0; i < width * height; i++) {
        scanf("%d", &src[i]);
    }

    // Resize the image by averaging the source pixels to the destination pixels
    for (i = 0; i < new_height; i++) {
        for (j = 0; j < new_width; j++) {
            k = i * new_width + j;
            l = i * width / new_height * width + j * width / new_width;
            dst[k] = (src[l] + src[l + 1] + src[l + width] + src[l + width + 1]) / 4;
        }
    }

    // WWrite the header to file
    FILE *fp = fopen("resize.pgm", "w");
    fprintf(fp, "P2\n%d %d\n%d\n", new_width, new_height, max_val);
    // Write the data to file result.pgm
    for (i = 0; i < new_height * new_width; i++) {
        fprintf(fp, "%d\n", dst[i]);
     }
    fclose(fp);
    // Free the data
    free(src);
    free(dst);
    return 0;
}
