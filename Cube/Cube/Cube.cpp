//
//  Cube.cpp
//  Cube
//
//  Created by 宁旭晖 on 2019/12/22.
//  Copyright © 2019 宁旭晖. All rights reserved.
//

#include "Cube.hpp"
#include "Cube.hpp"

namespace uiuc {
double Cube::getVolume(){
    return length_ * length_ * length_;
}

double Cube::getSurfaceArea(){
    return 6 * length_ * length_;
}

void Cube::serLength(double length){
    length_ = length;
}
}

