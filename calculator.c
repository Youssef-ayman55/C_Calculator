#include <gtk/gtk.h>
#include <string.h>
#include <math.h>

bool dot_added = false;
bool op_added = false;
bool equaled = true;
bool n_after_op = false;
bool unary = false;
bool error = false;
GtkLabel *up_panel;
GtkLabel *low_panel;

static void calculate();
static void equal();
static void minus();
static void plus();
static void mult();
static void divi();
static void negate();
static void inverse();
static void square();
static void sine();
static void cosine();
static void tangent();
static void c();
static void ce();
static void zero();
static void one();
static void two();
static void three();
static void four();
static void five();
static void six();
static void seven();
static void eight();
static void nine();
static void dot();
gboolean keypress(GtkEventControllerKey *event_controller, guint keyval, guint keycode, GdkModifierType state, gpointer user_data);
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
            gtk_label_set_label(low_panel, "Error");
            error = true;
            return;
        }
        x /= y;
    }
    char output[17];
    snprintf(output, 17, "%g", x);
    gtk_label_set_label(low_panel, output);
}
static void plus()
{
    if (op_added && !n_after_op || error)
        return;
    char text[21];
    if (n_after_op)
    {
        equal();
        op_added = true;
        n_after_op = false;
    }
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
    if (op_added && !n_after_op || error)
        return;
    if (n_after_op)
    {
        equal();
        op_added = true;
        n_after_op = false;
    }
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
    if (op_added && !n_after_op || error)
        return;
    if (n_after_op)
    {
        equal();
        op_added = true;
        n_after_op = false;
    }
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
    if (op_added && !n_after_op || error)
        return;
    if (n_after_op)
    {
        equal();
        op_added = true;
        n_after_op = false;
    }
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
    if (error)
        return;
    char text[17];
    strcpy(text, gtk_label_get_label(low_panel));
    double x = strtod(text, NULL);
    x *= -1;
    snprintf(text, 17, "%g", x);
    gtk_label_set_label(low_panel, text);
}
static void inverse()
{
    if (error)
        return;
    char text[17];
    strcpy(text, gtk_label_get_label(low_panel));
    double x = strtod(text, NULL);
    if (x == 0)
    {
        gtk_label_set_label(low_panel, "Error");
        error = true;
        return;
    }
    x = 1 / x;
    snprintf(text, 17, "%g", x);
    gtk_label_set_label(low_panel, text);
    if (!op_added)
        equaled = true;
    unary = true;
}
static void sine()
{
    if (error)
        return;
    char text[17];
    strcpy(text, gtk_label_get_label(low_panel));
    double x = strtod(text, NULL);
    x = sin(x);
    snprintf(text, 17, "%g", x);
    gtk_label_set_label(low_panel, text);
    if (!op_added)
        equaled = true;
    unary = true;
}
static void cosine()
{
    if (error)
        return;
    char text[17];
    strcpy(text, gtk_label_get_label(low_panel));
    double x = strtod(text, NULL);
    x = cos(x);
    snprintf(text, 17, "%g", x);
    gtk_label_set_label(low_panel, text);
    if (!op_added)
        equaled = true;
    unary = true;
}
static void tangent()
{
    if (error)
        return;
    char text[17];
    strcpy(text, gtk_label_get_label(low_panel));
    double x = strtod(text, NULL);
    x = tan(x);
    snprintf(text, 17, "%g", x);
    gtk_label_set_label(low_panel, text);
    if (!op_added)
        equaled = true;
    unary = true;
}
static void square()
{
    if (error)
        return;
    char text[17];
    strcpy(text, gtk_label_get_label(low_panel));
    double x = strtod(text, NULL);
    x *= x;
    snprintf(text, 17, "%g", x);
    gtk_label_set_label(low_panel, text);
    if (!op_added)
        equaled = true;
    unary = true;
}
static void c()
{
    dot_added = false;
    op_added = false;
    equaled = true;
    n_after_op = false;
    unary = false;
    error = false;
    gtk_label_set_label(low_panel, "0");
    gtk_label_set_label(up_panel, "");
}
static void ce()
{
    if (equaled || error)
    {
        c();
        return;
    }
    if (op_added)
        printf("HOOYAA");
    dot_added = false;
    n_after_op = false;
    unary = false;
    gtk_label_set_label(low_panel, "");
}
static void equal()
{
    if (equaled || error)
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
    unary = false;
}
static void zero()
{
    char text[21];
    if (error)
        c();
    if (op_added)
    {
        n_after_op = true;
    }
    if (equaled)
    {
        strcpy(text, "");
        gtk_label_set_label(up_panel, "");
    }
    else if (unary)
    {
        strcpy(text, "");
        unary = false;
    }
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "0"));
}
static void one()
{
    if (error)
        c();
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
    {
        strcpy(text, "");
        gtk_label_set_label(up_panel, "");
    }
    else if (unary)
    {
        strcpy(text, "");
        unary = false;
    }
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "1"));
    equaled = false;
}
static void two()
{
    if (error)
        c();
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
    {
        strcpy(text, "");
        gtk_label_set_label(up_panel, "");
    }
    else if (unary)
    {
        strcpy(text, "");
        unary = false;
    }
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "2"));
    equaled = false;
}
static void three()
{
    if (error)
        c();
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
    {
        strcpy(text, "");
        gtk_label_set_label(up_panel, "");
    }
    else if (unary)
    {
        strcpy(text, "");
        unary = false;
    }
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "3"));
    equaled = false;
}
static void four()
{
    if (error)
        c();
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
    {
        strcpy(text, "");
        gtk_label_set_label(up_panel, "");
    }
    else if (unary)
    {
        strcpy(text, "");
        unary = false;
    }
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "4"));
    equaled = false;
}
static void five()
{
    if (error)
        c();
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
    {
        strcpy(text, "");
        gtk_label_set_label(up_panel, "");
    }
    else if (unary)
    {
        strcpy(text, "");
        unary = false;
    }
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "5"));
    equaled = false;
}
static void six()
{
    if (error)
        c();
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
    {
        strcpy(text, "");
        gtk_label_set_label(up_panel, "");
    }
    else if (unary)
    {
        strcpy(text, "");
        unary = false;
    }
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "6"));
    equaled = false;
}
static void seven()
{
    if (error)
        c();
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
    {
        strcpy(text, "");
        gtk_label_set_label(up_panel, "");
    }
    else if (unary)
    {
        strcpy(text, "");
        unary = false;
    }
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "7"));
    equaled = false;
}
static void eight()
{
    if (error)
        c();
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
    {
        strcpy(text, "");
        gtk_label_set_label(up_panel, "");
    }
    else if (unary)
    {
        strcpy(text, "");
        unary = false;
    }
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "8"));
    equaled = false;
}
static void nine()
{
    if (error)
        c();
    if (op_added)
    {
        n_after_op = true;
    }
    char text[21];
    if (equaled)
    {
        strcpy(text, "");
        gtk_label_set_label(up_panel, "");
    }
    else if (unary)
    {
        strcpy(text, "");
        unary = false;
    }
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "9"));
    equaled = false;
}
static void dot()
{
    if (error)
        c();
    char text[21];
    if (op_added && !n_after_op)
    {
        n_after_op = true;
        strcpy(text, "0");
    }
    else if (equaled || unary)
        strcpy(text, "0");
    else
        strcpy(text, gtk_label_get_label(low_panel));
    if (strlen(text) < 16)
        gtk_label_set_label(low_panel, strcat(text, "."));
    equaled = false;
    unary = false;
}
gboolean keypress(GtkEventControllerKey *event_controller, guint keyval, guint keycode, GdkModifierType state, gpointer user_data)
{
    if (keyval == GDK_KEY_0 || keyval == GDK_KEY_KP_0)
        zero();
    else if (keyval == GDK_KEY_1 || keyval == GDK_KEY_KP_1)
        one();
    else if (keyval == GDK_KEY_2 || keyval == GDK_KEY_KP_2)
        two();
    else if (keyval == GDK_KEY_3 || keyval == GDK_KEY_KP_3)
        three();
    else if (keyval == GDK_KEY_4 || keyval == GDK_KEY_KP_4)
        four();
    else if (keyval == GDK_KEY_5 || keyval == GDK_KEY_KP_5)
        five();
    else if (keyval == GDK_KEY_6 || keyval == GDK_KEY_KP_6)
        six();
    else if (keyval == GDK_KEY_7 || keyval == GDK_KEY_KP_7)
        seven();
    else if (keyval == GDK_KEY_8 || keyval == GDK_KEY_KP_8)
        eight();
    else if (keyval == GDK_KEY_9 || keyval == GDK_KEY_KP_9)
        nine();
    else if (keyval == GDK_KEY_plus || keyval == GDK_KEY_KP_Add)
        plus();
    else if (keyval == GDK_KEY_minus || keyval == GDK_KEY_KP_Subtract)
        minus();
    else if (keyval == GDK_KEY_asterisk || keyval == GDK_KEY_KP_Multiply)
        mult();
    else if (keyval == GDK_KEY_slash || keyval == GDK_KEY_KP_Divide)
        divi();
    else if (keyval == GDK_KEY_period || keyval == GDK_KEY_KP_Decimal)
        dot();
    else if (keyval == GDK_KEY_equal || keyval == GDK_KEY_KP_Enter || keyval == GDK_KEY_Return)
        equal();
    else
    {
        return false;
    }
    return true;
}
static void activate(GtkApplication *app, gpointer user_data)
{
    GtkBuilder *build = gtk_builder_new_from_file("calculator.ui");

    GtkWidget *win = GTK_WIDGET(gtk_builder_get_object(build, "win"));
    gtk_widget_set_focusable(win, TRUE);
    GtkEventController *event_controller;
    event_controller = gtk_event_controller_key_new();
    gtk_widget_add_controller(win, event_controller);
    g_signal_connect(event_controller, "key-pressed", G_CALLBACK(keypress), NULL);
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
