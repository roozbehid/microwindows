#include "nxlib.h"
#include <string.h>
#include "X11/Xutil.h"
#include "X11/Xatom.h"

int XSetTransientForHint(Display* display, Window w, Window prop_window) {
	XChangeProperty(display, w, XA_WM_TRANSIENT_FOR, XA_WINDOW, 32,
		PropModeReplace, (unsigned char *)&prop_window, 1);
	return 1;
}

void
XSetWMName(Display * display, Window w, XTextProperty * name)
{
	XChangeProperty(display, w, XA_WM_NAME, XA_STRING, 8,
		PropModeReplace, (unsigned char *)name->value, name->nitems);
}

/* Not used */
void
XSetWMIconName(Display * display, Window w, XTextProperty * name)
{
#if DEBUG || SHOWSTUBS
	DPRINTF("XSetWMIconName\n");
#endif 
}

/* Not used */
void
XSetWMNormalHints(Display * display, Window w, XSizeHints * hints)
{
#if DEBUG || SHOWSTUBS
	DPRINTF("XSetWMNormalHints\n");
#endif   
}

/* Not used */
int
XSetWMHints(Display * display, Window w, XWMHints * hints)
{
#if DEBUG || SHOWSTUBS
	DPRINTF("XSetWMHints\n");
#endif   
	return 1;
}

/* Not used */
void
XSetWMClassHints(Display * display, Window w, XClassHint * hints)
{
#if DEBUG || SHOWSTUBS
	DPRINTF("XSetWMClassHints\n");
#endif     
}

XSizeHints *
XAllocSizeHints(void)
{
	return (XSizeHints *)Xcalloc(1, (unsigned)sizeof(XSizeHints));
}

XWMHints *
XAllocWMHints(void)
{
	return (XWMHints *)Xcalloc(1, (unsigned)sizeof(XWMHints));
}

void
XSetWMProperties(Display * display, Window w, XTextProperty * window_name,
	XTextProperty * icon_name, char **argv, int argc,
	XSizeHints * normal_hints, XWMHints * wm_hints, XClassHint *class_hints)
{
	if (window_name)
		XSetWMName(display, w, window_name);
	if (icon_name)
		XSetWMIconName(display, w, icon_name);
	if (normal_hints)
		XSetWMNormalHints(display, w, normal_hints);
	if (wm_hints)
		XSetWMHints(display, w, wm_hints);
	if (class_hints)
		XSetWMClassHints(display, w, class_hints);
}

void
XmbSetWMProperties(Display *dpy, Window w, _Xconst char *windowName,
	_Xconst char *iconName, char **argv, int argc, XSizeHints * sizeHints,
	XWMHints * wmHints, XClassHint * classHints)
{
	XTextProperty wname, iname;
	XTextProperty *wprop = NULL;
	XTextProperty *iprop = NULL;

	/* fake up XTextProperty struct members for XSetWMName*/
	if (windowName) {
		wname.value = (unsigned char *)windowName;
		wprop = &wname;
	}
	if (iconName) {
		iname.value = (unsigned char *)iconName;
		iprop = &iname;
	}
	XSetWMProperties(dpy, w, wprop, iprop, argv, argc, sizeHints, wmHints,
		classHints);
}

void
Xutf8SetWMProperties(Display *dpy, Window w, _Xconst char *windowName,
	_Xconst char *iconName, char **argv, int argc, XSizeHints * sizeHints,
	XWMHints * wmHints, XClassHint * classHints)
{
	XmbSetWMProperties(dpy, w, windowName, iconName, argv, argc,
		sizeHints, wmHints, classHints);
}
