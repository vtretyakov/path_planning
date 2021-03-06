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
    int get_best_lane(vector<double> closest_car_dist_in_lane);
    int get_next_lane(int best_lane, int lane, bool getting_close, const vector<vector<double>> &fusion_data, double car_s, double car_d, int prev_path_size);
    bool safe_to_change(const vector<vector<double>> &fusion_data, double car_s, double car_d, int new_lane, int prev_path_size);
  private:
    double _check_behind_dist;
    double _check_infront_dist;
    bool _prepare_to_change_lane;
};

#endif /* helper_hpp */
