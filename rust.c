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
                            BMP_SetPixelRGB( bmp, x, y, 210, 105, 30 );
                        }
                    
                }
            }
        }
        //step2
        if (t >= 10 && t < 40)
        {
            for ( x = 0 ; x < width ; ++x )
            {
                /* Iterate through all the image's pixels */
                for ( y = 0 ; y < height ; ++y )
                {
                    r = rand() % 2;
                    if (r == 0) 
                    {   
                        r = rand() % 2;
                        if (r == 0) 
                        {      
                            /* Get pixel's RGB values */
                            BMP_GetPixelRGB( bmp, x, y, &r, &g, &b );
                            //if get pixel brown
                            if (r == 210 && g == 105 && b == 30)
                            {
                                //if r == 0 then grow y
                                r = rand() % 2;
                                if (r == 0) 
                                {
                                    BMP_SetPixelRGB( bmp, x, y+1, 210, 105, 30 );
                                    BMP_SetPixelRGB( bmp, x, y-1, 210, 105, 30 );
                                }
                                //if r == 0 then grow y
                                r = rand() % 4;
                                if (r == 0) 
                                {
                                    BMP_SetPixelRGB( bmp, x+1, y, 210, 105, 30 );
                                    BMP_SetPixelRGB( bmp, x-1, y, 210, 105, 30 );
                                }                        
                            }
                        }
                    }
                }
            }
        }
        //step3
        if (t >= 40 && t < 100)
        {
            for ( x = 0 ; x < width ; ++x )
            {
                /* Iterate through all the image's pixels */
                for ( y = 0 ; y < height ; ++y )
                {
                    r = rand() % 2;
                    if (r == 0) 
                    {   
                        r = rand() % 2;
                        if (r == 0) 
                        {      
                            /* Get pixel's RGB values */
                            BMP_GetPixelRGB( bmp, x, y, &r, &g, &b );
                            //if get pixel not brown
                            if (!(r == 210 && g == 105 && b == 30))
                            {
                                //if r == 0 then grow y
                                r = rand() % 4;
                                if (r == 0) 
                                {
                                    BMP_SetPixelRGB( bmp, x, y+1, 139, 69, 19 );
                                    BMP_SetPixelRGB( bmp, x, y-1, 139, 69, 19 );
                                }
                                //if r == 0 then grow y
                                r = rand() % 2;
                                if (r == 0) 
                                {
                                    BMP_SetPixelRGB( bmp, x+1, y, 139, 69, 19 );
                                    BMP_SetPixelRGB( bmp, x-1, y, 139, 69, 19 );
                                }                        
                            }
                            else 
                            {
                                //if r == 0 then grow y
                                r = rand() % 5;
                                if (r == 0) 
                                {
                                    BMP_SetPixelRGB( bmp, x, y+1, 210, 105, 30 );
                                    BMP_SetPixelRGB( bmp, x, y-1, 210, 105, 30 );
                                    BMP_SetPixelRGB( bmp, x+1, y, 210, 105, 30 );
                                    BMP_SetPixelRGB( bmp, x-1, y, 210, 105, 30 );
                                }
                            }
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