CC=g++
SRC=main.cpp helloworld.cpp


CFLAGS=-I. -I/usr/include/gtkmm-3.0 -I/usr/include/glibmm-2.4/ -I/usr/lib/glibmm-2.4/include/ -I/usr/include/sigc++-2.0/ -I/usr/lib/sigc++-2.0/include/ -I/usr/lib/gtkmm-2.4/include/ -I/usr/lib/gdkmm-2.4/include/ -I/usr/lib/pangomm-1.4/include/ -I/usr/include/pangomm-1.4/ -I/usr/include/cairomm-1.0/ -I/usr/include/freetype2/ -I/usr/include/atkmm-1.6/ -I/usr/include/gdkmm-2.4/ -I/usr/include/giomm-2.4/ -I/usr/lib/giomm-2.4/include/ -I/usr/include/gtk-2.0 -I/usr/lib/gtk-2.0/include -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/harfbuzz/ -I/usr/include/gdk-pixbuf-2.0/ # -I/usr/include/gtk-2.0/
LIB= -lgtk-x11-3.0 -lgtkmm-3.0

make:
	$(CC) -o gtkgui $(CFLAGS) $(SRC) $(LIB)
	./gtkgui
