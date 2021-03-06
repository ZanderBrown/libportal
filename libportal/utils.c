/*
 * Copyright (C) 2018, Matthias Clasen
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"

#include "utils-private.h"

G_DEFINE_BOXED_TYPE (XdpParent, xdp_parent, _xdp_parent_copy, _xdp_parent_free)

XdpParent *
_xdp_parent_copy (XdpParent *source)
{
  XdpParent *parent;

  parent = g_new0 (XdpParent, 1);

  parent->export = source->export;
  parent->unexport = source->unexport;
  g_set_object (&parent->object, source->object);

  return parent;
}

void
_xdp_parent_free (XdpParent *parent)
{
  g_clear_object (&parent->object);
  g_free (parent);
}
