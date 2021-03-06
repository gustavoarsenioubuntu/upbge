/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file KX_PolyProxy.h
 *  \ingroup ketsji
 */

#ifndef __KX_POLYPROXY_H__
#define __KX_POLYPROXY_H__

#ifdef WITH_PYTHON

#include "SCA_IObject.h"

class KX_MeshProxy;
class RAS_MeshObject;
class RAS_Polygon;

class KX_PolyProxy : public CValue
{
	Py_Header
protected:
	KX_MeshProxy *m_meshProxy;
	RAS_Polygon* m_polygon;
	RAS_MeshObject*	m_mesh;
public:
	KX_PolyProxy(KX_MeshProxy *meshProxy, RAS_MeshObject *mesh, RAS_Polygon *polygon);
	virtual ~KX_PolyProxy();

	// stuff for cvalue related things
	virtual std::string GetName();

	RAS_Polygon *GetPolygon();
	KX_MeshProxy *GetMeshProxy();

	// stuff for python integration
	static PyObject *pyattr_get_material_name(PyObjectPlus *self_v, const KX_PYATTRIBUTE_DEF *attrdef);
	static PyObject *pyattr_get_texture_name(PyObjectPlus *self_v, const KX_PYATTRIBUTE_DEF *attrdef);
	static PyObject *pyattr_get_material(PyObjectPlus *self_v, const KX_PYATTRIBUTE_DEF *attrdef);
	static PyObject *pyattr_get_material_id(PyObjectPlus *self_v, const KX_PYATTRIBUTE_DEF *attrdef);
	static PyObject *pyattr_get_v1(PyObjectPlus *self_v, const KX_PYATTRIBUTE_DEF *attrdef);
	static PyObject *pyattr_get_v2(PyObjectPlus *self_v, const KX_PYATTRIBUTE_DEF *attrdef);
	static PyObject *pyattr_get_v3(PyObjectPlus *self_v, const KX_PYATTRIBUTE_DEF *attrdef);
	static PyObject *pyattr_get_v4(PyObjectPlus *self_v, const KX_PYATTRIBUTE_DEF *attrdef);
	static PyObject *pyattr_get_visible(PyObjectPlus *self_v, const KX_PYATTRIBUTE_DEF *attrdef);
	static PyObject *pyattr_get_collide(PyObjectPlus *self_v, const KX_PYATTRIBUTE_DEF *attrdef);
	static PyObject *pyattr_get_vertices(PyObjectPlus *self_v, const KX_PYATTRIBUTE_DEF *attrdef);

	KX_PYMETHOD_DOC_NOARGS(KX_PolyProxy, getMaterialIndex)
	KX_PYMETHOD_DOC_NOARGS(KX_PolyProxy, getNumVertex)
	KX_PYMETHOD_DOC_NOARGS(KX_PolyProxy, isVisible)
	KX_PYMETHOD_DOC_NOARGS(KX_PolyProxy, isCollider)
	KX_PYMETHOD_DOC_NOARGS(KX_PolyProxy, getMaterialName)
	KX_PYMETHOD_DOC_NOARGS(KX_PolyProxy, getTextureName)
	KX_PYMETHOD_DOC(KX_PolyProxy, getVertexIndex)
	KX_PYMETHOD_DOC_NOARGS(KX_PolyProxy, getMesh)
	KX_PYMETHOD_DOC_NOARGS(KX_PolyProxy, getMaterial)

};

#endif  /* WITH_PYTHON */

#endif  /* __KX_POLYPROXY_H__ */
