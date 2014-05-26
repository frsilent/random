#include "rectangle.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

//typedef void *tRectangle;
//typedef enum {RECT0,RECT5whxyz,RECT2wh} Rect_Init;
typedef struct {
  double red, green, blue;
  double x, y, z;
  double width, height;
} RealRectangle;
typedef RealRectangle *pRectangle;

tRectangle rect_open() {
  pRectangle p;
  p = (pRectangle)malloc(sizeof(RealRectangle));
  return (tRectangle)p;
}
int rect_init(tRectangle r, Rect_Init ri, ...) {
  va_list argp;
  pRectangle pr;
  va_start(argp, ri);
  switch (ri) {
  case RECT0:
    memset(r, 0, sizeof(RealRectangle));
    break;
  case RECT2wh:
    memset(r, 0, sizeof(RealRectangle));
    pr = (pRectangle)r;
    pr->width = va_arg(argp, double);
    pr->height = va_arg(argp, double);
    break;
  case RECT5whxyz:
    memset(r, 0, sizeof(RealRectangle));
    pr = (pRectangle)r;
    pr->width = va_arg(argp, double);
    pr->height = va_arg(argp, double);
    pr->x = va_arg(argp, double);
    pr->y = va_arg(argp, double);
    pr->z = va_arg(argp, double);
    break;
  default: assert(0);
  }
  va_end(argp);
  return 1;
}
void rect_position(tRectangle r, double *x, double *y, double *z) {
  pRectangle pr;
  pr = (pRectangle)r;
  *x = pr->x;
  *y = pr->y;
  *z = pr->z;
}
void rect_setposition(tRectangle r, double x, double y, double z) {
  pRectangle pr;
  pr = (pRectangle)r;
  pr->x = x;
  pr->y = y;
  pr->z = z;
}
void rect_setcolor(tRectangle r, double red, double green, double blue) {
  pRectangle pr;
  pr = (pRectangle)r;
  pr->red = red;
  pr->green = green;
  pr->blue = blue;
}
void rect_color(tRectangle r, double *red, double *green, double *blue) {
  pRectangle pr;
  pr = (pRectangle)r;
  *red = pr->red;
  *green = pr->green;
  *blue = pr->blue;
}
void rect_size(tRectangle r, double *width, double *height) {
  pRectangle pr;
  pr = (pRectangle)r;
  *width = pr->width;
  *height = pr->height;
}
void rect_finalize(tRectangle r) {
}
void rect_close(tRectangle r) {
  assert(r!=NULL);
  free(r);
}
#if 0
int main(void) {
  tRectangle r;
  r = rect_open();
  rect_init(r, RECT0);
  rect_init(r, RECT2wh, 1.0, 2.0);
  rect_init(r, RECT5whxyz, 1.0, 2.0, 3.0, 4.0, 5.0);
  rect_finalize(r);
  rect_close(r);
  return 0;
}
#endif
