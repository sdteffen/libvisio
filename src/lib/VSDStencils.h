/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* libvisio
 * Version: MPL 1.1 / GPLv2+ / LGPLv2+
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License or as specified alternatively below. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * Major Contributor(s):
 * Copyright (C) 2011 Fridrich Strba <fridrich.strba@bluewin.ch>
 * Copyright (C) 2011 Eilidh McAdam <tibbylickle@gmail.com>
 *
 *
 * All Rights Reserved.
 *
 * For minor contributions see the git repository.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPLv2+"), or
 * the GNU Lesser General Public License Version 2 or later (the "LGPLv2+"),
 * in which case the provisions of the GPLv2+ or the LGPLv2+ are applicable
 * instead of those above.
 */

#ifndef __VSDSTENCILS_H__
#define __VSDSTENCILS_H__

#include <map>
#include <vector>
#include "VSDStyles.h"
#include "VSDGeometryList.h"
#include "VSDFieldList.h"
#include "VSDTypes.h"

namespace libvisio
{

class VSDStencilShape
{
public:
  VSDStencilShape();
  VSDStencilShape(const VSDStencilShape &shape);
  ~VSDStencilShape();
  VSDStencilShape &operator=(const VSDStencilShape &shape);

  std::vector<VSDGeometryList> m_geometries;
  VSDFieldList m_fields;
  ForeignData *m_foreign;
  unsigned m_lineStyleId, m_fillStyleId, m_textStyleId;
  VSDLineStyle *m_lineStyle;
  VSDFillStyle *m_fillStyle;
  VSDTextBlockStyle *m_textBlockStyle;
  VSDCharStyle *m_charStyle;
  VSDParaStyle *m_paraStyle;
  WPXBinaryData m_text;
  std::map< unsigned, VSDName > m_names;
  TextFormat m_textFormat;
  std::map<unsigned, NURBSData> m_nurbsData;
  std::map<unsigned, PolylineData> m_polylineData;
};

class VSDStencil
{
public:
  VSDStencil();
  VSDStencil(const VSDStencil &stencil);
  ~VSDStencil();
  VSDStencil &operator=(const VSDStencil &stencil);
  void addStencilShape(unsigned id, const VSDStencilShape &shape);
  const VSDStencilShape *getStencilShape(unsigned id) const;
  std::map<unsigned, VSDStencilShape> m_shapes;
  double m_shadowOffsetX;
  double m_shadowOffsetY;
};

class VSDStencils
{
public:
  VSDStencils();
  ~VSDStencils();
  void addStencil(unsigned idx, const VSDStencil &stencil);
  const VSDStencil *getStencil(unsigned idx) const;
  unsigned count() const
  {
    return m_stencils.size();
  }
private:
  std::map<unsigned, VSDStencil> m_stencils;
};


} // namespace libvisio

#endif // __VSDSTENCILS_H__
/* vim:set shiftwidth=2 softtabstop=2 expandtab: */