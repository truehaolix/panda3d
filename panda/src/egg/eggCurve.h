// Filename: eggCurve.h
// Created by:  drose (15Feb00)
//
////////////////////////////////////////////////////////////////////

#ifndef EGGCURVE_H
#define EGGCURVE_H

#include <pandabase.h>

#include "eggPrimitive.h"

////////////////////////////////////////////////////////////////////
// 	 Class : EggCurve
// Description : A parametric curve of some kind.  See
//               EggNurbsCurve.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDAEGG EggCurve : public EggPrimitive {
public:
  INLINE EggCurve(const string &name = "");
  INLINE EggCurve(const EggCurve &copy);
  INLINE EggCurve &operator = (const EggCurve &copy);

  enum CurveType {
    CT_none,
    CT_xyz,
    CT_hpr,
    CT_t
  };

  INLINE void set_subdiv(int subdiv);
  INLINE int get_subdiv() const;

  INLINE void set_curve_type(CurveType type);
  INLINE CurveType get_curve_type() const;

  static CurveType string_curve_type(const string &string);

private:
  int _subdiv;
  CurveType _type;

public:

  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    EggPrimitive::init_type();
    register_type(_type_handle, "EggCurve",
                  EggPrimitive::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}
 
private:
  static TypeHandle _type_handle;
};

ostream &operator << (ostream &out, EggCurve::CurveType t);

#include "eggCurve.I"

#endif
