#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <vector>
#include <string>
#include <set>

BBL_MODULE(std) {

    bbl::Class<std::string>("String").ctor(
        bbl::Class<std::string>::Ctor<char const*>(), "from_char_ptr")
        .m(&std::string::c_str)
        ;

    // We provide macros for automating the binding of common types' methods
    bbl::Class<std::vector<std::string>>("StringVector")
        BBL_STD_VECTOR_METHODS(std::string)
    ;

    bbl::Class<std::vector<std::pair<std::string, std::string>>>("StringPairVector")
        BBL_STD_VECTOR_METHODS((std::pair<std::string, std::string>))
    ;

    bbl::Class<std::set<std::string>>("StringSet");

    bbl::Class<std::vector<double>>("DoubleVector")
        BBL_STD_VECTOR_METHODS(double);

    bbl::Class<std::set<double>>("DoubleSet");
    
}


#endif

