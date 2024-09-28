#include <gtk/gtk.h>
#include <string.h>

bool dot_added = false;
bool op_added = false;
bool equaled = true;
bool n_after_op = false;
GtkLabel *up_panel;
GtkLabel *low_panel;

static void calculate(char *text)
{
    int length = strlen(text);
    int first_space;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            first_space = i;
            break;
        }
    }
    char n1[first_space + 2];
    for (int i = 0; i < first_space; i++)
    {
        n1[i] = text[i];
    }
    char n2[length - first_space - 2];
    char op = text[first_space + 1];
    for (int i = first_space + 3; i < length; i++)
    {
        n2[i - first_space - 3] = text[i];
    }
    double x = strtod(n1, NULL);
    double y = strtod(n2, NULL);
    if (op == '+')
        x += y;
    else if (op == '-')
        x -= y;
    else if (op == '*')
        x *= y;
    else
    {
        if (y == 0)
        {
            // handle division by 0
            return;
        }
        x /= y;
    }
    char output[17];
    snprintf(output, 17, "%f", x);
    gtk_label_set_label(low_panel, output);
}
static void plus()
{
    if (op_added)
        return;
    char text[21];
    if (equaled)
    {
        gtk_label_set_label(up_panel, gtk_label_get_label(low_panel));
        equaled = false;
    }
    strcpy(text, gtk_label_get_label(low_panel));
    strcat(text, " + ");
    gtk_label_set_label(up_panel, text);
    gtk_label_set_label(low_panel, "");
    op_added = true;
}
static void minus()
{
    if (op_added)
        return;
    if (equaled)
    {
        gtk_label_set_label(up_panel, gtk_label_get_label(low_panel));
        equaled = false;
    }
    char text[21];
    strcpy(text, gtk_label_get_label(low_panel));
    strcat(text, " - ");
    gtk_label_set_label(up_panel, text);
    gtk_label_set_label(low_panel, "");
    op_added = true;
}
static void mult()
{
    if (op_added)
        return;
    if (equaled)
    {
        gtk_label_set_label(up_panel, gtk_label_get_label(low_panel));
        equaled = false;
    }
    char text[21];
    strcpy(text, gtk_label_get_label(low_panel));
    strcat(text, " * ");
    gtk_label_set_label(up_panel, text);
    gtk_label_set_label(low_panel, "");
    op_added = true;
}
static void divi()
{
    if (op_added)
        return;
    if (equaled)
    {
        gtk_label_set_label(up_panel, gtk_label_get_label(low_panel));
        equaled = false;
    }
    char text[21];
    strcpy(text, gtk_label_get_label(low_panel));
    strcat(text, " / ");
    gtk_label_set_label(up_panel, text);
    gtk_label_set_label(low_panel, "");
    op_added = true;
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
    if (equaled)
        return;
    if (!n_after_op)
    {
        return;
    }
    char text[42];
    strcpy(text, gtk_label_get_label(up_panel));
    strcat(text, gtk_label_get_label(low_panel));
    calculate(text);
    strcat(text, " =");
    gtk_label_set_label(up_panel, text);
    equaled = true;
    op_added = false;
    n_after_op = false;
}
static void zero()
{
    char text[21];
    if (equaled)
        strcpy(text, "");
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "0"));
}
static void one()
{
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
        strcpy(text, "");
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "1"));
    equaled = false;
}
static void two()
{
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
        strcpy(text, "");
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "2"));
    equaled = false;
}
static void three()
{
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
        strcpy(text, "");
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "3"));
    equaled = false;
}
static void four()
{
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
        strcpy(text, "");
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "4"));
    equaled = false;
}
static void five()
{
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
        strcpy(text, "");
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "5"));
    equaled = false;
}
static void six()
{
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
        strcpy(text, "");
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "6"));
    equaled = false;
}
static void seven()
{
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
        strcpy(text, "");
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "7"));
    equaled = false;
}
static void eight()
{
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
        strcpy(text, "");
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "8"));
    equaled = false;
}
static void nine()
{
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
        strcpy(text, "");
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "9"));
    equaled = false;
}
static void dot()
{
    char text[21];
    if (op_added && !n_after_op)
    {
        n_after_op = true;
        strcpy(text, "0");
    }
    else if (equaled)
        strcpy(text, "0");
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "."));
    equaled = false;
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkBuilder *build = gtk_builder_new_from_file("calculator.ui");

    GtkWidget *win = GTK_WIDGET(gtk_builder_get_object(build, "win"));
    gtk_window_set_application(GTK_WINDOW(win), GTK_APPLICATION(app));
    gtk_window_set_resizable(GTK_WINDOW(win), 0);
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

    up_panel = GTK_LABEL(gtk_builder_get_object(build, "up_panel"));
    gtk_label_set_max_width_chars(up_panel, 40);
    gtk_label_set_wrap_mode(up_panel, PANGO_WRAP_WORD_CHAR);

    low_panel = GTK_LABEL(gtk_builder_get_object(build, "low_panel"));
    gtk_label_set_max_width_chars(low_panel, 20);
    gtk_label_set_wrap_mode(low_panel, PANGO_WRAP_WORD_CHAR);
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