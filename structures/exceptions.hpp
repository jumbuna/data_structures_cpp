//
//  exceptions.hpp
//  structures
//
//  Created by jumbuna on 28/05/2020.
//  Copyright © 2020 jumbuna. All rights reserved.
//

#ifndef exceptions_hpp
#define exceptions_hpp

#include <exception>

struct arrayexception:std::exception{
    arrayexception(const char* message);
    virtual const char * what() const noexcept;
private:
    const char* message;
};

const char* arrayexception::what() const noexcept {
    return message;
}

arrayexception::arrayexception(const char* message)
: message(message)
{}

#endif
