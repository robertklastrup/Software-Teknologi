#include "Vector3D.h"


// Opgave b-1)
vector_3d::vector_3d(double x, double y, double z){
    x_ = x;
    y_ = y;
    z_ = z;
}
        
std::string vector_3d::to_string()const{
    std::string vector_string = "(" + std::to_string(x_) + "," + std::to_string(y_) + "," + std::to_string(z_) + ")" + "\n";
    return vector_string;
}
        


// Opgave c-1)
vector_3d vector_3d::operator!() const{
    double x = -(x_);
    double y = -(y_);
    double z = -(z_);

    vector_3d v (x,y,z);

    return v;
}

//Opgave d-2)
vector_3d operator+ (const vector_3d& v_1, const vector_3d& v_2){
    vector_3d v ((v_1.x_ + v_2.x_), (v_1.y_ + v_2.y_), (v_1.z_ + v_2.z_));
    return v;
}
        


//Opgave e-2)
vector_3d operator- (const vector_3d& v_1, const vector_3d& v_2){
    vector_3d v = v_1 + !v_2;
    return v;
}