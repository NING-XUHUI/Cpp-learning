//
//  Cube.hpp
//  Cube
//
//  Created by 宁旭晖 on 2019/12/22.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>

#pragma once
namespace uiuc{
class Cube {
public:
    double getVolume();
    double getSurfaceArea();
    void serLength(double length);
    
private:
    double length_;
};
}


#endif /* Cube_hpp */
