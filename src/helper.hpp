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
    vector<double> get_closest_car_dist_in_lanes(const vector<vector<double>> &fusion_data, double car_s, double car_d, int prev_path_size, double threshold);
    vector<double> get_closest_cer_vel_in_lanes();
    int get_best_lane(vector<double> closest_car_dist_in_lane);
    bool safe_to_change(const vector<vector<double>> &fusion_data, double car_s, double car_d, int new_lane, int prev_path_size);
  private:
    double _check_behind_dist;
    double _check_infront_dist;
    bool increasing_order (int i, int j);
};

#endif /* helper_hpp */
