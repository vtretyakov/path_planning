//
//  helper.hpp
//  path_planning
//
//  Created by Viatcheslav Tretyakov on 26.07.18.
//

#ifndef helper_hpp
#define helper_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Helper {
  public:
    Helper();
    ~Helper();
    vector<double> get_closest_car_dist_in_lanes(const vector<vector<double>> &fusion_data, double car_s, double car_d, int prev_path_size);
    vector<double> get_closest_cer_vel_in_lanes();
  private:
    vector<double> _car_dist;
    vector<double> _car_vel;
    bool increasing_order (int i, int j);
};

#endif /* helper_hpp */
