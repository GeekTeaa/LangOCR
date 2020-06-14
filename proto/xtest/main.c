#include <X11/Xlib.h> // Every Xlib program must include this
#include <assert.h>   // I include this to test return values the lazy way
#include <unistd.h>   // So we got the profile for 10 seconds
#include <stdio.h>           // This has the keyboard and file IO functions
#define NIL (0)       // A name for the void pointer
int main()
{
  char keyboard_input[100];
  GC gc;   //This will be the "graphics context"  It remembers the colors and window and various details.
  XColor black_col,white_col,red_col,green_col,blue_col,yellow_col;
  Colormap colormap;
  char black_bits[] = "#000000";
  char white_bits[] = "#FFFFFF";
  char red_bits[] = "#FF0000";
  char green_bits[] = "#00FF00";
  char blue_bits[] = "#0000FF";
  char yellow_bits[] = "#FFFF00";
  Display *dpy = XOpenDisplay(NIL); assert(dpy);   // Open the display
  // Get the only two predefined colors in xwindows:  Black and White
  int blackColor = BlackPixel(dpy, DefaultScreen(dpy));
  //int whiteColor = WhitePixel(dpy, DefaultScreen(dpy));
  // Define the colors we want to use
  colormap = DefaultColormap(dpy, 0);
  XParseColor(dpy, colormap, black_bits, &black_col); XAllocColor(dpy, colormap, &black_col);
  XParseColor(dpy, colormap, white_bits, &white_col); XAllocColor(dpy, colormap, &white_col);
  XParseColor(dpy, colormap, red_bits, &red_col); XAllocColor(dpy, colormap, &red_col);
  XParseColor(dpy, colormap, green_bits, &green_col);XAllocColor(dpy, colormap, &green_col);
  XParseColor(dpy, colormap, blue_bits, &blue_col);XAllocColor(dpy, colormap, &blue_col);
  XParseColor(dpy, colormap, yellow_bits, &yellow_col);XAllocColor(dpy, colormap, &yellow_col);
  // Create the window  The numbers are the x and y locations on the screen, the width and height, 
  // border width (which is usually zero)
  Window w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0, 200, 100, 0, blackColor, blackColor);
  XSelectInput(dpy, w, StructureNotifyMask);        // We want to get MapNotify events
  XMapWindow(dpy, w);         // "Map" the window (that is, make it appear on the screen)
  for(;;){XEvent e; XNextEvent(dpy,&e); if(e.type == MapNotify) break;} //Wait for the MapNotify event
  // which means that the window has appeared on the screen.
  gc = XCreateGC(dpy, w, 0, NIL);        // Create a "Graphics Context"
  
  //  We are finally ready to do some drawing!  Whew!

  //  Lets try XDrawLine(display, d, gc, x1, y1, x2, y2)
  XSetForeground(dpy, gc, red_col.pixel);  // Tell the GC we draw using the RED color
  XDrawLine(dpy, w, gc, 10, 70, 180, 30);      // Draw theline
  XSetForeground(dpy, gc, green_col.pixel);  // Tell the GC we draw using the GREEN color
  XDrawLine(dpy, w, gc, 10, 80, 180, 40);      // Draw the line
  XSetForeground(dpy, gc, blue_col.pixel);  // Tell the GC we draw using the BLUE color
  XDrawLine(dpy, w, gc, 10, 90, 180, 50);      // Draw the line
  //XSetForeground(dpy, gc, whiteColor);  // Tell the GC we draw using the WHITE color (Method 1)
  XSetForeground(dpy, gc, white_col.pixel);  // Tell the GC we draw using the WHITE color (Method 2)
  XDrawLine(dpy, w, gc, 10, 60, 180, 20);      // Draw the line

  //  Lets try XDrawArc(display, d, gc, x, y, width, height, angle1, angle2)
  //  The angle are in weird units of 1/64th of a degree.  angle1 is the start angle. (Zero is to the right.) 
  //  angle2 is how much of an arc to make.
  XSetForeground(dpy, gc, green_col.pixel);  // Tell the GC we draw using the GREEN color
  XDrawArc(dpy, w, gc, 150, 50, 40, 40, 90*64, 180*64);      // Draw the arc
  XSetForeground(dpy, gc, red_col.pixel);  // Tell the GC we draw using the RED color
  XDrawArc(dpy, w, gc, 155, 55, 30, 30, 180*64, 180*64);      // Draw the arc

  //  Lets try XDrawRectangle(display, d, gc, x, y, width, height)
  //XSetForeground(dpy, gc, red_col.pixel);  // Tell the GC we draw using the RED color
  //XDrawRectangle(dpy, w, gc, 10, 10, 50, 50);      // Draw the rectangle
  //
  ////  Lets try XFillRectangle(display, d, gc, x, y, width, height)
  //XSetForeground(dpy, gc, blue_col.pixel);  // Tell the GC we draw using the BLUE color
  //XFillRectangle(dpy, w, gc, 15, 15, 40, 40);      // Draw the filled rectangle

  //  Lets try XFillArc(display, d, gc,  x, y, width, height, angle1, angle2)
  //  The angle are in weird units of 1/64th of a degree.  angle1 is the start angle. (Zero is to the right.) 
  //  angle2 is how much of an arc to make.
  XSetForeground(dpy, gc, black_col.pixel);  // Tell the GC we draw using the BLACK color
  XFillArc(dpy, w, gc, 20, 20, 30, 30, 10*64, 330*64);      // Draw the filled arc
  XSetForeground(dpy, gc, yellow_col.pixel);  // Tell the GC we draw using the YELLOW color
  XFillArc(dpy, w, gc, 37, 23, 6, 6, 0*64, 360*64);      // Draw the filled circle

  XFlush(dpy); // Tell the graphics server that it should really show us the results now.
  sleep(1);  // Wait for 1 second
  printf("Press enter when done.\n");
  fgets (keyboard_input,100,stdin); 
  return(0);
}
