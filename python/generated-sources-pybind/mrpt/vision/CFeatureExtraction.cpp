#include <ios>
#include <iterator>
#include <memory>
#include <mrpt/bayes/CKalmanFilterCapable.h>
#include <mrpt/config/CConfigFileBase.h>
#include <mrpt/img/CCanvas.h>
#include <mrpt/img/CImage.h>
#include <mrpt/img/TCamera.h>
#include <mrpt/img/TColor.h>
#include <mrpt/img/TPixelCoord.h>
#include <mrpt/io/CStream.h>
#include <mrpt/math/CMatrixDynamic.h>
#include <mrpt/rtti/CObject.h>
#include <mrpt/system/COutputLogger.h>
#include <mrpt/typemeta/static_string.h>
#include <mrpt/vision/CFeature.h>
#include <mrpt/vision/CFeatureExtraction.h>
#include <mrpt/vision/types.h>
#include <ostream>
#include <sstream> // __str__
#include <streambuf>
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

// mrpt::vision::CFeatureExtraction::TOptions file:mrpt/vision/CFeatureExtraction.h line:85
struct PyCallBack_mrpt_vision_CFeatureExtraction_TOptions : public mrpt::vision::CFeatureExtraction::TOptions {
	using mrpt::vision::CFeatureExtraction::TOptions::TOptions;

	void loadFromConfigFile(const class mrpt::config::CConfigFileBase & a0, const std::string & a1) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const mrpt::vision::CFeatureExtraction::TOptions *>(this), "loadFromConfigFile");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return TOptions::loadFromConfigFile(a0, a1);
	}
	void saveToConfigFile(class mrpt::config::CConfigFileBase & a0, const std::string & a1) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const mrpt::vision::CFeatureExtraction::TOptions *>(this), "saveToConfigFile");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		return CLoadableOptions::saveToConfigFile(a0, a1);
	}
};

void bind_mrpt_vision_CFeatureExtraction(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // mrpt::vision::CFeatureExtraction file:mrpt/vision/CFeatureExtraction.h line:71
		pybind11::class_<mrpt::vision::CFeatureExtraction, std::shared_ptr<mrpt::vision::CFeatureExtraction>> cl(M("mrpt::vision"), "CFeatureExtraction", "The central class from which images can be analyzed in search of different\nkinds of interest points and descriptors computed for them.\n  To extract features from an image, create an instance of\nCFeatureExtraction,\n   fill out its CFeatureExtraction::options field, including the algorithm to\nuse (see\n   CFeatureExtraction::TOptions::featsType), and call\nCFeatureExtraction::detectFeatures.\n  This will return a set of features of the class mrpt::vision::CFeature,\nwhich include\n   details for each interest point as well as the desired descriptors and/or\npatches.\n\n  By default, a 21x21 patch is extracted for each detected feature. If the\npatch is not needed,\n   set patchSize to 0 in CFeatureExtraction::options\n\n  The implemented detection algorithms are (see\nCFeatureExtraction::TOptions::featsType):\n		- KLT (Kanade-Lucas-Tomasi): A detector (no descriptor vector).\n		- Harris: A detector (no descriptor vector).\n		- BCD (Binary Corner Detector): A detector (no descriptor vector) (Not\nimplemented yet).\n		- SIFT: An implementation of the SIFT detector and descriptor. The\nimplemention may be selected with\nCFeatureExtraction::TOptions::SIFTOptions::implementation.\n		- SURF: OpenCV's implementation of SURF detector and descriptor.\n		- The FAST feature detector (OpenCV's implementation)\n\n  Additionally, given a list of interest points onto an image, the following\n   descriptors can be computed for each point by calling\nCFeatureExtraction::computeDescriptors :\n		- SIFT descriptor (Lowe's descriptors).\n		- SURF descriptor (OpenCV's implementation - Requires OpenCV 1.1.0 from\nSVN\nor later).\n		- Intensity-domain spin images (SpinImage): Creates a vector descriptor\nwith the 2D histogram as a single row.\n		- A circular patch in polar coordinates (Polar images): The matrix\ndescriptor is a 2D polar image centered at the interest point.\n		- A log-polar image patch (Log-polar images): The matrix descriptor is\nthe\n2D log-polar image centered at the interest point.\n\n \n The descriptor \"Intensity-domain spin images\" is described in \"A\nsparse texture representation using affine-invariant regions\", S Lazebnik, C\nSchmid, J Ponce, 2003 IEEE Computer Society Conference on Computer Vision.\n \n\n mrpt::vision::CFeature\n \n\n\n ");
		cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction(); } ) );
		cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction const &o){ return new mrpt::vision::CFeatureExtraction(o); } ) );

		pybind11::enum_<mrpt::vision::CFeatureExtraction::TSIFTImplementation>(cl, "TSIFTImplementation", pybind11::arithmetic(), "")
			.value("OpenCV", mrpt::vision::CFeatureExtraction::OpenCV)
			.export_values();

		cl.def_readwrite("profiler", &mrpt::vision::CFeatureExtraction::profiler);
		cl.def_readwrite("options", &mrpt::vision::CFeatureExtraction::options);
		cl.def("detectFeatures", [](mrpt::vision::CFeatureExtraction &o, const class mrpt::img::CImage & a0, class mrpt::vision::CFeatureList & a1) -> void { return o.detectFeatures(a0, a1); }, "", pybind11::arg("img"), pybind11::arg("feats"));
		cl.def("detectFeatures", [](mrpt::vision::CFeatureExtraction &o, const class mrpt::img::CImage & a0, class mrpt::vision::CFeatureList & a1, const unsigned int & a2) -> void { return o.detectFeatures(a0, a1, a2); }, "", pybind11::arg("img"), pybind11::arg("feats"), pybind11::arg("init_ID"));
		cl.def("detectFeatures", [](mrpt::vision::CFeatureExtraction &o, const class mrpt::img::CImage & a0, class mrpt::vision::CFeatureList & a1, const unsigned int & a2, const unsigned int & a3) -> void { return o.detectFeatures(a0, a1, a2, a3); }, "", pybind11::arg("img"), pybind11::arg("feats"), pybind11::arg("init_ID"), pybind11::arg("nDesiredFeatures"));
		cl.def("detectFeatures", (void (mrpt::vision::CFeatureExtraction::*)(const class mrpt::img::CImage &, class mrpt::vision::CFeatureList &, const unsigned int, const unsigned int, const struct mrpt::vision::TImageROI &)) &mrpt::vision::CFeatureExtraction::detectFeatures, "Extract features from the image based on the method defined in\n TOptions. \n\n (input) The image from where to extract the\n images. \n\n (output) A complete list of features (containing\n a patch for each one of them if options.patchsize > 0). \n\n\n (op. input) Number of features to be extracted.\n Default: all possible.\n\n \n computeDescriptors\n\nC++: mrpt::vision::CFeatureExtraction::detectFeatures(const class mrpt::img::CImage &, class mrpt::vision::CFeatureList &, const unsigned int, const unsigned int, const struct mrpt::vision::TImageROI &) --> void", pybind11::arg("img"), pybind11::arg("feats"), pybind11::arg("init_ID"), pybind11::arg("nDesiredFeatures"), pybind11::arg("ROI"));
		cl.def("computeDescriptors", (void (mrpt::vision::CFeatureExtraction::*)(const class mrpt::img::CImage &, class mrpt::vision::CFeatureList &, enum mrpt::vision::TDescriptorType)) &mrpt::vision::CFeatureExtraction::computeDescriptors, "Compute one (or more) descriptors for the given set of interest\n points onto the image, which may have been filled out manually or\n from  \n\n (input) The image from where to\n compute the descriptors. \n\n (input/output) The\n list of features whose descriptors are going to be computed. \n\n\n (input) The bitwise OR of one or several\n descriptors defined in TDescriptorType.\n\n  Each value in \"in_descriptor_list\" represents one descriptor to be\n computed, for example:\n  \n\n\n\n\n\n \n The SIFT descriptors for already located features can only be\n computed through the Hess and\n        CSBinary implementations which may be specified in\n CFeatureExtraction::TOptions::SIFTOptions.\n\n \n This call will also use additional parameters from \n	 \n\nC++: mrpt::vision::CFeatureExtraction::computeDescriptors(const class mrpt::img::CImage &, class mrpt::vision::CFeatureList &, enum mrpt::vision::TDescriptorType) --> void", pybind11::arg("in_img"), pybind11::arg("inout_features"), pybind11::arg("in_descriptor_list"));
		cl.def("assign", (class mrpt::vision::CFeatureExtraction & (mrpt::vision::CFeatureExtraction::*)(const class mrpt::vision::CFeatureExtraction &)) &mrpt::vision::CFeatureExtraction::operator=, "C++: mrpt::vision::CFeatureExtraction::operator=(const class mrpt::vision::CFeatureExtraction &) --> class mrpt::vision::CFeatureExtraction &", pybind11::return_value_policy::automatic, pybind11::arg(""));

		{ // mrpt::vision::CFeatureExtraction::TOptions file:mrpt/vision/CFeatureExtraction.h line:85
			auto & enclosing_class = cl;
			pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions>, PyCallBack_mrpt_vision_CFeatureExtraction_TOptions, mrpt::config::CLoadableOptions> cl(enclosing_class, "TOptions", "The set of parameters for all the detectors & descriptor algorithms ");
			cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions(); }, [](){ return new PyCallBack_mrpt_vision_CFeatureExtraction_TOptions(); } ) );
			cl.def( pybind11::init<const enum mrpt::vision::TKeyPointMethod>(), pybind11::arg("ft") );

			cl.def( pybind11::init( [](PyCallBack_mrpt_vision_CFeatureExtraction_TOptions const &o){ return new PyCallBack_mrpt_vision_CFeatureExtraction_TOptions(o); } ) );
			cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions(o); } ) );
			cl.def_readwrite("featsType", &mrpt::vision::CFeatureExtraction::TOptions::featsType);
			cl.def_readwrite("patchSize", &mrpt::vision::CFeatureExtraction::TOptions::patchSize);
			cl.def_readwrite("useMask", &mrpt::vision::CFeatureExtraction::TOptions::useMask);
			cl.def_readwrite("addNewFeatures", &mrpt::vision::CFeatureExtraction::TOptions::addNewFeatures);
			cl.def_readwrite("FIND_SUBPIXEL", &mrpt::vision::CFeatureExtraction::TOptions::FIND_SUBPIXEL);
			cl.def_readwrite("KLTOptions", &mrpt::vision::CFeatureExtraction::TOptions::KLTOptions);
			cl.def_readwrite("harrisOptions", &mrpt::vision::CFeatureExtraction::TOptions::harrisOptions);
			cl.def_readwrite("BCDOptions", &mrpt::vision::CFeatureExtraction::TOptions::BCDOptions);
			cl.def_readwrite("FASTOptions", &mrpt::vision::CFeatureExtraction::TOptions::FASTOptions);
			cl.def_readwrite("ORBOptions", &mrpt::vision::CFeatureExtraction::TOptions::ORBOptions);
			cl.def_readwrite("SIFTOptions", &mrpt::vision::CFeatureExtraction::TOptions::SIFTOptions);
			cl.def_readwrite("SURFOptions", &mrpt::vision::CFeatureExtraction::TOptions::SURFOptions);
			cl.def_readwrite("SpinImagesOptions", &mrpt::vision::CFeatureExtraction::TOptions::SpinImagesOptions);
			cl.def_readwrite("PolarImagesOptions", &mrpt::vision::CFeatureExtraction::TOptions::PolarImagesOptions);
			cl.def_readwrite("LogPolarImagesOptions", &mrpt::vision::CFeatureExtraction::TOptions::LogPolarImagesOptions);
			cl.def_readwrite("AKAZEOptions", &mrpt::vision::CFeatureExtraction::TOptions::AKAZEOptions);
			cl.def_readwrite("LSDOptions", &mrpt::vision::CFeatureExtraction::TOptions::LSDOptions);
			cl.def_readwrite("BLDOptions", &mrpt::vision::CFeatureExtraction::TOptions::BLDOptions);
			cl.def_readwrite("LATCHOptions", &mrpt::vision::CFeatureExtraction::TOptions::LATCHOptions);
			cl.def("loadFromConfigFile", (void (mrpt::vision::CFeatureExtraction::TOptions::*)(const class mrpt::config::CConfigFileBase &, const std::string &)) &mrpt::vision::CFeatureExtraction::TOptions::loadFromConfigFile, "C++: mrpt::vision::CFeatureExtraction::TOptions::loadFromConfigFile(const class mrpt::config::CConfigFileBase &, const std::string &) --> void", pybind11::arg("c"), pybind11::arg("s"));
			cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions & (mrpt::vision::CFeatureExtraction::TOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));

			{ // mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions file:mrpt/vision/CFeatureExtraction.h line:120
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions>> cl(enclosing_class, "TKLTOptions", "KLT Options ");
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions(o); } ) );
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions(); } ) );
				cl.def_readwrite("radius", &mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions::radius);
				cl.def_readwrite("threshold", &mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions::threshold);
				cl.def_readwrite("min_distance", &mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions::min_distance);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions & (mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TKLTOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions file:mrpt/vision/CFeatureExtraction.h line:132
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions>> cl(enclosing_class, "THarrisOptions", "Harris Options ");
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions(o); } ) );
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions(); } ) );
				cl.def_readwrite("threshold", &mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions::threshold);
				cl.def_readwrite("sigma", &mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions::sigma);
				cl.def_readwrite("radius", &mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions::radius);
				cl.def_readwrite("min_distance", &mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions::min_distance);
				cl.def_readwrite("k", &mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions::k);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions & (mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::THarrisOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions file:mrpt/vision/CFeatureExtraction.h line:147
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions>> cl(enclosing_class, "TBCDOptions", "BCD Options ");
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions(o); } ) );
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions(); } ) );
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions & (mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TBCDOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions file:mrpt/vision/CFeatureExtraction.h line:152
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions>> cl(enclosing_class, "TFASTOptions", "FAST Options ");
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions(o); } ) );
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions(); } ) );
				cl.def_readwrite("threshold", &mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions::threshold);
				cl.def_readwrite("min_distance", &mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions::min_distance);
				cl.def_readwrite("nonmax_suppression", &mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions::nonmax_suppression);
				cl.def_readwrite("use_KLT_response", &mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions::use_KLT_response);
				cl.def_readwrite("KLT_response_half_win_size", &mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions::KLT_response_half_win_size);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions & (mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TFASTOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::TORBOptions file:mrpt/vision/CFeatureExtraction.h line:169
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TORBOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TORBOptions>> cl(enclosing_class, "TORBOptions", "ORB Options ");
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TORBOptions(); } ) );
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TORBOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TORBOptions(o); } ) );
				cl.def_readwrite("n_levels", &mrpt::vision::CFeatureExtraction::TOptions::TORBOptions::n_levels);
				cl.def_readwrite("min_distance", &mrpt::vision::CFeatureExtraction::TOptions::TORBOptions::min_distance);
				cl.def_readwrite("scale_factor", &mrpt::vision::CFeatureExtraction::TOptions::TORBOptions::scale_factor);
				cl.def_readwrite("extract_patch", &mrpt::vision::CFeatureExtraction::TOptions::TORBOptions::extract_patch);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TORBOptions & (mrpt::vision::CFeatureExtraction::TOptions::TORBOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TORBOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TORBOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TORBOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TORBOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TORBOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions file:mrpt/vision/CFeatureExtraction.h line:179
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions>> cl(enclosing_class, "TSIFTOptions", "SIFT Options  ");
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions(); } ) );
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions(o); } ) );
				cl.def_readwrite("implementation", &mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions::implementation);
				cl.def_readwrite("octaveLayers", &mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions::octaveLayers);
				cl.def_readwrite("threshold", &mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions::threshold);
				cl.def_readwrite("edgeThreshold", &mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions::edgeThreshold);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions & (mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TSIFTOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions file:mrpt/vision/CFeatureExtraction.h line:189
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions>> cl(enclosing_class, "TSURFOptions", "SURF Options ");
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions(); } ) );
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions(o); } ) );
				cl.def_readwrite("rotation_invariant", &mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions::rotation_invariant);
				cl.def_readwrite("hessianThreshold", &mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions::hessianThreshold);
				cl.def_readwrite("nOctaves", &mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions::nOctaves);
				cl.def_readwrite("nLayersPerOctave", &mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions::nLayersPerOctave);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions & (mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TSURFOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions file:mrpt/vision/CFeatureExtraction.h line:201
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions>> cl(enclosing_class, "TSpinImagesOptions", "SpinImages Options ");
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions(o); } ) );
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions(); } ) );
				cl.def_readwrite("hist_size_intensity", &mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions::hist_size_intensity);
				cl.def_readwrite("hist_size_distance", &mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions::hist_size_distance);
				cl.def_readwrite("std_dist", &mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions::std_dist);
				cl.def_readwrite("std_intensity", &mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions::std_intensity);
				cl.def_readwrite("radius", &mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions::radius);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions & (mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TSpinImagesOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions file:mrpt/vision/CFeatureExtraction.h line:221
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions>> cl(enclosing_class, "TPolarImagesOptions", "PolarImagesOptions options  ");
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions(o); } ) );
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions(); } ) );
				cl.def_readwrite("bins_angle", &mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions::bins_angle);
				cl.def_readwrite("bins_distance", &mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions::bins_distance);
				cl.def_readwrite("radius", &mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions::radius);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions & (mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TPolarImagesOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions file:mrpt/vision/CFeatureExtraction.h line:236
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions>> cl(enclosing_class, "TLogPolarImagesOptions", "LogPolarImagesOptions Options");
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions(o); } ) );
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions(); } ) );
				cl.def_readwrite("radius", &mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions::radius);
				cl.def_readwrite("num_angles", &mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions::num_angles);
				cl.def_readwrite("rho_scale", &mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions::rho_scale);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions & (mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TLogPolarImagesOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions file:mrpt/vision/CFeatureExtraction.h line:251
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions>> cl(enclosing_class, "TAKAZEOptions", "AKAZEOptions Options ");
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions(o); } ) );
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions(); } ) );
				cl.def_readwrite("descriptor_type", &mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions::descriptor_type);
				cl.def_readwrite("descriptor_size", &mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions::descriptor_size);
				cl.def_readwrite("descriptor_channels", &mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions::descriptor_channels);
				cl.def_readwrite("threshold", &mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions::threshold);
				cl.def_readwrite("nOctaves", &mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions::nOctaves);
				cl.def_readwrite("nOctaveLayers", &mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions::nOctaveLayers);
				cl.def_readwrite("diffusivity", &mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions::diffusivity);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions & (mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TAKAZEOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions file:mrpt/vision/CFeatureExtraction.h line:267
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions>> cl(enclosing_class, "TLSDOptions", "LSDOptions Options ");
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions(o); } ) );
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions(); } ) );
				cl.def_readwrite("scale", &mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions::scale);
				cl.def_readwrite("nOctaves", &mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions::nOctaves);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions & (mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TLSDOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions file:mrpt/vision/CFeatureExtraction.h line:274
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions>> cl(enclosing_class, "TBLDOptions", "BLDOptions Descriptor Options ");
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions(o); } ) );
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions(); } ) );
				cl.def_readwrite("ksize_", &mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions::ksize_);
				cl.def_readwrite("reductionRatio", &mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions::reductionRatio);
				cl.def_readwrite("widthOfBand", &mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions::widthOfBand);
				cl.def_readwrite("numOfOctave", &mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions::numOfOctave);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions & (mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TBLDOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

			{ // mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions file:mrpt/vision/CFeatureExtraction.h line:283
				auto & enclosing_class = cl;
				pybind11::class_<mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions, std::shared_ptr<mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions>> cl(enclosing_class, "TLATCHOptions", "LATCHOptions Descriptor ");
				cl.def( pybind11::init( [](mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions const &o){ return new mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions(o); } ) );
				cl.def( pybind11::init( [](){ return new mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions(); } ) );
				cl.def_readwrite("bytes", &mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions::bytes);
				cl.def_readwrite("rotationInvariance", &mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions::rotationInvariance);
				cl.def_readwrite("half_ssd_size", &mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions::half_ssd_size);
				cl.def("assign", (struct mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions & (mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions::*)(const struct mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions &)) &mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions::operator=, "C++: mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions::operator=(const struct mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions &) --> struct mrpt::vision::CFeatureExtraction::TOptions::TLATCHOptions &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			}

		}

	}
}
