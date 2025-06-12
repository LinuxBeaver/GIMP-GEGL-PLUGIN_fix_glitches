/* This file is an image processing operation for GEGL
 * GEGL is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * GEGL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GEGL; if not, see <https://www.gnu.org/licenses/>.
 * Credit to Øyvind Kolås (pippin) for major GEGL contributions
 * 2025, Beaver Repair GEGL pipeline
* 
* graph below
* 
median-blur radius=0 abyss-policy=none id=1 crop aux=[ ref=1 ] median-blur radius=0 abyss-policy=none

 * 
* 
* 
 */

#include "config.h"
#include <glib/gi18n-lib.h>

#ifdef GEGL_PROPERTIES




#else

#define GEGL_OP_META
#define GEGL_OP_NAME     fixer
#define GEGL_OP_C_SOURCE fixer.c

#include "gegl-op.h"

static void
attach (GeglOperation *operation)
{
  GeglNode *gegl   = operation->node;
  GeglNode *output = gegl_node_get_output_proxy (gegl, "output");

#define fix \
" median-blur radius=0 abyss-policy=none id=1 crop aux=[ ref=1 ] median-blur radius=0 abyss-policy=none "\

GeglNode*fixer = gegl_node_new_child (gegl, "operation", "gegl:gegl", "string", fix,  NULL);
GeglNode*input  = gegl_node_get_input_proxy (gegl, "input");

 gegl_node_link_many (input, fixer, output,  NULL);

}

static void
gegl_op_class_init (GeglOpClass *klass)
{
  GeglOperationClass *operation_class;

  operation_class = GEGL_OPERATION_CLASS (klass);

  operation_class->attach = attach;
  operation_class->threaded = FALSE;

  gegl_operation_class_set_keys (operation_class,
    "name",           "lb:fixer",
    "title",          _("Repair pipeline"),
    "reference-hash", "coffeehousecrimeyt",
    "description", _("Filter to help repair a corrupt GEGL pipeline. Apply if you believe your non-destructive layers in GIMP 3 are glitching out"),  
    "gimp:menu-path", "<Image>/Filters/Generic",
    "gimp:menu-label", _("Repair pipeline..."),
 NULL);                               
}

#endif
