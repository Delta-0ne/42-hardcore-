/* Big Header */

#ifndef HOOK_C
# define HOOK_C

/* ------ MODULES ------- */
// Globals :
# include "standard_types.h"
# include "layout_types.h"

// Local :
//...

/* ------- TYPES -------- */
//...

/* ----- STRUCT ------ */
//...


/* ----- PROTOTYPES ----- */

void	main_hook(XEvent *event, Display *server, void (*callback)(),
					void *usr_data);

#endif	// HOOK_C