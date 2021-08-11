#ifndef __HANJP_AUTOMATA_H__
#define __HANJP_AUTOMATA_H__

#include <glib-object.h>
#include <gmodule.h>

G_BEGIN_DECLS

enum {
    HANJP_AM_EAT,
    HANJP_AM_POP,
    HANJP_AM_FAIL
};

#define HANJP_TYPE_AUTOMATA hanjp_am_get_type()
G_DECLARE_INTERFACE(HanjpAutomata, hanjp_am, HANJP, AUTOMATA, GObject)

struct _HanjpAutomataInterface
{
    GTypeInterface parant_iface;

    gboolean (*to_kana) (HanjpAutomata* self, GArray *dest, gunichar cho, gunichar jung, gunichar jung2, gunichar jong);
    gint (*push) (HanjpAutomata *self, GArray *result, GArray *hangul, gunichar ch);
    gboolean (*backspace) (HanjpAutomata *self);
    gunichar (*flush) (HanjpAutomata *self);
};

gboolean hanjp_am_to_kana(HanjpAutomata *am, GArray *dest, gunichar cho, gunichar jung, gunichar jung2, gunichar jong);
gint hanjp_am_push(HanjpAutomata *am, GArray *result, GArray *hangul, gunichar ch);
gboolean hanjp_am_backspace(HanjpAutomata *am);
gunichar hanjp_am_flush(HanjpAutomata *am);

#define HANJP_TYPE_AUTOMATABASE hanjp_ambase_get_type()
G_DECLARE_DERIVABLE_TYPE(HanjpAutomataBase, hanjp_ambase, HANJP, AUTOMATABASE, GObject)

struct _HanjpAutomataBaseClass
{
    GObjectClass parent_class;
};

#define HANJP_TYPE_AUTOMATADEFAULT hanjp_amdefault_get_type()
G_DECLARE_DERIVABLE_TYPE(HanjpAutomataDefault, hanjp_amdefault, HANJP, AUTOMATADEFAULT, HanjpAutomataBase)

struct _HanjpAutomataDefaultClass
{
    HanjpAutomataBaseClass parent_class;
};

HanjpAutomataDefault *hanjp_amdefault_new();

G_END_DECLS

#endif //__HANJP_AUTOMATA_H__