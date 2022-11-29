/* Creates a negative image of the input bitmap file */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "qdbmp.h"

int main( int argc, char* argv[] )
{
    BMP*    bmp;
    UCHAR   r, g, b;
    UINT    width, height;
    UINT    x, y;

    if ( argc != 2 )
    {
        fprintf( stderr, "Usage: %s <input file>\n", argv[ 0 ] );
        return 0;
    }
    /* Read an image file */
    bmp = BMP_ReadFile( argv[ 1 ] );
    BMP_CHECK_ERROR( stderr, -1 ); /* If an error has occurred, notify and exit */

    /* Get image's dimensions */
    width = BMP_GetWidth( bmp );
    height = BMP_GetHeight( bmp );

    //random seed
    srand(time(NULL)); 
    r = 0;
            //time
    for (int t = 0; t < 100; t++) 
    {
        //step 1
        if (t >= 0 && t < 10) 
        {
            for ( x = 0 ; x < width ; ++x )
            {
                /* Iterate through all the image's pixels */
                for ( y = 0 ; y < height ; ++y )
                {
                    r = rand() % 2147483647;
                    if (r == 0) 
                    {
                        /* Change RGB values */
                        BMP_SetPixelRGB( bmp, x, y, 255, 255, 255 );
                    }
                }
            }
        }
        //step 2
        if (t >= 10 && t < 30)
        {
            for ( x = 0 ; x < width ; ++x )
            {
                /* Iterate through all the image's pixels */
                for ( y = 0 ; y < height ; ++y )
                {
                    r = rand() % 2147483647;
                    if (r == 0) 
                    {
                        r = rand() % 2147483647;
                        if (r == 0) 
                        {
                    
                            /* Change RGB values */
                            BMP_SetPixelRGB( bmp, x, y, 0, 0, 0 );
                            BMP_SetPixelRGB( bmp, x+1, y, 0, 0, 0 );
                            BMP_SetPixelRGB( bmp, x+1, y-1, 0, 0, 0 );
                            BMP_SetPixelRGB( bmp, x, y+1, 0, 0, 0 );
                            BMP_SetPixelRGB( bmp, x-1, y-1, 0, 0, 0 );
                            BMP_SetPixelRGB( bmp, x-1, y, 0, 0, 0 );
                            BMP_SetPixelRGB( bmp, x-1, y+1, 0, 0, 0 );
                            BMP_SetPixelRGB( bmp, x, y+1, 0, 0, 0 );
                            BMP_SetPixelRGB( bmp, x+1, y+1, 0, 0, 0 );
                        }
                    }
                }
            }
        }
        //step3
        if (t >= 30 && t < 60)
        {
            for ( x = 0 ; x < width ; ++x )
            {
                /* Iterate through all the image's pixels */
                for ( y = 0 ; y < height ; ++y )
                {
                    r = rand() % 2;
                    if (r == 0) 
                    {   
                        /* Get pixel's RGB values */
                        BMP_GetPixelRGB( bmp, x, y, &r, &g, &b );
                        //if get pixel black or gray
                        if ((r == 0 && g == 0 && b == 0)||(r == 192 && g == 192 && b == 192))
                        {
                            //if r == 0 then add black else gray
                            r = rand() % 2;
                            if (r == 0) 
                            {  
                                    //if r == 0 then grow to + else to -
                                    r = rand() % 2;
                                    if (r == 0) 
                                    {
                                        BMP_SetPixelRGB( bmp, x+1, y, 0, 0, 0 );
                                        BMP_SetPixelRGB( bmp, x, y+1, 0, 0, 0 );
                                    }
                                    if (r == 1) 
                                    {
                                        BMP_SetPixelRGB( bmp, x-1, y, 0, 0, 0 );
                                        BMP_SetPixelRGB( bmp, x, y-1, 0, 0, 0 );
                                    }
                                
                            }
                            if (r == 1) 
                            {  
                                //if r == 0 then grow to + else to -
                                r = rand() % 2;
                                if (r == 0) 
                                {
                                    BMP_SetPixelRGB( bmp, x+1, y, 192, 192, 192 );
                                    BMP_SetPixelRGB( bmp, x, y+1, 192, 192, 192 );
                                }
                                if (r == 1) 
                                {
                                    BMP_SetPixelRGB( bmp, x-1, y, 192, 192, 192 );
                                    BMP_SetPixelRGB( bmp, x, y-1, 192, 192, 192 );
                                }
                            }                      
                        }
                        //and grow white pixels
                        if (r == 255 && g == 255 && b == 255) 
                        {
                            r = rand() % 2;
                            if (r == 0)
                            {
                                //if r == 0 then grow to + else to -
                                r = rand() % 2;
                                if (r == 0) 
                                {
                                    BMP_SetPixelRGB( bmp, x+1, y, 255, 255, 255 );
                                    BMP_SetPixelRGB( bmp, x, y+1, 255, 255, 255 );
                                }
                                if (r == 1) 
                                {
                                    BMP_SetPixelRGB( bmp, x-1, y, 255, 255, 255 );
                                    BMP_SetPixelRGB( bmp, x, y-1, 255, 255, 255 );
                                }
                            }
                        }
                    }
                }
            }
        }
        //step4
        if (t >= 60 && t < 100)
        {
            for ( x = 0 ; x < width ; ++x )
            {
                /* Iterate through all the image's pixels */
                for ( y = 0 ; y < height ; ++y )
                {
                    r = rand() % 100;
                    if (r == 0) 
                    {   
                        //if r == 0 then grow to + else to -
                        r = rand() % 2;
                        if (r == 0) 
                        {
                            BMP_SetPixelRGB( bmp, x+1, y, 107, 142, 35 );
                            BMP_SetPixelRGB( bmp, x, y+1, 107, 142, 35 );
                        }
                        if (r == 1) 
                        {
                            BMP_SetPixelRGB( bmp, x-1, y, 107, 142, 35 );
                            BMP_SetPixelRGB( bmp, x, y-1, 107, 142, 35 );
                        }
                    }
                }
            }
        }
                  
        /* Save result */
        char name[20] = "./output/output";
        char num[4];       //+100 because fix for animation
        sprintf(num, "%d", t+100);
        strcat(name,num);
        strcat(name,".bmp");
        BMP_WriteFile( bmp, name );
        BMP_CHECK_ERROR( stderr, -2 );
    }

   
    /* Free all memory allocated for the image */
    BMP_Free( bmp );

    return 0;
}