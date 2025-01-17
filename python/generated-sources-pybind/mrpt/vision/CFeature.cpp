#include <iterator>
#include <memory>
#include <mrpt/math/CMatrixDynamic.h>
#include <mrpt/rtti/CObject.h>
#include <mrpt/typemeta/static_string.h>
#include <mrpt/vision/CFeature.h>
#include <mrpt/vision/types.h>
#include <ostream>
#include <sstream> // __str__
#include <string>
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

void bind_mrpt_vision_CFeature(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // mrpt::vision::CFeatureList file:mrpt/vision/CFeature.h line:276
		pybind11::class_<mrpt::vision::CFeatureList, std::shared_ptr<mrpt::vision::CFeatureList>> cl(M("mrpt::vision"), "CFeatureList", "A list of visual features, to be used as output by detectors, as\n input/output by trackers, etc.");
		cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureList(); } ) );
		cl.def( pybind11::init( [](mrpt::vision::CFeatureList const &o){ return new mrpt::vision::CFeatureList(o); } ) );
		cl.def("get_type", (enum mrpt::vision::TKeyPointMethod (mrpt::vision::CFeatureList::*)() const) &mrpt::vision::CFeatureList::get_type, "The type of the first feature in the list \n\nC++: mrpt::vision::CFeatureList::get_type() const --> enum mrpt::vision::TKeyPointMethod");
		cl.def("saveToTextFile", [](mrpt::vision::CFeatureList &o, const std::string & a0) -> void { return o.saveToTextFile(a0); }, "", pybind11::arg("fileName"));
		cl.def("saveToTextFile", (void (mrpt::vision::CFeatureList::*)(const std::string &, bool)) &mrpt::vision::CFeatureList::saveToTextFile, "Save feature list to a text file \n\nC++: mrpt::vision::CFeatureList::saveToTextFile(const std::string &, bool) --> void", pybind11::arg("fileName"), pybind11::arg("APPEND"));
		cl.def("loadFromTextFile", (void (mrpt::vision::CFeatureList::*)(const std::string &)) &mrpt::vision::CFeatureList::loadFromTextFile, "Save feature list to a text file \n\nC++: mrpt::vision::CFeatureList::loadFromTextFile(const std::string &) --> void", pybind11::arg("fileName"));
		cl.def("copyListFrom", (void (mrpt::vision::CFeatureList::*)(const class mrpt::vision::CFeatureList &)) &mrpt::vision::CFeatureList::copyListFrom, "Copies the content of another CFeatureList inside this one. The inner\n features are also copied. \n\nC++: mrpt::vision::CFeatureList::copyListFrom(const class mrpt::vision::CFeatureList &) --> void", pybind11::arg("otherList"));
		cl.def("getMaxID", (unsigned long (mrpt::vision::CFeatureList::*)() const) &mrpt::vision::CFeatureList::getMaxID, "Get the maximum ID into the list \n\nC++: mrpt::vision::CFeatureList::getMaxID() const --> unsigned long");
		cl.def("getByID", (const class mrpt::vision::CFeature * (mrpt::vision::CFeatureList::*)(const unsigned long &) const) &mrpt::vision::CFeatureList::getByID, "Get a reference to a Feature from its ID \n\nC++: mrpt::vision::CFeatureList::getByID(const unsigned long &) const --> const class mrpt::vision::CFeature *", pybind11::return_value_policy::automatic, pybind11::arg("ID"));
		cl.def("getByID", (const class mrpt::vision::CFeature * (mrpt::vision::CFeatureList::*)(const unsigned long &, int &) const) &mrpt::vision::CFeatureList::getByID, "C++: mrpt::vision::CFeatureList::getByID(const unsigned long &, int &) const --> const class mrpt::vision::CFeature *", pybind11::return_value_policy::automatic, pybind11::arg("ID"), pybind11::arg("out_idx"));
		cl.def("nearest", (const class mrpt::vision::CFeature * (mrpt::vision::CFeatureList::*)(const float, const float, double &) const) &mrpt::vision::CFeatureList::nearest, "Get a reference to the nearest feature to the a given 2D point (version\n returning distance to closest feature in \"max_dist\")\n   \n\n [IN] The query point x-coordinate\n   \n\n [IN] The query point y-coordinate\n   \n\n [IN/OUT] At input: The maximum distance to search for.\n At output: The actual distance to the feature.\n  \n\n A pointer to the found feature, or nullptr if not found.\n  \n\n See also all the available KD-tree search methods, listed in\n mrpt::math::KDTreeCapable\n\nC++: mrpt::vision::CFeatureList::nearest(const float, const float, double &) const --> const class mrpt::vision::CFeature *", pybind11::return_value_policy::automatic, pybind11::arg("x"), pybind11::arg("y"), pybind11::arg("max_dist"));
		cl.def("mark_kdtree_as_outdated", (void (mrpt::vision::CFeatureList::*)() const) &mrpt::vision::CFeatureList::mark_kdtree_as_outdated, "Call this when the list of features has been modified so the KD-tree is\n marked as outdated. \n\nC++: mrpt::vision::CFeatureList::mark_kdtree_as_outdated() const --> void");
		cl.def("empty", (bool (mrpt::vision::CFeatureList::*)() const) &mrpt::vision::CFeatureList::empty, "C++: mrpt::vision::CFeatureList::empty() const --> bool");
		cl.def("size", (size_t (mrpt::vision::CFeatureList::*)() const) &mrpt::vision::CFeatureList::size, "C++: mrpt::vision::CFeatureList::size() const --> size_t");
		cl.def("clear", (void (mrpt::vision::CFeatureList::*)()) &mrpt::vision::CFeatureList::clear, "C++: mrpt::vision::CFeatureList::clear() --> void");
		cl.def("resize", (void (mrpt::vision::CFeatureList::*)(size_t)) &mrpt::vision::CFeatureList::resize, "C++: mrpt::vision::CFeatureList::resize(size_t) --> void", pybind11::arg("N"));
		cl.def("push_back", (void (mrpt::vision::CFeatureList::*)(const class mrpt::vision::CFeature &)) &mrpt::vision::CFeatureList::push_back, "C++: mrpt::vision::CFeatureList::push_back(const class mrpt::vision::CFeature &) --> void", pybind11::arg("f"));
		cl.def("__getitem__", (class mrpt::vision::CFeature & (mrpt::vision::CFeatureList::*)(const unsigned int)) &mrpt::vision::CFeatureList::operator[], "C++: mrpt::vision::CFeatureList::operator[](const unsigned int) --> class mrpt::vision::CFeature &", pybind11::return_value_policy::automatic, pybind11::arg("index"));
		cl.def("kdtree_get_point_count", (size_t (mrpt::vision::CFeatureList::*)() const) &mrpt::vision::CFeatureList::kdtree_get_point_count, "Must return the number of data points\n\nC++: mrpt::vision::CFeatureList::kdtree_get_point_count() const --> size_t");
		cl.def("kdtree_get_pt", (float (mrpt::vision::CFeatureList::*)(size_t, int) const) &mrpt::vision::CFeatureList::kdtree_get_pt, "Returns the dim'th component of the idx'th point in the class:\n\nC++: mrpt::vision::CFeatureList::kdtree_get_pt(size_t, int) const --> float", pybind11::arg("idx"), pybind11::arg("dim"));
		cl.def("kdtree_distance", (float (mrpt::vision::CFeatureList::*)(const float *, size_t, size_t) const) &mrpt::vision::CFeatureList::kdtree_distance, "Returns the distance between the vector \"p1[0:size-1]\" and the data\n point with index \"idx_p2\" stored in the class:\n\nC++: mrpt::vision::CFeatureList::kdtree_distance(const float *, size_t, size_t) const --> float", pybind11::arg("p1"), pybind11::arg("idx_p2"), pybind11::arg("size"));
		cl.def("getFeatureX", (float (mrpt::vision::CFeatureList::*)(size_t) const) &mrpt::vision::CFeatureList::getFeatureX, "		@{ \n\nC++: mrpt::vision::CFeatureList::getFeatureX(size_t) const --> float", pybind11::arg("i"));
		cl.def("getFeatureY", (float (mrpt::vision::CFeatureList::*)(size_t) const) &mrpt::vision::CFeatureList::getFeatureY, "C++: mrpt::vision::CFeatureList::getFeatureY(size_t) const --> float", pybind11::arg("i"));
		cl.def("getFeatureID", (unsigned long (mrpt::vision::CFeatureList::*)(size_t) const) &mrpt::vision::CFeatureList::getFeatureID, "C++: mrpt::vision::CFeatureList::getFeatureID(size_t) const --> unsigned long", pybind11::arg("i"));
		cl.def("getFeatureResponse", (float (mrpt::vision::CFeatureList::*)(size_t) const) &mrpt::vision::CFeatureList::getFeatureResponse, "C++: mrpt::vision::CFeatureList::getFeatureResponse(size_t) const --> float", pybind11::arg("i"));
		cl.def("isPointFeature", (bool (mrpt::vision::CFeatureList::*)(size_t) const) &mrpt::vision::CFeatureList::isPointFeature, "C++: mrpt::vision::CFeatureList::isPointFeature(size_t) const --> bool", pybind11::arg("i"));
		cl.def("getScale", (float (mrpt::vision::CFeatureList::*)(size_t) const) &mrpt::vision::CFeatureList::getScale, "C++: mrpt::vision::CFeatureList::getScale(size_t) const --> float", pybind11::arg("i"));
		cl.def("getTrackStatus", (enum mrpt::vision::TFeatureTrackStatus (mrpt::vision::CFeatureList::*)(size_t)) &mrpt::vision::CFeatureList::getTrackStatus, "C++: mrpt::vision::CFeatureList::getTrackStatus(size_t) --> enum mrpt::vision::TFeatureTrackStatus", pybind11::arg("i"));
		cl.def("setFeatureX", (void (mrpt::vision::CFeatureList::*)(size_t, float)) &mrpt::vision::CFeatureList::setFeatureX, "C++: mrpt::vision::CFeatureList::setFeatureX(size_t, float) --> void", pybind11::arg("i"), pybind11::arg("x"));
		cl.def("setFeatureXf", (void (mrpt::vision::CFeatureList::*)(size_t, float)) &mrpt::vision::CFeatureList::setFeatureXf, "C++: mrpt::vision::CFeatureList::setFeatureXf(size_t, float) --> void", pybind11::arg("i"), pybind11::arg("x"));
		cl.def("setFeatureY", (void (mrpt::vision::CFeatureList::*)(size_t, float)) &mrpt::vision::CFeatureList::setFeatureY, "C++: mrpt::vision::CFeatureList::setFeatureY(size_t, float) --> void", pybind11::arg("i"), pybind11::arg("y"));
		cl.def("setFeatureYf", (void (mrpt::vision::CFeatureList::*)(size_t, float)) &mrpt::vision::CFeatureList::setFeatureYf, "C++: mrpt::vision::CFeatureList::setFeatureYf(size_t, float) --> void", pybind11::arg("i"), pybind11::arg("y"));
		cl.def("setFeatureID", (void (mrpt::vision::CFeatureList::*)(size_t, unsigned long)) &mrpt::vision::CFeatureList::setFeatureID, "C++: mrpt::vision::CFeatureList::setFeatureID(size_t, unsigned long) --> void", pybind11::arg("i"), pybind11::arg("id"));
		cl.def("setFeatureResponse", (void (mrpt::vision::CFeatureList::*)(size_t, float)) &mrpt::vision::CFeatureList::setFeatureResponse, "C++: mrpt::vision::CFeatureList::setFeatureResponse(size_t, float) --> void", pybind11::arg("i"), pybind11::arg("r"));
		cl.def("setScale", (void (mrpt::vision::CFeatureList::*)(size_t, uint8_t)) &mrpt::vision::CFeatureList::setScale, "C++: mrpt::vision::CFeatureList::setScale(size_t, uint8_t) --> void", pybind11::arg("i"), pybind11::arg("s"));
		cl.def("setTrackStatus", (void (mrpt::vision::CFeatureList::*)(size_t, enum mrpt::vision::TFeatureTrackStatus)) &mrpt::vision::CFeatureList::setTrackStatus, "C++: mrpt::vision::CFeatureList::setTrackStatus(size_t, enum mrpt::vision::TFeatureTrackStatus) --> void", pybind11::arg("i"), pybind11::arg("s"));
		cl.def("mark_as_outdated", (void (mrpt::vision::CFeatureList::*)() const) &mrpt::vision::CFeatureList::mark_as_outdated, "C++: mrpt::vision::CFeatureList::mark_as_outdated() const --> void");
		cl.def("assign", (class mrpt::vision::CFeatureList & (mrpt::vision::CFeatureList::*)(const class mrpt::vision::CFeatureList &)) &mrpt::vision::CFeatureList::operator=, "C++: mrpt::vision::CFeatureList::operator=(const class mrpt::vision::CFeatureList &) --> class mrpt::vision::CFeatureList &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // mrpt::vision::CMatchedFeatureList file:mrpt/vision/CFeature.h line:493
		pybind11::class_<mrpt::vision::CMatchedFeatureList, std::shared_ptr<mrpt::vision::CMatchedFeatureList>> cl(M("mrpt::vision"), "CMatchedFeatureList", "**************************************************\n			Class CMATCHEDFEATURELIST\n***************************************************\n\n A list of features");
		cl.def( pybind11::init( [](){ return new mrpt::vision::CMatchedFeatureList(); } ) );
		cl.def( pybind11::init( [](mrpt::vision::CMatchedFeatureList const &o){ return new mrpt::vision::CMatchedFeatureList(o); } ) );
		cl.def("get_type", (enum mrpt::vision::TKeyPointMethod (mrpt::vision::CMatchedFeatureList::*)() const) &mrpt::vision::CMatchedFeatureList::get_type, "The type of the first feature in the list \n\nC++: mrpt::vision::CMatchedFeatureList::get_type() const --> enum mrpt::vision::TKeyPointMethod");
		cl.def("saveToTextFile", (void (mrpt::vision::CMatchedFeatureList::*)(const std::string &)) &mrpt::vision::CMatchedFeatureList::saveToTextFile, "Save list of matched features to a text file \n\nC++: mrpt::vision::CMatchedFeatureList::saveToTextFile(const std::string &) --> void", pybind11::arg("fileName"));
		cl.def("getBothFeatureLists", (void (mrpt::vision::CMatchedFeatureList::*)(class mrpt::vision::CFeatureList &, class mrpt::vision::CFeatureList &)) &mrpt::vision::CMatchedFeatureList::getBothFeatureLists, "Returns the matching features as two separate CFeatureLists \n\nC++: mrpt::vision::CMatchedFeatureList::getBothFeatureLists(class mrpt::vision::CFeatureList &, class mrpt::vision::CFeatureList &) --> void", pybind11::arg("list1"), pybind11::arg("list2"));
		cl.def("getByID", (const class mrpt::vision::CFeature * (mrpt::vision::CMatchedFeatureList::*)(const unsigned long &, const enum mrpt::vision::TListIdx &)) &mrpt::vision::CMatchedFeatureList::getByID, "Returns a smart pointer to the feature with the provided ID or a empty\n one if not found \n\nC++: mrpt::vision::CMatchedFeatureList::getByID(const unsigned long &, const enum mrpt::vision::TListIdx &) --> const class mrpt::vision::CFeature *", pybind11::return_value_policy::automatic, pybind11::arg("ID"), pybind11::arg("idx"));
		cl.def("getMaxID", (void (mrpt::vision::CMatchedFeatureList::*)(const enum mrpt::vision::TListIdx &, unsigned long &, unsigned long &)) &mrpt::vision::CMatchedFeatureList::getMaxID, "Returns the maximum ID of the features in the list. If the max ID has\n	   been already set up, this method just returns it.\n		Otherwise, this method finds, stores and returns it.\n\nC++: mrpt::vision::CMatchedFeatureList::getMaxID(const enum mrpt::vision::TListIdx &, unsigned long &, unsigned long &) --> void", pybind11::arg("idx"), pybind11::arg("firstListID"), pybind11::arg("secondListID"));
		cl.def("updateMaxID", (void (mrpt::vision::CMatchedFeatureList::*)(const enum mrpt::vision::TListIdx &)) &mrpt::vision::CMatchedFeatureList::updateMaxID, "Updates the value of the maximum ID of the features in the matched list,\n i.e. it explicitly searches for the max ID and updates the member\n variables. \n\nC++: mrpt::vision::CMatchedFeatureList::updateMaxID(const enum mrpt::vision::TListIdx &) --> void", pybind11::arg("idx"));
		cl.def("setLeftMaxID", (void (mrpt::vision::CMatchedFeatureList::*)(const unsigned long &)) &mrpt::vision::CMatchedFeatureList::setLeftMaxID, "Explicitly set the max IDs values to certain values \n\nC++: mrpt::vision::CMatchedFeatureList::setLeftMaxID(const unsigned long &) --> void", pybind11::arg("leftID"));
		cl.def("setRightMaxID", (void (mrpt::vision::CMatchedFeatureList::*)(const unsigned long &)) &mrpt::vision::CMatchedFeatureList::setRightMaxID, "C++: mrpt::vision::CMatchedFeatureList::setRightMaxID(const unsigned long &) --> void", pybind11::arg("rightID"));
		cl.def("setMaxIDs", (void (mrpt::vision::CMatchedFeatureList::*)(const unsigned long &, const unsigned long &)) &mrpt::vision::CMatchedFeatureList::setMaxIDs, "C++: mrpt::vision::CMatchedFeatureList::setMaxIDs(const unsigned long &, const unsigned long &) --> void", pybind11::arg("leftID"), pybind11::arg("rightID"));
		cl.def("assign", (class mrpt::vision::CMatchedFeatureList & (mrpt::vision::CMatchedFeatureList::*)(const class mrpt::vision::CMatchedFeatureList &)) &mrpt::vision::CMatchedFeatureList::operator=, "C++: mrpt::vision::CMatchedFeatureList::operator=(const class mrpt::vision::CMatchedFeatureList &) --> class mrpt::vision::CMatchedFeatureList &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
