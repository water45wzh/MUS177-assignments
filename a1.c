/* code for "a1" pd class.  This takes two messages: floating-point
numbers, and "cats", and just prints something out for each message. */

#include "m_pd.h"

    /* the data structure for each copy of "a1".  In this case we
    on;y need pd's obligatory header (of type t_object). */
typedef struct a1
{
  t_object x_ob;
} t_a1;

    /* this is called back when a1 gets a "float" message (i.e., a
    number.) */
void a1_float(t_a1 *x, t_floatarg f)
{
    post("a1: %f", 1/f);
}

    /* this is called when a1 gets the message, "cats". */
void a1_cats(t_a1 *x)
{
    post("a1: cats");
}

    /* this is a pointer to the class for "a1", which is created in the
    "setup" routine below and used to create new ones in the "new" routine. */
t_class *a1_class;

    /* this is called when a new "a1" object is created. */
void *a1_new(void)
{
    t_a1 *x = (t_a1 *)pd_new(a1_class);
    post("a1_new");
    return (void *)x;
}

    /* this is called once at setup time, when this code is loaded into Pd. */
void a1_setup(void)
{
    post("a1_setup");
    a1_class = class_new(gensym("a1"), (t_newmethod)a1_new, 0,
    	sizeof(t_a1), 0, 0);
    class_addmethod(a1_class, (t_method)a1_cats, gensym("cats"), 0);
    class_addfloat(a1_class, a1_float);
}

