#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int width, height, max_val;
    int new_width, new_height;

    FILE *fo;
    fo = fopen(argv[1], "rb");
    // Read the header
    fscanf(fo, "P2\n%d %d\n%d\n", &width, &height, &max_val);

    // Calculate the new width and height
    if (argc > 2)
    {
        new_width = atoi(argv[2]);
    }
    else
    {
        new_width = width / 2;
    }
    // Height is proportional to width
    new_height = height * new_width / width;

    // Read the image
    int image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fscanf(fo, "%d", &image[i][j]);
        }
    }
    fclose(fo);

    // Write the header to image
    FILE *fp = fopen(strcat(strtok(argv[1], "."), "-resize.pgm"), "wb");

    fprintf(fp, "P2\n%d %d\n%d\n", new_width, new_height, max_val);

    // Write the image
    for (int i = 0; i < new_height; i++)
    {
        for (int j = 0; j < new_width; j++)
        {
            // Calculate the new pixel value
            int new_pixel = 0;
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    new_pixel += (image[i * 2 + k][j * 2 + l]) / 4;
                }
            }
            if (new_pixel > max_val || new_pixel < 0)
            {
                new_pixel = 0;
            }
            fprintf(fp, "%d ", new_pixel);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}
