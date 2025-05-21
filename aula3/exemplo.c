/*

   gcc x11.c  -lX11


https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h

https://tronche.com/gui/x/xlib/events/keyboard-pointer/keyboard-pointer.html#XKeyEvent

*/

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------------------------
Display *Gdisplay;
int Gscreen;
Window Gwin;
GC Ggc;
Pixmap *Gpix;
unsigned int Gwidth, Gheight;

Drawable d;
char *string;
int length;

int rect_x = 100, rect_y = 100; // posição inicial do retângulo
int rect_w = 20, rect_h = 20;

int x, y;

//-------------------------------------------------------------
void init_x()
{

   Gdisplay = XOpenDisplay((char *)0);
   Gscreen = DefaultScreen(Gdisplay);
   Gwin = XCreateSimpleWindow(Gdisplay, DefaultRootWindow(Gdisplay), 0, 0,
                              300, 300, 5, 0, 0x87CEEB);

   XSetStandardProperties(Gdisplay, Gwin, "TELA_LINUX", "xd", None, NULL, 0, NULL);

   XSelectInput(Gdisplay, Gwin, ExposureMask | KeyPressMask | KeyRelease | ButtonPressMask | ButtonReleaseMask); // add | KeyRelease| ButtonPressMask  | ButtonReleaseMask

   Ggc = XCreateGC(Gdisplay, Gwin, 0, 0);

   XSetBackground(Gdisplay, Ggc, WhitePixel(Gdisplay, Gscreen));
   XSetForeground(Gdisplay, Ggc, BlackPixel(Gdisplay, Gscreen));

   XClearWindow(Gdisplay, Gwin);
   XMapRaised(Gdisplay, Gwin);
};

//-------------------------------------------------------------
void redraw()
{
   XClearWindow(Gdisplay, Gwin);
};

//-------------------------------------------------------------
void close_x()
{
   XFreeGC(Gdisplay, Ggc);
   XCloseDisplay(Gdisplay);
   XDestroyWindow(Gdisplay, Gwin);
};

//-------------------------------------------------------------
int main()
{

   int xr, yr;
   XEvent event;
   KeySym key;
   char text[255];

   init_x();
   char stringg[] = "asdsdgrgsergsvergx";
   printf("\npress 'q' to break\n");
   while (1)
   {

      XNextEvent(Gdisplay, &event);

      printf("Evento %d   ", event.type);
      /*
      if (event.type == ButtonPress)
      {
         int x = event.xbutton.x;
         int y = event.xbutton.y;
         XDrawString(Gdisplay, Gwin, Ggc, x, y, stringg, 9);
         printf("Clique do mouse em: x = %d, y = %d\n", x, y);
      }
      */

      if (event.type == ButtonPress)
      {
         x = event.xbutton.x;
         y = event.xbutton.y;
         XDrawRectangle(Gdisplay, Gwin, Ggc, x, y, 5, 5);
         printf("Clique do mouse em: x = %d, y = %d\n", x, y);
      }

      if (event.type == KeyRelease)
      {
         printf("key release(soltura de teclas)\n");
      }

      if (event.type == ButtonRelease)
      {
         printf("button release(soltura de botao)\n");
      }
      /*
      if (event.type == KeyPress)
      {

         printf(" tecla = (%d) ", (int)event.xkey.keycode);

         XLookupString(&event.xkey, text, 255, &key, 0);

         if (text[0] == 'q')
            break;

         printf("caracter = %d \n", (int)text[0]);
      }
      */
      if (event.type == KeyPress)
      {
         printf(" tecla = (%d) ", (int)event.xkey.keycode);

         XLookupString(&event.xkey, text, 255, &key, 0);

         if (text[0] == 'q')
            break;

         // Mover o retângulo com as setas
         switch (key)
         {
         case XK_Left:
            rect_x -= 10;
            break;
         case XK_Right:
            rect_x += 10;
            break;
         case XK_Up:
            rect_y -= 10;
            break;
         case XK_Down:
            rect_y += 10;
            break;
         }

         redraw();                                                            // limpar a tela
         XDrawRectangle(Gdisplay, Gwin, Ggc, rect_x, rect_y, rect_w, rect_h); // redesenha retângulo na nova posição
         // XDrawRectangle(Gdisplay, Gwin, Ggc, x, y, rect_w, rect_h);
         printf("caracter = %d \n", (int)text[0]);
      }
   }

   close_x();

   return 0;
}
