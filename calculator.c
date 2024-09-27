#include <gtk/gtk.h>

static void
print_hello(GtkWidget *widget,
            gpointer data)
{
    g_print("Hello World\n");
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkBuilder *build;
    build = gtk_builder_new_from_file("calculator.ui");
    GtkWidget *win;
    win = GTK_WIDGET(gtk_builder_get_object(build, "win"));
    gtk_window_set_application(GTK_WINDOW(win), GTK_APPLICATION(app));
    gtk_widget_show(GTK_WIDGET(win));
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("c.calculator", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}