#include <iterator>
#include <memory>
#include <mrpt/math/TPoint2D.h>
#include <mrpt/math/TPoint3D.h>
#include <mrpt/math/TPose2D.h>
#include <mrpt/math/TPose3D.h>
#include <mrpt/math/TTwist2D.h>
#include <sstream> // __str__
#include <string>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <stl_binders.hpp>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_mrpt_math_TTwist2D(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // mrpt::math::TTwist2D file:mrpt/math/TTwist2D.h line:21
		pybind11::class_<mrpt::math::TTwist2D, std::shared_ptr<mrpt::math::TTwist2D>> cl(M("mrpt::math"), "TTwist2D", "2D twist: 2D velocity vector (vx,vy) + planar angular velocity (omega)\n \n\n mrpt::math::TTwist3D, mrpt::math::TPose2D\n \n\n\n ");
		cl.def( pybind11::init<double, double, double>(), pybind11::arg("vx_"), pybind11::arg("vy_"), pybind11::arg("omega_") );

		cl.def( pybind11::init( [](){ return new mrpt::math::TTwist2D(); } ) );
		cl.def( pybind11::init( [](mrpt::math::TTwist2D const &o){ return new mrpt::math::TTwist2D(o); } ) );
		cl.def_readwrite("vx", &mrpt::math::TTwist2D::vx);
		cl.def_readwrite("vy", &mrpt::math::TTwist2D::vy);
		cl.def_readwrite("omega", &mrpt::math::TTwist2D::omega);
		cl.def("__getitem__", (double & (mrpt::math::TTwist2D::*)(size_t)) &mrpt::math::TTwist2D::operator[], "Coordinate access using operator[]. Order: vx,vy,vphi \n\nC++: mrpt::math::TTwist2D::operator[](size_t) --> double &", pybind11::return_value_policy::automatic, pybind11::arg("i"));
		cl.def("rotate", (void (mrpt::math::TTwist2D::*)(const double)) &mrpt::math::TTwist2D::rotate, "Transform the (vx,vy) components for a counterclockwise rotation of\n `ang` radians. \n\nC++: mrpt::math::TTwist2D::rotate(const double) --> void", pybind11::arg("ang"));
		cl.def("rotated", (struct mrpt::math::TTwist2D (mrpt::math::TTwist2D::*)(const double) const) &mrpt::math::TTwist2D::rotated, "Like rotate(), but returning a copy of the rotated twist.\n  \n\n New in MRPT 2.3.2 \n\nC++: mrpt::math::TTwist2D::rotated(const double) const --> struct mrpt::math::TTwist2D", pybind11::arg("ang"));
		cl.def("__eq__", (bool (mrpt::math::TTwist2D::*)(const struct mrpt::math::TTwist2D &) const) &mrpt::math::TTwist2D::operator==, "C++: mrpt::math::TTwist2D::operator==(const struct mrpt::math::TTwist2D &) const --> bool", pybind11::arg("o"));
		cl.def("__ne__", (bool (mrpt::math::TTwist2D::*)(const struct mrpt::math::TTwist2D &) const) &mrpt::math::TTwist2D::operator!=, "C++: mrpt::math::TTwist2D::operator!=(const struct mrpt::math::TTwist2D &) const --> bool", pybind11::arg("o"));
		cl.def("__mul__", (struct mrpt::math::TPose2D (mrpt::math::TTwist2D::*)(const double) const) &mrpt::math::TTwist2D::operator*, "Returns the pose increment of multiplying each twist component times\n \"dt\" seconds. \n\nC++: mrpt::math::TTwist2D::operator*(const double) const --> struct mrpt::math::TPose2D", pybind11::arg("dt"));
		cl.def("__imul__", (void (mrpt::math::TTwist2D::*)(const double)) &mrpt::math::TTwist2D::operator*=, "Scale factor \n\nC++: mrpt::math::TTwist2D::operator*=(const double) --> void", pybind11::arg("k"));
		cl.def("asString", (void (mrpt::math::TTwist2D::*)(std::string &) const) &mrpt::math::TTwist2D::asString, "Returns a human-readable textual representation of the object (eg: \"[vx\n vy omega]\", omega in deg/s)\n \n\n fromString\n\nC++: mrpt::math::TTwist2D::asString(std::string &) const --> void", pybind11::arg("s"));
		cl.def("asString", (std::string (mrpt::math::TTwist2D::*)() const) &mrpt::math::TTwist2D::asString, "C++: mrpt::math::TTwist2D::asString() const --> std::string");
		cl.def("fromString", (void (mrpt::math::TTwist2D::*)(const std::string &)) &mrpt::math::TTwist2D::fromString, "Set the current object value from a string generated by 'asString' (eg:\n \"[0.02 1.04 -45.0]\" )\n \n\n asString\n \n\n std::exception On invalid format\n\nC++: mrpt::math::TTwist2D::fromString(const std::string &) --> void", pybind11::arg("s"));
		cl.def_static("FromString", (struct mrpt::math::TTwist2D (*)(const std::string &)) &mrpt::math::TTwist2D::FromString, "C++: mrpt::math::TTwist2D::FromString(const std::string &) --> struct mrpt::math::TTwist2D", pybind11::arg("s"));
		cl.def("assign", (struct mrpt::math::TTwist2D & (mrpt::math::TTwist2D::*)(const struct mrpt::math::TTwist2D &)) &mrpt::math::TTwist2D::operator=, "C++: mrpt::math::TTwist2D::operator=(const struct mrpt::math::TTwist2D &) --> struct mrpt::math::TTwist2D &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
