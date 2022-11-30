if [ $2 == 0 ]
then
    ./mold.out $1
fi
if [ $2 == 1 ]
then
    ./rust.out $1
fi
cd output
convert -delay 50 -loop 0 *.bmp animation.gif
rm *.bmp
