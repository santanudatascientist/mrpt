#include <chrono>
#include <functional>
#include <map>
#include <memory>
#include <mrpt/core/Clock.h>
#include <mrpt/serialization/CSerializable.h>
#include <ratio>
#include <sstream> // __str__
#include <utility>

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

void bind_std_stl_multimap(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // std::multimap file:bits/stl_multimap.h line:99
		pybind11::class_<std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>, std::shared_ptr<std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>>> cl(M("std"), "multimap_std_chrono_time_point_mrpt_Clock_std_chrono_duration_long_std_ratio_1_10000000_std_shared_ptr_mrpt_serialization_CSerializable_t", "");
		cl.def( pybind11::init( [](){ return new std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>(); } ) );
		cl.def( pybind11::init( [](const struct std::less<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > > & a0){ return new std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>(a0); } ), "doc" , pybind11::arg("__comp"));
		cl.def( pybind11::init<const struct std::less<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > > &, const class std::allocator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > &>(), pybind11::arg("__comp"), pybind11::arg("__a") );

		cl.def( pybind11::init( [](std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>> const &o){ return new std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>(o); } ) );
		cl.def( pybind11::init<const class std::allocator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > &>(), pybind11::arg("__a") );

		cl.def( pybind11::init<const class std::multimap<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable>, struct std::less<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > >, class std::allocator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > > &, const class std::allocator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > &>(), pybind11::arg("__m"), pybind11::arg("__a") );

		cl.def("assign", (class std::multimap<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable>, struct std::less<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > >, class std::allocator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > > & (std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>::*)(const class std::multimap<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable>, struct std::less<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > >, class std::allocator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > > &)) &std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::operator=, "C++: std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::operator=(const class std::multimap<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable>, struct std::less<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > >, class std::allocator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > > &) --> class std::multimap<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable>, struct std::less<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > >, class std::allocator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > > &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		cl.def("get_allocator", (class std::allocator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > (std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>::*)() const) &std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::get_allocator, "C++: std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::get_allocator() const --> class std::allocator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > >");
		cl.def("empty", (bool (std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>::*)() const) &std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::empty, "C++: std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::empty() const --> bool");
		cl.def("size", (unsigned long (std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>::*)() const) &std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::size, "C++: std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::size() const --> unsigned long");
		cl.def("max_size", (unsigned long (std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>::*)() const) &std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::max_size, "C++: std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::max_size() const --> unsigned long");
		cl.def("erase", (unsigned long (std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>::*)(const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > &)) &std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::erase, "C++: std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::erase(const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > &) --> unsigned long", pybind11::arg("__x"));
		cl.def("swap", (void (std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>::*)(class std::multimap<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable>, struct std::less<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > >, class std::allocator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > > &)) &std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::swap, "C++: std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::swap(class std::multimap<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable>, struct std::less<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > >, class std::allocator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > > &) --> void", pybind11::arg("__x"));
		cl.def("clear", (void (std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>::*)()) &std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::clear, "C++: std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::clear() --> void");
		cl.def("key_comp", (struct std::less<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > > (std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>::*)() const) &std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::key_comp, "C++: std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::key_comp() const --> struct std::less<struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > >");
		cl.def("count", (unsigned long (std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>::*)(const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > &) const) &std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::count, "C++: std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::count(const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > &) const --> unsigned long", pybind11::arg("__x"));
		cl.def("equal_range", (struct std::pair<struct std::_Rb_tree_iterator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > >, struct std::_Rb_tree_iterator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > > (std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>>::*)(const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > &)) &std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::equal_range, "C++: std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>, std::less<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>>, std::allocator<std::pair<const std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000>>>, std::shared_ptr<mrpt::serialization::CSerializable>>>>::equal_range(const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > > &) --> struct std::pair<struct std::_Rb_tree_iterator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > >, struct std::_Rb_tree_iterator<struct std::pair<const struct std::chrono::time_point<class mrpt::Clock, struct std::chrono::duration<long, struct std::ratio<1, 10000000> > >, class std::shared_ptr<class mrpt::serialization::CSerializable> > > >", pybind11::arg("__x"));
		
		cl.def("__iter__", [](std::multimap<std::chrono::time_point<mrpt::Clock, std::chrono::duration<long, std::ratio<1, 10000000> > >,std::shared_ptr<mrpt::serialization::CSerializable>> &mmap) {
			return pybind11::make_iterator(mmap.begin(), mmap.end());
			}, pybind11::keep_alive<0, 1>());
	}
}