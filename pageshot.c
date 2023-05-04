#include <stdio.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <webkit2/webkit2.h>



void webview_load_changed(WebKitWebView* webview, WebKitLoadEvent event, gpointer data) {
    if (event == WEBKIT_LOAD_FINISHED) {

        GtkWidget* widget = GTK_WIDGET(data);
        GdkWindow* gdk_window = gtk_widget_get_window(widget);
        gint width = 0;
        gint height = 0;
        gdk_window_get_geometry(gdk_window, NULL, NULL, &width, &height);


        GdkPixbuf* screenshot = gdk_pixbuf_get_from_window(gdk_window, 0, 0, width, height);

        
        const char* desktop_dir = g_get_user_special_dir(G_USER_DIRECTORY_DESKTOP);
        char filename[256];
        sprintf(filename, "%s/screenshot.png", desktop_dir);
        gdk_pixbuf_save(screenshot, filename, "png", NULL, NULL);
        g_object_unref(screenshot);


        printf("Screenshot saved to desktop.\n");


        gtk_main_quit();
    }
}

int main(int argc, char* argv[]) {

    g_setenv("GDK_BACKEND", "x11", TRUE);

    
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 1280, 720); 
    WebKitWebView* webview = WEBKIT_WEB_VIEW(webkit_web_view_new());
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(webview));

    
    char url[256];
    printf("Enter the URL (Use https://): ");
    scanf("%s", url);
    webkit_web_view_load_uri(webview, url);

    
    gtk_widget_show_all(window);

    
    g_signal_connect(webview, "load-changed", G_CALLBACK(webview_load_changed), window);

    gtk_main();
    return 0;
}

