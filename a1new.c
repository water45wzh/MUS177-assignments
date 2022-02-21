#include "m_pd.h"
 
typedef struct a1new
{
  t_object x_ob;
  t_outlet *x_outlet;
  float x_value;
} t_a1new;

void a1new_float(t_a1new *x, t_floatarg f)
{
    outlet_float(x->x_outlet, f * x->x_value);
}

void a1new_ft1(t_a1new *x, t_floatarg g)
{
    x->x_value = g;
}

t_class *a1new_class;

void *a1new_new(void)
{
    t_a1new *x = (t_a1new *)pd_new(a1new_class);
    inlet_new(&x->x_ob, &x->x_ob.ob_pd, gensym("float"), gensym("ft1"));
    x->x_outlet = outlet_new(&x->x_ob, gensym("float"));
    return (void *)x;
}

void a1new_setup(void)
{
    a1new_class = class_new(gensym("a1new"), (t_newmethod)a1new_new,
    	0, sizeof(t_a1new), 0, 0);
    class_addmethod(a1new_class, (t_method)a1new_ft1, gensym("ft1"), A_FLOAT, 0);
    class_addfloat(a1new_class, a1new_float);
}

