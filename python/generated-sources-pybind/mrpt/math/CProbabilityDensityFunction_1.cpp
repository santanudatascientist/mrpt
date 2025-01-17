#include <iterator>
#include <memory>
#include <mrpt/math/CMatrixDynamic.h>
#include <mrpt/math/CMatrixFixed.h>
#include <mrpt/math/CProbabilityDensityFunction.h>
#include <mrpt/math/CQuaternion.h>
#include <mrpt/math/CVectorDynamic.h>
#include <mrpt/math/TPoint2D.h>
#include <mrpt/math/TPoint3D.h>
#include <mrpt/math/TPose2D.h>
#include <mrpt/math/TPose3D.h>
#include <mrpt/math/TPose3DQuat.h>
#include <mrpt/math/math_frwds.h>
#include <mrpt/math/matrix_size_t.h>
#include <mrpt/poses/CPoint2D.h>
#include <mrpt/poses/CPoint3D.h>
#include <mrpt/poses/CPose2D.h>
#include <mrpt/poses/CPose3D.h>
#include <mrpt/poses/CPose3DQuat.h>
#include <mrpt/poses/CPoseOrPoint.h>
#include <mrpt/rtti/CObject.h>
#include <mrpt/typemeta/static_string.h>
#include <optional>
#include <sstream> // __str__
#include <string>
#include <tuple>
#include <vector>

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

// mrpt::math::CProbabilityDensityFunction file:mrpt/math/CProbabilityDensityFunction.h line:30
struct PyCallBack_mrpt_math_CProbabilityDensityFunction_mrpt_poses_CPose3DQuat_7_t : public mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7> {
	using mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>::CProbabilityDensityFunction;

	void getMean(class mrpt::poses::CPose3DQuat & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7> *>(this), "getMean");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"CProbabilityDensityFunction::getMean\"");
	}
	using _binder_ret_0 = class std::tuple<class mrpt::math::CMatrixFixed<double, 7, 7>, class mrpt::poses::CPose3DQuat>;
	_binder_ret_0 getCovarianceAndMean() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7> *>(this), "getCovarianceAndMean");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<_binder_ret_0>::value) {
				static pybind11::detail::override_caster_t<_binder_ret_0> caster;
				return pybind11::detail::cast_ref<_binder_ret_0>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<_binder_ret_0>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"CProbabilityDensityFunction::getCovarianceAndMean\"");
	}
	bool isInfType() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7> *>(this), "isInfType");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return CProbabilityDensityFunction::isInfType();
	}
	bool saveToTextFile(const std::string & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7> *>(this), "saveToTextFile");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"CProbabilityDensityFunction::saveToTextFile\"");
	}
	void drawSingleSample(class mrpt::poses::CPose3DQuat & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7> *>(this), "drawSingleSample");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"CProbabilityDensityFunction::drawSingleSample\"");
	}
};

void bind_mrpt_math_CProbabilityDensityFunction_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // mrpt::math::CProbabilityDensityFunction file:mrpt/math/CProbabilityDensityFunction.h line:30
		pybind11::class_<mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>, std::shared_ptr<mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>>, PyCallBack_mrpt_math_CProbabilityDensityFunction_mrpt_poses_CPose3DQuat_7_t> cl(M("mrpt::math"), "CProbabilityDensityFunction_mrpt_poses_CPose3DQuat_7_t", "");
		cl.def(pybind11::init<PyCallBack_mrpt_math_CProbabilityDensityFunction_mrpt_poses_CPose3DQuat_7_t const &>());
		cl.def( pybind11::init( [](){ return new PyCallBack_mrpt_math_CProbabilityDensityFunction_mrpt_poses_CPose3DQuat_7_t(); } ) );
		cl.def("getMean", (void (mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>::*)(class mrpt::poses::CPose3DQuat &) const) &mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::getMean, "C++: mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::getMean(class mrpt::poses::CPose3DQuat &) const --> void", pybind11::arg("mean_point"));
		cl.def("getCovarianceAndMean", (class std::tuple<class mrpt::math::CMatrixFixed<double, 7, 7>, class mrpt::poses::CPose3DQuat> (mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>::*)() const) &mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::getCovarianceAndMean, "C++: mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::getCovarianceAndMean() const --> class std::tuple<class mrpt::math::CMatrixFixed<double, 7, 7>, class mrpt::poses::CPose3DQuat>");
		cl.def("getCovarianceDynAndMean", (void (mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>::*)(class mrpt::math::CMatrixDynamic<double> &, class mrpt::poses::CPose3DQuat &) const) &mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::getCovarianceDynAndMean, "C++: mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::getCovarianceDynAndMean(class mrpt::math::CMatrixDynamic<double> &, class mrpt::poses::CPose3DQuat &) const --> void", pybind11::arg("cov"), pybind11::arg("mean_point"));
		cl.def("getMeanVal", (class mrpt::poses::CPose3DQuat (mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>::*)() const) &mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::getMeanVal, "C++: mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::getMeanVal() const --> class mrpt::poses::CPose3DQuat");
		cl.def("getCovariance", (void (mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>::*)(class mrpt::math::CMatrixDynamic<double> &) const) &mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::getCovariance, "C++: mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::getCovariance(class mrpt::math::CMatrixDynamic<double> &) const --> void", pybind11::arg("cov"));
		cl.def("isInfType", (bool (mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>::*)() const) &mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::isInfType, "C++: mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::isInfType() const --> bool");
		cl.def("saveToTextFile", (bool (mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>::*)(const std::string &) const) &mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::saveToTextFile, "C++: mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::saveToTextFile(const std::string &) const --> bool", pybind11::arg("file"));
		cl.def("drawSingleSample", (void (mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>::*)(class mrpt::poses::CPose3DQuat &) const) &mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::drawSingleSample, "C++: mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::drawSingleSample(class mrpt::poses::CPose3DQuat &) const --> void", pybind11::arg("outPart"));
		cl.def("getCovarianceEntropy", (double (mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>::*)() const) &mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::getCovarianceEntropy, "C++: mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::getCovarianceEntropy() const --> double");
		cl.def("assign", (class mrpt::math::CProbabilityDensityFunction<class mrpt::poses::CPose3DQuat, 7> & (mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat,7>::*)(const class mrpt::math::CProbabilityDensityFunction<class mrpt::poses::CPose3DQuat, 7> &)) &mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::operator=, "C++: mrpt::math::CProbabilityDensityFunction<mrpt::poses::CPose3DQuat, 7>::operator=(const class mrpt::math::CProbabilityDensityFunction<class mrpt::poses::CPose3DQuat, 7> &) --> class mrpt::math::CProbabilityDensityFunction<class mrpt::poses::CPose3DQuat, 7> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
