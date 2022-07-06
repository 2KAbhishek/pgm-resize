#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Read a pgm image from stdin and write a resized p5 pgm image to stdout
    int width, height, max_val;
    int i, j, k, l;
    int new_width, new_height;

    // Read the header
    scanf("P2\n%d %d\n%d\n", &width, &height, &max_val);

    // Calculate the new width and height
    new_width = 300;
    // Height is proportional to width
    new_height = height * new_width / width;

    // Read the image
    int image[height][width];
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }

    // Write the header to image.pgm
    FILE *fp = fopen("./resize.pgm", "wb");
    fprintf(fp, "P2\n%d %d\n%d\n", new_width, new_height, max_val);

    // Write the image
    for (i = 0; i < new_height; i++)
    {
        for (j = 0; j < new_width; j++)
        {
            // Calculate the new pixel value
            int new_pixel = 0;
            for (k = 0; k < 2; k++)
            {
                for (l = 0; l < 2; l++)
                {
                    new_pixel += image[i * 2 + k][j * 2 + l];
                }
            }
            new_pixel /= 4;
            fprintf(fp, "%d ", new_pixel);
        }
        fprintf(fp, "\n");
    }
}
