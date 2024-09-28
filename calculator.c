#include <gtk/gtk.h>

bool dot_added = false;
bool op_added = false;

static void plus()
{
    printf("HOOOYAAA");
}
static void minus()
{
    printf("HOOOYAAA");
}
static void mult()
{
    printf("HOOOYAAA");
}
static void divi()
{
    printf("HOOOYAAA");
}
static void negate()
{
    printf("HOOOYAAA");
}
static void inverse()
{
    printf("HOOOYAAA");
}
static void sine()
{
    printf("HOOOYAAA");
}
static void cosine()
{
    printf("HOOOYAAA");
}
static void tangent()
{
    printf("HOOOYAAA");
}
static void square()
{
    printf("HOOOYAAA");
}
static void c()
{
    printf("HOOOYAAA");
}
static void ce()
{
    printf("HOOOYAAA");
}
static void equal()
{
    printf("HOOOYAAA");
}
static void zero()
{
    printf("HOOOYAAA");
}
static void one()
{
    printf("HOOOYAAA");
}
static void two()
{
    printf("HOOOYAAA");
}
static void three()
{
    printf("HOOOYAAA");
}
static void four()
{
    printf("HOOOYAAA");
}
static void five()
{
    printf("HOOOYAAA");
}
static void six()
{
    printf("HOOOYAAA");
}
static void seven()
{
    printf("HOOOYAAA");
}
static void eight()
{
    printf("HOOOYAAA");
}
static void nine()
{
    printf("HOOOYAAA");
}
static void dot()
{
    printf("HOOOYAAA");
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkBuilder *build = gtk_builder_new_from_file("calculator.ui");

    GtkWidget *win = GTK_WIDGET(gtk_builder_get_object(build, "win"));
    gtk_window_set_application(GTK_WINDOW(win), GTK_APPLICATION(app));
    gtk_widget_show(GTK_WIDGET(win));

    GtkButton *bp = GTK_BUTTON(gtk_builder_get_object(build, "bplus"));
    g_signal_connect(bp, "clicked", G_CALLBACK(plus), NULL);

    GtkButton *bm = GTK_BUTTON(gtk_builder_get_object(build, "bminus"));
    g_signal_connect(bm, "clicked", G_CALLBACK(minus), NULL);

    GtkButton *bmult = GTK_BUTTON(gtk_builder_get_object(build, "bmult"));
    g_signal_connect(bmult, "clicked", G_CALLBACK(mult), NULL);

    GtkButton *bdiv = GTK_BUTTON(gtk_builder_get_object(build, "bdiv"));
    g_signal_connect(bdiv, "clicked", G_CALLBACK(divi), NULL);

    GtkButton *bc = GTK_BUTTON(gtk_builder_get_object(build, "bc"));
    g_signal_connect(bc, "clicked", G_CALLBACK(c), NULL);

    GtkButton *bce = GTK_BUTTON(gtk_builder_get_object(build, "bce"));
    g_signal_connect(bce, "clicked", G_CALLBACK(ce), NULL);

    GtkButton *bequal = GTK_BUTTON(gtk_builder_get_object(build, "bequal"));
    g_signal_connect(bequal, "clicked", G_CALLBACK(equal), NULL);

    GtkButton *b0 = GTK_BUTTON(gtk_builder_get_object(build, "b0"));
    g_signal_connect(b0, "clicked", G_CALLBACK(zero), NULL);

    GtkButton *b1 = GTK_BUTTON(gtk_builder_get_object(build, "b1"));
    g_signal_connect(b1, "clicked", G_CALLBACK(one), NULL);

    GtkButton *b2 = GTK_BUTTON(gtk_builder_get_object(build, "b2"));
    g_signal_connect(b2, "clicked", G_CALLBACK(two), NULL);

    GtkButton *b3 = GTK_BUTTON(gtk_builder_get_object(build, "b3"));
    g_signal_connect(b3, "clicked", G_CALLBACK(three), NULL);

    GtkButton *b4 = GTK_BUTTON(gtk_builder_get_object(build, "b4"));
    g_signal_connect(b4, "clicked", G_CALLBACK(four), NULL);

    GtkButton *b5 = GTK_BUTTON(gtk_builder_get_object(build, "b5"));
    g_signal_connect(b5, "clicked", G_CALLBACK(five), NULL);

    GtkButton *b6 = GTK_BUTTON(gtk_builder_get_object(build, "b6"));
    g_signal_connect(b6, "clicked", G_CALLBACK(six), NULL);

    GtkButton *b7 = GTK_BUTTON(gtk_builder_get_object(build, "b7"));
    g_signal_connect(b7, "clicked", G_CALLBACK(seven), NULL);

    GtkButton *b8 = GTK_BUTTON(gtk_builder_get_object(build, "b8"));
    g_signal_connect(b8, "clicked", G_CALLBACK(eight), NULL);

    GtkButton *b9 = GTK_BUTTON(gtk_builder_get_object(build, "b9"));
    g_signal_connect(b9, "clicked", G_CALLBACK(nine), NULL);

    GtkButton *binverse = GTK_BUTTON(gtk_builder_get_object(build, "binverse"));
    g_signal_connect(binverse, "clicked", G_CALLBACK(inverse), NULL);

    GtkButton *bsquare = GTK_BUTTON(gtk_builder_get_object(build, "bsquare"));
    g_signal_connect(bsquare, "clicked", G_CALLBACK(square), NULL);

    GtkButton *bsin = GTK_BUTTON(gtk_builder_get_object(build, "bsin"));
    g_signal_connect(bsin, "clicked", G_CALLBACK(sine), NULL);

    GtkButton *bcos = GTK_BUTTON(gtk_builder_get_object(build, "bcos"));
    g_signal_connect(bcos, "clicked", G_CALLBACK(cosine), NULL);

    GtkButton *btan = GTK_BUTTON(gtk_builder_get_object(build, "btan"));
    g_signal_connect(btan, "clicked", G_CALLBACK(tangent), NULL);

    GtkButton *bnegate = GTK_BUTTON(gtk_builder_get_object(build, "bnegate"));
    g_signal_connect(bnegate, "clicked", G_CALLBACK(negate), NULL);

    GtkButton *bdot = GTK_BUTTON(gtk_builder_get_object(build, "bd"));
    g_signal_connect(bdot, "clicked", G_CALLBACK(dot), NULL);
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