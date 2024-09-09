#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

#include <math.h>

static gboolean OnDrawEvent(GtkWidget *widget, cairo_t *cr, gpointer user_data);
static void DoDrawing(cairo_t *cr, GtkWidget *widget);

int main(int argc, char *argv[]) {
    GtkWidget *window = NULL;
    GtkWidget *darea = NULL;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    darea = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), darea);

    gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);

    g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(OnDrawEvent), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_WIDTH,
                                WINDOW_HEIGHT);
    gtk_window_set_title(GTK_WINDOW(window), "Cairo Gtk3 Window");

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

static gboolean OnDrawEvent(GtkWidget *widget, cairo_t *cr,
                            gpointer user_data) {
    DoDrawing(cr, widget);

    return FALSE;
}

static void DoDrawing(cairo_t *cr, GtkWidget *widget) {
    GtkWidget *win = gtk_widget_get_toplevel(widget);

    int width = 0;
    int height = 0;
    gtk_window_get_size(GTK_WINDOW(win), &width, &height);

    cairo_set_source_rgb(cr, 0.84, 0.92, 1);
    cairo_set_line_width(cr, 2);

    cairo_translate(cr, width / 2, height / 2);
    cairo_arc(cr, 0, 0, 50, 0, 2 * G_PI);
    cairo_stroke_preserve(cr);

    cairo_set_source_rgb(cr, 0.45, 0.76, 1);
    cairo_fill(cr);
}
