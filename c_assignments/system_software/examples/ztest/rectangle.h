#if !defined(__tRectangle__)
#define __tRectangle__
typedef void *tRectangle;
typedef enum {RECT0,RECT5whxyz,RECT2wh} Rect_Init;
tRectangle rect_open();
int rect_init(tRectangle r, Rect_Init ri, ...);
void rect_position(tRectangle r, double *x, double *y, double *z);
void rect_setposition(tRectangle r, double x, double y, double z);
void rect_setcolor(tRectangle r, double red, double green, double blue);
void rect_color(tRectangle r, double *red, double *green, double *blue);
void rect_size(tRectangle r, double *width, double *height);
void rect_finalize(tRectangle r);
void rect_close(tRectangle r);
#endif
