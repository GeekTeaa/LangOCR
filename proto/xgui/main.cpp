#include <iostream>
#include <unistd.h>
#include <cstring>
#include <X11/Xlib.h>
#include <X11/X.h>
#include <X11/Xcms.h>
#include <X11/Xutil.h>

using namespace std;

int x = 100;
int y = 100;
unsigned int width = 1000;
unsigned int height = 400;
unsigned int border_width = 2;
unsigned long int border = 0xFFFFFFLL; // Black
unsigned long int background = 0xFF0000LL; // Some color

int main(int argc, char* argv[])
{
    // Draw a rectangle with Xlib
    // First, open the display
    Display* disp = XOpenDisplay(NULL);
    if (disp == NULL)
    {
        printf("Failed to open Display with XOpenDisplay\n");
        exit(1);
    }
    int screen = DefaultScreen(disp);
    int depth = DefaultDepth(disp,screen);
    printf("Screen: %d, depth: %d\n", screen, depth);
    
    Window root = RootWindow(disp, screen);

    XRectangle rect;
    rect.x = 1000;
    rect.y = 1000;
    rect.width  = 1000;
    rect.height = 1000;

    XVisualInfo vinfo;
    XMatchVisualInfo(disp, DefaultScreen(disp), 32, TrueColor, &vinfo);
    
    XSetWindowAttributes attr;
    attr.colormap = XCreateColormap(disp,
                                    DefaultRootWindow(disp),
                                    vinfo.visual, AllocNone);
    attr.border_pixel = 2;
    attr.background_pixel = 0;
    // Window window = XCreateSimpleWindow(
    //     disp,
    //     root,
    //     x,
    //     y,
    //     width,
    //     height,
    //     border_width,
    //     border,
    //     background);

    // XSetForeground(disp, gc, 0xFF0000);  // Tell the GC we draw using the RED color
    // XFillRectangle(disp, window, gc, rect.x, rect.y, rect.width, rect.height);
    //int screenNum = XDefaultScreen(disp);
    // printf("Display width: %d\nDisplay Height: %d\n",
    //        XDisplayWidth(disp, screenNum),
    //        XDisplayHeight(disp, screenNum));

    
    Window window = XCreateWindow(disp,
                                  DefaultRootWindow(disp),
                                  x,
                                  y,
                                  29, // 1440, 
                                  29, // 900,
                                  0,
                                  vinfo.depth,
                                  InputOutput,
                                  vinfo.visual,
                                  CWColormap | CWBorderPixel | CWBackPixel,
                                  &attr);
    
    XMapWindow(disp, window);    // Map canvas window to display
    GC gc = XCreateGC(disp, window, 0, NULL);

    XSetForeground(disp, gc, 0xFF0000);  // Tell the GC we draw using the RED color
    XDrawRectangle(disp, window, gc, 100, 100, 500, 500);      // Draw the rectangle
    // 
    //  Lets try XFillRectangle(display, d, gc, x, y, width, height)
    XSetForeground(disp, gc, 0x00FF00);  // Tell the GC we draw using the BLUE color
    XFillRectangle(disp, window, gc, 15, 15, 40, 40);      // Draw the filled rectangle
    XSetBackground(disp, gc, 0L);

    XFlush(disp);
    XSync(disp, False);

    sleep(20);
    // Create a graphics context
    // XGCValues myGCVals; 

    // Capture box info
    // XWindowAttributes cwa;
    // XGetWindowAttributes(disp, window, &cwa);
    // printf("Width %d, Heigth %d\n", cwa.width, cwa.height);
    // XImage *image = XGetImage(disp, window, 0, 0, cwa.width, cwa.height, AllPlanes, ZPixmap);
    
    // XColor xcolour;
    // // I guess XParseColor will work here
    // xcolour.red = 32000; xcolour.green = 65000; xcolour.blue = 32000;
    // xcolour.flags = DoRed | DoGreen | DoBlue;
    // XAllocColor(d, cmap, &xcolour);
    // 
    // XSetForeground(d, gc, xcolour.pixel);
    // XFillRectangle(d, w, gc, 0, 0, winatt.width, 30);
    // XFlush(d);
    
    // uint16_t cnt = 0; 
    // while(1)
    // {
    //     cnt++;
    //     if (cnt == 20) break;
    // 
    //     if (cnt % 2 == 0)
    //     {
    //         width -= 10;
    //         height += 10;
    //         XSetBackground(disp, gc, 0x00FF00LL);
    //     }
    // 
    //     if (cnt % 2 == 1)
    //     {
    //         width += 10;
    //         height -= 10;
    //         XSetBackground(disp, gc, 0xFF0000LL);
    //     }
    //     
    //     sleep(1);
    //     XResizeWindow(disp, window, width, height);
    //     XFlushGC(disp, gc);
    //     XFlush(disp);
    // }
    
   
    //XDrawRectangle(disp, InputOnly, gc, 1000, 1000, 100, 100 );
    
    printf("End of script\n");
    exit(EXIT_SUCCESS);
}
