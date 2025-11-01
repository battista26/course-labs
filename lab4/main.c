#include <stdio.h>
#include <stdlib.h>

#include "lab4bmp.h"

/**
 * opens an image file with the name fname,
 * allocates memory for it, and assigns members of  Image in this memory,
 * and returns that Image.
 * If file not found returns NULL
 */
Image *imread(char *fname) {
    FILE *f = fopen(fname, "rb");
    Image *im;
    if (f == NULL) {
        perror("the file not found!");
        return NULL;
    }
    /*TODO: ders notlarinda verilen offset vb kullanarak
    fden gerekli bilgileri okuyun,
    im icin once memory ayirin, sonra meberlarini baslatiniz
    */
    /*TODO !!!im datanin ilki son pixel oluyor!! slidelardaki ornege bakiniz*/
    return im;
}

/** frees memory for the image and close the file */
int imclose(Image *im) {
    free(im);
    return 0;
}

/** hides character c in pixel p, returns modified pixel
 * for p, and character c
 * initial(left most) 2  bit in p.b
 * following 2 bit in p.g
 * following 2 bit in p.r
 * following 2 bit in p.a
 */
int hideinpixel(Pixel *p, unsigned char c) {
    /*TODO: verilen pixelin ABGR degerlerine,
    charin bastarafindan (sol en onemli bit, left most significant bit)
    baslayarak, ilk 2 biti b'nin sonuna,
    sonraki 2yi g,
    sonraki 2yi r,
    sonraki 2yi anin sonuna saklayiniz.
    bit shift ve maskeleme kullanabilirsiniz
    */
    return 0;
}

/**
 * hides given msg in im->data pixels by using above hideinpixel()
 */
int hidemsg(Image *im, unsigned char *msg) {
    /*TODO: create a loop from i to width*height and
     hide chars by using above
    helper function hideinpixel*/
    /*TODO: i den width*heighta kadar loop olusturarak,
    karakterleri tek tek pixellerin icerisine saklayiniz,
    bunun icin hideinpixel() fonksiyonunu kullaniniz*/
    return 0;
}

/**
 * read hidden char in pixel, and returns it:
 * initial(left most) 2  bit in p.b for 00000011->initial bits 00
 * following 2 bit in p.g
 * following 2 bit in p.r
 * following 2 bit in p.a
 */
char readcharinpixel(Pixel *p) {
    /*TODO: hideinpixel() yapilanin tersini yaparak karakteri bulunuz.
    bit shift ve maskeleme kullanabilirsiniz
    karakteri return edin
    */
    char c = 0;
    return c;
}

/**
 * reads hidden chars in im into msg[] by using readcharinpixel(),
 * returns its length
 */
int readmsg(Image *im, unsigned char msg[], int maxlength) {
    /*TODO:  im->pixels icersinde sakli mesaji
    readcharinpixel() fonksiyonu yardimiyla
    okuyarak msg ile verilen adrese kopyalayin. */
    return maxlength;
}

/**
 * prints pixels
 */
int printpixel(Pixel *p) {
    printf("r:%d-g:%d-b:%d-a:%d", p->r, p->g, p->b, p->a);
    return 0;
}

int main(void) {
    char *msg = "hello";
    char fname[] = "cute-animals32bit.bmp";
    Image *im = imread(fname);
    hidemsg(im, msg);
    readmsg(im, msg, 6);
    printf("%.6s", msg);
    return 0;
}
